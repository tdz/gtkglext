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

#include "gdkglprivate-win32.h"
#include "gdkglcontext.h"
#include "gdkglwindow-win32.h"

/* Forward declarations */
static gboolean gdk_win32_gl_window_make_context_current (GdkGLDrawable *draw,
                                                          GdkGLDrawable *read,
                                                          GdkGLContext  *glcontext);
static void     gdk_win32_gl_window_swap_buffers         (GdkGLDrawable *gldrawable);

static void gdk_gl_window_impl_win32_init       (GdkGLWindowImplWin32      *impl);
static void gdk_gl_window_impl_win32_class_init (GdkGLWindowImplWin32Class *klass);

static GObject *gdk_gl_window_impl_win32_constructor (GType                  type,
                                                      guint                  n_construct_properties,
                                                      GObjectConstructParam *construct_properties);
static void     gdk_gl_window_impl_win32_finalize    (GObject               *object);

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
   * Get DC.
   */

  /*
   * XXX GdkGLWindow is not GdkWindow for the moment :-<
   *     use glwindow->wrapper.
   */
  impl->hdc = GetDC (gdk_win32_drawable_get_handle (glwindow->wrapper));
  if (impl->hdc == NULL)
    goto FAIL;

  impl->saved_dc = SaveDC (impl->hdc);
  if (impl->saved_dc == 0)
    goto FAIL;

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

 FAIL:

  if (impl->hdc != NULL)
    ReleaseDC (gdk_win32_drawable_get_handle (glwindow->wrapper),
               impl->hdc);

  impl->hdc = NULL;
  impl->saved_dc = 0;

  return object;
}

static void
gdk_gl_window_impl_win32_finalize (GObject *object)
{
  GdkGLWindow *glwindow = GDK_GL_WINDOW (object);
  GdkGLWindowImplWin32 *impl = GDK_GL_WINDOW_IMPL_WIN32 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_finalize ()"));

  if (impl->saved_dc != 0)
    {
      RestoreDC (impl->hdc, impl->saved_dc);
      impl->saved_dc = 0;
    }

  if (impl->hdc != NULL)
    {
      ReleaseDC (gdk_win32_drawable_get_handle (glwindow->wrapper),
                 impl->hdc);
      impl->hdc = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_window_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_win32_gl_drawable_interface_init ()"));

  iface->create_new_context = _gdk_win32_gl_context_new;
  iface->make_context_current = gdk_win32_gl_window_make_context_current;
  iface->swap_buffers = gdk_win32_gl_window_swap_buffers;

  /*< private >*/
  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  iface->real_drawable = _gdk_gl_window_real_drawable;
}

static gboolean
gdk_win32_gl_window_make_context_current (GdkGLDrawable *draw,
                                          GdkGLDrawable *read,
                                          GdkGLContext  *glcontext)
{
  GdkGLWindowImplWin32 *impl;
  HGLRC hglrc;

  g_return_val_if_fail (GDK_IS_GL_WINDOW (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  impl = GDK_GL_WINDOW_IMPL_WIN32 (draw);

  hglrc = gdk_win32_gl_context_get_hglrc (glcontext);

  if (impl->hdc == wglGetCurrentDC () &&
      hglrc == wglGetCurrentContext ())
    return TRUE;

  GDK_GL_NOTE (IMPL, g_message (" * wglMakeCurrent ()"));

  if (!wglMakeCurrent (impl->hdc, hglrc))
    {
      _gdk_gl_context_set_gl_drawable (glcontext, NULL);
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

  GDK_GL_NOTE (IMPL, g_message (" * glXSwapBuffers ()"));

  SwapBuffers (impl->hdc);
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

HDC
gdk_win32_gl_window_get_hdc (GdkGLWindow *glwindow)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (glwindow), NULL);

  return GDK_GL_WINDOW_IMPL_WIN32 (glwindow)->hdc;
}
