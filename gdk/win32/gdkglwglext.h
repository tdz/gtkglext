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

/*
 * This is a generated file.  Please modify "gen-gdkglwglext-h.pl".
 */

#ifndef __GDK_GL_WGLEXT_H__
#define __GDK_GL_WGLEXT_H__

#include <glib.h>

#ifdef G_OS_WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#include <GL/gl.h>

#include <gdk/gdkgldefs.h>
#include <gdk/gdkglquery.h>
#include <gdk/gdkglconfig.h>

#undef __wglext_h_
#undef WGL_WGLEXT_VERSION
#include <gdk/glext/wglext.h>
#include <gdk/glext/wglext-extra.h>

G_BEGIN_DECLS

/*
 * WGL_ARB_buffer_region
 */

/* wglCreateBufferRegionARB */
typedef HANDLE (WINAPI * GdkGLProc_wglCreateBufferRegionARB) (HDC hDC, int iLayerPlane, UINT uType);
GdkGLProc    gdk_gl_get_wglCreateBufferRegionARB (void);
#define      gdk_gl_wglCreateBufferRegionARB(proc, hDC, iLayerPlane, uType) \
  ( ((GdkGLProc_wglCreateBufferRegionARB) (proc)) (hDC, iLayerPlane, uType) )

/* wglDeleteBufferRegionARB */
typedef VOID (WINAPI * GdkGLProc_wglDeleteBufferRegionARB) (HANDLE hRegion);
GdkGLProc    gdk_gl_get_wglDeleteBufferRegionARB (void);
#define      gdk_gl_wglDeleteBufferRegionARB(proc, hRegion) \
  ( ((GdkGLProc_wglDeleteBufferRegionARB) (proc)) (hRegion) )

/* wglSaveBufferRegionARB */
typedef BOOL (WINAPI * GdkGLProc_wglSaveBufferRegionARB) (HANDLE hRegion, int x, int y, int width, int height);
GdkGLProc    gdk_gl_get_wglSaveBufferRegionARB (void);
#define      gdk_gl_wglSaveBufferRegionARB(proc, hRegion, x, y, width, height) \
  ( ((GdkGLProc_wglSaveBufferRegionARB) (proc)) (hRegion, x, y, width, height) )

/* wglRestoreBufferRegionARB */
typedef BOOL (WINAPI * GdkGLProc_wglRestoreBufferRegionARB) (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
GdkGLProc    gdk_gl_get_wglRestoreBufferRegionARB (void);
#define      gdk_gl_wglRestoreBufferRegionARB(proc, hRegion, x, y, width, height, xSrc, ySrc) \
  ( ((GdkGLProc_wglRestoreBufferRegionARB) (proc)) (hRegion, x, y, width, height, xSrc, ySrc) )

/* proc struct */

typedef struct _GdkGL_WGL_ARB_buffer_region GdkGL_WGL_ARB_buffer_region;

struct _GdkGL_WGL_ARB_buffer_region
{
  GdkGLProc_wglCreateBufferRegionARB wglCreateBufferRegionARB;
  GdkGLProc_wglDeleteBufferRegionARB wglDeleteBufferRegionARB;
  GdkGLProc_wglSaveBufferRegionARB wglSaveBufferRegionARB;
  GdkGLProc_wglRestoreBufferRegionARB wglRestoreBufferRegionARB;
};

GdkGL_WGL_ARB_buffer_region *gdk_gl_get_WGL_ARB_buffer_region (GdkGLConfig *glconfig);

/*
 * WGL_ARB_extensions_string
 */

/* wglGetExtensionsStringARB */
typedef const char * (WINAPI * GdkGLProc_wglGetExtensionsStringARB) (HDC hdc);
GdkGLProc    gdk_gl_get_wglGetExtensionsStringARB (void);
#define      gdk_gl_wglGetExtensionsStringARB(proc, hdc) \
  ( ((GdkGLProc_wglGetExtensionsStringARB) (proc)) (hdc) )

/* proc struct */

typedef struct _GdkGL_WGL_ARB_extensions_string GdkGL_WGL_ARB_extensions_string;

struct _GdkGL_WGL_ARB_extensions_string
{
  GdkGLProc_wglGetExtensionsStringARB wglGetExtensionsStringARB;
};

GdkGL_WGL_ARB_extensions_string *gdk_gl_get_WGL_ARB_extensions_string (GdkGLConfig *glconfig);

/*
 * WGL_ARB_pixel_format
 */

/* wglGetPixelFormatAttribivARB */
typedef BOOL (WINAPI * GdkGLProc_wglGetPixelFormatAttribivARB) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
GdkGLProc    gdk_gl_get_wglGetPixelFormatAttribivARB (void);
#define      gdk_gl_wglGetPixelFormatAttribivARB(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) \
  ( ((GdkGLProc_wglGetPixelFormatAttribivARB) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) )

/* wglGetPixelFormatAttribfvARB */
typedef BOOL (WINAPI * GdkGLProc_wglGetPixelFormatAttribfvARB) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
GdkGLProc    gdk_gl_get_wglGetPixelFormatAttribfvARB (void);
#define      gdk_gl_wglGetPixelFormatAttribfvARB(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) \
  ( ((GdkGLProc_wglGetPixelFormatAttribfvARB) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) )

/* wglChoosePixelFormatARB */
typedef BOOL (WINAPI * GdkGLProc_wglChoosePixelFormatARB) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
GdkGLProc    gdk_gl_get_wglChoosePixelFormatARB (void);
#define      gdk_gl_wglChoosePixelFormatARB(proc, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) \
  ( ((GdkGLProc_wglChoosePixelFormatARB) (proc)) (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) )

/* proc struct */

typedef struct _GdkGL_WGL_ARB_pixel_format GdkGL_WGL_ARB_pixel_format;

struct _GdkGL_WGL_ARB_pixel_format
{
  GdkGLProc_wglGetPixelFormatAttribivARB wglGetPixelFormatAttribivARB;
  GdkGLProc_wglGetPixelFormatAttribfvARB wglGetPixelFormatAttribfvARB;
  GdkGLProc_wglChoosePixelFormatARB wglChoosePixelFormatARB;
};

GdkGL_WGL_ARB_pixel_format *gdk_gl_get_WGL_ARB_pixel_format (GdkGLConfig *glconfig);

/*
 * WGL_ARB_make_current_read
 */

/* wglMakeContextCurrentARB */
typedef BOOL (WINAPI * GdkGLProc_wglMakeContextCurrentARB) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
GdkGLProc    gdk_gl_get_wglMakeContextCurrentARB (void);
#define      gdk_gl_wglMakeContextCurrentARB(proc, hDrawDC, hReadDC, hglrc) \
  ( ((GdkGLProc_wglMakeContextCurrentARB) (proc)) (hDrawDC, hReadDC, hglrc) )

/* wglGetCurrentReadDCARB */
typedef HDC (WINAPI * GdkGLProc_wglGetCurrentReadDCARB) (void);
GdkGLProc    gdk_gl_get_wglGetCurrentReadDCARB (void);
#define      gdk_gl_wglGetCurrentReadDCARB(proc) \
  ( ((GdkGLProc_wglGetCurrentReadDCARB) (proc)) () )

/* proc struct */

typedef struct _GdkGL_WGL_ARB_make_current_read GdkGL_WGL_ARB_make_current_read;

struct _GdkGL_WGL_ARB_make_current_read
{
  GdkGLProc_wglMakeContextCurrentARB wglMakeContextCurrentARB;
  GdkGLProc_wglGetCurrentReadDCARB wglGetCurrentReadDCARB;
};

GdkGL_WGL_ARB_make_current_read *gdk_gl_get_WGL_ARB_make_current_read (GdkGLConfig *glconfig);

/*
 * WGL_ARB_pbuffer
 */

/* wglCreatePbufferARB */
typedef HPBUFFERARB (WINAPI * GdkGLProc_wglCreatePbufferARB) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
GdkGLProc    gdk_gl_get_wglCreatePbufferARB (void);
#define      gdk_gl_wglCreatePbufferARB(proc, hDC, iPixelFormat, iWidth, iHeight, piAttribList) \
  ( ((GdkGLProc_wglCreatePbufferARB) (proc)) (hDC, iPixelFormat, iWidth, iHeight, piAttribList) )

/* wglGetPbufferDCARB */
typedef HDC (WINAPI * GdkGLProc_wglGetPbufferDCARB) (HPBUFFERARB hPbuffer);
GdkGLProc    gdk_gl_get_wglGetPbufferDCARB (void);
#define      gdk_gl_wglGetPbufferDCARB(proc, hPbuffer) \
  ( ((GdkGLProc_wglGetPbufferDCARB) (proc)) (hPbuffer) )

/* wglReleasePbufferDCARB */
typedef int (WINAPI * GdkGLProc_wglReleasePbufferDCARB) (HPBUFFERARB hPbuffer, HDC hDC);
GdkGLProc    gdk_gl_get_wglReleasePbufferDCARB (void);
#define      gdk_gl_wglReleasePbufferDCARB(proc, hPbuffer, hDC) \
  ( ((GdkGLProc_wglReleasePbufferDCARB) (proc)) (hPbuffer, hDC) )

/* wglDestroyPbufferARB */
typedef BOOL (WINAPI * GdkGLProc_wglDestroyPbufferARB) (HPBUFFERARB hPbuffer);
GdkGLProc    gdk_gl_get_wglDestroyPbufferARB (void);
#define      gdk_gl_wglDestroyPbufferARB(proc, hPbuffer) \
  ( ((GdkGLProc_wglDestroyPbufferARB) (proc)) (hPbuffer) )

/* wglQueryPbufferARB */
typedef BOOL (WINAPI * GdkGLProc_wglQueryPbufferARB) (HPBUFFERARB hPbuffer, int iAttribute, int *piValue);
GdkGLProc    gdk_gl_get_wglQueryPbufferARB (void);
#define      gdk_gl_wglQueryPbufferARB(proc, hPbuffer, iAttribute, piValue) \
  ( ((GdkGLProc_wglQueryPbufferARB) (proc)) (hPbuffer, iAttribute, piValue) )

/* proc struct */

typedef struct _GdkGL_WGL_ARB_pbuffer GdkGL_WGL_ARB_pbuffer;

struct _GdkGL_WGL_ARB_pbuffer
{
  GdkGLProc_wglCreatePbufferARB wglCreatePbufferARB;
  GdkGLProc_wglGetPbufferDCARB wglGetPbufferDCARB;
  GdkGLProc_wglReleasePbufferDCARB wglReleasePbufferDCARB;
  GdkGLProc_wglDestroyPbufferARB wglDestroyPbufferARB;
  GdkGLProc_wglQueryPbufferARB wglQueryPbufferARB;
};

GdkGL_WGL_ARB_pbuffer *gdk_gl_get_WGL_ARB_pbuffer (GdkGLConfig *glconfig);

/*
 * WGL_ARB_render_texture
 */

/* wglBindTexImageARB */
typedef BOOL (WINAPI * GdkGLProc_wglBindTexImageARB) (HPBUFFERARB hPbuffer, int iBuffer);
GdkGLProc    gdk_gl_get_wglBindTexImageARB (void);
#define      gdk_gl_wglBindTexImageARB(proc, hPbuffer, iBuffer) \
  ( ((GdkGLProc_wglBindTexImageARB) (proc)) (hPbuffer, iBuffer) )

/* wglReleaseTexImageARB */
typedef BOOL (WINAPI * GdkGLProc_wglReleaseTexImageARB) (HPBUFFERARB hPbuffer, int iBuffer);
GdkGLProc    gdk_gl_get_wglReleaseTexImageARB (void);
#define      gdk_gl_wglReleaseTexImageARB(proc, hPbuffer, iBuffer) \
  ( ((GdkGLProc_wglReleaseTexImageARB) (proc)) (hPbuffer, iBuffer) )

/* wglSetPbufferAttribARB */
typedef BOOL (WINAPI * GdkGLProc_wglSetPbufferAttribARB) (HPBUFFERARB hPbuffer, const int *piAttribList);
GdkGLProc    gdk_gl_get_wglSetPbufferAttribARB (void);
#define      gdk_gl_wglSetPbufferAttribARB(proc, hPbuffer, piAttribList) \
  ( ((GdkGLProc_wglSetPbufferAttribARB) (proc)) (hPbuffer, piAttribList) )

/* proc struct */

typedef struct _GdkGL_WGL_ARB_render_texture GdkGL_WGL_ARB_render_texture;

struct _GdkGL_WGL_ARB_render_texture
{
  GdkGLProc_wglBindTexImageARB wglBindTexImageARB;
  GdkGLProc_wglReleaseTexImageARB wglReleaseTexImageARB;
  GdkGLProc_wglSetPbufferAttribARB wglSetPbufferAttribARB;
};

GdkGL_WGL_ARB_render_texture *gdk_gl_get_WGL_ARB_render_texture (GdkGLConfig *glconfig);

/*
 * WGL_ARB_create_context
 */

/* wglCreateContextAttribsARB */
typedef HGLRC (WINAPI * GdkGLProc_wglCreateContextAttribsARB) (HDC hDC, HGLRC hShareContext, const int *attribList);
GdkGLProc    gdk_gl_get_wglCreateContextAttribsARB (void);
#define      gdk_gl_wglCreateContextAttribsARB(proc, hDC, hShareContext, attribList) \
  ( ((GdkGLProc_wglCreateContextAttribsARB) (proc)) (hDC, hShareContext, attribList) )

/* proc struct */

typedef struct _GdkGL_WGL_ARB_create_context GdkGL_WGL_ARB_create_context;

struct _GdkGL_WGL_ARB_create_context
{
  GdkGLProc_wglCreateContextAttribsARB wglCreateContextAttribsARB;
};

GdkGL_WGL_ARB_create_context *gdk_gl_get_WGL_ARB_create_context (GdkGLConfig *glconfig);

/*
 * WGL_EXT_display_color_table
 */

/* wglCreateDisplayColorTableEXT */
typedef GLboolean (WINAPI * GdkGLProc_wglCreateDisplayColorTableEXT) (GLushort id);
GdkGLProc    gdk_gl_get_wglCreateDisplayColorTableEXT (void);
#define      gdk_gl_wglCreateDisplayColorTableEXT(proc, id) \
  ( ((GdkGLProc_wglCreateDisplayColorTableEXT) (proc)) (id) )

/* wglLoadDisplayColorTableEXT */
typedef GLboolean (WINAPI * GdkGLProc_wglLoadDisplayColorTableEXT) (const GLushort *table, GLuint length);
GdkGLProc    gdk_gl_get_wglLoadDisplayColorTableEXT (void);
#define      gdk_gl_wglLoadDisplayColorTableEXT(proc, table, length) \
  ( ((GdkGLProc_wglLoadDisplayColorTableEXT) (proc)) (table, length) )

/* wglBindDisplayColorTableEXT */
typedef GLboolean (WINAPI * GdkGLProc_wglBindDisplayColorTableEXT) (GLushort id);
GdkGLProc    gdk_gl_get_wglBindDisplayColorTableEXT (void);
#define      gdk_gl_wglBindDisplayColorTableEXT(proc, id) \
  ( ((GdkGLProc_wglBindDisplayColorTableEXT) (proc)) (id) )

/* wglDestroyDisplayColorTableEXT */
typedef VOID (WINAPI * GdkGLProc_wglDestroyDisplayColorTableEXT) (GLushort id);
GdkGLProc    gdk_gl_get_wglDestroyDisplayColorTableEXT (void);
#define      gdk_gl_wglDestroyDisplayColorTableEXT(proc, id) \
  ( ((GdkGLProc_wglDestroyDisplayColorTableEXT) (proc)) (id) )

/* proc struct */

typedef struct _GdkGL_WGL_EXT_display_color_table GdkGL_WGL_EXT_display_color_table;

struct _GdkGL_WGL_EXT_display_color_table
{
  GdkGLProc_wglCreateDisplayColorTableEXT wglCreateDisplayColorTableEXT;
  GdkGLProc_wglLoadDisplayColorTableEXT wglLoadDisplayColorTableEXT;
  GdkGLProc_wglBindDisplayColorTableEXT wglBindDisplayColorTableEXT;
  GdkGLProc_wglDestroyDisplayColorTableEXT wglDestroyDisplayColorTableEXT;
};

GdkGL_WGL_EXT_display_color_table *gdk_gl_get_WGL_EXT_display_color_table (GdkGLConfig *glconfig);

/*
 * WGL_EXT_extensions_string
 */

/* wglGetExtensionsStringEXT */
typedef const char * (WINAPI * GdkGLProc_wglGetExtensionsStringEXT) (void);
GdkGLProc    gdk_gl_get_wglGetExtensionsStringEXT (void);
#define      gdk_gl_wglGetExtensionsStringEXT(proc) \
  ( ((GdkGLProc_wglGetExtensionsStringEXT) (proc)) () )

/* proc struct */

typedef struct _GdkGL_WGL_EXT_extensions_string GdkGL_WGL_EXT_extensions_string;

struct _GdkGL_WGL_EXT_extensions_string
{
  GdkGLProc_wglGetExtensionsStringEXT wglGetExtensionsStringEXT;
};

GdkGL_WGL_EXT_extensions_string *gdk_gl_get_WGL_EXT_extensions_string (GdkGLConfig *glconfig);

/*
 * WGL_EXT_make_current_read
 */

/* wglMakeContextCurrentEXT */
typedef BOOL (WINAPI * GdkGLProc_wglMakeContextCurrentEXT) (HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
GdkGLProc    gdk_gl_get_wglMakeContextCurrentEXT (void);
#define      gdk_gl_wglMakeContextCurrentEXT(proc, hDrawDC, hReadDC, hglrc) \
  ( ((GdkGLProc_wglMakeContextCurrentEXT) (proc)) (hDrawDC, hReadDC, hglrc) )

/* wglGetCurrentReadDCEXT */
typedef HDC (WINAPI * GdkGLProc_wglGetCurrentReadDCEXT) (void);
GdkGLProc    gdk_gl_get_wglGetCurrentReadDCEXT (void);
#define      gdk_gl_wglGetCurrentReadDCEXT(proc) \
  ( ((GdkGLProc_wglGetCurrentReadDCEXT) (proc)) () )

/* proc struct */

typedef struct _GdkGL_WGL_EXT_make_current_read GdkGL_WGL_EXT_make_current_read;

struct _GdkGL_WGL_EXT_make_current_read
{
  GdkGLProc_wglMakeContextCurrentEXT wglMakeContextCurrentEXT;
  GdkGLProc_wglGetCurrentReadDCEXT wglGetCurrentReadDCEXT;
};

GdkGL_WGL_EXT_make_current_read *gdk_gl_get_WGL_EXT_make_current_read (GdkGLConfig *glconfig);

/*
 * WGL_EXT_pbuffer
 */

/* wglCreatePbufferEXT */
typedef HPBUFFEREXT (WINAPI * GdkGLProc_wglCreatePbufferEXT) (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
GdkGLProc    gdk_gl_get_wglCreatePbufferEXT (void);
#define      gdk_gl_wglCreatePbufferEXT(proc, hDC, iPixelFormat, iWidth, iHeight, piAttribList) \
  ( ((GdkGLProc_wglCreatePbufferEXT) (proc)) (hDC, iPixelFormat, iWidth, iHeight, piAttribList) )

/* wglGetPbufferDCEXT */
typedef HDC (WINAPI * GdkGLProc_wglGetPbufferDCEXT) (HPBUFFEREXT hPbuffer);
GdkGLProc    gdk_gl_get_wglGetPbufferDCEXT (void);
#define      gdk_gl_wglGetPbufferDCEXT(proc, hPbuffer) \
  ( ((GdkGLProc_wglGetPbufferDCEXT) (proc)) (hPbuffer) )

/* wglReleasePbufferDCEXT */
typedef int (WINAPI * GdkGLProc_wglReleasePbufferDCEXT) (HPBUFFEREXT hPbuffer, HDC hDC);
GdkGLProc    gdk_gl_get_wglReleasePbufferDCEXT (void);
#define      gdk_gl_wglReleasePbufferDCEXT(proc, hPbuffer, hDC) \
  ( ((GdkGLProc_wglReleasePbufferDCEXT) (proc)) (hPbuffer, hDC) )

/* wglDestroyPbufferEXT */
typedef BOOL (WINAPI * GdkGLProc_wglDestroyPbufferEXT) (HPBUFFEREXT hPbuffer);
GdkGLProc    gdk_gl_get_wglDestroyPbufferEXT (void);
#define      gdk_gl_wglDestroyPbufferEXT(proc, hPbuffer) \
  ( ((GdkGLProc_wglDestroyPbufferEXT) (proc)) (hPbuffer) )

/* wglQueryPbufferEXT */
typedef BOOL (WINAPI * GdkGLProc_wglQueryPbufferEXT) (HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);
GdkGLProc    gdk_gl_get_wglQueryPbufferEXT (void);
#define      gdk_gl_wglQueryPbufferEXT(proc, hPbuffer, iAttribute, piValue) \
  ( ((GdkGLProc_wglQueryPbufferEXT) (proc)) (hPbuffer, iAttribute, piValue) )

/* proc struct */

typedef struct _GdkGL_WGL_EXT_pbuffer GdkGL_WGL_EXT_pbuffer;

struct _GdkGL_WGL_EXT_pbuffer
{
  GdkGLProc_wglCreatePbufferEXT wglCreatePbufferEXT;
  GdkGLProc_wglGetPbufferDCEXT wglGetPbufferDCEXT;
  GdkGLProc_wglReleasePbufferDCEXT wglReleasePbufferDCEXT;
  GdkGLProc_wglDestroyPbufferEXT wglDestroyPbufferEXT;
  GdkGLProc_wglQueryPbufferEXT wglQueryPbufferEXT;
};

GdkGL_WGL_EXT_pbuffer *gdk_gl_get_WGL_EXT_pbuffer (GdkGLConfig *glconfig);

/*
 * WGL_EXT_pixel_format
 */

/* wglGetPixelFormatAttribivEXT */
typedef BOOL (WINAPI * GdkGLProc_wglGetPixelFormatAttribivEXT) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
GdkGLProc    gdk_gl_get_wglGetPixelFormatAttribivEXT (void);
#define      gdk_gl_wglGetPixelFormatAttribivEXT(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) \
  ( ((GdkGLProc_wglGetPixelFormatAttribivEXT) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues) )

/* wglGetPixelFormatAttribfvEXT */
typedef BOOL (WINAPI * GdkGLProc_wglGetPixelFormatAttribfvEXT) (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
GdkGLProc    gdk_gl_get_wglGetPixelFormatAttribfvEXT (void);
#define      gdk_gl_wglGetPixelFormatAttribfvEXT(proc, hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) \
  ( ((GdkGLProc_wglGetPixelFormatAttribfvEXT) (proc)) (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues) )

/* wglChoosePixelFormatEXT */
typedef BOOL (WINAPI * GdkGLProc_wglChoosePixelFormatEXT) (HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
GdkGLProc    gdk_gl_get_wglChoosePixelFormatEXT (void);
#define      gdk_gl_wglChoosePixelFormatEXT(proc, hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) \
  ( ((GdkGLProc_wglChoosePixelFormatEXT) (proc)) (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats) )

/* proc struct */

typedef struct _GdkGL_WGL_EXT_pixel_format GdkGL_WGL_EXT_pixel_format;

struct _GdkGL_WGL_EXT_pixel_format
{
  GdkGLProc_wglGetPixelFormatAttribivEXT wglGetPixelFormatAttribivEXT;
  GdkGLProc_wglGetPixelFormatAttribfvEXT wglGetPixelFormatAttribfvEXT;
  GdkGLProc_wglChoosePixelFormatEXT wglChoosePixelFormatEXT;
};

GdkGL_WGL_EXT_pixel_format *gdk_gl_get_WGL_EXT_pixel_format (GdkGLConfig *glconfig);

/*
 * WGL_EXT_swap_control
 */

/* wglSwapIntervalEXT */
typedef BOOL (WINAPI * GdkGLProc_wglSwapIntervalEXT) (int interval);
GdkGLProc    gdk_gl_get_wglSwapIntervalEXT (void);
#define      gdk_gl_wglSwapIntervalEXT(proc, interval) \
  ( ((GdkGLProc_wglSwapIntervalEXT) (proc)) (interval) )

/* wglGetSwapIntervalEXT */
typedef int (WINAPI * GdkGLProc_wglGetSwapIntervalEXT) (void);
GdkGLProc    gdk_gl_get_wglGetSwapIntervalEXT (void);
#define      gdk_gl_wglGetSwapIntervalEXT(proc) \
  ( ((GdkGLProc_wglGetSwapIntervalEXT) (proc)) () )

/* proc struct */

typedef struct _GdkGL_WGL_EXT_swap_control GdkGL_WGL_EXT_swap_control;

struct _GdkGL_WGL_EXT_swap_control
{
  GdkGLProc_wglSwapIntervalEXT wglSwapIntervalEXT;
  GdkGLProc_wglGetSwapIntervalEXT wglGetSwapIntervalEXT;
};

GdkGL_WGL_EXT_swap_control *gdk_gl_get_WGL_EXT_swap_control (GdkGLConfig *glconfig);

/*
 * WGL_NV_vertex_array_range
 */

/* wglAllocateMemoryNV */
typedef void* (WINAPI * GdkGLProc_wglAllocateMemoryNV) (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
GdkGLProc    gdk_gl_get_wglAllocateMemoryNV (void);
#define      gdk_gl_wglAllocateMemoryNV(proc, size, readfreq, writefreq, priority) \
  ( ((GdkGLProc_wglAllocateMemoryNV) (proc)) (size, readfreq, writefreq, priority) )

/* wglFreeMemoryNV */
typedef void (WINAPI * GdkGLProc_wglFreeMemoryNV) (void *pointer);
GdkGLProc    gdk_gl_get_wglFreeMemoryNV (void);
#define      gdk_gl_wglFreeMemoryNV(proc, pointer) \
  ( ((GdkGLProc_wglFreeMemoryNV) (proc)) (pointer) )

/* proc struct */

typedef struct _GdkGL_WGL_NV_vertex_array_range GdkGL_WGL_NV_vertex_array_range;

struct _GdkGL_WGL_NV_vertex_array_range
{
  GdkGLProc_wglAllocateMemoryNV wglAllocateMemoryNV;
  GdkGLProc_wglFreeMemoryNV wglFreeMemoryNV;
};

GdkGL_WGL_NV_vertex_array_range *gdk_gl_get_WGL_NV_vertex_array_range (GdkGLConfig *glconfig);

/*
 * WGL_OML_sync_control
 */

/* wglGetSyncValuesOML */
typedef BOOL (WINAPI * GdkGLProc_wglGetSyncValuesOML) (HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
GdkGLProc    gdk_gl_get_wglGetSyncValuesOML (void);
#define      gdk_gl_wglGetSyncValuesOML(proc, hdc, ust, msc, sbc) \
  ( ((GdkGLProc_wglGetSyncValuesOML) (proc)) (hdc, ust, msc, sbc) )

/* wglGetMscRateOML */
typedef BOOL (WINAPI * GdkGLProc_wglGetMscRateOML) (HDC hdc, INT32 *numerator, INT32 *denominator);
GdkGLProc    gdk_gl_get_wglGetMscRateOML (void);
#define      gdk_gl_wglGetMscRateOML(proc, hdc, numerator, denominator) \
  ( ((GdkGLProc_wglGetMscRateOML) (proc)) (hdc, numerator, denominator) )

/* wglSwapBuffersMscOML */
typedef INT64 (WINAPI * GdkGLProc_wglSwapBuffersMscOML) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
GdkGLProc    gdk_gl_get_wglSwapBuffersMscOML (void);
#define      gdk_gl_wglSwapBuffersMscOML(proc, hdc, target_msc, divisor, remainder) \
  ( ((GdkGLProc_wglSwapBuffersMscOML) (proc)) (hdc, target_msc, divisor, remainder) )

/* wglSwapLayerBuffersMscOML */
typedef INT64 (WINAPI * GdkGLProc_wglSwapLayerBuffersMscOML) (HDC hdc, int fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
GdkGLProc    gdk_gl_get_wglSwapLayerBuffersMscOML (void);
#define      gdk_gl_wglSwapLayerBuffersMscOML(proc, hdc, fuPlanes, target_msc, divisor, remainder) \
  ( ((GdkGLProc_wglSwapLayerBuffersMscOML) (proc)) (hdc, fuPlanes, target_msc, divisor, remainder) )

/* wglWaitForMscOML */
typedef BOOL (WINAPI * GdkGLProc_wglWaitForMscOML) (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
GdkGLProc    gdk_gl_get_wglWaitForMscOML (void);
#define      gdk_gl_wglWaitForMscOML(proc, hdc, target_msc, divisor, remainder, ust, msc, sbc) \
  ( ((GdkGLProc_wglWaitForMscOML) (proc)) (hdc, target_msc, divisor, remainder, ust, msc, sbc) )

/* wglWaitForSbcOML */
typedef BOOL (WINAPI * GdkGLProc_wglWaitForSbcOML) (HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);
GdkGLProc    gdk_gl_get_wglWaitForSbcOML (void);
#define      gdk_gl_wglWaitForSbcOML(proc, hdc, target_sbc, ust, msc, sbc) \
  ( ((GdkGLProc_wglWaitForSbcOML) (proc)) (hdc, target_sbc, ust, msc, sbc) )

/* proc struct */

typedef struct _GdkGL_WGL_OML_sync_control GdkGL_WGL_OML_sync_control;

struct _GdkGL_WGL_OML_sync_control
{
  GdkGLProc_wglGetSyncValuesOML wglGetSyncValuesOML;
  GdkGLProc_wglGetMscRateOML wglGetMscRateOML;
  GdkGLProc_wglSwapBuffersMscOML wglSwapBuffersMscOML;
  GdkGLProc_wglSwapLayerBuffersMscOML wglSwapLayerBuffersMscOML;
  GdkGLProc_wglWaitForMscOML wglWaitForMscOML;
  GdkGLProc_wglWaitForSbcOML wglWaitForSbcOML;
};

GdkGL_WGL_OML_sync_control *gdk_gl_get_WGL_OML_sync_control (GdkGLConfig *glconfig);

/*
 * WGL_I3D_digital_video_control
 */

/* wglGetDigitalVideoParametersI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGetDigitalVideoParametersI3D) (HDC hDC, int iAttribute, int *piValue);
GdkGLProc    gdk_gl_get_wglGetDigitalVideoParametersI3D (void);
#define      gdk_gl_wglGetDigitalVideoParametersI3D(proc, hDC, iAttribute, piValue) \
  ( ((GdkGLProc_wglGetDigitalVideoParametersI3D) (proc)) (hDC, iAttribute, piValue) )

/* wglSetDigitalVideoParametersI3D */
typedef BOOL (WINAPI * GdkGLProc_wglSetDigitalVideoParametersI3D) (HDC hDC, int iAttribute, const int *piValue);
GdkGLProc    gdk_gl_get_wglSetDigitalVideoParametersI3D (void);
#define      gdk_gl_wglSetDigitalVideoParametersI3D(proc, hDC, iAttribute, piValue) \
  ( ((GdkGLProc_wglSetDigitalVideoParametersI3D) (proc)) (hDC, iAttribute, piValue) )

/* proc struct */

typedef struct _GdkGL_WGL_I3D_digital_video_control GdkGL_WGL_I3D_digital_video_control;

struct _GdkGL_WGL_I3D_digital_video_control
{
  GdkGLProc_wglGetDigitalVideoParametersI3D wglGetDigitalVideoParametersI3D;
  GdkGLProc_wglSetDigitalVideoParametersI3D wglSetDigitalVideoParametersI3D;
};

GdkGL_WGL_I3D_digital_video_control *gdk_gl_get_WGL_I3D_digital_video_control (GdkGLConfig *glconfig);

/*
 * WGL_I3D_gamma
 */

/* wglGetGammaTableParametersI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGetGammaTableParametersI3D) (HDC hDC, int iAttribute, int *piValue);
GdkGLProc    gdk_gl_get_wglGetGammaTableParametersI3D (void);
#define      gdk_gl_wglGetGammaTableParametersI3D(proc, hDC, iAttribute, piValue) \
  ( ((GdkGLProc_wglGetGammaTableParametersI3D) (proc)) (hDC, iAttribute, piValue) )

/* wglSetGammaTableParametersI3D */
typedef BOOL (WINAPI * GdkGLProc_wglSetGammaTableParametersI3D) (HDC hDC, int iAttribute, const int *piValue);
GdkGLProc    gdk_gl_get_wglSetGammaTableParametersI3D (void);
#define      gdk_gl_wglSetGammaTableParametersI3D(proc, hDC, iAttribute, piValue) \
  ( ((GdkGLProc_wglSetGammaTableParametersI3D) (proc)) (hDC, iAttribute, piValue) )

/* wglGetGammaTableI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGetGammaTableI3D) (HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
GdkGLProc    gdk_gl_get_wglGetGammaTableI3D (void);
#define      gdk_gl_wglGetGammaTableI3D(proc, hDC, iEntries, puRed, puGreen, puBlue) \
  ( ((GdkGLProc_wglGetGammaTableI3D) (proc)) (hDC, iEntries, puRed, puGreen, puBlue) )

/* wglSetGammaTableI3D */
typedef BOOL (WINAPI * GdkGLProc_wglSetGammaTableI3D) (HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);
GdkGLProc    gdk_gl_get_wglSetGammaTableI3D (void);
#define      gdk_gl_wglSetGammaTableI3D(proc, hDC, iEntries, puRed, puGreen, puBlue) \
  ( ((GdkGLProc_wglSetGammaTableI3D) (proc)) (hDC, iEntries, puRed, puGreen, puBlue) )

/* proc struct */

typedef struct _GdkGL_WGL_I3D_gamma GdkGL_WGL_I3D_gamma;

struct _GdkGL_WGL_I3D_gamma
{
  GdkGLProc_wglGetGammaTableParametersI3D wglGetGammaTableParametersI3D;
  GdkGLProc_wglSetGammaTableParametersI3D wglSetGammaTableParametersI3D;
  GdkGLProc_wglGetGammaTableI3D wglGetGammaTableI3D;
  GdkGLProc_wglSetGammaTableI3D wglSetGammaTableI3D;
};

GdkGL_WGL_I3D_gamma *gdk_gl_get_WGL_I3D_gamma (GdkGLConfig *glconfig);

/*
 * WGL_I3D_genlock
 */

/* wglEnableGenlockI3D */
typedef BOOL (WINAPI * GdkGLProc_wglEnableGenlockI3D) (HDC hDC);
GdkGLProc    gdk_gl_get_wglEnableGenlockI3D (void);
#define      gdk_gl_wglEnableGenlockI3D(proc, hDC) \
  ( ((GdkGLProc_wglEnableGenlockI3D) (proc)) (hDC) )

/* wglDisableGenlockI3D */
typedef BOOL (WINAPI * GdkGLProc_wglDisableGenlockI3D) (HDC hDC);
GdkGLProc    gdk_gl_get_wglDisableGenlockI3D (void);
#define      gdk_gl_wglDisableGenlockI3D(proc, hDC) \
  ( ((GdkGLProc_wglDisableGenlockI3D) (proc)) (hDC) )

/* wglIsEnabledGenlockI3D */
typedef BOOL (WINAPI * GdkGLProc_wglIsEnabledGenlockI3D) (HDC hDC, BOOL *pFlag);
GdkGLProc    gdk_gl_get_wglIsEnabledGenlockI3D (void);
#define      gdk_gl_wglIsEnabledGenlockI3D(proc, hDC, pFlag) \
  ( ((GdkGLProc_wglIsEnabledGenlockI3D) (proc)) (hDC, pFlag) )

/* wglGenlockSourceI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGenlockSourceI3D) (HDC hDC, UINT uSource);
GdkGLProc    gdk_gl_get_wglGenlockSourceI3D (void);
#define      gdk_gl_wglGenlockSourceI3D(proc, hDC, uSource) \
  ( ((GdkGLProc_wglGenlockSourceI3D) (proc)) (hDC, uSource) )

/* wglGetGenlockSourceI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGetGenlockSourceI3D) (HDC hDC, UINT *uSource);
GdkGLProc    gdk_gl_get_wglGetGenlockSourceI3D (void);
#define      gdk_gl_wglGetGenlockSourceI3D(proc, hDC, uSource) \
  ( ((GdkGLProc_wglGetGenlockSourceI3D) (proc)) (hDC, uSource) )

/* wglGenlockSourceEdgeI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGenlockSourceEdgeI3D) (HDC hDC, UINT uEdge);
GdkGLProc    gdk_gl_get_wglGenlockSourceEdgeI3D (void);
#define      gdk_gl_wglGenlockSourceEdgeI3D(proc, hDC, uEdge) \
  ( ((GdkGLProc_wglGenlockSourceEdgeI3D) (proc)) (hDC, uEdge) )

/* wglGetGenlockSourceEdgeI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGetGenlockSourceEdgeI3D) (HDC hDC, UINT *uEdge);
GdkGLProc    gdk_gl_get_wglGetGenlockSourceEdgeI3D (void);
#define      gdk_gl_wglGetGenlockSourceEdgeI3D(proc, hDC, uEdge) \
  ( ((GdkGLProc_wglGetGenlockSourceEdgeI3D) (proc)) (hDC, uEdge) )

/* wglGenlockSampleRateI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGenlockSampleRateI3D) (HDC hDC, UINT uRate);
GdkGLProc    gdk_gl_get_wglGenlockSampleRateI3D (void);
#define      gdk_gl_wglGenlockSampleRateI3D(proc, hDC, uRate) \
  ( ((GdkGLProc_wglGenlockSampleRateI3D) (proc)) (hDC, uRate) )

/* wglGetGenlockSampleRateI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGetGenlockSampleRateI3D) (HDC hDC, UINT *uRate);
GdkGLProc    gdk_gl_get_wglGetGenlockSampleRateI3D (void);
#define      gdk_gl_wglGetGenlockSampleRateI3D(proc, hDC, uRate) \
  ( ((GdkGLProc_wglGetGenlockSampleRateI3D) (proc)) (hDC, uRate) )

/* wglGenlockSourceDelayI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGenlockSourceDelayI3D) (HDC hDC, UINT uDelay);
GdkGLProc    gdk_gl_get_wglGenlockSourceDelayI3D (void);
#define      gdk_gl_wglGenlockSourceDelayI3D(proc, hDC, uDelay) \
  ( ((GdkGLProc_wglGenlockSourceDelayI3D) (proc)) (hDC, uDelay) )

/* wglGetGenlockSourceDelayI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGetGenlockSourceDelayI3D) (HDC hDC, UINT *uDelay);
GdkGLProc    gdk_gl_get_wglGetGenlockSourceDelayI3D (void);
#define      gdk_gl_wglGetGenlockSourceDelayI3D(proc, hDC, uDelay) \
  ( ((GdkGLProc_wglGetGenlockSourceDelayI3D) (proc)) (hDC, uDelay) )

/* wglQueryGenlockMaxSourceDelayI3D */
typedef BOOL (WINAPI * GdkGLProc_wglQueryGenlockMaxSourceDelayI3D) (HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);
GdkGLProc    gdk_gl_get_wglQueryGenlockMaxSourceDelayI3D (void);
#define      gdk_gl_wglQueryGenlockMaxSourceDelayI3D(proc, hDC, uMaxLineDelay, uMaxPixelDelay) \
  ( ((GdkGLProc_wglQueryGenlockMaxSourceDelayI3D) (proc)) (hDC, uMaxLineDelay, uMaxPixelDelay) )

/* proc struct */

typedef struct _GdkGL_WGL_I3D_genlock GdkGL_WGL_I3D_genlock;

struct _GdkGL_WGL_I3D_genlock
{
  GdkGLProc_wglEnableGenlockI3D wglEnableGenlockI3D;
  GdkGLProc_wglDisableGenlockI3D wglDisableGenlockI3D;
  GdkGLProc_wglIsEnabledGenlockI3D wglIsEnabledGenlockI3D;
  GdkGLProc_wglGenlockSourceI3D wglGenlockSourceI3D;
  GdkGLProc_wglGetGenlockSourceI3D wglGetGenlockSourceI3D;
  GdkGLProc_wglGenlockSourceEdgeI3D wglGenlockSourceEdgeI3D;
  GdkGLProc_wglGetGenlockSourceEdgeI3D wglGetGenlockSourceEdgeI3D;
  GdkGLProc_wglGenlockSampleRateI3D wglGenlockSampleRateI3D;
  GdkGLProc_wglGetGenlockSampleRateI3D wglGetGenlockSampleRateI3D;
  GdkGLProc_wglGenlockSourceDelayI3D wglGenlockSourceDelayI3D;
  GdkGLProc_wglGetGenlockSourceDelayI3D wglGetGenlockSourceDelayI3D;
  GdkGLProc_wglQueryGenlockMaxSourceDelayI3D wglQueryGenlockMaxSourceDelayI3D;
};

GdkGL_WGL_I3D_genlock *gdk_gl_get_WGL_I3D_genlock (GdkGLConfig *glconfig);

/*
 * WGL_I3D_image_buffer
 */

/* wglCreateImageBufferI3D */
typedef LPVOID (WINAPI * GdkGLProc_wglCreateImageBufferI3D) (HDC hDC, DWORD dwSize, UINT uFlags);
GdkGLProc    gdk_gl_get_wglCreateImageBufferI3D (void);
#define      gdk_gl_wglCreateImageBufferI3D(proc, hDC, dwSize, uFlags) \
  ( ((GdkGLProc_wglCreateImageBufferI3D) (proc)) (hDC, dwSize, uFlags) )

/* wglDestroyImageBufferI3D */
typedef BOOL (WINAPI * GdkGLProc_wglDestroyImageBufferI3D) (HDC hDC, LPVOID pAddress);
GdkGLProc    gdk_gl_get_wglDestroyImageBufferI3D (void);
#define      gdk_gl_wglDestroyImageBufferI3D(proc, hDC, pAddress) \
  ( ((GdkGLProc_wglDestroyImageBufferI3D) (proc)) (hDC, pAddress) )

/* wglAssociateImageBufferEventsI3D */
typedef BOOL (WINAPI * GdkGLProc_wglAssociateImageBufferEventsI3D) (HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
GdkGLProc    gdk_gl_get_wglAssociateImageBufferEventsI3D (void);
#define      gdk_gl_wglAssociateImageBufferEventsI3D(proc, hDC, pEvent, pAddress, pSize, count) \
  ( ((GdkGLProc_wglAssociateImageBufferEventsI3D) (proc)) (hDC, pEvent, pAddress, pSize, count) )

/* wglReleaseImageBufferEventsI3D */
typedef BOOL (WINAPI * GdkGLProc_wglReleaseImageBufferEventsI3D) (HDC hDC, const LPVOID *pAddress, UINT count);
GdkGLProc    gdk_gl_get_wglReleaseImageBufferEventsI3D (void);
#define      gdk_gl_wglReleaseImageBufferEventsI3D(proc, hDC, pAddress, count) \
  ( ((GdkGLProc_wglReleaseImageBufferEventsI3D) (proc)) (hDC, pAddress, count) )

/* proc struct */

typedef struct _GdkGL_WGL_I3D_image_buffer GdkGL_WGL_I3D_image_buffer;

struct _GdkGL_WGL_I3D_image_buffer
{
  GdkGLProc_wglCreateImageBufferI3D wglCreateImageBufferI3D;
  GdkGLProc_wglDestroyImageBufferI3D wglDestroyImageBufferI3D;
  GdkGLProc_wglAssociateImageBufferEventsI3D wglAssociateImageBufferEventsI3D;
  GdkGLProc_wglReleaseImageBufferEventsI3D wglReleaseImageBufferEventsI3D;
};

GdkGL_WGL_I3D_image_buffer *gdk_gl_get_WGL_I3D_image_buffer (GdkGLConfig *glconfig);

/*
 * WGL_I3D_swap_frame_lock
 */

/* wglEnableFrameLockI3D */
typedef BOOL (WINAPI * GdkGLProc_wglEnableFrameLockI3D) (void);
GdkGLProc    gdk_gl_get_wglEnableFrameLockI3D (void);
#define      gdk_gl_wglEnableFrameLockI3D(proc) \
  ( ((GdkGLProc_wglEnableFrameLockI3D) (proc)) () )

/* wglDisableFrameLockI3D */
typedef BOOL (WINAPI * GdkGLProc_wglDisableFrameLockI3D) (void);
GdkGLProc    gdk_gl_get_wglDisableFrameLockI3D (void);
#define      gdk_gl_wglDisableFrameLockI3D(proc) \
  ( ((GdkGLProc_wglDisableFrameLockI3D) (proc)) () )

/* wglIsEnabledFrameLockI3D */
typedef BOOL (WINAPI * GdkGLProc_wglIsEnabledFrameLockI3D) (BOOL *pFlag);
GdkGLProc    gdk_gl_get_wglIsEnabledFrameLockI3D (void);
#define      gdk_gl_wglIsEnabledFrameLockI3D(proc, pFlag) \
  ( ((GdkGLProc_wglIsEnabledFrameLockI3D) (proc)) (pFlag) )

/* wglQueryFrameLockMasterI3D */
typedef BOOL (WINAPI * GdkGLProc_wglQueryFrameLockMasterI3D) (BOOL *pFlag);
GdkGLProc    gdk_gl_get_wglQueryFrameLockMasterI3D (void);
#define      gdk_gl_wglQueryFrameLockMasterI3D(proc, pFlag) \
  ( ((GdkGLProc_wglQueryFrameLockMasterI3D) (proc)) (pFlag) )

/* proc struct */

typedef struct _GdkGL_WGL_I3D_swap_frame_lock GdkGL_WGL_I3D_swap_frame_lock;

struct _GdkGL_WGL_I3D_swap_frame_lock
{
  GdkGLProc_wglEnableFrameLockI3D wglEnableFrameLockI3D;
  GdkGLProc_wglDisableFrameLockI3D wglDisableFrameLockI3D;
  GdkGLProc_wglIsEnabledFrameLockI3D wglIsEnabledFrameLockI3D;
  GdkGLProc_wglQueryFrameLockMasterI3D wglQueryFrameLockMasterI3D;
};

GdkGL_WGL_I3D_swap_frame_lock *gdk_gl_get_WGL_I3D_swap_frame_lock (GdkGLConfig *glconfig);

/*
 * WGL_I3D_swap_frame_usage
 */

/* wglGetFrameUsageI3D */
typedef BOOL (WINAPI * GdkGLProc_wglGetFrameUsageI3D) (float *pUsage);
GdkGLProc    gdk_gl_get_wglGetFrameUsageI3D (void);
#define      gdk_gl_wglGetFrameUsageI3D(proc, pUsage) \
  ( ((GdkGLProc_wglGetFrameUsageI3D) (proc)) (pUsage) )

/* wglBeginFrameTrackingI3D */
typedef BOOL (WINAPI * GdkGLProc_wglBeginFrameTrackingI3D) (void);
GdkGLProc    gdk_gl_get_wglBeginFrameTrackingI3D (void);
#define      gdk_gl_wglBeginFrameTrackingI3D(proc) \
  ( ((GdkGLProc_wglBeginFrameTrackingI3D) (proc)) () )

/* wglEndFrameTrackingI3D */
typedef BOOL (WINAPI * GdkGLProc_wglEndFrameTrackingI3D) (void);
GdkGLProc    gdk_gl_get_wglEndFrameTrackingI3D (void);
#define      gdk_gl_wglEndFrameTrackingI3D(proc) \
  ( ((GdkGLProc_wglEndFrameTrackingI3D) (proc)) () )

/* wglQueryFrameTrackingI3D */
typedef BOOL (WINAPI * GdkGLProc_wglQueryFrameTrackingI3D) (DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);
GdkGLProc    gdk_gl_get_wglQueryFrameTrackingI3D (void);
#define      gdk_gl_wglQueryFrameTrackingI3D(proc, pFrameCount, pMissedFrames, pLastMissedUsage) \
  ( ((GdkGLProc_wglQueryFrameTrackingI3D) (proc)) (pFrameCount, pMissedFrames, pLastMissedUsage) )

/* proc struct */

typedef struct _GdkGL_WGL_I3D_swap_frame_usage GdkGL_WGL_I3D_swap_frame_usage;

struct _GdkGL_WGL_I3D_swap_frame_usage
{
  GdkGLProc_wglGetFrameUsageI3D wglGetFrameUsageI3D;
  GdkGLProc_wglBeginFrameTrackingI3D wglBeginFrameTrackingI3D;
  GdkGLProc_wglEndFrameTrackingI3D wglEndFrameTrackingI3D;
  GdkGLProc_wglQueryFrameTrackingI3D wglQueryFrameTrackingI3D;
};

GdkGL_WGL_I3D_swap_frame_usage *gdk_gl_get_WGL_I3D_swap_frame_usage (GdkGLConfig *glconfig);

/*
 * WGL_3DL_stereo_control
 */

/* wglSetStereoEmitterState3DL */
typedef BOOL (WINAPI * GdkGLProc_wglSetStereoEmitterState3DL) (HDC hDC, UINT uState);
GdkGLProc    gdk_gl_get_wglSetStereoEmitterState3DL (void);
#define      gdk_gl_wglSetStereoEmitterState3DL(proc, hDC, uState) \
  ( ((GdkGLProc_wglSetStereoEmitterState3DL) (proc)) (hDC, uState) )

/* proc struct */

typedef struct _GdkGL_WGL_3DL_stereo_control GdkGL_WGL_3DL_stereo_control;

struct _GdkGL_WGL_3DL_stereo_control
{
  GdkGLProc_wglSetStereoEmitterState3DL wglSetStereoEmitterState3DL;
};

GdkGL_WGL_3DL_stereo_control *gdk_gl_get_WGL_3DL_stereo_control (GdkGLConfig *glconfig);

/*
 * WGL_NV_present_video
 */

/* wglEnumerateVideoDevicesNV */
typedef int (WINAPI * GdkGLProc_wglEnumerateVideoDevicesNV) (HDC hDC, HVIDEOOUTPUTDEVICENV *phDeviceList);
GdkGLProc    gdk_gl_get_wglEnumerateVideoDevicesNV (void);
#define      gdk_gl_wglEnumerateVideoDevicesNV(proc, hDC, phDeviceList) \
  ( ((GdkGLProc_wglEnumerateVideoDevicesNV) (proc)) (hDC, phDeviceList) )

/* wglBindVideoDeviceNV */
typedef BOOL (WINAPI * GdkGLProc_wglBindVideoDeviceNV) (HDC hDC, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
GdkGLProc    gdk_gl_get_wglBindVideoDeviceNV (void);
#define      gdk_gl_wglBindVideoDeviceNV(proc, hDC, uVideoSlot, hVideoDevice, piAttribList) \
  ( ((GdkGLProc_wglBindVideoDeviceNV) (proc)) (hDC, uVideoSlot, hVideoDevice, piAttribList) )

/* wglQueryCurrentContextNV */
typedef BOOL (WINAPI * GdkGLProc_wglQueryCurrentContextNV) (int iAttribute, int *piValue);
GdkGLProc    gdk_gl_get_wglQueryCurrentContextNV (void);
#define      gdk_gl_wglQueryCurrentContextNV(proc, iAttribute, piValue) \
  ( ((GdkGLProc_wglQueryCurrentContextNV) (proc)) (iAttribute, piValue) )

/* proc struct */

typedef struct _GdkGL_WGL_NV_present_video GdkGL_WGL_NV_present_video;

struct _GdkGL_WGL_NV_present_video
{
  GdkGLProc_wglEnumerateVideoDevicesNV wglEnumerateVideoDevicesNV;
  GdkGLProc_wglBindVideoDeviceNV wglBindVideoDeviceNV;
  GdkGLProc_wglQueryCurrentContextNV wglQueryCurrentContextNV;
};

GdkGL_WGL_NV_present_video *gdk_gl_get_WGL_NV_present_video (GdkGLConfig *glconfig);

/*
 * WGL_NV_video_output
 */

/* wglGetVideoDeviceNV */
typedef BOOL (WINAPI * GdkGLProc_wglGetVideoDeviceNV) (HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
GdkGLProc    gdk_gl_get_wglGetVideoDeviceNV (void);
#define      gdk_gl_wglGetVideoDeviceNV(proc, hDC, numDevices, hVideoDevice) \
  ( ((GdkGLProc_wglGetVideoDeviceNV) (proc)) (hDC, numDevices, hVideoDevice) )

/* wglReleaseVideoDeviceNV */
typedef BOOL (WINAPI * GdkGLProc_wglReleaseVideoDeviceNV) (HPVIDEODEV hVideoDevice);
GdkGLProc    gdk_gl_get_wglReleaseVideoDeviceNV (void);
#define      gdk_gl_wglReleaseVideoDeviceNV(proc, hVideoDevice) \
  ( ((GdkGLProc_wglReleaseVideoDeviceNV) (proc)) (hVideoDevice) )

/* wglBindVideoImageNV */
typedef BOOL (WINAPI * GdkGLProc_wglBindVideoImageNV) (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
GdkGLProc    gdk_gl_get_wglBindVideoImageNV (void);
#define      gdk_gl_wglBindVideoImageNV(proc, hVideoDevice, hPbuffer, iVideoBuffer) \
  ( ((GdkGLProc_wglBindVideoImageNV) (proc)) (hVideoDevice, hPbuffer, iVideoBuffer) )

/* wglReleaseVideoImageNV */
typedef BOOL (WINAPI * GdkGLProc_wglReleaseVideoImageNV) (HPBUFFERARB hPbuffer, int iVideoBuffer);
GdkGLProc    gdk_gl_get_wglReleaseVideoImageNV (void);
#define      gdk_gl_wglReleaseVideoImageNV(proc, hPbuffer, iVideoBuffer) \
  ( ((GdkGLProc_wglReleaseVideoImageNV) (proc)) (hPbuffer, iVideoBuffer) )

/* wglSendPbufferToVideoNV */
typedef BOOL (WINAPI * GdkGLProc_wglSendPbufferToVideoNV) (HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
GdkGLProc    gdk_gl_get_wglSendPbufferToVideoNV (void);
#define      gdk_gl_wglSendPbufferToVideoNV(proc, hPbuffer, iBufferType, pulCounterPbuffer, bBlock) \
  ( ((GdkGLProc_wglSendPbufferToVideoNV) (proc)) (hPbuffer, iBufferType, pulCounterPbuffer, bBlock) )

/* wglGetVideoInfoNV */
typedef BOOL (WINAPI * GdkGLProc_wglGetVideoInfoNV) (HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);
GdkGLProc    gdk_gl_get_wglGetVideoInfoNV (void);
#define      gdk_gl_wglGetVideoInfoNV(proc, hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo) \
  ( ((GdkGLProc_wglGetVideoInfoNV) (proc)) (hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo) )

/* proc struct */

typedef struct _GdkGL_WGL_NV_video_output GdkGL_WGL_NV_video_output;

struct _GdkGL_WGL_NV_video_output
{
  GdkGLProc_wglGetVideoDeviceNV wglGetVideoDeviceNV;
  GdkGLProc_wglReleaseVideoDeviceNV wglReleaseVideoDeviceNV;
  GdkGLProc_wglBindVideoImageNV wglBindVideoImageNV;
  GdkGLProc_wglReleaseVideoImageNV wglReleaseVideoImageNV;
  GdkGLProc_wglSendPbufferToVideoNV wglSendPbufferToVideoNV;
  GdkGLProc_wglGetVideoInfoNV wglGetVideoInfoNV;
};

GdkGL_WGL_NV_video_output *gdk_gl_get_WGL_NV_video_output (GdkGLConfig *glconfig);

/*
 * WGL_NV_swap_group
 */

/* wglJoinSwapGroupNV */
typedef BOOL (WINAPI * GdkGLProc_wglJoinSwapGroupNV) (HDC hDC, GLuint group);
GdkGLProc    gdk_gl_get_wglJoinSwapGroupNV (void);
#define      gdk_gl_wglJoinSwapGroupNV(proc, hDC, group) \
  ( ((GdkGLProc_wglJoinSwapGroupNV) (proc)) (hDC, group) )

/* wglBindSwapBarrierNV */
typedef BOOL (WINAPI * GdkGLProc_wglBindSwapBarrierNV) (GLuint group, GLuint barrier);
GdkGLProc    gdk_gl_get_wglBindSwapBarrierNV (void);
#define      gdk_gl_wglBindSwapBarrierNV(proc, group, barrier) \
  ( ((GdkGLProc_wglBindSwapBarrierNV) (proc)) (group, barrier) )

/* wglQuerySwapGroupNV */
typedef BOOL (WINAPI * GdkGLProc_wglQuerySwapGroupNV) (HDC hDC, GLuint *group, GLuint *barrier);
GdkGLProc    gdk_gl_get_wglQuerySwapGroupNV (void);
#define      gdk_gl_wglQuerySwapGroupNV(proc, hDC, group, barrier) \
  ( ((GdkGLProc_wglQuerySwapGroupNV) (proc)) (hDC, group, barrier) )

/* wglQueryMaxSwapGroupsNV */
typedef BOOL (WINAPI * GdkGLProc_wglQueryMaxSwapGroupsNV) (HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
GdkGLProc    gdk_gl_get_wglQueryMaxSwapGroupsNV (void);
#define      gdk_gl_wglQueryMaxSwapGroupsNV(proc, hDC, maxGroups, maxBarriers) \
  ( ((GdkGLProc_wglQueryMaxSwapGroupsNV) (proc)) (hDC, maxGroups, maxBarriers) )

/* wglQueryFrameCountNV */
typedef BOOL (WINAPI * GdkGLProc_wglQueryFrameCountNV) (HDC hDC, GLuint *count);
GdkGLProc    gdk_gl_get_wglQueryFrameCountNV (void);
#define      gdk_gl_wglQueryFrameCountNV(proc, hDC, count) \
  ( ((GdkGLProc_wglQueryFrameCountNV) (proc)) (hDC, count) )

/* wglResetFrameCountNV */
typedef BOOL (WINAPI * GdkGLProc_wglResetFrameCountNV) (HDC hDC);
GdkGLProc    gdk_gl_get_wglResetFrameCountNV (void);
#define      gdk_gl_wglResetFrameCountNV(proc, hDC) \
  ( ((GdkGLProc_wglResetFrameCountNV) (proc)) (hDC) )

/* proc struct */

typedef struct _GdkGL_WGL_NV_swap_group GdkGL_WGL_NV_swap_group;

struct _GdkGL_WGL_NV_swap_group
{
  GdkGLProc_wglJoinSwapGroupNV wglJoinSwapGroupNV;
  GdkGLProc_wglBindSwapBarrierNV wglBindSwapBarrierNV;
  GdkGLProc_wglQuerySwapGroupNV wglQuerySwapGroupNV;
  GdkGLProc_wglQueryMaxSwapGroupsNV wglQueryMaxSwapGroupsNV;
  GdkGLProc_wglQueryFrameCountNV wglQueryFrameCountNV;
  GdkGLProc_wglResetFrameCountNV wglResetFrameCountNV;
};

GdkGL_WGL_NV_swap_group *gdk_gl_get_WGL_NV_swap_group (GdkGLConfig *glconfig);

/*
 * WGL_NV_gpu_affinity
 */

/* wglEnumGpusNV */
typedef BOOL (WINAPI * GdkGLProc_wglEnumGpusNV) (UINT iGpuIndex, HGPUNV *phGpu);
GdkGLProc    gdk_gl_get_wglEnumGpusNV (void);
#define      gdk_gl_wglEnumGpusNV(proc, iGpuIndex, phGpu) \
  ( ((GdkGLProc_wglEnumGpusNV) (proc)) (iGpuIndex, phGpu) )

/* wglEnumGpuDevicesNV */
typedef BOOL (WINAPI * GdkGLProc_wglEnumGpuDevicesNV) (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
GdkGLProc    gdk_gl_get_wglEnumGpuDevicesNV (void);
#define      gdk_gl_wglEnumGpuDevicesNV(proc, hGpu, iDeviceIndex, lpGpuDevice) \
  ( ((GdkGLProc_wglEnumGpuDevicesNV) (proc)) (hGpu, iDeviceIndex, lpGpuDevice) )

/* wglCreateAffinityDCNV */
typedef HDC (WINAPI * GdkGLProc_wglCreateAffinityDCNV) (const HGPUNV *phGpuList);
GdkGLProc    gdk_gl_get_wglCreateAffinityDCNV (void);
#define      gdk_gl_wglCreateAffinityDCNV(proc, phGpuList) \
  ( ((GdkGLProc_wglCreateAffinityDCNV) (proc)) (phGpuList) )

/* wglEnumGpusFromAffinityDCNV */
typedef BOOL (WINAPI * GdkGLProc_wglEnumGpusFromAffinityDCNV) (HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
GdkGLProc    gdk_gl_get_wglEnumGpusFromAffinityDCNV (void);
#define      gdk_gl_wglEnumGpusFromAffinityDCNV(proc, hAffinityDC, iGpuIndex, hGpu) \
  ( ((GdkGLProc_wglEnumGpusFromAffinityDCNV) (proc)) (hAffinityDC, iGpuIndex, hGpu) )

/* wglDeleteDCNV */
typedef BOOL (WINAPI * GdkGLProc_wglDeleteDCNV) (HDC hdc);
GdkGLProc    gdk_gl_get_wglDeleteDCNV (void);
#define      gdk_gl_wglDeleteDCNV(proc, hdc) \
  ( ((GdkGLProc_wglDeleteDCNV) (proc)) (hdc) )

/* proc struct */

typedef struct _GdkGL_WGL_NV_gpu_affinity GdkGL_WGL_NV_gpu_affinity;

struct _GdkGL_WGL_NV_gpu_affinity
{
  GdkGLProc_wglEnumGpusNV wglEnumGpusNV;
  GdkGLProc_wglEnumGpuDevicesNV wglEnumGpuDevicesNV;
  GdkGLProc_wglCreateAffinityDCNV wglCreateAffinityDCNV;
  GdkGLProc_wglEnumGpusFromAffinityDCNV wglEnumGpusFromAffinityDCNV;
  GdkGLProc_wglDeleteDCNV wglDeleteDCNV;
};

GdkGL_WGL_NV_gpu_affinity *gdk_gl_get_WGL_NV_gpu_affinity (GdkGLConfig *glconfig);

/*
 * WGL_AMD_gpu_association
 */

/* wglGetGPUIDsAMD */
typedef UINT (WINAPI * GdkGLProc_wglGetGPUIDsAMD) (UINT maxCount, UINT *ids);
GdkGLProc    gdk_gl_get_wglGetGPUIDsAMD (void);
#define      gdk_gl_wglGetGPUIDsAMD(proc, maxCount, ids) \
  ( ((GdkGLProc_wglGetGPUIDsAMD) (proc)) (maxCount, ids) )

/* wglGetGPUInfoAMD */
typedef INT (WINAPI * GdkGLProc_wglGetGPUInfoAMD) (UINT id, int property, GLenum dataType, UINT size, void *data);
GdkGLProc    gdk_gl_get_wglGetGPUInfoAMD (void);
#define      gdk_gl_wglGetGPUInfoAMD(proc, id, property, dataType, size, data) \
  ( ((GdkGLProc_wglGetGPUInfoAMD) (proc)) (id, property, dataType, size, data) )

/* wglGetContextGPUIDAMD */
typedef UINT (WINAPI * GdkGLProc_wglGetContextGPUIDAMD) (HGLRC hglrc);
GdkGLProc    gdk_gl_get_wglGetContextGPUIDAMD (void);
#define      gdk_gl_wglGetContextGPUIDAMD(proc, hglrc) \
  ( ((GdkGLProc_wglGetContextGPUIDAMD) (proc)) (hglrc) )

/* wglCreateAssociatedContextAMD */
typedef HGLRC (WINAPI * GdkGLProc_wglCreateAssociatedContextAMD) (UINT id);
GdkGLProc    gdk_gl_get_wglCreateAssociatedContextAMD (void);
#define      gdk_gl_wglCreateAssociatedContextAMD(proc, id) \
  ( ((GdkGLProc_wglCreateAssociatedContextAMD) (proc)) (id) )

/* wglCreateAssociatedContextAttribsAMD */
typedef HGLRC (WINAPI * GdkGLProc_wglCreateAssociatedContextAttribsAMD) (UINT id, HGLRC hShareContext, const int *attribList);
GdkGLProc    gdk_gl_get_wglCreateAssociatedContextAttribsAMD (void);
#define      gdk_gl_wglCreateAssociatedContextAttribsAMD(proc, id, hShareContext, attribList) \
  ( ((GdkGLProc_wglCreateAssociatedContextAttribsAMD) (proc)) (id, hShareContext, attribList) )

/* wglDeleteAssociatedContextAMD */
typedef BOOL (WINAPI * GdkGLProc_wglDeleteAssociatedContextAMD) (HGLRC hglrc);
GdkGLProc    gdk_gl_get_wglDeleteAssociatedContextAMD (void);
#define      gdk_gl_wglDeleteAssociatedContextAMD(proc, hglrc) \
  ( ((GdkGLProc_wglDeleteAssociatedContextAMD) (proc)) (hglrc) )

/* wglMakeAssociatedContextCurrentAMD */
typedef BOOL (WINAPI * GdkGLProc_wglMakeAssociatedContextCurrentAMD) (HGLRC hglrc);
GdkGLProc    gdk_gl_get_wglMakeAssociatedContextCurrentAMD (void);
#define      gdk_gl_wglMakeAssociatedContextCurrentAMD(proc, hglrc) \
  ( ((GdkGLProc_wglMakeAssociatedContextCurrentAMD) (proc)) (hglrc) )

/* wglGetCurrentAssociatedContextAMD */
typedef HGLRC (WINAPI * GdkGLProc_wglGetCurrentAssociatedContextAMD) (void);
GdkGLProc    gdk_gl_get_wglGetCurrentAssociatedContextAMD (void);
#define      gdk_gl_wglGetCurrentAssociatedContextAMD(proc) \
  ( ((GdkGLProc_wglGetCurrentAssociatedContextAMD) (proc)) () )

/* wglBlitContextFramebufferAMD */
typedef VOID (WINAPI * GdkGLProc_wglBlitContextFramebufferAMD) (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GdkGLProc    gdk_gl_get_wglBlitContextFramebufferAMD (void);
#define      gdk_gl_wglBlitContextFramebufferAMD(proc, dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter) \
  ( ((GdkGLProc_wglBlitContextFramebufferAMD) (proc)) (dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter) )

/* proc struct */

typedef struct _GdkGL_WGL_AMD_gpu_association GdkGL_WGL_AMD_gpu_association;

struct _GdkGL_WGL_AMD_gpu_association
{
  GdkGLProc_wglGetGPUIDsAMD wglGetGPUIDsAMD;
  GdkGLProc_wglGetGPUInfoAMD wglGetGPUInfoAMD;
  GdkGLProc_wglGetContextGPUIDAMD wglGetContextGPUIDAMD;
  GdkGLProc_wglCreateAssociatedContextAMD wglCreateAssociatedContextAMD;
  GdkGLProc_wglCreateAssociatedContextAttribsAMD wglCreateAssociatedContextAttribsAMD;
  GdkGLProc_wglDeleteAssociatedContextAMD wglDeleteAssociatedContextAMD;
  GdkGLProc_wglMakeAssociatedContextCurrentAMD wglMakeAssociatedContextCurrentAMD;
  GdkGLProc_wglGetCurrentAssociatedContextAMD wglGetCurrentAssociatedContextAMD;
  GdkGLProc_wglBlitContextFramebufferAMD wglBlitContextFramebufferAMD;
};

GdkGL_WGL_AMD_gpu_association *gdk_gl_get_WGL_AMD_gpu_association (GdkGLConfig *glconfig);

/*
 * WGL_NV_video_capture
 */

/* wglBindVideoCaptureDeviceNV */
typedef BOOL (WINAPI * GdkGLProc_wglBindVideoCaptureDeviceNV) (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
GdkGLProc    gdk_gl_get_wglBindVideoCaptureDeviceNV (void);
#define      gdk_gl_wglBindVideoCaptureDeviceNV(proc, uVideoSlot, hDevice) \
  ( ((GdkGLProc_wglBindVideoCaptureDeviceNV) (proc)) (uVideoSlot, hDevice) )

/* wglEnumerateVideoCaptureDevicesNV */
typedef UINT (WINAPI * GdkGLProc_wglEnumerateVideoCaptureDevicesNV) (HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
GdkGLProc    gdk_gl_get_wglEnumerateVideoCaptureDevicesNV (void);
#define      gdk_gl_wglEnumerateVideoCaptureDevicesNV(proc, hDc, phDeviceList) \
  ( ((GdkGLProc_wglEnumerateVideoCaptureDevicesNV) (proc)) (hDc, phDeviceList) )

/* wglLockVideoCaptureDeviceNV */
typedef BOOL (WINAPI * GdkGLProc_wglLockVideoCaptureDeviceNV) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
GdkGLProc    gdk_gl_get_wglLockVideoCaptureDeviceNV (void);
#define      gdk_gl_wglLockVideoCaptureDeviceNV(proc, hDc, hDevice) \
  ( ((GdkGLProc_wglLockVideoCaptureDeviceNV) (proc)) (hDc, hDevice) )

/* wglQueryVideoCaptureDeviceNV */
typedef BOOL (WINAPI * GdkGLProc_wglQueryVideoCaptureDeviceNV) (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
GdkGLProc    gdk_gl_get_wglQueryVideoCaptureDeviceNV (void);
#define      gdk_gl_wglQueryVideoCaptureDeviceNV(proc, hDc, hDevice, iAttribute, piValue) \
  ( ((GdkGLProc_wglQueryVideoCaptureDeviceNV) (proc)) (hDc, hDevice, iAttribute, piValue) )

/* wglReleaseVideoCaptureDeviceNV */
typedef BOOL (WINAPI * GdkGLProc_wglReleaseVideoCaptureDeviceNV) (HDC hDc, HVIDEOINPUTDEVICENV hDevice);
GdkGLProc    gdk_gl_get_wglReleaseVideoCaptureDeviceNV (void);
#define      gdk_gl_wglReleaseVideoCaptureDeviceNV(proc, hDc, hDevice) \
  ( ((GdkGLProc_wglReleaseVideoCaptureDeviceNV) (proc)) (hDc, hDevice) )

/* proc struct */

typedef struct _GdkGL_WGL_NV_video_capture GdkGL_WGL_NV_video_capture;

struct _GdkGL_WGL_NV_video_capture
{
  GdkGLProc_wglBindVideoCaptureDeviceNV wglBindVideoCaptureDeviceNV;
  GdkGLProc_wglEnumerateVideoCaptureDevicesNV wglEnumerateVideoCaptureDevicesNV;
  GdkGLProc_wglLockVideoCaptureDeviceNV wglLockVideoCaptureDeviceNV;
  GdkGLProc_wglQueryVideoCaptureDeviceNV wglQueryVideoCaptureDeviceNV;
  GdkGLProc_wglReleaseVideoCaptureDeviceNV wglReleaseVideoCaptureDeviceNV;
};

GdkGL_WGL_NV_video_capture *gdk_gl_get_WGL_NV_video_capture (GdkGLConfig *glconfig);

/*
 * WGL_NV_copy_image
 */

/* wglCopyImageSubDataNV */
typedef BOOL (WINAPI * GdkGLProc_wglCopyImageSubDataNV) (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
GdkGLProc    gdk_gl_get_wglCopyImageSubDataNV (void);
#define      gdk_gl_wglCopyImageSubDataNV(proc, hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth) \
  ( ((GdkGLProc_wglCopyImageSubDataNV) (proc)) (hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth) )

/* proc struct */

typedef struct _GdkGL_WGL_NV_copy_image GdkGL_WGL_NV_copy_image;

struct _GdkGL_WGL_NV_copy_image
{
  GdkGLProc_wglCopyImageSubDataNV wglCopyImageSubDataNV;
};

GdkGL_WGL_NV_copy_image *gdk_gl_get_WGL_NV_copy_image (GdkGLConfig *glconfig);

G_END_DECLS

#endif /* __GDK_GL_WGLEXT_H__ */
