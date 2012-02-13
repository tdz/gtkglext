/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2012 Thomas Zimmermann
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

#include <gdk/gdkgldebug.h>
#include <gdk/x11/gdkglx.h>

#include "gdkglwindow-x11.h"

struct _GdkX11GLWindow
{
  GdkGLWindow parent;
};

struct _GdkX11GLWindowClass
{
  GdkGLWindowClass parent_class;
};

static GdkGLContext *_gdk_x11_gl_window_create_gl_context   (GdkGLDrawable *gldrawable,
                                                             GdkGLContext  *share_list,
                                                             gboolean       direct,
                                                             int            render_type);
static gboolean      _gdk_x11_gl_window_is_double_buffered  (GdkGLDrawable *gldrawable);
static void          _gdk_x11_gl_window_swap_buffers        (GdkGLDrawable *gldrawable);
static void          _gdk_x11_gl_window_wait_gl             (GdkGLDrawable *gldrawable);
static void          _gdk_x11_gl_window_wait_gdk            (GdkGLDrawable *gldrawable);
static GdkGLConfig  *_gdk_x11_gl_window_get_gl_config       (GdkGLDrawable *gldrawable);

static void gdk_x11_gl_window_gl_drawable_interface_init (GdkGLDrawableClass *iface);

G_DEFINE_TYPE_EXTENDED (GdkX11GLWindow,
                        gdk_x11_gl_window,
                        GDK_TYPE_GL_WINDOW,
                        0,
                        G_IMPLEMENT_INTERFACE (
                          GDK_TYPE_GL_DRAWABLE,
                          gdk_x11_gl_window_gl_drawable_interface_init))

static void
gdk_x11_gl_window_init (GdkX11GLWindow *self)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();
}

static void
gdk_x11_gl_window_finalize (GObject *object)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();

  G_OBJECT_CLASS (gdk_x11_gl_window_parent_class)->finalize (object);
}

static void
gdk_x11_gl_window_class_init (GdkX11GLWindowClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE_FUNC_PRIVATE ();

  object_class->finalize = gdk_x11_gl_window_finalize;
}

static void
gdk_x11_gl_window_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();

  iface->create_gl_context_impl = _gdk_x11_gl_window_create_gl_context;
  iface->is_double_buffered     = _gdk_x11_gl_window_is_double_buffered;
  iface->swap_buffers           = _gdk_x11_gl_window_swap_buffers;
  iface->wait_gl                = _gdk_x11_gl_window_wait_gl;
  iface->wait_gdk               = _gdk_x11_gl_window_wait_gdk;
  iface->get_gl_config          = _gdk_x11_gl_window_get_gl_config;
}

static GdkGLContext *_gdk_x11_gl_window_create_gl_context (GdkGLDrawable *gldrawable,
                                                           GdkGLContext  *share_list,
                                                           gboolean       direct,
                                                           int            render_type)
{
  g_return_val_if_fail(GDK_IS_X11_GL_WINDOW(gldrawable), NULL);

  return GDK_GL_WINDOW_IMPL_GET_CLASS(GDK_GL_WINDOW(gldrawable)->impl)->create_gl_context(gldrawable,
                                                                                          share_list,
                                                                                          direct,
                                                                                          render_type);
}

static gboolean _gdk_x11_gl_window_is_double_buffered (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail(GDK_IS_X11_GL_WINDOW(gldrawable), FALSE);

  return GDK_GL_WINDOW_IMPL_GET_CLASS(GDK_GL_WINDOW(gldrawable)->impl)->is_double_buffered(gldrawable);
}

static void _gdk_x11_gl_window_swap_buffers (GdkGLDrawable *gldrawable)
{
  g_return_if_fail(GDK_IS_X11_GL_WINDOW(gldrawable));

  GDK_GL_WINDOW_IMPL_GET_CLASS(GDK_GL_WINDOW(gldrawable)->impl)->swap_buffers(gldrawable);
}

static void _gdk_x11_gl_window_wait_gl (GdkGLDrawable *gldrawable)
{
  g_return_if_fail(GDK_IS_X11_GL_WINDOW(gldrawable));

  GDK_GL_WINDOW_IMPL_GET_CLASS(GDK_GL_WINDOW(gldrawable)->impl)->wait_gl(gldrawable);
}

static void _gdk_x11_gl_window_wait_gdk (GdkGLDrawable *gldrawable)
{
  g_return_if_fail(GDK_IS_X11_GL_WINDOW(gldrawable));

  GDK_GL_WINDOW_IMPL_GET_CLASS(GDK_GL_WINDOW(gldrawable)->impl)->wait_gdk(gldrawable);
}

static GdkGLConfig  *_gdk_x11_gl_window_get_gl_config (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail(GDK_IS_X11_GL_WINDOW(gldrawable), NULL);

  return GDK_GL_WINDOW_IMPL_GET_CLASS(GDK_GL_WINDOW(gldrawable)->impl)->get_gl_config(gldrawable);
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
  g_return_val_if_fail (GDK_IS_X11_GL_WINDOW (glwindow), None);

  return GDK_GL_WINDOW_IMPL_X11_CLASS (glwindow->impl)->get_glxwindow(glwindow);
}
