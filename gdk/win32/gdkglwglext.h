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

/* wglCreateBufferRegionARB */
GdkGLProc gdk_gl_get_wglCreateBufferRegionARB (void);
#define   gdk_gl_wglCreateBufferRegionARB(proc, hDC, iLayerPlane, uType) \
  (((PFNWGLCREATEBUFFERREGIONARBPROC) (proc)) (hDC, iLayerPlane, uType))

/* wglDeleteBufferRegionARB */
GdkGLProc gdk_gl_get_wglDeleteBufferRegionARB (void);
#define   gdk_gl_wglDeleteBufferRegionARB(proc, hRegion) \
  (((PFNWGLDELETEBUFFERREGIONARBPROC) (proc)) (hRegion))

/* wglSaveBufferRegionARB */
GdkGLProc gdk_gl_get_wglSaveBufferRegionARB (void);
#define   gdk_gl_wglSaveBufferRegionARB(proc, hRegion, x, y, width, height) \
  (((PFNWGLSAVEBUFFERREGIONARBPROC) (proc)) (hRegion, x, y, width, height))

/* wglRestoreBufferRegionARB */
GdkGLProc gdk_gl_get_wglRestoreBufferRegionARB (void);
#define   gdk_gl_wglRestoreBufferRegionARB(proc, hRegion, x, y, width, height, xSrc, ySrc) \
  (((PFNWGLRESTOREBUFFERREGIONARBPROC) (proc)) (hRegion, x, y, width, height, xSrc, ySrc))

/* 
 * WGL_ARB_extensions_string
 */

/* wglGetExtensionsStringARB */
GdkGLProc gdk_gl_get_wglGetExtensionsStringARB (void);
#define   gdk_gl_wglGetExtensionsStringARB(proc, hdc) \
  (((PFNWGLGETEXTENSIONSSTRINGARBPROC) (proc)) (hdc))

/* 
 * WGL_ARB_pixel_format
 */

/* wglGetPixelFormatAttribivARB */
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribivARB (void);
#define   gdk_gl_wglGetPixelFormatAttribivARB(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) \
  (((PFNWGLGETEXTENSIONSSTRINGARBPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues))

/* wglGetPixelFormatAttribfvARB */
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribfvARB (void);
#define   gdk_gl_wglGetPixelFormatAttribfvARB(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) \
  (((PFNWGLGETPIXELFORMATATTRIBFVARBPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues))

/* wglChoosePixelFormatARB */
GdkGLProc gdk_gl_get_wglChoosePixelFormatARB (void);
#define   gdk_gl_wglChoosePixelFormatARB(proc, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) \
  (((PFNWGLCHOOSEPIXELFORMATARBPROC) (proc)) (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats))

/* 
 * WGL_ARB_make_current_read
 */

/* wglMakeContextCurrentARB */
GdkGLProc gdk_gl_get_wglMakeContextCurrentARB (void);
#define   gdk_gl_wglMakeContextCurrentARB(proc, hDrawDC, hReadDC, hglrc) \
  (((PFNWGLMAKECONTEXTCURRENTARBPROC) (proc)) (hDrawDC, hReadDC, hglrc))

/* wglGetCurrentReadDCARB */
GdkGLProc gdk_gl_get_wglGetCurrentReadDCARB (void);
#define   gdk_gl_wglGetCurrentReadDCARB(proc) \
  (((PFNWGLGETCURRENTREADDCARBPROC) (proc)) ())

/* 
 * WGL_ARB_pbuffer
 */

/* wglCreatePbufferARB */
GdkGLProc gdk_gl_get_wglCreatePbufferARB (void);
#define   gdk_gl_wglCreatePbufferARB(proc, hDC, iPixelFormat, iWidth, iHeight, piAttribList) \
  (((PFNWGLCREATEPBUFFERARBPROC) (proc)) (hDC, iPixelFormat, iWidth, iHeight, piAttribList))

/* wglGetPbufferDCARB */
GdkGLProc gdk_gl_get_wglGetPbufferDCARB (void);
#define   gdk_gl_wglGetPbufferDCARB(proc, hPbuffer) \
  (((PFNWGLGETPBUFFERDCARBPROC) (proc)) (hPbuffer))

/* wglReleasePbufferDCARB */
GdkGLProc gdk_gl_get_wglReleasePbufferDCARB (void);
#define   gdk_gl_wglReleasePbufferDCARB(proc, hPbuffer, hDC) \
  (((PFNWGLRELEASEPBUFFERDCARBPROC) (proc)) (hPbuffer, hDC))

/* wglDestroyPbufferARB */
GdkGLProc gdk_gl_get_wglDestroyPbufferARB (void);
#define   gdk_gl_wglDestroyPbufferARB(proc, hPbuffer) \
  (((PFNWGLDESTROYPBUFFERARBPROC) (proc)) (hPbuffer))

/* wglQueryPbufferARB */
GdkGLProc gdk_gl_get_wglQueryPbufferARB (void);
#define   gdk_gl_wglQueryPbufferARB(proc, hPbuffer, iAttribute, piValue) \
  (((PFNWGLQUERYPBUFFERARBPROC) (proc)) (hPbuffer, iAttribute, piValue))

/* 
 * WGL_ARB_render_texture
 */

/* wglBindTexImageARB */
GdkGLProc gdk_gl_get_wglBindTexImageARB (void);
#define   gdk_gl_wglBindTexImageARB(proc, hPbuffer, iBuffer) \
  (((PFNWGLBINDTEXIMAGEARBPROC) (proc)) (hPbuffer, iBuffer))

/* wglReleaseTexImageARB */
GdkGLProc gdk_gl_get_wglReleaseTexImageARB (void);
#define   gdk_gl_wglReleaseTexImageARB(proc, hPbuffer, iBuffer) \
  (((PFNWGLRELEASETEXIMAGEARBPROC) (proc)) (hPbuffer, iBuffer))

/* wglSetPbufferAttribARB */
GdkGLProc gdk_gl_get_wglSetPbufferAttribARB (void);
#define   gdk_gl_wglSetPbufferAttribARB(proc, hPbuffer, piAttribList) \
  (((PFNWGLSETPBUFFERATTRIBARBPROC) (proc)) (hPbuffer, piAttribList))

/* 
 * WGL_EXT_display_color_table
 */

/* wglCreateDisplayColorTableEXT */
GdkGLProc gdk_gl_get_wglCreateDisplayColorTableEXT (void);
#define   gdk_gl_wglCreateDisplayColorTableEXT(proc, id) \
  (((PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* wglLoadDisplayColorTableEXT */
GdkGLProc gdk_gl_get_wglLoadDisplayColorTableEXT (void);
#define   gdk_gl_wglLoadDisplayColorTableEXT(proc, table, length) \
  (((PFNWGLLOADDISPLAYCOLORTABLEEXTPROC) (proc)) (table, length))

/* wglBindDisplayColorTableEXT */
GdkGLProc gdk_gl_get_wglBindDisplayColorTableEXT (void);
#define   gdk_gl_wglBindDisplayColorTableEXT(proc, id) \
  (((PFNWGLBINDDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* wglDestroyDisplayColorTableEXT */
GdkGLProc gdk_gl_get_wglDestroyDisplayColorTableEXT (void);
#define   gdk_gl_wglDestroyDisplayColorTableEXT(proc, id) \
  (((PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC) (proc)) (id))

/* 
 * WGL_EXT_extensions_string
 */

/* wglGetExtensionsStringEXT */
GdkGLProc gdk_gl_get_wglGetExtensionsStringEXT (void);
#define   gdk_gl_wglGetExtensionsStringEXT(proc) \
  (((PFNWGLGETEXTENSIONSSTRINGEXTPROC) (proc)) ())

/* 
 * WGL_EXT_make_current_read
 */

/* wglMakeContextCurrentEXT */
GdkGLProc gdk_gl_get_wglMakeContextCurrentEXT (void);
#define   gdk_gl_wglMakeContextCurrentEXT(proc, hDrawDC, hReadDC, hglrc) \
  (((PFNWGLMAKECONTEXTCURRENTEXTPROC) (proc)) (hDrawDC, hReadDC, hglrc))

/* wglGetCurrentReadDCEXT */
GdkGLProc gdk_gl_get_wglGetCurrentReadDCEXT (void);
#define   gdk_gl_wglGetCurrentReadDCEXT(proc) \
  (((PFNWGLGETCURRENTREADDCEXTPROC) (proc)) ())

/* 
 * WGL_EXT_pbuffer
 */

/* wglCreatePbufferEXT */
GdkGLProc gdk_gl_get_wglCreatePbufferEXT (void);
#define   gdk_gl_wglCreatePbufferEXT(proc, hDC, iPixelFormat, iWidth, iHeight, piAttribList) \
  (((PFNWGLCREATEPBUFFEREXTPROC) (proc)) (hDC, iPixelFormat, iWidth, iHeight, piAttribList))

/* wglGetPbufferDCEXT */
GdkGLProc gdk_gl_get_wglGetPbufferDCEXT (void);
#define   gdk_gl_wglGetPbufferDCEXT(proc, hPbuffer) \
  (((PFNWGLGETPBUFFERDCEXTPROC) (proc)) (hPbuffer))

/* wglReleasePbufferDCEXT */
GdkGLProc gdk_gl_get_wglReleasePbufferDCEXT (void);
#define   gdk_gl_wglReleasePbufferDCEXT(proc, hPbuffer, hDC) \
  (((PFNWGLRELEASEPBUFFERDCEXTPROC) (proc)) (hPbuffer, hDC))

/* wglDestroyPbufferEXT */
GdkGLProc gdk_gl_get_wglDestroyPbufferEXT (void);
#define   gdk_gl_wglDestroyPbufferEXT(proc, hPbuffer) \
  (((PFNWGLDESTROYPBUFFEREXTPROC) (proc)) (hPbuffer))

/* wglQueryPbufferEXT */
GdkGLProc gdk_gl_get_wglQueryPbufferEXT (void);
#define   gdk_gl_wglQueryPbufferEXT(proc, hPbuffer, iAttribute, piValue) \
  (((PFNWGLQUERYPBUFFEREXTPROC) (proc)) (hPbuffer, iAttribute, piValue))

/* 
 * WGL_EXT_pixel_format
 */

/* wglGetPixelFormatAttribivEXT */
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribivEXT (void);
#define   gdk_gl_wglGetPixelFormatAttribivEXT(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) \
  (((PFNWGLGETPIXELFORMATATTRIBIVEXTPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues))

/* wglGetPixelFormatAttribfvEXT */
GdkGLProc gdk_gl_get_wglGetPixelFormatAttribfvEXT (void);
#define   gdk_gl_wglGetPixelFormatAttribfvEXT(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) \
  (((PFNWGLGETPIXELFORMATATTRIBFVEXTPROC) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues))

/* wglChoosePixelFormatEXT */
GdkGLProc gdk_gl_get_wglChoosePixelFormatEXT (void);
#define   gdk_gl_wglChoosePixelFormatEXT(proc, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) \
  (((PFNWGLCHOOSEPIXELFORMATEXTPROC) (proc)) (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats))

/* 
 * WGL_EXT_swap_control
 */

/* wglSwapIntervalEXT */
GdkGLProc gdk_gl_get_wglSwapIntervalEXT (void);
#define   gdk_gl_wglSwapIntervalEXT(proc, interval) \
  (((PFNWGLSWAPINTERVALEXTPROC) (proc)) (interval))

/* wglGetSwapIntervalEXT */
GdkGLProc gdk_gl_get_wglGetSwapIntervalEXT (void);
#define   gdk_gl_wglGetSwapIntervalEXT(proc) \
  (((PFNWGLGETSWAPINTERVALEXTPROC) (proc)) ())

/* 
 * WGL_NV_vertex_array_range
 */

/* wglAllocateMemoryNV */
GdkGLProc gdk_gl_get_wglAllocateMemoryNV (void);
#define   gdk_gl_wglAllocateMemoryNV(proc, size, readfreq, writefreq, priority) \
  (((PFNWGLALLOCATEMEMORYNVPROC) (proc)) (size, readfreq, writefreq, priority))

/* wglFreeMemoryNV */
GdkGLProc gdk_gl_get_wglFreeMemoryNV (void);
#define   gdk_gl_wglFreeMemoryNV(proc, pointer) \
  (((PFNWGLFREEMEMORYNVPROC) (proc)) (pointer))

/* 
 * WGL_OML_sync_control
 */

/* wglGetSyncValuesOML */
GdkGLProc gdk_gl_get_wglGetSyncValuesOML (void);
#define   gdk_gl_wglGetSyncValuesOML(proc, hdc, ust, msc, sbc) \
  (((PFNWGLGETSYNCVALUESOMLPROC) (proc)) (hdc, ust, msc, sbc))

/* wglGetMscRateOML */
GdkGLProc gdk_gl_get_wglGetMscRateOML (void);
#define   gdk_gl_wglGetMscRateOML(proc, hdc, numerator, denominator) \
  (((PFNWGLGETMSCRATEOMLPROC) (proc)) (hdc, numerator, denominator))

/* wglSwapBuffersMscOML */
GdkGLProc gdk_gl_get_wglSwapBuffersMscOML (void);
#define   gdk_gl_wglSwapBuffersMscOML(proc, hdc, target_msc, divisor, remainder) \
  (((PFNWGLSWAPBUFFERSMSCOMLPROC) (proc)) (hdc, target_msc, divisor, remainder))

/* wglSwapLayerBuffersMscOML */
GdkGLProc gdk_gl_get_wglSwapLayerBuffersMscOML (void);
#define   gdk_gl_wglSwapLayerBuffersMscOML(proc, hdc, fuPlanes, target_msc, divisor, remainder) \
  (((PFNWGLSWAPLAYERBUFFERSMSCOMLPROC) (proc)) (hdc, fuPlanes, target_msc, divisor, remainder))

/* wglWaitForMscOML */
GdkGLProc gdk_gl_get_wglWaitForMscOML (void);
#define   gdk_gl_wglWaitForMscOML(proc, hdc, target_msc, divisor, remainder, ust, msc, sbc) \
  (((PFNWGLWAITFORMSCOMLPROC) (proc)) (hdc, target_msc, divisor, remainder, ust, msc, sbc))

/* wglWaitForSbcOML */
GdkGLProc gdk_gl_get_wglWaitForSbcOML (void);
#define   gdk_gl_wglWaitForSbcOML(proc, hdc, target_sbc, ust, msc, sbc) \
  (((PFNWGLWAITFORSBCOMLPROC) (proc)) (hdc, target_sbc, ust, msc, sbc))

/* 
 * WGL_I3D_digital_video_control
 */

/* wglGetDigitalVideoParametersI3D */
GdkGLProc gdk_gl_get_wglGetDigitalVideoParametersI3D (void);
#define   gdk_gl_wglGetDigitalVideoParametersI3D(proc, hDC, iAttribute, piValue) \
  (((PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* wglSetDigitalVideoParametersI3D */
GdkGLProc gdk_gl_get_wglSetDigitalVideoParametersI3D (void);
#define   gdk_gl_wglSetDigitalVideoParametersI3D(proc, hDC, iAttribute, piValue) \
  (((PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* 
 * WGL_I3D_gamma
 */

/* wglGetGammaTableParametersI3D */
GdkGLProc gdk_gl_get_wglGetGammaTableParametersI3D (void);
#define   gdk_gl_wglGetGammaTableParametersI3D(proc, hDC, iAttribute, piValue) \
  (((PFNWGLGETGAMMATABLEPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* wglSetGammaTableParametersI3D */
GdkGLProc gdk_gl_get_wglSetGammaTableParametersI3D (void);
#define   gdk_gl_wglSetGammaTableParametersI3D(proc, hDC, iAttribute, piValue) \
  (((PFNWGLSETGAMMATABLEPARAMETERSI3DPROC) (proc)) (hDC, iAttribute, piValue))

/* wglGetGammaTableI3D */
GdkGLProc gdk_gl_get_wglGetGammaTableI3D (void);
#define   gdk_gl_wglGetGammaTableI3D(proc, hDC, iEntries, puRed, puGreen, puBlue) \
  (((PFNWGLGETGAMMATABLEI3DPROC) (proc)) (hDC, iEntries, puRed, puGreen, puBlue))

/* wglSetGammaTableI3D */
GdkGLProc gdk_gl_get_wglSetGammaTableI3D (void);
#define   gdk_gl_wglSetGammaTableI3D(proc, hDC, iEntries, puRed, puGreen, puBlue) \
  (((PFNWGLSETGAMMATABLEI3DPROC) (proc)) (hDC, iEntries, puRed, puGreen, puBlue))

/* 
 * WGL_I3D_genlock
 */

/* wglEnableGenlockI3D */
GdkGLProc gdk_gl_get_wglEnableGenlockI3D (void);
#define   gdk_gl_wglEnableGenlockI3D(proc, hDC) \
  (((PFNWGLENABLEGENLOCKI3DPROC) (proc)) (hDC))

/* wglDisableGenlockI3D */
GdkGLProc gdk_gl_get_wglDisableGenlockI3D (void);
#define   gdk_gl_wglDisableGenlockI3D(proc, hDC) \
  (((PFNWGLDISABLEGENLOCKI3DPROC) (proc)) (hDC))

/* wglIsEnabledGenlockI3D */
GdkGLProc gdk_gl_get_wglIsEnabledGenlockI3D (void);
#define   gdk_gl_wglIsEnabledGenlockI3D(proc, hDC, pFlag) \
  (((PFNWGLISENABLEDGENLOCKI3DPROC) (proc)) (hDC, pFlag))

/* wglGenlockSourceI3D */
GdkGLProc gdk_gl_get_wglGenlockSourceI3D (void);
#define   gdk_gl_wglGenlockSourceI3D(proc, hDC, uSource) \
  (((PFNWGLGENLOCKSOURCEI3DPROC) (proc)) (hDC, uSource))

/* wglGetGenlockSourceI3D */
GdkGLProc gdk_gl_get_wglGetGenlockSourceI3D (void);
#define   gdk_gl_wglGetGenlockSourceI3D(proc, hDC, uSource) \
  (((PFNWGLGETGENLOCKSOURCEI3DPROC) (proc)) (hDC, uSource))

/* wglGenlockSourceEdgeI3D */
GdkGLProc gdk_gl_get_wglGenlockSourceEdgeI3D (void);
#define   gdk_gl_wglGenlockSourceEdgeI3D(proc, hDC, uEdge) \
  (((PFNWGLGENLOCKSOURCEEDGEI3DPROC) (proc)) (hDC, uEdge))

/* wglGetGenlockSourceEdgeI3D */
GdkGLProc gdk_gl_get_wglGetGenlockSourceEdgeI3D (void);
#define   gdk_gl_wglGetGenlockSourceEdgeI3D(proc, hDC, uEdge) \
  (((PFNWGLGETGENLOCKSOURCEEDGEI3DPROC) (proc)) (hDC, uEdge))

/* wglGenlockSampleRateI3D */
GdkGLProc gdk_gl_get_wglGenlockSampleRateI3D (void);
#define   gdk_gl_wglGenlockSampleRateI3D(proc, hDC, uRate) \
  (((PFNWGLGENLOCKSAMPLERATEI3DPROC) (proc)) (hDC, uRate))

/* wglGetGenlockSampleRateI3D */
GdkGLProc gdk_gl_get_wglGetGenlockSampleRateI3D (void);
#define   gdk_gl_wglGetGenlockSampleRateI3D(proc, hDC, uRate) \
  (((PFNWGLGETGENLOCKSAMPLERATEI3DPROC) (proc)) (hDC, uRate))

/* wglGenlockSourceDelayI3D */
GdkGLProc gdk_gl_get_wglGenlockSourceDelayI3D (void);
#define   gdk_gl_wglGenlockSourceDelayI3D(proc, hDC, uDelay) \
  (((PFNWGLGENLOCKSOURCEDELAYI3DPROC) (proc)) (hDC, uDelay))

/* wglGetGenlockSourceDelayI3D */
GdkGLProc gdk_gl_get_wglGetGenlockSourceDelayI3D (void);
#define   gdk_gl_wglGetGenlockSourceDelayI3D(proc, hDC, uDelay) \
  (((PFNWGLGETGENLOCKSOURCEDELAYI3DPROC) (proc)) (hDC, uDelay))

/* wglQueryGenlockMaxSourceDelayI3D */
GdkGLProc gdk_gl_get_wglQueryGenlockMaxSourceDelayI3D (void);
#define   gdk_gl_wglQueryGenlockMaxSourceDelayI3D(proc, hDC, uMaxLineDelay, uMaxPixelDelay) \
  (((PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC) (proc)) (hDC, uMaxLineDelay, uMaxPixelDelay))

/* 
 * WGL_I3D_image_buffer
 */

/* wglCreateImageBufferI3D */
GdkGLProc gdk_gl_get_wglCreateImageBufferI3D (void);
#define   gdk_gl_wglCreateImageBufferI3D(proc, hDC, dwSize, uFlags) \
  (((PFNWGLCREATEIMAGEBUFFERI3DPROC) (proc)) (hDC, dwSize, uFlags))

/* wglDestroyImageBufferI3D */
GdkGLProc gdk_gl_get_wglDestroyImageBufferI3D (void);
#define   gdk_gl_wglDestroyImageBufferI3D(proc, hDC, pAddress) \
  (((PFNWGLDESTROYIMAGEBUFFERI3DPROC) (proc)) (hDC, pAddress))

/* wglAssociateImageBufferEventsI3D */
GdkGLProc gdk_gl_get_wglAssociateImageBufferEventsI3D (void);
#define   gdk_gl_wglAssociateImageBufferEventsI3D(proc, hDC, pEvent, pAddress, pSize, count) \
  (((PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC) (proc)) (hDC, pEvent, pAddress, pSize, count))

/* wglReleaseImageBufferEventsI3D */
GdkGLProc gdk_gl_get_wglReleaseImageBufferEventsI3D (void);
#define   gdk_gl_wglReleaseImageBufferEventsI3D(proc, hDC, pAddress, count) \
  (((PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC) (proc)) (hDC, pAddress, count))

/* 
 * WGL_I3D_swap_frame_lock
 */

/* wglEnableFrameLockI3D */
GdkGLProc gdk_gl_get_wglEnableFrameLockI3D (void);
#define   gdk_gl_wglEnableFrameLockI3D(proc) \
  (((PFNWGLENABLEFRAMELOCKI3DPROC) (proc)) ())

/* wglDisableFrameLockI3D */
GdkGLProc gdk_gl_get_wglDisableFrameLockI3D (void);
#define   gdk_gl_wglDisableFrameLockI3D(proc) \
  (((PFNWGLDISABLEFRAMELOCKI3DPROC) (proc)) ())

/* wglIsEnabledFrameLockI3D */
GdkGLProc gdk_gl_get_wglIsEnabledFrameLockI3D (void);
#define   gdk_gl_wglIsEnabledFrameLockI3D(proc, pFlag) \
  (((PFNWGLISENABLEDFRAMELOCKI3DPROC) (proc)) (pFlag))

/* wglQueryFrameLockMasterI3D */
GdkGLProc gdk_gl_get_wglQueryFrameLockMasterI3D (void);
#define   gdk_gl_wglQueryFrameLockMasterI3D(proc, pFlag) \
  (((PFNWGLQUERYFRAMELOCKMASTERI3DPROC) (proc)) (pFlag))

/* 
 * WGL_I3D_swap_frame_usage
 */

/* wglGetFrameUsageI3D */
GdkGLProc gdk_gl_get_wglGetFrameUsageI3D (void);
#define   gdk_gl_wglGetFrameUsageI3D(proc, pUsage) \
  (((PFNWGLGETFRAMEUSAGEI3DPROC) (proc)) (pUsage))

/* wglBeginFrameTrackingI3D */
GdkGLProc gdk_gl_get_wglBeginFrameTrackingI3D (void);
#define   gdk_gl_wglBeginFrameTrackingI3D(proc) \
  (((PFNWGLBEGINFRAMETRACKINGI3DPROC) (proc)) ())

/* wglEndFrameTrackingI3D */
GdkGLProc gdk_gl_get_wglEndFrameTrackingI3D (void);
#define   gdk_gl_wglEndFrameTrackingI3D(proc) \
  (((PFNWGLENDFRAMETRACKINGI3DPROC) (proc)) ())

/* wglQueryFrameTrackingI3D */
GdkGLProc gdk_gl_get_wglQueryFrameTrackingI3D (void);
#define   gdk_gl_wglQueryFrameTrackingI3D(proc, pFrameCount, pMissedFrames, pLastMissedUsage) \
  (((PFNWGLQUERYFRAMETRACKINGI3DPROC) (proc)) (pFrameCount, pMissedFrames, pLastMissedUsage))

G_END_DECLS

#endif /* __GDK_GL_WGLEXT_H__ */
