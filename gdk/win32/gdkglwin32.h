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

#ifndef __GDK_GL_WIN32_H__
#define __GDK_GL_WIN32_H__

#include <gdk/gdkwin32.h>

#include <gdk/gdkglprivate.h>

#ifndef STRICT
#define STRICT                  /* We want strict type checks */
#endif
#include <windows.h>

#include <GL/gl.h>

G_BEGIN_DECLS

PIXELFORMATDESCRIPTOR *gdk_win32_gl_config_get_pfd (GdkGLConfig *glconfig);

HGLRC gdk_win32_gl_context_get_hglrc    (GdkGLContext  *glcontext);

HDC   gdk_win32_gl_drawable_hdc_get     (GdkGLDrawable *gldrawable);
void  gdk_win32_gl_drawable_hdc_release (GdkGLDrawable *gldrawable);

G_END_DECLS

#endif /* __GDK_GL_WIN32_H__ */
