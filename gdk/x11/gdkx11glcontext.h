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

#ifndef __GDK_X11_GL_CONTEXT_H__
#define __GDK_X11_GL_CONTEXT_H__

#include <gdk/gdkx.h>

#include <gdk/gdkgl.h>

G_BEGIN_DECLS

GdkGLContext *gdk_x11_gl_context_foreign_new      (GdkGLConfig  *glconfig,
                                                   GdkGLContext *share_list,
                                                   GLXContext    glxcontext);

GLXContext    gdk_x11_gl_context_get_glxcontext   (GdkGLContext *glcontext);

#ifdef INSIDE_GDK_GL_X11

#define GDK_GL_CONTEXT_GLXCONTEXT(glcontext)   (GDK_GL_CONTEXT_IMPL_X11 (glcontext)->glxcontext)

#else

#define GDK_GL_CONTEXT_GLXCONTEXT(glcontext)   (gdk_x11_gl_context_get_glxcontext (glcontext))

#endif

G_END_DECLS

#endif /* __GDK_GL_GL_CONFIG_H__ */
