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

#include <gdk/gdkwindow.h>

#include "gdkglprivate.h"
#include "gdkglconfig.h"

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
#include <gdk/gdkscreen.h>
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

enum {
  PROP_0,
  PROP_SCREEN
};

static void gdk_gl_config_class_init   (GdkGLConfigClass *klass);

static void gdk_gl_config_set_property (GObject          *object,
                                        guint             property_id,
                                        const GValue     *value,
                                        GParamSpec       *pspec);
static void gdk_gl_config_get_property (GObject          *object,
                                        guint             property_id,
                                        GValue           *value,
                                        GParamSpec       *pspec);
static void gdk_gl_config_finalize     (GObject          *object);

static GdkGLConfig *gdk_gl_config_new_ci       (GdkScreen       *screen,
                                                GdkGLConfigMode  mode);
static GdkGLConfig *gdk_gl_config_new_rgb      (GdkScreen       *screen,
                                                GdkGLConfigMode  mode);
static GdkGLConfig *gdk_gl_config_new_internal (GdkScreen       *screen,
                                                GdkGLConfigMode  mode);

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
        (GInstanceInitFunc) NULL,
      };

      type = g_type_register_static (G_TYPE_OBJECT,
                                     "GdkGLConfig",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_config_class_init (GdkGLConfigClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->set_property = gdk_gl_config_set_property;
  object_class->get_property = gdk_gl_config_get_property;
  object_class->finalize     = gdk_gl_config_finalize;

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  g_object_class_install_property (object_class,
                                   PROP_SCREEN,
                                   g_param_spec_object ("screen",
                                                        "Screen",
                                                        "Target screen for the OpenGL frame buffer configuration.",
                                                        GDK_TYPE_SCREEN,
                                                        G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
  g_object_class_install_property (object_class,
                                   PROP_SCREEN,
                                   g_param_spec_pointer ("screen",
                                                         "Screen",
                                                         "Target screen for the OpenGL frame buffer configuration.",
                                                         G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */
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
#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
      glconfig->screen = g_value_get_object (value);
      g_object_ref (G_OBJECT (glconfig->screen));
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
      glconfig->screen = g_value_get_pointer (value);
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */
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

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  if (glconfig->screen != NULL)
    {
      g_object_unref (G_OBJECT (glconfig->screen));
      glconfig->screen = NULL;
    }
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GdkGLConfig *
gdk_gl_config_new_ci (GdkScreen       *screen,
                      GdkGLConfigMode  mode)
{
  GdkGLConfig *glconfig = NULL;
  static const int buf_size_list[] = { 16, 12, 8, 4, 2, 1, 0 };
  int list[32];
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

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
      glconfig = gdk_gl_config_new_for_screen (screen, list);
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
      glconfig = gdk_gl_config_new (list);
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

      if (glconfig != NULL)
        return glconfig;
    }

  return NULL;
}

static GdkGLConfig *
gdk_gl_config_new_rgb (GdkScreen       *screen,
                       GdkGLConfigMode  mode)
{
  int list[32];
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

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  return gdk_gl_config_new_for_screen (screen, list);
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
  return gdk_gl_config_new (list);
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */
}

static GdkGLConfig *
gdk_gl_config_new_internal (GdkScreen       *screen,
                            GdkGLConfigMode  mode)
{
  if (mode & GDK_GL_MODE_RGB)
    return gdk_gl_config_new_rgb (screen, mode);
  else
    return gdk_gl_config_new_ci (screen, mode);
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
  GdkGLConfig *glconfig;

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
#define _GDK_GL_CONFIG_NEW_INTERNAL(__mode) \
   gdk_gl_config_new_internal (gdk_screen_get_default (), __mode)
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
#define _GDK_GL_CONFIG_NEW_INTERNAL(__mode) \
   gdk_gl_config_new_internal (NULL, __mode);
#endif

  glconfig = _GDK_GL_CONFIG_NEW_INTERNAL (mode);

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
          glconfig = _GDK_GL_CONFIG_NEW_INTERNAL (mode);
          if (glconfig != NULL)
            glconfig->as_single_mode = TRUE;
        }
    }

#undef _GDK_GL_CONFIG_NEW_INTERNAL

  return glconfig;
}

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT

GdkGLConfig *
gdk_gl_config_new_by_mode_for_screen (GdkScreen       *screen,
                                      GdkGLConfigMode  mode)
{
  GdkGLConfig *glconfig;

  glconfig = gdk_gl_config_new_internal (screen, mode);

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
          glconfig = gdk_gl_config_new_internal (screen, mode);
          if (glconfig != NULL)
            glconfig->as_single_mode = TRUE;
        }
    }

  return glconfig;
}

#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

GdkScreen *
gdk_gl_config_get_screen (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return glconfig->screen;
}

/**
 * gdk_gl_config_get_attrib:
 * @glconfig: a #GdkGLConfig.
 * @attribute: the attribute to be returned.
 * @value: returns the requested value.
 *
 * Returns information about a OpenGL frame buffer configuration.
 *
 * Returns the value one of the attributes which can be specified in
 * #gdk_gl_config_new.
 *
 * Return value: an error code if it fails for any reason, otherwise, GDK_GL_SUCCESS is returned.
 **/
gboolean
gdk_gl_config_get_attrib (GdkGLConfig *glconfig,
                          int          attribute,
                          int         *value)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return GDK_GL_CONFIG_GET_CLASS (glconfig)->get_attrib (glconfig, attribute, value);
}

/**
 * gdk_gl_config_get_colormap:
 * @glconfig: a #GdkGLConfig.
 *
 * Get the #GdkColormap that is appropriate for the OpenGL frame buffer
 * configuration.
 *
 * Useful to get the appropiate colormap (GdkColormap) for the OpenGL
 * framebuffer.
 *
 * Return value: the appropriate #GdkColormap.
 **/
GdkColormap *
gdk_gl_config_get_colormap (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return glconfig->colormap;
}

/**
 * gdk_gl_config_get_visual:
 * @glconfig: a #GdkGLConfig.
 *
 * Get the #GdkVisual that is appropriate for the OpenGL frame buffer
 * configuration.
 *
 * Return value: the appropriate #GdkVisual.
 **/
GdkVisual *
gdk_gl_config_get_visual (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return gdk_colormap_get_visual (glconfig->colormap);
}

/**
 * gdk_gl_config_get_depth:
 * @glconfig: a #GdkGLConfig.
 *
 * Get the depth (number of bits per pixel) of the OpenGL-capable visual.
 *
 * Color depth is a somehow confusing term. It is defined as the amount of
 * bits per pixel used to define a color. It is confusing because in some
 * environments is expressed as the amount of bits used to define each of
 * the components (RGBA) of the color. Here it will be named as the total
 * amount of bits required to define the whole color.
 *
 * Return value: the depth value.
 **/
gint
gdk_gl_config_get_depth (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), 0);

  return glconfig->depth;
}

/**
 * gdk_gl_config_is_rgba:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the configured frame buffer is RGBA mode.
 *
 * Return value: TRUE if the configured frame buffer is RGBA mode, FALSE otherwise.
 **/
gboolean
gdk_gl_config_is_rgba (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->is_rgba;
}

/**
 * gdk_gl_config_is_double_buffered:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the configuration supports the double-buffered visual.
 *
 * Checks for double buffering use in the #GdkGLConfig struct.
 * Double buffering is a technique use to avoid drawing directly in the
 * viewable area. With double buffering, all entities drawn with OpenGL are
 * stored in an invisible buffer. This buffer is then replaced by the frame
 * buffer. Using Double-buffering, a big amount of memory is used to mantain
 * this buffer, but quality is highly improved. Use #gdk_drawable_swap_buffers
 * to swap buffers when drawing is complete.
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
 * Stereo Viewing deals with all techniques used to give 3D capabilities to
 * a view, as for example are all kind of 3D and VR glasses. Generating 3D
 * vision is a matter only of generating two views of the same scene, one for
 * each eye. OpenGL does not support any specific hardware, but has the
 * underlying support for using it. This function check for stereo support in
 * a #GdkGLConfig struct.
 *
 * Return value: TRUE if the stereo visual is supported, FALSE otherwise.
 **/
gboolean
gdk_gl_config_is_stereo (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->is_stereo;
}

/**
 * gdk_gl_config_has_alpha:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the configured color buffer has alpha bits.
 *
 * Return value: TRUE if the color buffer has alpha bits, FALSE otherwise.
 **/
gboolean
gdk_gl_config_has_alpha (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->has_alpha;
}

/**
 * gdk_gl_config_has_depth_buffer:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the configured frame buffer has depth buffer.
 *
 * Return value: TRUE if the frame buffer has depth buffer, FALSE otherwise.
 **/
gboolean
gdk_gl_config_has_depth_buffer (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->has_depth_buffer;
}

/**
 * gdk_gl_config_has_stencil_buffer:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the configured frame buffer has stencil buffer.
 *
 * Return value: TRUE if the frame buffer has stencil buffer, FALSE otherwise.
 **/
gboolean
gdk_gl_config_has_stencil_buffer (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->has_stencil_buffer;
}

/**
 * gdk_gl_config_has_accum_buffer:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the configured frame buffer has accumulation buffer.
 *
 * Return value: TRUE if the frame buffer has accumulation buffer, FALSE otherwise.
 **/
gboolean
gdk_gl_config_has_accum_buffer (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->has_accum_buffer;
}
