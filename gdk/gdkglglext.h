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

#ifndef __GDK_GL_GLEXT_H__
#define __GDK_GL_GLEXT_H__

#include <GL/gl.h>

#include <gdk/glext/glext.h>

#include <gdk/gdkglquery.h>

G_BEGIN_DECLS

/* 
 * GL_VERSION_1_2
 */

/* glBlendColor */
typedef void (APIENTRY * GdkGLProc_GLBLENDCOLOR) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GdkGLProc    gdk_gl_get_glBlendColor (void);
#define      gdk_gl_glBlendColor(proc, red, green, blue, alpha) \
  ( ((GdkGLProc_GLBLENDCOLOR) (proc)) (red, green, blue, alpha) )

/* glBlendEquation */
typedef void (APIENTRY * GdkGLProc_GLBLENDEQUATION) (GLenum mode);
GdkGLProc    gdk_gl_get_glBlendEquation (void);
#define      gdk_gl_glBlendEquation(proc, mode) \
  ( ((GdkGLProc_GLBLENDEQUATION) (proc)) (mode) )

/* glDrawRangeElements */
typedef void (APIENTRY * GdkGLProc_GLDRAWRANGEELEMENTS) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
GdkGLProc    gdk_gl_get_glDrawRangeElements (void);
#define      gdk_gl_glDrawRangeElements(proc, mode, start, end, count, type, indices) \
  ( ((GdkGLProc_GLDRAWRANGEELEMENTS) (proc)) (mode, start, end, count, type, indices) )

/* glColorTable */
typedef void (APIENTRY * GdkGLProc_GLCOLORTABLE) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
GdkGLProc    gdk_gl_get_glColorTable (void);
#define      gdk_gl_glColorTable(proc, target, internalformat, width, format, type, table) \
  ( ((GdkGLProc_GLCOLORTABLE) (proc)) (target, internalformat, width, format, type, table) )

/* glColorTableParameterfv */
typedef void (APIENTRY * GdkGLProc_GLCOLORTABLEPARAMETERFV) (GLenum target, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glColorTableParameterfv (void);
#define      gdk_gl_glColorTableParameterfv(proc, target, pname, params) \
  ( ((GdkGLProc_GLCOLORTABLEPARAMETERFV) (proc)) (target, pname, params) )

/* glColorTableParameteriv */
typedef void (APIENTRY * GdkGLProc_GLCOLORTABLEPARAMETERIV) (GLenum target, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glColorTableParameteriv (void);
#define      gdk_gl_glColorTableParameteriv(proc, target, pname, params) \
  ( ((GdkGLProc_GLCOLORTABLEPARAMETERIV) (proc)) (target, pname, params) )

/* glCopyColorTable */
typedef void (APIENTRY * GdkGLProc_GLCOPYCOLORTABLE) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GdkGLProc    gdk_gl_get_glCopyColorTable (void);
#define      gdk_gl_glCopyColorTable(proc, target, internalformat, x, y, width) \
  ( ((GdkGLProc_GLCOPYCOLORTABLE) (proc)) (target, internalformat, x, y, width) )

/* glGetColorTable */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLE) (GLenum target, GLenum format, GLenum type, GLvoid *table);
GdkGLProc    gdk_gl_get_glGetColorTable (void);
#define      gdk_gl_glGetColorTable(proc, target, format, type, table) \
  ( ((GdkGLProc_GLGETCOLORTABLE) (proc)) (target, format, type, table) )

/* glGetColorTableParameterfv */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLEPARAMETERFV) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetColorTableParameterfv (void);
#define      gdk_gl_glGetColorTableParameterfv(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCOLORTABLEPARAMETERFV) (proc)) (target, pname, params) )

/* glGetColorTableParameteriv */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLEPARAMETERIV) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetColorTableParameteriv (void);
#define      gdk_gl_glGetColorTableParameteriv(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCOLORTABLEPARAMETERIV) (proc)) (target, pname, params) )

/* glColorSubTable */
typedef void (APIENTRY * GdkGLProc_GLCOLORSUBTABLE) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
GdkGLProc    gdk_gl_get_glColorSubTable (void);
#define      gdk_gl_glColorSubTable(proc, target, start, count, format, type, data) \
  ( ((GdkGLProc_GLCOLORSUBTABLE) (proc)) (target, start, count, format, type, data) )

/* glCopyColorSubTable */
typedef void (APIENTRY * GdkGLProc_GLCOPYCOLORSUBTABLE) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
GdkGLProc    gdk_gl_get_glCopyColorSubTable (void);
#define      gdk_gl_glCopyColorSubTable(proc, target, start, x, y, width) \
  ( ((GdkGLProc_GLCOPYCOLORSUBTABLE) (proc)) (target, start, x, y, width) )

/* glConvolutionFilter1D */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONFILTER1D) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
GdkGLProc    gdk_gl_get_glConvolutionFilter1D (void);
#define      gdk_gl_glConvolutionFilter1D(proc, target, internalformat, width, format, type, image) \
  ( ((GdkGLProc_GLCONVOLUTIONFILTER1D) (proc)) (target, internalformat, width, format, type, image) )

/* glConvolutionFilter2D */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONFILTER2D) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
GdkGLProc    gdk_gl_get_glConvolutionFilter2D (void);
#define      gdk_gl_glConvolutionFilter2D(proc, target, internalformat, width, height, format, type, image) \
  ( ((GdkGLProc_GLCONVOLUTIONFILTER2D) (proc)) (target, internalformat, width, height, format, type, image) )

/* glConvolutionParameterf */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONPARAMETERF) (GLenum target, GLenum pname, GLfloat params);
GdkGLProc    gdk_gl_get_glConvolutionParameterf (void);
#define      gdk_gl_glConvolutionParameterf(proc, target, pname, params) \
  ( ((GdkGLProc_GLCONVOLUTIONPARAMETERF) (proc)) (target, pname, params) )

/* glConvolutionParameterfv */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONPARAMETERFV) (GLenum target, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glConvolutionParameterfv (void);
#define      gdk_gl_glConvolutionParameterfv(proc, target, pname, params) \
  ( ((GdkGLProc_GLCONVOLUTIONPARAMETERFV) (proc)) (target, pname, params) )

/* glConvolutionParameteri */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONPARAMETERI) (GLenum target, GLenum pname, GLint params);
GdkGLProc    gdk_gl_get_nglConvolutionParameteri (void);
#define      gdk_gl_glConvolutionParameteri(proc, target, pname, params) \
  ( ((GdkGLProc_GLCONVOLUTIONPARAMETERI) (proc)) (target, pname, params) )

/* glConvolutionParameteriv */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONPARAMETERIV) (GLenum target, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glConvolutionParameteriv (void);
#define      gdk_gl_glConvolutionParameteriv(proc, target, pname, params) \
  ( ((GdkGLProc_GLCONVOLUTIONPARAMETERIV) (proc)) (target, pname, params) )

/* glCopyConvolutionFilter1D */
typedef void (APIENTRY * GdkGLProc_GLCOPYCONVOLUTIONFILTER1D) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GdkGLProc    gdk_gl_get_glCopyConvolutionFilter1D (void);
#define      gdk_gl_glCopyConvolutionFilter1D(proc, target, internalformat, x, y, width) \
  ( ((GdkGLProc_GLCOPYCONVOLUTIONFILTER1D) (proc)) (target, internalformat, x, y, width) )

/* glCopyConvolutionFilter2D */
typedef void (APIENTRY * GdkGLProc_GLCOPYCONVOLUTIONFILTER2D) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
GdkGLProc    gdk_gl_get_glCopyConvolutionFilter2D (void);
#define      gdk_gl_glCopyConvolutionFilter2D(proc, target, internalformat, x, y, width, height) \
  ( ((GdkGLProc_GLCOPYCONVOLUTIONFILTER2D) (proc)) (target, internalformat, x, y, width, height) )

/* glGetConvolutionFilter */
typedef void (APIENTRY * GdkGLProc_GLGETCONVOLUTIONFILTER) (GLenum target, GLenum format, GLenum type, GLvoid *image);
GdkGLProc    gdk_gl_get_glGetConvolutionFilter (void);
#define      gdk_gl_glGetConvolutionFilter(proc, target, format, type, image) \
  ( ((GdkGLProc_GLGETCONVOLUTIONFILTER) (proc)) (target, format, type, image) )

/* glGetConvolutionParameterfv */
typedef void (APIENTRY * GdkGLProc_GLGETCONVOLUTIONPARAMETERFV) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetConvolutionParameterfv (void);
#define      gdk_gl_glGetConvolutionParameterfv(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCONVOLUTIONPARAMETERFV) (proc)) (target, pname, params) )

/* glGetConvolutionParameteriv */
typedef void (APIENTRY * GdkGLProc_GLGETCONVOLUTIONPARAMETERIV) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetConvolutionParameteriv (void);
#define      gdk_gl_glGetConvolutionParameteriv(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCONVOLUTIONPARAMETERIV) (proc)) (target, pname, params) )

/* glGetSeparableFilter */
typedef void (APIENTRY * GdkGLProc_GLGETSEPARABLEFILTER) (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
GdkGLProc    gdk_gl_get_glGetSeparableFilter (void);
#define      gdk_gl_glGetSeparableFilter(proc, target, format, type, row, column, span) \
  ( ((GdkGLProc_GLGETSEPARABLEFILTER) (proc)) (target, format, type, row, column, span) )

/* glSeparableFilter2D */
typedef void (APIENTRY * GdkGLProc_GLSEPARABLEFILTER2D) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
GdkGLProc    gdk_gl_get_glSeparableFilter2D (void);
#define      gdk_gl_glSeparableFilter2D(proc, target, internalformat, width, height, format, type, row, column) \
  ( ((GdkGLProc_GLSEPARABLEFILTER2D) (proc)) (target, internalformat, width, height, format, type, row, column) )

/* glGetHistogram */
typedef void (APIENTRY * GdkGLProc_GLGETHISTOGRAM) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
GdkGLProc    gdk_gl_get_glGetHistogram (void);
#define      gdk_gl_glGetHistogram(proc, target, reset, format, type, values) \
  ( ((GdkGLProc_GLGETHISTOGRAM) (proc)) (target, reset, format, type, values) )

/* glGetHistogramParameterfv */
typedef void (APIENTRY * GdkGLProc_GLGETHISTOGRAMPARAMETERFV) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetHistogramParameterfv (void);
#define      gdk_gl_glGetHistogramParameterfv(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETHISTOGRAMPARAMETERFV) (proc)) (target, pname, params) )

/* glGetHistogramParameteriv */
typedef void (APIENTRY * GdkGLProc_GLGETHISTOGRAMPARAMETERIV) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetHistogramParameteriv (void);
#define      gdk_gl_glGetHistogramParameteriv(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETHISTOGRAMPARAMETERIV) (proc)) (target, pname, params) )

/* glGetMinmax */
typedef void (APIENTRY * GdkGLProc_GLGETMINMAX) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
GdkGLProc    gdk_gl_get_glGetMinmax (void);
#define      gdk_gl_glGetMinmax(proc, target, reset, format, type, values) \
  ( ((GdkGLProc_GLGETMINMAX) (proc)) (target, reset, format, type, values) )

/* glGetMinmaxParameterfv */
typedef void (APIENTRY * GdkGLProc_GLGETMINMAXPARAMETERFV) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetMinmaxParameterfv (void);
#define      gdk_gl_glGetMinmaxParameterfv(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETMINMAXPARAMETERFV) (proc)) (target, pname, params) )

/* glGetMinmaxParameteriv */
typedef void (APIENTRY * GdkGLProc_GLGETMINMAXPARAMETERIV) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetMinmaxParameteriv (void);
#define      gdk_gl_glGetMinmaxParameteriv(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETMINMAXPARAMETERIV) (proc)) (target, pname, params) )

/* glHistogram */
typedef void (APIENTRY * GdkGLProc_GLHISTOGRAM) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
GdkGLProc    gdk_gl_get_glHistogram (void);
#define      gdk_gl_glHistogram(proc, target, width, internalformat, sink) \
  ( ((GdkGLProc_GLHISTOGRAM) (proc)) (target, width, internalformat, sink) )

/* glMinmax */
typedef void (APIENTRY * GdkGLProc_GLMINMAX) (GLenum target, GLenum internalformat, GLboolean sink);
GdkGLProc    gdk_gl_get_glMinmax (void);
#define      gdk_gl_glMinmax(proc, target, internalformat, sink) \
  ( ((GdkGLProc_GLMINMAX) (proc)) (target, internalformat, sink) )

/* glResetHistogram */
typedef void (APIENTRY * GdkGLProc_GLRESETHISTOGRAM) (GLenum target);
GdkGLProc    gdk_gl_get_glResetHistogram (void);
#define      gdk_gl_glResetHistogram(proc, target) \
  ( ((GdkGLProc_GLRESETHISTOGRAM) (proc)) (target) )

/* glResetMinmax */
typedef void (APIENTRY * GdkGLProc_GLRESETMINMAX) (GLenum target);
GdkGLProc    gdk_gl_get_glResetMinmax (void);
#define      gdk_gl_glResetMinmax(proc, target) \
  ( ((GdkGLProc_GLRESETMINMAX) (proc)) (target) )

/* glTexImage3D */
typedef void (APIENTRY * GdkGLProc_GLTEXIMAGE3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GdkGLProc    gdk_gl_get_glTexImage3D (void);
#define      gdk_gl_glTexImage3D(proc, target, level, internalformat, width, height, depth, border, format, type, pixels) \
  ( ((GdkGLProc_GLTEXIMAGE3D) (proc)) (target, level, internalformat, width, height, depth, border, format, type, pixels) )

/* glTexSubImage3D */
typedef void (APIENTRY * GdkGLProc_GLTEXSUBIMAGE3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
GdkGLProc    gdk_gl_get_glTexSubImage3D (void);
#define      gdk_gl_glTexSubImage3D(proc, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) \
  ( ((GdkGLProc_GLTEXSUBIMAGE3D) (proc)) (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) )

/* glCopyTexSubImage3D */
typedef void (APIENTRY * GdkGLProc_GLCOPYTEXSUBIMAGE3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GdkGLProc    gdk_gl_get_glCopyTexSubImage3D (void);
#define      gdk_gl_glCopyTexSubImage3D(proc, target, level, xoffset, yoffset, zoffset, x, y, width, height) \
  ( ((GdkGLProc_GLCOPYTEXSUBIMAGE3D) (proc)) (target, level, xoffset, yoffset, zoffset, x, y, width, height) )

/* 
 * GL_VERSION_1_3
 */

/* glActiveTexture */
typedef void (APIENTRY * GdkGLProc_GLACTIVETEXTURE) (GLenum texture);
GdkGLProc    gdk_gl_get_glActiveTexture (void);
#define      gdk_gl_glActiveTexture(proc, texture) \
  ( ((GdkGLProc_GLACTIVETEXTURE) (proc)) (texture) )

/* glClientActiveTexture */
typedef void (APIENTRY * GdkGLProc_GLCLIENTACTIVETEXTURE) (GLenum texture);
GdkGLProc    gdk_gl_get_glClientActiveTexture (void);
#define      gdk_gl_glClientActiveTexture(proc, texture) \
  ( ((GdkGLProc_GLCLIENTACTIVETEXTURE) (proc)) (texture) )

/* glMultiTexCoord1d */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1D) (GLenum target, GLdouble s);
GdkGLProc    gdk_gl_get_glMultiTexCoord1d (void);
#define      gdk_gl_glMultiTexCoord1d(proc, target, s) \
  ( ((GdkGLProc_GLMULTITEXCOORD1D) (proc)) (target, s) )

/* glMultiTexCoord1dv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1DV) (GLenum target, const GLdouble *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord1dv (void);
#define      gdk_gl_glMultiTexCoord1dv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD1DV) (proc)) (target, v) )

/* glMultiTexCoord1f */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1F) (GLenum target, GLfloat s);
GdkGLProc    gdk_gl_get_glMultiTexCoord1f (void);
#define      gdk_gl_glMultiTexCoord1f(proc, target, s) \
  ( ((GdkGLProc_GLMULTITEXCOORD1F) (proc)) (target, s) )

/* glMultiTexCoord1fv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1FV) (GLenum target, const GLfloat *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord1fv (void);
#define      gdk_gl_glMultiTexCoord1fv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD1FV) (proc)) (target, v) )

/* glMultiTexCoord1i */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1I) (GLenum target, GLint s);
GdkGLProc    gdk_gl_get_glMultiTexCoord1i (void);
#define      gdk_gl_glMultiTexCoord1i(proc, target, s) \
  ( ((GdkGLProc_GLMULTITEXCOORD1I) (proc)) (target, s) )

/* glMultiTexCoord1iv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1IV) (GLenum target, const GLint *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord1iv (void);
#define      gdk_gl_glMultiTexCoord1iv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD1IV) (proc)) (target, v) )

/* glMultiTexCoord1s */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1S) (GLenum target, GLshort s);
GdkGLProc    gdk_gl_get_glMultiTexCoord1s (void);
#define      gdk_gl_glMultiTexCoord1s(proc, target, s) \
  ( ((GdkGLProc_GLMULTITEXCOORD1S) (proc)) (target, s) )

/* glMultiTexCoord1sv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1SV) (GLenum target, const GLshort *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord1sv (void);
#define      gdk_gl_glMultiTexCoord1sv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD1SV) (proc)) (target, v) )

/* glMultiTexCoord2d */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2D) (GLenum target, GLdouble s, GLdouble t);
GdkGLProc    gdk_gl_get_glMultiTexCoord2d (void);
#define      gdk_gl_glMultiTexCoord2d(proc, target, s, t) \
  ( ((GdkGLProc_GLMULTITEXCOORD2D) (proc)) (target, s, t) )

/* glMultiTexCoord2dv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2DV) (GLenum target, const GLdouble *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord2dv (void);
#define      gdk_gl_glMultiTexCoord2dv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD2DV) (proc)) (target, v) )

/* glMultiTexCoord2f */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2F) (GLenum target, GLfloat s, GLfloat t);
GdkGLProc    gdk_gl_get_glMultiTexCoord2f (void);
#define      gdk_gl_glMultiTexCoord2f(proc, target, s, t) \
  ( ((GdkGLProc_GLMULTITEXCOORD2F) (proc)) (target, s, t) )

/* glMultiTexCoord2fv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2FV) (GLenum target, const GLfloat *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord2fv (void);
#define      gdk_gl_glMultiTexCoord2fv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD2FV) (proc)) (target, v) )

/* glMultiTexCoord2i */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2I) (GLenum target, GLint s, GLint t);
GdkGLProc    gdk_gl_get_glMultiTexCoord2i (void);
#define      gdk_gl_glMultiTexCoord2i(proc, target, s, t) \
  ( ((GdkGLProc_GLMULTITEXCOORD2I) (proc)) (target, s, t) )

/* glMultiTexCoord2iv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2IV) (GLenum target, const GLint *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord2iv (void);
#define      gdk_gl_glMultiTexCoord2iv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD2IV) (proc)) (target, v) )

/* glMultiTexCoord2s */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2S) (GLenum target, GLshort s, GLshort t);
GdkGLProc    gdk_gl_get_glMultiTexCoord2s (void);
#define      gdk_gl_glMultiTexCoord2s(proc, target, s, t) \
  ( ((GdkGLProc_GLMULTITEXCOORD2S) (proc)) (target, s, t) )

/* glMultiTexCoord2sv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2SV) (GLenum target, const GLshort *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord2sv (void);
#define      gdk_gl_glMultiTexCoord2sv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD2SV) (proc)) (target, v) )

/* glMultiTexCoord3d */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3D) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
GdkGLProc    gdk_gl_get_glMultiTexCoord3d (void);
#define      gdk_gl_glMultiTexCoord3d(proc, target, s, t, r) \
  ( ((GdkGLProc_GLMULTITEXCOORD3D) (proc)) (target, s, t, r) )

/* glMultiTexCoord3dv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3DV) (GLenum target, const GLdouble *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord3dv (void);
#define      gdk_gl_glMultiTexCoord3dv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD3DV) (proc)) (target, v) )

/* glMultiTexCoord3f */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3F) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
GdkGLProc    gdk_gl_get_glMultiTexCoord3f (void);
#define      gdk_gl_glMultiTexCoord3f(proc, target, s, t, r) \
  ( ((GdkGLProc_GLMULTITEXCOORD3F) (proc)) (target, s, t, r) )

/* glMultiTexCoord3fv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3FV) (GLenum target, const GLfloat *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord3fv (void);
#define      gdk_gl_glMultiTexCoord3fv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD3FV) (proc)) (target, v) )

/* glMultiTexCoord3i */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3I) (GLenum target, GLint s, GLint t, GLint r);
GdkGLProc    gdk_gl_get_glMultiTexCoord3i (void);
#define      gdk_gl_glMultiTexCoord3i(proc, target, s, t, r) \
  ( ((GdkGLProc_GLMULTITEXCOORD3I) (proc)) (target, s, t, r) )

/* glMultiTexCoord3iv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3IV) (GLenum target, const GLint *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord3iv (void);
#define      gdk_gl_glMultiTexCoord3iv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD3IV) (proc)) (target, v) )

/* glMultiTexCoord3s */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3S) (GLenum target, GLshort s, GLshort t, GLshort r);
GdkGLProc    gdk_gl_get_glMultiTexCoord3s (void);
#define      gdk_gl_glMultiTexCoord3s(proc, target, s, t, r) \
  ( ((GdkGLProc_GLMULTITEXCOORD3S) (proc)) (target, s, t, r) )

/* glMultiTexCoord3sv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3SV) (GLenum target, const GLshort *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord3sv (void);
#define      gdk_gl_glMultiTexCoord3sv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD3SV) (proc)) (target, v) )

/* glMultiTexCoord4d */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4D) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GdkGLProc    gdk_gl_get_glMultiTexCoord4d (void);
#define      gdk_gl_glMultiTexCoord4d(proc, target, s, t, r, q) \
  ( ((GdkGLProc_GLMULTITEXCOORD4D) (proc)) (target, s, t, r, q) )

/* glMultiTexCoord4dv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4DV) (GLenum target, const GLdouble *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord4dv (void);
#define      gdk_gl_glMultiTexCoord4dv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD4DV) (proc)) (target, v) )

/* glMultiTexCoord4f */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4F) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GdkGLProc    gdk_gl_get_glMultiTexCoord4f (void);
#define      gdk_gl_glMultiTexCoord4f(proc, target, s, t, r, q) \
  ( ((GdkGLProc_GLMULTITEXCOORD4F) (proc)) (target, s, t, r, q) )

/* glMultiTexCoord4fv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4FV) (GLenum target, const GLfloat *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord4fv (void);
#define      gdk_gl_glMultiTexCoord4fv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD4FV) (proc)) (target, v) )

/* glMultiTexCoord4i */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4I) (GLenum target, GLint s, GLint t, GLint r, GLint q);
GdkGLProc    gdk_gl_get_glMultiTexCoord4i (void);
#define      gdk_gl_glMultiTexCoord4i(proc, target, s, t, r, q) \
  ( ((GdkGLProc_GLMULTITEXCOORD4I) (proc)) (target, s, t, r, q) )

/* glMultiTexCoord4iv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4IV) (GLenum target, const GLint *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord4iv (void);
#define      gdk_gl_glMultiTexCoord4iv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD4IV) (proc)) (target, v) )

/* glMultiTexCoord4s */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4S) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GdkGLProc    gdk_gl_get_glMultiTexCoord4s (void);
#define      gdk_gl_glMultiTexCoord4s(proc, target, s, t, r, q) \
  ( ((GdkGLProc_GLMULTITEXCOORD4S) (proc)) (target, s, t, r, q) )

/* glMultiTexCoord4sv */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4SV) (GLenum target, const GLshort *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord4sv (void);
#define      gdk_gl_glMultiTexCoord4sv(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD4SV) (proc)) (target, v) )

/* glLoadTransposeMatrixf */
typedef void (APIENTRY * GdkGLProc_GLLOADTRANSPOSEMATRIXF) (const GLfloat *m);
GdkGLProc    gdk_gl_get_glLoadTransposeMatrixf (void);
#define      gdk_gl_glLoadTransposeMatrixf(proc, m) \
  ( ((GdkGLProc_GLLOADTRANSPOSEMATRIXF) (proc)) (m) )

/* glLoadTransposeMatrixd */
typedef void (APIENTRY * GdkGLProc_GLLOADTRANSPOSEMATRIXD) (const GLdouble *m);
GdkGLProc    gdk_gl_get_glLoadTransposeMatrixd (void);
#define      gdk_gl_glLoadTransposeMatrixd(proc, m) \
  ( ((GdkGLProc_GLLOADTRANSPOSEMATRIXD) (proc)) (m) )

/* glMultTransposeMatrixf */
typedef void (APIENTRY * GdkGLProc_GLMULTTRANSPOSEMATRIXF) (const GLfloat *m);
GdkGLProc    gdk_gl_get_glMultTransposeMatrixf (void);
#define      gdk_gl_glMultTransposeMatrixf(proc, m) \
  ( ((GdkGLProc_GLMULTTRANSPOSEMATRIXF) (proc)) (m) )

/* glMultTransposeMatrixd */
typedef void (APIENTRY * GdkGLProc_GLMULTTRANSPOSEMATRIXD) (const GLdouble *m);
GdkGLProc    gdk_gl_get_glMultTransposeMatrixd (void);
#define      gdk_gl_glMultTransposeMatrixd(proc, m) \
  ( ((GdkGLProc_GLMULTTRANSPOSEMATRIXD) (proc)) (m) )

/* glSampleCoverage */
typedef void (APIENTRY * GdkGLProc_GLSAMPLECOVERAGE) (GLclampf value, GLboolean invert);
GdkGLProc    gdk_gl_get_glSampleCoverage (void);
#define      gdk_gl_glSampleCoverage(proc, value, invert) \
  ( ((GdkGLProc_GLSAMPLECOVERAGE) (proc)) (value, invert) )

/* glCompressedTexImage3D */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXIMAGE3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexImage3D (void);
#define      gdk_gl_glCompressedTexImage3D(proc, target, level, internalformat, width, height, depth, border, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXIMAGE3D) (proc)) (target, level, internalformat, width, height, depth, border, imageSize, data) )

/* glCompressedTexImage2D */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXIMAGE2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexImage2D (void);
#define      gdk_gl_glCompressedTexImage2D(proc, target, level, internalformat, width, height, border, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXIMAGE2D) (proc)) (target, level, internalformat, width, height, border, imageSize, data) )

/* glCompressedTexImage1D */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXIMAGE1D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexImage1D (void);
#define      gdk_gl_glCompressedTexImage1D(proc, target, level, internalformat, width, border, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXIMAGE1D) (proc)) (target, level, internalformat, width, border, imageSize, data) )

/* glCompressedTexSubImage3D */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexSubImage3D (void);
#define      gdk_gl_glCompressedTexSubImage3D(proc, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE3D) (proc)) (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) )

/* glCompressedTexSubImage2D */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexSubImage2D (void);
#define      gdk_gl_glCompressedTexSubImage2D(proc, target, level, xoffset, yoffset, width, height, format, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE2D) (proc)) (target, level, xoffset, yoffset, width, height, format, imageSize, data) )

/* glCompressedTexSubImage1D */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexSubImage1D (void);
#define      gdk_gl_glCompressedTexSubImage1D(proc, target, level, xoffset, width, format, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE1D) (proc)) (target, level, xoffset, width, format, imageSize, data) )

/* glGetCompressedTexImage */
typedef void (APIENTRY * GdkGLProc_GLGETCOMPRESSEDTEXIMAGE) (GLenum target, GLint level, void *img);
GdkGLProc    gdk_gl_get_glGetCompressedTexImage (void);
#define      gdk_gl_glGetCompressedTexImage(proc, target, level, img) \
  ( ((GdkGLProc_GLGETCOMPRESSEDTEXIMAGE) (proc)) (target, level, img) )

/* 
 * GL_VERSION_1_4
 */

/* glBlendFuncSeparate */
typedef void (APIENTRY * GdkGLProc_GLBLENDFUNCSEPARATE) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GdkGLProc    gdk_gl_get_glBlendFuncSeparate (void);
#define      gdk_gl_glBlendFuncSeparate(proc, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) \
  ( ((GdkGLProc_GLBLENDFUNCSEPARATE) (proc)) (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) )

/* glFogCoordf */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDF) (GLfloat coord);
GdkGLProc    gdk_gl_get_glFogCoordf (void);
#define      gdk_gl_glFogCoordf(proc, coord) \
  ( ((GdkGLProc_GLFOGCOORDF) (proc)) (coord) )

/* glFogCoordfv */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDFV) (const GLfloat *coord);
GdkGLProc    gdk_gl_get_glFogCoordfv (void);
#define      gdk_gl_glFogCoordfv(proc, coord) \
  ( ((GdkGLProc_GLFOGCOORDFV) (proc)) (coord) )

/* glFogCoordd */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDD) (GLdouble coord);
GdkGLProc    gdk_gl_get_glFogCoordd (void);
#define      gdk_gl_glFogCoordd(proc, coord) \
  ( ((GdkGLProc_GLFOGCOORDD) (proc)) (coord) )

/* glFogCoorddv */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDDV) (const GLdouble *coord);
GdkGLProc    gdk_gl_get_glFogCoorddv (void);
#define      gdk_gl_glFogCoorddv(proc, coord) \
  ( ((GdkGLProc_GLFOGCOORDDV) (proc)) (coord) )

/* glFogCoordPointer */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDPOINTER) (GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glFogCoordPointer (void);
#define      gdk_gl_glFogCoordPointer(proc, type, stride, pointer) \
  ( ((GdkGLProc_GLFOGCOORDPOINTER) (proc)) (type, stride, pointer) )

/* glMultiDrawArrays */
typedef void (APIENTRY * GdkGLProc_GLMULTIDRAWARRAYS) (GLenum mode, GLint *first, GLsizei *count, GLsizei primcount);
GdkGLProc    gdk_gl_get_glMultiDrawArrays (void);
#define      gdk_gl_glMultiDrawArrays(proc, mode, first, count, primcount) \
  ( ((GdkGLProc_GLMULTIDRAWARRAYS) (proc)) (mode, first, count, primcount) )

/* glMultiDrawElements */
typedef void (APIENTRY * GdkGLProc_GLMULTIDRAWELEMENTS) (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
GdkGLProc    gdk_gl_get_glMultiDrawElements (void);
#define      gdk_gl_glMultiDrawElements(proc, mode, count, type, indices, primcount) \
  ( ((GdkGLProc_GLMULTIDRAWELEMENTS) (proc)) (mode, count, type, indices, primcount) )

/* glPointParameterf */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERF) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glPointParameterf (void);
#define      gdk_gl_glPointParameterf(proc, pname, param) \
  ( ((GdkGLProc_GLPOINTPARAMETERF) (proc)) (pname, param) )

/* glPointParameterfv */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERFV) (GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glPointParameterfv (void);
#define      gdk_gl_glPointParameterfv(proc, pname, params) \
  ( ((GdkGLProc_GLPOINTPARAMETERFV) (proc)) (pname, params) )

/* glPointParameteri */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERI) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glPointParameteri (void);
#define      gdk_gl_glPointParameteri(proc, pname, param) \
  ( ((GdkGLProc_GLPOINTPARAMETERI) (proc)) (pname, param) )

/* glPointParameteriv */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERIV) (GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glPointParameteriv (void);
#define      gdk_gl_glPointParameteriv(proc, pname, params) \
  ( ((GdkGLProc_GLPOINTPARAMETERIV) (proc)) (pname, params) )

/* glSecondaryColor3b */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3B) (GLbyte red, GLbyte green, GLbyte blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3b (void);
#define      gdk_gl_glSecondaryColor3b(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3B) (proc)) (red, green, blue) )

/* glSecondaryColor3bv */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3BV) (const GLbyte *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3bv (void);
#define      gdk_gl_glSecondaryColor3bv(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3BV) (proc)) (v) )

/* glSecondaryColor3d */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3D) (GLdouble red, GLdouble green, GLdouble blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3d (void);
#define      gdk_gl_glSecondaryColor3d(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3D) (proc)) (red, green, blue) )

/* glSecondaryColor3dv */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3DV) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3dv (void);
#define      gdk_gl_glSecondaryColor3dv(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3DV) (proc)) (v) )

/* glSecondaryColor3f */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3F) (GLfloat red, GLfloat green, GLfloat blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3f (void);
#define      gdk_gl_glSecondaryColor3f(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3F) (proc)) (red, green, blue) )

/* glSecondaryColor3fv */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3FV) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3fv (void);
#define      gdk_gl_glSecondaryColor3fv(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3FV) (proc)) (v) )

/* glSecondaryColor3i */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3I) (GLint red, GLint green, GLint blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3i (void);
#define      gdk_gl_glSecondaryColor3i(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3I) (proc)) (red, green, blue) )

/* glSecondaryColor3iv */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3IV) (const GLint *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3iv (void);
#define      gdk_gl_glSecondaryColor3iv(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3IV) (proc)) (v) )

/* glSecondaryColor3s */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3S) (GLshort red, GLshort green, GLshort blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3s (void);
#define      gdk_gl_glSecondaryColor3s(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3S) (proc)) (red, green, blue) )

/* glSecondaryColor3sv */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3SV) (const GLshort *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3sv (void);
#define      gdk_gl_glSecondaryColor3sv(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3SV) (proc)) (v) )

/* glSecondaryColor3ub  */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3UB) (GLubyte red, GLubyte green, GLubyte blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3ub (void);
#define      gdk_gl_glSecondaryColor3ub(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3UB) (proc)) (red, green, blue) )

/* glSecondaryColor3ubv */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3UBV) (const GLubyte *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3ubv (void);
#define      gdk_gl_glSecondaryColor3ubv(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3UBV) (proc)) (v) )

/* glSecondaryColor3ui */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3UI) (GLuint red, GLuint green, GLuint blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3ui (void);
#define      gdk_gl_glSecondaryColor3ui(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3UI) (proc)) (red, green, blue) )

/* glSecondaryColor3uiv */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3UIV) (const GLuint *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3uiv (void);
#define      gdk_gl_glSecondaryColor3uiv(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3UIV) (proc)) (v) )

/* glSecondaryColor3us */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3US) (GLushort red, GLushort green, GLushort blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3us (void);
#define      gdk_gl_glSecondaryColor3us(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3US) (proc)) (red, green, blue) )

/* glSecondaryColor3usv */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3USV) (const GLushort *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3usv (void);
#define      gdk_gl_glSecondaryColor3usv(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3USV) (proc)) (v) )

/* glSecondaryColorPointer */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLORPOINTER) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glSecondaryColorPointer (void);
#define      gdk_gl_glSecondaryColorPointer(proc, size, type, stride, pointer) \
  ( ((GdkGLProc_GLSECONDARYCOLORPOINTER) (proc)) (size, type, stride, pointer) )

/* glWindowPos2d */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2D) (GLdouble x, GLdouble y);
GdkGLProc    gdk_gl_get_glWindowPos2d (void);
#define      gdk_gl_glWindowPos2d(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2D) (proc)) (x, y) )

/* glWindowPos2dv */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2DV) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glWindowPos2dv (void);
#define      gdk_gl_glWindowPos2dv(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2DV) (proc)) (v) )

/* glWindowPos2f */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2F) (GLfloat x, GLfloat y);
GdkGLProc    gdk_gl_get_glWindowPos2f (void);
#define      gdk_gl_glWindowPos2f(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2F) (proc)) (x, y) )

/* glWindowPos2fv */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2FV) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glWindowPos2fv (void);
#define      gdk_gl_glWindowPos2fv(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2FV) (proc)) (v) )

/* glWindowPos2i */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2I) (GLint x, GLint y);
GdkGLProc    gdk_gl_get_glWindowPos2i (void);
#define      gdk_gl_glWindowPos2i(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2I) (proc)) (x, y) )

/* glWindowPos2iv */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2IV) (const GLint *v);
GdkGLProc    gdk_gl_get_glWindowPos2iv (void);
#define      gdk_gl_glWindowPos2iv(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2IV) (proc)) (v) )

/* glWindowPos2s */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2S) (GLshort x, GLshort y);
GdkGLProc    gdk_gl_get_glWindowPos2s (void);
#define      gdk_gl_glWindowPos2s(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2S) (proc)) (x, y) )

/* glWindowPos2sv */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2SV) (const GLshort *v);
GdkGLProc    gdk_gl_get_glWindowPos2sv (void);
#define      gdk_gl_glWindowPos2sv(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2SV) (proc)) (v) )

/* glWindowPos3d */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3D) (GLdouble x, GLdouble y, GLdouble z);
GdkGLProc    gdk_gl_get_glWindowPos3d (void);
#define      gdk_gl_glWindowPos3d(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3D) (proc)) (x, y, z) )

/* glWindowPos3dv */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3DV) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glWindowPos3dv (void);
#define      gdk_gl_glWindowPos3dv(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3DV) (proc)) (v) )

/* glWindowPos3f */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3F) (GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glWindowPos3f (void);
#define      gdk_gl_glWindowPos3f(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3F) (proc)) (x, y, z) )

/* glWindowPos3fv */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3FV) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glWindowPos3fv (void);
#define      gdk_gl_glWindowPos3fv(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3FV) (proc)) (v) )

/* glWindowPos3i */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3I) (GLint x, GLint y, GLint z);
GdkGLProc    gdk_gl_get_glWindowPos3i (void);
#define      gdk_gl_glWindowPos3i(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3I) (proc)) (x, y, z) )

/* glWindowPos3iv */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3IV) (const GLint *v);
GdkGLProc    gdk_gl_get_glWindowPos3iv (void);
#define      gdk_gl_glWindowPos3iv(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3IV) (proc)) (v) )

/* glWindowPos3s */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3S) (GLshort x, GLshort y, GLshort z);
GdkGLProc    gdk_gl_get_glWindowPos3s (void);
#define      gdk_gl_glWindowPos3s(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3S) (proc)) (x, y, z) )

/* glWindowPos3sv */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3SV) (const GLshort *v);
GdkGLProc    gdk_gl_get_glWindowPos3sv (void);
#define      gdk_gl_glWindowPos3sv(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3SV) (proc)) (v) )

/* 
 * GL_ARB_multitexture
 */

/* glActiveTextureARB */
typedef void (APIENTRY * GdkGLProc_GLACTIVETEXTUREARB) (GLenum texture);
GdkGLProc    gdk_gl_get_glActiveTextureARB (void);
#define      gdk_gl_glActiveTextureARB(proc, texture) \
  ( ((GdkGLProc_GLACTIVETEXTUREARB) (proc)) (texture) )

/* glClientActiveTextureARB */
typedef void (APIENTRY * GdkGLProc_GLCLIENTACTIVETEXTUREARB) (GLenum texture);
GdkGLProc    gdk_gl_get_glClientActiveTextureARB (void);
#define      gdk_gl_glClientActiveTextureARB(proc, texture) \
  ( ((GdkGLProc_GLCLIENTACTIVETEXTUREARB) (proc)) (texture) )

/* glMultiTexCoord1dARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1DARB) (GLenum target, GLdouble s);
GdkGLProc    gdk_gl_get_glMultiTexCoord1dARB (void);
#define      gdk_gl_glMultiTexCoord1dARB(proc, target, s) \
  ( ((GdkGLProc_GLMULTITEXCOORD1DARB) (proc)) (target, s) )

/* glMultiTexCoord1dvARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1DVARB) (GLenum target, const GLdouble *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord1dvARB (void);
#define      gdk_gl_glMultiTexCoord1dvARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD1DVARB) (proc)) (target, v) )

/* glMultiTexCoord1fARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1FARB) (GLenum target, GLfloat s);
GdkGLProc    gdk_gl_get_glMultiTexCoord1fARB (void);
#define      gdk_gl_glMultiTexCoord1fARB(proc, target, s) \
  ( ((GdkGLProc_GLMULTITEXCOORD1FARB) (proc)) (target, s) )

/* glMultiTexCoord1fvARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1FVARB) (GLenum target, const GLfloat *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord1fvARB (void);
#define      gdk_gl_glMultiTexCoord1fvARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD1FVARB) (proc)) (target, v) )

/* glMultiTexCoord1iARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1IARB) (GLenum target, GLint s);
GdkGLProc    gdk_gl_get_glMultiTexCoord1iARB (void);
#define      gdk_gl_glMultiTexCoord1iARB(proc, target, s) \
  ( ((GdkGLProc_GLMULTITEXCOORD1IARB) (proc)) (target, s) )

/* glMultiTexCoord1ivARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1IVARB) (GLenum target, const GLint *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord1ivARB (void);
#define      gdk_gl_glMultiTexCoord1ivARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD1IVARB) (proc)) (target, v) )

/* glMultiTexCoord1sARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1SARB) (GLenum target, GLshort s);
GdkGLProc    gdk_gl_get_glMultiTexCoord1sARB (void);
#define      gdk_gl_glMultiTexCoord1sARB(proc, target, s) \
  ( ((GdkGLProc_GLMULTITEXCOORD1SARB) (proc)) (target, s) )

/* glMultiTexCoord1svARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD1SVARB) (GLenum target, const GLshort *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord1svARB (void);
#define      gdk_gl_glMultiTexCoord1svARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD1SVARB) (proc)) (target, v) )

/* glMultiTexCoord2dARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2DARB) (GLenum target, GLdouble s, GLdouble t);
GdkGLProc    gdk_gl_get_glMultiTexCoord2dARB (void);
#define      gdk_gl_glMultiTexCoord2dARB(proc, target, s, t) \
  ( ((GdkGLProc_GLMULTITEXCOORD2DARB) (proc)) (target, s, t) )

/* glMultiTexCoord2dvARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2DVARB) (GLenum target, const GLdouble *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord2dvARB (void);
#define      gdk_gl_glMultiTexCoord2dvARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD2DVARB) (proc)) (target, v) )

/* glMultiTexCoord2fARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2FARB) (GLenum target, GLfloat s, GLfloat t);
GdkGLProc    gdk_gl_get_glMultiTexCoord2fARB (void);
#define      gdk_gl_glMultiTexCoord2fARB(proc, target, s, t) \
  ( ((GdkGLProc_GLMULTITEXCOORD2FARB) (proc)) (target, s, t) )

/* glMultiTexCoord2fvARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2FVARB) (GLenum target, const GLfloat *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord2fvARB (void);
#define      gdk_gl_glMultiTexCoord2fvARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD2FVARB) (proc)) (target, v) )

/* glMultiTexCoord2iARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2IARB) (GLenum target, GLint s, GLint t);
GdkGLProc    gdk_gl_get_glMultiTexCoord2iARB (void);
#define      gdk_gl_glMultiTexCoord2iARB(proc, target, s, t) \
  ( ((GdkGLProc_GLMULTITEXCOORD2IARB) (proc)) (target, s, t) )

/* glMultiTexCoord2ivARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2IVARB) (GLenum target, const GLint *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord2ivARB (void);
#define      gdk_gl_glMultiTexCoord2ivARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD2IVARB) (proc)) (target, v) )

/* glMultiTexCoord2sARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2SARB) (GLenum target, GLshort s, GLshort t);
GdkGLProc    gdk_gl_get_glMultiTexCoord2sARB (void);
#define      gdk_gl_glMultiTexCoord2sARB(proc, target, s, t) \
  ( ((GdkGLProc_GLMULTITEXCOORD2SARB) (proc)) (target, s, t) )

/* glMultiTexCoord2svARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD2SVARB) (GLenum target, const GLshort *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord2svARB (void);
#define      gdk_gl_glMultiTexCoord2svARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD2SVARB) (proc)) (target, v) )

/* glMultiTexCoord3dARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3DARB) (GLenum target, GLdouble s, GLdouble t, GLdouble r);
GdkGLProc    gdk_gl_get_glMultiTexCoord3dARB (void);
#define      gdk_gl_glMultiTexCoord3dARB(proc, target, s, t, r) \
  ( ((GdkGLProc_GLMULTITEXCOORD3DARB) (proc)) (target, s, t, r) )

/* glMultiTexCoord3dvARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3DVARB) (GLenum target, const GLdouble *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord3dvARB (void);
#define      gdk_gl_glMultiTexCoord3dvARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD3DVARB) (proc)) (target, v) )

/* glMultiTexCoord3fARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3FARB) (GLenum target, GLfloat s, GLfloat t, GLfloat r);
GdkGLProc    gdk_gl_get_glMultiTexCoord3fARB (void);
#define      gdk_gl_glMultiTexCoord3fARB(proc, target, s, t, r) \
  ( ((GdkGLProc_GLMULTITEXCOORD3FARB) (proc)) (target, s, t, r) )

/* glMultiTexCoord3fvARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3FVARB) (GLenum target, const GLfloat *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord3fvARB (void);
#define      gdk_gl_glMultiTexCoord3fvARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD3FVARB) (proc)) (target, v) )

/* glMultiTexCoord3iARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3IARB) (GLenum target, GLint s, GLint t, GLint r);
GdkGLProc    gdk_gl_get_glMultiTexCoord3iARB (void);
#define      gdk_gl_glMultiTexCoord3iARB(proc, target, s, t, r) \
  ( ((GdkGLProc_GLMULTITEXCOORD3IARB) (proc)) (target, s, t, r) )

/* glMultiTexCoord3ivARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3IVARB) (GLenum target, const GLint *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord3ivARB (void);
#define      gdk_gl_glMultiTexCoord3ivARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD3IVARB) (proc)) (target, v) )

/* glMultiTexCoord3sARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3SARB) (GLenum target, GLshort s, GLshort t, GLshort r);
GdkGLProc    gdk_gl_get_glMultiTexCoord3sARB (void);
#define      gdk_gl_glMultiTexCoord3sARB(proc, target, s, t, r) \
  ( ((GdkGLProc_GLMULTITEXCOORD3SARB) (proc)) (target, s, t, r) )

/* glMultiTexCoord3svARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD3SVARB) (GLenum target, const GLshort *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord3svARB (void);
#define      gdk_gl_glMultiTexCoord3svARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD3SVARB) (proc)) (target, v) )

/* glMultiTexCoord4dARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4DARB) (GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GdkGLProc    gdk_gl_get_glMultiTexCoord4dARB (void);
#define      gdk_gl_glMultiTexCoord4dARB(proc, target, s, t, r, q) \
  ( ((GdkGLProc_GLMULTITEXCOORD4DARB) (proc)) (target, s, t, r, q) )

/* glMultiTexCoord4dvARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4DVARB) (GLenum target, const GLdouble *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord4dvARB (void);
#define      gdk_gl_glMultiTexCoord4dvARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD4DVARB) (proc)) (target, v) )

/* glMultiTexCoord4fARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4FARB) (GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GdkGLProc    gdk_gl_get_glMultiTexCoord4fARB (void);
#define      gdk_gl_glMultiTexCoord4fARB(proc, target, s, t, r, q) \
  ( ((GdkGLProc_GLMULTITEXCOORD4FARB) (proc)) (target, s, t, r, q) )

/* glMultiTexCoord4fvARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4FVARB) (GLenum target, const GLfloat *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord4fvARB (void);
#define      gdk_gl_glMultiTexCoord4fvARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD4FVARB) (proc)) (target, v) )

/* glMultiTexCoord4iARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4IARB) (GLenum target, GLint s, GLint t, GLint r, GLint q);
GdkGLProc    gdk_gl_get_glMultiTexCoord4iARB (void);
#define      gdk_gl_glMultiTexCoord4iARB(proc, target, s, t, r, q) \
  ( ((GdkGLProc_GLMULTITEXCOORD4IARB) (proc)) (target, s, t, r, q) )

/* glMultiTexCoord4ivARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4IVARB) (GLenum target, const GLint *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord4ivARB (void);
#define      gdk_gl_glMultiTexCoord4ivARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD4IVARB) (proc)) (target, v) )

/* glMultiTexCoord4sARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4SARB) (GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GdkGLProc    gdk_gl_get_glMultiTexCoord4sARB (void);
#define      gdk_gl_glMultiTexCoord4sARB(proc, target, s, t, r, q) \
  ( ((GdkGLProc_GLMULTITEXCOORD4SARB) (proc)) (target, s, t, r, q) )

/* glMultiTexCoord4svARB */
typedef void (APIENTRY * GdkGLProc_GLMULTITEXCOORD4SVARB) (GLenum target, const GLshort *v);
GdkGLProc    gdk_gl_get_glMultiTexCoord4svARB (void);
#define      gdk_gl_glMultiTexCoord4svARB(proc, target, v) \
  ( ((GdkGLProc_GLMULTITEXCOORD4SVARB) (proc)) (target, v) )

/* 
 * GL_ARB_transpose_matrix
 */

/* glLoadTransposeMatrixfARB */
typedef void (APIENTRY * GdkGLProc_GLLOADTRANSPOSEMATRIXFARB) (const GLfloat *m);
GdkGLProc    gdk_gl_get_glLoadTransposeMatrixfARB (void);
#define      gdk_gl_glLoadTransposeMatrixfARB(proc, m) \
  ( ((GdkGLProc_GLLOADTRANSPOSEMATRIXFARB) (proc)) (m) )

/* glLoadTransposeMatrixdARB */
typedef void (APIENTRY * GdkGLProc_GLLOADTRANSPOSEMATRIXDARB) (const GLdouble *m);
GdkGLProc    gdk_gl_get_glLoadTransposeMatrixdARB (void);
#define      gdk_gl_glLoadTransposeMatrixdARB(proc, m) \
  ( ((GdkGLProc_GLLOADTRANSPOSEMATRIXDARB) (proc)) (m) )

/* glMultTransposeMatrixfARB */
typedef void (APIENTRY * GdkGLProc_GLMULTTRANSPOSEMATRIXFARB) (const GLfloat *m);
GdkGLProc    gdk_gl_get_glMultTransposeMatrixfARB (void);
#define      gdk_gl_glMultTransposeMatrixfARB(proc, m) \
  ( ((GdkGLProc_GLMULTTRANSPOSEMATRIXFARB) (proc)) (m) )

/* glMultTransposeMatrixdARB */
typedef void (APIENTRY * GdkGLProc_GLMULTTRANSPOSEMATRIXDARB) (const GLdouble *m);
GdkGLProc    gdk_gl_get_glMultTransposeMatrixdARB (void);
#define      gdk_gl_glMultTransposeMatrixdARB(proc, m) \
  ( ((GdkGLProc_GLMULTTRANSPOSEMATRIXDARB) (proc)) (m) )

/* 
 * GL_ARB_multisample
 */

/* glSampleCoverageARB */
typedef void (APIENTRY * GdkGLProc_GLSAMPLECOVERAGEARB) (GLclampf value, GLboolean invert);
GdkGLProc    gdk_gl_get_glSampleCoverageARB (void);
#define      gdk_gl_glSampleCoverageARB(proc, value, invert) \
  ( ((GdkGLProc_GLSAMPLECOVERAGEARB) (proc)) (value, invert) )

/* 
 * GL_ARB_texture_compression
 */

/* glCompressedTexImage3DARB */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXIMAGE3DARB) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexImage3DARB (void);
#define      gdk_gl_glCompressedTexImage3DARB(proc, target, level, internalformat, width, height, depth, border, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXIMAGE3DARB) (proc)) (target, level, internalformat, width, height, depth, border, imageSize, data) )

/* glCompressedTexImage2DARB */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXIMAGE2DARB) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexImage2DARB (void);
#define      gdk_gl_glCompressedTexImage2DARB(proc, target, level, internalformat, width, height, border, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXIMAGE2DARB) (proc)) (target, level, internalformat, width, height, border, imageSize, data) )

/* glCompressedTexImage1DARB */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXIMAGE1DARB) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexImage1DARB (void);
#define      gdk_gl_glCompressedTexImage1DARB(proc, target, level, internalformat, width, border, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXIMAGE1DARB) (proc)) (target, level, internalformat, width, border, imageSize, data) )

/* glCompressedTexSubImage3DARB */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE3DARB) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexSubImage3DARB (void);
#define      gdk_gl_glCompressedTexSubImage3DARB(proc, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE3DARB) (proc)) (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) )

/* glCompressedTexSubImage2DARB */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE2DARB) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexSubImage2DARB (void);
#define      gdk_gl_glCompressedTexSubImage2DARB(proc, target, level, xoffset, yoffset, width, height, format, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE2DARB) (proc)) (target, level, xoffset, yoffset, width, height, format, imageSize, data) )

/* glCompressedTexSubImage1DARB */
typedef void (APIENTRY * GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE1DARB) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
GdkGLProc    gdk_gl_get_glCompressedTexSubImage1DARB (void);
#define      gdk_gl_glCompressedTexSubImage1DARB(proc, target, level, xoffset, width, format, imageSize, data) \
  ( ((GdkGLProc_GLCOMPRESSEDTEXSUBIMAGE1DARB) (proc)) (target, level, xoffset, width, format, imageSize, data) )

/* glGetCompressedTexImageARB */
typedef void (APIENTRY * GdkGLProc_GLGETCOMPRESSEDTEXIMAGEARB) (GLenum target, GLint level, void *img);
GdkGLProc    gdk_gl_get_glGetCompressedTexImageARB (void);
#define      gdk_gl_glGetCompressedTexImageARB(proc, target, level, img) \
  ( ((GdkGLProc_GLGETCOMPRESSEDTEXIMAGEARB) (proc)) (target, level, img) )

/* 
 * GL_ARB_point_parameters
 */

/* glPointParameterfARB */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERFARB) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glPointParameterfARB (void);
#define      gdk_gl_glPointParameterfARB(proc, pname, param) \
  ( ((GdkGLProc_GLPOINTPARAMETERFARB) (proc)) (pname, param) )

/* glPointParameterfvARB */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERFVARB) (GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glPointParameterfvARB (void);
#define      gdk_gl_glPointParameterfvARB(proc, pname, params) \
  ( ((GdkGLProc_GLPOINTPARAMETERFVARB) (proc)) (pname, params) )

/* 
 * GL_ARB_vertex_blend
 */

/* glWeightbvARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTBVARB) (GLint size, const GLbyte *weights);
GdkGLProc    gdk_gl_get_glWeightbvARB (void);
#define      gdk_gl_glWeightbvARB(proc, size, weights) \
  ( ((GdkGLProc_GLWEIGHTBVARB) (proc)) (size, weights) )

/* glWeightsvARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTSVARB) (GLint size, const GLshort *weights);
GdkGLProc    gdk_gl_get_glWeightsvARB (void);
#define      gdk_gl_glWeightsvARB(proc, size, weights) \
  ( ((GdkGLProc_GLWEIGHTSVARB) (proc)) (size, weights) )

/* glWeightivARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTIVARB) (GLint size, const GLint *weights);
GdkGLProc    gdk_gl_get_glWeightivARB (void);
#define      gdk_gl_glWeightivARB(proc, size, weights) \
  ( ((GdkGLProc_GLWEIGHTIVARB) (proc)) (size, weights) )

/* glWeightfvARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTFVARB) (GLint size, const GLfloat *weights);
GdkGLProc    gdk_gl_get_glWeightfvARB (void);
#define      gdk_gl_glWeightfvARB(proc, size, weights) \
  ( ((GdkGLProc_GLWEIGHTFVARB) (proc)) (size, weights) )

/* glWeightdvARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTDVARB) (GLint size, const GLdouble *weights);
GdkGLProc    gdk_gl_get_glWeightdvARB (void);
#define      gdk_gl_glWeightdvARB(proc, size, weights) \
  ( ((GdkGLProc_GLWEIGHTDVARB) (proc)) (size, weights) )

/* glWeightubvARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTUBVARB) (GLint size, const GLubyte *weights);
GdkGLProc    gdk_gl_get_glWeightubvARB (void);
#define      gdk_gl_glWeightubvARB(proc, size, weights) \
  ( ((GdkGLProc_GLWEIGHTUBVARB) (proc)) (size, weights) )

/* glWeightusvARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTUSVARB) (GLint size, const GLushort *weights);
GdkGLProc    gdk_gl_get_glWeightusvARB (void);
#define      gdk_gl_glWeightusvARB(proc, size, weights) \
  ( ((GdkGLProc_GLWEIGHTUSVARB) (proc)) (size, weights) )

/* glWeightuivARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTUIVARB) (GLint size, const GLuint *weights);
GdkGLProc    gdk_gl_get_glWeightuivARB (void);
#define      gdk_gl_glWeightuivARB(proc, size, weights) \
  ( ((GdkGLProc_GLWEIGHTUIVARB) (proc)) (size, weights) )

/* glWeightPointerARB */
typedef void (APIENTRY * GdkGLProc_GLWEIGHTPOINTERARB) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glWeightPointerARB (void);
#define      gdk_gl_glWeightPointerARB(proc, size, type, stride, pointer) \
  ( ((GdkGLProc_GLWEIGHTPOINTERARB) (proc)) (size, type, stride, pointer) )

/* glVertexBlendARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXBLENDARB) (GLint count);
GdkGLProc    gdk_gl_get_glVertexBlendARB (void);
#define      gdk_gl_glVertexBlendARB(proc, count) \
  ( ((GdkGLProc_GLVERTEXBLENDARB) (proc)) (count) )

/* 
 * GL_ARB_matrix_palette
 */

/* glCurrentPaletteMatrixARB */
typedef void (APIENTRY * GdkGLProc_GLCURRENTPALETTEMATRIXARB) (GLint index);
GdkGLProc    gdk_gl_get_glCurrentPaletteMatrixARB (void);
#define      gdk_gl_glCurrentPaletteMatrixARB(proc, index) \
  ( ((GdkGLProc_GLCURRENTPALETTEMATRIXARB) (proc)) (index) )

/* glMatrixIndexubvARB */
typedef void (APIENTRY * GdkGLProc_GLMATRIXINDEXUBVARB) (GLint size, const GLubyte *indices);
GdkGLProc    gdk_gl_get_glMatrixIndexubvARB (void);
#define      gdk_gl_glMatrixIndexubvARB(proc, size, indices) \
  ( ((GdkGLProc_GLMATRIXINDEXUBVARB) (proc)) (size, indices) )

/* glMatrixIndexusvARB */
typedef void (APIENTRY * GdkGLProc_GLMATRIXINDEXUSVARB) (GLint size, const GLushort *indices);
GdkGLProc    gdk_gl_get_glMatrixIndexusvARB (void);
#define      gdk_gl_glMatrixIndexusvARB(proc, size, indices) \
  ( ((GdkGLProc_GLMATRIXINDEXUSVARB) (proc)) (size, indices) )

/* glMatrixIndexuivARB */
typedef void (APIENTRY * GdkGLProc_GLMATRIXINDEXUIVARB) (GLint size, const GLuint *indices);
GdkGLProc    gdk_gl_get_glMatrixIndexuivARB (void);
#define      gdk_gl_glMatrixIndexuivARB(proc, size, indices) \
  ( ((GdkGLProc_GLMATRIXINDEXUIVARB) (proc)) (size, indices) )

/* glMatrixIndexPointerARB */
typedef void (APIENTRY * GdkGLProc_GLMATRIXINDEXPOINTERARB) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glMatrixIndexPointerARB (void);
#define      gdk_gl_glMatrixIndexPointerARB(proc, size, type, stride, pointer) \
  ( ((GdkGLProc_GLMATRIXINDEXPOINTERARB) (proc)) (size, type, stride, pointer) )

/* 
 * GL_ARB_window_pos
 */

/* glWindowPos2dARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2DARB) (GLdouble x, GLdouble y);
GdkGLProc    gdk_gl_get_glWindowPos2dARB (void);
#define      gdk_gl_glWindowPos2dARB(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2DARB) (proc)) (x, y) )

/* glWindowPos2dvARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2DVARB) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glWindowPos2dvARB (void);
#define      gdk_gl_glWindowPos2dvARB(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2DVARB) (proc)) (v) )

/* glWindowPos2fARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2FARB) (GLfloat x, GLfloat y);
GdkGLProc    gdk_gl_get_glWindowPos2fARB (void);
#define      gdk_gl_glWindowPos2fARB(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2FARB) (proc)) (x, y) )

/* glWindowPos2fvARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2FVARB) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glWindowPos2fvARB (void);
#define      gdk_gl_glWindowPos2fvARB(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2FVARB) (proc)) (v) )

/* glWindowPos2iARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2IARB) (GLint x, GLint y);
GdkGLProc    gdk_gl_get_glWindowPos2iARB (void);
#define      gdk_gl_glWindowPos2iARB(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2IARB) (proc)) (x, y) )

/* glWindowPos2ivARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2IVARB) (const GLint *v);
GdkGLProc    gdk_gl_get_glWindowPos2ivARB (void);
#define      gdk_gl_glWindowPos2ivARB(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2IVARB) (proc)) (v) )

/* glWindowPos2sARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2SARB) (GLshort x, GLshort y);
GdkGLProc    gdk_gl_get_glWindowPos2sARB (void);
#define      gdk_gl_glWindowPos2sARB(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2SARB) (proc)) (x, y) )

/* glWindowPos2svARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2SVARB) (const GLshort *v);
GdkGLProc    gdk_gl_get_glWindowPos2svARB (void);
#define      gdk_gl_glWindowPos2svARB(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2SVARB) (proc)) (v) )

/* glWindowPos3dARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3DARB) (GLdouble x, GLdouble y, GLdouble z);
GdkGLProc    gdk_gl_get_glWindowPos3dARB (void);
#define      gdk_gl_glWindowPos3dARB(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3DARB) (proc)) (x, y, z) )

/* glWindowPos3dvARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3DVARB) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glWindowPos3dvARB (void);
#define      gdk_gl_glWindowPos3dvARB(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3DVARB) (proc)) (v) )

/* glWindowPos3fARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3FARB) (GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glWindowPos3fARB (void);
#define      gdk_gl_glWindowPos3fARB(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3FARB) (proc)) (x, y, z) )

/* glWindowPos3fvARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3FVARB) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glWindowPos3fvARB (void);
#define      gdk_gl_glWindowPos3fvARB(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3FVARB) (proc)) (v) )

/* glWindowPos3iARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3IARB) (GLint x, GLint y, GLint z);
GdkGLProc    gdk_gl_get_glWindowPos3iARB (void);
#define      gdk_gl_glWindowPos3iARB(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3IARB) (proc)) (x, y, z) )

/* glWindowPos3ivARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3IVARB) (const GLint *v);
GdkGLProc    gdk_gl_get_glWindowPos3ivARB (void);
#define      gdk_gl_glWindowPos3ivARB(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3IVARB) (proc)) (v) )

/* glWindowPos3sARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3SARB) (GLshort x, GLshort y, GLshort z);
GdkGLProc    gdk_gl_get_glWindowPos3sARB (void);
#define      gdk_gl_glWindowPos3sARB(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3SARB) (proc)) (x, y, z) )

/* glWindowPos3svARB */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3SVARB) (const GLshort *v);
GdkGLProc    gdk_gl_get_glWindowPos3svARB (void);
#define      gdk_gl_glWindowPos3svARB(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3SVARB) (proc)) (v) )

/* 
 * GL_ARB_vertex_program
 */

/* glVertexAttrib1dARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1DARB) (GLuint index, GLdouble x);
GdkGLProc    gdk_gl_get_glVertexAttrib1dARB (void);
#define      gdk_gl_glVertexAttrib1dARB(proc, index, x) \
  ( ((GdkGLProc_GLVERTEXATTRIB1DARB) (proc)) (index, x) )

/* glVertexAttrib1dvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1DVARB) (GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttrib1dvARB (void);
#define      gdk_gl_glVertexAttrib1dvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB1DVARB) (proc)) (index, v) )

/* glVertexAttrib1fARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1FARB) (GLuint index, GLfloat x);
GdkGLProc    gdk_gl_get_glVertexAttrib1fARB (void);
#define      gdk_gl_glVertexAttrib1fARB(proc, index, x) \
  ( ((GdkGLProc_GLVERTEXATTRIB1FARB) (proc)) (index, x) )

/* glVertexAttrib1fvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1FVARB) (GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttrib1fvARB (void);
#define      gdk_gl_glVertexAttrib1fvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB1FVARB) (proc)) (index, v) )

/* glVertexAttrib1sARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1SARB) (GLuint index, GLshort x);
GdkGLProc    gdk_gl_get_glVertexAttrib1sARB (void);
#define      gdk_gl_glVertexAttrib1sARB(proc, index, x) \
  ( ((GdkGLProc_GLVERTEXATTRIB1SARB) (proc)) (index, x) )

/* glVertexAttrib1svARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1SVARB) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib1svARB (void);
#define      gdk_gl_glVertexAttrib1svARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB1SVARB) (proc)) (index, v) )

/* glVertexAttrib2dARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2DARB) (GLuint index, GLdouble x, GLdouble y);
GdkGLProc    gdk_gl_get_glVertexAttrib2dARB (void);
#define      gdk_gl_glVertexAttrib2dARB(proc, index, x, y) \
  ( ((GdkGLProc_GLVERTEXATTRIB2DARB) (proc)) (index, x, y) )

/* glVertexAttrib2dvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2DVARB) (GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttrib2dvARB (void);
#define      gdk_gl_glVertexAttrib2dvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB2DVARB) (proc)) (index, v) )

/* glVertexAttrib2fARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2FARB) (GLuint index, GLfloat x, GLfloat y);
GdkGLProc    gdk_gl_get_glVertexAttrib2fARB (void);
#define      gdk_gl_glVertexAttrib2fARB(proc, index, x, y) \
  ( ((GdkGLProc_GLVERTEXATTRIB2FARB) (proc)) (index, x, y) )

/* glVertexAttrib2fvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2FVARB) (GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttrib2fvARB (void);
#define      gdk_gl_glVertexAttrib2fvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB2FVARB) (proc)) (index, v) )

/* glVertexAttrib2sARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2SARB) (GLuint index, GLshort x, GLshort y);
GdkGLProc    gdk_gl_get_glVertexAttrib2sARB (void);
#define      gdk_gl_glVertexAttrib2sARB(proc, index, x, y) \
  ( ((GdkGLProc_GLVERTEXATTRIB2SARB) (proc)) (index, x, y) )

/* glVertexAttrib2svARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2SVARB) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib2svARB (void);
#define      gdk_gl_glVertexAttrib2svARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB2SVARB) (proc)) (index, v) )

/* glVertexAttrib3dARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3DARB) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GdkGLProc    gdk_gl_get_glVertexAttrib3dARB (void);
#define      gdk_gl_glVertexAttrib3dARB(proc, index, x, y, z) \
  ( ((GdkGLProc_GLVERTEXATTRIB3DARB) (proc)) (index, x, y, z) )

/* glVertexAttrib3dvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3DVARB) (GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttrib3dvARB (void);
#define      gdk_gl_glVertexAttrib3dvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB3DVARB) (proc)) (index, v) )

/* glVertexAttrib3fARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3FARB) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glVertexAttrib3fARB (void);
#define      gdk_gl_glVertexAttrib3fARB(proc, index, x, y, z) \
  ( ((GdkGLProc_GLVERTEXATTRIB3FARB) (proc)) (index, x, y, z) )

/* glVertexAttrib3fvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3FVARB) (GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttrib3fvARB (void);
#define      gdk_gl_glVertexAttrib3fvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB3FVARB) (proc)) (index, v) )

/* glVertexAttrib3sARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3SARB) (GLuint index, GLshort x, GLshort y, GLshort z);
GdkGLProc    gdk_gl_get_glVertexAttrib3sARB (void);
#define      gdk_gl_glVertexAttrib3sARB(proc, index, x, y, z) \
  ( ((GdkGLProc_GLVERTEXATTRIB3SARB) (proc)) (index, x, y, z) )

/* glVertexAttrib3svARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3SVARB) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib3svARB (void);
#define      gdk_gl_glVertexAttrib3svARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB3SVARB) (proc)) (index, v) )

/* glVertexAttrib4NbvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4NBVARB) (GLuint index, const GLbyte *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4NbvARB (void);
#define      gdk_gl_glVertexAttrib4NbvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4NBVARB) (proc)) (index, v) )

/* glVertexAttrib4NivARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4NIVARB) (GLuint index, const GLint *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4NivARB (void);
#define      gdk_gl_glVertexAttrib4NivARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4NIVARB) (proc)) (index, v) )

/* glVertexAttrib4NsvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4NSVARB) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4NsvARB (void);
#define      gdk_gl_glVertexAttrib4NsvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4NSVARB) (proc)) (index, v) )

/* glVertexAttrib4NubARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4NUBARB) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GdkGLProc    gdk_gl_get_glVertexAttrib4NubARB (void);
#define      gdk_gl_glVertexAttrib4NubARB(proc, index, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXATTRIB4NUBARB) (proc)) (index, x, y, z, w) )

/* glVertexAttrib4NubvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4NUBVARB) (GLuint index, const GLubyte *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4NubvARB (void);
#define      gdk_gl_glVertexAttrib4NubvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4NUBVARB) (proc)) (index, v) )

/* glVertexAttrib4NuivARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4NUIVARB) (GLuint index, const GLuint *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4NuivARB (void);
#define      gdk_gl_glVertexAttrib4NuivARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4NUIVARB) (proc)) (index, v) )

/* glVertexAttrib4NusvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4NUSVARB) (GLuint index, const GLushort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4NusvARB (void);
#define      gdk_gl_glVertexAttrib4NusvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4NUSVARB) (proc)) (index, v) )

/* glVertexAttrib4bvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4BVARB) (GLuint index, const GLbyte *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4bvARB (void);
#define      gdk_gl_glVertexAttrib4bvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4BVARB) (proc)) (index, v) )

/* glVertexAttrib4dARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4DARB) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GdkGLProc    gdk_gl_get_glVertexAttrib4dARB (void);
#define      gdk_gl_glVertexAttrib4dARB(proc, index, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXATTRIB4DARB) (proc)) (index, x, y, z, w) )

/* glVertexAttrib4dvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4DVARB) (GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4dvARB (void);
#define      gdk_gl_glVertexAttrib4dvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4DVARB) (proc)) (index, v) )

/* glVertexAttrib4fARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4FARB) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glVertexAttrib4fARB (void);
#define      gdk_gl_glVertexAttrib4fARB(proc, index, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXATTRIB4FARB) (proc)) (index, x, y, z, w) )

/* glVertexAttrib4fvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4FVARB) (GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4fvARB (void);
#define      gdk_gl_glVertexAttrib4fvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4FVARB) (proc)) (index, v) )

/* glVertexAttrib4ivARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4IVARB) (GLuint index, const GLint *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4ivARB (void);
#define      gdk_gl_glVertexAttrib4ivARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4IVARB) (proc)) (index, v) )

/* glVertexAttrib4sARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4SARB) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GdkGLProc    gdk_gl_get_glVertexAttrib4sARB (void);
#define      gdk_gl_glVertexAttrib4sARB(proc, index, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXATTRIB4SARB) (proc)) (index, x, y, z, w) )

/* glVertexAttrib4svARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4SVARB) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4svARB (void);
#define      gdk_gl_glVertexAttrib4svARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4SVARB) (proc)) (index, v) )

/* glVertexAttrib4ubvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4UBVARB) (GLuint index, const GLubyte *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4ubvARB (void);
#define      gdk_gl_glVertexAttrib4ubvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4UBVARB) (proc)) (index, v) )

/* glVertexAttrib4uivARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4UIVARB) (GLuint index, const GLuint *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4uivARB (void);
#define      gdk_gl_glVertexAttrib4uivARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4UIVARB) (proc)) (index, v) )

/* glVertexAttrib4usvARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4USVARB) (GLuint index, const GLushort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4usvARB (void);
#define      gdk_gl_glVertexAttrib4usvARB(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4USVARB) (proc)) (index, v) )

/* glVertexAttribPointerARB */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBPOINTERARB) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glVertexAttribPointerARB (void);
#define      gdk_gl_glVertexAttribPointerARB(proc, index, size, type, normalized, stride, pointer) \
  ( ((GdkGLProc_GLVERTEXATTRIBPOINTERARB) (proc)) (index, size, type, normalized, stride, pointer) )

/* glEnableVertexAttribArrayARB */
typedef void (APIENTRY * GdkGLProc_GLENABLEVERTEXATTRIBARRAYARB) (GLuint index);
GdkGLProc    gdk_gl_get_glEnableVertexAttribArrayARB (void);
#define      gdk_gl_glEnableVertexAttribArrayARB(proc, index) \
  ( ((GdkGLProc_GLENABLEVERTEXATTRIBARRAYARB) (proc)) (index) )

/* glDisableVertexAttribArrayARB */
typedef void (APIENTRY * GdkGLProc_GLDISABLEVERTEXATTRIBARRAYARB) (GLuint index);
GdkGLProc    gdk_gl_get_glDisableVertexAttribArrayARB (void);
#define      gdk_gl_glDisableVertexAttribArrayARB(proc, index) \
  ( ((GdkGLProc_GLDISABLEVERTEXATTRIBARRAYARB) (proc)) (index) )

/* glProgramStringARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMSTRINGARB) (GLenum target, GLenum format, GLsizei len, const GLvoid *string);
GdkGLProc    gdk_gl_get_glProgramStringARB (void);
#define      gdk_gl_glProgramStringARB(proc, target, format, len, string) \
  ( ((GdkGLProc_GLPROGRAMSTRINGARB) (proc)) (target, format, len, string) )

/* glBindProgramARB */
typedef void (APIENTRY * GdkGLProc_GLBINDPROGRAMARB) (GLenum target, GLuint program);
GdkGLProc    gdk_gl_get_glBindProgramARB (void);
#define      gdk_gl_glBindProgramARB(proc, target, program) \
  ( ((GdkGLProc_GLBINDPROGRAMARB) (proc)) (target, program) )

/* glDeleteProgramsARB */
typedef void (APIENTRY * GdkGLProc_GLDELETEPROGRAMSARB) (GLsizei n, const GLuint *programs);
GdkGLProc    gdk_gl_get_glDeleteProgramsARB (void);
#define      gdk_gl_glDeleteProgramsARB(proc, n, programs) \
  ( ((GdkGLProc_GLDELETEPROGRAMSARB) (proc)) (n, programs) )

/* glGenProgramsARB */
typedef void (APIENTRY * GdkGLProc_GLGENPROGRAMSARB) (GLsizei n, GLuint *programs);
GdkGLProc    gdk_gl_get_glGenProgramsARB (void);
#define      gdk_gl_glGenProgramsARB(proc, n, programs) \
  ( ((GdkGLProc_GLGENPROGRAMSARB) (proc)) (n, programs) )

/* glProgramEnvParameter4dARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMENVPARAMETER4DARB) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GdkGLProc    gdk_gl_get_glProgramEnvParameter4dARB (void);
#define      gdk_gl_glProgramEnvParameter4dARB(proc, target, index, x, y, z, w) \
  ( ((GdkGLProc_GLPROGRAMENVPARAMETER4DARB) (proc)) (target, index, x, y, z, w) )

/* glProgramEnvParameter4dvARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMENVPARAMETER4DVARB) (GLenum target, GLuint index, const GLdouble *params);
GdkGLProc    gdk_gl_get_glProgramEnvParameter4dvARB (void);
#define      gdk_gl_glProgramEnvParameter4dvARB(proc, target, index, params) \
  ( ((GdkGLProc_GLPROGRAMENVPARAMETER4DVARB) (proc)) (target, index, params) )

/* glProgramEnvParameter4fARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMENVPARAMETER4FARB) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glProgramEnvParameter4fARB (void);
#define      gdk_gl_glProgramEnvParameter4fARB(proc, target, index, x, y, z, w) \
  ( ((GdkGLProc_GLPROGRAMENVPARAMETER4FARB) (proc)) (target, index, x, y, z, w) )

/* glProgramEnvParameter4fvARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMENVPARAMETER4FVARB) (GLenum target, GLuint index, const GLfloat *params);
GdkGLProc    gdk_gl_get_glProgramEnvParameter4fvARB (void);
#define      gdk_gl_glProgramEnvParameter4fvARB(proc, target, index, params) \
  ( ((GdkGLProc_GLPROGRAMENVPARAMETER4FVARB) (proc)) (target, index, params) )

/* glProgramLocalParameter4dARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMLOCALPARAMETER4DARB) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GdkGLProc    gdk_gl_get_glProgramLocalParameter4dARB (void);
#define      gdk_gl_glProgramLocalParameter4dARB(proc, target, index, x, y, z, w) \
  ( ((GdkGLProc_GLPROGRAMLOCALPARAMETER4DARB) (proc)) (target, index, x, y, z, w) )

/* glProgramLocalParameter4dvARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMLOCALPARAMETER4DVARB) (GLenum target, GLuint index, const GLdouble *params);
GdkGLProc    gdk_gl_get_glProgramLocalParameter4dvARB (void);
#define      gdk_gl_glProgramLocalParameter4dvARB(proc, target, index, params) \
  ( ((GdkGLProc_GLPROGRAMLOCALPARAMETER4DVARB) (proc)) (target, index, params) )

/* glProgramLocalParameter4fARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMLOCALPARAMETER4FARB) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glProgramLocalParameter4fARB (void);
#define      gdk_gl_glProgramLocalParameter4fARB(proc, target, index, x, y, z, w) \
  ( ((GdkGLProc_GLPROGRAMLOCALPARAMETER4FARB) (proc)) (target, index, x, y, z, w) )

/* glProgramLocalParameter4fvARB */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMLOCALPARAMETER4FVARB) (GLenum target, GLuint index, const GLfloat *params);
GdkGLProc    gdk_gl_get_glProgramLocalParameter4fvARB (void);
#define      gdk_gl_glProgramLocalParameter4fvARB(proc, target, index, params) \
  ( ((GdkGLProc_GLPROGRAMLOCALPARAMETER4FVARB) (proc)) (target, index, params) )

/* glGetProgramEnvParameterdvARB */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMENVPARAMETERDVARB) (GLenum target, GLuint index, GLdouble *params);
GdkGLProc    gdk_gl_get_glGetProgramEnvParameterdvARB (void);
#define      gdk_gl_glGetProgramEnvParameterdvARB(proc, target, index, params) \
  ( ((GdkGLProc_GLGETPROGRAMENVPARAMETERDVARB) (proc)) (target, index, params) )

/* glGetProgramEnvParameterfvARB */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMENVPARAMETERFVARB) (GLenum target, GLuint index, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetProgramEnvParameterfvARB (void);
#define      gdk_gl_glGetProgramEnvParameterfvARB(proc, target, index, params) \
  ( ((GdkGLProc_GLGETPROGRAMENVPARAMETERFVARB) (proc)) (target, index, params) )

/* glGetProgramLocalParameterdvARB */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMLOCALPARAMETERDVARB) (GLenum target, GLuint index, GLdouble *params);
GdkGLProc    gdk_gl_get_glGetProgramLocalParameterdvARB (void);
#define      gdk_gl_glGetProgramLocalParameterdvARB(proc, target, index, params) \
  ( ((GdkGLProc_GLGETPROGRAMLOCALPARAMETERDVARB) (proc)) (target, index, params) )

/* glGetProgramLocalParameterfvARB */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMLOCALPARAMETERFVARB) (GLenum target, GLuint index, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetProgramLocalParameterfvARB (void);
#define      gdk_gl_glGetProgramLocalParameterfvARB(proc, target, index, params) \
  ( ((GdkGLProc_GLGETPROGRAMLOCALPARAMETERFVARB) (proc)) (target, index, params) )

/* glGetProgramivARB */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMIVARB) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetProgramivARB (void);
#define      gdk_gl_glGetProgramivARB(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETPROGRAMIVARB) (proc)) (target, pname, params) )

/* glGetProgramStringARB */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMSTRINGARB) (GLenum target, GLenum pname, GLvoid *string);
GdkGLProc    gdk_gl_get_glGetProgramStringARB (void);
#define      gdk_gl_glGetProgramStringARB(proc, target, pname, string) \
  ( ((GdkGLProc_GLGETPROGRAMSTRINGARB) (proc)) (target, pname, string) )

/* glGetVertexAttribdvARB */
typedef void (APIENTRY * GdkGLProc_GLGETVERTEXATTRIBDVARB) (GLuint index, GLenum pname, GLdouble *params);
GdkGLProc    gdk_gl_get_glGetVertexAttribdvARB (void);
#define      gdk_gl_glGetVertexAttribdvARB(proc, index, pname, params) \
  ( ((GdkGLProc_GLGETVERTEXATTRIBDVARB) (proc)) (index, pname, params) )

/* glGetVertexAttribfvARB */
typedef void (APIENTRY * GdkGLProc_GLGETVERTEXATTRIBFVARB) (GLuint index, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetVertexAttribfvARB (void);
#define      gdk_gl_glGetVertexAttribfvARB(proc, index, pname, params) \
  ( ((GdkGLProc_GLGETVERTEXATTRIBFVARB) (proc)) (index, pname, params) )

/* glGetVertexAttribivARB */
typedef void (APIENTRY * GdkGLProc_GLGETVERTEXATTRIBIVARB) (GLuint index, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetVertexAttribivARB (void);
#define      gdk_gl_glGetVertexAttribivARB(proc, index, pname, params) \
  ( ((GdkGLProc_GLGETVERTEXATTRIBIVARB) (proc)) (index, pname, params) )

/* glGetVertexAttribPointervARB */
typedef void (APIENTRY * GdkGLProc_GLGETVERTEXATTRIBPOINTERVARB) (GLuint index, GLenum pname, GLvoid* *pointer);
GdkGLProc    gdk_gl_get_glGetVertexAttribPointervARB (void);
#define      gdk_gl_glGetVertexAttribPointervARB(proc, index, pname, pointer) \
  ( ((GdkGLProc_GLGETVERTEXATTRIBPOINTERVARB) (proc)) (index, pname, pointer) )

/* glIsProgramARB */
typedef GLboolean (APIENTRY * GdkGLProc_GLISPROGRAMARB) (GLuint program);
GdkGLProc    gdk_gl_get_glIsProgramARB (void);
#define      gdk_gl_glIsProgramARB(proc, program) \
  ( ((GdkGLProc_GLISPROGRAMARB) (proc)) (program) )

/* 
 * GL_EXT_blend_color
 */

/* glBlendColorEXT */
typedef void (APIENTRY * GdkGLProc_GLBLENDCOLOREXT) (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
GdkGLProc    gdk_gl_get_glBlendColorEXT (void);
#define      gdk_gl_glBlendColorEXT(proc, red, green, blue, alpha) \
  ( ((GdkGLProc_GLBLENDCOLOREXT) (proc)) (red, green, blue, alpha) )

/* 
 * GL_EXT_polygon_offset
 */

/* glPolygonOffsetEXT */
typedef void (APIENTRY * GdkGLProc_GLPOLYGONOFFSETEXT) (GLfloat factor, GLfloat bias);
GdkGLProc    gdk_gl_get_glPolygonOffsetEXT (void);
#define      gdk_gl_glPolygonOffsetEXT(proc, factor, bias) \
  ( ((GdkGLProc_GLPOLYGONOFFSETEXT) (proc)) (factor, bias) )

/* 
 * GL_EXT_texture3D
 */

/* glTexImage3DEXT */
typedef void (APIENTRY * GdkGLProc_GLTEXIMAGE3DEXT) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GdkGLProc    gdk_gl_get_glTexImage3DEXT (void);
#define      gdk_gl_glTexImage3DEXT(proc, target, level, internalformat, width, height, depth, border, format, type, pixels) \
  ( ((GdkGLProc_GLTEXIMAGE3DEXT) (proc)) (target, level, internalformat, width, height, depth, border, format, type, pixels) )

/* glTexSubImage3DEXT */
typedef void (APIENTRY * GdkGLProc_GLTEXSUBIMAGE3DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
GdkGLProc    gdk_gl_get_glTexSubImage3DEXT (void);
#define      gdk_gl_glTexSubImage3DEXT(proc, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) \
  ( ((GdkGLProc_GLTEXSUBIMAGE3DEXT) (proc)) (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) )

/* 
 * GL_SGIS_texture_filter4
 */

/* glGetTexFilterFuncSGIS */
typedef void (APIENTRY * GdkGLProc_GLGETTEXFILTERFUNCSGIS) (GLenum target, GLenum filter, GLfloat *weights);
GdkGLProc    gdk_gl_get_glGetTexFilterFuncSGIS (void);
#define      gdk_gl_glGetTexFilterFuncSGIS(proc, target, filter, weights) \
  ( ((GdkGLProc_GLGETTEXFILTERFUNCSGIS) (proc)) (target, filter, weights) )

/* glTexFilterFuncSGIS */
typedef void (APIENTRY * GdkGLProc_GLTEXFILTERFUNCSGIS) (GLenum target, GLenum filter, GLsizei n, const GLfloat *weights);
GdkGLProc    gdk_gl_get_glTexFilterFuncSGIS (void);
#define      gdk_gl_glTexFilterFuncSGIS(proc, target, filter, n, weights) \
  ( ((GdkGLProc_GLTEXFILTERFUNCSGIS) (proc)) (target, filter, n, weights) )

/* 
 * GL_EXT_subtexture
 */

/* glTexSubImage1DEXT */
typedef void (APIENTRY * GdkGLProc_GLTEXSUBIMAGE1DEXT) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
GdkGLProc    gdk_gl_get_glTexSubImage1DEXT (void);
#define      gdk_gl_glTexSubImage1DEXT(proc, target, level, xoffset, width, format, type, pixels) \
  ( ((GdkGLProc_GLTEXSUBIMAGE1DEXT) (proc)) (target, level, xoffset, width, format, type, pixels) )

/* glTexSubImage2DEXT */
typedef void (APIENTRY * GdkGLProc_GLTEXSUBIMAGE2DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
GdkGLProc    gdk_gl_get_glTexSubImage2DEXT (void);
#define      gdk_gl_glTexSubImage2DEXT(proc, target, level, xoffset, yoffset, width, height, format, type, pixels) \
  ( ((GdkGLProc_GLTEXSUBIMAGE2DEXT) (proc)) (target, level, xoffset, yoffset, width, height, format, type, pixels) )

/* 
 * GL_EXT_copy_texture
 */

/* glCopyTexImage1DEXT */
typedef void (APIENTRY * GdkGLProc_GLCOPYTEXIMAGE1DEXT) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GdkGLProc    gdk_gl_get_glCopyTexImage1DEXT (void);
#define      gdk_gl_glCopyTexImage1DEXT(proc, target, level, internalformat, x, y, width, border) \
  ( ((GdkGLProc_GLCOPYTEXIMAGE1DEXT) (proc)) (target, level, internalformat, x, y, width, border) )

/* glCopyTexImage2DEXT */
typedef void (APIENTRY * GdkGLProc_GLCOPYTEXIMAGE2DEXT) (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GdkGLProc    gdk_gl_get_glCopyTexImage2DEXT (void);
#define      gdk_gl_glCopyTexImage2DEXT(proc, target, level, internalformat, x, y, width, height, border) \
  ( ((GdkGLProc_GLCOPYTEXIMAGE2DEXT) (proc)) (target, level, internalformat, x, y, width, height, border) )

/* glCopyTexSubImage1DEXT */
typedef void (APIENTRY * GdkGLProc_GLCOPYTEXSUBIMAGE1DEXT) (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GdkGLProc    gdk_gl_get_glCopyTexSubImage1DEXT (void);
#define      gdk_gl_glCopyTexSubImage1DEXT(proc, target, level, xoffset, x, y, width) \
  ( ((GdkGLProc_GLCOPYTEXSUBIMAGE1DEXT) (proc)) (target, level, xoffset, x, y, width) )

/* glCopyTexSubImage2DEXT */
typedef void (APIENTRY * GdkGLProc_GLCOPYTEXSUBIMAGE2DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GdkGLProc    gdk_gl_get_glCopyTexSubImage2DEXT (void);
#define      gdk_gl_glCopyTexSubImage2DEXT(proc, target, level, xoffset, yoffset, x, y, width, height) \
  ( ((GdkGLProc_GLCOPYTEXSUBIMAGE2DEXT) (proc)) (target, level, xoffset, yoffset, x, y, width, height) )

/* glCopyTexSubImage3DEXT */
typedef void (APIENTRY * GdkGLProc_GLCOPYTEXSUBIMAGE3DEXT) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GdkGLProc    gdk_gl_get_glCopyTexSubImage3DEXT (void);
#define      gdk_gl_glCopyTexSubImage3DEXT(proc, target, level, xoffset, yoffset, zoffset, x, y, width, height) \
  ( ((GdkGLProc_GLCOPYTEXSUBIMAGE3DEXT) (proc)) (target, level, xoffset, yoffset, zoffset, x, y, width, height) )

/* 
 * GL_EXT_histogram
 */

/* glGetHistogramEXT */
typedef void (APIENTRY * GdkGLProc_GLGETHISTOGRAMEXT) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
GdkGLProc    gdk_gl_get_glGetHistogramEXT (void);
#define      gdk_gl_glGetHistogramEXT(proc, target, reset, format, type, values) \
  ( ((GdkGLProc_GLGETHISTOGRAMEXT) (proc)) (target, reset, format, type, values) )

/* glGetHistogramParameterfvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETHISTOGRAMPARAMETERFVEXT) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetHistogramParameterfvEXT (void);
#define      gdk_gl_glGetHistogramParameterfvEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETHISTOGRAMPARAMETERFVEXT) (proc)) (target, pname, params) )

/* glGetHistogramParameterivEXT */
typedef void (APIENTRY * GdkGLProc_GLGETHISTOGRAMPARAMETERIVEXT) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetHistogramParameterivEXT (void);
#define      gdk_gl_glGetHistogramParameterivEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETHISTOGRAMPARAMETERIVEXT) (proc)) (target, pname, params) )

/* glGetMinmaxEXT */
typedef void (APIENTRY * GdkGLProc_GLGETMINMAXEXT) (GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
GdkGLProc    gdk_gl_get_glGetMinmaxEXT (void);
#define      gdk_gl_glGetMinmaxEXT(proc, target, reset, format, type, values) \
  ( ((GdkGLProc_GLGETMINMAXEXT) (proc)) (target, reset, format, type, values) )

/* glGetMinmaxParameterfvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETMINMAXPARAMETERFVEXT) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetMinmaxParameterfvEXT (void);
#define      gdk_gl_glGetMinmaxParameterfvEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETMINMAXPARAMETERFVEXT) (proc)) (target, pname, params) )

/* glGetMinmaxParameterivEXT */
typedef void (APIENTRY * GdkGLProc_GLGETMINMAXPARAMETERIVEXT) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetMinmaxParameterivEXT (void);
#define      gdk_gl_glGetMinmaxParameterivEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETMINMAXPARAMETERIVEXT) (proc)) (target, pname, params) )

/* glHistogramEXT */
typedef void (APIENTRY * GdkGLProc_GLHISTOGRAMEXT) (GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
GdkGLProc    gdk_gl_get_glHistogramEXT (void);
#define      gdk_gl_glHistogramEXT(proc, target, width, internalformat, sink) \
  ( ((GdkGLProc_GLHISTOGRAMEXT) (proc)) (target, width, internalformat, sink) )

/* glMinmaxEXT */
typedef void (APIENTRY * GdkGLProc_GLMINMAXEXT) (GLenum target, GLenum internalformat, GLboolean sink);
GdkGLProc    gdk_gl_get_glMinmaxEXT (void);
#define      gdk_gl_glMinmaxEXT(proc, target, internalformat, sink) \
  ( ((GdkGLProc_GLMINMAXEXT) (proc)) (target, internalformat, sink) )

/* glResetHistogramEXT */
typedef void (APIENTRY * GdkGLProc_GLRESETHISTOGRAMEXT) (GLenum target);
GdkGLProc    gdk_gl_get_glResetHistogramEXT (void);
#define      gdk_gl_glResetHistogramEXT(proc, target) \
  ( ((GdkGLProc_GLRESETHISTOGRAMEXT) (proc)) (target) )

/* glResetMinmaxEXT */
typedef void (APIENTRY * GdkGLProc_GLRESETMINMAXEXT) (GLenum target);
GdkGLProc    gdk_gl_get_glResetMinmaxEXT (void);
#define      gdk_gl_glResetMinmaxEXT(proc, target) \
  ( ((GdkGLProc_GLRESETMINMAXEXT) (proc)) (target) )

/* 
 * GL_EXT_convolution
 */

/* glConvolutionFilter1DEXT */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONFILTER1DEXT) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
GdkGLProc    gdk_gl_get_glConvolutionFilter1DEXT (void);
#define      gdk_gl_glConvolutionFilter1DEXT(proc, target, internalformat, width, format, type, image) \
  ( ((GdkGLProc_GLCONVOLUTIONFILTER1DEXT) (proc)) (target, internalformat, width, format, type, image) )

/* glConvolutionFilter2DEXT */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONFILTER2DEXT) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
GdkGLProc    gdk_gl_get_glConvolutionFilter2DEXT (void);
#define      gdk_gl_glConvolutionFilter2DEXT(proc, target, internalformat, width, height, format, type, image) \
  ( ((GdkGLProc_GLCONVOLUTIONFILTER2DEXT) (proc)) (target, internalformat, width, height, format, type, image) )

/* glConvolutionParameterfEXT */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONPARAMETERFEXT) (GLenum target, GLenum pname, GLfloat params);
GdkGLProc    gdk_gl_get_glConvolutionParameterfEXT (void);
#define      gdk_gl_glConvolutionParameterfEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLCONVOLUTIONPARAMETERFEXT) (proc)) (target, pname, params) )

/* glConvolutionParameterfvEXT */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONPARAMETERFVEXT) (GLenum target, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glConvolutionParameterfvEXT (void);
#define      gdk_gl_glConvolutionParameterfvEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLCONVOLUTIONPARAMETERFVEXT) (proc)) (target, pname, params) )

/* glConvolutionParameteriEXT */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONPARAMETERIEXT) (GLenum target, GLenum pname, GLint params);
GdkGLProc    gdk_gl_get_glConvolutionParameteriEXT (void);
#define      gdk_gl_glConvolutionParameteriEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLCONVOLUTIONPARAMETERIEXT) (proc)) (target, pname, params) )

/* glConvolutionParameterivEXT */
typedef void (APIENTRY * GdkGLProc_GLCONVOLUTIONPARAMETERIVEXT) (GLenum target, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glConvolutionParameterivEXT (void);
#define      gdk_gl_glConvolutionParameterivEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLCONVOLUTIONPARAMETERIVEXT) (proc)) (target, pname, params) )

/* glCopyConvolutionFilter1DEXT */
typedef void (APIENTRY * GdkGLProc_GLCOPYCONVOLUTIONFILTER1DEXT) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GdkGLProc    gdk_gl_get_glCopyConvolutionFilter1DEXT (void);
#define      gdk_gl_glCopyConvolutionFilter1DEXT(proc, target, internalformat, x, y, width) \
  ( ((GdkGLProc_GLCOPYCONVOLUTIONFILTER1DEXT) (proc)) (target, internalformat, x, y, width) )

/* glCopyConvolutionFilter2DEXT */
typedef void (APIENTRY * GdkGLProc_GLCOPYCONVOLUTIONFILTER2DEXT) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
GdkGLProc    gdk_gl_get_glCopyConvolutionFilter2DEXT (void);
#define      gdk_gl_glCopyConvolutionFilter2DEXT(proc, target, internalformat, x, y, width, height) \
  ( ((GdkGLProc_GLCOPYCONVOLUTIONFILTER2DEXT) (proc)) (target, internalformat, x, y, width, height) )

/* glGetConvolutionFilterEXT */
typedef void (APIENTRY * GdkGLProc_GLGETCONVOLUTIONFILTEREXT) (GLenum target, GLenum format, GLenum type, GLvoid *image);
GdkGLProc    gdk_gl_get_glGetConvolutionFilterEXT (void);
#define      gdk_gl_glGetConvolutionFilterEXT(proc, target, format, type, image) \
  ( ((GdkGLProc_GLGETCONVOLUTIONFILTEREXT) (proc)) (target, format, type, image) )

/* glGetConvolutionParameterfvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETCONVOLUTIONPARAMETERFVEXT) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetConvolutionParameterfvEXT (void);
#define      gdk_gl_glGetConvolutionParameterfvEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCONVOLUTIONPARAMETERFVEXT) (proc)) (target, pname, params) )

/* glGetConvolutionParameterivEXT */
typedef void (APIENTRY * GdkGLProc_GLGETCONVOLUTIONPARAMETERIVEXT) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetConvolutionParameterivEXT (void);
#define      gdk_gl_glGetConvolutionParameterivEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCONVOLUTIONPARAMETERIVEXT) (proc)) (target, pname, params) )

/* glGetSeparableFilterEXT */
typedef void (APIENTRY * GdkGLProc_GLGETSEPARABLEFILTEREXT) (GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
GdkGLProc    gdk_gl_get_glGetSeparableFilterEXT (void);
#define      gdk_gl_glGetSeparableFilterEXT(proc, target, format, type, row, column, span) \
  ( ((GdkGLProc_GLGETSEPARABLEFILTEREXT) (proc)) (target, format, type, row, column, span) )

/* glSeparableFilter2DEXT */
typedef void (APIENTRY * GdkGLProc_GLSEPARABLEFILTER2DEXT) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
GdkGLProc    gdk_gl_get_glSeparableFilter2DEXT (void);
#define      gdk_gl_glSeparableFilter2DEXT(proc, target, internalformat, width, height, format, type, row, column) \
  ( ((GdkGLProc_GLSEPARABLEFILTER2DEXT) (proc)) (target, internalformat, width, height, format, type, row, column) )

/* 
 * GL_SGI_color_table
 */

/* glColorTableSGI */
typedef void (APIENTRY * GdkGLProc_GLCOLORTABLESGI) (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
GdkGLProc    gdk_gl_get_glColorTableSGI (void);
#define      gdk_gl_glColorTableSGI(proc, target, internalformat, width, format, type, table) \
  ( ((GdkGLProc_GLCOLORTABLESGI) (proc)) (target, internalformat, width, format, type, table) )

/* glColorTableParameterfvSGI */
typedef void (APIENTRY * GdkGLProc_GLCOLORTABLEPARAMETERFVSGI) (GLenum target, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glColorTableParameterfvSGI (void);
#define      gdk_gl_glColorTableParameterfvSGI(proc, target, pname, params) \
  ( ((GdkGLProc_GLCOLORTABLEPARAMETERFVSGI) (proc)) (target, pname, params) )

/* glColorTableParameterivSGI */
typedef void (APIENTRY * GdkGLProc_GLCOLORTABLEPARAMETERIVSGI) (GLenum target, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glColorTableParameterivSGI (void);
#define      gdk_gl_glColorTableParameterivSGI(proc, target, pname, params) \
  ( ((GdkGLProc_GLCOLORTABLEPARAMETERIVSGI) (proc)) (target, pname, params) )

/* glCopyColorTableSGI */
typedef void (APIENTRY * GdkGLProc_GLCOPYCOLORTABLESGI) (GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
GdkGLProc    gdk_gl_get_glCopyColorTableSGI (void);
#define      gdk_gl_glCopyColorTableSGI(proc, target, internalformat, x, y, width) \
  ( ((GdkGLProc_GLCOPYCOLORTABLESGI) (proc)) (target, internalformat, x, y, width) )

/* glGetColorTableSGI */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLESGI) (GLenum target, GLenum format, GLenum type, GLvoid *table);
GdkGLProc    gdk_gl_get_glGetColorTableSGI (void);
#define      gdk_gl_glGetColorTableSGI(proc, target, format, type, table) \
  ( ((GdkGLProc_GLGETCOLORTABLESGI) (proc)) (target, format, type, table) )

/* glGetColorTableParameterfvSGI */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLEPARAMETERFVSGI) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetColorTableParameterfvSGI (void);
#define      gdk_gl_glGetColorTableParameterfvSGI(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCOLORTABLEPARAMETERFVSGI) (proc)) (target, pname, params) )

/* glGetColorTableParameterivSGI */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLEPARAMETERIVSGI) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetColorTableParameterivSGI (void);
#define      gdk_gl_glGetColorTableParameterivSGI(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCOLORTABLEPARAMETERIVSGI) (proc)) (target, pname, params) )

/* 
 * GL_SGIX_pixel_texture
 */

/* glPixelTexGenSGIX */
typedef void (APIENTRY * GdkGLProc_GLPIXELTEXGENSGIX) (GLenum mode);
GdkGLProc    gdk_gl_get_glPixelTexGenSGIX (void);
#define      gdk_gl_glPixelTexGenSGIX(proc, mode) \
  ( ((GdkGLProc_GLPIXELTEXGENSGIX) (proc)) (mode) )

/* 
 * GL_SGIS_pixel_texture
 */

/* glPixelTexGenParameteriSGIS */
typedef void (APIENTRY * GdkGLProc_GLPIXELTEXGENPARAMETERISGIS) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glPixelTexGenParameteriSGIS (void);
#define      gdk_gl_glPixelTexGenParameteriSGIS(proc, pname, param) \
  ( ((GdkGLProc_GLPIXELTEXGENPARAMETERISGIS) (proc)) (pname, param) )

/* glPixelTexGenParameterivSGIS */
typedef void (APIENTRY * GdkGLProc_GLPIXELTEXGENPARAMETERIVSGIS) (GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glPixelTexGenParameterivSGIS (void);
#define      gdk_gl_glPixelTexGenParameterivSGIS(proc, pname, params) \
  ( ((GdkGLProc_GLPIXELTEXGENPARAMETERIVSGIS) (proc)) (pname, params) )

/* glPixelTexGenParameterfSGIS */
typedef void (APIENTRY * GdkGLProc_GLPIXELTEXGENPARAMETERFSGIS) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glPixelTexGenParameterfSGIS (void);
#define      gdk_gl_glPixelTexGenParameterfSGIS(proc, pname, param) \
  ( ((GdkGLProc_GLPIXELTEXGENPARAMETERFSGIS) (proc)) (pname, param) )

/* glPixelTexGenParameterfvSGIS */
typedef void (APIENTRY * GdkGLProc_GLPIXELTEXGENPARAMETERFVSGIS) (GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glPixelTexGenParameterfvSGIS (void);
#define      gdk_gl_glPixelTexGenParameterfvSGIS(proc, pname, params) \
  ( ((GdkGLProc_GLPIXELTEXGENPARAMETERFVSGIS) (proc)) (pname, params) )

/* glGetPixelTexGenParameterivSGIS */
typedef void (APIENTRY * GdkGLProc_GLGETPIXELTEXGENPARAMETERIVSGIS) (GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetPixelTexGenParameterivSGIS (void);
#define      gdk_gl_glGetPixelTexGenParameterivSGIS(proc, pname, params) \
  ( ((GdkGLProc_GLGETPIXELTEXGENPARAMETERIVSGIS) (proc)) (pname, params) )

/* glGetPixelTexGenParameterfvSGIS */
typedef void (APIENTRY * GdkGLProc_GLGETPIXELTEXGENPARAMETERFVSGIS) (GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetPixelTexGenParameterfvSGIS (void);
#define      gdk_gl_glGetPixelTexGenParameterfvSGIS(proc, pname, params) \
  ( ((GdkGLProc_GLGETPIXELTEXGENPARAMETERFVSGIS) (proc)) (pname, params) )

/* 
 * GL_SGIS_texture4D
 */

/* glTexImage4DSGIS */
typedef void (APIENTRY * GdkGLProc_GLTEXIMAGE4DSGIS) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
GdkGLProc    gdk_gl_get_glTexImage4DSGIS (void);
#define      gdk_gl_glTexImage4DSGIS(proc, target, level, internalformat, width, height, depth, size4d, border, format, type, pixels) \
  ( ((GdkGLProc_GLTEXIMAGE4DSGIS) (proc)) (target, level, internalformat, width, height, depth, size4d, border, format, type, pixels) )

/* glTexSubImage4DSGIS */
typedef void (APIENTRY * GdkGLProc_GLTEXSUBIMAGE4DSGIS) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const GLvoid *pixels);
GdkGLProc    gdk_gl_get_glTexSubImage4DSGIS (void);
#define      gdk_gl_glTexSubImage4DSGIS(proc, target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels) \
  ( ((GdkGLProc_GLTEXSUBIMAGE4DSGIS) (proc)) (target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels) )

/* 
 * GL_EXT_texture_object
 */

/*  glAreTexturesResidentEXT */
typedef GLboolean (APIENTRY * GdkGLProc_GLARETEXTURESRESIDENTEXT) (GLsizei n, const GLuint *textures, GLboolean *residences);
GdkGLProc    gdk_gl_get_glAreTexturesResidentEXT (void);
#define      gdk_gl_glAreTexturesResidentEXT(proc, n, textures, residences) \
  ( ((GdkGLProc_GLARETEXTURESRESIDENTEXT) (proc)) (n, textures, residences) )

/* glBindTextureEXT */
typedef void (APIENTRY * GdkGLProc_GLBINDTEXTUREEXT) (GLenum target, GLuint texture);
GdkGLProc    gdk_gl_get_glBindTextureEXT (void);
#define      gdk_gl_glBindTextureEXT(proc, target, texture) \
  ( ((GdkGLProc_GLBINDTEXTUREEXT) (proc)) (target, texture) )

/* glDeleteTexturesEXT */
typedef void (APIENTRY * GdkGLProc_GLDELETETEXTURESEXT) (GLsizei n, const GLuint *textures);
GdkGLProc    gdk_gl_get_glDeleteTexturesEXT (void);
#define      gdk_gl_glDeleteTexturesEXT(proc, n, textures) \
  ( ((GdkGLProc_GLDELETETEXTURESEXT) (proc)) (n, textures) )

/* glGenTexturesEXT */
typedef void (APIENTRY * GdkGLProc_GLGENTEXTURESEXT) (GLsizei n, GLuint *textures);
GdkGLProc    gdk_gl_get_glGenTexturesEXT (void);
#define      gdk_gl_glGenTexturesEXT(proc, n, textures) \
  ( ((GdkGLProc_GLGENTEXTURESEXT) (proc)) (n, textures) )

/*  glIsTextureEXT */
typedef GLboolean (APIENTRY * GdkGLProc_GLISTEXTUREEXT) (GLuint texture);
GdkGLProc    gdk_gl_get_glIsTextureEXT (void);
#define      gdk_gl_glIsTextureEXT(proc, texture) \
  ( ((GdkGLProc_GLISTEXTUREEXT) (proc)) (texture) )

/* glPrioritizeTexturesEXT */
typedef void (APIENTRY * GdkGLProc_GLPRIORITIZETEXTURESEXT) (GLsizei n, const GLuint *textures, const GLclampf *priorities);
GdkGLProc    gdk_gl_get_glPrioritizeTexturesEXT (void);
#define      gdk_gl_glPrioritizeTexturesEXT(proc, n, textures, priorities) \
  ( ((GdkGLProc_GLPRIORITIZETEXTURESEXT) (proc)) (n, textures, priorities) )

/* 
 * GL_SGIS_detail_texture
 */

/* glDetailTexFuncSGIS */
typedef void (APIENTRY * GdkGLProc_GLDETAILTEXFUNCSGIS) (GLenum target, GLsizei n, const GLfloat *points);
GdkGLProc    gdk_gl_get_glDetailTexFuncSGIS (void);
#define      gdk_gl_glDetailTexFuncSGIS(proc, target, n, points) \
  ( ((GdkGLProc_GLDETAILTEXFUNCSGIS) (proc)) (target, n, points) )

/* glGetDetailTexFuncSGIS */
typedef void (APIENTRY * GdkGLProc_GLGETDETAILTEXFUNCSGIS) (GLenum target, GLfloat *points);
GdkGLProc    gdk_gl_get_glGetDetailTexFuncSGIS (void);
#define      gdk_gl_glGetDetailTexFuncSGIS(proc, target, points) \
  ( ((GdkGLProc_GLGETDETAILTEXFUNCSGIS) (proc)) (target, points) )

/* 
 * GL_SGIS_sharpen_texture
 */

/* glSharpenTexFuncSGIS */
typedef void (APIENTRY * GdkGLProc_GLSHARPENTEXFUNCSGIS) (GLenum target, GLsizei n, const GLfloat *points);
GdkGLProc    gdk_gl_get_glSharpenTexFuncSGIS (void);
#define      gdk_gl_glSharpenTexFuncSGIS(proc, target, n, points) \
  ( ((GdkGLProc_GLSHARPENTEXFUNCSGIS) (proc)) (target, n, points) )

/* glGetSharpenTexFuncSGIS */
typedef void (APIENTRY * GdkGLProc_GLGETSHARPENTEXFUNCSGIS) (GLenum target, GLfloat *points);
GdkGLProc    gdk_gl_get_glGetSharpenTexFuncSGIS (void);
#define      gdk_gl_glGetSharpenTexFuncSGIS(proc, target, points) \
  ( ((GdkGLProc_GLGETSHARPENTEXFUNCSGIS) (proc)) (target, points) )

/* 
 * GL_SGIS_multisample
 */

/* glSampleMaskSGIS */
typedef void (APIENTRY * GdkGLProc_GLSAMPLEMASKSGIS) (GLclampf value, GLboolean invert);
GdkGLProc    gdk_gl_get_glSampleMaskSGIS (void);
#define      gdk_gl_glSampleMaskSGIS(proc, value, invert) \
  ( ((GdkGLProc_GLSAMPLEMASKSGIS) (proc)) (value, invert) )

/* glSamplePatternSGIS */
typedef void (APIENTRY * GdkGLProc_GLSAMPLEPATTERNSGIS) (GLenum pattern);
GdkGLProc    gdk_gl_get_glSamplePatternSGIS (void);
#define      gdk_gl_glSamplePatternSGIS(proc, pattern) \
  ( ((GdkGLProc_GLSAMPLEPATTERNSGIS) (proc)) (pattern) )

/* 
 * GL_EXT_vertex_array
 */

/* glArrayElementEXT */
typedef void (APIENTRY * GdkGLProc_GLARRAYELEMENTEXT) (GLint i);
GdkGLProc    gdk_gl_get_glArrayElementEXT (void);
#define      gdk_gl_glArrayElementEXT(proc, i) \
  ( ((GdkGLProc_GLARRAYELEMENTEXT) (proc)) (i) )

/* glColorPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLCOLORPOINTEREXT) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glColorPointerEXT (void);
#define      gdk_gl_glColorPointerEXT(proc, size, type, stride, count, pointer) \
  ( ((GdkGLProc_GLCOLORPOINTEREXT) (proc)) (size, type, stride, count, pointer) )

/* glDrawArraysEXT */
typedef void (APIENTRY * GdkGLProc_GLDRAWARRAYSEXT) (GLenum mode, GLint first, GLsizei count);
GdkGLProc    gdk_gl_get_glDrawArraysEXT (void);
#define      gdk_gl_glDrawArraysEXT(proc, mode, first, count) \
  ( ((GdkGLProc_GLDRAWARRAYSEXT) (proc)) (mode, first, count) )

/* glEdgeFlagPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLEDGEFLAGPOINTEREXT) (GLsizei stride, GLsizei count, const GLboolean *pointer);
GdkGLProc    gdk_gl_get_glEdgeFlagPointerEXT (void);
#define      gdk_gl_glEdgeFlagPointerEXT(proc, stride, count, pointer) \
  ( ((GdkGLProc_GLEDGEFLAGPOINTEREXT) (proc)) (stride, count, pointer) )

/* glGetPointervEXT */
typedef void (APIENTRY * GdkGLProc_GLGETPOINTERVEXT) (GLenum pname, GLvoid* *params);
GdkGLProc    gdk_gl_get_glGetPointervEXT (void);
#define      gdk_gl_glGetPointervEXT(proc, pname, params) \
  ( ((GdkGLProc_GLGETPOINTERVEXT) (proc)) (pname, params) )

/* glIndexPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLINDEXPOINTEREXT) (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glIndexPointerEXT (void);
#define      gdk_gl_glIndexPointerEXT(proc, type, stride, count, pointer) \
  ( ((GdkGLProc_GLINDEXPOINTEREXT) (proc)) (type, stride, count, pointer) )

/* glNormalPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLNORMALPOINTEREXT) (GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glNormalPointerEXT (void);
#define      gdk_gl_glNormalPointerEXT(proc, type, stride, count, pointer) \
  ( ((GdkGLProc_GLNORMALPOINTEREXT) (proc)) (type, stride, count, pointer) )

/* glTexCoordPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORDPOINTEREXT) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glTexCoordPointerEXT (void);
#define      gdk_gl_glTexCoordPointerEXT(proc, size, type, stride, count, pointer) \
  ( ((GdkGLProc_GLTEXCOORDPOINTEREXT) (proc)) (size, type, stride, count, pointer) )

/* glVertexPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLVERTEXPOINTEREXT) (GLint size, GLenum type, GLsizei stride, GLsizei count, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glVertexPointerEXT (void);
#define      gdk_gl_glVertexPointerEXT(proc, size, type, stride, count, pointer) \
  ( ((GdkGLProc_GLVERTEXPOINTEREXT) (proc)) (size, type, stride, count, pointer) )

/* 
 * GL_EXT_blend_minmax
 */

/* glBlendEquationEXT */
typedef void (APIENTRY * GdkGLProc_GLBLENDEQUATIONEXT) (GLenum mode);
GdkGLProc    gdk_gl_get_glBlendEquationEXT (void);
#define      gdk_gl_glBlendEquationEXT(proc, mode) \
  ( ((GdkGLProc_GLBLENDEQUATIONEXT) (proc)) (mode) )

/* 
 * GL_SGIX_sprite
 */

/* glSpriteParameterfSGIX */
typedef void (APIENTRY * GdkGLProc_GLSPRITEPARAMETERFSGIX) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glSpriteParameterfSGIX (void);
#define      gdk_gl_glSpriteParameterfSGIX(proc, pname, param) \
  ( ((GdkGLProc_GLSPRITEPARAMETERFSGIX) (proc)) (pname, param) )

/* glSpriteParameterfvSGIX */
typedef void (APIENTRY * GdkGLProc_GLSPRITEPARAMETERFVSGIX) (GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glSpriteParameterfvSGIX (void);
#define      gdk_gl_glSpriteParameterfvSGIX(proc, pname, params) \
  ( ((GdkGLProc_GLSPRITEPARAMETERFVSGIX) (proc)) (pname, params) )

/* glSpriteParameteriSGIX */
typedef void (APIENTRY * GdkGLProc_GLSPRITEPARAMETERISGIX) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glSpriteParameteriSGIX (void);
#define      gdk_gl_glSpriteParameteriSGIX(proc, pname, param) \
  ( ((GdkGLProc_GLSPRITEPARAMETERISGIX) (proc)) (pname, param) )

/* glSpriteParameterivSGIX */
typedef void (APIENTRY * GdkGLProc_GLSPRITEPARAMETERIVSGIX) (GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glSpriteParameterivSGIX (void);
#define      gdk_gl_glSpriteParameterivSGIX(proc, pname, params) \
  ( ((GdkGLProc_GLSPRITEPARAMETERIVSGIX) (proc)) (pname, params) )

/* 
 * GL_EXT_point_parameters
 */

/* glPointParameterfEXT */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERFEXT) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glPointParameterfEXT (void);
#define      gdk_gl_glPointParameterfEXT(proc, pname, param) \
  ( ((GdkGLProc_GLPOINTPARAMETERFEXT) (proc)) (pname, param) )

/* glPointParameterfvEXT */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERFVEXT) (GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glPointParameterfvEXT (void);
#define      gdk_gl_glPointParameterfvEXT(proc, pname, params) \
  ( ((GdkGLProc_GLPOINTPARAMETERFVEXT) (proc)) (pname, params) )

/* 
 * GL_SGIS_point_parameters
 */

/* glPointParameterfSGIS */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERFSGIS) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glPointParameterfSGIS (void);
#define      gdk_gl_glPointParameterfSGIS(proc, pname, param) \
  ( ((GdkGLProc_GLPOINTPARAMETERFSGIS) (proc)) (pname, param) )

/* glPointParameterfvSGIS */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERFVSGIS) (GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glPointParameterfvSGIS (void);
#define      gdk_gl_glPointParameterfvSGIS(proc, pname, params) \
  ( ((GdkGLProc_GLPOINTPARAMETERFVSGIS) (proc)) (pname, params) )

/* 
 * GL_SGIX_instruments
 */

/*  glGetInstrumentsSGIX */
typedef GLint (APIENTRY * GdkGLProc_GLGETINSTRUMENTSSGIX) (void);
GdkGLProc    gdk_gl_get_glGetInstrumentsSGIX (void);
#define      gdk_gl_glGetInstrumentsSGIX(proc) \
  ( ((GdkGLProc_GLGETINSTRUMENTSSGIX) (proc)) () )

/* glInstrumentsBufferSGIX */
typedef void (APIENTRY * GdkGLProc_GLINSTRUMENTSBUFFERSGIX) (GLsizei size, GLint *buffer);
GdkGLProc    gdk_gl_get_glInstrumentsBufferSGIX (void);
#define      gdk_gl_glInstrumentsBufferSGIX(proc, size, buffer) \
  ( ((GdkGLProc_GLINSTRUMENTSBUFFERSGIX) (proc)) (size, buffer) )

/*  glPollInstrumentsSGIX */
typedef GLint (APIENTRY * GdkGLProc_GLPOLLINSTRUMENTSSGIX) (GLint *marker_p);
GdkGLProc    gdk_gl_get_glPollInstrumentsSGIX (void);
#define      gdk_gl_glPollInstrumentsSGIX(proc, marker_p) \
  ( ((GdkGLProc_GLPOLLINSTRUMENTSSGIX) (proc)) (marker_p) )

/* glReadInstrumentsSGIX */
typedef void (APIENTRY * GdkGLProc_GLREADINSTRUMENTSSGIX) (GLint marker);
GdkGLProc    gdk_gl_get_glReadInstrumentsSGIX (void);
#define      gdk_gl_glReadInstrumentsSGIX(proc, marker) \
  ( ((GdkGLProc_GLREADINSTRUMENTSSGIX) (proc)) (marker) )

/* glStartInstrumentsSGIX */
typedef void (APIENTRY * GdkGLProc_GLSTARTINSTRUMENTSSGIX) (void);
GdkGLProc    gdk_gl_get_glStartInstrumentsSGIX (void);
#define      gdk_gl_glStartInstrumentsSGIX(proc) \
  ( ((GdkGLProc_GLSTARTINSTRUMENTSSGIX) (proc)) () )

/* glStopInstrumentsSGIX */
typedef void (APIENTRY * GdkGLProc_GLSTOPINSTRUMENTSSGIX) (GLint marker);
GdkGLProc    gdk_gl_get_glStopInstrumentsSGIX (void);
#define      gdk_gl_glStopInstrumentsSGIX(proc, marker) \
  ( ((GdkGLProc_GLSTOPINSTRUMENTSSGIX) (proc)) (marker) )

/* 
 * GL_SGIX_framezoom
 */

/* glFrameZoomSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAMEZOOMSGIX) (GLint factor);
GdkGLProc    gdk_gl_get_glFrameZoomSGIX (void);
#define      gdk_gl_glFrameZoomSGIX(proc, factor) \
  ( ((GdkGLProc_GLFRAMEZOOMSGIX) (proc)) (factor) )

/* 
 * GL_SGIX_tag_sample_buffer
 */

/* glTagSampleBufferSGIX */
typedef void (APIENTRY * GdkGLProc_GLTAGSAMPLEBUFFERSGIX) (void);
GdkGLProc    gdk_gl_get_glTagSampleBufferSGIX (void);
#define      gdk_gl_glTagSampleBufferSGIX(proc) \
  ( ((GdkGLProc_GLTAGSAMPLEBUFFERSGIX) (proc)) () )

/* 
 * GL_SGIX_polynomial_ffd
 */

/* glDeformationMap3dSGIX */
typedef void (APIENTRY * GdkGLProc_GLDEFORMATIONMAP3DSGIX) (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points);
GdkGLProc    gdk_gl_get_glDeformationMap3dSGIX (void);
#define      gdk_gl_glDeformationMap3dSGIX(proc, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points) \
  ( ((GdkGLProc_GLDEFORMATIONMAP3DSGIX) (proc)) (target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points) )

/* glDeformationMap3fSGIX */
typedef void (APIENTRY * GdkGLProc_GLDEFORMATIONMAP3FSGIX) (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points);
GdkGLProc    gdk_gl_get_glDeformationMap3fSGIX (void);
#define      gdk_gl_glDeformationMap3fSGIX(proc, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points) \
  ( ((GdkGLProc_GLDEFORMATIONMAP3FSGIX) (proc)) (target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points) )

/* glDeformSGIX (GLbitfield) */
typedef void (APIENTRY * GdkGLProc_GLDEFORMSGIX) (GLbitfield mask);
GdkGLProc    gdk_gl_get_glDeformSGIX (void);
#define      gdk_gl_glDeformSGIX(proc, mask) \
  ( ((GdkGLProc_GLDEFORMSGIX) (proc)) (mask) )

/* glLoadIdentityDeformationMapSGIX */
typedef void (APIENTRY * GdkGLProc_GLLOADIDENTITYDEFORMATIONMAPSGIX) (GLbitfield mask);
GdkGLProc    gdk_gl_get_glLoadIdentityDeformationMapSGIX (void);
#define      gdk_gl_glLoadIdentityDeformationMapSGIX(proc, mask) \
  ( ((GdkGLProc_GLLOADIDENTITYDEFORMATIONMAPSGIX) (proc)) (mask) )

/* 
 * GL_SGIX_reference_plane
 */

/* glReferencePlaneSGIX */
typedef void (APIENTRY * GdkGLProc_GLREFERENCEPLANESGIX) (const GLdouble *equation);
GdkGLProc    gdk_gl_get_glReferencePlaneSGIX (void);
#define      gdk_gl_glReferencePlaneSGIX(proc, equation) \
  ( ((GdkGLProc_GLREFERENCEPLANESGIX) (proc)) (equation) )

/* 
 * GL_SGIX_flush_raster
 */

/* glFlushRasterSGIX */
typedef void (APIENTRY * GdkGLProc_GLFLUSHRASTERSGIX) (void);
GdkGLProc    gdk_gl_get_glFlushRasterSGIX (void);
#define      gdk_gl_glFlushRasterSGIX(proc) \
  ( ((GdkGLProc_GLFLUSHRASTERSGIX) (proc)) () )

/* 
 * GL_SGIS_fog_function
 */

/* glFogFuncSGIS */
typedef void (APIENTRY * GdkGLProc_GLFOGFUNCSGIS) (GLsizei n, const GLfloat *points);
GdkGLProc    gdk_gl_get_glFogFuncSGIS (void);
#define      gdk_gl_glFogFuncSGIS(proc, n, points) \
  ( ((GdkGLProc_GLFOGFUNCSGIS) (proc)) (n, points) )

/* glGetFogFuncSGIS */
typedef void (APIENTRY * GdkGLProc_GLGETFOGFUNCSGIS) (GLfloat *points);
GdkGLProc    gdk_gl_get_glGetFogFuncSGIS (void);
#define      gdk_gl_glGetFogFuncSGIS(proc, points) \
  ( ((GdkGLProc_GLGETFOGFUNCSGIS) (proc)) (points) )

/* 
 * GL_HP_image_transform
 */

/* glImageTransformParameteriHP */
typedef void (APIENTRY * GdkGLProc_GLIMAGETRANSFORMPARAMETERIHP) (GLenum target, GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glImageTransformParameteriHP (void);
#define      gdk_gl_glImageTransformParameteriHP(proc, target, pname, param) \
  ( ((GdkGLProc_GLIMAGETRANSFORMPARAMETERIHP) (proc)) (target, pname, param) )

/* glImageTransformParameterfHP */
typedef void (APIENTRY * GdkGLProc_GLIMAGETRANSFORMPARAMETERFHP) (GLenum target, GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glImageTransformParameterfHP (void);
#define      gdk_gl_glImageTransformParameterfHP(proc, target, pname, param) \
  ( ((GdkGLProc_GLIMAGETRANSFORMPARAMETERFHP) (proc)) (target, pname, param) )

/* glImageTransformParameterivHP */
typedef void (APIENTRY * GdkGLProc_GLIMAGETRANSFORMPARAMETERIVHP) (GLenum target, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glImageTransformParameterivHP (void);
#define      gdk_gl_glImageTransformParameterivHP(proc, target, pname, params) \
  ( ((GdkGLProc_GLIMAGETRANSFORMPARAMETERIVHP) (proc)) (target, pname, params) )

/* glImageTransformParameterfvHP */
typedef void (APIENTRY * GdkGLProc_GLIMAGETRANSFORMPARAMETERFVHP) (GLenum target, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glImageTransformParameterfvHP (void);
#define      gdk_gl_glImageTransformParameterfvHP(proc, target, pname, params) \
  ( ((GdkGLProc_GLIMAGETRANSFORMPARAMETERFVHP) (proc)) (target, pname, params) )

/* glGetImageTransformParameterivHP */
typedef void (APIENTRY * GdkGLProc_GLGETIMAGETRANSFORMPARAMETERIVHP) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetImageTransformParameterivHP (void);
#define      gdk_gl_glGetImageTransformParameterivHP(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETIMAGETRANSFORMPARAMETERIVHP) (proc)) (target, pname, params) )

/* glGetImageTransformParameterfvHP */
typedef void (APIENTRY * GdkGLProc_GLGETIMAGETRANSFORMPARAMETERFVHP) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetImageTransformParameterfvHP (void);
#define      gdk_gl_glGetImageTransformParameterfvHP(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETIMAGETRANSFORMPARAMETERFVHP) (proc)) (target, pname, params) )

/* 
 * GL_EXT_color_subtable
 */

/* glColorSubTableEXT */
typedef void (APIENTRY * GdkGLProc_GLCOLORSUBTABLEEXT) (GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
GdkGLProc    gdk_gl_get_glColorSubTableEXT (void);
#define      gdk_gl_glColorSubTableEXT(proc, target, start, count, format, type, data) \
  ( ((GdkGLProc_GLCOLORSUBTABLEEXT) (proc)) (target, start, count, format, type, data) )

/* glCopyColorSubTableEXT */
typedef void (APIENTRY * GdkGLProc_GLCOPYCOLORSUBTABLEEXT) (GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
GdkGLProc    gdk_gl_get_glCopyColorSubTableEXT (void);
#define      gdk_gl_glCopyColorSubTableEXT(proc, target, start, x, y, width) \
  ( ((GdkGLProc_GLCOPYCOLORSUBTABLEEXT) (proc)) (target, start, x, y, width) )

/* 
 * GL_PGI_misc_hints
 */

/* glHintPGI */
typedef void (APIENTRY * GdkGLProc_GLHINTPGI) (GLenum target, GLint mode);
GdkGLProc    gdk_gl_get_glHintPGI (void);
#define      gdk_gl_glHintPGI(proc, target, mode) \
  ( ((GdkGLProc_GLHINTPGI) (proc)) (target, mode) )

/* 
 * GL_EXT_paletted_texture
 */

/* glColorTableEXT */
typedef void (APIENTRY * GdkGLProc_GLCOLORTABLEEXT) (GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
GdkGLProc    gdk_gl_get_glColorTableEXT (void);
#define      gdk_gl_glColorTableEXT(proc, target, internalFormat, width, format, type, table) \
  ( ((GdkGLProc_GLCOLORTABLEEXT) (proc)) (target, internalFormat, width, format, type, table) )

/* glGetColorTableEXT */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLEEXT) (GLenum target, GLenum format, GLenum type, GLvoid *data);
GdkGLProc    gdk_gl_get_glGetColorTableEXT (void);
#define      gdk_gl_glGetColorTableEXT(proc, target, format, type, data) \
  ( ((GdkGLProc_GLGETCOLORTABLEEXT) (proc)) (target, format, type, data) )

/* glGetColorTableParameterivEXT */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLEPARAMETERIVEXT) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetColorTableParameterivEXT (void);
#define      gdk_gl_glGetColorTableParameterivEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCOLORTABLEPARAMETERIVEXT) (proc)) (target, pname, params) )

/* glGetColorTableParameterfvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETCOLORTABLEPARAMETERFVEXT) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetColorTableParameterfvEXT (void);
#define      gdk_gl_glGetColorTableParameterfvEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETCOLORTABLEPARAMETERFVEXT) (proc)) (target, pname, params) )

/* 
 * GL_SGIX_list_priority
 */

/* glGetListParameterfvSGIX */
typedef void (APIENTRY * GdkGLProc_GLGETLISTPARAMETERFVSGIX) (GLuint list, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetListParameterfvSGIX (void);
#define      gdk_gl_glGetListParameterfvSGIX(proc, list, pname, params) \
  ( ((GdkGLProc_GLGETLISTPARAMETERFVSGIX) (proc)) (list, pname, params) )

/* glGetListParameterivSGIX */
typedef void (APIENTRY * GdkGLProc_GLGETLISTPARAMETERIVSGIX) (GLuint list, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetListParameterivSGIX (void);
#define      gdk_gl_glGetListParameterivSGIX(proc, list, pname, params) \
  ( ((GdkGLProc_GLGETLISTPARAMETERIVSGIX) (proc)) (list, pname, params) )

/* glListParameterfSGIX */
typedef void (APIENTRY * GdkGLProc_GLLISTPARAMETERFSGIX) (GLuint list, GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glListParameterfSGIX (void);
#define      gdk_gl_glListParameterfSGIX(proc, list, pname, param) \
  ( ((GdkGLProc_GLLISTPARAMETERFSGIX) (proc)) (list, pname, param) )

/* glListParameterfvSGIX */
typedef void (APIENTRY * GdkGLProc_GLLISTPARAMETERFVSGIX) (GLuint list, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glListParameterfvSGIX (void);
#define      gdk_gl_glListParameterfvSGIX(proc, list, pname, params) \
  ( ((GdkGLProc_GLLISTPARAMETERFVSGIX) (proc)) (list, pname, params) )

/* glListParameteriSGIX */
typedef void (APIENTRY * GdkGLProc_GLLISTPARAMETERISGIX) (GLuint list, GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glListParameteriSGIX (void);
#define      gdk_gl_glListParameteriSGIX(proc, list, pname, param) \
  ( ((GdkGLProc_GLLISTPARAMETERISGIX) (proc)) (list, pname, param) )

/* glListParameterivSGIX */
typedef void (APIENTRY * GdkGLProc_GLLISTPARAMETERIVSGIX) (GLuint list, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glListParameterivSGIX (void);
#define      gdk_gl_glListParameterivSGIX(proc, list, pname, params) \
  ( ((GdkGLProc_GLLISTPARAMETERIVSGIX) (proc)) (list, pname, params) )

/* 
 * GL_EXT_index_material
 */

/* glIndexMaterialEXT */
typedef void (APIENTRY * GdkGLProc_GLINDEXMATERIALEXT) (GLenum face, GLenum mode);
GdkGLProc    gdk_gl_get_glIndexMaterialEXT (void);
#define      gdk_gl_glIndexMaterialEXT(proc, face, mode) \
  ( ((GdkGLProc_GLINDEXMATERIALEXT) (proc)) (face, mode) )

/* 
 * GL_EXT_index_func
 */

/* glIndexFuncEXT */
typedef void (APIENTRY * GdkGLProc_GLINDEXFUNCEXT) (GLenum func, GLclampf ref);
GdkGLProc    gdk_gl_get_glIndexFuncEXT (void);
#define      gdk_gl_glIndexFuncEXT(proc, func, ref) \
  ( ((GdkGLProc_GLINDEXFUNCEXT) (proc)) (func, ref) )

/* 
 * GL_EXT_compiled_vertex_array
 */

/* glLockArraysEXT */
typedef void (APIENTRY * GdkGLProc_GLLOCKARRAYSEXT) (GLint first, GLsizei count);
GdkGLProc    gdk_gl_get_glLockArraysEXT (void);
#define      gdk_gl_glLockArraysEXT(proc, first, count) \
  ( ((GdkGLProc_GLLOCKARRAYSEXT) (proc)) (first, count) )

/* glUnlockArraysEXT */
typedef void (APIENTRY * GdkGLProc_GLUNLOCKARRAYSEXT) (void);
GdkGLProc    gdk_gl_get_glUnlockArraysEXT (void);
#define      gdk_gl_glUnlockArraysEXT(proc) \
  ( ((GdkGLProc_GLUNLOCKARRAYSEXT) (proc)) () )

/* 
 * GL_EXT_cull_vertex
 */

/* glCullParameterdvEXT */
typedef void (APIENTRY * GdkGLProc_GLCULLPARAMETERDVEXT) (GLenum pname, GLdouble *params);
GdkGLProc    gdk_gl_get_glCullParameterdvEXT (void);
#define      gdk_gl_glCullParameterdvEXT(proc, pname, params) \
  ( ((GdkGLProc_GLCULLPARAMETERDVEXT) (proc)) (pname, params) )

/* glCullParameterfvEXT */
typedef void (APIENTRY * GdkGLProc_GLCULLPARAMETERFVEXT) (GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glCullParameterfvEXT (void);
#define      gdk_gl_glCullParameterfvEXT(proc, pname, params) \
  ( ((GdkGLProc_GLCULLPARAMETERFVEXT) (proc)) (pname, params) )

/* 
 * GL_SGIX_fragment_lighting
 */

/* glFragmentColorMaterialSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTCOLORMATERIALSGIX) (GLenum face, GLenum mode);
GdkGLProc    gdk_gl_get_glFragmentColorMaterialSGIX (void);
#define      gdk_gl_glFragmentColorMaterialSGIX(proc, face, mode) \
  ( ((GdkGLProc_GLFRAGMENTCOLORMATERIALSGIX) (proc)) (face, mode) )

/* glFragmentLightfSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTLIGHTFSGIX) (GLenum light, GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glFragmentLightfSGIX (void);
#define      gdk_gl_glFragmentLightfSGIX(proc, light, pname, param) \
  ( ((GdkGLProc_GLFRAGMENTLIGHTFSGIX) (proc)) (light, pname, param) )

/* glFragmentLightfvSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTLIGHTFVSGIX) (GLenum light, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glFragmentLightfvSGIX (void);
#define      gdk_gl_glFragmentLightfvSGIX(proc, light, pname, params) \
  ( ((GdkGLProc_GLFRAGMENTLIGHTFVSGIX) (proc)) (light, pname, params) )

/* glFragmentLightiSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTLIGHTISGIX) (GLenum light, GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glFragmentLightiSGIX (void);
#define      gdk_gl_glFragmentLightiSGIX(proc, light, pname, param) \
  ( ((GdkGLProc_GLFRAGMENTLIGHTISGIX) (proc)) (light, pname, param) )

/* glFragmentLightivSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTLIGHTIVSGIX) (GLenum light, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glFragmentLightivSGIX (void);
#define      gdk_gl_glFragmentLightivSGIX(proc, light, pname, params) \
  ( ((GdkGLProc_GLFRAGMENTLIGHTIVSGIX) (proc)) (light, pname, params) )

/* glFragmentLightModelfSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTLIGHTMODELFSGIX) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glFragmentLightModelfSGIX (void);
#define      gdk_gl_glFragmentLightModelfSGIX(proc, pname, param) \
  ( ((GdkGLProc_GLFRAGMENTLIGHTMODELFSGIX) (proc)) (pname, param) )

/* glFragmentLightModelfvSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTLIGHTMODELFVSGIX) (GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glFragmentLightModelfvSGIX (void);
#define      gdk_gl_glFragmentLightModelfvSGIX(proc, pname, params) \
  ( ((GdkGLProc_GLFRAGMENTLIGHTMODELFVSGIX) (proc)) (pname, params) )

/* glFragmentLightModeliSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTLIGHTMODELISGIX) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glFragmentLightModeliSGIX (void);
#define      gdk_gl_glFragmentLightModeliSGIX(proc, pname, param) \
  ( ((GdkGLProc_GLFRAGMENTLIGHTMODELISGIX) (proc)) (pname, param) )

/* glFragmentLightModelivSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTLIGHTMODELIVSGIX) (GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glFragmentLightModelivSGIX (void);
#define      gdk_gl_glFragmentLightModelivSGIX(proc, pname, params) \
  ( ((GdkGLProc_GLFRAGMENTLIGHTMODELIVSGIX) (proc)) (pname, params) )

/* glFragmentMaterialfSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTMATERIALFSGIX) (GLenum face, GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glFragmentMaterialfSGIX (void);
#define      gdk_gl_glFragmentMaterialfSGIX(proc, face, pname, param) \
  ( ((GdkGLProc_GLFRAGMENTMATERIALFSGIX) (proc)) (face, pname, param) )

/* glFragmentMaterialfvSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTMATERIALFVSGIX) (GLenum face, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glFragmentMaterialfvSGIX (void);
#define      gdk_gl_glFragmentMaterialfvSGIX(proc, face, pname, params) \
  ( ((GdkGLProc_GLFRAGMENTMATERIALFVSGIX) (proc)) (face, pname, params) )

/* glFragmentMaterialiSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTMATERIALISGIX) (GLenum face, GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glFragmentMaterialiSGIX (void);
#define      gdk_gl_glFragmentMaterialiSGIX(proc, face, pname, param) \
  ( ((GdkGLProc_GLFRAGMENTMATERIALISGIX) (proc)) (face, pname, param) )

/* glFragmentMaterialivSGIX */
typedef void (APIENTRY * GdkGLProc_GLFRAGMENTMATERIALIVSGIX) (GLenum face, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glFragmentMaterialivSGIX (void);
#define      gdk_gl_glFragmentMaterialivSGIX(proc, face, pname, params) \
  ( ((GdkGLProc_GLFRAGMENTMATERIALIVSGIX) (proc)) (face, pname, params) )

/* glGetFragmentLightfvSGIX */
typedef void (APIENTRY * GdkGLProc_GLGETFRAGMENTLIGHTFVSGIX) (GLenum light, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetFragmentLightfvSGIX (void);
#define      gdk_gl_glGetFragmentLightfvSGIX(proc, light, pname, params) \
  ( ((GdkGLProc_GLGETFRAGMENTLIGHTFVSGIX) (proc)) (light, pname, params) )

/* glGetFragmentLightivSGIX */
typedef void (APIENTRY * GdkGLProc_GLGETFRAGMENTLIGHTIVSGIX) (GLenum light, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetFragmentLightivSGIX (void);
#define      gdk_gl_glGetFragmentLightivSGIX(proc, light, pname, params) \
  ( ((GdkGLProc_GLGETFRAGMENTLIGHTIVSGIX) (proc)) (light, pname, params) )

/* glGetFragmentMaterialfvSGIX */
typedef void (APIENTRY * GdkGLProc_GLGETFRAGMENTMATERIALFVSGIX) (GLenum face, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetFragmentMaterialfvSGIX (void);
#define      gdk_gl_glGetFragmentMaterialfvSGIX(proc, face, pname, params) \
  ( ((GdkGLProc_GLGETFRAGMENTMATERIALFVSGIX) (proc)) (face, pname, params) )

/* glGetFragmentMaterialivSGIX */
typedef void (APIENTRY * GdkGLProc_GLGETFRAGMENTMATERIALIVSGIX) (GLenum face, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetFragmentMaterialivSGIX (void);
#define      gdk_gl_glGetFragmentMaterialivSGIX(proc, face, pname, params) \
  ( ((GdkGLProc_GLGETFRAGMENTMATERIALIVSGIX) (proc)) (face, pname, params) )

/* glLightEnviSGIX */
typedef void (APIENTRY * GdkGLProc_GLLIGHTENVISGIX) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glLightEnviSGIX (void);
#define      gdk_gl_glLightEnviSGIX(proc, pname, param) \
  ( ((GdkGLProc_GLLIGHTENVISGIX) (proc)) (pname, param) )

/* 
 * GL_EXT_draw_range_elements
 */

/* glDrawRangeElementsEXT */
typedef void (APIENTRY * GdkGLProc_GLDRAWRANGEELEMENTSEXT) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
GdkGLProc    gdk_gl_get_glDrawRangeElementsEXT (void);
#define      gdk_gl_glDrawRangeElementsEXT(proc, mode, start, end, count, type, indices) \
  ( ((GdkGLProc_GLDRAWRANGEELEMENTSEXT) (proc)) (mode, start, end, count, type, indices) )

/* 
 * GL_EXT_light_texture
 */

/* glApplyTextureEXT */
typedef void (APIENTRY * GdkGLProc_GLAPPLYTEXTUREEXT) (GLenum mode);
GdkGLProc    gdk_gl_get_glApplyTextureEXT (void);
#define      gdk_gl_glApplyTextureEXT(proc, mode) \
  ( ((GdkGLProc_GLAPPLYTEXTUREEXT) (proc)) (mode) )

/* glTextureLightEXT */
typedef void (APIENTRY * GdkGLProc_GLTEXTURELIGHTEXT) (GLenum pname);
GdkGLProc    gdk_gl_get_glTextureLightEXT (void);
#define      gdk_gl_glTextureLightEXT(proc, pname) \
  ( ((GdkGLProc_GLTEXTURELIGHTEXT) (proc)) (pname) )

/* glTextureMaterialEXT */
typedef void (APIENTRY * GdkGLProc_GLTEXTUREMATERIALEXT) (GLenum face, GLenum mode);
GdkGLProc    gdk_gl_get_glTextureMaterialEXT (void);
#define      gdk_gl_glTextureMaterialEXT(proc, face, mode) \
  ( ((GdkGLProc_GLTEXTUREMATERIALEXT) (proc)) (face, mode) )

/* 
 * GL_SGIX_async
 */

/* glAsyncMarkerSGIX */
typedef void (APIENTRY * GdkGLProc_GLASYNCMARKERSGIX) (GLuint marker);
GdkGLProc    gdk_gl_get_glAsyncMarkerSGIX (void);
#define      gdk_gl_glAsyncMarkerSGIX(proc, marker) \
  ( ((GdkGLProc_GLASYNCMARKERSGIX) (proc)) (marker) )

/* glFinishAsyncSGIX */
typedef GLint (APIENTRY * GdkGLProc_GLFINISHASYNCSGIX) (GLuint *markerp);
GdkGLProc    gdk_gl_get_glFinishAsyncSGIX (void);
#define      gdk_gl_glFinishAsyncSGIX(proc, markerp) \
  ( ((GdkGLProc_GLFINISHASYNCSGIX) (proc)) (markerp) )

/* glPollAsyncSGIX */
typedef GLint (APIENTRY * GdkGLProc_GLPOLLASYNCSGIX) (GLuint *markerp);
GdkGLProc    gdk_gl_get_glPollAsyncSGIX (void);
#define      gdk_gl_glPollAsyncSGIX(proc, markerp) \
  ( ((GdkGLProc_GLPOLLASYNCSGIX) (proc)) (markerp) )

/* glGenAsyncMarkersSGIX */
typedef GLuint (APIENTRY * GdkGLProc_GLGENASYNCMARKERSSGIX) (GLsizei range);
GdkGLProc    gdk_gl_get_glGenAsyncMarkersSGIX (void);
#define      gdk_gl_glGenAsyncMarkersSGIX(proc, range) \
  ( ((GdkGLProc_GLGENASYNCMARKERSSGIX) (proc)) (range) )

/* glDeleteAsyncMarkersSGIX */
typedef void (APIENTRY * GdkGLProc_GLDELETEASYNCMARKERSSGIX) (GLuint marker, GLsizei range);
GdkGLProc    gdk_gl_get_glDeleteAsyncMarkersSGIX (void);
#define      gdk_gl_glDeleteAsyncMarkersSGIX(proc, marker, range) \
  ( ((GdkGLProc_GLDELETEASYNCMARKERSSGIX) (proc)) (marker, range) )

/* glIsAsyncMarkerSGIX */
typedef GLboolean (APIENTRY * GdkGLProc_GLISASYNCMARKERSGIX) (GLuint marker);
GdkGLProc    gdk_gl_get_glIsAsyncMarkerSGIX (void);
#define      gdk_gl_glIsAsyncMarkerSGIX(proc, marker) \
  ( ((GdkGLProc_GLISASYNCMARKERSGIX) (proc)) (marker) )

/* 
 * GL_INTEL_parallel_arrays
 */

/* glVertexPointervINTEL */
typedef void (APIENTRY * GdkGLProc_GLVERTEXPOINTERVINTEL) (GLint size, GLenum type, const GLvoid* *pointer);
GdkGLProc    gdk_gl_get_glVertexPointervINTEL (void);
#define      gdk_gl_glVertexPointervINTEL(proc, size, type, pointer) \
  ( ((GdkGLProc_GLVERTEXPOINTERVINTEL) (proc)) (size, type, pointer) )

/* glNormalPointervINTEL */
typedef void (APIENTRY * GdkGLProc_GLNORMALPOINTERVINTEL) (GLenum type, const GLvoid* *pointer);
GdkGLProc    gdk_gl_get_glNormalPointervINTEL (void);
#define      gdk_gl_glNormalPointervINTEL(proc, type, pointer) \
  ( ((GdkGLProc_GLNORMALPOINTERVINTEL) (proc)) (type, pointer) )

/* glColorPointervINTEL */
typedef void (APIENTRY * GdkGLProc_GLCOLORPOINTERVINTEL) (GLint size, GLenum type, const GLvoid* *pointer);
GdkGLProc    gdk_gl_get_glColorPointervINTEL (void);
#define      gdk_gl_glColorPointervINTEL(proc, size, type, pointer) \
  ( ((GdkGLProc_GLCOLORPOINTERVINTEL) (proc)) (size, type, pointer) )

/* glTexCoordPointervINTEL */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORDPOINTERVINTEL) (GLint size, GLenum type, const GLvoid* *pointer);
GdkGLProc    gdk_gl_get_glTexCoordPointervINTEL (void);
#define      gdk_gl_glTexCoordPointervINTEL(proc, size, type, pointer) \
  ( ((GdkGLProc_GLTEXCOORDPOINTERVINTEL) (proc)) (size, type, pointer) )

/* 
 * GL_EXT_pixel_transform
 */

/* glPixelTransformParameteriEXT */
typedef void (APIENTRY * GdkGLProc_GLPIXELTRANSFORMPARAMETERIEXT) (GLenum target, GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glPixelTransformParameteriEXT (void);
#define      gdk_gl_glPixelTransformParameteriEXT(proc, target, pname, param) \
  ( ((GdkGLProc_GLPIXELTRANSFORMPARAMETERIEXT) (proc)) (target, pname, param) )

/* glPixelTransformParameterfEXT */
typedef void (APIENTRY * GdkGLProc_GLPIXELTRANSFORMPARAMETERFEXT) (GLenum target, GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glPixelTransformParameterfEXT (void);
#define      gdk_gl_glPixelTransformParameterfEXT(proc, target, pname, param) \
  ( ((GdkGLProc_GLPIXELTRANSFORMPARAMETERFEXT) (proc)) (target, pname, param) )

/* glPixelTransformParameterivEXT */
typedef void (APIENTRY * GdkGLProc_GLPIXELTRANSFORMPARAMETERIVEXT) (GLenum target, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glPixelTransformParameterivEXT (void);
#define      gdk_gl_glPixelTransformParameterivEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLPIXELTRANSFORMPARAMETERIVEXT) (proc)) (target, pname, params) )

/* glPixelTransformParameterfvEXT */
typedef void (APIENTRY * GdkGLProc_GLPIXELTRANSFORMPARAMETERFVEXT) (GLenum target, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glPixelTransformParameterfvEXT (void);
#define      gdk_gl_glPixelTransformParameterfvEXT(proc, target, pname, params) \
  ( ((GdkGLProc_GLPIXELTRANSFORMPARAMETERFVEXT) (proc)) (target, pname, params) )

/* 
 * GL_EXT_secondary_color
 */

/* glSecondaryColor3bEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3BEXT) (GLbyte red, GLbyte green, GLbyte blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3bEXT (void);
#define      gdk_gl_glSecondaryColor3bEXT(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3BEXT) (proc)) (red, green, blue) )

/* glSecondaryColor3bvEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3BVEXT) (const GLbyte *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3bvEXT (void);
#define      gdk_gl_glSecondaryColor3bvEXT(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3BVEXT) (proc)) (v) )

/* glSecondaryColor3dEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3DEXT) (GLdouble red, GLdouble green, GLdouble blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3dEXT (void);
#define      gdk_gl_glSecondaryColor3dEXT(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3DEXT) (proc)) (red, green, blue) )

/* glSecondaryColor3dvEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3DVEXT) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3dvEXT (void);
#define      gdk_gl_glSecondaryColor3dvEXT(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3DVEXT) (proc)) (v) )

/* glSecondaryColor3fEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3FEXT) (GLfloat red, GLfloat green, GLfloat blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3fEXT (void);
#define      gdk_gl_glSecondaryColor3fEXT(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3FEXT) (proc)) (red, green, blue) )

/* glSecondaryColor3fvEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3FVEXT) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3fvEXT (void);
#define      gdk_gl_glSecondaryColor3fvEXT(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3FVEXT) (proc)) (v) )

/* glSecondaryColor3iEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3IEXT) (GLint red, GLint green, GLint blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3iEXT (void);
#define      gdk_gl_glSecondaryColor3iEXT(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3IEXT) (proc)) (red, green, blue) )

/* glSecondaryColor3ivEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3IVEXT) (const GLint *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3ivEXT (void);
#define      gdk_gl_glSecondaryColor3ivEXT(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3IVEXT) (proc)) (v) )

/* glSecondaryColor3sEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3SEXT) (GLshort red, GLshort green, GLshort blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3sEXT (void);
#define      gdk_gl_glSecondaryColor3sEXT(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3SEXT) (proc)) (red, green, blue) )

/* glSecondaryColor3svEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3SVEXT) (const GLshort *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3svEXT (void);
#define      gdk_gl_glSecondaryColor3svEXT(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3SVEXT) (proc)) (v) )

/* glSecondaryColor3ubEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3UBEXT) (GLubyte red, GLubyte green, GLubyte blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3ubEXT (void);
#define      gdk_gl_glSecondaryColor3ubEXT(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3UBEXT) (proc)) (red, green, blue) )

/* glSecondaryColor3ubvEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3UBVEXT) (const GLubyte *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3ubvEXT (void);
#define      gdk_gl_glSecondaryColor3ubvEXT(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3UBVEXT) (proc)) (v) )

/* glSecondaryColor3uiEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3UIEXT) (GLuint red, GLuint green, GLuint blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3uiEXT (void);
#define      gdk_gl_glSecondaryColor3uiEXT(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3UIEXT) (proc)) (red, green, blue) )

/* glSecondaryColor3uivEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3UIVEXT) (const GLuint *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3uivEXT (void);
#define      gdk_gl_glSecondaryColor3uivEXT(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3UIVEXT) (proc)) (v) )

/* glSecondaryColor3usEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3USEXT) (GLushort red, GLushort green, GLushort blue);
GdkGLProc    gdk_gl_get_glSecondaryColor3usEXT (void);
#define      gdk_gl_glSecondaryColor3usEXT(proc, red, green, blue) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3USEXT) (proc)) (red, green, blue) )

/* glSecondaryColor3usvEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLOR3USVEXT) (const GLushort *v);
GdkGLProc    gdk_gl_get_glSecondaryColor3usvEXT (void);
#define      gdk_gl_glSecondaryColor3usvEXT(proc, v) \
  ( ((GdkGLProc_GLSECONDARYCOLOR3USVEXT) (proc)) (v) )

/* glSecondaryColorPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLORPOINTEREXT) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glSecondaryColorPointerEXT (void);
#define      gdk_gl_glSecondaryColorPointerEXT(proc, size, type, stride, pointer) \
  ( ((GdkGLProc_GLSECONDARYCOLORPOINTEREXT) (proc)) (size, type, stride, pointer) )

/* 
 * GL_EXT_texture_perturb_normal
 */

/* glTextureNormalEXT */
typedef void (APIENTRY * GdkGLProc_GLTEXTURENORMALEXT) (GLenum mode);
GdkGLProc    gdk_gl_get_glTextureNormalEXT (void);
#define      gdk_gl_glTextureNormalEXT(proc, mode) \
  ( ((GdkGLProc_GLTEXTURENORMALEXT) (proc)) (mode) )

/* 
 * GL_EXT_multi_draw_arrays
 */

/* glMultiDrawArraysEXT */
typedef void (APIENTRY * GdkGLProc_GLMULTIDRAWARRAYSEXT) (GLenum mode, GLint *first, GLsizei *count, GLsizei primcount);
GdkGLProc    gdk_gl_get_glMultiDrawArraysEXT (void);
#define      gdk_gl_glMultiDrawArraysEXT(proc, mode, first, count, primcount) \
  ( ((GdkGLProc_GLMULTIDRAWARRAYSEXT) (proc)) (mode, first, count, primcount) )

/* glMultiDrawElementsEXT */
typedef void (APIENTRY * GdkGLProc_GLMULTIDRAWELEMENTSEXT) (GLenum mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount);
GdkGLProc    gdk_gl_get_glMultiDrawElementsEXT (void);
#define      gdk_gl_glMultiDrawElementsEXT(proc, mode, count, type, indices, primcount) \
  ( ((GdkGLProc_GLMULTIDRAWELEMENTSEXT) (proc)) (mode, count, type, indices, primcount) )

/* 
 * GL_EXT_fog_coord
 */

/* glFogCoordfEXT */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDFEXT) (GLfloat coord);
GdkGLProc    gdk_gl_get_glFogCoordfEXT (void);
#define      gdk_gl_glFogCoordfEXT(proc, coord) \
  ( ((GdkGLProc_GLFOGCOORDFEXT) (proc)) (coord) )

/* glFogCoordfvEXT */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDFVEXT) (const GLfloat *coord);
GdkGLProc    gdk_gl_get_glFogCoordfvEXT (void);
#define      gdk_gl_glFogCoordfvEXT(proc, coord) \
  ( ((GdkGLProc_GLFOGCOORDFVEXT) (proc)) (coord) )

/* glFogCoorddEXT */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDDEXT) (GLdouble coord);
GdkGLProc    gdk_gl_get_glFogCoorddEXT (void);
#define      gdk_gl_glFogCoorddEXT(proc, coord) \
  ( ((GdkGLProc_GLFOGCOORDDEXT) (proc)) (coord) )

/* glFogCoorddvEXT */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDDVEXT) (const GLdouble *coord);
GdkGLProc    gdk_gl_get_glFogCoorddvEXT (void);
#define      gdk_gl_glFogCoorddvEXT(proc, coord) \
  ( ((GdkGLProc_GLFOGCOORDDVEXT) (proc)) (coord) )

/* glFogCoordPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDPOINTEREXT) (GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glFogCoordPointerEXT (void);
#define      gdk_gl_glFogCoordPointerEXT(proc, type, stride, pointer) \
  ( ((GdkGLProc_GLFOGCOORDPOINTEREXT) (proc)) (type, stride, pointer) )

/* 
 * GL_EXT_coordinate_frame
 */

/* glTangent3bEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3BEXT) (GLbyte tx, GLbyte ty, GLbyte tz);
GdkGLProc    gdk_gl_get_glTangent3bEXT (void);
#define      gdk_gl_glTangent3bEXT(proc, tx, ty, tz) \
  ( ((GdkGLProc_GLTANGENT3BEXT) (proc)) (tx, ty, tz) )

/* glTangent3bvEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3BVEXT) (const GLbyte *v);
GdkGLProc    gdk_gl_get_glTangent3bvEXT (void);
#define      gdk_gl_glTangent3bvEXT(proc, v) \
  ( ((GdkGLProc_GLTANGENT3BVEXT) (proc)) (v) )

/* glTangent3dEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3DEXT) (GLdouble tx, GLdouble ty, GLdouble tz);
GdkGLProc    gdk_gl_get_glTangent3dEXT (void);
#define      gdk_gl_glTangent3dEXT(proc, tx, ty, tz) \
  ( ((GdkGLProc_GLTANGENT3DEXT) (proc)) (tx, ty, tz) )

/* glTangent3dvEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3DVEXT) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glTangent3dvEXT (void);
#define      gdk_gl_glTangent3dvEXT(proc, v) \
  ( ((GdkGLProc_GLTANGENT3DVEXT) (proc)) (v) )

/* glTangent3fEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3FEXT) (GLfloat tx, GLfloat ty, GLfloat tz);
GdkGLProc    gdk_gl_get_glTangent3fEXT (void);
#define      gdk_gl_glTangent3fEXT(proc, tx, ty, tz) \
  ( ((GdkGLProc_GLTANGENT3FEXT) (proc)) (tx, ty, tz) )

/* glTangent3fvEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3FVEXT) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glTangent3fvEXT (void);
#define      gdk_gl_glTangent3fvEXT(proc, v) \
  ( ((GdkGLProc_GLTANGENT3FVEXT) (proc)) (v) )

/* glTangent3iEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3IEXT) (GLint tx, GLint ty, GLint tz);
GdkGLProc    gdk_gl_get_glTangent3iEXT (void);
#define      gdk_gl_glTangent3iEXT(proc, tx, ty, tz) \
  ( ((GdkGLProc_GLTANGENT3IEXT) (proc)) (tx, ty, tz) )

/* glTangent3ivEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3IVEXT) (const GLint *v);
GdkGLProc    gdk_gl_get_glTangent3ivEXT (void);
#define      gdk_gl_glTangent3ivEXT(proc, v) \
  ( ((GdkGLProc_GLTANGENT3IVEXT) (proc)) (v) )

/* glTangent3sEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3SEXT) (GLshort tx, GLshort ty, GLshort tz);
GdkGLProc    gdk_gl_get_glTangent3sEXT (void);
#define      gdk_gl_glTangent3sEXT(proc, tx, ty, tz) \
  ( ((GdkGLProc_GLTANGENT3SEXT) (proc)) (tx, ty, tz) )

/* glTangent3svEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENT3SVEXT) (const GLshort *v);
GdkGLProc    gdk_gl_get_glTangent3svEXT (void);
#define      gdk_gl_glTangent3svEXT(proc, v) \
  ( ((GdkGLProc_GLTANGENT3SVEXT) (proc)) (v) )

/* glBinormal3bEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3BEXT) (GLbyte bx, GLbyte by, GLbyte bz);
GdkGLProc    gdk_gl_get_glBinormal3bEXT (void);
#define      gdk_gl_glBinormal3bEXT(proc, bx, by, bz) \
  ( ((GdkGLProc_GLBINORMAL3BEXT) (proc)) (bx, by, bz) )

/* glBinormal3bvEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3BVEXT) (const GLbyte *v);
GdkGLProc    gdk_gl_get_glBinormal3bvEXT (void);
#define      gdk_gl_glBinormal3bvEXT(proc, v) \
  ( ((GdkGLProc_GLBINORMAL3BVEXT) (proc)) (v) )

/* glBinormal3dEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3DEXT) (GLdouble bx, GLdouble by, GLdouble bz);
GdkGLProc    gdk_gl_get_glBinormal3dEXT (void);
#define      gdk_gl_glBinormal3dEXT(proc, bx, by, bz) \
  ( ((GdkGLProc_GLBINORMAL3DEXT) (proc)) (bx, by, bz) )

/* glBinormal3dvEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3DVEXT) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glBinormal3dvEXT (void);
#define      gdk_gl_glBinormal3dvEXT(proc, v) \
  ( ((GdkGLProc_GLBINORMAL3DVEXT) (proc)) (v) )

/* glBinormal3fEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3FEXT) (GLfloat bx, GLfloat by, GLfloat bz);
GdkGLProc    gdk_gl_get_glBinormal3fEXT (void);
#define      gdk_gl_glBinormal3fEXT(proc, bx, by, bz) \
  ( ((GdkGLProc_GLBINORMAL3FEXT) (proc)) (bx, by, bz) )

/* glBinormal3fvEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3FVEXT) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glBinormal3fvEXT (void);
#define      gdk_gl_glBinormal3fvEXT(proc, v) \
  ( ((GdkGLProc_GLBINORMAL3FVEXT) (proc)) (v) )

/* glBinormal3iEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3IEXT) (GLint bx, GLint by, GLint bz);
GdkGLProc    gdk_gl_get_glBinormal3iEXT (void);
#define      gdk_gl_glBinormal3iEXT(proc, bx, by, bz) \
  ( ((GdkGLProc_GLBINORMAL3IEXT) (proc)) (bx, by, bz) )

/* glBinormal3ivEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3IVEXT) (const GLint *v);
GdkGLProc    gdk_gl_get_glBinormal3ivEXT (void);
#define      gdk_gl_glBinormal3ivEXT(proc, v) \
  ( ((GdkGLProc_GLBINORMAL3IVEXT) (proc)) (v) )

/* glBinormal3sEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3SEXT) (GLshort bx, GLshort by, GLshort bz);
GdkGLProc    gdk_gl_get_glBinormal3sEXT (void);
#define      gdk_gl_glBinormal3sEXT(proc, bx, by, bz) \
  ( ((GdkGLProc_GLBINORMAL3SEXT) (proc)) (bx, by, bz) )

/* glBinormal3svEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMAL3SVEXT) (const GLshort *v);
GdkGLProc    gdk_gl_get_glBinormal3svEXT (void);
#define      gdk_gl_glBinormal3svEXT(proc, v) \
  ( ((GdkGLProc_GLBINORMAL3SVEXT) (proc)) (v) )

/* glTangentPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLTANGENTPOINTEREXT) (GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glTangentPointerEXT (void);
#define      gdk_gl_glTangentPointerEXT(proc, type, stride, pointer) \
  ( ((GdkGLProc_GLTANGENTPOINTEREXT) (proc)) (type, stride, pointer) )

/* glBinormalPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLBINORMALPOINTEREXT) (GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glBinormalPointerEXT (void);
#define      gdk_gl_glBinormalPointerEXT(proc, type, stride, pointer) \
  ( ((GdkGLProc_GLBINORMALPOINTEREXT) (proc)) (type, stride, pointer) )

/* 
 * GL_SUNX_constant_data
 */

/* glFinishTextureSUNX */
typedef void (APIENTRY * GdkGLProc_GLFINISHTEXTURESUNX) (void);
GdkGLProc    gdk_gl_get_glFinishTextureSUNX (void);
#define      gdk_gl_glFinishTextureSUNX(proc) \
  ( ((GdkGLProc_GLFINISHTEXTURESUNX) (proc)) () )

/* 
 * GL_SUN_global_alpha
 */

/* glGlobalAlphaFactorbSUN */
typedef void (APIENTRY * GdkGLProc_GLGLOBALALPHAFACTORBSUN) (GLbyte factor);
GdkGLProc    gdk_gl_get_glGlobalAlphaFactorbSUN (void);
#define      gdk_gl_glGlobalAlphaFactorbSUN(proc, factor) \
  ( ((GdkGLProc_GLGLOBALALPHAFACTORBSUN) (proc)) (factor) )

/* glGlobalAlphaFactorsSUN */
typedef void (APIENTRY * GdkGLProc_GLGLOBALALPHAFACTORSSUN) (GLshort factor);
GdkGLProc    gdk_gl_get_glGlobalAlphaFactorsSUN (void);
#define      gdk_gl_glGlobalAlphaFactorsSUN(proc, factor) \
  ( ((GdkGLProc_GLGLOBALALPHAFACTORSSUN) (proc)) (factor) )

/* glGlobalAlphaFactoriSUN */
typedef void (APIENTRY * GdkGLProc_GLGLOBALALPHAFACTORISUN) (GLint factor);
GdkGLProc    gdk_gl_get_glGlobalAlphaFactoriSUN (void);
#define      gdk_gl_glGlobalAlphaFactoriSUN(proc, factor) \
  ( ((GdkGLProc_GLGLOBALALPHAFACTORISUN) (proc)) (factor) )

/* glGlobalAlphaFactorfSUN */
typedef void (APIENTRY * GdkGLProc_GLGLOBALALPHAFACTORFSUN) (GLfloat factor);
GdkGLProc    gdk_gl_get_glGlobalAlphaFactorfSUN (void);
#define      gdk_gl_glGlobalAlphaFactorfSUN(proc, factor) \
  ( ((GdkGLProc_GLGLOBALALPHAFACTORFSUN) (proc)) (factor) )

/* glGlobalAlphaFactordSUN */
typedef void (APIENTRY * GdkGLProc_GLGLOBALALPHAFACTORDSUN) (GLdouble factor);
GdkGLProc    gdk_gl_get_glGlobalAlphaFactordSUN (void);
#define      gdk_gl_glGlobalAlphaFactordSUN(proc, factor) \
  ( ((GdkGLProc_GLGLOBALALPHAFACTORDSUN) (proc)) (factor) )

/* glGlobalAlphaFactorubSUN */
typedef void (APIENTRY * GdkGLProc_GLGLOBALALPHAFACTORUBSUN) (GLubyte factor);
GdkGLProc    gdk_gl_get_glGlobalAlphaFactorubSUN (void);
#define      gdk_gl_glGlobalAlphaFactorubSUN(proc, factor) \
  ( ((GdkGLProc_GLGLOBALALPHAFACTORUBSUN) (proc)) (factor) )

/* glGlobalAlphaFactorusSUN */
typedef void (APIENTRY * GdkGLProc_GLGLOBALALPHAFACTORUSSUN) (GLushort factor);
GdkGLProc    gdk_gl_get_glGlobalAlphaFactorusSUN (void);
#define      gdk_gl_glGlobalAlphaFactorusSUN(proc, factor) \
  ( ((GdkGLProc_GLGLOBALALPHAFACTORUSSUN) (proc)) (factor) )

/* glGlobalAlphaFactoruiSUN */
typedef void (APIENTRY * GdkGLProc_GLGLOBALALPHAFACTORUISUN) (GLuint factor);
GdkGLProc    gdk_gl_get_glGlobalAlphaFactoruiSUN (void);
#define      gdk_gl_glGlobalAlphaFactoruiSUN(proc, factor) \
  ( ((GdkGLProc_GLGLOBALALPHAFACTORUISUN) (proc)) (factor) )

/* 
 * GL_SUN_triangle_list
 */

/* glReplacementCodeuiSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUISUN) (GLuint code);
GdkGLProc    gdk_gl_get_glReplacementCodeuiSUN (void);
#define      gdk_gl_glReplacementCodeuiSUN(proc, code) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUISUN) (proc)) (code) )

/* glReplacementCodeusSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUSSUN) (GLushort code);
GdkGLProc    gdk_gl_get_glReplacementCodeusSUN (void);
#define      gdk_gl_glReplacementCodeusSUN(proc, code) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUSSUN) (proc)) (code) )

/* glReplacementCodeubSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUBSUN) (GLubyte code);
GdkGLProc    gdk_gl_get_glReplacementCodeubSUN (void);
#define      gdk_gl_glReplacementCodeubSUN(proc, code) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUBSUN) (proc)) (code) )

/* glReplacementCodeuivSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUIVSUN) (const GLuint *code);
GdkGLProc    gdk_gl_get_glReplacementCodeuivSUN (void);
#define      gdk_gl_glReplacementCodeuivSUN(proc, code) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUIVSUN) (proc)) (code) )

/* glReplacementCodeusvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUSVSUN) (const GLushort *code);
GdkGLProc    gdk_gl_get_glReplacementCodeusvSUN (void);
#define      gdk_gl_glReplacementCodeusvSUN(proc, code) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUSVSUN) (proc)) (code) )

/* glReplacementCodeubvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUBVSUN) (const GLubyte *code);
GdkGLProc    gdk_gl_get_glReplacementCodeubvSUN (void);
#define      gdk_gl_glReplacementCodeubvSUN(proc, code) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUBVSUN) (proc)) (code) )

/* glReplacementCodePointerSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEPOINTERSUN) (GLenum type, GLsizei stride, const GLvoid* *pointer);
GdkGLProc    gdk_gl_get_glReplacementCodePointerSUN (void);
#define      gdk_gl_glReplacementCodePointerSUN(proc, type, stride, pointer) \
  ( ((GdkGLProc_GLREPLACEMENTCODEPOINTERSUN) (proc)) (type, stride, pointer) )

/* 
 * GL_SUN_vertex
 */

/* glColor4ubVertex2fSUN */
typedef void (APIENTRY * GdkGLProc_GLCOLOR4UBVERTEX2FSUN) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
GdkGLProc    gdk_gl_get_glColor4ubVertex2fSUN (void);
#define      gdk_gl_glColor4ubVertex2fSUN(proc, r, g, b, a, x, y) \
  ( ((GdkGLProc_GLCOLOR4UBVERTEX2FSUN) (proc)) (r, g, b, a, x, y) )

/* glColor4ubVertex2fvSUN */
typedef void (APIENTRY * GdkGLProc_GLCOLOR4UBVERTEX2FVSUN) (const GLubyte *c, const GLfloat *v);
GdkGLProc    gdk_gl_get_glColor4ubVertex2fvSUN (void);
#define      gdk_gl_glColor4ubVertex2fvSUN(proc, c, v) \
  ( ((GdkGLProc_GLCOLOR4UBVERTEX2FVSUN) (proc)) (c, v) )

/* glColor4ubVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLCOLOR4UBVERTEX3FSUN) (GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glColor4ubVertex3fSUN (void);
#define      gdk_gl_glColor4ubVertex3fSUN(proc, r, g, b, a, x, y, z) \
  ( ((GdkGLProc_GLCOLOR4UBVERTEX3FSUN) (proc)) (r, g, b, a, x, y, z) )

/* glColor4ubVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLCOLOR4UBVERTEX3FVSUN) (const GLubyte *c, const GLfloat *v);
GdkGLProc    gdk_gl_get_glColor4ubVertex3fvSUN (void);
#define      gdk_gl_glColor4ubVertex3fvSUN(proc, c, v) \
  ( ((GdkGLProc_GLCOLOR4UBVERTEX3FVSUN) (proc)) (c, v) )

/* glColor3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLCOLOR3FVERTEX3FSUN) (GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glColor3fVertex3fSUN (void);
#define      gdk_gl_glColor3fVertex3fSUN(proc, r, g, b, x, y, z) \
  ( ((GdkGLProc_GLCOLOR3FVERTEX3FSUN) (proc)) (r, g, b, x, y, z) )

/* glColor3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLCOLOR3FVERTEX3FVSUN) (const GLfloat *c, const GLfloat *v);
GdkGLProc    gdk_gl_get_glColor3fVertex3fvSUN (void);
#define      gdk_gl_glColor3fVertex3fvSUN(proc, c, v) \
  ( ((GdkGLProc_GLCOLOR3FVERTEX3FVSUN) (proc)) (c, v) )

/* glNormal3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLNORMAL3FVERTEX3FSUN) (GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glNormal3fVertex3fSUN (void);
#define      gdk_gl_glNormal3fVertex3fSUN(proc, nx, ny, nz, x, y, z) \
  ( ((GdkGLProc_GLNORMAL3FVERTEX3FSUN) (proc)) (nx, ny, nz, x, y, z) )

/* glNormal3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLNORMAL3FVERTEX3FVSUN) (const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glNormal3fVertex3fvSUN (void);
#define      gdk_gl_glNormal3fVertex3fvSUN(proc, n, v) \
  ( ((GdkGLProc_GLNORMAL3FVERTEX3FVSUN) (proc)) (n, v) )

/* glColor4fNormal3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLCOLOR4FNORMAL3FVERTEX3FSUN) (GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glColor4fNormal3fVertex3fSUN (void);
#define      gdk_gl_glColor4fNormal3fVertex3fSUN(proc, r, g, b, a, nx, ny, nz, x, y, z) \
  ( ((GdkGLProc_GLCOLOR4FNORMAL3FVERTEX3FSUN) (proc)) (r, g, b, a, nx, ny, nz, x, y, z) )

/* glColor4fNormal3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLCOLOR4FNORMAL3FVERTEX3FVSUN) (const GLfloat *c, const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glColor4fNormal3fVertex3fvSUN (void);
#define      gdk_gl_glColor4fNormal3fVertex3fvSUN(proc, c, n, v) \
  ( ((GdkGLProc_GLCOLOR4FNORMAL3FVERTEX3FVSUN) (proc)) (c, n, v) )

/* glTexCoord2fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FVERTEX3FSUN) (GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glTexCoord2fVertex3fSUN (void);
#define      gdk_gl_glTexCoord2fVertex3fSUN(proc, s, t, x, y, z) \
  ( ((GdkGLProc_GLTEXCOORD2FVERTEX3FSUN) (proc)) (s, t, x, y, z) )

/* glTexCoord2fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FVERTEX3FVSUN) (const GLfloat *tc, const GLfloat *v);
GdkGLProc    gdk_gl_get_glTexCoord2fVertex3fvSUN (void);
#define      gdk_gl_glTexCoord2fVertex3fvSUN(proc, tc, v) \
  ( ((GdkGLProc_GLTEXCOORD2FVERTEX3FVSUN) (proc)) (tc, v) )

/* glTexCoord4fVertex4fSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD4FVERTEX4FSUN) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glTexCoord4fVertex4fSUN (void);
#define      gdk_gl_glTexCoord4fVertex4fSUN(proc, s, t, p, q, x, y, z, w) \
  ( ((GdkGLProc_GLTEXCOORD4FVERTEX4FSUN) (proc)) (s, t, p, q, x, y, z, w) )

/* glTexCoord4fVertex4fvSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD4FVERTEX4FVSUN) (const GLfloat *tc, const GLfloat *v);
GdkGLProc    gdk_gl_get_glTexCoord4fVertex4fvSUN (void);
#define      gdk_gl_glTexCoord4fVertex4fvSUN(proc, tc, v) \
  ( ((GdkGLProc_GLTEXCOORD4FVERTEX4FVSUN) (proc)) (tc, v) )

/* glTexCoord2fColor4ubVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FCOLOR4UBVERTEX3FSUN) (GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glTexCoord2fColor4ubVertex3fSUN (void);
#define      gdk_gl_glTexCoord2fColor4ubVertex3fSUN(proc, s, t, r, g, b, a, x, y, z) \
  ( ((GdkGLProc_GLTEXCOORD2FCOLOR4UBVERTEX3FSUN) (proc)) (s, t, r, g, b, a, x, y, z) )

/* glTexCoord2fColor4ubVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FCOLOR4UBVERTEX3FVSUN) (const GLfloat *tc, const GLubyte *c, const GLfloat *v);
GdkGLProc    gdk_gl_get_glTexCoord2fColor4ubVertex3fvSUN (void);
#define      gdk_gl_glTexCoord2fColor4ubVertex3fvSUN(proc, tc, c, v) \
  ( ((GdkGLProc_GLTEXCOORD2FCOLOR4UBVERTEX3FVSUN) (proc)) (tc, c, v) )

/* glTexCoord2fColor3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FCOLOR3FVERTEX3FSUN) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glTexCoord2fColor3fVertex3fSUN (void);
#define      gdk_gl_glTexCoord2fColor3fVertex3fSUN(proc, s, t, r, g, b, x, y, z) \
  ( ((GdkGLProc_GLTEXCOORD2FCOLOR3FVERTEX3FSUN) (proc)) (s, t, r, g, b, x, y, z) )

/* glTexCoord2fColor3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FCOLOR3FVERTEX3FVSUN) (const GLfloat *tc, const GLfloat *c, const GLfloat *v);
GdkGLProc    gdk_gl_get_glTexCoord2fColor3fVertex3fvSUN (void);
#define      gdk_gl_glTexCoord2fColor3fVertex3fvSUN(proc, tc, c, v) \
  ( ((GdkGLProc_GLTEXCOORD2FCOLOR3FVERTEX3FVSUN) (proc)) (tc, c, v) )

/* glTexCoord2fNormal3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FNORMAL3FVERTEX3FSUN) (GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glTexCoord2fNormal3fVertex3fSUN (void);
#define      gdk_gl_glTexCoord2fNormal3fVertex3fSUN(proc, s, t, nx, ny, nz, x, y, z) \
  ( ((GdkGLProc_GLTEXCOORD2FNORMAL3FVERTEX3FSUN) (proc)) (s, t, nx, ny, nz, x, y, z) )

/* glTexCoord2fNormal3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FNORMAL3FVERTEX3FVSUN) (const GLfloat *tc, const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glTexCoord2fNormal3fVertex3fvSUN (void);
#define      gdk_gl_glTexCoord2fNormal3fVertex3fvSUN(proc, tc, n, v) \
  ( ((GdkGLProc_GLTEXCOORD2FNORMAL3FVERTEX3FVSUN) (proc)) (tc, n, v) )

/* glTexCoord2fColor4fNormal3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUN) (GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glTexCoord2fColor4fNormal3fVertex3fSUN (void);
#define      gdk_gl_glTexCoord2fColor4fNormal3fVertex3fSUN(proc, s, t, r, g, b, a, nx, ny, nz, x, y, z) \
  ( ((GdkGLProc_GLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUN) (proc)) (s, t, r, g, b, a, nx, ny, nz, x, y, z) )

/* glTexCoord2fColor4fNormal3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUN) (const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glTexCoord2fColor4fNormal3fVertex3fvSUN (void);
#define      gdk_gl_glTexCoord2fColor4fNormal3fVertex3fvSUN(proc, tc, c, n, v) \
  ( ((GdkGLProc_GLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUN) (proc)) (tc, c, n, v) )

/* glTexCoord4fColor4fNormal3fVertex4fSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUN) (GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glTexCoord4fColor4fNormal3fVertex4fSUN (void);
#define      gdk_gl_glTexCoord4fColor4fNormal3fVertex4fSUN(proc, s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w) \
  ( ((GdkGLProc_GLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUN) (proc)) (s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w) )

/* glTexCoord4fColor4fNormal3fVertex4fvSUN */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUN) (const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glTexCoord4fColor4fNormal3fVertex4fvSUN (void);
#define      gdk_gl_glTexCoord4fColor4fNormal3fVertex4fvSUN(proc, tc, c, n, v) \
  ( ((GdkGLProc_GLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUN) (proc)) (tc, c, n, v) )

/* glReplacementCodeuiVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUIVERTEX3FSUN) (GLuint rc, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glReplacementCodeuiVertex3fSUN (void);
#define      gdk_gl_glReplacementCodeuiVertex3fSUN(proc, rc, x, y, z) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUIVERTEX3FSUN) (proc)) (rc, x, y, z) )

/* glReplacementCodeuiVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUIVERTEX3FVSUN) (const GLuint *rc, const GLfloat *v);
GdkGLProc    gdk_gl_get_glReplacementCodeuiVertex3fvSUN (void);
#define      gdk_gl_glReplacementCodeuiVertex3fvSUN(proc, rc, v) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUIVERTEX3FVSUN) (proc)) (rc, v) )

/* glReplacementCodeuiColor4ubVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUN) (GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glReplacementCodeuiColor4ubVertex3fSUN (void);
#define      gdk_gl_glReplacementCodeuiColor4ubVertex3fSUN(proc, rc, r, g, b, a, x, y, z) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUN) (proc)) (rc, r, g, b, a, x, y, z) )

/* glReplacementCodeuiColor4ubVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUN) (const GLuint *rc, const GLubyte *c, const GLfloat *v);
GdkGLProc    gdk_gl_get_glReplacementCodeuiColor4ubVertex3fvSUN (void);
#define      gdk_gl_glReplacementCodeuiColor4ubVertex3fvSUN(proc, rc, c, v) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUN) (proc)) (rc, c, v) )

/* glReplacementCodeuiColor3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUICOLOR3FVERTEX3FSUN) (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glReplacementCodeuiColor3fVertex3fSUN (void);
#define      gdk_gl_glReplacementCodeuiColor3fVertex3fSUN(proc, rc, r, g, b, x, y, z) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUICOLOR3FVERTEX3FSUN) (proc)) (rc, r, g, b, x, y, z) )

/* glReplacementCodeuiColor3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUN) (const GLuint *rc, const GLfloat *c, const GLfloat *v);
GdkGLProc    gdk_gl_get_glReplacementCodeuiColor3fVertex3fvSUN (void);
#define      gdk_gl_glReplacementCodeuiColor3fVertex3fvSUN(proc, rc, c, v) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUN) (proc)) (rc, c, v) )

/* glReplacementCodeuiNormal3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUINORMAL3FVERTEX3FSUN) (GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glReplacementCodeuiNormal3fVertex3fSUN (void);
#define      gdk_gl_glReplacementCodeuiNormal3fVertex3fSUN(proc, rc, nx, ny, nz, x, y, z) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUINORMAL3FVERTEX3FSUN) (proc)) (rc, nx, ny, nz, x, y, z) )

/* glReplacementCodeuiNormal3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUN) (const GLuint *rc, const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glReplacementCodeuiNormal3fVertex3fvSUN (void);
#define      gdk_gl_glReplacementCodeuiNormal3fVertex3fvSUN(proc, rc, n, v) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUN) (proc)) (rc, n, v) )

/* glReplacementCodeuiColor4fNormal3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUN) (GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glReplacementCodeuiColor4fNormal3fVertex3fSUN (void);
#define      gdk_gl_glReplacementCodeuiColor4fNormal3fVertex3fSUN(proc, rc, r, g, b, a, nx, ny, nz, x, y, z) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUN) (proc)) (rc, r, g, b, a, nx, ny, nz, x, y, z) )

/* glReplacementCodeuiColor4fNormal3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUN) (const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glReplacementCodeuiColor4fNormal3fVertex3fvSUN (void);
#define      gdk_gl_glReplacementCodeuiColor4fNormal3fVertex3fvSUN(proc, rc, c, n, v) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUN) (proc)) (rc, c, n, v) )

/* glReplacementCodeuiTexCoord2fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUN) (GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glReplacementCodeuiTexCoord2fVertex3fSUN (void);
#define      gdk_gl_glReplacementCodeuiTexCoord2fVertex3fSUN(proc, rc, s, t, x, y, z) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUN) (proc)) (rc, s, t, x, y, z) )

/* glReplacementCodeuiTexCoord2fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUN) (const GLuint *rc, const GLfloat *tc, const GLfloat *v);
GdkGLProc    gdk_gl_get_glReplacementCodeuiTexCoord2fVertex3fvSUN (void);
#define      gdk_gl_glReplacementCodeuiTexCoord2fVertex3fvSUN(proc, rc, tc, v) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUN) (proc)) (rc, tc, v) )

/* glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUN) (GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN (void);
#define      gdk_gl_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(proc, rc, s, t, nx, ny, nz, x, y, z) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUN) (proc)) (rc, s, t, nx, ny, nz, x, y, z) )

/* glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUN) (const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN (void);
#define      gdk_gl_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(proc, rc, tc, n, v) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUN) (proc)) (rc, tc, n, v) )

/* glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUN) (GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN (void);
#define      gdk_gl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(proc, rc, s, t, r, g, b, a, nx, ny, nz, x, y, z) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUN) (proc)) (rc, s, t, r, g, b, a, nx, ny, nz, x, y, z) )

/* glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN */
typedef void (APIENTRY * GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUN) (const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
GdkGLProc    gdk_gl_get_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN (void);
#define      gdk_gl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(proc, rc, tc, c, n, v) \
  ( ((GdkGLProc_GLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUN) (proc)) (rc, tc, c, n, v) )

/* 
 * GL_EXT_blend_func_separate
 */

/* glBlendFuncSeparateEXT */
typedef void (APIENTRY * GdkGLProc_GLBLENDFUNCSEPARATEEXT) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GdkGLProc    gdk_gl_get_glBlendFuncSeparateEXT (void);
#define      gdk_gl_glBlendFuncSeparateEXT(proc, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) \
  ( ((GdkGLProc_GLBLENDFUNCSEPARATEEXT) (proc)) (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) )

/* 
 * GL_INGR_blend_func_separate
 */

/* glBlendFuncSeparateINGR */
typedef void (APIENTRY * GdkGLProc_GLBLENDFUNCSEPARATEINGR) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GdkGLProc    gdk_gl_get_glBlendFuncSeparateINGR (void);
#define      gdk_gl_glBlendFuncSeparateINGR(proc, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) \
  ( ((GdkGLProc_GLBLENDFUNCSEPARATEINGR) (proc)) (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) )

/* 
 * GL_EXT_vertex_weighting
 */

/* glVertexWeightfEXT */
typedef void (APIENTRY * GdkGLProc_GLVERTEXWEIGHTFEXT) (GLfloat weight);
GdkGLProc    gdk_gl_get_glVertexWeightfEXT (void);
#define      gdk_gl_glVertexWeightfEXT(proc, weight) \
  ( ((GdkGLProc_GLVERTEXWEIGHTFEXT) (proc)) (weight) )

/* glVertexWeightfvEXT */
typedef void (APIENTRY * GdkGLProc_GLVERTEXWEIGHTFVEXT) (const GLfloat *weight);
GdkGLProc    gdk_gl_get_glVertexWeightfvEXT (void);
#define      gdk_gl_glVertexWeightfvEXT(proc, weight) \
  ( ((GdkGLProc_GLVERTEXWEIGHTFVEXT) (proc)) (weight) )

/* glVertexWeightPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLVERTEXWEIGHTPOINTEREXT) (GLsizei size, GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glVertexWeightPointerEXT (void);
#define      gdk_gl_glVertexWeightPointerEXT(proc, size, type, stride, pointer) \
  ( ((GdkGLProc_GLVERTEXWEIGHTPOINTEREXT) (proc)) (size, type, stride, pointer) )

/* 
 * GL_NV_vertex_array_range
 */

/* glFlushVertexArrayRangeNV */
typedef void (APIENTRY * GdkGLProc_GLFLUSHVERTEXARRAYRANGENV) (void);
GdkGLProc    gdk_gl_get_glFlushVertexArrayRangeNV (void);
#define      gdk_gl_glFlushVertexArrayRangeNV(proc) \
  ( ((GdkGLProc_GLFLUSHVERTEXARRAYRANGENV) (proc)) () )

/* glVertexArrayRangeNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXARRAYRANGENV) (GLsizei length, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glVertexArrayRangeNV (void);
#define      gdk_gl_glVertexArrayRangeNV(proc, length, pointer) \
  ( ((GdkGLProc_GLVERTEXARRAYRANGENV) (proc)) (length, pointer) )

/* 
 * GL_NV_register_combiners
 */

/* glCombinerParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLCOMBINERPARAMETERFVNV) (GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glCombinerParameterfvNV (void);
#define      gdk_gl_glCombinerParameterfvNV(proc, pname, params) \
  ( ((GdkGLProc_GLCOMBINERPARAMETERFVNV) (proc)) (pname, params) )

/* glCombinerParameterfNV */
typedef void (APIENTRY * GdkGLProc_GLCOMBINERPARAMETERFNV) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glCombinerParameterfNV (void);
#define      gdk_gl_glCombinerParameterfNV(proc, pname, param) \
  ( ((GdkGLProc_GLCOMBINERPARAMETERFNV) (proc)) (pname, param) )

/* glCombinerParameterivNV */
typedef void (APIENTRY * GdkGLProc_GLCOMBINERPARAMETERIVNV) (GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glCombinerParameterivNV (void);
#define      gdk_gl_glCombinerParameterivNV(proc, pname, params) \
  ( ((GdkGLProc_GLCOMBINERPARAMETERIVNV) (proc)) (pname, params) )

/* glCombinerParameteriNV */
typedef void (APIENTRY * GdkGLProc_GLCOMBINERPARAMETERINV) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glCombinerParameteriNV (void);
#define      gdk_gl_glCombinerParameteriNV(proc, pname, param) \
  ( ((GdkGLProc_GLCOMBINERPARAMETERINV) (proc)) (pname, param) )

/* glCombinerInputNV */
typedef void (APIENTRY * GdkGLProc_GLCOMBINERINPUTNV) (GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GdkGLProc    gdk_gl_get_glCombinerInputNV (void);
#define      gdk_gl_glCombinerInputNV(proc, stage, portion, variable, input, mapping, componentUsage) \
  ( ((GdkGLProc_GLCOMBINERINPUTNV) (proc)) (stage, portion, variable, input, mapping, componentUsage) )

/* glCombinerOutputNV */
typedef void (APIENTRY * GdkGLProc_GLCOMBINEROUTPUTNV) (GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
GdkGLProc    gdk_gl_get_glCombinerOutputNV (void);
#define      gdk_gl_glCombinerOutputNV(proc, stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum) \
  ( ((GdkGLProc_GLCOMBINEROUTPUTNV) (proc)) (stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum) )

/* glFinalCombinerInputNV */
typedef void (APIENTRY * GdkGLProc_GLFINALCOMBINERINPUTNV) (GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
GdkGLProc    gdk_gl_get_glFinalCombinerInputNV (void);
#define      gdk_gl_glFinalCombinerInputNV(proc, variable, input, mapping, componentUsage) \
  ( ((GdkGLProc_GLFINALCOMBINERINPUTNV) (proc)) (variable, input, mapping, componentUsage) )

/* glGetCombinerInputParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLGETCOMBINERINPUTPARAMETERFVNV) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetCombinerInputParameterfvNV (void);
#define      gdk_gl_glGetCombinerInputParameterfvNV(proc, stage, portion, variable, pname, params) \
  ( ((GdkGLProc_GLGETCOMBINERINPUTPARAMETERFVNV) (proc)) (stage, portion, variable, pname, params) )

/* glGetCombinerInputParameterivNV */
typedef void (APIENTRY * GdkGLProc_GLGETCOMBINERINPUTPARAMETERIVNV) (GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetCombinerInputParameterivNV (void);
#define      gdk_gl_glGetCombinerInputParameterivNV(proc, stage, portion, variable, pname, params) \
  ( ((GdkGLProc_GLGETCOMBINERINPUTPARAMETERIVNV) (proc)) (stage, portion, variable, pname, params) )

/* glGetCombinerOutputParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLGETCOMBINEROUTPUTPARAMETERFVNV) (GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetCombinerOutputParameterfvNV (void);
#define      gdk_gl_glGetCombinerOutputParameterfvNV(proc, stage, portion, pname, params) \
  ( ((GdkGLProc_GLGETCOMBINEROUTPUTPARAMETERFVNV) (proc)) (stage, portion, pname, params) )

/* glGetCombinerOutputParameterivNV */
typedef void (APIENTRY * GdkGLProc_GLGETCOMBINEROUTPUTPARAMETERIVNV) (GLenum stage, GLenum portion, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetCombinerOutputParameterivNV (void);
#define      gdk_gl_glGetCombinerOutputParameterivNV(proc, stage, portion, pname, params) \
  ( ((GdkGLProc_GLGETCOMBINEROUTPUTPARAMETERIVNV) (proc)) (stage, portion, pname, params) )

/* glGetFinalCombinerInputParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLGETFINALCOMBINERINPUTPARAMETERFVNV) (GLenum variable, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetFinalCombinerInputParameterfvNV (void);
#define      gdk_gl_glGetFinalCombinerInputParameterfvNV(proc, variable, pname, params) \
  ( ((GdkGLProc_GLGETFINALCOMBINERINPUTPARAMETERFVNV) (proc)) (variable, pname, params) )

/* glGetFinalCombinerInputParameterivNV */
typedef void (APIENTRY * GdkGLProc_GLGETFINALCOMBINERINPUTPARAMETERIVNV) (GLenum variable, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetFinalCombinerInputParameterivNV (void);
#define      gdk_gl_glGetFinalCombinerInputParameterivNV(proc, variable, pname, params) \
  ( ((GdkGLProc_GLGETFINALCOMBINERINPUTPARAMETERIVNV) (proc)) (variable, pname, params) )

/* 
 * GL_MESA_resize_buffers
 */

/* glResizeBuffersMESA */
typedef void (APIENTRY * GdkGLProc_GLRESIZEBUFFERSMESA) (void);
GdkGLProc    gdk_gl_get_glResizeBuffersMESA (void);
#define      gdk_gl_glResizeBuffersMESA(proc) \
  ( ((GdkGLProc_GLRESIZEBUFFERSMESA) (proc)) () )

/* 
 * GL_MESA_window_pos
 */

/* glWindowPos2dMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2DMESA) (GLdouble x, GLdouble y);
GdkGLProc    gdk_gl_get_glWindowPos2dMESA (void);
#define      gdk_gl_glWindowPos2dMESA(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2DMESA) (proc)) (x, y) )

/* glWindowPos2dvMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2DVMESA) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glWindowPos2dvMESA (void);
#define      gdk_gl_glWindowPos2dvMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2DVMESA) (proc)) (v) )

/* glWindowPos2fMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2FMESA) (GLfloat x, GLfloat y);
GdkGLProc    gdk_gl_get_glWindowPos2fMESA (void);
#define      gdk_gl_glWindowPos2fMESA(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2FMESA) (proc)) (x, y) )

/* glWindowPos2fvMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2FVMESA) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glWindowPos2fvMESA (void);
#define      gdk_gl_glWindowPos2fvMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2FVMESA) (proc)) (v) )

/* glWindowPos2iMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2IMESA) (GLint x, GLint y);
GdkGLProc    gdk_gl_get_glWindowPos2iMESA (void);
#define      gdk_gl_glWindowPos2iMESA(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2IMESA) (proc)) (x, y) )

/* glWindowPos2ivMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2IVMESA) (const GLint *v);
GdkGLProc    gdk_gl_get_glWindowPos2ivMESA (void);
#define      gdk_gl_glWindowPos2ivMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2IVMESA) (proc)) (v) )

/* glWindowPos2sMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2SMESA) (GLshort x, GLshort y);
GdkGLProc    gdk_gl_get_glWindowPos2sMESA (void);
#define      gdk_gl_glWindowPos2sMESA(proc, x, y) \
  ( ((GdkGLProc_GLWINDOWPOS2SMESA) (proc)) (x, y) )

/* glWindowPos2svMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS2SVMESA) (const GLshort *v);
GdkGLProc    gdk_gl_get_glWindowPos2svMESA (void);
#define      gdk_gl_glWindowPos2svMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS2SVMESA) (proc)) (v) )

/* glWindowPos3dMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3DMESA) (GLdouble x, GLdouble y, GLdouble z);
GdkGLProc    gdk_gl_get_glWindowPos3dMESA (void);
#define      gdk_gl_glWindowPos3dMESA(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3DMESA) (proc)) (x, y, z) )

/* glWindowPos3dvMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3DVMESA) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glWindowPos3dvMESA (void);
#define      gdk_gl_glWindowPos3dvMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3DVMESA) (proc)) (v) )

/* glWindowPos3fMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3FMESA) (GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glWindowPos3fMESA (void);
#define      gdk_gl_glWindowPos3fMESA(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3FMESA) (proc)) (x, y, z) )

/* glWindowPos3fvMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3FVMESA) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glWindowPos3fvMESA (void);
#define      gdk_gl_glWindowPos3fvMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3FVMESA) (proc)) (v) )

/* glWindowPos3iMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3IMESA) (GLint x, GLint y, GLint z);
GdkGLProc    gdk_gl_get_glWindowPos3iMESA (void);
#define      gdk_gl_glWindowPos3iMESA(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3IMESA) (proc)) (x, y, z) )

/* glWindowPos3ivMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3IVMESA) (const GLint *v);
GdkGLProc    gdk_gl_get_glWindowPos3ivMESA (void);
#define      gdk_gl_glWindowPos3ivMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3IVMESA) (proc)) (v) )

/* glWindowPos3sMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3SMESA) (GLshort x, GLshort y, GLshort z);
GdkGLProc    gdk_gl_get_glWindowPos3sMESA (void);
#define      gdk_gl_glWindowPos3sMESA(proc, x, y, z) \
  ( ((GdkGLProc_GLWINDOWPOS3SMESA) (proc)) (x, y, z) )

/* glWindowPos3svMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS3SVMESA) (const GLshort *v);
GdkGLProc    gdk_gl_get_glWindowPos3svMESA (void);
#define      gdk_gl_glWindowPos3svMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS3SVMESA) (proc)) (v) )

/* glWindowPos4dMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS4DMESA) (GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GdkGLProc    gdk_gl_get_glWindowPos4dMESA (void);
#define      gdk_gl_glWindowPos4dMESA(proc, x, y, z, w) \
  ( ((GdkGLProc_GLWINDOWPOS4DMESA) (proc)) (x, y, z, w) )

/* glWindowPos4dvMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS4DVMESA) (const GLdouble *v);
GdkGLProc    gdk_gl_get_glWindowPos4dvMESA (void);
#define      gdk_gl_glWindowPos4dvMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS4DVMESA) (proc)) (v) )

/* glWindowPos4fMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS4FMESA) (GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glWindowPos4fMESA (void);
#define      gdk_gl_glWindowPos4fMESA(proc, x, y, z, w) \
  ( ((GdkGLProc_GLWINDOWPOS4FMESA) (proc)) (x, y, z, w) )

/* glWindowPos4fvMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS4FVMESA) (const GLfloat *v);
GdkGLProc    gdk_gl_get_glWindowPos4fvMESA (void);
#define      gdk_gl_glWindowPos4fvMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS4FVMESA) (proc)) (v) )

/* glWindowPos4iMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS4IMESA) (GLint x, GLint y, GLint z, GLint w);
GdkGLProc    gdk_gl_get_glWindowPos4iMESA (void);
#define      gdk_gl_glWindowPos4iMESA(proc, x, y, z, w) \
  ( ((GdkGLProc_GLWINDOWPOS4IMESA) (proc)) (x, y, z, w) )

/* glWindowPos4ivMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS4IVMESA) (const GLint *v);
GdkGLProc    gdk_gl_get_glWindowPos4ivMESA (void);
#define      gdk_gl_glWindowPos4ivMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS4IVMESA) (proc)) (v) )

/* glWindowPos4sMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS4SMESA) (GLshort x, GLshort y, GLshort z, GLshort w);
GdkGLProc    gdk_gl_get_glWindowPos4sMESA (void);
#define      gdk_gl_glWindowPos4sMESA(proc, x, y, z, w) \
  ( ((GdkGLProc_GLWINDOWPOS4SMESA) (proc)) (x, y, z, w) )

/* glWindowPos4svMESA */
typedef void (APIENTRY * GdkGLProc_GLWINDOWPOS4SVMESA) (const GLshort *v);
GdkGLProc    gdk_gl_get_glWindowPos4svMESA (void);
#define      gdk_gl_glWindowPos4svMESA(proc, v) \
  ( ((GdkGLProc_GLWINDOWPOS4SVMESA) (proc)) (v) )

/* 
 * GL_IBM_multimode_draw_arrays
 */

/* glMultiModeDrawArraysIBM */
typedef void (APIENTRY * GdkGLProc_GLMULTIMODEDRAWARRAYSIBM) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride);
GdkGLProc    gdk_gl_get_glMultiModeDrawArraysIBM (void);
#define      gdk_gl_glMultiModeDrawArraysIBM(proc, mode, first, count, primcount, modestride) \
  ( ((GdkGLProc_GLMULTIMODEDRAWARRAYSIBM) (proc)) (mode, first, count, primcount, modestride) )

/* glMultiModeDrawElementsIBM */
typedef void (APIENTRY * GdkGLProc_GLMULTIMODEDRAWELEMENTSIBM) (const GLenum *mode, const GLsizei *count, GLenum type, const GLvoid* *indices, GLsizei primcount, GLint modestride);
GdkGLProc    gdk_gl_get_glMultiModeDrawElementsIBM (void);
#define      gdk_gl_glMultiModeDrawElementsIBM(proc, mode, count, type, indices, primcount, modestride) \
  ( ((GdkGLProc_GLMULTIMODEDRAWELEMENTSIBM) (proc)) (mode, count, type, indices, primcount, modestride) )

/* 
 * GL_IBM_vertex_array_lists
 */

/* glColorPointerListIBM */
typedef void (APIENTRY * GdkGLProc_GLCOLORPOINTERLISTIBM) (GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
GdkGLProc    gdk_gl_get_glColorPointerListIBM (void);
#define      gdk_gl_glColorPointerListIBM(proc, size, type, stride, pointer, ptrstride) \
  ( ((GdkGLProc_GLCOLORPOINTERLISTIBM) (proc)) (size, type, stride, pointer, ptrstride) )

/* glSecondaryColorPointerListIBM */
typedef void (APIENTRY * GdkGLProc_GLSECONDARYCOLORPOINTERLISTIBM) (GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
GdkGLProc    gdk_gl_get_glSecondaryColorPointerListIBM (void);
#define      gdk_gl_glSecondaryColorPointerListIBM(proc, size, type, stride, pointer, ptrstride) \
  ( ((GdkGLProc_GLSECONDARYCOLORPOINTERLISTIBM) (proc)) (size, type, stride, pointer, ptrstride) )

/* glEdgeFlagPointerListIBM */
typedef void (APIENTRY * GdkGLProc_GLEDGEFLAGPOINTERLISTIBM) (GLint stride, const GLboolean* *pointer, GLint ptrstride);
GdkGLProc    gdk_gl_get_glEdgeFlagPointerListIBM (void);
#define      gdk_gl_glEdgeFlagPointerListIBM(proc, stride, pointer, ptrstride) \
  ( ((GdkGLProc_GLEDGEFLAGPOINTERLISTIBM) (proc)) (stride, pointer, ptrstride) )

/* glFogCoordPointerListIBM */
typedef void (APIENTRY * GdkGLProc_GLFOGCOORDPOINTERLISTIBM) (GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
GdkGLProc    gdk_gl_get_glFogCoordPointerListIBM (void);
#define      gdk_gl_glFogCoordPointerListIBM(proc, type, stride, pointer, ptrstride) \
  ( ((GdkGLProc_GLFOGCOORDPOINTERLISTIBM) (proc)) (type, stride, pointer, ptrstride) )

/* glIndexPointerListIBM */
typedef void (APIENTRY * GdkGLProc_GLINDEXPOINTERLISTIBM) (GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
GdkGLProc    gdk_gl_get_glIndexPointerListIBM (void);
#define      gdk_gl_glIndexPointerListIBM(proc, type, stride, pointer, ptrstride) \
  ( ((GdkGLProc_GLINDEXPOINTERLISTIBM) (proc)) (type, stride, pointer, ptrstride) )

/* glNormalPointerListIBM */
typedef void (APIENTRY * GdkGLProc_GLNORMALPOINTERLISTIBM) (GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
GdkGLProc    gdk_gl_get_glNormalPointerListIBM (void);
#define      gdk_gl_glNormalPointerListIBM(proc, type, stride, pointer, ptrstride) \
  ( ((GdkGLProc_GLNORMALPOINTERLISTIBM) (proc)) (type, stride, pointer, ptrstride) )

/* glTexCoordPointerListIBM */
typedef void (APIENTRY * GdkGLProc_GLTEXCOORDPOINTERLISTIBM) (GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
GdkGLProc    gdk_gl_get_glTexCoordPointerListIBM (void);
#define      gdk_gl_glTexCoordPointerListIBM(proc, size, type, stride, pointer, ptrstride) \
  ( ((GdkGLProc_GLTEXCOORDPOINTERLISTIBM) (proc)) (size, type, stride, pointer, ptrstride) )

/* glVertexPointerListIBM */
typedef void (APIENTRY * GdkGLProc_GLVERTEXPOINTERLISTIBM) (GLint size, GLenum type, GLint stride, const GLvoid* *pointer, GLint ptrstride);
GdkGLProc    gdk_gl_get_glVertexPointerListIBM (void);
#define      gdk_gl_glVertexPointerListIBM(proc, size, type, stride, pointer, ptrstride) \
  ( ((GdkGLProc_GLVERTEXPOINTERLISTIBM) (proc)) (size, type, stride, pointer, ptrstride) )

/* 
 * GL_3DFX_tbuffer
 */

/* glTbufferMask3DFX */
typedef void (APIENTRY * GdkGLProc_GLTBUFFERMASK3DFX) (GLuint mask);
GdkGLProc    gdk_gl_get_glTbufferMask3DFX (void);
#define      gdk_gl_glTbufferMask3DFX(proc, mask) \
  ( ((GdkGLProc_GLTBUFFERMASK3DFX) (proc)) (mask) )

/* 
 * GL_EXT_multisample
 */

/* glSampleMaskEXT */
typedef void (APIENTRY * GdkGLProc_GLSAMPLEMASKEXT) (GLclampf value, GLboolean invert);
GdkGLProc    gdk_gl_get_glSampleMaskEXT (void);
#define      gdk_gl_glSampleMaskEXT(proc, value, invert) \
  ( ((GdkGLProc_GLSAMPLEMASKEXT) (proc)) (value, invert) )

/* glSamplePatternEXT */
typedef void (APIENTRY * GdkGLProc_GLSAMPLEPATTERNEXT) (GLenum pattern);
GdkGLProc    gdk_gl_get_glSamplePatternEXT (void);
#define      gdk_gl_glSamplePatternEXT(proc, pattern) \
  ( ((GdkGLProc_GLSAMPLEPATTERNEXT) (proc)) (pattern) )

/* 
 * GL_SGIS_texture_color_mask
 */

/* glTextureColorMaskSGIS */
typedef void (APIENTRY * GdkGLProc_GLTEXTURECOLORMASKSGIS) (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GdkGLProc    gdk_gl_get_glTextureColorMaskSGIS (void);
#define      gdk_gl_glTextureColorMaskSGIS(proc, red, green, blue, alpha) \
  ( ((GdkGLProc_GLTEXTURECOLORMASKSGIS) (proc)) (red, green, blue, alpha) )

/* 
 * GL_SGIX_igloo_interface
 */

/* glIglooInterfaceSGIX */
typedef void (APIENTRY * GdkGLProc_GLIGLOOINTERFACESGIX) (GLenum pname, const GLvoid *params);
GdkGLProc    gdk_gl_get_glIglooInterfaceSGIX (void);
#define      gdk_gl_glIglooInterfaceSGIX(proc, pname, params) \
  ( ((GdkGLProc_GLIGLOOINTERFACESGIX) (proc)) (pname, params) )

/* 
 * GL_NV_fence
 */

/* glDeleteFencesNV */
typedef void (APIENTRY * GdkGLProc_GLDELETEFENCESNV) (GLsizei n, const GLuint *fences);
GdkGLProc    gdk_gl_get_glDeleteFencesNV (void);
#define      gdk_gl_glDeleteFencesNV(proc, n, fences) \
  ( ((GdkGLProc_GLDELETEFENCESNV) (proc)) (n, fences) )

/* glGenFencesNV */
typedef void (APIENTRY * GdkGLProc_GLGENFENCESNV) (GLsizei n, GLuint *fences);
GdkGLProc    gdk_gl_get_glGenFencesNV (void);
#define      gdk_gl_glGenFencesNV(proc, n, fences) \
  ( ((GdkGLProc_GLGENFENCESNV) (proc)) (n, fences) )

/* glIsFenceNV */
typedef GLboolean (APIENTRY * GdkGLProc_GLISFENCENV) (GLuint fence);
GdkGLProc    gdk_gl_get_glIsFenceNV (void);
#define      gdk_gl_glIsFenceNV(proc, fence) \
  ( ((GdkGLProc_GLISFENCENV) (proc)) (fence) )

/* glTestFenceNV */
typedef GLboolean (APIENTRY * GdkGLProc_GLTESTFENCENV) (GLuint fence);
GdkGLProc    gdk_gl_get_glTestFenceNV (void);
#define      gdk_gl_glTestFenceNV(proc, fence) \
  ( ((GdkGLProc_GLTESTFENCENV) (proc)) (fence) )

/* glGetFenceivNV */
typedef void (APIENTRY * GdkGLProc_GLGETFENCEIVNV) (GLuint fence, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetFenceivNV (void);
#define      gdk_gl_glGetFenceivNV(proc, fence, pname, params) \
  ( ((GdkGLProc_GLGETFENCEIVNV) (proc)) (fence, pname, params) )

/* glFinishFenceNV */
typedef void (APIENTRY * GdkGLProc_GLFINISHFENCENV) (GLuint fence);
GdkGLProc    gdk_gl_get_glFinishFenceNV (void);
#define      gdk_gl_glFinishFenceNV(proc, fence) \
  ( ((GdkGLProc_GLFINISHFENCENV) (proc)) (fence) )

/* glSetFenceNV */
typedef void (APIENTRY * GdkGLProc_GLSETFENCENV) (GLuint fence, GLenum condition);
GdkGLProc    gdk_gl_get_glSetFenceNV (void);
#define      gdk_gl_glSetFenceNV(proc, fence, condition) \
  ( ((GdkGLProc_GLSETFENCENV) (proc)) (fence, condition) )

/* 
 * GL_NV_evaluators
 */

/* glMapControlPointsNV */
typedef void (APIENTRY * GdkGLProc_GLMAPCONTROLPOINTSNV) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const GLvoid *points);
GdkGLProc    gdk_gl_get_glMapControlPointsNV (void);
#define      gdk_gl_glMapControlPointsNV(proc, target, index, type, ustride, vstride, uorder, vorder, packed, points) \
  ( ((GdkGLProc_GLMAPCONTROLPOINTSNV) (proc)) (target, index, type, ustride, vstride, uorder, vorder, packed, points) )

/* glMapParameterivNV */
typedef void (APIENTRY * GdkGLProc_GLMAPPARAMETERIVNV) (GLenum target, GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glMapParameterivNV (void);
#define      gdk_gl_glMapParameterivNV(proc, target, pname, params) \
  ( ((GdkGLProc_GLMAPPARAMETERIVNV) (proc)) (target, pname, params) )

/* glMapParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLMAPPARAMETERFVNV) (GLenum target, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glMapParameterfvNV (void);
#define      gdk_gl_glMapParameterfvNV(proc, target, pname, params) \
  ( ((GdkGLProc_GLMAPPARAMETERFVNV) (proc)) (target, pname, params) )

/* glGetMapControlPointsNV */
typedef void (APIENTRY * GdkGLProc_GLGETMAPCONTROLPOINTSNV) (GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid *points);
GdkGLProc    gdk_gl_get_glGetMapControlPointsNV (void);
#define      gdk_gl_glGetMapControlPointsNV(proc, target, index, type, ustride, vstride, packed, points) \
  ( ((GdkGLProc_GLGETMAPCONTROLPOINTSNV) (proc)) (target, index, type, ustride, vstride, packed, points) )

/* glGetMapParameterivNV */
typedef void (APIENTRY * GdkGLProc_GLGETMAPPARAMETERIVNV) (GLenum target, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetMapParameterivNV (void);
#define      gdk_gl_glGetMapParameterivNV(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETMAPPARAMETERIVNV) (proc)) (target, pname, params) )

/* glGetMapParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLGETMAPPARAMETERFVNV) (GLenum target, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetMapParameterfvNV (void);
#define      gdk_gl_glGetMapParameterfvNV(proc, target, pname, params) \
  ( ((GdkGLProc_GLGETMAPPARAMETERFVNV) (proc)) (target, pname, params) )

/* glGetMapAttribParameterivNV */
typedef void (APIENTRY * GdkGLProc_GLGETMAPATTRIBPARAMETERIVNV) (GLenum target, GLuint index, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetMapAttribParameterivNV (void);
#define      gdk_gl_glGetMapAttribParameterivNV(proc, target, index, pname, params) \
  ( ((GdkGLProc_GLGETMAPATTRIBPARAMETERIVNV) (proc)) (target, index, pname, params) )

/* glGetMapAttribParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLGETMAPATTRIBPARAMETERFVNV) (GLenum target, GLuint index, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetMapAttribParameterfvNV (void);
#define      gdk_gl_glGetMapAttribParameterfvNV(proc, target, index, pname, params) \
  ( ((GdkGLProc_GLGETMAPATTRIBPARAMETERFVNV) (proc)) (target, index, pname, params) )

/* glEvalMapsNV */
typedef void (APIENTRY * GdkGLProc_GLEVALMAPSNV) (GLenum target, GLenum mode);
GdkGLProc    gdk_gl_get_glEvalMapsNV (void);
#define      gdk_gl_glEvalMapsNV(proc, target, mode) \
  ( ((GdkGLProc_GLEVALMAPSNV) (proc)) (target, mode) )

/* 
 * GL_NV_register_combiners2
 */

/* glCombinerStageParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLCOMBINERSTAGEPARAMETERFVNV) (GLenum stage, GLenum pname, const GLfloat *params);
GdkGLProc    gdk_gl_get_glCombinerStageParameterfvNV (void);
#define      gdk_gl_glCombinerStageParameterfvNV(proc, stage, pname, params) \
  ( ((GdkGLProc_GLCOMBINERSTAGEPARAMETERFVNV) (proc)) (stage, pname, params) )

/* glGetCombinerStageParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLGETCOMBINERSTAGEPARAMETERFVNV) (GLenum stage, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetCombinerStageParameterfvNV (void);
#define      gdk_gl_glGetCombinerStageParameterfvNV(proc, stage, pname, params) \
  ( ((GdkGLProc_GLGETCOMBINERSTAGEPARAMETERFVNV) (proc)) (stage, pname, params) )

/* 
 * GL_NV_vertex_program
 */

/*  glAreProgramsResidentNV */
typedef GLboolean (APIENTRY * GdkGLProc_GLAREPROGRAMSRESIDENTNV) (GLsizei n, const GLuint *programs, GLboolean *residences);
GdkGLProc    gdk_gl_get_glAreProgramsResidentNV (void);
#define      gdk_gl_glAreProgramsResidentNV(proc, n, programs, residences) \
  ( ((GdkGLProc_GLAREPROGRAMSRESIDENTNV) (proc)) (n, programs, residences) )

/* glBindProgramNV */
typedef void (APIENTRY * GdkGLProc_GLBINDPROGRAMNV) (GLenum target, GLuint id);
GdkGLProc    gdk_gl_get_glBindProgramNV (void);
#define      gdk_gl_glBindProgramNV(proc, target, id) \
  ( ((GdkGLProc_GLBINDPROGRAMNV) (proc)) (target, id) )

/* glDeleteProgramsNV */
typedef void (APIENTRY * GdkGLProc_GLDELETEPROGRAMSNV) (GLsizei n, const GLuint *programs);
GdkGLProc    gdk_gl_get_glDeleteProgramsNV (void);
#define      gdk_gl_glDeleteProgramsNV(proc, n, programs) \
  ( ((GdkGLProc_GLDELETEPROGRAMSNV) (proc)) (n, programs) )

/* glExecuteProgramNV */
typedef void (APIENTRY * GdkGLProc_GLEXECUTEPROGRAMNV) (GLenum target, GLuint id, const GLfloat *params);
GdkGLProc    gdk_gl_get_glExecuteProgramNV (void);
#define      gdk_gl_glExecuteProgramNV(proc, target, id, params) \
  ( ((GdkGLProc_GLEXECUTEPROGRAMNV) (proc)) (target, id, params) )

/* glGenProgramsNV */
typedef void (APIENTRY * GdkGLProc_GLGENPROGRAMSNV) (GLsizei n, GLuint *programs);
GdkGLProc    gdk_gl_get_glGenProgramsNV (void);
#define      gdk_gl_glGenProgramsNV(proc, n, programs) \
  ( ((GdkGLProc_GLGENPROGRAMSNV) (proc)) (n, programs) )

/* glGetProgramParameterdvNV */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMPARAMETERDVNV) (GLenum target, GLuint index, GLenum pname, GLdouble *params);
GdkGLProc    gdk_gl_get_glGetProgramParameterdvNV (void);
#define      gdk_gl_glGetProgramParameterdvNV(proc, target, index, pname, params) \
  ( ((GdkGLProc_GLGETPROGRAMPARAMETERDVNV) (proc)) (target, index, pname, params) )

/* glGetProgramParameterfvNV */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMPARAMETERFVNV) (GLenum target, GLuint index, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetProgramParameterfvNV (void);
#define      gdk_gl_glGetProgramParameterfvNV(proc, target, index, pname, params) \
  ( ((GdkGLProc_GLGETPROGRAMPARAMETERFVNV) (proc)) (target, index, pname, params) )

/* glGetProgramivNV */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMIVNV) (GLuint id, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetProgramivNV (void);
#define      gdk_gl_glGetProgramivNV(proc, id, pname, params) \
  ( ((GdkGLProc_GLGETPROGRAMIVNV) (proc)) (id, pname, params) )

/* glGetProgramStringNV */
typedef void (APIENTRY * GdkGLProc_GLGETPROGRAMSTRINGNV) (GLuint id, GLenum pname, GLubyte *program);
GdkGLProc    gdk_gl_get_glGetProgramStringNV (void);
#define      gdk_gl_glGetProgramStringNV(proc, id, pname, program) \
  ( ((GdkGLProc_GLGETPROGRAMSTRINGNV) (proc)) (id, pname, program) )

/* glGetTrackMatrixivNV */
typedef void (APIENTRY * GdkGLProc_GLGETTRACKMATRIXIVNV) (GLenum target, GLuint address, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetTrackMatrixivNV (void);
#define      gdk_gl_glGetTrackMatrixivNV(proc, target, address, pname, params) \
  ( ((GdkGLProc_GLGETTRACKMATRIXIVNV) (proc)) (target, address, pname, params) )

/* glGetVertexAttribdvNV */
typedef void (APIENTRY * GdkGLProc_GLGETVERTEXATTRIBDVNV) (GLuint index, GLenum pname, GLdouble *params);
GdkGLProc    gdk_gl_get_glGetVertexAttribdvNV (void);
#define      gdk_gl_glGetVertexAttribdvNV(proc, index, pname, params) \
  ( ((GdkGLProc_GLGETVERTEXATTRIBDVNV) (proc)) (index, pname, params) )

/* glGetVertexAttribfvNV */
typedef void (APIENTRY * GdkGLProc_GLGETVERTEXATTRIBFVNV) (GLuint index, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetVertexAttribfvNV (void);
#define      gdk_gl_glGetVertexAttribfvNV(proc, index, pname, params) \
  ( ((GdkGLProc_GLGETVERTEXATTRIBFVNV) (proc)) (index, pname, params) )

/* glGetVertexAttribivNV */
typedef void (APIENTRY * GdkGLProc_GLGETVERTEXATTRIBIVNV) (GLuint index, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetVertexAttribivNV (void);
#define      gdk_gl_glGetVertexAttribivNV(proc, index, pname, params) \
  ( ((GdkGLProc_GLGETVERTEXATTRIBIVNV) (proc)) (index, pname, params) )

/* glGetVertexAttribPointervNV */
typedef void (APIENTRY * GdkGLProc_GLGETVERTEXATTRIBPOINTERVNV) (GLuint index, GLenum pname, GLvoid* *pointer);
GdkGLProc    gdk_gl_get_glGetVertexAttribPointervNV (void);
#define      gdk_gl_glGetVertexAttribPointervNV(proc, index, pname, pointer) \
  ( ((GdkGLProc_GLGETVERTEXATTRIBPOINTERVNV) (proc)) (index, pname, pointer) )

/*  glIsProgramNV */
typedef GLboolean (APIENTRY * GdkGLProc_GLISPROGRAMNV) (GLuint id);
GdkGLProc    gdk_gl_get_glIsProgramNV (void);
#define      gdk_gl_glIsProgramNV(proc, id) \
  ( ((GdkGLProc_GLISPROGRAMNV) (proc)) (id) )

/* glLoadProgramNV */
typedef void (APIENTRY * GdkGLProc_GLLOADPROGRAMNV) (GLenum target, GLuint id, GLsizei len, const GLubyte *program);
GdkGLProc    gdk_gl_get_glLoadProgramNV (void);
#define      gdk_gl_glLoadProgramNV(proc, target, id, len, program) \
  ( ((GdkGLProc_GLLOADPROGRAMNV) (proc)) (target, id, len, program) )

/* glProgramParameter4dNV */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMPARAMETER4DNV) (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GdkGLProc    gdk_gl_get_glProgramParameter4dNV (void);
#define      gdk_gl_glProgramParameter4dNV(proc, target, index, x, y, z, w) \
  ( ((GdkGLProc_GLPROGRAMPARAMETER4DNV) (proc)) (target, index, x, y, z, w) )

/* glProgramParameter4dvNV */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMPARAMETER4DVNV) (GLenum target, GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glProgramParameter4dvNV (void);
#define      gdk_gl_glProgramParameter4dvNV(proc, target, index, v) \
  ( ((GdkGLProc_GLPROGRAMPARAMETER4DVNV) (proc)) (target, index, v) )

/* glProgramParameter4fNV */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMPARAMETER4FNV) (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glProgramParameter4fNV (void);
#define      gdk_gl_glProgramParameter4fNV(proc, target, index, x, y, z, w) \
  ( ((GdkGLProc_GLPROGRAMPARAMETER4FNV) (proc)) (target, index, x, y, z, w) )

/* glProgramParameter4fvNV */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMPARAMETER4FVNV) (GLenum target, GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glProgramParameter4fvNV (void);
#define      gdk_gl_glProgramParameter4fvNV(proc, target, index, v) \
  ( ((GdkGLProc_GLPROGRAMPARAMETER4FVNV) (proc)) (target, index, v) )

/* glProgramParameters4dvNV */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMPARAMETERS4DVNV) (GLenum target, GLuint index, GLuint count, const GLdouble *v);
GdkGLProc    gdk_gl_get_glProgramParameters4dvNV (void);
#define      gdk_gl_glProgramParameters4dvNV(proc, target, index, count, v) \
  ( ((GdkGLProc_GLPROGRAMPARAMETERS4DVNV) (proc)) (target, index, count, v) )

/* glProgramParameters4fvNV */
typedef void (APIENTRY * GdkGLProc_GLPROGRAMPARAMETERS4FVNV) (GLenum target, GLuint index, GLuint count, const GLfloat *v);
GdkGLProc    gdk_gl_get_glProgramParameters4fvNV (void);
#define      gdk_gl_glProgramParameters4fvNV(proc, target, index, count, v) \
  ( ((GdkGLProc_GLPROGRAMPARAMETERS4FVNV) (proc)) (target, index, count, v) )

/* glRequestResidentProgramsNV */
typedef void (APIENTRY * GdkGLProc_GLREQUESTRESIDENTPROGRAMSNV) (GLsizei n, const GLuint *programs);
GdkGLProc    gdk_gl_get_glRequestResidentProgramsNV (void);
#define      gdk_gl_glRequestResidentProgramsNV(proc, n, programs) \
  ( ((GdkGLProc_GLREQUESTRESIDENTPROGRAMSNV) (proc)) (n, programs) )

/* glTrackMatrixNV */
typedef void (APIENTRY * GdkGLProc_GLTRACKMATRIXNV) (GLenum target, GLuint address, GLenum matrix, GLenum transform);
GdkGLProc    gdk_gl_get_glTrackMatrixNV (void);
#define      gdk_gl_glTrackMatrixNV(proc, target, address, matrix, transform) \
  ( ((GdkGLProc_GLTRACKMATRIXNV) (proc)) (target, address, matrix, transform) )

/* glVertexAttribPointerNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBPOINTERNV) (GLuint index, GLint fsize, GLenum type, GLsizei stride, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glVertexAttribPointerNV (void);
#define      gdk_gl_glVertexAttribPointerNV(proc, index, fsize, type, stride, pointer) \
  ( ((GdkGLProc_GLVERTEXATTRIBPOINTERNV) (proc)) (index, fsize, type, stride, pointer) )

/* glVertexAttrib1dNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1DNV) (GLuint index, GLdouble x);
GdkGLProc    gdk_gl_get_glVertexAttrib1dNV (void);
#define      gdk_gl_glVertexAttrib1dNV(proc, index, x) \
  ( ((GdkGLProc_GLVERTEXATTRIB1DNV) (proc)) (index, x) )

/* glVertexAttrib1dvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1DVNV) (GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttrib1dvNV (void);
#define      gdk_gl_glVertexAttrib1dvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB1DVNV) (proc)) (index, v) )

/* glVertexAttrib1fNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1FNV) (GLuint index, GLfloat x);
GdkGLProc    gdk_gl_get_glVertexAttrib1fNV (void);
#define      gdk_gl_glVertexAttrib1fNV(proc, index, x) \
  ( ((GdkGLProc_GLVERTEXATTRIB1FNV) (proc)) (index, x) )

/* glVertexAttrib1fvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1FVNV) (GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttrib1fvNV (void);
#define      gdk_gl_glVertexAttrib1fvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB1FVNV) (proc)) (index, v) )

/* glVertexAttrib1sNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1SNV) (GLuint index, GLshort x);
GdkGLProc    gdk_gl_get_glVertexAttrib1sNV (void);
#define      gdk_gl_glVertexAttrib1sNV(proc, index, x) \
  ( ((GdkGLProc_GLVERTEXATTRIB1SNV) (proc)) (index, x) )

/* glVertexAttrib1svNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB1SVNV) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib1svNV (void);
#define      gdk_gl_glVertexAttrib1svNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB1SVNV) (proc)) (index, v) )

/* glVertexAttrib2dNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2DNV) (GLuint index, GLdouble x, GLdouble y);
GdkGLProc    gdk_gl_get_glVertexAttrib2dNV (void);
#define      gdk_gl_glVertexAttrib2dNV(proc, index, x, y) \
  ( ((GdkGLProc_GLVERTEXATTRIB2DNV) (proc)) (index, x, y) )

/* glVertexAttrib2dvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2DVNV) (GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttrib2dvNV (void);
#define      gdk_gl_glVertexAttrib2dvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB2DVNV) (proc)) (index, v) )

/* glVertexAttrib2fNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2FNV) (GLuint index, GLfloat x, GLfloat y);
GdkGLProc    gdk_gl_get_glVertexAttrib2fNV (void);
#define      gdk_gl_glVertexAttrib2fNV(proc, index, x, y) \
  ( ((GdkGLProc_GLVERTEXATTRIB2FNV) (proc)) (index, x, y) )

/* glVertexAttrib2fvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2FVNV) (GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttrib2fvNV (void);
#define      gdk_gl_glVertexAttrib2fvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB2FVNV) (proc)) (index, v) )

/* glVertexAttrib2sNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2SNV) (GLuint index, GLshort x, GLshort y);
GdkGLProc    gdk_gl_get_glVertexAttrib2sNV (void);
#define      gdk_gl_glVertexAttrib2sNV(proc, index, x, y) \
  ( ((GdkGLProc_GLVERTEXATTRIB2SNV) (proc)) (index, x, y) )

/* glVertexAttrib2svNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB2SVNV) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib2svNV (void);
#define      gdk_gl_glVertexAttrib2svNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB2SVNV) (proc)) (index, v) )

/* glVertexAttrib3dNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3DNV) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
GdkGLProc    gdk_gl_get_glVertexAttrib3dNV (void);
#define      gdk_gl_glVertexAttrib3dNV(proc, index, x, y, z) \
  ( ((GdkGLProc_GLVERTEXATTRIB3DNV) (proc)) (index, x, y, z) )

/* glVertexAttrib3dvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3DVNV) (GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttrib3dvNV (void);
#define      gdk_gl_glVertexAttrib3dvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB3DVNV) (proc)) (index, v) )

/* glVertexAttrib3fNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3FNV) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glVertexAttrib3fNV (void);
#define      gdk_gl_glVertexAttrib3fNV(proc, index, x, y, z) \
  ( ((GdkGLProc_GLVERTEXATTRIB3FNV) (proc)) (index, x, y, z) )

/* glVertexAttrib3fvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3FVNV) (GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttrib3fvNV (void);
#define      gdk_gl_glVertexAttrib3fvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB3FVNV) (proc)) (index, v) )

/* glVertexAttrib3sNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3SNV) (GLuint index, GLshort x, GLshort y, GLshort z);
GdkGLProc    gdk_gl_get_glVertexAttrib3sNV (void);
#define      gdk_gl_glVertexAttrib3sNV(proc, index, x, y, z) \
  ( ((GdkGLProc_GLVERTEXATTRIB3SNV) (proc)) (index, x, y, z) )

/* glVertexAttrib3svNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB3SVNV) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib3svNV (void);
#define      gdk_gl_glVertexAttrib3svNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB3SVNV) (proc)) (index, v) )

/* glVertexAttrib4dNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4DNV) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GdkGLProc    gdk_gl_get_glVertexAttrib4dNV (void);
#define      gdk_gl_glVertexAttrib4dNV(proc, index, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXATTRIB4DNV) (proc)) (index, x, y, z, w) )

/* glVertexAttrib4dvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4DVNV) (GLuint index, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4dvNV (void);
#define      gdk_gl_glVertexAttrib4dvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4DVNV) (proc)) (index, v) )

/* glVertexAttrib4fNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4FNV) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glVertexAttrib4fNV (void);
#define      gdk_gl_glVertexAttrib4fNV(proc, index, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXATTRIB4FNV) (proc)) (index, x, y, z, w) )

/* glVertexAttrib4fvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4FVNV) (GLuint index, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4fvNV (void);
#define      gdk_gl_glVertexAttrib4fvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4FVNV) (proc)) (index, v) )

/* glVertexAttrib4sNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4SNV) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GdkGLProc    gdk_gl_get_glVertexAttrib4sNV (void);
#define      gdk_gl_glVertexAttrib4sNV(proc, index, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXATTRIB4SNV) (proc)) (index, x, y, z, w) )

/* glVertexAttrib4svNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4SVNV) (GLuint index, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4svNV (void);
#define      gdk_gl_glVertexAttrib4svNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4SVNV) (proc)) (index, v) )

/* glVertexAttrib4ubNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4UBNV) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GdkGLProc    gdk_gl_get_glVertexAttrib4ubNV (void);
#define      gdk_gl_glVertexAttrib4ubNV(proc, index, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXATTRIB4UBNV) (proc)) (index, x, y, z, w) )

/* glVertexAttrib4ubvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIB4UBVNV) (GLuint index, const GLubyte *v);
GdkGLProc    gdk_gl_get_glVertexAttrib4ubvNV (void);
#define      gdk_gl_glVertexAttrib4ubvNV(proc, index, v) \
  ( ((GdkGLProc_GLVERTEXATTRIB4UBVNV) (proc)) (index, v) )

/* glVertexAttribs1dvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS1DVNV) (GLuint index, GLsizei count, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttribs1dvNV (void);
#define      gdk_gl_glVertexAttribs1dvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS1DVNV) (proc)) (index, count, v) )

/* glVertexAttribs1fvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS1FVNV) (GLuint index, GLsizei count, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttribs1fvNV (void);
#define      gdk_gl_glVertexAttribs1fvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS1FVNV) (proc)) (index, count, v) )

/* glVertexAttribs1svNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS1SVNV) (GLuint index, GLsizei count, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttribs1svNV (void);
#define      gdk_gl_glVertexAttribs1svNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS1SVNV) (proc)) (index, count, v) )

/* glVertexAttribs2dvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS2DVNV) (GLuint index, GLsizei count, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttribs2dvNV (void);
#define      gdk_gl_glVertexAttribs2dvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS2DVNV) (proc)) (index, count, v) )

/* glVertexAttribs2fvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS2FVNV) (GLuint index, GLsizei count, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttribs2fvNV (void);
#define      gdk_gl_glVertexAttribs2fvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS2FVNV) (proc)) (index, count, v) )

/* glVertexAttribs2svNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS2SVNV) (GLuint index, GLsizei count, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttribs2svNV (void);
#define      gdk_gl_glVertexAttribs2svNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS2SVNV) (proc)) (index, count, v) )

/* glVertexAttribs3dvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS3DVNV) (GLuint index, GLsizei count, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttribs3dvNV (void);
#define      gdk_gl_glVertexAttribs3dvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS3DVNV) (proc)) (index, count, v) )

/* glVertexAttribs3fvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS3FVNV) (GLuint index, GLsizei count, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttribs3fvNV (void);
#define      gdk_gl_glVertexAttribs3fvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS3FVNV) (proc)) (index, count, v) )

/* glVertexAttribs3svNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS3SVNV) (GLuint index, GLsizei count, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttribs3svNV (void);
#define      gdk_gl_glVertexAttribs3svNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS3SVNV) (proc)) (index, count, v) )

/* glVertexAttribs4dvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS4DVNV) (GLuint index, GLsizei count, const GLdouble *v);
GdkGLProc    gdk_gl_get_glVertexAttribs4dvNV (void);
#define      gdk_gl_glVertexAttribs4dvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS4DVNV) (proc)) (index, count, v) )

/* glVertexAttribs4fvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS4FVNV) (GLuint index, GLsizei count, const GLfloat *v);
GdkGLProc    gdk_gl_get_glVertexAttribs4fvNV (void);
#define      gdk_gl_glVertexAttribs4fvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS4FVNV) (proc)) (index, count, v) )

/* glVertexAttribs4svNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS4SVNV) (GLuint index, GLsizei count, const GLshort *v);
GdkGLProc    gdk_gl_get_glVertexAttribs4svNV (void);
#define      gdk_gl_glVertexAttribs4svNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS4SVNV) (proc)) (index, count, v) )

/* glVertexAttribs4ubvNV */
typedef void (APIENTRY * GdkGLProc_GLVERTEXATTRIBS4UBVNV) (GLuint index, GLsizei count, const GLubyte *v);
GdkGLProc    gdk_gl_get_glVertexAttribs4ubvNV (void);
#define      gdk_gl_glVertexAttribs4ubvNV(proc, index, count, v) \
  ( ((GdkGLProc_GLVERTEXATTRIBS4UBVNV) (proc)) (index, count, v) )

/* 
 * GL_ATI_envmap_bumpmap
 */

/* glTexBumpParameterivATI */
typedef void (APIENTRY * GdkGLProc_GLTEXBUMPPARAMETERIVATI) (GLenum pname, const GLint *param);
GdkGLProc    gdk_gl_get_glTexBumpParameterivATI (void);
#define      gdk_gl_glTexBumpParameterivATI(proc, pname, param) \
  ( ((GdkGLProc_GLTEXBUMPPARAMETERIVATI) (proc)) (pname, param) )

/* glTexBumpParameterfvATI */
typedef void (APIENTRY * GdkGLProc_GLTEXBUMPPARAMETERFVATI) (GLenum pname, const GLfloat *param);
GdkGLProc    gdk_gl_get_glTexBumpParameterfvATI (void);
#define      gdk_gl_glTexBumpParameterfvATI(proc, pname, param) \
  ( ((GdkGLProc_GLTEXBUMPPARAMETERFVATI) (proc)) (pname, param) )

/* glGetTexBumpParameterivATI */
typedef void (APIENTRY * GdkGLProc_GLGETTEXBUMPPARAMETERIVATI) (GLenum pname, GLint *param);
GdkGLProc    gdk_gl_get_glGetTexBumpParameterivATI (void);
#define      gdk_gl_glGetTexBumpParameterivATI(proc, pname, param) \
  ( ((GdkGLProc_GLGETTEXBUMPPARAMETERIVATI) (proc)) (pname, param) )

/* glGetTexBumpParameterfvATI */
typedef void (APIENTRY * GdkGLProc_GLGETTEXBUMPPARAMETERFVATI) (GLenum pname, GLfloat *param);
GdkGLProc    gdk_gl_get_glGetTexBumpParameterfvATI (void);
#define      gdk_gl_glGetTexBumpParameterfvATI(proc, pname, param) \
  ( ((GdkGLProc_GLGETTEXBUMPPARAMETERFVATI) (proc)) (pname, param) )

/* 
 * GL_ATI_fragment_shader
 */

/*  glGenFragmentShadersATI */
typedef GLuint (APIENTRY * GdkGLProc_GLGENFRAGMENTSHADERSATI) (GLuint range);
GdkGLProc    gdk_gl_get_glGenFragmentShadersATI (void);
#define      gdk_gl_glGenFragmentShadersATI(proc, range) \
  ( ((GdkGLProc_GLGENFRAGMENTSHADERSATI) (proc)) (range) )

/* glBindFragmentShaderATI */
typedef void (APIENTRY * GdkGLProc_GLBINDFRAGMENTSHADERATI) (GLuint id);
GdkGLProc    gdk_gl_get_glBindFragmentShaderATI (void);
#define      gdk_gl_glBindFragmentShaderATI(proc, id) \
  ( ((GdkGLProc_GLBINDFRAGMENTSHADERATI) (proc)) (id) )

/* glDeleteFragmentShaderATI */
typedef void (APIENTRY * GdkGLProc_GLDELETEFRAGMENTSHADERATI) (GLuint id);
GdkGLProc    gdk_gl_get_glDeleteFragmentShaderATI (void);
#define      gdk_gl_glDeleteFragmentShaderATI(proc, id) \
  ( ((GdkGLProc_GLDELETEFRAGMENTSHADERATI) (proc)) (id) )

/* glBeginFragmentShaderATI */
typedef void (APIENTRY * GdkGLProc_GLBEGINFRAGMENTSHADERATI) (void);
GdkGLProc    gdk_gl_get_glBeginFragmentShaderATI (void);
#define      gdk_gl_glBeginFragmentShaderATI(proc) \
  ( ((GdkGLProc_GLBEGINFRAGMENTSHADERATI) (proc)) () )

/* glEndFragmentShaderATI */
typedef void (APIENTRY * GdkGLProc_GLENDFRAGMENTSHADERATI) (void);
GdkGLProc    gdk_gl_get_glEndFragmentShaderATI (void);
#define      gdk_gl_glEndFragmentShaderATI(proc) \
  ( ((GdkGLProc_GLENDFRAGMENTSHADERATI) (proc)) () )

/* glPassTexCoordATI */
typedef void (APIENTRY * GdkGLProc_GLPASSTEXCOORDATI) (GLuint dst, GLuint coord, GLenum swizzle);
GdkGLProc    gdk_gl_get_glPassTexCoordATI (void);
#define      gdk_gl_glPassTexCoordATI(proc, dst, coord, swizzle) \
  ( ((GdkGLProc_GLPASSTEXCOORDATI) (proc)) (dst, coord, swizzle) )

/* glSampleMapATI */
typedef void (APIENTRY * GdkGLProc_GLSAMPLEMAPATI) (GLuint dst, GLuint interp, GLenum swizzle);
GdkGLProc    gdk_gl_get_glSampleMapATI (void);
#define      gdk_gl_glSampleMapATI(proc, dst, interp, swizzle) \
  ( ((GdkGLProc_GLSAMPLEMAPATI) (proc)) (dst, interp, swizzle) )

/* glColorFragmentOp1ATI */
typedef void (APIENTRY * GdkGLProc_GLCOLORFRAGMENTOP1ATI) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
GdkGLProc    gdk_gl_get_glColorFragmentOp1ATI (void);
#define      gdk_gl_glColorFragmentOp1ATI(proc, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod) \
  ( ((GdkGLProc_GLCOLORFRAGMENTOP1ATI) (proc)) (op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod) )

/* glColorFragmentOp2ATI */
typedef void (APIENTRY * GdkGLProc_GLCOLORFRAGMENTOP2ATI) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
GdkGLProc    gdk_gl_get_glColorFragmentOp2ATI (void);
#define      gdk_gl_glColorFragmentOp2ATI(proc, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) \
  ( ((GdkGLProc_GLCOLORFRAGMENTOP2ATI) (proc)) (op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) )

/* glColorFragmentOp3ATI */
typedef void (APIENTRY * GdkGLProc_GLCOLORFRAGMENTOP3ATI) (GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
GdkGLProc    gdk_gl_get_glColorFragmentOp3ATI (void);
#define      gdk_gl_glColorFragmentOp3ATI(proc, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) \
  ( ((GdkGLProc_GLCOLORFRAGMENTOP3ATI) (proc)) (op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) )

/* glAlphaFragmentOp1ATI */
typedef void (APIENTRY * GdkGLProc_GLALPHAFRAGMENTOP1ATI) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
GdkGLProc    gdk_gl_get_glAlphaFragmentOp1ATI (void);
#define      gdk_gl_glAlphaFragmentOp1ATI(proc, op, dst, dstMod, arg1, arg1Rep, arg1Mod) \
  ( ((GdkGLProc_GLALPHAFRAGMENTOP1ATI) (proc)) (op, dst, dstMod, arg1, arg1Rep, arg1Mod) )

/* glAlphaFragmentOp2ATI */
typedef void (APIENTRY * GdkGLProc_GLALPHAFRAGMENTOP2ATI) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
GdkGLProc    gdk_gl_get_glAlphaFragmentOp2ATI (void);
#define      gdk_gl_glAlphaFragmentOp2ATI(proc, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) \
  ( ((GdkGLProc_GLALPHAFRAGMENTOP2ATI) (proc)) (op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) )

/* glAlphaFragmentOp3ATI */
typedef void (APIENTRY * GdkGLProc_GLALPHAFRAGMENTOP3ATI) (GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
GdkGLProc    gdk_gl_get_glAlphaFragmentOp3ATI (void);
#define      gdk_gl_glAlphaFragmentOp3ATI(proc, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) \
  ( ((GdkGLProc_GLALPHAFRAGMENTOP3ATI) (proc)) (op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) )

/* glSetFragmentShaderConstantATI */
typedef void (APIENTRY * GdkGLProc_GLSETFRAGMENTSHADERCONSTANTATI) (GLuint dst, const GLfloat *value);
GdkGLProc    gdk_gl_get_glSetFragmentShaderConstantATI (void);
#define      gdk_gl_glSetFragmentShaderConstantATI(proc, dst, value) \
  ( ((GdkGLProc_GLSETFRAGMENTSHADERCONSTANTATI) (proc)) (dst, value) )

/* 
 * GL_ATI_pn_triangles
 */

/* glPNTrianglesiATI */
typedef void (APIENTRY * GdkGLProc_GLPNTRIANGLESIATI) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glPNTrianglesiATI (void);
#define      gdk_gl_glPNTrianglesiATI(proc, pname, param) \
  ( ((GdkGLProc_GLPNTRIANGLESIATI) (proc)) (pname, param) )

/* glPNTrianglesfATI */
typedef void (APIENTRY * GdkGLProc_GLPNTRIANGLESFATI) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glPNTrianglesfATI (void);
#define      gdk_gl_glPNTrianglesfATI(proc, pname, param) \
  ( ((GdkGLProc_GLPNTRIANGLESFATI) (proc)) (pname, param) )

/* 
 * GL_ATI_vertex_array_object
 */

/*  glNewObjectBufferATI */
typedef GLuint (APIENTRY * GdkGLProc_GLNEWOBJECTBUFFERATI) (GLsizei size, const GLvoid *pointer, GLenum usage);
GdkGLProc    gdk_gl_get_glNewObjectBufferATI (void);
#define      gdk_gl_glNewObjectBufferATI(proc, size, pointer, usage) \
  ( ((GdkGLProc_GLNEWOBJECTBUFFERATI) (proc)) (size, pointer, usage) )

/*  glIsObjectBufferATI */
typedef GLboolean (APIENTRY * GdkGLProc_GLISOBJECTBUFFERATI) (GLuint buffer);
GdkGLProc    gdk_gl_get_glIsObjectBufferATI (void);
#define      gdk_gl_glIsObjectBufferATI(proc, buffer) \
  ( ((GdkGLProc_GLISOBJECTBUFFERATI) (proc)) (buffer) )

/* glUpdateObjectBufferATI */
typedef void (APIENTRY * GdkGLProc_GLUPDATEOBJECTBUFFERATI) (GLuint buffer, GLuint offset, GLsizei size, const GLvoid *pointer, GLenum preserve);
GdkGLProc    gdk_gl_get_glUpdateObjectBufferATI (void);
#define      gdk_gl_glUpdateObjectBufferATI(proc, buffer, offset, size, pointer, preserve) \
  ( ((GdkGLProc_GLUPDATEOBJECTBUFFERATI) (proc)) (buffer, offset, size, pointer, preserve) )

/* glGetObjectBufferfvATI */
typedef void (APIENTRY * GdkGLProc_GLGETOBJECTBUFFERFVATI) (GLuint buffer, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetObjectBufferfvATI (void);
#define      gdk_gl_glGetObjectBufferfvATI(proc, buffer, pname, params) \
  ( ((GdkGLProc_GLGETOBJECTBUFFERFVATI) (proc)) (buffer, pname, params) )

/* glGetObjectBufferivATI */
typedef void (APIENTRY * GdkGLProc_GLGETOBJECTBUFFERIVATI) (GLuint buffer, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetObjectBufferivATI (void);
#define      gdk_gl_glGetObjectBufferivATI(proc, buffer, pname, params) \
  ( ((GdkGLProc_GLGETOBJECTBUFFERIVATI) (proc)) (buffer, pname, params) )

/* glDeleteObjectBufferATI */
typedef void (APIENTRY * GdkGLProc_GLDELETEOBJECTBUFFERATI) (GLuint buffer);
GdkGLProc    gdk_gl_get_glDeleteObjectBufferATI (void);
#define      gdk_gl_glDeleteObjectBufferATI(proc, buffer) \
  ( ((GdkGLProc_GLDELETEOBJECTBUFFERATI) (proc)) (buffer) )

/* glArrayObjectATI */
typedef void (APIENTRY * GdkGLProc_GLARRAYOBJECTATI) (GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
GdkGLProc    gdk_gl_get_glArrayObjectATI (void);
#define      gdk_gl_glArrayObjectATI(proc, array, size, type, stride, buffer, offset) \
  ( ((GdkGLProc_GLARRAYOBJECTATI) (proc)) (array, size, type, stride, buffer, offset) )

/* glGetArrayObjectfvATI */
typedef void (APIENTRY * GdkGLProc_GLGETARRAYOBJECTFVATI) (GLenum array, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetArrayObjectfvATI (void);
#define      gdk_gl_glGetArrayObjectfvATI(proc, array, pname, params) \
  ( ((GdkGLProc_GLGETARRAYOBJECTFVATI) (proc)) (array, pname, params) )

/* glGetArrayObjectivATI */
typedef void (APIENTRY * GdkGLProc_GLGETARRAYOBJECTIVATI) (GLenum array, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetArrayObjectivATI (void);
#define      gdk_gl_glGetArrayObjectivATI(proc, array, pname, params) \
  ( ((GdkGLProc_GLGETARRAYOBJECTIVATI) (proc)) (array, pname, params) )

/* glVariantArrayObjectATI */
typedef void (APIENTRY * GdkGLProc_GLVARIANTARRAYOBJECTATI) (GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
GdkGLProc    gdk_gl_get_glVariantArrayObjectATI (void);
#define      gdk_gl_glVariantArrayObjectATI(proc, id, type, stride, buffer, offset) \
  ( ((GdkGLProc_GLVARIANTARRAYOBJECTATI) (proc)) (id, type, stride, buffer, offset) )

/* glGetVariantArrayObjectfvATI */
typedef void (APIENTRY * GdkGLProc_GLGETVARIANTARRAYOBJECTFVATI) (GLuint id, GLenum pname, GLfloat *params);
GdkGLProc    gdk_gl_get_glGetVariantArrayObjectfvATI (void);
#define      gdk_gl_glGetVariantArrayObjectfvATI(proc, id, pname, params) \
  ( ((GdkGLProc_GLGETVARIANTARRAYOBJECTFVATI) (proc)) (id, pname, params) )

/* glGetVariantArrayObjectivATI */
typedef void (APIENTRY * GdkGLProc_GLGETVARIANTARRAYOBJECTIVATI) (GLuint id, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetVariantArrayObjectivATI (void);
#define      gdk_gl_glGetVariantArrayObjectivATI(proc, id, pname, params) \
  ( ((GdkGLProc_GLGETVARIANTARRAYOBJECTIVATI) (proc)) (id, pname, params) )

/* 
 * GL_EXT_vertex_shader
 */

/* glBeginVertexShaderEXT */
typedef void (APIENTRY * GdkGLProc_GLBEGINVERTEXSHADEREXT) (void);
GdkGLProc    gdk_gl_get_glBeginVertexShaderEXT (void);
#define      gdk_gl_glBeginVertexShaderEXT(proc) \
  ( ((GdkGLProc_GLBEGINVERTEXSHADEREXT) (proc)) () )

/* glEndVertexShaderEXT */
typedef void (APIENTRY * GdkGLProc_GLENDVERTEXSHADEREXT) (void);
GdkGLProc    gdk_gl_get_glEndVertexShaderEXT (void);
#define      gdk_gl_glEndVertexShaderEXT(proc) \
  ( ((GdkGLProc_GLENDVERTEXSHADEREXT) (proc)) () )

/* glBindVertexShaderEXT */
typedef void (APIENTRY * GdkGLProc_GLBINDVERTEXSHADEREXT) (GLuint id);
GdkGLProc    gdk_gl_get_glBindVertexShaderEXT (void);
#define      gdk_gl_glBindVertexShaderEXT(proc, id) \
  ( ((GdkGLProc_GLBINDVERTEXSHADEREXT) (proc)) (id) )

/* glGenVertexShadersEXT */
typedef GLuint (APIENTRY * GdkGLProc_GLGENVERTEXSHADERSEXT) (GLuint range);
GdkGLProc    gdk_gl_get_glGenVertexShadersEXT (void);
#define      gdk_gl_glGenVertexShadersEXT(proc, range) \
  ( ((GdkGLProc_GLGENVERTEXSHADERSEXT) (proc)) (range) )

/* glDeleteVertexShaderEXT */
typedef void (APIENTRY * GdkGLProc_GLDELETEVERTEXSHADEREXT) (GLuint id);
GdkGLProc    gdk_gl_get_glDeleteVertexShaderEXT (void);
#define      gdk_gl_glDeleteVertexShaderEXT(proc, id) \
  ( ((GdkGLProc_GLDELETEVERTEXSHADEREXT) (proc)) (id) )

/* glShaderOp1EXT */
typedef void (APIENTRY * GdkGLProc_GLSHADEROP1EXT) (GLenum op, GLuint res, GLuint arg1);
GdkGLProc    gdk_gl_get_glShaderOp1EXT (void);
#define      gdk_gl_glShaderOp1EXT(proc, op, res, arg1) \
  ( ((GdkGLProc_GLSHADEROP1EXT) (proc)) (op, res, arg1) )

/* glShaderOp2EXT */
typedef void (APIENTRY * GdkGLProc_GLSHADEROP2EXT) (GLenum op, GLuint res, GLuint arg1, GLuint arg2);
GdkGLProc    gdk_gl_get_glShaderOp2EXT (void);
#define      gdk_gl_glShaderOp2EXT(proc, op, res, arg1, arg2) \
  ( ((GdkGLProc_GLSHADEROP2EXT) (proc)) (op, res, arg1, arg2) )

/* glShaderOp3EXT */
typedef void (APIENTRY * GdkGLProc_GLSHADEROP3EXT) (GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
GdkGLProc    gdk_gl_get_glShaderOp3EXT (void);
#define      gdk_gl_glShaderOp3EXT(proc, op, res, arg1, arg2, arg3) \
  ( ((GdkGLProc_GLSHADEROP3EXT) (proc)) (op, res, arg1, arg2, arg3) )

/* glSwizzleEXT */
typedef void (APIENTRY * GdkGLProc_GLSWIZZLEEXT) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
GdkGLProc    gdk_gl_get_glSwizzleEXT (void);
#define      gdk_gl_glSwizzleEXT(proc, res, in, outX, outY, outZ, outW) \
  ( ((GdkGLProc_GLSWIZZLEEXT) (proc)) (res, in, outX, outY, outZ, outW) )

/* glWriteMaskEXT */
typedef void (APIENTRY * GdkGLProc_GLWRITEMASKEXT) (GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
GdkGLProc    gdk_gl_get_glWriteMaskEXT (void);
#define      gdk_gl_glWriteMaskEXT(proc, res, in, outX, outY, outZ, outW) \
  ( ((GdkGLProc_GLWRITEMASKEXT) (proc)) (res, in, outX, outY, outZ, outW) )

/* glInsertComponentEXT */
typedef void (APIENTRY * GdkGLProc_GLINSERTCOMPONENTEXT) (GLuint res, GLuint src, GLuint num);
GdkGLProc    gdk_gl_get_glInsertComponentEXT (void);
#define      gdk_gl_glInsertComponentEXT(proc, res, src, num) \
  ( ((GdkGLProc_GLINSERTCOMPONENTEXT) (proc)) (res, src, num) )

/* glExtractComponentEXT */
typedef void (APIENTRY * GdkGLProc_GLEXTRACTCOMPONENTEXT) (GLuint res, GLuint src, GLuint num);
GdkGLProc    gdk_gl_get_glExtractComponentEXT (void);
#define      gdk_gl_glExtractComponentEXT(proc, res, src, num) \
  ( ((GdkGLProc_GLEXTRACTCOMPONENTEXT) (proc)) (res, src, num) )

/* glGenSymbolsEXT */
typedef GLuint (APIENTRY * GdkGLProc_GLGENSYMBOLSEXT) (GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
GdkGLProc    gdk_gl_get_glGenSymbolsEXT (void);
#define      gdk_gl_glGenSymbolsEXT(proc, datatype, storagetype, range, components) \
  ( ((GdkGLProc_GLGENSYMBOLSEXT) (proc)) (datatype, storagetype, range, components) )

/* glSetInvariantEXT */
typedef void (APIENTRY * GdkGLProc_GLSETINVARIANTEXT) (GLuint id, GLenum type, const void *addr);
GdkGLProc    gdk_gl_get_glSetInvariantEXT (void);
#define      gdk_gl_glSetInvariantEXT(proc, id, type, addr) \
  ( ((GdkGLProc_GLSETINVARIANTEXT) (proc)) (id, type, addr) )

/* glSetLocalConstantEXT */
typedef void (APIENTRY * GdkGLProc_GLSETLOCALCONSTANTEXT) (GLuint id, GLenum type, const void *addr);
GdkGLProc    gdk_gl_get_glSetLocalConstantEXT (void);
#define      gdk_gl_glSetLocalConstantEXT(proc, id, type, addr) \
  ( ((GdkGLProc_GLSETLOCALCONSTANTEXT) (proc)) (id, type, addr) )

/* glVariantbvEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTBVEXT) (GLuint id, const GLbyte *addr);
GdkGLProc    gdk_gl_get_glVariantbvEXT (void);
#define      gdk_gl_glVariantbvEXT(proc, id, addr) \
  ( ((GdkGLProc_GLVARIANTBVEXT) (proc)) (id, addr) )

/* glVariantsvEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTSVEXT) (GLuint id, const GLshort *addr);
GdkGLProc    gdk_gl_get_glVariantsvEXT (void);
#define      gdk_gl_glVariantsvEXT(proc, id, addr) \
  ( ((GdkGLProc_GLVARIANTSVEXT) (proc)) (id, addr) )

/* glVariantivEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTIVEXT) (GLuint id, const GLint *addr);
GdkGLProc    gdk_gl_get_glVariantivEXT (void);
#define      gdk_gl_glVariantivEXT(proc, id, addr) \
  ( ((GdkGLProc_GLVARIANTIVEXT) (proc)) (id, addr) )

/* glVariantfvEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTFVEXT) (GLuint id, const GLfloat *addr);
GdkGLProc    gdk_gl_get_glVariantfvEXT (void);
#define      gdk_gl_glVariantfvEXT(proc, id, addr) \
  ( ((GdkGLProc_GLVARIANTFVEXT) (proc)) (id, addr) )

/* glVariantdvEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTDVEXT) (GLuint id, const GLdouble *addr);
GdkGLProc    gdk_gl_get_glVariantdvEXT (void);
#define      gdk_gl_glVariantdvEXT(proc, id, addr) \
  ( ((GdkGLProc_GLVARIANTDVEXT) (proc)) (id, addr) )

/* glVariantubvEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTUBVEXT) (GLuint id, const GLubyte *addr);
GdkGLProc    gdk_gl_get_glVariantubvEXT (void);
#define      gdk_gl_glVariantubvEXT(proc, id, addr) \
  ( ((GdkGLProc_GLVARIANTUBVEXT) (proc)) (id, addr) )

/* glVariantusvEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTUSVEXT) (GLuint id, const GLushort *addr);
GdkGLProc    gdk_gl_get_glVariantusvEXT (void);
#define      gdk_gl_glVariantusvEXT(proc, id, addr) \
  ( ((GdkGLProc_GLVARIANTUSVEXT) (proc)) (id, addr) )

/* glVariantuivEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTUIVEXT) (GLuint id, const GLuint *addr);
GdkGLProc    gdk_gl_get_glVariantuivEXT (void);
#define      gdk_gl_glVariantuivEXT(proc, id, addr) \
  ( ((GdkGLProc_GLVARIANTUIVEXT) (proc)) (id, addr) )

/* glVariantPointerEXT */
typedef void (APIENTRY * GdkGLProc_GLVARIANTPOINTEREXT) (GLuint id, GLenum type, GLuint stride, const void *addr);
GdkGLProc    gdk_gl_get_glVariantPointerEXT (void);
#define      gdk_gl_glVariantPointerEXT(proc, id, type, stride, addr) \
  ( ((GdkGLProc_GLVARIANTPOINTEREXT) (proc)) (id, type, stride, addr) )

/* glEnableVariantClientStateEXT */
typedef void (APIENTRY * GdkGLProc_GLENABLEVARIANTCLIENTSTATEEXT) (GLuint id);
GdkGLProc    gdk_gl_get_glEnableVariantClientStateEXT (void);
#define      gdk_gl_glEnableVariantClientStateEXT(proc, id) \
  ( ((GdkGLProc_GLENABLEVARIANTCLIENTSTATEEXT) (proc)) (id) )

/* glDisableVariantClientStateEXT */
typedef void (APIENTRY * GdkGLProc_GLDISABLEVARIANTCLIENTSTATEEXT) (GLuint id);
GdkGLProc    gdk_gl_get_glDisableVariantClientStateEXT (void);
#define      gdk_gl_glDisableVariantClientStateEXT(proc, id) \
  ( ((GdkGLProc_GLDISABLEVARIANTCLIENTSTATEEXT) (proc)) (id) )

/* glBindLightParameterEXT */
typedef GLuint (APIENTRY * GdkGLProc_GLBINDLIGHTPARAMETEREXT) (GLenum light, GLenum value);
GdkGLProc    gdk_gl_get_glBindLightParameterEXT (void);
#define      gdk_gl_glBindLightParameterEXT(proc, light, value) \
  ( ((GdkGLProc_GLBINDLIGHTPARAMETEREXT) (proc)) (light, value) )

/* glBindMaterialParameterEXT */
typedef GLuint (APIENTRY * GdkGLProc_GLBINDMATERIALPARAMETEREXT) (GLenum face, GLenum value);
GdkGLProc    gdk_gl_get_glBindMaterialParameterEXT (void);
#define      gdk_gl_glBindMaterialParameterEXT(proc, face, value) \
  ( ((GdkGLProc_GLBINDMATERIALPARAMETEREXT) (proc)) (face, value) )

/* glBindTexGenParameterEXT */
typedef GLuint (APIENTRY * GdkGLProc_GLBINDTEXGENPARAMETEREXT) (GLenum unit, GLenum coord, GLenum value);
GdkGLProc    gdk_gl_get_glBindTexGenParameterEXT (void);
#define      gdk_gl_glBindTexGenParameterEXT(proc, unit, coord, value) \
  ( ((GdkGLProc_GLBINDTEXGENPARAMETEREXT) (proc)) (unit, coord, value) )

/* glBindTextureUnitParameterEXT */
typedef GLuint (APIENTRY * GdkGLProc_GLBINDTEXTUREUNITPARAMETEREXT) (GLenum unit, GLenum value);
GdkGLProc    gdk_gl_get_glBindTextureUnitParameterEXT (void);
#define      gdk_gl_glBindTextureUnitParameterEXT(proc, unit, value) \
  ( ((GdkGLProc_GLBINDTEXTUREUNITPARAMETEREXT) (proc)) (unit, value) )

/* glBindParameterEXT */
typedef GLuint (APIENTRY * GdkGLProc_GLBINDPARAMETEREXT) (GLenum value);
GdkGLProc    gdk_gl_get_glBindParameterEXT (void);
#define      gdk_gl_glBindParameterEXT(proc, value) \
  ( ((GdkGLProc_GLBINDPARAMETEREXT) (proc)) (value) )

/* glIsVariantEnabledEXT */
typedef GLboolean (APIENTRY * GdkGLProc_GLISVARIANTENABLEDEXT) (GLuint id, GLenum cap);
GdkGLProc    gdk_gl_get_glIsVariantEnabledEXT (void);
#define      gdk_gl_glIsVariantEnabledEXT(proc, id, cap) \
  ( ((GdkGLProc_GLISVARIANTENABLEDEXT) (proc)) (id, cap) )

/* glGetVariantBooleanvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETVARIANTBOOLEANVEXT) (GLuint id, GLenum value, GLboolean *data);
GdkGLProc    gdk_gl_get_glGetVariantBooleanvEXT (void);
#define      gdk_gl_glGetVariantBooleanvEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETVARIANTBOOLEANVEXT) (proc)) (id, value, data) )

/* glGetVariantIntegervEXT */
typedef void (APIENTRY * GdkGLProc_GLGETVARIANTINTEGERVEXT) (GLuint id, GLenum value, GLint *data);
GdkGLProc    gdk_gl_get_glGetVariantIntegervEXT (void);
#define      gdk_gl_glGetVariantIntegervEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETVARIANTINTEGERVEXT) (proc)) (id, value, data) )

/* glGetVariantFloatvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETVARIANTFLOATVEXT) (GLuint id, GLenum value, GLfloat *data);
GdkGLProc    gdk_gl_get_glGetVariantFloatvEXT (void);
#define      gdk_gl_glGetVariantFloatvEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETVARIANTFLOATVEXT) (proc)) (id, value, data) )

/* glGetVariantPointervEXT */
typedef void (APIENTRY * GdkGLProc_GLGETVARIANTPOINTERVEXT) (GLuint id, GLenum value, GLvoid* *data);
GdkGLProc    gdk_gl_get_glGetVariantPointervEXT (void);
#define      gdk_gl_glGetVariantPointervEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETVARIANTPOINTERVEXT) (proc)) (id, value, data) )

/* glGetInvariantBooleanvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETINVARIANTBOOLEANVEXT) (GLuint id, GLenum value, GLboolean *data);
GdkGLProc    gdk_gl_get_glGetInvariantBooleanvEXT (void);
#define      gdk_gl_glGetInvariantBooleanvEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETINVARIANTBOOLEANVEXT) (proc)) (id, value, data) )

/* glGetInvariantIntegervEXT */
typedef void (APIENTRY * GdkGLProc_GLGETINVARIANTINTEGERVEXT) (GLuint id, GLenum value, GLint *data);
GdkGLProc    gdk_gl_get_glGetInvariantIntegervEXT (void);
#define      gdk_gl_glGetInvariantIntegervEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETINVARIANTINTEGERVEXT) (proc)) (id, value, data) )

/* glGetInvariantFloatvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETINVARIANTFLOATVEXT) (GLuint id, GLenum value, GLfloat *data);
GdkGLProc    gdk_gl_get_glGetInvariantFloatvEXT (void);
#define      gdk_gl_glGetInvariantFloatvEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETINVARIANTFLOATVEXT) (proc)) (id, value, data) )

/* glGetLocalConstantBooleanvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETLOCALCONSTANTBOOLEANVEXT) (GLuint id, GLenum value, GLboolean *data);
GdkGLProc    gdk_gl_get_glGetLocalConstantBooleanvEXT (void);
#define      gdk_gl_glGetLocalConstantBooleanvEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETLOCALCONSTANTBOOLEANVEXT) (proc)) (id, value, data) )

/* glGetLocalConstantIntegervEXT */
typedef void (APIENTRY * GdkGLProc_GLGETLOCALCONSTANTINTEGERVEXT) (GLuint id, GLenum value, GLint *data);
GdkGLProc    gdk_gl_get_glGetLocalConstantIntegervEXT (void);
#define      gdk_gl_glGetLocalConstantIntegervEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETLOCALCONSTANTINTEGERVEXT) (proc)) (id, value, data) )

/* glGetLocalConstantFloatvEXT */
typedef void (APIENTRY * GdkGLProc_GLGETLOCALCONSTANTFLOATVEXT) (GLuint id, GLenum value, GLfloat *data);
GdkGLProc    gdk_gl_get_glGetLocalConstantFloatvEXT (void);
#define      gdk_gl_glGetLocalConstantFloatvEXT(proc, id, value, data) \
  ( ((GdkGLProc_GLGETLOCALCONSTANTFLOATVEXT) (proc)) (id, value, data) )

/* 
 * GL_ATI_vertex_streams
 */

/* glVertexStream1sATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM1SATI) (GLenum stream, GLshort x);
GdkGLProc    gdk_gl_get_glVertexStream1sATI (void);
#define      gdk_gl_glVertexStream1sATI(proc, stream, x) \
  ( ((GdkGLProc_GLVERTEXSTREAM1SATI) (proc)) (stream, x) )

/* glVertexStream1svATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM1SVATI) (GLenum stream, const GLshort *coords);
GdkGLProc    gdk_gl_get_glVertexStream1svATI (void);
#define      gdk_gl_glVertexStream1svATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM1SVATI) (proc)) (stream, coords) )

/* glVertexStream1iATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM1IATI) (GLenum stream, GLint x);
GdkGLProc    gdk_gl_get_glVertexStream1iATI (void);
#define      gdk_gl_glVertexStream1iATI(proc, stream, x) \
  ( ((GdkGLProc_GLVERTEXSTREAM1IATI) (proc)) (stream, x) )

/* glVertexStream1ivATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM1IVATI) (GLenum stream, const GLint *coords);
GdkGLProc    gdk_gl_get_glVertexStream1ivATI (void);
#define      gdk_gl_glVertexStream1ivATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM1IVATI) (proc)) (stream, coords) )

/* glVertexStream1fATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM1FATI) (GLenum stream, GLfloat x);
GdkGLProc    gdk_gl_get_glVertexStream1fATI (void);
#define      gdk_gl_glVertexStream1fATI(proc, stream, x) \
  ( ((GdkGLProc_GLVERTEXSTREAM1FATI) (proc)) (stream, x) )

/* glVertexStream1fvATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM1FVATI) (GLenum stream, const GLfloat *coords);
GdkGLProc    gdk_gl_get_glVertexStream1fvATI (void);
#define      gdk_gl_glVertexStream1fvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM1FVATI) (proc)) (stream, coords) )

/* glVertexStream1dATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM1DATI) (GLenum stream, GLdouble x);
GdkGLProc    gdk_gl_get_glVertexStream1dATI (void);
#define      gdk_gl_glVertexStream1dATI(proc, stream, x) \
  ( ((GdkGLProc_GLVERTEXSTREAM1DATI) (proc)) (stream, x) )

/* glVertexStream1dvATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM1DVATI) (GLenum stream, const GLdouble *coords);
GdkGLProc    gdk_gl_get_glVertexStream1dvATI (void);
#define      gdk_gl_glVertexStream1dvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM1DVATI) (proc)) (stream, coords) )

/* glVertexStream2sATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM2SATI) (GLenum stream, GLshort x, GLshort y);
GdkGLProc    gdk_gl_get_glVertexStream2sATI (void);
#define      gdk_gl_glVertexStream2sATI(proc, stream, x, y) \
  ( ((GdkGLProc_GLVERTEXSTREAM2SATI) (proc)) (stream, x, y) )

/* glVertexStream2svATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM2SVATI) (GLenum stream, const GLshort *coords);
GdkGLProc    gdk_gl_get_glVertexStream2svATI (void);
#define      gdk_gl_glVertexStream2svATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM2SVATI) (proc)) (stream, coords) )

/* glVertexStream2iATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM2IATI) (GLenum stream, GLint x, GLint y);
GdkGLProc    gdk_gl_get_glVertexStream2iATI (void);
#define      gdk_gl_glVertexStream2iATI(proc, stream, x, y) \
  ( ((GdkGLProc_GLVERTEXSTREAM2IATI) (proc)) (stream, x, y) )

/* glVertexStream2ivATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM2IVATI) (GLenum stream, const GLint *coords);
GdkGLProc    gdk_gl_get_glVertexStream2ivATI (void);
#define      gdk_gl_glVertexStream2ivATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM2IVATI) (proc)) (stream, coords) )

/* glVertexStream2fATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM2FATI) (GLenum stream, GLfloat x, GLfloat y);
GdkGLProc    gdk_gl_get_glVertexStream2fATI (void);
#define      gdk_gl_glVertexStream2fATI(proc, stream, x, y) \
  ( ((GdkGLProc_GLVERTEXSTREAM2FATI) (proc)) (stream, x, y) )

/* glVertexStream2fvATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM2FVATI) (GLenum stream, const GLfloat *coords);
GdkGLProc    gdk_gl_get_glVertexStream2fvATI (void);
#define      gdk_gl_glVertexStream2fvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM2FVATI) (proc)) (stream, coords) )

/* glVertexStream2dATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM2DATI) (GLenum stream, GLdouble x, GLdouble y);
GdkGLProc    gdk_gl_get_glVertexStream2dATI (void);
#define      gdk_gl_glVertexStream2dATI(proc, stream, x, y) \
  ( ((GdkGLProc_GLVERTEXSTREAM2DATI) (proc)) (stream, x, y) )

/* glVertexStream2dvATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM2DVATI) (GLenum stream, const GLdouble *coords);
GdkGLProc    gdk_gl_get_glVertexStream2dvATI (void);
#define      gdk_gl_glVertexStream2dvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM2DVATI) (proc)) (stream, coords) )

/* glVertexStream3sATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM3SATI) (GLenum stream, GLshort x, GLshort y, GLshort z);
GdkGLProc    gdk_gl_get_glVertexStream3sATI (void);
#define      gdk_gl_glVertexStream3sATI(proc, stream, x, y, z) \
  ( ((GdkGLProc_GLVERTEXSTREAM3SATI) (proc)) (stream, x, y, z) )

/* glVertexStream3svATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM3SVATI) (GLenum stream, const GLshort *coords);
GdkGLProc    gdk_gl_get_glVertexStream3svATI (void);
#define      gdk_gl_glVertexStream3svATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM3SVATI) (proc)) (stream, coords) )

/* glVertexStream3iATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM3IATI) (GLenum stream, GLint x, GLint y, GLint z);
GdkGLProc    gdk_gl_get_glVertexStream3iATI (void);
#define      gdk_gl_glVertexStream3iATI(proc, stream, x, y, z) \
  ( ((GdkGLProc_GLVERTEXSTREAM3IATI) (proc)) (stream, x, y, z) )

/* glVertexStream3ivATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM3IVATI) (GLenum stream, const GLint *coords);
GdkGLProc    gdk_gl_get_glVertexStream3ivATI (void);
#define      gdk_gl_glVertexStream3ivATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM3IVATI) (proc)) (stream, coords) )

/* glVertexStream3fATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM3FATI) (GLenum stream, GLfloat x, GLfloat y, GLfloat z);
GdkGLProc    gdk_gl_get_glVertexStream3fATI (void);
#define      gdk_gl_glVertexStream3fATI(proc, stream, x, y, z) \
  ( ((GdkGLProc_GLVERTEXSTREAM3FATI) (proc)) (stream, x, y, z) )

/* glVertexStream3fvATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM3FVATI) (GLenum stream, const GLfloat *coords);
GdkGLProc    gdk_gl_get_glVertexStream3fvATI (void);
#define      gdk_gl_glVertexStream3fvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM3FVATI) (proc)) (stream, coords) )

/* glVertexStream3dATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM3DATI) (GLenum stream, GLdouble x, GLdouble y, GLdouble z);
GdkGLProc    gdk_gl_get_glVertexStream3dATI (void);
#define      gdk_gl_glVertexStream3dATI(proc, stream, x, y, z) \
  ( ((GdkGLProc_GLVERTEXSTREAM3DATI) (proc)) (stream, x, y, z) )

/* glVertexStream3dvATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM3DVATI) (GLenum stream, const GLdouble *coords);
GdkGLProc    gdk_gl_get_glVertexStream3dvATI (void);
#define      gdk_gl_glVertexStream3dvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM3DVATI) (proc)) (stream, coords) )

/* glVertexStream4sATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM4SATI) (GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
GdkGLProc    gdk_gl_get_glVertexStream4sATI (void);
#define      gdk_gl_glVertexStream4sATI(proc, stream, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXSTREAM4SATI) (proc)) (stream, x, y, z, w) )

/* glVertexStream4svATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM4SVATI) (GLenum stream, const GLshort *coords);
GdkGLProc    gdk_gl_get_glVertexStream4svATI (void);
#define      gdk_gl_glVertexStream4svATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM4SVATI) (proc)) (stream, coords) )

/* glVertexStream4iATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM4IATI) (GLenum stream, GLint x, GLint y, GLint z, GLint w);
GdkGLProc    gdk_gl_get_glVertexStream4iATI (void);
#define      gdk_gl_glVertexStream4iATI(proc, stream, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXSTREAM4IATI) (proc)) (stream, x, y, z, w) )

/* glVertexStream4ivATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM4IVATI) (GLenum stream, const GLint *coords);
GdkGLProc    gdk_gl_get_glVertexStream4ivATI (void);
#define      gdk_gl_glVertexStream4ivATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM4IVATI) (proc)) (stream, coords) )

/* glVertexStream4fATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM4FATI) (GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GdkGLProc    gdk_gl_get_glVertexStream4fATI (void);
#define      gdk_gl_glVertexStream4fATI(proc, stream, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXSTREAM4FATI) (proc)) (stream, x, y, z, w) )

/* glVertexStream4fvATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM4FVATI) (GLenum stream, const GLfloat *coords);
GdkGLProc    gdk_gl_get_glVertexStream4fvATI (void);
#define      gdk_gl_glVertexStream4fvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM4FVATI) (proc)) (stream, coords) )

/* glVertexStream4dATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM4DATI) (GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GdkGLProc    gdk_gl_get_glVertexStream4dATI (void);
#define      gdk_gl_glVertexStream4dATI(proc, stream, x, y, z, w) \
  ( ((GdkGLProc_GLVERTEXSTREAM4DATI) (proc)) (stream, x, y, z, w) )

/* glVertexStream4dvATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXSTREAM4DVATI) (GLenum stream, const GLdouble *coords);
GdkGLProc    gdk_gl_get_glVertexStream4dvATI (void);
#define      gdk_gl_glVertexStream4dvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLVERTEXSTREAM4DVATI) (proc)) (stream, coords) )

/* glNormalStream3bATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3BATI) (GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
GdkGLProc    gdk_gl_get_glNormalStream3bATI (void);
#define      gdk_gl_glNormalStream3bATI(proc, stream, nx, ny, nz) \
  ( ((GdkGLProc_GLNORMALSTREAM3BATI) (proc)) (stream, nx, ny, nz) )

/* glNormalStream3bvATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3BVATI) (GLenum stream, const GLbyte *coords);
GdkGLProc    gdk_gl_get_glNormalStream3bvATI (void);
#define      gdk_gl_glNormalStream3bvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLNORMALSTREAM3BVATI) (proc)) (stream, coords) )

/* glNormalStream3sATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3SATI) (GLenum stream, GLshort nx, GLshort ny, GLshort nz);
GdkGLProc    gdk_gl_get_glNormalStream3sATI (void);
#define      gdk_gl_glNormalStream3sATI(proc, stream, nx, ny, nz) \
  ( ((GdkGLProc_GLNORMALSTREAM3SATI) (proc)) (stream, nx, ny, nz) )

/* glNormalStream3svATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3SVATI) (GLenum stream, const GLshort *coords);
GdkGLProc    gdk_gl_get_glNormalStream3svATI (void);
#define      gdk_gl_glNormalStream3svATI(proc, stream, coords) \
  ( ((GdkGLProc_GLNORMALSTREAM3SVATI) (proc)) (stream, coords) )

/* glNormalStream3iATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3IATI) (GLenum stream, GLint nx, GLint ny, GLint nz);
GdkGLProc    gdk_gl_get_glNormalStream3iATI (void);
#define      gdk_gl_glNormalStream3iATI(proc, stream, nx, ny, nz) \
  ( ((GdkGLProc_GLNORMALSTREAM3IATI) (proc)) (stream, nx, ny, nz) )

/* glNormalStream3ivATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3IVATI) (GLenum stream, const GLint *coords);
GdkGLProc    gdk_gl_get_glNormalStream3ivATI (void);
#define      gdk_gl_glNormalStream3ivATI(proc, stream, coords) \
  ( ((GdkGLProc_GLNORMALSTREAM3IVATI) (proc)) (stream, coords) )

/* glNormalStream3fATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3FATI) (GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
GdkGLProc    gdk_gl_get_glNormalStream3fATI (void);
#define      gdk_gl_glNormalStream3fATI(proc, stream, nx, ny, nz) \
  ( ((GdkGLProc_GLNORMALSTREAM3FATI) (proc)) (stream, nx, ny, nz) )

/* glNormalStream3fvATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3FVATI) (GLenum stream, const GLfloat *coords);
GdkGLProc    gdk_gl_get_glNormalStream3fvATI (void);
#define      gdk_gl_glNormalStream3fvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLNORMALSTREAM3FVATI) (proc)) (stream, coords) )

/* glNormalStream3dATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3DATI) (GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
GdkGLProc    gdk_gl_get_glNormalStream3dATI (void);
#define      gdk_gl_glNormalStream3dATI(proc, stream, nx, ny, nz) \
  ( ((GdkGLProc_GLNORMALSTREAM3DATI) (proc)) (stream, nx, ny, nz) )

/* glNormalStream3dvATI */
typedef void (APIENTRY * GdkGLProc_GLNORMALSTREAM3DVATI) (GLenum stream, const GLdouble *coords);
GdkGLProc    gdk_gl_get_glNormalStream3dvATI (void);
#define      gdk_gl_glNormalStream3dvATI(proc, stream, coords) \
  ( ((GdkGLProc_GLNORMALSTREAM3DVATI) (proc)) (stream, coords) )

/* glClientActiveVertexStreamATI */
typedef void (APIENTRY * GdkGLProc_GLCLIENTACTIVEVERTEXSTREAMATI) (GLenum stream);
GdkGLProc    gdk_gl_get_glClientActiveVertexStreamATI (void);
#define      gdk_gl_glClientActiveVertexStreamATI(proc, stream) \
  ( ((GdkGLProc_GLCLIENTACTIVEVERTEXSTREAMATI) (proc)) (stream) )

/* glVertexBlendEnviATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXBLENDENVIATI) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glVertexBlendEnviATI (void);
#define      gdk_gl_glVertexBlendEnviATI(proc, pname, param) \
  ( ((GdkGLProc_GLVERTEXBLENDENVIATI) (proc)) (pname, param) )

/* glVertexBlendEnvfATI */
typedef void (APIENTRY * GdkGLProc_GLVERTEXBLENDENVFATI) (GLenum pname, GLfloat param);
GdkGLProc    gdk_gl_get_glVertexBlendEnvfATI (void);
#define      gdk_gl_glVertexBlendEnvfATI(proc, pname, param) \
  ( ((GdkGLProc_GLVERTEXBLENDENVFATI) (proc)) (pname, param) )

/* 
 * GL_ATI_element_array
 */

/* glElementPointerATI */
typedef void (APIENTRY * GdkGLProc_GLELEMENTPOINTERATI) (GLenum type, const GLvoid *pointer);
GdkGLProc    gdk_gl_get_glElementPointerATI (void);
#define      gdk_gl_glElementPointerATI(proc, type, pointer) \
  ( ((GdkGLProc_GLELEMENTPOINTERATI) (proc)) (type, pointer) )

/* glDrawElementArrayATI */
typedef void (APIENTRY * GdkGLProc_GLDRAWELEMENTARRAYATI) (GLenum mode, GLsizei count);
GdkGLProc    gdk_gl_get_glDrawElementArrayATI (void);
#define      gdk_gl_glDrawElementArrayATI(proc, mode, count) \
  ( ((GdkGLProc_GLDRAWELEMENTARRAYATI) (proc)) (mode, count) )

/* glDrawRangeElementArrayATI */
typedef void (APIENTRY * GdkGLProc_GLDRAWRANGEELEMENTARRAYATI) (GLenum mode, GLuint start, GLuint end, GLsizei count);
GdkGLProc    gdk_gl_get_glDrawRangeElementArrayATI (void);
#define      gdk_gl_glDrawRangeElementArrayATI(proc, mode, start, end, count) \
  ( ((GdkGLProc_GLDRAWRANGEELEMENTARRAYATI) (proc)) (mode, start, end, count) )

/* 
 * GL_SUN_mesh_array
 */

/* glDrawMeshArraysSUN */
typedef void (APIENTRY * GdkGLProc_GLDRAWMESHARRAYSSUN) (GLenum mode, GLint first, GLsizei count, GLsizei width);
GdkGLProc    gdk_gl_get_glDrawMeshArraysSUN (void);
#define      gdk_gl_glDrawMeshArraysSUN(proc, mode, first, count, width) \
  ( ((GdkGLProc_GLDRAWMESHARRAYSSUN) (proc)) (mode, first, count, width) )

/* 
 * GL_NV_occlusion_query
 */

/* glGenOcclusionQueriesNV */
typedef void (APIENTRY * GdkGLProc_GLGENOCCLUSIONQUERIESNV) (GLsizei n, GLuint *ids);
GdkGLProc    gdk_gl_get_glGenOcclusionQueriesNV (void);
#define      gdk_gl_glGenOcclusionQueriesNV(proc, n, ids) \
  ( ((GdkGLProc_GLGENOCCLUSIONQUERIESNV) (proc)) (n, ids) )

/* glDeleteOcclusionQueriesNV */
typedef void (APIENTRY * GdkGLProc_GLDELETEOCCLUSIONQUERIESNV) (GLsizei n, const GLuint *ids);
GdkGLProc    gdk_gl_get_glDeleteOcclusionQueriesNV (void);
#define      gdk_gl_glDeleteOcclusionQueriesNV(proc, n, ids) \
  ( ((GdkGLProc_GLDELETEOCCLUSIONQUERIESNV) (proc)) (n, ids) )

/* glIsOcclusionQueryNV */
typedef GLboolean (APIENTRY * GdkGLProc_GLISOCCLUSIONQUERYNV) (GLuint id);
GdkGLProc    gdk_gl_get_glIsOcclusionQueryNV (void);
#define      gdk_gl_glIsOcclusionQueryNV(proc, id) \
  ( ((GdkGLProc_GLISOCCLUSIONQUERYNV) (proc)) (id) )

/* glBeginOcclusionQueryNV */
typedef void (APIENTRY * GdkGLProc_GLBEGINOCCLUSIONQUERYNV) (GLuint id);
GdkGLProc    gdk_gl_get_glBeginOcclusionQueryNV (void);
#define      gdk_gl_glBeginOcclusionQueryNV(proc, id) \
  ( ((GdkGLProc_GLBEGINOCCLUSIONQUERYNV) (proc)) (id) )

/* glEndOcclusionQueryNV */
typedef void (APIENTRY * GdkGLProc_GLENDOCCLUSIONQUERYNV) (void);
GdkGLProc    gdk_gl_get_glEndOcclusionQueryNV (void);
#define      gdk_gl_glEndOcclusionQueryNV(proc) \
  ( ((GdkGLProc_GLENDOCCLUSIONQUERYNV) (proc)) () )

/* glGetOcclusionQueryivNV */
typedef void (APIENTRY * GdkGLProc_GLGETOCCLUSIONQUERYIVNV) (GLuint id, GLenum pname, GLint *params);
GdkGLProc    gdk_gl_get_glGetOcclusionQueryivNV (void);
#define      gdk_gl_glGetOcclusionQueryivNV(proc, id, pname, params) \
  ( ((GdkGLProc_GLGETOCCLUSIONQUERYIVNV) (proc)) (id, pname, params) )

/* glGetOcclusionQueryuivNV */
typedef void (APIENTRY * GdkGLProc_GLGETOCCLUSIONQUERYUIVNV) (GLuint id, GLenum pname, GLuint *params);
GdkGLProc    gdk_gl_get_glGetOcclusionQueryuivNV (void);
#define      gdk_gl_glGetOcclusionQueryuivNV(proc, id, pname, params) \
  ( ((GdkGLProc_GLGETOCCLUSIONQUERYUIVNV) (proc)) (id, pname, params) )

/* 
 * GL_NV_point_sprite
 */

/* glPointParameteriNV */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERINV) (GLenum pname, GLint param);
GdkGLProc    gdk_gl_get_glPointParameteriNV (void);
#define      gdk_gl_glPointParameteriNV(proc, pname, param) \
  ( ((GdkGLProc_GLPOINTPARAMETERINV) (proc)) (pname, param) )

/* glPointParameterivNV */
typedef void (APIENTRY * GdkGLProc_GLPOINTPARAMETERIVNV) (GLenum pname, const GLint *params);
GdkGLProc    gdk_gl_get_glPointParameterivNV (void);
#define      gdk_gl_glPointParameterivNV(proc, pname, params) \
  ( ((GdkGLProc_GLPOINTPARAMETERIVNV) (proc)) (pname, params) )

/* 
 * GL_EXT_stencil_two_side
 */

/* glActiveStencilFaceEXT */
typedef void (APIENTRY * GdkGLProc_GLACTIVESTENCILFACEEXT) (GLenum face);
GdkGLProc    gdk_gl_get_glActiveStencilFaceEXT (void);
#define      gdk_gl_glActiveStencilFaceEXT(proc, face) \
  ( ((GdkGLProc_GLACTIVESTENCILFACEEXT) (proc)) (face) )

G_END_DECLS

#endif /* __GDK_GL_GLEXT_H__ */
