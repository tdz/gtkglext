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

#if !defined (__GDKGLWIN32_H_INSIDE__) && !defined (GDK_GL_COMPILATION)
#error "Only <gdk/gdkglwin32.h> can be included directly."
#endif

#ifndef __GDK_WIN32_GL_CONTEXT_H__
#define __GDK_WIN32_GL_CONTEXT_H__

#include <gdk/gdkwin32.h>
#include <gdk/gdkgl.h>

G_BEGIN_DECLS

GdkGLContext  *gdk_win32_gl_context_foreign_new     (GdkGLConfig   *glconfig,
                                                     GdkGLContext  *share_list,
                                                     HGLRC          hglrc);

HGLRC          gdk_win32_gl_context_get_hglrc       (GdkGLContext  *glcontext);

G_END_DECLS

#ifdef INSIDE_GDK_GL_WIN32
#define GDK_GL_CONTEXT_HGLRC(glcontext)      (GDK_GL_CONTEXT_IMPL_WIN32 (glcontext)->hglrc)
#else
#define GDK_GL_CONTEXT_HGLRC(glcontext)      (gdk_win32_gl_context_get_hglrc (glcontext))
#endif

#endif /* __GDK_WIN32_GL_CONTEXT_H__ */
