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

#include "gdkglwin32.h"
#include "gdkglprivate-win32.h"
#include "gdkglconfig-win32.h"
#include "gdkglcontext-win32.h"
#include "gdkglwindow-win32.h"

/* Forward declarations */
static gboolean gdk_win32_gl_window_make_context_current (GdkGLDrawable             *draw,
                                                          GdkGLDrawable             *read,
                                                          GdkGLContext              *glcontext);
static void     gdk_win32_gl_window_swap_buffers         (GdkGLDrawable             *gldrawable);
static void     gdk_win32_gl_window_wait_gl              (GdkGLDrawable             *gldrawable);
static void     gdk_win32_gl_window_wait_gdk             (GdkGLDrawable             *gldrawable);

static void     gdk_gl_window_impl_win32_init            (GdkGLWindowImplWin32      *impl);
static void     gdk_gl_window_impl_win32_class_init      (GdkGLWindowImplWin32Class *klass);

static GObject *gdk_gl_window_impl_win32_constructor     (GType                      type,
                                                          guint                      n_construct_properties,
                                                          GObjectConstructParam     *construct_properties);
static void     gdk_gl_window_impl_win32_finalize        (GObject                   *object);

static void     gdk_gl_window_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface);

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
        (GInstanceInitFunc) gdk_gl_window_impl_win32_init,
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
gdk_gl_window_impl_win32_init (GdkGLWindowImplWin32 *impl)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_window_impl_win32_class_init (GdkGLWindowImplWin32Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor = gdk_gl_window_impl_win32_constructor;
  object_class->finalize    = gdk_gl_window_impl_win32_finalize;
}

static GObject *
gdk_gl_window_impl_win32_constructor (GType                  type,
                                      guint                  n_construct_properties,
                                      GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLWindow *glwindow;
  GdkGLWindowImplWin32 *impl;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_constructor ()"));

  glwindow = GDK_GL_WINDOW (object);
  impl = GDK_GL_WINDOW_IMPL_WIN32 (glwindow);

  impl->hwnd = (HWND) gdk_win32_drawable_get_handle (glwindow->wrapper);

  /* Get DC. */
  impl->hdc = GetDC (impl->hwnd);
  if (impl->hdc == NULL)
    {
      g_warning ("cannot get DC");
      goto FAIL;
    }

  /*
   * Choose pixel format.
   */

  impl->pfd = *(GDK_GL_CONFIG_PFD (glwindow->glconfig));
  /* Draw to window */
  impl->pfd.dwFlags &= ~PFD_DRAW_TO_BITMAP;
  impl->pfd.dwFlags |= PFD_DRAW_TO_WINDOW;

  /* Request pfd.cColorBits should exclude alpha bitplanes. */
  /*
  impl->pfd.cColorBits = impl->pfd.cRedBits +
                         impl->pfd.cGreenBits +
                         impl->pfd.cBlueBits;
  */

  /*
  impl->pixel_format = ChoosePixelFormat (impl->hdc, &(impl->pfd));
  */

  impl->pixel_format = _gdk_win32_gl_config_find_pixel_format (impl->hdc,
							       &(impl->pfd),
							       &(impl->pfd));

  if (impl->pixel_format == 0)
    {
      g_warning ("cannot choose pixel format");
      goto FAIL;
    }

  /*
   * Set pixel format.
   */

  if (!SetPixelFormat (impl->hdc, impl->pixel_format, &(impl->pfd)))
    {
      g_warning ("cannot set pixel format");
      goto FAIL;
    }

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

 FAIL:

  /* Release DC. */
  if (impl->hdc != NULL)
    ReleaseDC (impl->hwnd, impl->hdc);

  impl->hdc = NULL;

  return object;
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

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_window_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_gl_drawable_interface_init ()"));

  iface->create_new_context   = _gdk_win32_gl_context_new;
  iface->make_context_current = gdk_win32_gl_window_make_context_current;
  iface->is_double_buffered   = _gdk_gl_window_is_double_buffered;
  iface->swap_buffers         = gdk_win32_gl_window_swap_buffers;
  iface->wait_gl              = gdk_win32_gl_window_wait_gl;
  iface->wait_gdk             = gdk_win32_gl_window_wait_gdk;
  iface->get_gl_config        = _gdk_gl_window_get_gl_config;
  iface->get_drawable         = _gdk_gl_window_get_drawable;
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
  GdkGLWindow *glwindow;
  HDC hdc;
  HGLRC hglrc;
  gboolean ret = TRUE;

  g_return_val_if_fail (GDK_IS_GL_WINDOW (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  glwindow = GDK_GL_WINDOW (draw);

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
      ret = FALSE;
      goto DONE;
    }

  _gdk_gl_context_set_gl_drawable (glcontext, draw);

  if (GDK_GL_CONFIG_AS_SINGLE_MODE(glwindow->glconfig))
    {
      /* We do this because we are treating a double-buffered frame
         buffer as a single-buffered frame buffer because the system
         does not appear to export any suitable single-buffered
         visuals (in which the following are necessary). */
      glDrawBuffer(GL_FRONT);
      glReadBuffer(GL_FRONT);
    }

 DONE:

  /* Release DC. */
  GDK_GL_WINDOW_HDC_RELEASE (draw);

  return ret;
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

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 */
GdkGLWindow *
gdk_gl_window_new (GdkGLConfig *glconfig,
                   GdkWindow   *window,
                   const gint  *attrib_list)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_window_new ()"));

  /*
   * Instanciate the GdkGLWindowImplWin32 object.
   */
  glwindow = g_object_new (GDK_TYPE_GL_WINDOW_IMPL_WIN32,
                           "glconfig", glconfig,
                           "wrapper",  GDK_DRAWABLE (window),
                           NULL);
  impl = GDK_GL_WINDOW_IMPL_WIN32 (glwindow);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glwindow));
      return NULL;
    }

  return glwindow;
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
