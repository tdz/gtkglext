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
 * Additional WGL extensions.
 */

#ifndef __wglext_extra_h_
#define __wglext_extra_h_

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
 * 3DFX
 */

/*
 * ARB
 */

/*
 * ATI
 */

#ifndef WGL_ATI_pixel_format_float
#define WGL_TYPE_RGBA_FLOAT_ATI            0x21A0
#define GL_TYPE_RGBA_FLOAT_ATI             0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI 0x8835
#endif

#ifndef WGL_ATI_pixel_format_float
#define WGL_ATI_pixel_format_float  1
#endif

/*
 * 3DFX
 */

/*
 * ARB
 */

/*
 * EXT
 */

/*
 * I3D
 */

/*
 * NV
 */

#ifndef WGL_NV_allocate_memory
#define WGL_NV_allocate_memory 1
#ifdef WGL_WGLEXT_PROTOTYPES
extern void * wglAllocateMemoryNV (int, float, float, float);
extern void wglFreeMemoryNV (void *); 
#endif
typedef void * (APIENTRY * PFNWGLALLOCATEMEMORYNVPROC) (int size, float readfreq, float writefreq, float priority);
typedef void (APIENTRY * PFNWGLFREEMEMORYNVPROC) (void *pointer);
#endif

/*
 * OML
 */

#ifdef __cplusplus
}
#endif

#endif /* __wglext_extra_h_ */
