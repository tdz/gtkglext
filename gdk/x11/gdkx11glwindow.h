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

#if !defined (__GDKGLX_H_INSIDE__) && !defined (GDK_GL_COMPILATION)
#error "Only <gdk/gdkglx.h> can be included directly."
#endif

#ifndef __GDK_X11_GL_WINDOW_H__
#define __GDK_X11_GL_WINDOW_H__

#include <gdk/gdkx.h>

#include <gdk/gdkgl.h>

G_BEGIN_DECLS

Window        gdk_x11_gl_window_get_glxwindow     (GdkGLWindow  *glwindow);

#ifdef INSIDE_GDK_GL_X11

#define GDK_GL_WINDOW_GLXWINDOW(glwindow)      (GDK_GL_WINDOW_IMPL_X11 (glwindow)->glxwindow)

#else

#define GDK_GL_WINDOW_GLXWINDOW(glwindow)      (gdk_x11_gl_window_get_glxwindow (glwindow))

#endif

G_END_DECLS

#endif /* __GDK_X11_GL_WINDOW_H__ */
