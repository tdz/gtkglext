/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002  Naofumi Yasufuku
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA.
 */

#include "gdkglprivate.h"
#include "gdkglconfig.h"
#include "gdkglpixmap.h"

enum {
  PROP_0,
  PROP_GLCONFIG,
  PROP_WRAPPER
};

static void gdk_gl_pixmap_init         (GdkGLPixmap      *glpixmap);
static void gdk_gl_pixmap_class_init   (GdkGLPixmapClass *klass);
static void gdk_gl_pixmap_set_property (GObject          *object,
                                        guint             property_id,
                                        const GValue     *value,
                                        GParamSpec       *pspec);
static void gdk_gl_pixmap_get_property (GObject          *object,
                                        guint             property_id,
                                        GValue           *value,
                                        GParamSpec       *pspec);
static void gdk_gl_pixmap_finalize     (GObject          *object);

static gpointer parent_class = NULL;

GType
gdk_gl_pixmap_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLPixmapClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_pixmap_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLPixmap),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_pixmap_init,
      };

      /*
      type = g_type_register_static (GDK_TYPE_PIXMAP,
                                     "GdkGLPixmap",
                                     &type_info, 0);
      */
      type = g_type_register_static (G_TYPE_OBJECT,
                                     "GdkGLPixmap",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_pixmap_init (GdkGLPixmap *glpixmap)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_init ()"));
}

static void
gdk_gl_pixmap_class_init (GdkGLPixmapClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->set_property = gdk_gl_pixmap_set_property;
  object_class->get_property = gdk_gl_pixmap_get_property;
  object_class->finalize     = gdk_gl_pixmap_finalize;

  g_object_class_install_property (object_class,
                                   PROP_GLCONFIG,
                                   g_param_spec_object ("glconfig",
                                                        _("GL configuration"),
                                                        _("The OpenGL configuration object."),
                                                        GDK_TYPE_GL_CONFIG,
                                                        G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
  g_object_class_install_property (object_class,
                                   PROP_WRAPPER,
                                   g_param_spec_object ("wrapper",
                                                        _("Wrapper"),
                                                        _("Real GdkDrawable object."),
                                                        GDK_TYPE_DRAWABLE,
                                                        G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

static void
gdk_gl_pixmap_set_property (GObject      *object,
                            guint         property_id,
                            const GValue *value,
                            GParamSpec   *pspec)
{
  GdkGLPixmap *glpixmap = GDK_GL_PIXMAP (object);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_set_property ()"));

  switch (property_id)
    {
    case PROP_GLCONFIG:
      glpixmap->glconfig = g_value_get_object (value);
      g_object_ref (G_OBJECT (glpixmap->glconfig));
      g_object_notify (object, "glconfig");
      break;
    case PROP_WRAPPER:
      glpixmap->wrapper = g_value_get_object (value);
      /* g_object_ref (G_OBJECT (glpixmap->wrapper)); */
      g_object_notify (object, "wrapper");
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_pixmap_get_property (GObject    *object,
                            guint       property_id,
                            GValue     *value,
                            GParamSpec *pspec)
{
  switch (property_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_pixmap_finalize (GObject *object)
{
  GdkGLPixmap *glpixmap = GDK_GL_PIXMAP (object);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_finalize ()"));

  if (glpixmap->glconfig != NULL)
    {
      g_object_unref (G_OBJECT (glpixmap->glconfig));
      glpixmap->glconfig = NULL;
    }

  /*
  if (glpixmap->wrapper != NULL)
    {
      g_object_unref (G_OBJECT (glpixmap->wrapper));
      glpixmap->wrapper = NULL;
    }
  */

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

/*< private >*/
gboolean
_gdk_gl_pixmap_is_double_buffered (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (gldrawable), FALSE);

  return gdk_gl_config_is_double_buffered (GDK_GL_PIXMAP (gldrawable)->glconfig);
}

/*
 * OpenGL extension to GdkPixmap
 */

static const gchar quark_gl_pixmap_string[] = "gdk-gl-pixmap-gl-pixmap";
static GQuark quark_gl_pixmap = 0;

static void
gl_pixmap_destroy (GdkGLPixmap *glpixmap)
{
  if (glpixmap != NULL)
    g_object_unref (G_OBJECT (glpixmap));
}

/**
 * gdk_pixmap_set_gl_capability:
 * @pixmap: the #GdkPixmap to be used as the rendering area.
 * @glconfig: a #GdkGLConfig.
 * @attrib_list: this must be set to NULL or empty (first attribute of None).
 *
 * Set the OpenGL-capability to the #GdkPixmap.
 * The call creates a new #GdkGLPixmap.
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None).
 *
 * Return value: the #GdkGLPixmap used by the #GdkPixmap if it is successful, NULL otherwise.
 **/
GdkGLPixmap *
gdk_pixmap_set_gl_capability (GdkPixmap    *pixmap,
                              GdkGLConfig  *glconfig,
                              const gint   *attrib_list)
{
  GdkGLPixmap *glpixmap;

  g_return_val_if_fail (GDK_IS_PIXMAP (pixmap), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  /*
   * Initialize quarks
   */

  if (quark_gl_pixmap == 0)
    quark_gl_pixmap = g_quark_from_static_string (quark_gl_pixmap_string);

  /* If already set */
  glpixmap = g_object_get_qdata (G_OBJECT (pixmap), quark_gl_pixmap);
  if (glpixmap != NULL)
    return glpixmap;

  /*
   * Create GdkGLPixmap
   */

  glpixmap = gdk_gl_pixmap_new (glconfig, pixmap, attrib_list);
  if (glpixmap == NULL)
    {
      g_warning ("cannot create GdkGLPixmap\n");
      goto FAIL;
    }

  g_object_set_qdata_full (G_OBJECT (pixmap), quark_gl_pixmap, glpixmap,
                           (GDestroyNotify) gl_pixmap_destroy);

  return glpixmap;

 FAIL:

  g_object_set_qdata (G_OBJECT (pixmap), quark_gl_pixmap, NULL);

  return NULL;
}

/**
 * gdk_pixmap_unset_gl_capability:
 * @pixmap: a #GdkPixmap.
 *
 * Unset the OpenGL-capability of the #GdkPixmap.
 * The call destroys the #GdkGLPixmap holded by the #GdkPixmap.
 *
 **/
void
gdk_pixmap_unset_gl_capability (GdkPixmap *pixmap)
{
  /*
   * If quarks are not initialized
   */

  if (quark_gl_pixmap == 0)
    quark_gl_pixmap = g_quark_from_static_string (quark_gl_pixmap_string);

  /*
   * Unref OpenGL-related data of the pixmap
   */

  g_object_set_qdata (G_OBJECT (pixmap), quark_gl_pixmap, NULL);
}

/**
 * gdk_pixmap_is_gl_capable:
 * @pixmap: a #GdkPixmap.
 *
 * Return whether the #GdkPixmap is OpenGL-capable.
 *
 * Return value: TRUE if the #GdkPixmap is OpenGL-capable, FALSE otherwise.
 **/
gboolean
gdk_pixmap_is_gl_capable (GdkPixmap *pixmap)
{
  g_return_val_if_fail (GDK_IS_PIXMAP (pixmap), FALSE);

  return g_object_get_qdata (G_OBJECT (pixmap), quark_gl_pixmap) != NULL ? TRUE : FALSE;
}

/**
 * gdk_pixmap_get_gl_pixmap:
 * @pixmap: a #GdkPixmap.
 *
 * Return the #GdkGLPixmap holded by the #GdkPixmap.
 *
 * Return value: the #GdkGLPixmap.
 **/
GdkGLPixmap *
gdk_pixmap_get_gl_pixmap (GdkPixmap *pixmap)
{
  g_return_val_if_fail (GDK_IS_PIXMAP (pixmap), NULL);

  return g_object_get_qdata (G_OBJECT (pixmap), quark_gl_pixmap);
}
