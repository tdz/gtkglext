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

#include "gdkglpixmap.h"
#include "gdkglwindow.h"
#include "gdkglprivate-win32.h"
#include "gdkgldrawable.h"

HDC
gdk_win32_gl_drawable_hdc_get (GdkGLDrawable *gldrawable)
{
  if (GDK_IS_GL_PIXMAP (gldrawable))
    return _gdk_win32_gl_pixmap_hdc_get (gldrawable);
  else if (GDK_IS_GL_WINDOW (gldrawable))
    return _gdk_win32_gl_window_hdc_get (gldrawable);
  else
    g_warning ("GLDrawable should be GLPixmap or GLWindow");

  return NULL;
}

void
gdk_win32_gl_drawable_hdc_release (GdkGLDrawable *gldrawable)
{
  if (GDK_IS_GL_PIXMAP (gldrawable))
    _gdk_win32_gl_pixmap_hdc_release (gldrawable);
  else if (GDK_IS_GL_WINDOW (gldrawable))
    _gdk_win32_gl_window_hdc_release (gldrawable);
  else
    g_warning ("GLDrawable should be GLPixmap or GLWindow");
}

void
gdk_gl_drawable_wait_gl (GdkGLDrawable *gldrawable)
{
  if (GDK_IS_GL_PIXMAP (gldrawable))
    _gdk_win32_gl_pixmap_wait_gl (gldrawable);
  else if (GDK_IS_GL_WINDOW (gldrawable))
    _gdk_win32_gl_window_wait_gl (gldrawable);
  else
    g_warning ("GLDrawable should be GLPixmap or GLWindow");
}

void
gdk_gl_drawable_wait_gdk (GdkGLDrawable *gldrawable)
{
  GdiFlush ();
}
