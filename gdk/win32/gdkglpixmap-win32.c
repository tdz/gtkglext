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
#include "gdkglpixmap-win32.h"

/* Forward declarations */
static gboolean gdk_win32_gl_pixmap_make_context_current (GdkGLDrawable *draw,
                                                          GdkGLDrawable *read,
                                                          GdkGLContext  *glcontext);
static void     gdk_win32_gl_pixmap_swap_buffers         (GdkGLDrawable *gldrawable);

static void gdk_gl_pixmap_impl_win32_init       (GdkGLPixmapImplWin32      *impl);
static void gdk_gl_pixmap_impl_win32_class_init (GdkGLPixmapImplWin32Class *klass);

static GObject *gdk_gl_pixmap_impl_win32_constructor (GType                  type,
                                                      guint                  n_construct_properties,
                                                      GObjectConstructParam *construct_properties);
static void     gdk_gl_pixmap_impl_win32_finalize    (GObject               *object);

static void gdk_gl_pixmap_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface);

static gpointer parent_class = NULL;

GType
gdk_gl_pixmap_impl_win32_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLPixmapImplWin32Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_pixmap_impl_win32_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLPixmapImplWin32),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_pixmap_impl_win32_init,
      };
      static const GInterfaceInfo gl_drawable_interface_info = {
        (GInterfaceInitFunc) gdk_gl_pixmap_impl_win32_gl_drawable_interface_init,
        (GInterfaceFinalizeFunc) NULL,
        NULL                    /* interface_data */
      };

      type = g_type_register_static (GDK_TYPE_GL_PIXMAP,
                                     "GdkGLPixmapImplWin32",
                                     &type_info, 0);
      g_type_add_interface_static (type,
                                   GDK_TYPE_GL_DRAWABLE,
                                   &gl_drawable_interface_info);
    }

  return type;
}

static void
gdk_gl_pixmap_impl_win32_init (GdkGLPixmapImplWin32 *impl)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_pixmap_impl_win32_class_init (GdkGLPixmapImplWin32Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor = gdk_gl_pixmap_impl_win32_constructor;
  object_class->finalize    = gdk_gl_pixmap_impl_win32_finalize;
}

static GObject *
gdk_gl_pixmap_impl_win32_constructor (GType                  type,
                                      guint                  n_construct_properties,
                                      GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplWin32 *impl;

  HANDLE old_handle;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_constructor ()"));

  glpixmap = GDK_GL_PIXMAP (object);
  impl = GDK_GL_PIXMAP_IMPL_WIN32 (object);

  /*
   * Create a memory DC.
   */

  impl->hdc = CreateCompatibleDC (NULL);
  if (impl->hdc == NULL)
    goto FAIL;

  /*
   * XXX GdkGLPixmap is not GdkPixmap for the moment :-<
   *     use glpixmap->wrapper.
   */  
  old_handle = SelectObject (impl->hdc,
                             gdk_win32_drawable_get_handle (glpixmap->wrapper));
  if (old_handle == NULL)
    goto FAIL;

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

 FAIL:

  if (impl->hdc != NULL)
    DeleteDC (impl->hdc);

  impl->hdc = NULL;

  return object;
}

static void
gdk_gl_pixmap_impl_win32_finalize (GObject *object)
{
  GdkGLPixmapImplWin32 *impl = GDK_GL_PIXMAP_IMPL_WIN32 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_finalize ()"));

  if (impl->hdc != NULL)
    {
      DeleteDC (impl->hdc);
      impl->hdc = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_pixmap_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_gl_drawable_interface_init ()"));

  iface->create_new_context = _gdk_win32_gl_context_new;
  iface->make_context_current = gdk_win32_gl_pixmap_make_context_current;
  iface->swap_buffers = gdk_win32_gl_pixmap_swap_buffers;

  /*< private >*/
  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  iface->real_drawable = _gdk_gl_pixmap_real_drawable;
}

static gboolean
gdk_win32_gl_pixmap_make_context_current (GdkGLDrawable *draw,
                                          GdkGLDrawable *read,
                                          GdkGLContext  *glcontext)
{
  GdkGLPixmapImplWin32 *impl;
  HGLRC hglrc;

  g_return_val_if_fail (GDK_IS_GL_PIXMAP (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  impl = GDK_GL_PIXMAP_IMPL_WIN32 (draw);

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
gdk_win32_gl_pixmap_swap_buffers (GdkGLDrawable *gldrawable)
{
  GdkGLPixmapImplWin32 *impl;

  g_return_if_fail (GDK_IS_GL_DRAWABLE (gldrawable));

  impl = GDK_GL_PIXMAP_IMPL_WIN32 (gldrawable);

  GDK_GL_NOTE (IMPL, g_message (" * glXSwapBuffers ()"));

  SwapBuffers (impl->hdc);
}

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 */
GdkGLPixmap *
gdk_gl_pixmap_new (GdkGLConfig *glconfig,
                   GdkPixmap   *pixmap,
                   const gint  *attrib_list)
{
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_new ()\n"));

  /*
   * Instanciate the GdkGLPixmapImplWin32 object.
   */
  glpixmap = g_object_new (GDK_TYPE_GL_PIXMAP_IMPL_WIN32,
                           "glconfig", glconfig,
                           "wrapper",  GDK_DRAWABLE (pixmap),
                           NULL);
  impl = GDK_GL_PIXMAP_IMPL_WIN32 (glpixmap);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glpixmap));
      return NULL;
    }

  return glpixmap;
}

HDC
gdk_win32_gl_pixmap_get_hdc (GdkGLPixmap *glpixmap)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (glpixmap), NULL);

  return GDK_GL_PIXMAP_IMPL_WIN32 (glpixmap)->hdc;
}
