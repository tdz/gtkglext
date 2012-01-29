/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002-2004  Naofumi Yasufuku
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <string.h>

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglconfig-x11.h"
#include "gdkglcontext-x11.h"
#include "gdkglwindow-x11.h"

#include <gdk/gdkglquery.h>

static gboolean     _gdk_x11_gl_window_impl_is_double_buffered   (GdkGLDrawable *gldrawable);
static void         _gdk_x11_gl_window_impl_swap_buffers         (GdkGLDrawable *gldrawable);
static GdkGLConfig *_gdk_x11_gl_window_impl_get_gl_config        (GdkGLDrawable *gldrawable);

static void         gdk_gl_window_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface);

G_DEFINE_TYPE_EXTENDED (GdkGLWindowImplX11,
                        gdk_gl_window_impl_x11,
                        GDK_TYPE_GL_WINDOW,
                        0,
                        G_IMPLEMENT_INTERFACE
                        (GDK_TYPE_GL_DRAWABLE,
                         gdk_gl_window_impl_x11_gl_drawable_interface_init))

static void
gdk_gl_window_impl_x11_init (GdkGLWindowImplX11 *self)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();

  self->glxwindow = None;
  self->glconfig = NULL;
  self->is_destroyed = 0;
}

static void
_gdk_x11_gl_window_impl_destroy (GdkGLWindow *glwindow)
{
  GdkGLWindowImplX11 *impl = GDK_GL_WINDOW_IMPL_X11 (glwindow);
  Display *xdisplay;
  Bool (APIENTRY *ReleaseBuffersMESA) (Display*, GLXDrawable);

  GDK_GL_NOTE_FUNC_PRIVATE ();

  if (impl->is_destroyed)
    return;

  xdisplay = GDK_GL_CONFIG_XDISPLAY (impl->glconfig);

  if (impl->glxwindow == glXGetCurrentDrawable ())
    {
      glXWaitGL ();

      GDK_GL_NOTE_FUNC_IMPL ("glXMakeCurrent");
      glXMakeCurrent (xdisplay, None, NULL);
    }

  if (gdk_x11_gl_query_glx_extension (impl->glconfig, "GLX_MESA_release_buffers"))
    {
      /* Release buffers if GLX_MESA_release_buffers is supported. */

      ReleaseBuffersMESA = (Bool (APIENTRY *)(Display*, GLXDrawable))
        gdk_gl_get_proc_address("glXReleaseBuffersMESA");

      GDK_GL_NOTE_FUNC_IMPL ("glXReleaseBuffersMESA");
      if (ReleaseBuffersMESA)
        ReleaseBuffersMESA (xdisplay, impl->glxwindow);
    }

  impl->glxwindow = None;

  impl->is_destroyed = TRUE;
}

static void
gdk_gl_window_impl_x11_finalize (GObject *object)
{
  GdkGLWindowImplX11 *impl = GDK_GL_WINDOW_IMPL_X11 (object);

  GDK_GL_NOTE_FUNC_PRIVATE ();

  _gdk_x11_gl_window_impl_destroy (GDK_GL_WINDOW (object));

  g_object_unref (G_OBJECT (impl->glconfig));

  G_OBJECT_CLASS (gdk_gl_window_impl_x11_parent_class)->finalize (object);
}

static void
gdk_gl_window_impl_x11_class_init (GdkGLWindowImplX11Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE_FUNC_PRIVATE ();

  klass->parent_class.destroy_window = _gdk_x11_gl_window_impl_destroy;

  object_class->finalize = gdk_gl_window_impl_x11_finalize;
}

static void
gdk_gl_window_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();

  iface->create_new_context   = _gdk_x11_gl_context_impl_new;
  iface->is_double_buffered   = _gdk_x11_gl_window_impl_is_double_buffered;
  iface->swap_buffers         = _gdk_x11_gl_window_impl_swap_buffers;
  iface->wait_gl              = _gdk_gl_drawable_impl_x11_wait_gl;
  iface->wait_gdk             = _gdk_gl_drawable_impl_x11_wait_gdk;
  iface->get_gl_config        = _gdk_x11_gl_window_impl_get_gl_config;
}

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 */
GdkGLWindow *
_gdk_x11_gl_window_impl_new (GdkGLConfig *glconfig,
                             GdkWindow   *window,
                             const int   *attrib_list)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplX11 *impl;

  /* GLXWindow glxwindow; */
  Window glxwindow;

  GDK_GL_NOTE_FUNC ();

  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), NULL);
  g_return_val_if_fail (GDK_IS_WINDOW (window), NULL);

  /*
   * Get X Window.
   */

  glxwindow = GDK_WINDOW_XID (window);

  /*
   * Instantiate the GdkGLWindowImplX11 object.
   */

  glwindow = g_object_new (GDK_TYPE_GL_WINDOW_IMPL_X11, NULL);
  impl = GDK_GL_WINDOW_IMPL_X11 (glwindow);

  glwindow->window = window;
  g_object_add_weak_pointer (G_OBJECT (glwindow->window),
                             (gpointer *) &(glwindow->window));

  impl->glxwindow = glxwindow;

  impl->glconfig = glconfig;
  g_object_ref (G_OBJECT (impl->glconfig));

  impl->is_destroyed = FALSE;

  return glwindow;
}

static gboolean
_gdk_x11_gl_window_impl_is_double_buffered (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW_IMPL_X11 (gldrawable), FALSE);

  return gdk_gl_config_is_double_buffered (GDK_GL_WINDOW_IMPL_X11 (gldrawable)->glconfig);
}

static void
_gdk_x11_gl_window_impl_swap_buffers (GdkGLDrawable *gldrawable)
{
  Display *xdisplay;
  Window glxwindow;

  g_return_if_fail (GDK_IS_GL_WINDOW_IMPL_X11 (gldrawable));

  xdisplay = GDK_GL_CONFIG_XDISPLAY (GDK_GL_WINDOW_IMPL_X11 (gldrawable)->glconfig);
  glxwindow = GDK_GL_WINDOW_IMPL_X11 (gldrawable)->glxwindow;

  if (glxwindow == None)
    return;

  GDK_GL_NOTE_FUNC_IMPL ("glXSwapBuffers");

  glXSwapBuffers (xdisplay, glxwindow);
}

static GdkGLConfig *
_gdk_x11_gl_window_impl_get_gl_config (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW_IMPL_X11 (gldrawable), NULL);

  return GDK_GL_WINDOW_IMPL_X11 (gldrawable)->glconfig;
}

/**
 * gdk_x11_gl_window_get_glxwindow:
 * @glwindow: a #GdkGLWindow.
 *
 * Gets X Window.
 *
 * Return value: the Window.
 **/
Window
gdk_x11_gl_window_get_glxwindow (GdkGLWindow *glwindow)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW_IMPL_X11 (glwindow), None);

  return GDK_GL_WINDOW_IMPL_X11 (glwindow)->glxwindow;
}
