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

/*
 * Additional OpenGL extensions.
 */

#ifndef __glext_extra_h_
#define __glext_extra_h_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__)
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

/*
 * Microsoft OpenGL extensions
 */

#ifndef GL_WIN_swap_hint
#define GL_WIN_swap_hint 1
#ifdef GL_GLEXT_PROTOTYPES
GLAPI void APIENTRY glAddSwapHintRectWIN (GLint, GLint, GLsizei, GLsizei);
#endif /* GL_GLEXT_PROTOTYPES */
typedef void (APIENTRY * PFNGLADDSWAPHINTRECTWINPROC) (GLint x, GLint y, GLsizei width, GLsizei height);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __glext_extra_h_ */
