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
#include "gdkglpixmap-win32.h"

/* For direct access to GDK objects' internal data. */
#include "gdkinternal-win32.h"

/* Forward declarations */

static void gdk_gl_pixmap_sync_gl  (GdkGLPixmap *glpixmap);
static void gdk_gl_pixmap_sync_gdk (GdkGLPixmap *glpixmap);

static gboolean     gdk_win32_gl_pixmap_make_context_current (GdkGLDrawable *draw,
                                                              GdkGLDrawable *read,
                                                              GdkGLContext  *glcontext);
static gboolean     gdk_win32_gl_pixmap_is_double_buffered   (GdkGLDrawable *gldrawable);
static void         gdk_win32_gl_pixmap_swap_buffers         (GdkGLDrawable *gldrawable);
static void         gdk_win32_gl_pixmap_wait_gl              (GdkGLDrawable *gldrawable);
static void         gdk_win32_gl_pixmap_wait_gdk             (GdkGLDrawable *gldrawable);
static gboolean     gdk_win32_gl_pixmap_gl_begin             (GdkGLDrawable *draw,
                                                              GdkGLDrawable *read,
                                                              GdkGLContext  *glcontext);
static void         gdk_win32_gl_pixmap_gl_end               (GdkGLDrawable *gldrawable);
static GdkGLConfig *gdk_win32_gl_pixmap_get_gl_config        (GdkGLDrawable *gldrawable);

static void gdk_gl_pixmap_impl_win32_class_init (GdkGLPixmapImplWin32Class *klass);
static void gdk_gl_pixmap_impl_win32_finalize   (GObject                   *object);
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
        (GInstanceInitFunc) NULL
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
gdk_gl_pixmap_impl_win32_class_init (GdkGLPixmapImplWin32Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->finalize = gdk_gl_pixmap_impl_win32_finalize;
}

static void
gdk_gl_pixmap_impl_win32_finalize (GObject *object)
{
  GdkGLPixmapImplWin32 *impl = GDK_GL_PIXMAP_IMPL_WIN32 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_finalize ()"));

  /* Delete the memory DC. */
  DeleteDC (impl->hdc);

  g_object_unref (G_OBJECT (impl->aux_pixmap));

  g_object_unref (G_OBJECT (impl->glconfig));

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_pixmap_impl_win32_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_win32_gl_drawable_interface_init ()"));

  iface->create_new_context   = _gdk_win32_gl_context_new;
  iface->make_context_current =  gdk_win32_gl_pixmap_make_context_current;
  iface->is_double_buffered   =  gdk_win32_gl_pixmap_is_double_buffered;
  iface->swap_buffers         =  gdk_win32_gl_pixmap_swap_buffers;
  iface->wait_gl              =  gdk_win32_gl_pixmap_wait_gl;
  iface->wait_gdk             =  gdk_win32_gl_pixmap_wait_gdk;
  iface->gl_begin             =  gdk_win32_gl_pixmap_gl_begin;
  iface->gl_end               =  gdk_win32_gl_pixmap_gl_end;
  iface->get_gl_config        =  gdk_win32_gl_pixmap_get_gl_config;
  iface->get_size             = _gdk_gl_pixmap_get_size;
}

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 */
GdkGLPixmap *
gdk_gl_pixmap_new (GdkGLConfig *glconfig,
                   GdkPixmap   *pixmap,
                   const int   *attrib_list)
{
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplWin32 *impl;

  gint width, height;
  gint depth;
  GdkPixmap *aux_pixmap = NULL;

  HBITMAP gl_hbitmap;
  HBITMAP gdk_hbitmap;
  HDC hdc = NULL;
  PIXELFORMATDESCRIPTOR pfd;
  int pixel_format;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_new ()"));

  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);
  g_return_val_if_fail (GDK_IS_PIXMAP (pixmap), NULL);

  /*
   * Create offscreen rendering area.
   */

  gdk_drawable_get_size (GDK_DRAWABLE (pixmap), &width, &height);
  depth = gdk_drawable_get_depth (GDK_DRAWABLE (pixmap));

  aux_pixmap = gdk_pixmap_new (NULL, width, height, depth);
  if (aux_pixmap == NULL)
    goto FAIL;

  /* Source (OpenGL) DIB */
  gl_hbitmap = (HBITMAP) gdk_win32_drawable_get_handle (GDK_DRAWABLE (aux_pixmap));

  /* Destination (GDK) DIB */
  gdk_hbitmap = (HBITMAP) gdk_win32_drawable_get_handle (GDK_DRAWABLE (pixmap));

  /*
   * Create a memory DC.
   */

  hdc = CreateCompatibleDC (NULL);
  if (hdc == NULL)
    {
      g_warning ("cannot create a memory DC");
      goto FAIL;
    }

  /*
   * Select the bitmap.
   */

  if (SelectObject (hdc, gl_hbitmap) == NULL)
    {
      g_warning ("cannot select DIB");
      goto FAIL;
    }

  /*
   * Choose pixel format.
   */

  pfd = *(GDK_GL_CONFIG_PFD (glconfig));
  /* Draw to bitmap */
  pfd.dwFlags &= ~PFD_DRAW_TO_WINDOW;
  pfd.dwFlags |= PFD_DRAW_TO_BITMAP;

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

  /*
   * Instantiate the GdkGLPixmapImplWin32 object.
   */

  glpixmap = g_object_new (GDK_TYPE_GL_PIXMAP_IMPL_WIN32, NULL);
  impl = GDK_GL_PIXMAP_IMPL_WIN32 (glpixmap);

  glpixmap->drawable = GDK_DRAWABLE (pixmap);

  impl->aux_pixmap = aux_pixmap;

  impl->gl_hbitmap = gl_hbitmap;
  impl->gdk_hbitmap = gdk_hbitmap;

  impl->pfd = pfd;
  impl->pixel_format = pixel_format;

  impl->glconfig = glconfig;
  g_object_ref (G_OBJECT (impl->glconfig));

  impl->hdc = hdc;

  return glpixmap;

 FAIL:

  if (hdc != NULL)
    DeleteDC (hdc);

  if (aux_pixmap != NULL)
    g_object_unref (G_OBJECT (aux_pixmap));

  return NULL;  
}

HDC
_gdk_win32_gl_pixmap_hdc_get (GdkGLDrawable *gldrawable)
{
  GdkGLPixmapImplWin32 *impl = GDK_GL_PIXMAP_IMPL_WIN32 (gldrawable);

  g_assert (impl->hdc != NULL);

  /*
   * Select the OpenGL bitmap.
   */

  if (SelectObject (impl->hdc, impl->gl_hbitmap) == NULL)
    g_warning ("cannot select DIB");

  return impl->hdc;
}

void
_gdk_win32_gl_pixmap_hdc_release (GdkGLDrawable *gldrawable)
{
  /* Do nothing. */
}

static void
gdk_gl_pixmap_sync_gl (GdkGLPixmap *glpixmap)
{
  GdkGLPixmapImplWin32 *impl;
  GdkImage *gl_image;
  BITMAPINFO bmi;
  UINT usage;
  HBITMAP old_hbitmap;

  g_return_if_fail (GDK_IS_GL_PIXMAP (glpixmap));

  GDK_GL_NOTE (IMPL, g_message (" -- gdk_gl_pixmap_sync_gl ()"));

  impl = GDK_GL_PIXMAP_IMPL_WIN32 (glpixmap);

  /*
   * Get OpenGL DIB info.
   */

  /* Access directly to GdkPixmap's internal image data
     for performance reason. */
  gl_image = ((GdkPixmapImplWin32 *) (GDK_PIXMAP_OBJECT (impl->aux_pixmap)->impl))->image;

  /* See gdkpixmap-win32.c. */
  usage = DIB_RGB_COLORS;
  if (gl_image->depth <= 8)
    usage = DIB_PAL_COLORS;

  memset (&bmi, 0, sizeof (bmi));
  bmi.bmiHeader.biSize = sizeof (BITMAPINFOHEADER);

  GetDIBits (impl->hdc, impl->gl_hbitmap, 0, 1, NULL,
	     (BITMAPINFO *) &bmi, usage);

  /*
   * Set OpenGL DIB bits to GDK DIB.
   */

  if (SetDIBits (impl->hdc, impl->gdk_hbitmap,
		 0, gl_image->height,
		 gl_image->mem,
		 (BITMAPINFO *) &bmi, usage) == 0)
    g_warning ("cannot set DIB bits");

  old_hbitmap = SelectObject (impl->hdc, impl->gdk_hbitmap);
  if (old_hbitmap == NULL)
    g_warning ("cannot select DIB");

  /*
   * Reset selected object.
   */

  if (SelectObject (impl->hdc, old_hbitmap) == NULL)
    g_warning ("cannot select old DIB");
}

static void
gdk_gl_pixmap_sync_gdk (GdkGLPixmap *glpixmap)
{
  GdkGLPixmapImplWin32 *impl;
  GdkImage *gdk_image;
  BITMAPINFO bmi;
  UINT usage;
  HBITMAP old_hbitmap;

  g_return_if_fail (GDK_IS_GL_PIXMAP (glpixmap));

  GDK_GL_NOTE (IMPL, g_message (" -- gdk_gl_pixmap_sync_gdk ()"));

  impl = GDK_GL_PIXMAP_IMPL_WIN32 (glpixmap);

  /*
   * Get GDK DIB info.
   */

  /* Access directly to GdkPixmap's internal image data
     for performance reason. */
  gdk_image = ((GdkPixmapImplWin32 *) (GDK_PIXMAP_OBJECT (glpixmap->drawable)->impl))->image;

  /* See gdkpixmap-win32.c. */
  usage = DIB_RGB_COLORS;
  if (gdk_image->depth <= 8)
    usage = DIB_PAL_COLORS;

  memset (&bmi, 0, sizeof (bmi));
  bmi.bmiHeader.biSize = sizeof (BITMAPINFOHEADER);

  GetDIBits (impl->hdc, impl->gdk_hbitmap, 0, 1, NULL,
	     (BITMAPINFO *) &bmi, usage);

  /*
   * Set GDK DIB bits to OpenGL DIB.
   */

  if (SetDIBits (impl->hdc, impl->gl_hbitmap,
		 0, gdk_image->height,
		 gdk_image->mem,
		 (BITMAPINFO *) &bmi, usage) == 0)
    g_warning ("cannot set DIB bits");

  old_hbitmap = SelectObject (impl->hdc, impl->gl_hbitmap);
  if (old_hbitmap == NULL)
    g_warning ("cannot select DIB");

  /*
   * Reset selected object.
   */

  if (SelectObject (impl->hdc, old_hbitmap) == NULL)
    g_warning ("cannot select old DIB");
}

static gboolean
gdk_win32_gl_pixmap_make_context_current (GdkGLDrawable *draw,
                                          GdkGLDrawable *read,
                                          GdkGLContext  *glcontext)
{
  GdkGLPixmapImplWin32 *impl;
  HDC hdc;
  HGLRC hglrc;
  gboolean ret = TRUE;

  g_return_val_if_fail (GDK_IS_GL_PIXMAP (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  /* Sync. */
  gdk_gl_pixmap_sync_gdk (GDK_GL_PIXMAP (draw));

  /* Get DC. */
  hdc = GDK_GL_PIXMAP_HDC_GET (draw);

  /* Get GLRC. */
  hglrc = GDK_GL_CONTEXT_HGLRC (glcontext);

  if (hdc == wglGetCurrentDC () &&
      hglrc == wglGetCurrentContext ())
    goto DONE;

  GDK_GL_NOTE (IMPL, g_message (" * wglMakeCurrent ()"));

  if (!wglMakeCurrent (hdc, hglrc))
    {
      _gdk_gl_context_set_gl_drawable (glcontext, NULL);
      /* currently unused. */
      /* _gdk_gl_context_set_gl_drawable_read (glcontext, NULL); */
      ret = FALSE;
      goto DONE;
    }

  _gdk_gl_context_set_gl_drawable (glcontext, draw);
  /* currently unused. */
  /* _gdk_gl_context_set_gl_drawable_read (glcontext, read); */

  impl = GDK_GL_PIXMAP_IMPL_WIN32 (draw);
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
  GDK_GL_PIXMAP_HDC_RELEASE (draw);

  return ret;
}

static gboolean
gdk_win32_gl_pixmap_is_double_buffered (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (gldrawable), FALSE);

  return gdk_gl_config_is_double_buffered (GDK_GL_PIXMAP_IMPL_WIN32 (gldrawable)->glconfig);
}

static void
gdk_win32_gl_pixmap_swap_buffers (GdkGLDrawable *gldrawable)
{
  HDC hdc;

  g_return_if_fail (GDK_IS_GL_PIXMAP (gldrawable));

  /* Get DC. */
  hdc = GDK_GL_PIXMAP_HDC_GET (gldrawable);

  GDK_GL_NOTE (IMPL, g_message (" * SwapBuffers ()"));

  SwapBuffers (hdc);

  /* Release DC. */
  GDK_GL_PIXMAP_HDC_RELEASE (gldrawable);
}

static void
gdk_win32_gl_pixmap_wait_gl (GdkGLDrawable *gldrawable)
{
  glFinish ();

  /* Sync. */
  gdk_gl_pixmap_sync_gl (GDK_GL_PIXMAP (gldrawable));
}

static void
gdk_win32_gl_pixmap_wait_gdk (GdkGLDrawable *gldrawable)
{
  GdiFlush ();

  /* Sync. */
  gdk_gl_pixmap_sync_gdk (GDK_GL_PIXMAP (gldrawable));
}

static gboolean
gdk_win32_gl_pixmap_gl_begin (GdkGLDrawable *draw,
                              GdkGLDrawable *read,
                              GdkGLContext  *glcontext)
{
  gboolean ret;

  ret = gdk_win32_gl_pixmap_make_context_current (draw, read, glcontext);
  if (!ret)
    return FALSE;

  gdk_win32_gl_pixmap_wait_gdk (draw);

  return TRUE;
}

static void
gdk_win32_gl_pixmap_gl_end (GdkGLDrawable *gldrawable)
{
  gdk_win32_gl_pixmap_wait_gl (gldrawable);
}

static GdkGLConfig *
gdk_win32_gl_pixmap_get_gl_config (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (gldrawable), NULL);

  return GDK_GL_PIXMAP_IMPL_WIN32 (gldrawable)->glconfig;
}

PIXELFORMATDESCRIPTOR *
gdk_win32_gl_pixmap_get_pfd (GdkGLPixmap *glpixmap)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (glpixmap), NULL);

  return &(GDK_GL_PIXMAP_IMPL_WIN32 (glpixmap)->pfd);
}

int
gdk_win32_gl_pixmap_get_pixel_format (GdkGLPixmap *glpixmap)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (glpixmap), 0);

  return GDK_GL_PIXMAP_IMPL_WIN32 (glpixmap)->pixel_format;
}
