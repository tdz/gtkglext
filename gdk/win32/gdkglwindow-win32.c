/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002-2003  Naofumi Yasufuku
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

#include "gdkglwin32.h"
#include "gdkglprivate-win32.h"
#include "gdkglconfig-win32.h"
#include "gdkglcontext-win32.h"
#include "gdkglwindow-win32.h"

/* Forward declarations */

static gboolean     gdk_win32_gl_window_make_context_current (GdkGLDrawable *draw,
                                                              GdkGLDrawable *read,
                                                              GdkGLContext  *glcontext);
static gboolean     gdk_win32_gl_window_is_double_buffered   (GdkGLDrawable *gldrawable);
static void         gdk_win32_gl_window_swap_buffers         (GdkGLDrawable *gldrawable);
static void         gdk_win32_gl_window_wait_gl              (GdkGLDrawable *gldrawable);
static void         gdk_win32_gl_window_wait_gdk             (GdkGLDrawable *gldrawable);
static gboolean     gdk_win32_gl_window_gl_begin             (GdkGLDrawable *draw,
                                                              GdkGLDrawable *read,
                                                              GdkGLContext  *glcontext);
static void         gdk_win32_gl_window_gl_end               (GdkGLDrawable *gldrawable);
static GdkGLConfig *gdk_win32_gl_window_get_gl_config        (GdkGLDrawable *gldrawable);

static void gdk_gl_window_impl_win32_class_init (GdkGLWindowImplWin32Class *klass);

static void gdk_gl_window_impl_win32_finalize   (GObject                   *object);

static void gdk_gl_window_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface);

static gpointer parent_class = NULL;

GType
gdk_gl_window_impl_win32_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLWindowImplWin32Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_window_impl_win32_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLWindowImplWin32),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) NULL,
      };
      static const GInterfaceInfo gl_drawable_interface_info = {
        (GInterfaceInitFunc) gdk_gl_window_impl_win32_gl_drawable_interface_init,
        (GInterfaceFinalizeFunc) NULL,
        NULL                    /* interface_data */
      };

      type = g_type_register_static (GDK_TYPE_GL_WINDOW,
                                     "GdkGLWindowImplWin32",
                                     &type_info, 0);
      g_type_add_interface_static (type,
                                   GDK_TYPE_GL_DRAWABLE,
                                   &gl_drawable_interface_info);
    }

  return type;
}

static void
gdk_gl_window_impl_win32_class_init (GdkGLWindowImplWin32Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->finalize = gdk_gl_window_impl_win32_finalize;
}

static void
gdk_gl_window_impl_win32_finalize (GObject *object)
{
  GdkGLWindowImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_finalize ()"));

  impl = GDK_GL_WINDOW_IMPL_WIN32 (object);

  /* Release DC. */
  if (impl->hdc != NULL)
    {
      ReleaseDC (impl->hwnd, impl->hdc);
      impl->hdc = NULL;
    }

  if (impl->glconfig != NULL)
    {
      g_object_unref (G_OBJECT (impl->glconfig));
      impl->glconfig = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_window_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_gl_drawable_interface_init ()"));

  iface->create_new_context   = _gdk_win32_gl_context_new;
  iface->make_context_current =  gdk_win32_gl_window_make_context_current;
  iface->is_double_buffered   =  gdk_win32_gl_window_is_double_buffered;
  iface->swap_buffers         =  gdk_win32_gl_window_swap_buffers;
  iface->wait_gl              =  gdk_win32_gl_window_wait_gl;
  iface->wait_gdk             =  gdk_win32_gl_window_wait_gdk;
  iface->gl_begin             =  gdk_win32_gl_window_gl_begin;
  iface->gl_end               =  gdk_win32_gl_window_gl_end;
  iface->get_gl_config        =  gdk_win32_gl_window_get_gl_config;
  iface->get_size             = _gdk_gl_window_get_size;
}

HDC
_gdk_win32_gl_window_hdc_get (GdkGLDrawable *gldrawable)
{
  GdkGLWindowImplWin32 *impl = GDK_GL_WINDOW_IMPL_WIN32 (gldrawable);

  g_assert (impl->hdc == NULL);

  /* Get DC. */
  impl->hdc = GetDC (impl->hwnd);
  if (impl->hdc == NULL)
    g_warning ("cannot get DC");

  return impl->hdc;
}

void
_gdk_win32_gl_window_hdc_release (GdkGLDrawable *gldrawable)
{
  GdkGLWindowImplWin32 *impl = GDK_GL_WINDOW_IMPL_WIN32 (gldrawable);

  g_assert (impl->hdc != NULL);

  /* Release DC. */
  if (!ReleaseDC (impl->hwnd, impl->hdc))
    g_warning ("cannot release DC");

  impl->hdc = NULL;
}

static gboolean
gdk_win32_gl_window_make_context_current (GdkGLDrawable *draw,
                                          GdkGLDrawable *read,
                                          GdkGLContext  *glcontext)
{
  GdkGLWindowImplWin32 *impl;
  HDC hdc;
  HGLRC hglrc;
  gboolean ret = TRUE;

  g_return_val_if_fail (GDK_IS_GL_WINDOW (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  /* Get DC. */
  hdc = GDK_GL_WINDOW_HDC_GET (draw);

  /* Get GLRC. */
  hglrc = GDK_GL_CONTEXT_HGLRC (glcontext);

  if (hdc == wglGetCurrentDC () &&
      hglrc == wglGetCurrentContext ())
    goto DONE;

  GDK_GL_NOTE (IMPL, g_message (" * wglMakeCurrent ()"));

  if (!wglMakeCurrent (hdc, hglrc))
    {
      _gdk_gl_context_set_gl_drawable (glcontext, NULL);
      _gdk_gl_context_set_gl_drawable_read (glcontext, NULL);
      ret = FALSE;
      goto DONE;
    }

  _gdk_gl_context_set_gl_drawable (glcontext, draw);
  _gdk_gl_context_set_gl_drawable_read (glcontext, read);

  impl = GDK_GL_WINDOW_IMPL_WIN32 (draw);
  if (GDK_GL_CONFIG_AS_SINGLE_MODE (impl->glconfig))
    {
      /* We do this because we are treating a double-buffered frame
         buffer as a single-buffered frame buffer because the system
         does not appear to export any suitable single-buffered
         visuals (in which the following are necessary). */
      glDrawBuffer (GL_FRONT);
      glReadBuffer (GL_FRONT);
    }

 DONE:

  /* Release DC. */
  GDK_GL_WINDOW_HDC_RELEASE (draw);

  return ret;
}

static gboolean
gdk_win32_gl_window_is_double_buffered (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (gldrawable), FALSE);

  return gdk_gl_config_is_double_buffered (GDK_GL_WINDOW_IMPL_WIN32 (gldrawable)->glconfig);
}

static void
gdk_win32_gl_window_swap_buffers (GdkGLDrawable *gldrawable)
{
  HDC hdc;

  g_return_if_fail (GDK_IS_GL_WINDOW (gldrawable));

  /* Get DC. */
  hdc = GDK_GL_WINDOW_HDC_GET (gldrawable);

  GDK_GL_NOTE (IMPL, g_message (" * SwapBuffers ()"));

  SwapBuffers (hdc);

  /* Release DC. */
  GDK_GL_WINDOW_HDC_RELEASE (gldrawable);
}

static void
gdk_win32_gl_window_wait_gl (GdkGLDrawable *gldrawable)
{
  glFinish ();
}

static void
gdk_win32_gl_window_wait_gdk (GdkGLDrawable *gldrawable)
{
  GdiFlush ();
}

static gboolean
gdk_win32_gl_window_gl_begin (GdkGLDrawable *draw,
                              GdkGLDrawable *read,
                              GdkGLContext  *glcontext)
{
  return gdk_win32_gl_window_make_context_current (draw, read, glcontext);
}

static void
gdk_win32_gl_window_gl_end (GdkGLDrawable *gldrawable)
{
  /* do nothing */
}

static GdkGLConfig *
gdk_win32_gl_window_get_gl_config (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (gldrawable), NULL);

  return GDK_GL_WINDOW_IMPL_WIN32 (gldrawable)->glconfig;
}

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 */
GdkGLWindow *
gdk_gl_window_new (GdkGLConfig *glconfig,
                   GdkWindow   *window,
                   const int   *attrib_list)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplWin32 *impl;

  HWND hwnd;
  HDC hdc = NULL;
  PIXELFORMATDESCRIPTOR pfd;
  int pixel_format;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_window_new ()"));

  hwnd = (HWND) gdk_win32_drawable_get_handle (GDK_DRAWABLE (window));

  /* Get DC. */
  hdc = GetDC (hwnd);
  if (hdc == NULL)
    {
      g_warning ("cannot get DC");
      goto FAIL;
    }

  /*
   * Choose pixel format.
   */

  pfd = *(GDK_GL_CONFIG_PFD (glconfig));
  /* Draw to window */
  pfd.dwFlags &= ~PFD_DRAW_TO_BITMAP;
  pfd.dwFlags |= PFD_DRAW_TO_WINDOW;

  /* Request pfd.cColorBits should exclude alpha bitplanes. */
  pfd.cColorBits = pfd.cRedBits + pfd.cGreenBits + pfd.cBlueBits;

  GDK_GL_NOTE (IMPL, g_message (" * ChoosePixelFormat ()"));

  pixel_format = ChoosePixelFormat (hdc, &pfd);
  /*
  pixel_format = _gdk_win32_gl_config_find_pixel_format (hdc, &pfd, &pfd);
  */

  if (pixel_format == 0)
    {
      g_warning ("cannot choose pixel format");
      goto FAIL;
    }

  GDK_GL_NOTE (MISC, g_message (" -- impl->pixel_format = 0x%x", pixel_format));
  GDK_GL_NOTE (MISC, _gdk_win32_gl_print_pfd (&pfd));

  /*
   * Set pixel format.
   */

  GDK_GL_NOTE (IMPL, g_message (" * SetPixelFormat ()"));

  if (!SetPixelFormat (hdc, pixel_format, &pfd))
    {
      g_warning ("cannot set pixel format");
      goto FAIL;
    }

  /* Release DC. */
  ReleaseDC (hwnd, hdc);

  /*
   * Instantiate the GdkGLWindowImplWin32 object.
   */

  glwindow = g_object_new (GDK_TYPE_GL_WINDOW_IMPL_WIN32, NULL);
  impl = GDK_GL_WINDOW_IMPL_WIN32 (glwindow);

  glwindow->drawable = GDK_DRAWABLE (window);

  impl->hwnd = hwnd;

  impl->pfd = pfd;
  impl->pixel_format = pixel_format;

  impl->glconfig = glconfig;
  g_object_ref (G_OBJECT (impl->glconfig));

  impl->hdc = NULL;

  return glwindow;

 FAIL:

  /* Release DC. */
  if (hdc != NULL)
    ReleaseDC (hwnd, hdc);

  return NULL;
}

PIXELFORMATDESCRIPTOR *
gdk_win32_gl_window_get_pfd (GdkGLWindow *glwindow)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (glwindow), NULL);

  return &(GDK_GL_WINDOW_IMPL_WIN32 (glwindow)->pfd);
}

int
gdk_win32_gl_window_get_pixel_format (GdkGLWindow *glwindow)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (glwindow), 0);

  return GDK_GL_WINDOW_IMPL_WIN32 (glwindow)->pixel_format;
}
