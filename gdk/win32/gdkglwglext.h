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

#ifndef __GDK_GL_WGLEXT_H__
#define __GDK_GL_WGLEXT_H__

#include <GL/gl.h>

#include <gdk/glext/wglext.h>

#include <gdk/gdkglquery.h>

G_BEGIN_DECLS

/* 
 * WGL_ARB_buffer_region
 */

/* HANDLE WINAPI wglCreateBufferRegionARB (HDC, int, UINT) */
GdkGLProc gdk_gl_get_wglCreateBufferRegionARB (void);
#define   gdk_gl_wglCreateBufferRegionARB(proc, hDC, iLayerPlane, uType) \
  (((PFNWGLCREATEBUFFERREGIONARBPROC) (proc)) (hDC, iLayerPlane, uType))

/* VOID WINAPI wglDeleteBufferRegionARB (HANDLE) */
GdkGLProc gdk_gl_get_wglDeleteBufferRegionARB (void);
#define   gdk_gl_wglDeleteBufferRegionARB(proc, hRegion) \
  (((PFNWGLDELETEBUFFERREGIONARBPROC) (proc)) (hRegion))

/* BOOL WINAPI wglSaveBufferRegionARB (HANDLE, int, int, int, int) */
GdkGLProc gdk_gl_get_wglSaveBufferRegionARB (void);
#define   gdk_gl_wglSaveBufferRegionARB(proc, hRegion, x, y, width, height) \
  (((PFNWGLSAVEBUFFERREGIONARBPROC) (proc)) (hRegion, x, y, width, height))

/* BOOL WINAPI wglRestoreBufferRegionARB (HANDLE, int, int, int, int, int, int) */
GdkGLProc gdk_gl_get_wglRestoreBufferRegionARB (void);
#define   gdk_gl_wglRestoreBufferRegionARB(proc, hRegion, x, y, width, height, xSrc, ySrc) \
  (((PFNWGLRESTOREBUFFERREGIONARBPROC) (proc)) (hRegion, x, y, width, height, xSrc, ySrc))

/* 
 * WGL_ARB_extensions_string
 */

/* const char * WINAPI wglGetExtensionsStringARB (HDC) */
GdkGLProc gdk_gl_get_wglGetExtensionsStringARB (void);
#define   gdk_gl_wglGetExtensionsStringARB(proc, hdc) \
  (((PFNWGLGETEXTENSIONSSTRINGARBPROC) (proc)) (hdc))

/* 
 * WGL_ARB_pixel_format
 */

/* BOOL WINAPI wglGetPixelFormatAttribivARB (HDC, int, int, UINT, const int *, int *) */
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribivARB (void);
#define   gdk_gl_wglGetPixelFormatAttribivARB(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) \
  (((PFNWGLGETEXTENSIONSSTRINGARBPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues))

/* BOOL WINAPI wglGetPixelFormatAttribfvARB (HDC, int, int, UINT, const int *, FLOAT *) */
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribfvARB (void);
#define   gdk_gl_wglGetPixelFormatAttribfvARB(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) \
  (((PFNWGLGETPIXELFORMATATTRIBFVARBPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues))

/* BOOL WINAPI wglChoosePixelFormatARB (HDC, const int *, const FLOAT *, UINT, int *, UINT *) */
GdkGLProc gdk_gl_get_wglChoosePixelFormatARB (void);
#define   gdk_gl_wglChoosePixelFormatARB(proc, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) \
  (((PFNWGLCHOOSEPIXELFORMATARBPROC) (proc)) (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats))

/* 
 * WGL_ARB_make_current_read
 */

/* BOOL WINAPI wglMakeContextCurrentARB (HDC, HDC, HGLRC) */
GdkGLProc gdk_gl_get_wglMakeContextCurrentARB (void);
#define   gdk_gl_wglMakeContextCurrentARB(proc, hDrawDC, hReadDC, hglrc) \
  (((PFNWGLMAKECONTEXTCURRENTARBPROC) (proc)) (hDrawDC, hReadDC, hglrc))

/* HDC WINAPI wglGetCurrentReadDCARB (void) */
GdkGLProc gdk_gl_get_wglGetCurrentReadDCARB (void);
#define   gdk_gl_wglGetCurrentReadDCARB(proc) \
  (((PFNWGLGETCURRENTREADDCARBPROC) (proc)) ())

/* 
 * WGL_ARB_pbuffer
 */

/* HPBUFFERARB WINAPI wglCreatePbufferARB (HDC, int, int, int, const int *) */
GdkGLProc gdk_gl_get_wglCreatePbufferARB (void);
#define   gdk_gl_wglCreatePbufferARB(proc, hDC, iPixelFormat, iWidth, iHeight, piAttribList) \
  (((PFNWGLCREATEPBUFFERARBPROC) (proc)) (hDC, iPixelFormat, iWidth, iHeight, piAttribList))

/* HDC WINAPI wglGetPbufferDCARB (HPBUFFERARB) */
GdkGLProc gdk_gl_get_wglGetPbufferDCARB (void);
#define   gdk_gl_wglGetPbufferDCARB(proc, hPbuffer) \
  (((PFNWGLGETPBUFFERDCARBPROC) (proc)) (hPbuffer))

/* int WINAPI wglReleasePbufferDCARB (HPBUFFERARB, HDC) */
GdkGLProc gdk_gl_get_wglReleasePbufferDCARB (void);
#define   gdk_gl_wglReleasePbufferDCARB(proc, hPbuffer, hDC) \
  (((PFNWGLRELEASEPBUFFERDCARBPROC) (proc)) (hPbuffer, hDC))

/* BOOL WINAPI wglDestroyPbufferARB (HPBUFFERARB) */
GdkGLProc gdk_gl_get_wglDestroyPbufferARB (void);
#define   gdk_gl_wglDestroyPbufferARB(proc, hPbuffer) \
  (((PFNWGLDESTROYPBUFFERARBPROC) (proc)) (hPbuffer))

/* BOOL WINAPI wglQueryPbufferARB (HPBUFFERARB, int, int *) */
GdkGLProc gdk_gl_get_wglQueryPbufferARB (void);
#define   gdk_gl_wglQueryPbufferARB(proc, hPbuffer, iAttribute, piValue) \
  (((PFNWGLQUERYPBUFFERARBPROC) (proc)) (hPbuffer, iAttribute, piValue))

/* 
 * WGL_ARB_render_texture
 */

/* BOOL WINAPI wglBindTexImageARB (HPBUFFERARB, int) */
GdkGLProc gdk_gl_get_wglBindTexImageARB (void);
#define   gdk_gl_wglBindTexImageARB(proc, hPbuffer, iBuffer) \
  (((PFNWGLBINDTEXIMAGEARBPROC) (proc)) (hPbuffer, iBuffer))

/* BOOL WINAPI wglReleaseTexImageARB (HPBUFFERARB, int) */
GdkGLProc gdk_gl_get_wglReleaseTexImageARB (void);
#define   gdk_gl_wglReleaseTexImageARB(proc, hPbuffer, iBuffer) \
  (((PFNWGLRELEASETEXIMAGEARBPROC) (proc)) (hPbuffer, iBuffer))

/* BOOL WINAPI wglSetPbufferAttribARB (HPBUFFERARB, const int *) */
GdkGLProc gdk_gl_get_wglSetPbufferAttribARB (void);
#define   gdk_gl_wglSetPbufferAttribARB(proc, hPbuffer, piAttribList) \
  (((PFNWGLSETPBUFFERATTRIBARBPROC) (proc)) (hPbuffer, piAttribList))

/* 
 * WGL_EXT_display_color_table
 */

/* GLboolean WINAPI wglCreateDisplayColorTableEXT (GLushort) */
GdkGLProc gdk_gl_get_wglCreateDisplayColorTableEXT (void);
#define   gdk_gl_wglCreateDisplayColorTableEXT(proc, id) \
  (((PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* GLboolean WINAPI wglLoadDisplayColorTableEXT (const GLushort *, GLuint) */
GdkGLProc gdk_gl_get_wglLoadDisplayColorTableEXT (void);
#define   gdk_gl_wglLoadDisplayColorTableEXT(proc, table, length) \
  (((PFNWGLLOADDISPLAYCOLORTABLEEXTPROC) (proc)) (table, length))

/* GLboolean WINAPI wglBindDisplayColorTableEXT (GLushort) */
GdkGLProc gdk_gl_get_wglBindDisplayColorTableEXT (void);
#define   gdk_gl_wglBindDisplayColorTableEXT(proc, id) \
  (((PFNWGLBINDDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* VOID WINAPI wglDestroyDisplayColorTableEXT (GLushort) */
GdkGLProc gdk_gl_get_wglDestroyDisplayColorTableEXT (void);
#define   gdk_gl_wglDestroyDisplayColorTableEXT(proc, id) \
  (((PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* 
 * WGL_EXT_extensions_string
 */

/* const char * WINAPI wglGetExtensionsStringEXT (void) */
GdkGLProc gdk_gl_get_wglGetExtensionsStringEXT (void);
#define   gdk_gl_wglGetExtensionsStringEXT(proc) \
  (((PFNWGLGETEXTENSIONSSTRINGEXTPROC) (proc)) ())

/* 
 * WGL_EXT_make_current_read
 */

/* BOOL WINAPI wglMakeContextCurrentEXT (HDC, HDC, HGLRC) */
GdkGLProc gdk_gl_get_wglMakeContextCurrentEXT (void);
#define   gdk_gl_wglMakeContextCurrentEXT(proc, hDrawDC, hReadDC, hglrc) \
  (((PFNWGLMAKECONTEXTCURRENTEXTPROC) (proc)) (hDrawDC, hReadDC, hglrc))

/* HDC WINAPI wglGetCurrentReadDCEXT (void) */
GdkGLProc gdk_gl_get_wglGetCurrentReadDCEXT (void);
#define   gdk_gl_wglGetCurrentReadDCEXT(proc) \
  (((PFNWGLGETCURRENTREADDCEXTPROC) (proc)) ())

/* 
 * WGL_EXT_pbuffer
 */

/* HPBUFFEREXT WINAPI wglCreatePbufferEXT (HDC, int, int, int, const int *) */
GdkGLProc gdk_gl_get_wglCreatePbufferEXT (void);
#define   gdk_gl_wglCreatePbufferEXT(proc, hDC, iPixelFormat, iWidth, iHeight, piAttribList) \
  (((PFNWGLCREATEPBUFFEREXTPROC) (proc)) (hDC, iPixelFormat, iWidth, iHeight, piAttribList))

/* HDC WINAPI wglGetPbufferDCEXT (HPBUFFEREXT) */
GdkGLProc gdk_gl_get_wglGetPbufferDCEXT (void);
#define   gdk_gl_wglGetPbufferDCEXT(proc, hPbuffer) \
  (((PFNWGLGETPBUFFERDCEXTPROC) (proc)) (hPbuffer))

/* int WINAPI wglReleasePbufferDCEXT (HPBUFFEREXT, HDC) */
GdkGLProc gdk_gl_get_wglReleasePbufferDCEXT (void);
#define   gdk_gl_wglReleasePbufferDCEXT(proc, hPbuffer, hDC) \
  (((PFNWGLRELEASEPBUFFERDCEXTPROC) (proc)) (hPbuffer, hDC))

/* BOOL WINAPI wglDestroyPbufferEXT (HPBUFFEREXT) */
GdkGLProc gdk_gl_get_wglDestroyPbufferEXT (void);
#define   gdk_gl_wglDestroyPbufferEXT(proc, hPbuffer) \
  (((PFNWGLDESTROYPBUFFEREXTPROC) (proc)) (hPbuffer))

/* BOOL WINAPI wglQueryPbufferEXT (HPBUFFEREXT, int, int *) */
GdkGLProc gdk_gl_get_wglQueryPbufferEXT (void);
#define   gdk_gl_wglQueryPbufferEXT(proc, hPbuffer, iAttribute, piValue) \
  (((PFNWGLQUERYPBUFFEREXTPROC) (proc)) (hPbuffer, iAttribute, piValue))

/* 
 * WGL_EXT_pixel_format
 */

/* BOOL WINAPI wglGetPixelFormatAttribivEXT (HDC, int, int, UINT, int *, int *) */
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribivEXT (void);
#define   gdk_gl_wglGetPixelFormatAttribivEXT(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) \
  (((PFNWGLGETPIXELFORMATATTRIBIVEXTPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues))

/* BOOL WINAPI wglGetPixelFormatAttribfvEXT (HDC, int, int, UINT, int *, FLOAT *) */
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribfvEXT (void);
#define   gdk_gl_wglGetPixelFormatAttribfvEXT(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) \
  (((PFNWGLGETPIXELFORMATATTRIBFVEXTPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues))

/* BOOL WINAPI wglChoosePixelFormatEXT (HDC, const int *, const FLOAT *, UINT, int *, UINT *) */
GdkGLProc gdk_gl_get_wglChoosePixelFormatEXT (void);
#define   gdk_gl_wglChoosePixelFormatEXT(proc, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) \
  (((PFNWGLCHOOSEPIXELFORMATEXTPROC) (proc)) (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats))

/* 
 * WGL_EXT_swap_control
 */

/* BOOL WINAPI wglSwapIntervalEXT (int) */
GdkGLProc gdk_gl_get_wglSwapIntervalEXT (void);
#define   gdk_gl_wglSwapIntervalEXT(proc, interval) \
  (((PFNWGLSWAPINTERVALEXTPROC) (proc)) (interval))

/* int WINAPI wglGetSwapIntervalEXT (void) */
GdkGLProc gdk_gl_get_wglGetSwapIntervalEXT (void);
#define   gdk_gl_wglGetSwapIntervalEXT(proc) \
  (((PFNWGLGETSWAPINTERVALEXTPROC) (proc)) ())

/* 
 * WGL_NV_vertex_array_range
 */

/* void* WINAPI wglAllocateMemoryNV (GLsizei, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_wglAllocateMemoryNV (void);
#define   gdk_gl_wglAllocateMemoryNV(proc, size, readfreq, writefreq, priority) \
  (((PFNWGLALLOCATEMEMORYNVPROC) (proc)) (size, readfreq, writefreq, priority))

/* void WINAPI wglFreeMemoryNV (void *) */
GdkGLProc gdk_gl_get_wglFreeMemoryNV (void);
#define   gdk_gl_wglFreeMemoryNV(proc, pointer) \
  (((PFNWGLFREEMEMORYNVPROC) (proc)) (pointer))

/* 
 * WGL_OML_sync_control
 */

/* BOOL WINAPI wglGetSyncValuesOML (HDC, INT64 *, INT64 *, INT64 *) */
GdkGLProc gdk_gl_get_wglGetSyncValuesOML (void);
#define   gdk_gl_wglGetSyncValuesOML(proc, hdc, ust, msc, sbc) \
  (((PFNWGLGETSYNCVALUESOMLPROC) (proc)) (hdc, ust, msc, sbc))

/* BOOL WINAPI wglGetMscRateOML (HDC, INT32 *, INT32 *) */
GdkGLProc gdk_gl_get_wglGetMscRateOML (void);
#define   gdk_gl_wglGetMscRateOML(proc, hdc, numerator, denominator) \
  (((PFNWGLGETMSCRATEOMLPROC) (proc)) (hdc, numerator, denominator))

/* INT64 WINAPI wglSwapBuffersMscOML (HDC, INT64, INT64, INT64) */
GdkGLProc gdk_gl_get_wglSwapBuffersMscOML (void);
#define   gdk_gl_wglSwapBuffersMscOML(proc, hdc, target_msc, divisor, remainder) \
  (((PFNWGLSWAPBUFFERSMSCOMLPROC) (proc)) (hdc, target_msc, divisor, remainder))

/* INT64 WINAPI wglSwapLayerBuffersMscOML (HDC, int, INT64, INT64, INT64) */
GdkGLProc gdk_gl_get_wglSwapLayerBuffersMscOML (void);
#define   gdk_gl_wglSwapLayerBuffersMscOML(proc, hdc, fuPlanes, target_msc, divisor, remainder) \
  (((PFNWGLSWAPLAYERBUFFERSMSCOMLPROC) (proc)) (hdc, fuPlanes, target_msc, divisor, remainder))

/* BOOL WINAPI wglWaitForMscOML (HDC, INT64, INT64, INT64, INT64 *, INT64 *, INT64 *) */
GdkGLProc gdk_gl_get_wglWaitForMscOML (void);
#define   gdk_gl_wglWaitForMscOML(proc, hdc, target_msc, divisor, remainder, ust, msc, sbc) \
  (((PFNWGLWAITFORMSCOMLPROC) (proc)) (hdc, target_msc, divisor, remainder, ust, msc, sbc))

/* BOOL WINAPI wglWaitForSbcOML (HDC, INT64, INT64 *, INT64 *, INT64 *) */
GdkGLProc gdk_gl_get_wglWaitForSbcOML (void);
#define   gdk_gl_wglWaitForSbcOML(proc, hdc, target_sbc, ust, msc, sbc) \
  (((PFNWGLWAITFORSBCOMLPROC) (proc)) (hdc, target_sbc, ust, msc, sbc))

/* 
 * WGL_I3D_digital_video_control
 */

/* BOOL WINAPI wglGetDigitalVideoParametersI3D (HDC, int, int *) */
GdkGLProc gdk_gl_get_wglGetDigitalVideoParametersI3D (void);
#define   gdk_gl_wglGetDigitalVideoParametersI3D(proc, hDC, iAttribute, piValue) \
  (((PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* BOOL WINAPI wglSetDigitalVideoParametersI3D (HDC, int, const int *) */
GdkGLProc gdk_gl_get_wglSetDigitalVideoParametersI3D (void);
#define   gdk_gl_wglSetDigitalVideoParametersI3D(proc, hDC, iAttribute, piValue) \
  (((PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* 
 * WGL_I3D_gamma
 */

/* BOOL WINAPI wglGetGammaTableParametersI3D (HDC, int, int *) */
GdkGLProc gdk_gl_get_wglGetGammaTableParametersI3D (void);
#define   gdk_gl_wglGetGammaTableParametersI3D(proc, hDC, iAttribute, piValue) \
  (((PFNWGLGETGAMMATABLEPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* BOOL WINAPI wglSetGammaTableParametersI3D (HDC, int, const int *) */
GdkGLProc gdk_gl_get_wglSetGammaTableParametersI3D (void);
#define   gdk_gl_wglSetGammaTableParametersI3D(proc, hDC, iAttribute, piValue) \
  (((PFNWGLSETGAMMATABLEPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* BOOL WINAPI wglGetGammaTableI3D (HDC, int, USHORT *, USHORT *, USHORT *) */
GdkGLProc gdk_gl_get_wglGetGammaTableI3D (void);
#define   gdk_gl_wglGetGammaTableI3D(proc, hDC, iEntries, puRed, puGreen, puBlue) \
  (((PFNWGLGETGAMMATABLEI3DPROC) (proc)) (hDC, iEntries, puRed, puGreen, puBlue))

/* BOOL WINAPI wglSetGammaTableI3D (HDC, int, const USHORT *, const USHORT *, const USHORT *) */
GdkGLProc gdk_gl_get_wglSetGammaTableI3D (void);
#define   gdk_gl_wglSetGammaTableI3D(proc, hDC, iEntries, puRed, puGreen, puBlue) \
  (((PFNWGLSETGAMMATABLEI3DPROC) (proc)) (hDC, iEntries, puRed, puGreen, puBlue))

/* 
 * WGL_I3D_genlock
 */

/* BOOL WINAPI wglEnableGenlockI3D (HDC) */
GdkGLProc gdk_gl_get_wglEnableGenlockI3D (void);
#define   gdk_gl_wglEnableGenlockI3D(proc, hDC) \
  (((PFNWGLENABLEGENLOCKI3DPROC) (proc)) (hDC))

/* BOOL WINAPI wglDisableGenlockI3D (HDC) */
GdkGLProc gdk_gl_get_wglDisableGenlockI3D (void);
#define   gdk_gl_wglDisableGenlockI3D(proc, hDC) \
  (((PFNWGLDISABLEGENLOCKI3DPROC) (proc)) (hDC))

/* BOOL WINAPI wglIsEnabledGenlockI3D (HDC, BOOL *) */
GdkGLProc gdk_gl_get_wglIsEnabledGenlockI3D (void);
#define   gdk_gl_wglIsEnabledGenlockI3D(proc, hDC, pFlag) \
  (((PFNWGLISENABLEDGENLOCKI3DPROC) (proc)) (hDC, pFlag))

/* BOOL WINAPI wglGenlockSourceI3D (HDC, UINT) */
GdkGLProc gdk_gl_get_wglGenlockSourceI3D (void);
#define   gdk_gl_wglGenlockSourceI3D(proc, hDC, uSource) \
  (((PFNWGLGENLOCKSOURCEI3DPROC) (proc)) (hDC, uSource))

/* BOOL WINAPI wglGetGenlockSourceI3D (HDC, UINT *) */
GdkGLProc gdk_gl_get_wglGetGenlockSourceI3D (void);
#define   gdk_gl_wglGetGenlockSourceI3D(proc, hDC, uSource) \
  (((PFNWGLGETGENLOCKSOURCEI3DPROC) (proc)) (hDC, uSource))

/* BOOL WINAPI wglGenlockSourceEdgeI3D (HDC, UINT) */
GdkGLProc gdk_gl_get_wglGenlockSourceEdgeI3D (void);
#define   gdk_gl_wglGenlockSourceEdgeI3D(proc, hDC, uEdge) \
  (((PFNWGLGENLOCKSOURCEEDGEI3DPROC) (proc)) (hDC, uEdge))

/* BOOL WINAPI wglGetGenlockSourceEdgeI3D (HDC, UINT *) */
GdkGLProc gdk_gl_get_wglGetGenlockSourceEdgeI3D (void);
#define   gdk_gl_wglGetGenlockSourceEdgeI3D(proc, hDC, uEdge) \
  (((PFNWGLGETGENLOCKSOURCEEDGEI3DPROC) (proc)) (hDC, uEdge))

/* BOOL WINAPI wglGenlockSampleRateI3D (HDC, UINT) */
GdkGLProc gdk_gl_get_wglGenlockSampleRateI3D (void);
#define   gdk_gl_wglGenlockSampleRateI3D(proc, hDC, uRate) \
  (((PFNWGLGENLOCKSAMPLERATEI3DPROC) (proc)) (hDC, uRate))

/* BOOL WINAPI wglGetGenlockSampleRateI3D (HDC, UINT *) */
GdkGLProc gdk_gl_get_wglGetGenlockSampleRateI3D (void);
#define   gdk_gl_wglGetGenlockSampleRateI3D(proc, hDC, uRate) \
  (((PFNWGLGETGENLOCKSAMPLERATEI3DPROC) (proc)) (hDC, uRate))

/* BOOL WINAPI wglGenlockSourceDelayI3D (HDC, UINT) */
GdkGLProc gdk_gl_get_wglGenlockSourceDelayI3D (void);
#define   gdk_gl_wglGenlockSourceDelayI3D(proc, hDC, uDelay) \
  (((PFNWGLGENLOCKSOURCEDELAYI3DPROC) (proc)) (hDC, uDelay))

/* BOOL WINAPI wglGetGenlockSourceDelayI3D (HDC, UINT *) */
GdkGLProc gdk_gl_get_wglGetGenlockSourceDelayI3D (void);
#define   gdk_gl_wglGetGenlockSourceDelayI3D(proc, hDC, uDelay) \
  (((PFNWGLGETGENLOCKSOURCEDELAYI3DPROC) (proc)) (hDC, uDelay))

/* BOOL WINAPI wglQueryGenlockMaxSourceDelayI3D (HDC, UINT *, UINT *) */
GdkGLProc gdk_gl_get_wglQueryGenlockMaxSourceDelayI3D (void);
#define   gdk_gl_wglQueryGenlockMaxSourceDelayI3D(proc, hDC, uMaxLineDelay, uMaxPixelDelay) \
  (((PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (proc)) (hDC, uMaxLineDelay, uMaxPixelDelay))

/* 
 * WGL_I3D_image_buffer
 */

/* LPVOID WINAPI wglCreateImageBufferI3D (HDC, DWORD, UINT) */
GdkGLProc gdk_gl_get_wglCreateImageBufferI3D (void);
#define   gdk_gl_wglCreateImageBufferI3D(proc, hDC, dwSize, uFlags) \
  (((PFNWGLCREATEIMAGEBUFFERI3DPROC) (proc)) (hDC, dwSize, uFlags))

/* BOOL WINAPI wglDestroyImageBufferI3D (HDC, LPVOID) */
GdkGLProc gdk_gl_get_wglDestroyImageBufferI3D (void);
#define   gdk_gl_wglDestroyImageBufferI3D(proc, hDC, pAddress) \
  (((PFNWGLDESTROYIMAGEBUFFERI3DPROC) (proc)) (hDC, pAddress))

/* BOOL WINAPI wglAssociateImageBufferEventsI3D (HDC, const HANDLE *, const LPVOID *, const DWORD *, UINT) */
GdkGLProc gdk_gl_get_wglAssociateImageBufferEventsI3D (void);
#define   gdk_gl_wglAssociateImageBufferEventsI3D(proc, hDC, pEvent, pAddress, pSize, count) \
  (((PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (proc)) (hDC, pEvent, pAddress, pSize, count))

/* BOOL WINAPI wglReleaseImageBufferEventsI3D (HDC, const LPVOID *, UINT) */
GdkGLProc gdk_gl_get_wglReleaseImageBufferEventsI3D (void);
#define   gdk_gl_wglReleaseImageBufferEventsI3D(proc, hDC, pAddress, count) \
  (((PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (proc)) (hDC, pAddress, count))

/* 
 * WGL_I3D_swap_frame_lock
 */

/* BOOL WINAPI wglEnableFrameLockI3D (void) */
GdkGLProc gdk_gl_get_wglEnableFrameLockI3D (void);
#define   gdk_gl_wglEnableFrameLockI3D(proc) \
  (((PFNWGLENABLEFRAMELOCKI3DPROC) (proc)) ())

/* BOOL WINAPI wglDisableFrameLockI3D (void) */
GdkGLProc gdk_gl_get_wglDisableFrameLockI3D (void);
#define   gdk_gl_wglDisableFrameLockI3D(proc) \
  (((PFNWGLDISABLEFRAMELOCKI3DPROC) (proc)) ())

/* BOOL WINAPI wglIsEnabledFrameLockI3D (BOOL *) */
GdkGLProc gdk_gl_get_wglIsEnabledFrameLockI3D (void);
#define   gdk_gl_wglIsEnabledFrameLockI3D(proc, pFlag) \
  (((PFNWGLISENABLEDFRAMELOCKI3DPROC) (proc)) (pFlag))

/* BOOL WINAPI wglQueryFrameLockMasterI3D (BOOL *) */
GdkGLProc gdk_gl_get_wglQueryFrameLockMasterI3D (void);
#define   gdk_gl_wglQueryFrameLockMasterI3D(proc, pFlag) \
  (((PFNWGLQUERYFRAMELOCKMASTERI3DPROC) (proc)) (pFlag))

/* 
 * WGL_I3D_swap_frame_usage
 */

/* BOOL WINAPI wglGetFrameUsageI3D (float *) */
GdkGLProc gdk_gl_get_wglGetFrameUsageI3D (void);
#define   gdk_gl_wglGetFrameUsageI3D(proc, pUsage) \
  (((PFNWGLGETFRAMEUSAGEI3DPROC) (proc)) (pUsage))

/* BOOL WINAPI wglBeginFrameTrackingI3D (void) */
GdkGLProc gdk_gl_get_wglBeginFrameTrackingI3D (void);
#define   gdk_gl_wglBeginFrameTrackingI3D(proc) \
  (((PFNWGLBEGINFRAMETRACKINGI3DPROC) (proc)) ())

/* BOOL WINAPI wglEndFrameTrackingI3D (void) */
GdkGLProc gdk_gl_get_wglEndFrameTrackingI3D (void);
#define   gdk_gl_wglEndFrameTrackingI3D(proc) \
  (((PFNWGLENDFRAMETRACKINGI3DPROC) (proc)) ())

/* BOOL WINAPI wglQueryFrameTrackingI3D (DWORD *, DWORD *, float *) */
GdkGLProc gdk_gl_get_wglQueryFrameTrackingI3D (void);
#define   gdk_gl_wglQueryFrameTrackingI3D(proc, pFrameCount, pMissedFrames, pLastMissedUsage) \
  (((PFNWGLQUERYFRAMETRACKINGI3DPROC) (proc)) (pFrameCount, pMissedFrames, pLastMissedUsage))

G_END_DECLS

#endif /* __GDK_GL_WGLEXT_H__ */
