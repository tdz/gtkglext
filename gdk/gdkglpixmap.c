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
  object_class->finalize = gdk_gl_pixmap_finalize;

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
      g_object_ref (G_OBJECT (glpixmap->wrapper));
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

  if (glpixmap->wrapper != NULL)
    {
      g_object_unref (G_OBJECT (glpixmap->wrapper));
      glpixmap->wrapper = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

/*< private >*/
/* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
GdkDrawable *
_gdk_gl_pixmap_real_drawable (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (gldrawable), NULL);

  return GDK_GL_PIXMAP (gldrawable)->wrapper;
}
