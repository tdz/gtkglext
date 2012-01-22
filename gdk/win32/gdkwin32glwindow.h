/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002-2004  Naofumi Yasufuku
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

#ifndef __GDK_WIN32_GL_WINDOW_H__
#define __GDK_WIN32_GL_WINDOW_H__

#include <gdk/gdkwin32.h>
#include <gdk/gdkgl.h>

G_BEGIN_DECLS

PIXELFORMATDESCRIPTOR *gdk_win32_gl_window_get_pfd          (GdkGLWindow   *glwindow);
int                    gdk_win32_gl_window_get_pixel_format (GdkGLWindow   *glwindow);

#ifdef INSIDE_GDK_GL_WIN32

#define GDK_GL_WINDOW_PFD(glwindow)          (&(GDK_GL_WINDOW_IMPL_WIN32 (glwindow)->pfd))
#define GDK_GL_WINDOW_PIXEL_FORMAT(glwindow) (GDK_GL_WINDOW_IMPL_WIN32 (glwindow)->pixel_format)

#else

#define GDK_GL_WINDOW_PFD(glwindow)          (gdk_win32_gl_window_get_pfd (glwindow))
#define GDK_GL_WINDOW_PIXEL_FORMAT(glwindow) (gdk_win32_gl_window_get_pixel_format (glwindow))

#endif

G_END_DECLS

#endif /* __GDK_WIN32_GL_WINDOW_H__ */