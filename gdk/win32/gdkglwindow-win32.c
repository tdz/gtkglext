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

#include "gdkglcontext.h"
#include "gdkglprivate-win32.h"
#include "gdkglwindow-win32.h"

/* Forward declarations */
static gboolean gdk_win32_gl_window_make_context_current (GdkGLDrawable             *draw,
                                                          GdkGLDrawable             *read,
                                                          GdkGLContext              *glcontext);
static void     gdk_win32_gl_window_swap_buffers         (GdkGLDrawable             *gldrawable);

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
  impl = GDK_GL_WINDOW_IMPL_WIN32 (object);

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

  return object;
}

static void
gdk_gl_window_impl_win32_finalize (GObject *object)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_finalize ()"));

  glwindow = GDK_GL_WINDOW (object);
  impl = GDK_GL_WINDOW_IMPL_WIN32 (object);

  if (impl->hdc != NULL)
    _gdk_win32_gl_window_hdc_release (GDK_GL_DRAWABLE (glwindow));

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_window_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_gl_drawable_interface_init ()"));

  iface->create_new_context   = _gdk_win32_gl_context_new;
  iface->make_context_current = gdk_win32_gl_window_make_context_current;
  iface->swap_buffers         = gdk_win32_gl_window_swap_buffers;

  /*< private >*/
  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  iface->real_drawable        = _gdk_gl_window_real_drawable;
}

HDC
_gdk_win32_gl_window_hdc_get (GdkGLDrawable *gldrawable)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplWin32 *impl;
  GdkDrawable *drawable;
  PIXELFORMATDESCRIPTOR *pfd;
  int pf;

  g_return_val_if_fail (GDK_IS_GL_DRAWABLE (gldrawable), NULL);

  glwindow = GDK_GL_WINDOW (gldrawable);
  impl = GDK_GL_WINDOW_IMPL_WIN32 (gldrawable);

  g_assert (impl->hdc == NULL);

  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  drawable = GDK_GL_DRAWABLE_GET_CLASS (gldrawable)->real_drawable (gldrawable);
  impl->hwnd = (HWND) gdk_win32_drawable_get_handle (drawable);

  /*
   * Get DC.
   */

  impl->hdc = GetDC (impl->hwnd);
  if (impl->hdc == NULL)
    {
      g_warning ("cannot get DC");
      goto FAIL;
    }

  /*
   * Save current DC.
   */
      
  impl->saved_dc = SaveDC (impl->hdc);
  if (impl->saved_dc == 0)
    {
      g_warning ("cannot save DC");
      goto FAIL;
    }

  /*
   * Set pixel format.
   */

  pfd = gdk_win32_gl_config_get_pfd (glwindow->glconfig);
  /* Draw to window */
  pfd->dwFlags &= ~PFD_DRAW_TO_BITMAP;
  pfd->dwFlags |= PFD_DRAW_TO_WINDOW;

  pf = ChoosePixelFormat (impl->hdc, pfd);
  if (pf == 0)
    {
      g_warning ("cannot choose pixel format");
      goto FAIL;
    }

  if (!SetPixelFormat (impl->hdc, pf, pfd))
    {
      g_warning ("cannot set pixel format");
      goto FAIL;
    }

  return impl->hdc;

 FAIL:

  if (impl->saved_dc != 0)
    RestoreDC (impl->hdc, impl->saved_dc);

  if (impl->hdc != NULL)
    ReleaseDC (impl->hwnd, impl->hdc);

  impl->hwnd = NULL;
  impl->hdc = NULL;
  impl->saved_dc = 0;

  return NULL;
}

void
_gdk_win32_gl_window_hdc_release (GdkGLDrawable *gldrawable)
{
  GdkGLWindowImplWin32 *impl;

  g_return_if_fail (GDK_IS_GL_DRAWABLE (gldrawable));

  impl = GDK_GL_WINDOW_IMPL_WIN32 (gldrawable);

  g_assert (impl->hdc != NULL);

  /*
   * Restore saved DC.
   */

  if (!RestoreDC (impl->hdc, impl->saved_dc))
    g_warning ("cannot restore DC");

  /*
   * Release DC.
   */

  if (!ReleaseDC (impl->hwnd, impl->hdc))
    g_warning ("cannot release DC");

  impl->hwnd = NULL;
  impl->hdc = NULL;
  impl->saved_dc = 0;
}

static gboolean
gdk_win32_gl_window_make_context_current (GdkGLDrawable *draw,
                                          GdkGLDrawable *read,
                                          GdkGLContext  *glcontext)
{
  HDC hdc;
  HGLRC hglrc;

  g_return_val_if_fail (GDK_IS_GL_WINDOW (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  /*
   * Get DC.
   */

  hdc = _gdk_win32_gl_window_hdc_get (draw);

  /*
   * Get GLRC.
   */

  hglrc = gdk_win32_gl_context_get_hglrc (glcontext);

  if (hdc == wglGetCurrentDC () &&
      hglrc == wglGetCurrentContext ())
    return TRUE;

  GDK_GL_NOTE (IMPL, g_message (" * wglMakeCurrent ()"));

  if (!wglMakeCurrent (hdc, hglrc))
    {
      _gdk_gl_context_set_gl_drawable (glcontext, NULL);
      _gdk_win32_gl_window_hdc_release (draw);
      return FALSE;
    }

  _gdk_gl_context_set_gl_drawable (glcontext, draw);

  return TRUE;
}

static void
gdk_win32_gl_window_swap_buffers (GdkGLDrawable *gldrawable)
{
  GdkGLWindowImplWin32 *impl;

  g_return_if_fail (GDK_IS_GL_DRAWABLE (gldrawable));

  impl = GDK_GL_WINDOW_IMPL_WIN32 (gldrawable);

  g_assert (impl->hdc != NULL);

  GDK_GL_NOTE (IMPL, g_message (" * SwapBuffers ()"));

  SwapBuffers (impl->hdc);
}

void
_gdk_win32_gl_window_wait_gl (GdkGLDrawable *gldrawable)
{
  glFinish ();

  /*
   * Release DC.
   */

  _gdk_win32_gl_window_hdc_release (gldrawable);
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
