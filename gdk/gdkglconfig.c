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

static GdkGLConfig *gdk_gl_config_new_ci       (GdkGLConfigMode mode);
static GdkGLConfig *gdk_gl_config_new_rgb      (GdkGLConfigMode mode);
static GdkGLConfig *gdk_gl_config_new_internal (GdkGLConfigMode mode);

static gpointer parent_class = NULL;

GType
gdk_gl_config_mode_get_type (void)
{
  static GType etype = 0;

  if (!etype)
    {
      static const GFlagsValue values[] = {
        { GDK_GL_MODE_RGB,         "GDK_GL_MODE_RGB",         "rgb" },
        { GDK_GL_MODE_RGBA,        "GDK_GL_MODE_RGBA",        "rgba" },
        { GDK_GL_MODE_INDEX,       "GDK_GL_MODE_INDEX",       "index" },
        { GDK_GL_MODE_SINGLE,      "GDK_GL_MODE_SINGLE",      "single" },
        { GDK_GL_MODE_DOUBLE,      "GDK_GL_MODE_DOUBLE",      "double" },
        { GDK_GL_MODE_ACCUM,       "GDK_GL_MODE_ACCUM",       "accum" },
        { GDK_GL_MODE_ALPHA,       "GDK_GL_MODE_ALPHA",       "alpha" },
        { GDK_GL_MODE_DEPTH,       "GDK_GL_MODE_DEPTH",       "depth" },
        { GDK_GL_MODE_STENCIL,     "GDK_GL_MODE_STENCIL",     "stencil" },
        { GDK_GL_MODE_STEREO,      "GDK_GL_MODE_STEREO",      "stereo" },
        { GDK_GL_MODE_MULTISAMPLE, "GDK_GL_MODE_MULTISAMPLE", "multisample" },
        { GDK_GL_MODE_LUMINANCE,   "GDK_GL_MODE_LUMINANCE",   "luminance" },
        { 0, NULL, NULL }
      };

      etype = g_flags_register_static ("GdkGLConfigMode", values);
    }

  return etype;
}

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

static GdkGLConfig *
gdk_gl_config_new_ci (GdkGLConfigMode mode)
{
  static const gint buf_size_list[] = { 16, 12, 8, 4, 2, 1, 0 };
  gint list[32];
  GdkGLConfig *glconfig = NULL;
  int n = 0;
  int i;

  list[n++] = GDK_GL_BUFFER_SIZE;
  list[n++] = 1;
  if (mode & GDK_GL_MODE_DOUBLE)
    {
      list[n++] = GDK_GL_DOUBLEBUFFER;
    }
  if (mode & GDK_GL_MODE_STEREO)
    {
      list[n++] = GDK_GL_STEREO;
    }
  if (mode & GDK_GL_MODE_DEPTH)
    {
      list[n++] = GDK_GL_DEPTH_SIZE;
      list[n++] = 1;
    }
  if (mode & GDK_GL_MODE_STENCIL)
    {
      list[n++] = GDK_GL_STENCIL_SIZE;
      list[n++] = 1;
    }
  list[n] = GDK_GL_ATTRIB_LIST_NONE;

  /* from GLUT */
  /* glXChooseVisual specify GLX_BUFFER_SIZE prefers the
     "smallest index buffer of at least the specified size".
     This would be reasonable if GLUT allowed the user to
     specify the required buffe size, but GLUT's display mode
     is too simplistic (easy to use?). GLUT should try to find
     the "largest".  So start with a large buffer size and
     shrink until we find a matching one that exists. */

  for (i = 0; buf_size_list[i]; i++)
    {
      /* XXX Assumes list[1] is where GDK_GL_BUFFER_SIZE parameter is. */
      list[1] = buf_size_list[i];
      glconfig = gdk_gl_config_new (list);
      if (glconfig != NULL)
        return glconfig;
    }

  return NULL;
}

static GdkGLConfig *
gdk_gl_config_new_rgb (GdkGLConfigMode mode)
{
  gint list[32];
  int n = 0;

  list[n++] = GDK_GL_RGBA;
  list[n++] = GDK_GL_RED_SIZE;
  list[n++] = 1;
  list[n++] = GDK_GL_GREEN_SIZE;
  list[n++] = 1;
  list[n++] = GDK_GL_BLUE_SIZE;
  list[n++] = 1;
  if (mode & GDK_GL_MODE_ALPHA)
    {
      list[n++] = GDK_GL_ALPHA_SIZE;
      list[n++] = 1;
    }
  if (mode & GDK_GL_MODE_DOUBLE)
    {
      list[n++] = GDK_GL_DOUBLEBUFFER;
    }
  if (mode & GDK_GL_MODE_STEREO)
    {
      list[n++] = GDK_GL_STEREO;
    }
  if (mode & GDK_GL_MODE_DEPTH)
    {
      list[n++] = GDK_GL_DEPTH_SIZE;
      list[n++] = 1;
    }
  if (mode & GDK_GL_MODE_STENCIL)
    {
      list[n++] = GDK_GL_STENCIL_SIZE;
      list[n++] = 1;
    }
  if (mode & GDK_GL_MODE_ACCUM)
    {
      list[n++] = GDK_GL_ACCUM_RED_SIZE;
      list[n++] = 1;
      list[n++] = GDK_GL_ACCUM_GREEN_SIZE;
      list[n++] = 1;
      list[n++] = GDK_GL_ACCUM_BLUE_SIZE;
      list[n++] = 1;
      if (mode & GDK_GL_MODE_ALPHA)
        {
          list[n++] = GDK_GL_ACCUM_ALPHA_SIZE;
          list[n++] = 1;
        }
    }
  list[n] = GDK_GL_ATTRIB_LIST_NONE;

  return gdk_gl_config_new (list);
}

static GdkGLConfig *
gdk_gl_config_new_internal (GdkGLConfigMode mode)
{
  if (mode & GDK_GL_MODE_RGB)
    return gdk_gl_config_new_rgb (mode);
  else
    return gdk_gl_config_new_ci (mode);
}

/**
 * gdk_gl_config_new_by_mode:
 * @mode: display mode bit mask.
 *
 * Returns an OpenGL frame buffer configuration that match the specified
 * display mode.
 *
 * Return value: the new #GdkGLConfig.
 **/
GdkGLConfig *
gdk_gl_config_new_by_mode (GdkGLConfigMode mode)
{
  GdkGLConfig *glconfig = NULL;

  glconfig = gdk_gl_config_new_internal (mode);

  if (glconfig == NULL)
    {
      /* Fallback cases when can't get exactly what was asked for... */
      if (mode & GDK_GL_MODE_SINGLE)
        {
          /* If we can't find a single buffered visual, try looking
             for a double buffered visual.  We can treat a double
             buffered visual as a single buffered visual by changing
             the draw buffer to GL_FRONT and treating any swap
             buffers as no-ops. */
          mode |= GDK_GL_MODE_DOUBLE;
          glconfig = gdk_gl_config_new_internal (mode);
          if (glconfig != NULL)
            glconfig->as_single_mode = TRUE;
        }
    }

  return glconfig;
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
