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

#include "gdkgldrawable.h"
#include "gdkglconfig.h"
#include "gdkglprivate-win32.h"
#include "gdkglcontext-win32.h"

static void gdk_gl_context_impl_win32_init       (GdkGLContextImplWin32      *impl);
static void gdk_gl_context_impl_win32_class_init (GdkGLContextImplWin32Class *klass);

static GObject *gdk_gl_context_impl_win32_constructor  (GType                  type,
                                                        guint                  n_construct_properties,
                                                        GObjectConstructParam *construct_properties);
static void     gdk_gl_context_impl_win32_finalize     (GObject               *object);

static gpointer parent_class = NULL;

GType
gdk_gl_context_impl_win32_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLContextImplWin32Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_context_impl_win32_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLContextImplWin32),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_context_impl_win32_init,
      };

      type = g_type_register_static (GDK_TYPE_GL_CONTEXT,
                                     "GdkGLContextImplWin32",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_context_impl_win32_init (GdkGLContextImplWin32 *impl)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_context_impl_win32_class_init (GdkGLContextImplWin32Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor  = gdk_gl_context_impl_win32_constructor;
  object_class->finalize     = gdk_gl_context_impl_win32_finalize;
}

static GObject *
gdk_gl_context_impl_win32_constructor (GType                  type,
                                       guint                  n_construct_properties,
                                       GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLContext *glcontext;
  GdkGLContextImplWin32 *impl;

  GdkGLContextImplWin32 *share_impl = NULL;

  GdkDrawable *drawable;
  HWND hwnd;
  PIXELFORMATDESCRIPTOR *pfd;
  int pf;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_constructor ()"));

  glcontext = GDK_GL_CONTEXT (object);
  impl = GDK_GL_CONTEXT_IMPL_WIN32 (object);

  /*
   * Create an OpenGL rendering context.
   */

  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  drawable = GDK_GL_DRAWABLE_GET_CLASS (glcontext->gldrawable)->real_drawable (glcontext->gldrawable);

  hwnd = (HWND) gdk_win32_drawable_get_handle (drawable);

  /* Get DC. */
  impl->hdc = GetDC (hwnd);
  pfd = gdk_win32_gl_config_get_pfd (glcontext->glconfig);

  pf = ChoosePixelFormat(impl->hdc, pfd);
  if (pf == 0)
    goto FAIL;

  SetPixelFormat (impl->hdc, pf, pfd);
  impl->hglrc = wglCreateContext (impl->hdc);
  if (impl->hglrc == NULL)
    goto FAIL;

  if (glcontext->share_list != NULL)
    {
      share_impl = GDK_GL_CONTEXT_IMPL_WIN32 (glcontext->share_list);
      if (!wglShareLists (share_impl->hglrc, impl->hglrc))
        goto FAIL;
    }

  /* Release DC. */
  ReleaseDC (hwnd, impl->hdc);
  impl->hdc = NULL;

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

  return object;

 FAIL:

  if (impl->hdc != NULL)
    {
      ReleaseDC (hwnd, impl->hdc);
      impl->hdc = NULL;
    }

  if (impl->hglrc != NULL)
    {
      wglDeleteContext (impl->hglrc);
      impl->hglrc = NULL;
    }

  /* Release DC */
  ReleaseDC (hwnd, impl->hdc);
  impl->hdc = NULL;

  return object;
}

static void
gdk_gl_context_impl_win32_finalize (GObject *object)
{
  GdkGLContextImplWin32 *impl = GDK_GL_CONTEXT_IMPL_WIN32 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_finalize ()"));

  if (impl->hglrc != NULL)
    {
      if (impl->hglrc == wglGetCurrentContext ())
        wglMakeCurrent (NULL, NULL);

      wglDeleteContext (impl->hglrc);
      impl->hglrc = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

GdkGLContext *
_gdk_win32_gl_context_new (GdkGLDrawable *gldrawable,
                           GdkGLConfig   *glconfig,
                           gint           render_type,
                           GdkGLContext  *share_list,
                           gboolean       direct)
{
  GdkGLContext *glcontext;
  GdkGLContextImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_new ()"));

  /*
   * Instanciate the GdkGLContextImplWin32 object.
   */

  glcontext = g_object_new (GDK_TYPE_GL_CONTEXT_IMPL_WIN32,
                            "gldrawable",  gldrawable,
                            "glconfig",    glconfig,
                            "render_type", render_type,
                            "share_list",  share_list,
                            "is_direct",   direct,
                            NULL);
  impl = GDK_GL_CONTEXT_IMPL_WIN32 (glcontext);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glcontext));
      return NULL;
    }

  return glcontext;
}

HDC
gdk_win32_gl_context_get_hdc (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), NULL);

  return GDK_GL_CONTEXT_IMPL_WIN32 (glcontext)->hdc;
}

HGLRC
gdk_win32_gl_context_get_hglrc (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), NULL);

  return GDK_GL_CONTEXT_IMPL_WIN32 (glcontext)->hglrc;
}
