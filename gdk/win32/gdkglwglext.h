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

#ifndef __GDK_GL_WGL_EXT_H__
#define __GDK_GL_WGL_EXT_H__

#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>

#include <GL/gl.h>

#include <gdk/gdkglquery.h>

G_BEGIN_DECLS

#ifndef __wglext_h_

#ifndef WGL_ARB_pbuffer
DECLARE_HANDLE(HPBUFFERARB);
#endif
#ifndef WGL_EXT_pbuffer
DECLARE_HANDLE(HPBUFFEREXT);
#endif

#endif /* __wglext_h_ */

/* 
 * WGL_ARB_buffer_region
 */

/* wglCreateBufferRegionARB */
typedef HANDLE (WINAPI * GDK_GL_WGLCREATEBUFFERREGIONARBPROC) (HDC hDC, int iLayerPlane, UINT uType);
GdkGLProc gdk_gl_get_wglCreateBufferRegionARB (void);
#define gdk_gl_wglCreateBufferRegionARB(proc, hDC, iLayerPlane, uType) \
  (((GDK_GL_WGLCREATEBUFFERREGIONARBPROC) (proc)) (hDC, iLayerPlane, uType))

/* wglDeleteBufferRegionARB */
typedef VOID (WINAPI * GDK_GL_WGLDELETEBUFFERREGIONARBPROC) (HANDLE hRegion);
GdkGLProc gdk_gl_get_wglDeleteBufferRegionARB (void);
#define gdk_gl_wglDeleteBufferRegionARB(proc, hRegion) \
  (((GDK_GL_WGLDELETEBUFFERREGIONARBPROC) (proc)) (hRegion))

/* wglSaveBufferRegionARB */
typedef BOOL (WINAPI * GDK_GL_WGLSAVEBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height);
GdkGLProc gdk_gl_get_wglSaveBufferRegionARB (void);
#define gdk_gl_wglSaveBufferRegionARB(proc, hRegion, x, y, width, height) \
  (((GDK_GL_WGLSAVEBUFFERREGIONARBPROC) (proc)) (hRegion, x, y, width, height))

/* wglRestoreBufferRegionARB */
typedef BOOL (WINAPI * GDK_GL_WGLRESTOREBUFFERREGIONARBPROC) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
GdkGLProc gdk_gl_get_wglRestoreBufferRegionARB (void);
#define gdk_gl_wglRestoreBufferRegionARB(proc, hRegion, x, y, width, height, xSrc, ySrc) \
  (((GDK_GL_WGLRESTOREBUFFERREGIONARBPROC) (proc)) (hRegion, x, y, width, height, xSrc, ySrc))

/* 
 * WGL_ARB_extensions_string
 */

/* wglGetExtensionsStringARB */
typedef const char * (WINAPI * GDK_GL_WGLGETEXTENSIONSSTRINGARBPROC) (HDC hdc);
GdkGLProc gdk_gl_get_wglGetExtensionsStringARB (void);
#define gdk_gl_wglGetExtensionsStringARB(proc, hdc) \
  (((GDK_GL_WGLGETEXTENSIONSSTRINGARBPROC) (proc)) (hdc))

/* 
 * WGL_ARB_pixel_format
 */

/* wglGetPixelFormatAttribivARB */
typedef BOOL (WINAPI * GDK_GL_WGLGETPIXELFORMATATTRIBIVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribivARB (void);
#define gdk_gl_wglGetPixelFormatAttribivARB(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) \
  (((GDK_GL_WGLGETEXTENSIONSSTRINGARBPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues))

/* wglGetPixelFormatAttribfvARB */
typedef BOOL (WINAPI * GDK_GL_WGLGETPIXELFORMATATTRIBFVARBPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribfvARB (void);
#define gdk_gl_wglGetPixelFormatAttribfvARB(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) \
  (((GDK_GL_WGLGETPIXELFORMATATTRIBFVARBPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues))

/* wglChoosePixelFormatARB */
typedef BOOL (WINAPI * GDK_GL_WGLCHOOSEPIXELFORMATARBPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
GdkGLProc gdk_gl_get_wglChoosePixelFormatARB (void);
#define gdk_gl_wglChoosePixelFormatARB(proc, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) \
  (((GDK_GL_WGLCHOOSEPIXELFORMATARBPROC) (proc)) (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats))

/* 
 * WGL_ARB_make_current_read
 */

/* wglMakeContextCurrentARB */
typedef BOOL (WINAPI * GDK_GL_WGLMAKECONTEXTCURRENTARBPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
GdkGLProc gdk_gl_get_wglMakeContextCurrentARB (void);
#define gdk_gl_wglMakeContextCurrentARB(proc, hDrawDC, hReadDC, hglrc) \
  (((GDK_GL_WGLMAKECONTEXTCURRENTARBPROC) (proc)) (hDrawDC, hReadDC, hglrc))

/* wglGetCurrentReadDCARB */
typedef HDC (WINAPI * GDK_GL_WGLGETCURRENTREADDCARBPROC) (void);
GdkGLProc gdk_gl_get_wglGetCurrentReadDCARB (void);
#define gdk_gl_wglGetCurrentReadDCARB(proc) \
  (((GDK_GL_WGLGETCURRENTREADDCARBPROC) (proc)) ())

/* 
 * WGL_ARB_pbuffer
 */

/* wglCreatePbufferARB */
typedef HPBUFFERARB (WINAPI * GDK_GL_WGLCREATEPBUFFERARBPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
GdkGLProc gdk_gl_get_wglCreatePbufferARB (void);
#define gdk_gl_wglCreatePbufferARB(proc, hDC, iPixelFormat, iWidth, iHeight, piAttribList) \
  (((GDK_GL_WGLCREATEPBUFFERARBPROC) (proc)) (hDC, iPixelFormat, iWidth, iHeight, piAttribList))

/* wglGetPbufferDCARB */
typedef HDC (WINAPI * GDK_GL_WGLGETPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer);
GdkGLProc gdk_gl_get_wglGetPbufferDCARB (void);
#define gdk_gl_wglGetPbufferDCARB(proc, hPbuffer) \
  (((GDK_GL_WGLGETPBUFFERDCARBPROC) (proc)) (hPbuffer))

/* wglReleasePbufferDCARB */
typedef int (WINAPI * GDK_GL_WGLRELEASEPBUFFERDCARBPROC) (HPBUFFERARB hPbuffer, HDC hDC);
GdkGLProc gdk_gl_get_wglReleasePbufferDCARB (void);
#define gdk_gl_wglReleasePbufferDCARB(proc, hPbuffer, hDC) \
  (((GDK_GL_WGLRELEASEPBUFFERDCARBPROC) (proc)) (hPbuffer, hDC))

/* wglDestroyPbufferARB */
typedef BOOL (WINAPI * GDK_GL_WGLDESTROYPBUFFERARBPROC) (HPBUFFERARB hPbuffer);
GdkGLProc gdk_gl_get_wglDestroyPbufferARB (void);
#define gdk_gl_wglDestroyPbufferARB(proc, hPbuffer) \
  (((GDK_GL_WGLDESTROYPBUFFERARBPROC) (proc)) (hPbuffer))

/* wglQueryPbufferARB */
typedef BOOL (WINAPI * GDK_GL_WGLQUERYPBUFFERARBPROC) (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
GdkGLProc gdk_gl_get_wglQueryPbufferARB (void);
#define gdk_gl_wglQueryPbufferARB(proc, hPbuffer, iAttribute, piValue) \
  (((GDK_GL_WGLQUERYPBUFFERARBPROC) (proc)) (hPbuffer, iAttribute, piValue))

/* 
 * WGL_ARB_render_texture
 */

/* wglBindTexImageARB */
typedef BOOL (WINAPI * GDK_GL_WGLBINDTEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
GdkGLProc gdk_gl_get_wglBindTexImageARB (void);
#define gdk_gl_wglBindTexImageARB(proc, hPbuffer, iBuffer) \
  (((GDK_GL_WGLBINDTEXIMAGEARBPROC) (proc)) (hPbuffer, iBuffer))

/* wglReleaseTexImageARB */
typedef BOOL (WINAPI * GDK_GL_WGLRELEASETEXIMAGEARBPROC) (HPBUFFERARB hPbuffer, int iBuffer);
GdkGLProc gdk_gl_get_wglReleaseTexImageARB (void);
#define gdk_gl_wglReleaseTexImageARB(proc, hPbuffer, iBuffer) \
  (((GDK_GL_WGLRELEASETEXIMAGEARBPROC) (proc)) (hPbuffer, iBuffer))

/* wglSetPbufferAttribARB */
typedef BOOL (WINAPI * GDK_GL_WGLSETPBUFFERATTRIBARBPROC) (HPBUFFERARB hPbuffer, const int *piAttribList);
GdkGLProc gdk_gl_get_wglSetPbufferAttribARB (void);
#define gdk_gl_wglSetPbufferAttribARB(proc, hPbuffer, piAttribList) \
  (((GDK_GL_WGLSETPBUFFERATTRIBARBPROC) (proc)) (hPbuffer, piAttribList))

/* 
 * WGL_EXT_display_color_table
 */

/* wglCreateDisplayColorTableEXT */
typedef GLboolean (WINAPI * GDK_GL_WGLCREATEDISPLAYCOLORTABLEEXTPROC) (GLushort id);
GdkGLProc gdk_gl_get_wglCreateDisplayColorTableEXT (void);
#define gdk_gl_wglCreateDisplayColorTableEXT(proc, id) \
  (((GDK_GL_WGLCREATEDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* wglLoadDisplayColorTableEXT */
typedef GLboolean (WINAPI * GDK_GL_WGLLOADDISPLAYCOLORTABLEEXTPROC) (const GLushort *table, GLuint length);
GdkGLProc gdk_gl_get_wglLoadDisplayColorTableEXT (void);
#define gdk_gl_wglLoadDisplayColorTableEXT(proc, table, length) \
  (((GDK_GL_WGLLOADDISPLAYCOLORTABLEEXTPROC) (proc)) (table, length))

/* wglBindDisplayColorTableEXT */
typedef GLboolean (WINAPI * GDK_GL_WGLBINDDISPLAYCOLORTABLEEXTPROC) (GLushort id);
GdkGLProc gdk_gl_get_wglBindDisplayColorTableEXT (void);
#define gdk_gl_wglBindDisplayColorTableEXT(proc, id) \
  (((GDK_GL_WGLBINDDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* wglDestroyDisplayColorTableEXT */
typedef VOID (WINAPI * GDK_GL_WGLDESTROYDISPLAYCOLORTABLEEXTPROC) (GLushort id);
GdkGLProc gdk_gl_get_wglDestroyDisplayColorTableEXT (void);
#define gdk_gl_wglDestroyDisplayColorTableEXT(proc, id) \
  (((GDK_GL_WGLDESTROYDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* 
 * WGL_EXT_extensions_string
 */

/* wglGetExtensionsStringEXT */
typedef const char * (WINAPI * GDK_GL_WGLGETEXTENSIONSSTRINGEXTPROC) (void);
GdkGLProc gdk_gl_get_wglGetExtensionsStringEXT (void);
#define gdk_gl_wglGetExtensionsStringEXT(proc) \
  (((GDK_GL_WGLGETEXTENSIONSSTRINGEXTPROC) (proc)) ())

/* 
 * WGL_EXT_make_current_read
 */

/* wglMakeContextCurrentEXT */
typedef BOOL (WINAPI * GDK_GL_WGLMAKECONTEXTCURRENTEXTPROC) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
GdkGLProc gdk_gl_get_wglMakeContextCurrentEXT (void);
#define gdk_gl_wglMakeContextCurrentEXT(proc, hDrawDC, hReadDC, hglrc) \
  (((GDK_GL_WGLMAKECONTEXTCURRENTEXTPROC) (proc)) (hDrawDC, hReadDC, hglrc))

/* wglGetCurrentReadDCEXT */
typedef HDC (WINAPI * GDK_GL_WGLGETCURRENTREADDCEXTPROC) (void);
GdkGLProc gdk_gl_get_wglGetCurrentReadDCEXT (void);
#define gdk_gl_wglGetCurrentReadDCEXT(proc) \
  (((GDK_GL_WGLGETCURRENTREADDCEXTPROC) (proc)) ())

/* 
 * WGL_EXT_pbuffer
 */

/* wglCreatePbufferEXT */
typedef HPBUFFEREXT (WINAPI * GDK_GL_WGLCREATEPBUFFEREXTPROC) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
GdkGLProc gdk_gl_get_wglCreatePbufferEXT (void);
#define gdk_gl_wglCreatePbufferEXT(proc, hDC, iPixelFormat, iWidth, iHeight, piAttribList) \
  (((GDK_GL_WGLCREATEPBUFFEREXTPROC) (proc)) (hDC, iPixelFormat, iWidth, iHeight, piAttribList))

/* wglGetPbufferDCEXT */
typedef HDC (WINAPI * GDK_GL_WGLGETPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer);
GdkGLProc gdk_gl_get_wglGetPbufferDCEXT (void);
#define gdk_gl_wglGetPbufferDCEXT(proc, hPbuffer) \
  (((GDK_GL_WGLGETPBUFFERDCEXTPROC) (proc)) (hPbuffer))

/* wglReleasePbufferDCEXT */
typedef int (WINAPI * GDK_GL_WGLRELEASEPBUFFERDCEXTPROC) (HPBUFFEREXT hPbuffer, HDC hDC);
GdkGLProc gdk_gl_get_wglReleasePbufferDCEXT (void);
#define gdk_gl_wglReleasePbufferDCEXT(proc, hPbuffer, hDC) \
  (((GDK_GL_WGLRELEASEPBUFFERDCEXTPROC) (proc)) (hPbuffer, hDC))

/* wglDestroyPbufferEXT */
typedef BOOL (WINAPI * GDK_GL_WGLDESTROYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer);
GdkGLProc gdk_gl_get_wglDestroyPbufferEXT (void);
#define gdk_gl_wglDestroyPbufferEXT(proc, hPbuffer) \
  (((GDK_GL_WGLDESTROYPBUFFEREXTPROC) (proc)) (hPbuffer))

/* wglQueryPbufferEXT */
typedef BOOL (WINAPI * GDK_GL_WGLQUERYPBUFFEREXTPROC) (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
GdkGLProc gdk_gl_get_wglQueryPbufferEXT (void);
#define gdk_gl_wglQueryPbufferEXT(proc, hPbuffer, iAttribute, piValue) \
  (((GDK_GL_WGLQUERYPBUFFEREXTPROC) (proc)) (hPbuffer, iAttribute, piValue))

/* 
 * WGL_EXT_pixel_format
 */

/* wglGetPixelFormatAttribivEXT */
typedef BOOL (WINAPI * GDK_GL_WGLGETPIXELFORMATATTRIBIVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribivEXT (void);
#define gdk_gl_wglGetPixelFormatAttribivEXT(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) \
  (((GDK_GL_WGLGETPIXELFORMATATTRIBIVEXTPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues))

/* wglGetPixelFormatAttribfvEXT */
typedef BOOL (WINAPI * GDK_GL_WGLGETPIXELFORMATATTRIBFVEXTPROC) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribfvEXT (void);
#define gdk_gl_wglGetPixelFormatAttribfvEXT(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) \
  (((GDK_GL_WGLGETPIXELFORMATATTRIBFVEXTPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues))

/* wglChoosePixelFormatEXT */
typedef BOOL (WINAPI * GDK_GL_WGLCHOOSEPIXELFORMATEXTPROC) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
GdkGLProc gdk_gl_get_wglChoosePixelFormatEXT (void);
#define gdk_gl_wglChoosePixelFormatEXT(proc, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) \
  (((GDK_GL_WGLCHOOSEPIXELFORMATEXTPROC) (proc)) (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats))

/* 
 * WGL_EXT_swap_control
 */

/* wglSwapIntervalEXT */
typedef BOOL (WINAPI * GDK_GL_WGLSWAPINTERVALEXTPROC) (int interval);
GdkGLProc gdk_gl_get_wglSwapIntervalEXT (void);
#define gdk_gl_wglSwapIntervalEXT(proc, interval) \
  (((GDK_GL_WGLSWAPINTERVALEXTPROC) (proc)) (interval))

/* wglGetSwapIntervalEXT */
typedef int (WINAPI * GDK_GL_WGLGETSWAPINTERVALEXTPROC) (void);
GdkGLProc gdk_gl_get_wglGetSwapIntervalEXT (void);
#define gdk_gl_wglGetSwapIntervalEXT(proc) \
  (((GDK_GL_WGLGETSWAPINTERVALEXTPROC) (proc)) ())

/* 
 * WGL_NV_vertex_array_range
 */

/* wglAllocateMemoryNV */
typedef void* (WINAPI * GDK_GL_WGLALLOCATEMEMORYNVPROC) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
GdkGLProc gdk_gl_get_wglAllocateMemoryNV (void);
#define gdk_gl_wglAllocateMemoryNV(proc, size, readfreq, writefreq, priority) \
  (((GDK_GL_WGLALLOCATEMEMORYNVPROC) (proc)) (size, readfreq, writefreq, priority))

/* wglFreeMemoryNV */
typedef void (WINAPI * GDK_GL_WGLFREEMEMORYNVPROC) (void *pointer);
GdkGLProc gdk_gl_get_wglFreeMemoryNV (void);
#define gdk_gl_wglFreeMemoryNV(proc, pointer) \
  (((GDK_GL_WGLFREEMEMORYNVPROC) (proc)) (pointer))

/* 
 * WGL_OML_sync_control
 */

/* wglGetSyncValuesOML */
typedef BOOL (WINAPI * GDK_GL_WGLGETSYNCVALUESOMLPROC) (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
GdkGLProc gdk_gl_get_wglGetSyncValuesOML (void);
#define gdk_gl_wglGetSyncValuesOML(proc, hdc, ust, msc, sbc) \
  (((GDK_GL_WGLGETSYNCVALUESOMLPROC) (proc)) (hdc, ust, msc, sbc))

/* wglGetMscRateOML */
typedef BOOL (WINAPI * GDK_GL_WGLGETMSCRATEOMLPROC) (HDC hdc, INT32 *numerator, INT32 *denominator);
GdkGLProc gdk_gl_get_wglGetMscRateOML (void);
#define gdk_gl_wglGetMscRateOML(proc, hdc, numerator, denominator) \
  (((GDK_GL_WGLGETMSCRATEOMLPROC) (proc)) (hdc, numerator, denominator))

/* wglSwapBuffersMscOML */
typedef INT64 (WINAPI * GDK_GL_WGLSWAPBUFFERSMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
GdkGLProc gdk_gl_get_wglSwapBuffersMscOML (void);
#define gdk_gl_wglSwapBuffersMscOML(proc, hdc, target_msc, divisor, remainder) \
  (((GDK_GL_WGLSWAPBUFFERSMSCOMLPROC) (proc)) (hdc, target_msc, divisor, remainder))

/* wglSwapLayerBuffersMscOML */
typedef INT64 (WINAPI * GDK_GL_WGLSWAPLAYERBUFFERSMSCOMLPROC) (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
GdkGLProc gdk_gl_get_wglSwapLayerBuffersMscOML (void);
#define gdk_gl_wglSwapLayerBuffersMscOML(proc, hdc, fuPlanes, target_msc, divisor, remainder) \
  (((GDK_GL_WGLSWAPLAYERBUFFERSMSCOMLPROC) (proc)) (hdc, fuPlanes, target_msc, divisor, remainder))

/* wglWaitForMscOML */
typedef BOOL (WINAPI * GDK_GL_WGLWAITFORMSCOMLPROC) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
GdkGLProc gdk_gl_get_wglWaitForMscOML (void);
#define gdk_gl_wglWaitForMscOML(proc, hdc, target_msc, divisor, remainder, ust, msc, sbc) \
  (((GDK_GL_WGLWAITFORMSCOMLPROC) (proc)) (hdc, target_msc, divisor, remainder, ust, msc, sbc))

/* wglWaitForSbcOML */
typedef BOOL (WINAPI * GDK_GL_WGLWAITFORSBCOMLPROC) (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
GdkGLProc gdk_gl_get_wglWaitForSbcOML (void);
#define gdk_gl_wglWaitForSbcOML(proc, hdc, target_sbc, ust, msc, sbc) \
  (((GDK_GL_WGLWAITFORSBCOMLPROC) (proc)) (hdc, target_sbc, ust, msc, sbc))

/* 
 * WGL_I3D_digital_video_control
 */

/* wglGetDigitalVideoParametersI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int *piValue);
GdkGLProc gdk_gl_get_wglGetDigitalVideoParametersI3D (void);
#define gdk_gl_wglGetDigitalVideoParametersI3D(proc, hDC, iAttribute, piValue) \
  (((GDK_GL_WGLGETDIGITALVIDEOPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* wglSetDigitalVideoParametersI3D */
typedef BOOL (WINAPI * GDK_GL_WGLSETDIGITALVIDEOPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int *piValue);
GdkGLProc gdk_gl_get_wglSetDigitalVideoParametersI3D (void);
#define gdk_gl_wglSetDigitalVideoParametersI3D(proc, hDC, iAttribute, piValue) \
  (((GDK_GL_WGLSETDIGITALVIDEOPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* 
 * WGL_I3D_gamma
 */

/* wglGetGammaTableParametersI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, int *piValue);
GdkGLProc gdk_gl_get_wglGetGammaTableParametersI3D (void);
#define gdk_gl_wglGetGammaTableParametersI3D(proc, hDC, iAttribute, piValue) \
  (((GDK_GL_WGLGETGAMMATABLEPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* wglSetGammaTableParametersI3D */
typedef BOOL (WINAPI * GDK_GL_WGLSETGAMMATABLEPARAMETERSI3DPROC) (HDC hDC, int iAttribute, const int *piValue);
GdkGLProc gdk_gl_get_wglSetGammaTableParametersI3D (void);
#define gdk_gl_wglSetGammaTableParametersI3D(proc, hDC, iAttribute, piValue) \
  (((GDK_GL_WGLSETGAMMATABLEPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* wglGetGammaTableI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
GdkGLProc gdk_gl_get_wglGetGammaTableI3D (void);
#define gdk_gl_wglGetGammaTableI3D(proc, hDC, iEntries, puRed, puGreen, puBlue) \
  (((GDK_GL_WGLGETGAMMATABLEI3DPROC) (proc)) (hDC, iEntries, puRed, puGreen, puBlue))

/* wglSetGammaTableI3D */
typedef BOOL (WINAPI * GDK_GL_WGLSETGAMMATABLEI3DPROC) (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
GdkGLProc gdk_gl_get_wglSetGammaTableI3D (void);
#define gdk_gl_wglSetGammaTableI3D(proc, hDC, iEntries, puRed, puGreen, puBlue) \
  (((GDK_GL_WGLSETGAMMATABLEI3DPROC) (proc)) (hDC, iEntries, puRed, puGreen, puBlue))

/* 
 * WGL_I3D_genlock
 */

/* wglEnableGenlockI3D */
typedef BOOL (WINAPI * GDK_GL_WGLENABLEGENLOCKI3DPROC) (HDC hDC);
GdkGLProc gdk_gl_get_wglEnableGenlockI3D (void);
#define gdk_gl_wglEnableGenlockI3D(proc, hDC) \
  (((GDK_GL_WGLENABLEGENLOCKI3DPROC) (proc)) (hDC))

/* wglDisableGenlockI3D */
typedef BOOL (WINAPI * GDK_GL_WGLDISABLEGENLOCKI3DPROC) (HDC hDC);
GdkGLProc gdk_gl_get_wglDisableGenlockI3D (void);
#define gdk_gl_wglDisableGenlockI3D(proc, hDC) \
  (((GDK_GL_WGLDISABLEGENLOCKI3DPROC) (proc)) (hDC))

/* wglIsEnabledGenlockI3D */
typedef BOOL (WINAPI * GDK_GL_WGLISENABLEDGENLOCKI3DPROC) (HDC hDC, BOOL *pFlag);
GdkGLProc gdk_gl_get_wglIsEnabledGenlockI3D (void);
#define gdk_gl_wglIsEnabledGenlockI3D(proc, hDC, pFlag) \
  (((GDK_GL_WGLISENABLEDGENLOCKI3DPROC) (proc)) (hDC, pFlag))

/* wglGenlockSourceI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGENLOCKSOURCEI3DPROC) (HDC hDC, UINT uSource);
GdkGLProc gdk_gl_get_wglGenlockSourceI3D (void);
#define gdk_gl_wglGenlockSourceI3D(proc, hDC, uSource) \
  (((GDK_GL_WGLGENLOCKSOURCEI3DPROC) (proc)) (hDC, uSource))

/* wglGetGenlockSourceI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGETGENLOCKSOURCEI3DPROC) (HDC hDC, UINT *uSource);
GdkGLProc gdk_gl_get_wglGetGenlockSourceI3D (void);
#define gdk_gl_wglGetGenlockSourceI3D(proc, hDC, uSource) \
  (((GDK_GL_WGLGETGENLOCKSOURCEI3DPROC) (proc)) (hDC, uSource))

/* wglGenlockSourceEdgeI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT uEdge);
GdkGLProc gdk_gl_get_wglGenlockSourceEdgeI3D (void);
#define gdk_gl_wglGenlockSourceEdgeI3D(proc, hDC, uEdge) \
  (((GDK_GL_WGLGENLOCKSOURCEEDGEI3DPROC) (proc)) (hDC, uEdge))

/* wglGetGenlockSourceEdgeI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGETGENLOCKSOURCEEDGEI3DPROC) (HDC hDC, UINT *uEdge);
GdkGLProc gdk_gl_get_wglGetGenlockSourceEdgeI3D (void);
#define gdk_gl_wglGetGenlockSourceEdgeI3D(proc, hDC, uEdge) \
  (((GDK_GL_WGLGETGENLOCKSOURCEEDGEI3DPROC) (proc)) (hDC, uEdge))

/* wglGenlockSampleRateI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT uRate);
GdkGLProc gdk_gl_get_wglGenlockSampleRateI3D (void);
#define gdk_gl_wglGenlockSampleRateI3D(proc, hDC, uRate) \
  (((GDK_GL_WGLGENLOCKSAMPLERATEI3DPROC) (proc)) (hDC, uRate))

/* wglGetGenlockSampleRateI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGETGENLOCKSAMPLERATEI3DPROC) (HDC hDC, UINT *uRate);
GdkGLProc gdk_gl_get_wglGetGenlockSampleRateI3D (void);
#define gdk_gl_wglGetGenlockSampleRateI3D(proc, hDC, uRate) \
  (((GDK_GL_WGLGETGENLOCKSAMPLERATEI3DPROC) (proc)) (hDC, uRate))

/* wglGenlockSourceDelayI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT uDelay);
GdkGLProc gdk_gl_get_wglGenlockSourceDelayI3D (void);
#define gdk_gl_wglGenlockSourceDelayI3D(proc, hDC, uDelay) \
  (((GDK_GL_WGLGENLOCKSOURCEDELAYI3DPROC) (proc)) (hDC, uDelay))

/* wglGetGenlockSourceDelayI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGETGENLOCKSOURCEDELAYI3DPROC) (HDC hDC, UINT *uDelay);
GdkGLProc gdk_gl_get_wglGetGenlockSourceDelayI3D (void);
#define gdk_gl_wglGetGenlockSourceDelayI3D(proc, hDC, uDelay) \
  (((GDK_GL_WGLGETGENLOCKSOURCEDELAYI3DPROC) (proc)) (hDC, uDelay))

/* wglQueryGenlockMaxSourceDelayI3D */
typedef BOOL (WINAPI * GDK_GL_WGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
GdkGLProc gdk_gl_get_wglQueryGenlockMaxSourceDelayI3D (void);
#define gdk_gl_wglQueryGenlockMaxSourceDelayI3D(proc, hDC, uMaxLineDelay, uMaxPixelDelay) \
  (((GDK_GL_WGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (proc)) (hDC, uMaxLineDelay, uMaxPixelDelay))

/* 
 * WGL_I3D_image_buffer
 */

/* wglCreateImageBufferI3D */
typedef LPVOID (WINAPI * GDK_GL_WGLCREATEIMAGEBUFFERI3DPROC) (HDC hDC, DWORD dwSize, UINT uFlags);
GdkGLProc gdk_gl_get_wglCreateImageBufferI3D (void);
#define gdk_gl_wglCreateImageBufferI3D(proc, hDC, dwSize, uFlags) \
  (((GDK_GL_WGLCREATEIMAGEBUFFERI3DPROC) (proc)) (hDC, dwSize, uFlags))

/* wglDestroyImageBufferI3D */
typedef BOOL (WINAPI * GDK_GL_WGLDESTROYIMAGEBUFFERI3DPROC) (HDC hDC, LPVOID pAddress);
GdkGLProc gdk_gl_get_wglDestroyImageBufferI3D (void);
#define gdk_gl_wglDestroyImageBufferI3D(proc, hDC, pAddress) \
  (((GDK_GL_WGLDESTROYIMAGEBUFFERI3DPROC) (proc)) (hDC, pAddress))

/* wglAssociateImageBufferEventsI3D */
typedef BOOL (WINAPI * GDK_GL_WGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
GdkGLProc gdk_gl_get_wglAssociateImageBufferEventsI3D (void);
#define gdk_gl_wglAssociateImageBufferEventsI3D(proc, hDC, pEvent, pAddress, pSize, count) \
  (((GDK_GL_WGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (proc)) (hDC, pEvent, pAddress, pSize, count))

/* wglReleaseImageBufferEventsI3D */
typedef BOOL (WINAPI * GDK_GL_WGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (HDC hDC, const LPVOID *pAddress, UINT count);
GdkGLProc gdk_gl_get_wglReleaseImageBufferEventsI3D (void);
#define gdk_gl_wglReleaseImageBufferEventsI3D(proc, hDC, pAddress, count) \
  (((GDK_GL_WGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (proc)) (hDC, pAddress, count))

/* 
 * WGL_I3D_swap_frame_lock
 */

/* wglEnableFrameLockI3D */
typedef BOOL (WINAPI * GDK_GL_WGLENABLEFRAMELOCKI3DPROC) (void);
GdkGLProc gdk_gl_get_wglEnableFrameLockI3D (void);
#define gdk_gl_wglEnableFrameLockI3D(proc) \
  (((GDK_GL_WGLENABLEFRAMELOCKI3DPROC) (proc)) ())

/* wglDisableFrameLockI3D */
typedef BOOL (WINAPI * GDK_GL_WGLDISABLEFRAMELOCKI3DPROC) (void);
GdkGLProc gdk_gl_get_wglDisableFrameLockI3D (void);
#define gdk_gl_wglDisableFrameLockI3D(proc) \
  (((GDK_GL_WGLDISABLEFRAMELOCKI3DPROC) (proc)) ())

/* wglIsEnabledFrameLockI3D */
typedef BOOL (WINAPI * GDK_GL_WGLISENABLEDFRAMELOCKI3DPROC) (BOOL *pFlag);
GdkGLProc gdk_gl_get_wglIsEnabledFrameLockI3D (void);
#define gdk_gl_wglIsEnabledFrameLockI3D(proc, pFlag) \
  (((GDK_GL_WGLISENABLEDFRAMELOCKI3DPROC) (proc)) (pFlag))

/* wglQueryFrameLockMasterI3D */
typedef BOOL (WINAPI * GDK_GL_WGLQUERYFRAMELOCKMASTERI3DPROC) (BOOL *pFlag);
GdkGLProc gdk_gl_get_wglQueryFrameLockMasterI3D (void);
#define gdk_gl_wglQueryFrameLockMasterI3D(proc, pFlag) \
  (((GDK_GL_WGLQUERYFRAMELOCKMASTERI3DPROC) (proc)) (pFlag))

/* 
 * WGL_I3D_swap_frame_usage
 */

/* wglGetFrameUsageI3D */
typedef BOOL (WINAPI * GDK_GL_WGLGETFRAMEUSAGEI3DPROC) (float *pUsage);
GdkGLProc gdk_gl_get_wglGetFrameUsageI3D (void);
#define gdk_gl_wglGetFrameUsageI3D(proc, pUsage) \
  (((GDK_GL_WGLGETFRAMEUSAGEI3DPROC) (proc)) (pUsage))

/* wglBeginFrameTrackingI3D */
typedef BOOL (WINAPI * GDK_GL_WGLBEGINFRAMETRACKINGI3DPROC) (void);
GdkGLProc gdk_gl_get_wglBeginFrameTrackingI3D (void);
#define gdk_gl_wglBeginFrameTrackingI3D(proc) \
  (((GDK_GL_WGLBEGINFRAMETRACKINGI3DPROC) (proc)) ())

/* wglEndFrameTrackingI3D */
typedef BOOL (WINAPI * GDK_GL_WGLENDFRAMETRACKINGI3DPROC) (void);
GdkGLProc gdk_gl_get_wglEndFrameTrackingI3D (void);
#define gdk_gl_wglEndFrameTrackingI3D(proc) \
  (((GDK_GL_WGLENDFRAMETRACKINGI3DPROC) (proc)) ())

/* wglQueryFrameTrackingI3D */
typedef BOOL (WINAPI * GDK_GL_WGLQUERYFRAMETRACKINGI3DPROC) (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
GdkGLProc gdk_gl_get_wglQueryFrameTrackingI3D (void);
#define gdk_gl_wglQueryFrameTrackingI3D(proc, pFrameCount, pMissedFrames, pLastMissedUsage) \
  (((GDK_GL_WGLQUERYFRAMETRACKINGI3DPROC) (proc)) (pFrameCount, pMissedFrames, pLastMissedUsage))

G_END_DECLS

#endif /* __GDK_GL_WGL_EXT_H__ */
