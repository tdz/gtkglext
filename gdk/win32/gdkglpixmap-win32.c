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

/* For direct access to GDK objects' internal data. */
#include "gdkinternal-win32.h"

#include "gdkglcontext.h"
#include "gdkglprivate-win32.h"
#include "gdkglpixmap-win32.h"

/* Forward declarations */
static gboolean gdk_win32_gl_pixmap_make_context_current (GdkGLDrawable             *draw,
                                                          GdkGLDrawable             *read,
                                                          GdkGLContext              *glcontext);
static void     gdk_win32_gl_pixmap_swap_buffers         (GdkGLDrawable             *gldrawable);
static void     gdk_win32_gl_pixmap_wait_gl              (GdkGLDrawable             *gldrawable);

static void     gdk_gl_pixmap_impl_win32_init            (GdkGLPixmapImplWin32      *impl);
static void     gdk_gl_pixmap_impl_win32_class_init      (GdkGLPixmapImplWin32Class *klass);

static GObject *gdk_gl_pixmap_impl_win32_constructor     (GType                      type,
                                                          guint                      n_construct_properties,
                                                          GObjectConstructParam     *construct_properties);
static void     gdk_gl_pixmap_impl_win32_finalize        (GObject                   *object);

static void     gdk_gl_pixmap_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface);

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
  gint width, height;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_constructor ()"));

  glpixmap = GDK_GL_PIXMAP (object);
  impl = GDK_GL_PIXMAP_IMPL_WIN32 (object);

  /*
   * Create offscreen rendering area.
   */

  /*
   * XXX GdkGLPixmap is not GdkPixmap for the moment :-<
   *     use glpixmap->wrapper.
   */
  gdk_drawable_get_size (glpixmap->wrapper, &width, &height);

  impl->pixmap = gdk_pixmap_new (NULL,
				 width, height,
				 gdk_drawable_get_depth (glpixmap->wrapper));
  if (impl->pixmap == NULL)
    goto FAIL;

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

 FAIL:

  return object;
}

static void
gdk_gl_pixmap_impl_win32_finalize (GObject *object)
{
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_finalize ()"));

  glpixmap = GDK_GL_PIXMAP (object);
  impl = GDK_GL_PIXMAP_IMPL_WIN32 (object);

  if (impl->pixmap != NULL)
    {
      g_object_unref (G_OBJECT (impl->pixmap));
      impl->pixmap = NULL;
    }

  if (impl->hdc != NULL)
    _gdk_win32_gl_pixmap_hdc_release (GDK_GL_DRAWABLE (glpixmap));

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_pixmap_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_gl_drawable_interface_init ()"));

  iface->create_new_context   = _gdk_win32_gl_context_new;
  iface->make_context_current = gdk_win32_gl_pixmap_make_context_current;
  iface->swap_buffers         = gdk_win32_gl_pixmap_swap_buffers;
  iface->wait_gl              = gdk_win32_gl_pixmap_wait_gl;
  iface->wait_gdk             = _gdk_win32_gl_drawable_wait_gdk;

  /*< private >*/
  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  iface->real_drawable        = _gdk_gl_pixmap_real_drawable;
}

HDC
_gdk_win32_gl_pixmap_hdc_get (GdkGLDrawable *gldrawable)
{
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplWin32 *impl;
  PIXELFORMATDESCRIPTOR *pfd;
  int pf;

  g_return_val_if_fail (GDK_IS_GL_DRAWABLE (gldrawable), NULL);

  glpixmap = GDK_GL_PIXMAP (gldrawable);
  impl = GDK_GL_PIXMAP_IMPL_WIN32 (gldrawable);

  g_assert (impl->hdc == NULL);

  /*
   * Create a memory DC.
   */

  impl->hdc = CreateCompatibleDC (NULL);
  if (impl->hdc == NULL)
    {
      g_warning ("cannot create a memory DC");
      goto FAIL;
    }

  /*
   * Select the bitmap.
   */

  impl->hbitmap = (HBITMAP) gdk_win32_drawable_get_handle (GDK_DRAWABLE (impl->pixmap));

  if (SelectObject (impl->hdc, impl->hbitmap) == NULL)
    {
      g_warning ("cannot select DIB");
      goto FAIL;
    }

  /*
   * Set pixel format.
   */

  pfd = gdk_win32_gl_config_get_pfd (glpixmap->glconfig);
  /* Draw to bitmap */
  pfd->dwFlags &= ~PFD_DRAW_TO_WINDOW;
  pfd->dwFlags |= PFD_DRAW_TO_BITMAP;

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

  if (impl->hdc != NULL)
    DeleteDC (impl->hdc);

  impl->hdc = NULL;
  impl->hbitmap = NULL;

  return NULL;
}

void
_gdk_win32_gl_pixmap_hdc_release (GdkGLDrawable *gldrawable)
{
  GdkGLPixmapImplWin32 *impl;
  GdkImage *src_image;
  GdkDrawable *dest_drawable;
  BITMAPINFO bmi;
  UINT usage;
  HBITMAP dest_hbitmap;

  g_return_if_fail (GDK_IS_GL_DRAWABLE (gldrawable));

  impl = GDK_GL_PIXMAP_IMPL_WIN32 (gldrawable);

  g_assert (impl->hdc != NULL);

  /*
   * Get source (OpenGL) DIB info.
   */

  /* Access directly to GdkPixmap's internal image data
     for performance reason. */
  src_image = ((GdkPixmapImplWin32 *) (GDK_PIXMAP_OBJECT (impl->pixmap)->impl))->image;

  /* See gdkpixmap-win32.c. */
  usage = DIB_RGB_COLORS;
  if (src_image->depth <= 8)
    usage = DIB_PAL_COLORS;

  memset (&bmi, 0, sizeof (bmi));
  bmi.bmiHeader.biSize = sizeof (BITMAPINFOHEADER);

  GetDIBits (impl->hdc, impl->hbitmap, 0, 1, NULL,
	     (BITMAPINFO *) &bmi, usage);

  /*
   * Set source (OpenGL) DIB bits to destination DIB.
   */

  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  dest_drawable = GDK_GL_DRAWABLE_GET_CLASS (gldrawable)->real_drawable (gldrawable);
  dest_hbitmap = (HBITMAP) gdk_win32_drawable_get_handle (dest_drawable);

  if (SetDIBits (impl->hdc, dest_hbitmap,
		 0, src_image->height,
		 src_image->mem,
		 (BITMAPINFO *) &bmi, usage) == 0)
    g_warning ("cannot set DIB bits");

  if (SelectObject (impl->hdc, dest_hbitmap) == NULL)
    g_warning ("cannot select DIB");

  /*
   * Delete the memory DC.
   */

  if (!DeleteDC (impl->hdc))
    g_warning ("cannot delete the memory DC");

  impl->hdc = NULL;
  impl->hbitmap = NULL;
}

static gboolean
gdk_win32_gl_pixmap_make_context_current (GdkGLDrawable *draw,
                                          GdkGLDrawable *read,
                                          GdkGLContext  *glcontext)
{
  HDC hdc;
  HGLRC hglrc;

  g_return_val_if_fail (GDK_IS_GL_PIXMAP (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  /*
   * Get DC.
   */

  hdc = _gdk_win32_gl_pixmap_hdc_get (draw);

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
      _gdk_win32_gl_pixmap_hdc_release (draw);
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

  g_assert (impl->hdc != NULL);

  GDK_GL_NOTE (IMPL, g_message (" * SwapBuffers ()"));

  SwapBuffers (impl->hdc);
}

static void
gdk_win32_gl_pixmap_wait_gl (GdkGLDrawable *gldrawable)
{
  glFinish ();

  /*
   * Release DC.
   */

  _gdk_win32_gl_pixmap_hdc_release (gldrawable);
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

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_new ()"));

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
