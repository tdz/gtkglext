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

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglconfig-x11.h"
#include "gdkglcontext-x11.h"
#include "gdkglwindow-x11.h"

#include <gdk/gdkglquery.h>

#include <string.h>

/* Forward declarations */
static gboolean gdk_x11_gl_window_make_context_current (GdkGLDrawable           *draw,
                                                        GdkGLDrawable           *read,
                                                        GdkGLContext            *glcontext);
static void     gdk_x11_gl_window_swap_buffers         (GdkGLDrawable           *gldrawable);
static gboolean gdk_x11_gl_window_gl_begin             (GdkGLDrawable           *draw,
                                                        GdkGLDrawable           *read,
                                                        GdkGLContext            *glcontext);
static void     gdk_x11_gl_window_gl_end               (GdkGLDrawable           *gldrawable);

static void     gdk_gl_window_impl_x11_init            (GdkGLWindowImplX11      *impl);
static void     gdk_gl_window_impl_x11_class_init      (GdkGLWindowImplX11Class *klass);

static GObject *gdk_gl_window_impl_x11_constructor     (GType                    type,
                                                        guint                    n_construct_properties,
                                                        GObjectConstructParam   *construct_properties);
static void     gdk_gl_window_impl_x11_finalize        (GObject                 *object);

static void     gdk_gl_window_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface);

static gpointer parent_class = NULL;

GType
gdk_gl_window_impl_x11_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLWindowImplX11Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_window_impl_x11_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLWindowImplX11),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_window_impl_x11_init,
      };
      static const GInterfaceInfo gl_drawable_interface_info = {
        (GInterfaceInitFunc) gdk_gl_window_impl_x11_gl_drawable_interface_init,
        (GInterfaceFinalizeFunc) NULL,
        NULL                    /* interface_data */
      };

      type = g_type_register_static (GDK_TYPE_GL_WINDOW,
                                     "GdkGLWindowImplX11",
                                     &type_info, 0);
      g_type_add_interface_static (type,
                                   GDK_TYPE_GL_DRAWABLE,
                                   &gl_drawable_interface_info);
    }

  return type;
}

static void
gdk_gl_window_impl_x11_init (GdkGLWindowImplX11 *impl)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_window_impl_x11_class_init (GdkGLWindowImplX11Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor = gdk_gl_window_impl_x11_constructor;
  object_class->finalize    = gdk_gl_window_impl_x11_finalize;
}

static GObject *
gdk_gl_window_impl_x11_constructor (GType                  type,
                                    guint                  n_construct_properties,
                                    GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLWindow *glwindow;
  GdkGLWindowImplX11 *impl;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_constructor ()"));

  glwindow = GDK_GL_WINDOW (object);
  impl = GDK_GL_WINDOW_IMPL_X11 (object);

  /*
   * Associated GdkWindow.
   */
  impl->glxwindow = GDK_DRAWABLE_XID (glwindow->drawable);

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

  return object;
}

static void
gdk_gl_window_impl_x11_finalize (GObject *object)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplX11 *impl;
  Display *xdisplay;
  int screen_num;
  GdkGL_GLX_MESA_release_buffers *mesa_ext;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_finalize ()"));

  glwindow = GDK_GL_WINDOW (object);
  impl = GDK_GL_WINDOW_IMPL_X11 (object);

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glwindow->glconfig);
  screen_num = GDK_GL_CONFIG_SCREEN_XNUMBER (glwindow->glconfig);

  /* If GLX_MESA_release_buffers is supported. */
  mesa_ext = gdk_gl_get_GLX_MESA_release_buffers (glwindow->glconfig);
  if (mesa_ext)
    {
      GDK_GL_NOTE (IMPL, g_message (" * glXReleaseBuffersMESA ()"));
      mesa_ext->glXReleaseBuffersMESA (xdisplay,
                                       GDK_GL_WINDOW_GLXWINDOW (glwindow));
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_window_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_gl_drawable_interface_init ()"));

  iface->create_new_context   = _gdk_x11_gl_context_new;
  iface->make_context_current =  gdk_x11_gl_window_make_context_current;
  iface->is_double_buffered   = _gdk_gl_window_is_double_buffered;
  iface->swap_buffers         =  gdk_x11_gl_window_swap_buffers;
  iface->wait_gl              = _gdk_x11_gl_drawable_wait_gl;
  iface->wait_gdk             = _gdk_x11_gl_drawable_wait_gdk;
  iface->gl_begin             =  gdk_x11_gl_window_gl_begin;
  iface->gl_end               =  gdk_x11_gl_window_gl_end;
  iface->get_gl_config        = _gdk_gl_window_get_gl_config;
  iface->get_size             = _gdk_gl_window_get_size;
}

static gboolean
gdk_x11_gl_window_make_context_current (GdkGLDrawable *draw,
                                        GdkGLDrawable *read,
                                        GdkGLContext  *glcontext)
{
  GdkGLWindow *glwindow;
  Display *xdisplay;
  Window glxwindow;
  GLXContext glxcontext;

  g_return_val_if_fail (GDK_IS_GL_WINDOW (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  glwindow = GDK_GL_WINDOW (draw);

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glwindow->glconfig);
  glxwindow = GDK_GL_WINDOW_GLXWINDOW (glwindow);
  glxcontext = GDK_GL_CONTEXT_GLXCONTEXT (glcontext);

  if (xdisplay == glXGetCurrentDisplay () &&
      glxwindow == glXGetCurrentDrawable () &&
      glxcontext == glXGetCurrentContext ())
    return TRUE;

  GDK_GL_NOTE (IMPL, g_message (" * glXMakeCurrent ()"));

  if (!glXMakeCurrent (xdisplay, glxwindow, glxcontext))
    {
      _gdk_gl_context_set_gl_drawable (glcontext, NULL);
      _gdk_gl_context_set_gl_drawable_read (glcontext, NULL);
      return FALSE;
    }

  _gdk_gl_context_set_gl_drawable (glcontext, draw);
  _gdk_gl_context_set_gl_drawable_read (glcontext, read);

  if (GDK_GL_CONFIG_AS_SINGLE_MODE(glwindow->glconfig))
    {
      /* We do this because we are treating a double-buffered frame
         buffer as a single-buffered frame buffer because the system
         does not appear to export any suitable single-buffered
         visuals (in which the following are necessary). */
      glDrawBuffer(GL_FRONT);
      glReadBuffer(GL_FRONT);
    }

  return TRUE;
}

static void
gdk_x11_gl_window_swap_buffers (GdkGLDrawable *gldrawable)
{
  GdkGLWindow *glwindow;

  g_return_if_fail (GDK_IS_GL_WINDOW (gldrawable));

  glwindow = GDK_GL_WINDOW (gldrawable);

  GDK_GL_NOTE (IMPL, g_message (" * glXSwapBuffers ()"));

  glXSwapBuffers (GDK_GL_CONFIG_XDISPLAY (glwindow->glconfig),
                  GDK_GL_WINDOW_GLXWINDOW (glwindow));
}

static gboolean
gdk_x11_gl_window_gl_begin (GdkGLDrawable *draw,
                            GdkGLDrawable *read,
                            GdkGLContext  *glcontext)
{
  gboolean ret;

  ret = gdk_x11_gl_window_make_context_current (draw, read, glcontext);
  if (!ret)
    return FALSE;

  _gdk_x11_gl_drawable_wait_gdk (draw);

  return TRUE;
}

static void
gdk_x11_gl_window_gl_end (GdkGLDrawable *gldrawable)
{
  /* do nothing */
}

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 */
/**
 * gdk_gl_window_new:
 * @glconfig: a #GdkGLConfig.
 * @window: the #GdkWindow to be used as the rendering area.
 * @attrib_list: this must be set to NULL or empty (first attribute of None).
 *
 * Create an on-screen rendering area.
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 *
 * Return value: the new #GdkGLWindow.
 **/
GdkGLWindow *
gdk_gl_window_new (GdkGLConfig *glconfig,
                   GdkWindow   *window,
                   const int   *attrib_list)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_window_new ()"));

  /*
   * Instanciate the GdkGLWindowImplX11 object.
   */
  glwindow = g_object_new (GDK_TYPE_GL_WINDOW_IMPL_X11,
                           "glconfig", glconfig,
                           "drawable", GDK_DRAWABLE (window),
                           NULL);
  impl = GDK_GL_WINDOW_IMPL_X11 (glwindow);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glwindow));
      return NULL;
    }

  return glwindow;
}

/**
 * gdk_x11_gl_window_get_glxwindow:
 * @glwindow: a #GdkGLWindow.
 *
 * Get X Window.
 *
 * Return value: the Window.
 **/
Window
gdk_x11_gl_window_get_glxwindow (GdkGLWindow *glwindow)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (glwindow), None);

  return GDK_GL_WINDOW_IMPL_X11 (glwindow)->glxwindow;
}
