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

#ifdef GDK_MULTIHEAD_SAFE
#include <gdk/gdkscreen.h>
#endif /* GDK_MULTIHEAD_SAFE */

#include <gdk/gdkwindow.h>
#include "gdkglprivate.h"
#include "gdkglconfig.h"

enum {
  PROP_0,
  PROP_SCREEN
};

static void     gdk_gl_config_init         (GdkGLConfig           *glconfig);
static void     gdk_gl_config_class_init   (GdkGLConfigClass      *klass);

static GObject *gdk_gl_config_constructor  (GType                  type,
                                            guint                  n_construct_properties,
                                            GObjectConstructParam *construct_properties);
static void     gdk_gl_config_set_property (GObject               *object,
                                            guint                  property_id,
                                            const GValue          *value,
                                            GParamSpec            *pspec);
static void     gdk_gl_config_get_property (GObject               *object,
                                            guint                  property_id,
                                            GValue                *value,
                                            GParamSpec            *pspec);
static void     gdk_gl_config_finalize     (GObject               *object);

static gpointer parent_class = NULL;

GType
gdk_gl_config_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLConfigClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_config_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLConfig),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_config_init,
      };

      type = g_type_register_static (G_TYPE_OBJECT,
                                     "GdkGLConfig",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_config_init (GdkGLConfig *glconfig)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_init ()"));

  glconfig->is_double_buffered = FALSE;
  glconfig->is_stereo = FALSE;
}

static void
gdk_gl_config_class_init (GdkGLConfigClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor  = gdk_gl_config_constructor;
  object_class->set_property = gdk_gl_config_set_property;
  object_class->get_property = gdk_gl_config_get_property;
  object_class->finalize     = gdk_gl_config_finalize;

#ifdef GDK_MULTIHEAD_SAFE
  g_object_class_install_property (object_class,
                                   PROP_SCREEN,
                                   g_param_spec_object ("screen",
                                                        _("Screen"),
                                                        _("Target screen for the OpenGL configuration."),
                                                        GDK_TYPE_SCREEN,
                                                        G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
#else  /* GDK_MULTIHEAD_SAFE */
  g_object_class_install_property (object_class,
                                   PROP_SCREEN,
                                   g_param_spec_pointer ("screen",
                                                         _("Screen"),
                                                         _("Target screen for the OpenGL configuration."),
                                                         G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
#endif /* GDK_MULTIHEAD_SAFE */
}

static GObject *
gdk_gl_config_constructor (GType                  type,
                           guint                  n_construct_properties,
                           GObjectConstructParam *construct_properties)
{
  GObject *object;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_constructor ()"));

  return object;
}

static void
gdk_gl_config_set_property (GObject      *object,
                            guint         property_id,
                            const GValue *value,
                            GParamSpec   *pspec)
{
  GdkGLConfig *glconfig = GDK_GL_CONFIG (object);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_set_property ()"));

  switch (property_id)
    {
    case PROP_SCREEN:
#ifdef GDK_MULTIHEAD_SAFE
      glconfig->screen = g_value_get_object (value);
      g_object_ref (G_OBJECT (glconfig->screen));
#else  /* GDK_MULTIHEAD_SAFE */
      glconfig->screen = g_value_get_pointer (value);
#endif /* GDK_MULTIHEAD_SAFE */
      g_object_notify (object, "screen");
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_config_get_property (GObject    *object,
                            guint       property_id,
                            GValue     *value,
                            GParamSpec *pspec)
{
  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_get_property ()"));

  switch (property_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_config_finalize (GObject *object)
{
  GdkGLConfig *glconfig = GDK_GL_CONFIG (object);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_finalize ()"));

  if (glconfig->colormap != NULL)
    {
      g_object_unref (G_OBJECT (glconfig->colormap));
      glconfig->colormap = NULL;
    }

#ifdef GDK_MULTIHEAD_SAFE
  if (glconfig->screen != NULL)
    {
      g_object_unref (G_OBJECT (glconfig->screen));
      glconfig->screen = NULL;
    }
#endif /* GDK_MULTIHEAD_SAFE */

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

#ifdef GDK_MULTIHEAD_SAFE

GdkScreen *
gdk_gl_config_get_screen (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return glconfig->screen;
}

#endif /* GDK_MULTIHEAD_SAFE */

/**
 * gdk_gl_config_get_attrib:
 * @glconfig: a #GdkGLConfig.
 * @attribute: the attribute to be returned.
 * @value: returns the requested value.
 *
 * Return information about a OpenGL frame buffer configuration.
 *
 * Return value: an error code if it fails for any reason, otherwise, GDK_GL_SUCCESS is returned.
 **/
gboolean
gdk_gl_config_get_attrib (GdkGLConfig *glconfig,
                          gint         attribute,
                          gint        *value)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return GDK_GL_CONFIG_GET_CLASS (glconfig)->get_attrib (glconfig, attribute, value);
}

/**
 * gdk_gl_config_get_colormap:
 * @glconfig: a #GdkGLConfig.
 *
 * Get the colormap that is appropriate for the OpenGL frame buffer
 * configuration.
 *
 * Return value: the appropriate colormap.
 **/
GdkColormap *
gdk_gl_config_get_colormap (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return glconfig->colormap;
}

/**
 * gdk_gl_config_get_depth:
 * @glconfig: a #GdkGLConfig.
 *
 * Get the depth (number of bits per pixel) of the OpenGL-capable visual.
 *
 * Return value: the depth value.
 **/
gint
gdk_gl_config_get_depth (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->depth;
}

/**
 * gdk_gl_config_is_double_buffered:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the configuration supports the double-buffered visual.
 *
 * Return value: TRUE if the double-buffered visual is supported, FALSE otherwise.
 **/
gboolean
gdk_gl_config_is_double_buffered (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->is_double_buffered;
}

/**
 * gdk_gl_config_is_stereo:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the configuration supports the stereo visual.
 *
 * Return value: TRUE if the stereo visual is supported, FALSE otherwise.
 **/
gboolean
gdk_gl_config_is_stereo (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->is_stereo;
}
