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

/* void glBlendColor (GLclampf, GLclampf, GLclampf, GLclampf) */
GdkGLProc gdk_gl_get_glBlendColor (void);
#define   gdk_gl_glBlendColor(proc, red, green, blue, alpha) \
  ( ((PFNGLBLENDCOLORPROC) (proc)) (red, green, blue, alpha) )

/* void glBlendEquation (GLenum) */
GdkGLProc gdk_gl_get_glBlendEquation (void);
#define   gdk_gl_glBlendEquation(proc, mode) \
  ( ((PFNGLBLENDEQUATIONPROC) (proc)) (mode) )

/* void glDrawRangeElements (GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glDrawRangeElements (void);
#define   gdk_gl_glDrawRangeElements(proc, mode, start, end, count, type, indices) \
  ( ((PFNGLDRAWRANGEELEMENTSPROC) (proc)) (mode, start, end, count, type, indices) )

/* void glColorTable (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glColorTable (void);
#define   gdk_gl_glColorTable(proc, target, internalformat, width, format, type, table) \
  ( ((PFNGLCOLORTABLEPROC) (proc)) (target, internalformat, width, format, type, table) )

/* void glColorTableParameterfv (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glColorTableParameterfv (void);
#define   gdk_gl_glColorTableParameterfv(proc, target, pname, params) \
  ( ((PFNGLCOLORTABLEPARAMETERFVPROC) (proc)) (target, pname, params) )

/* void glColorTableParameteriv (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glColorTableParameteriv (void);
#define   gdk_gl_glColorTableParameteriv(proc, target, pname, params) \
  ( ((PFNGLCOLORTABLEPARAMETERIVPROC) (proc)) (target, pname, params) )

/* void glCopyColorTable (GLenum, GLenum, GLint, GLint, GLsizei) */
GdkGLProc gdk_gl_get_glCopyColorTable (void);
#define   gdk_gl_glCopyColorTable(proc, target, internalformat, x, y, width) \
  ( ((PFNGLCOPYCOLORTABLEPROC) (proc)) (target, internalformat, x, y, width) )

/* void glGetColorTable (GLenum, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetColorTable (void);
#define   gdk_gl_glGetColorTable(proc, target, format, type, table) \
  ( ((PFNGLGETCOLORTABLEPROC) (proc)) (target, format, type, table) )

/* void glGetColorTableParameterfv (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetColorTableParameterfv (void);
#define   gdk_gl_glGetColorTableParameterfv(proc, target, pname, params) \
  ( ((PFNGLGETCOLORTABLEPARAMETERFVPROC) (proc)) (target, pname, params) )

/* void glGetColorTableParameteriv (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetColorTableParameteriv (void);
#define   gdk_gl_glGetColorTableParameteriv(proc, target, pname, params) \
  ( ((PFNGLGETCOLORTABLEPARAMETERIVPROC) (proc)) (target, pname, params) )

/* void glColorSubTable (GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glColorSubTable (void);
#define   gdk_gl_glColorSubTable(proc, target, start, count, format, type, data) \
  ( ((PFNGLCOLORSUBTABLEPROC) (proc)) (target, start, count, format, type, data) )

/* void glCopyColorSubTable (GLenum, GLsizei, GLint, GLint, GLsizei) */
GdkGLProc gdk_gl_get_glCopyColorSubTable (void);
#define   gdk_gl_glCopyColorSubTable(proc, target, start, x, y, width) \
  ( ((PFNGLCOPYCOLORSUBTABLEPROC) (proc)) (target, start, x, y, width) )

/* void glConvolutionFilter1D (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glConvolutionFilter1D (void);
#define   gdk_gl_glConvolutionFilter1D(proc, target, internalformat, width, format, type, image) \
  ( ((PFNGLCONVOLUTIONFILTER1DPROC) (proc)) (target, internalformat, width, format, type, image) )

/* void glConvolutionFilter2D (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glConvolutionFilter2D (void);
#define   gdk_gl_glConvolutionFilter2D(proc, target, internalformat, width, height, format, type, image) \
  ( ((PFNGLCONVOLUTIONFILTER2DPROC) (proc)) (target, internalformat, width, height, format, type, image) )

/* void glConvolutionParameterf (GLenum, GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glConvolutionParameterf (void);
#define   gdk_gl_glConvolutionParameterf(proc, target, pname, params) \
  ( ((PFNGLCONVOLUTIONPARAMETERFPROC) (proc)) (target, pname, params) )

/* void glConvolutionParameterfv (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glConvolutionParameterfv (void);
#define   gdk_gl_glConvolutionParameterfv(proc, target, pname, params) \
  ( ((PFNGLCONVOLUTIONPARAMETERFVPROC) (proc)) (target, pname, params) )

/* void glConvolutionParameteri (GLenum, GLenum, GLint) */
GdkGLProc gdk_gl_get_nglConvolutionParameteri (void);
#define   gdk_gl_glConvolutionParameteri(proc, target, pname, params) \
  ( ((PFNGLCONVOLUTIONPARAMETERIPROC) (proc)) (target, pname, params) )

/* void glConvolutionParameteriv (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glConvolutionParameteriv (void);
#define   gdk_gl_glConvolutionParameteriv(proc, target, pname, params) \
  ( ((PFNGLCONVOLUTIONPARAMETERIVPROC) (proc)) (target, pname, params) )

/* void glCopyConvolutionFilter1D (GLenum, GLenum, GLint, GLint, GLsizei) */
GdkGLProc gdk_gl_get_glCopyConvolutionFilter1D (void);
#define   gdk_gl_glCopyConvolutionFilter1D(proc, target, internalformat, x, y, width) \
  ( ((PFNGLCOPYCONVOLUTIONFILTER1DPROC) (proc)) (target, internalformat, x, y, width) )

/* void glCopyConvolutionFilter2D (GLenum, GLenum, GLint, GLint, GLsizei, GLsizei) */
GdkGLProc gdk_gl_get_glCopyConvolutionFilter2D (void);
#define   gdk_gl_glCopyConvolutionFilter2D(proc, target, internalformat, x, y, width, height) \
  ( ((PFNGLCOPYCONVOLUTIONFILTER2DPROC) (proc)) (target, internalformat, x, y, width, height) )

/* void glGetConvolutionFilter (GLenum, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetConvolutionFilter (void);
#define   gdk_gl_glGetConvolutionFilter(proc, target, format, type, image) \
  ( ((PFNGLGETCONVOLUTIONFILTERPROC) (proc)) (target, format, type, image) )

/* void glGetConvolutionParameterfv (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetConvolutionParameterfv (void);
#define   gdk_gl_glGetConvolutionParameterfv(proc, target, pname, params) \
  ( ((PFNGLGETCONVOLUTIONPARAMETERFVPROC) (proc)) (target, pname, params) )

/* void glGetConvolutionParameteriv (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetConvolutionParameteriv (void);
#define   gdk_gl_glGetConvolutionParameteriv(proc, target, pname, params) \
  ( ((PFNGLGETCONVOLUTIONPARAMETERIVPROC) (proc)) (target, pname, params) )

/* void glGetSeparableFilter (GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *) */
GdkGLProc gdk_gl_get_glGetSeparableFilter (void);
#define   gdk_gl_glGetSeparableFilter(proc, target, format, type, row, column, span) \
  ( ((PFNGLGETSEPARABLEFILTERPROC) (proc)) (target, format, type, row, column, span) )

/* void glSeparableFilter2D (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *) */
GdkGLProc gdk_gl_get_glSeparableFilter2D (void);
#define   gdk_gl_glSeparableFilter2D(proc, target, internalformat, width, height, format, type, row, column) \
  ( ((PFNGLSEPARABLEFILTER2DPROC) (proc)) (target, internalformat, width, height, format, type, row, column) )

/* void glGetHistogram (GLenum, GLboolean, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetHistogram (void);
#define   gdk_gl_glGetHistogram(proc, target, reset, format, type, values) \
  ( ((PFNGLGETHISTOGRAMPROC) (proc)) (target, reset, format, type, values) )

/* void glGetHistogramParameterfv (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetHistogramParameterfv (void);
#define   gdk_gl_glGetHistogramParameterfv(proc, target, pname, params) \
  ( ((PFNGLGETHISTOGRAMPARAMETERFVPROC) (proc)) (target, pname, params) )

/* void glGetHistogramParameteriv (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetHistogramParameteriv (void);
#define   gdk_gl_glGetHistogramParameteriv(proc, target, pname, params) \
  ( ((PFNGLGETHISTOGRAMPARAMETERIVPROC) (proc)) (target, pname, params) )

/* void glGetMinmax (GLenum, GLboolean, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetMinmax (void);
#define   gdk_gl_glGetMinmax(proc, target, reset, format, type, values) \
  ( ((PFNGLGETMINMAXPROC) (proc)) (target, reset, format, type, values) )

/* void glGetMinmaxParameterfv (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetMinmaxParameterfv (void);
#define   gdk_gl_glGetMinmaxParameterfv(proc, target, pname, params) \
  ( ((PFNGLGETMINMAXPARAMETERFVPROC) (proc)) (target, pname, params) )

/* void glGetMinmaxParameteriv (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetMinmaxParameteriv (void);
#define   gdk_gl_glGetMinmaxParameteriv(proc, target, pname, params) \
  ( ((PFNGLGETMINMAXPARAMETERIVPROC) (proc)) (target, pname, params) )

/* void glHistogram (GLenum, GLsizei, GLenum, GLboolean) */
GdkGLProc gdk_gl_get_glHistogram (void);
#define   gdk_gl_glHistogram(proc, target, width, internalformat, sink) \
  ( ((PFNGLHISTOGRAMPROC) (proc)) (target, width, internalformat, sink) )

/* void glMinmax (GLenum, GLenum, GLboolean) */
GdkGLProc gdk_gl_get_glMinmax (void);
#define   gdk_gl_glMinmax(proc, target, internalformat, sink) \
  ( ((PFNGLMINMAXPROC) (proc)) (target, internalformat, sink) )

/* void glResetHistogram (GLenum) */
GdkGLProc gdk_gl_get_glResetHistogram (void);
#define   gdk_gl_glResetHistogram(proc, target) \
  ( ((PFNGLRESETHISTOGRAMPROC) (proc)) (target) )

/* void glResetMinmax (GLenum) */
GdkGLProc gdk_gl_get_glResetMinmax (void);
#define   gdk_gl_glResetMinmax(proc, target) \
  ( ((PFNGLRESETMINMAXPROC) (proc)) (target) )

/* void glTexImage3D (GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexImage3D (void);
#define   gdk_gl_glTexImage3D(proc, target, level, internalformat, width, height, depth, border, format, type, pixels) \
  ( ((PFNGLTEXIMAGE3DPROC) (proc)) (target, level, internalformat, width, height, depth, border, format, type, pixels) )

/* void glTexSubImage3D (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexSubImage3D (void);
#define   gdk_gl_glTexSubImage3D(proc, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) \
  ( ((PFNGLTEXSUBIMAGE3DPROC) (proc)) (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) )

/* void glCopyTexSubImage3D (GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) */
GdkGLProc gdk_gl_get_glCopyTexSubImage3D (void);
#define   gdk_gl_glCopyTexSubImage3D(proc, target, level, xoffset, yoffset, zoffset, x, y, width, height) \
  ( ((PFNGLCOPYTEXSUBIMAGE3DPROC) (proc)) (target, level, xoffset, yoffset, zoffset, x, y, width, height) )

/* 
 * GL_VERSION_1_3
 */

/* void glActiveTexture (GLenum) */
GdkGLProc gdk_gl_get_glActiveTexture (void);
#define   gdk_gl_glActiveTexture(proc, texture) \
  ( ((PFNGLACTIVETEXTUREPROC) (proc)) (texture) )

/* void glClientActiveTexture (GLenum) */
GdkGLProc gdk_gl_get_glClientActiveTexture (void);
#define   gdk_gl_glClientActiveTexture(proc, texture) \
  ( ((PFNGLCLIENTACTIVETEXTUREPROC) (proc)) (texture) )

/* void glMultiTexCoord1d (GLenum, GLdouble) */
GdkGLProc gdk_gl_get_glMultiTexCoord1d (void);
#define   gdk_gl_glMultiTexCoord1d(proc, target, s) \
  ( ((PFNGLMULTITEXCOORD1DPROC) (proc)) (target, s) )

/* void glMultiTexCoord1dv (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glMultiTexCoord1dv (void);
#define   gdk_gl_glMultiTexCoord1dv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD1DVPROC) (proc)) (target, v) )

/* void glMultiTexCoord1f (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glMultiTexCoord1f (void);
#define   gdk_gl_glMultiTexCoord1f(proc, target, s) \
  ( ((PFNGLMULTITEXCOORD1FPROC) (proc)) (target, s) )

/* void glMultiTexCoord1fv (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMultiTexCoord1fv (void);
#define   gdk_gl_glMultiTexCoord1fv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD1FVPROC) (proc)) (target, v) )

/* void glMultiTexCoord1i (GLenum, GLint) */
GdkGLProc gdk_gl_get_glMultiTexCoord1i (void);
#define   gdk_gl_glMultiTexCoord1i(proc, target, s) \
  ( ((PFNGLMULTITEXCOORD1IPROC) (proc)) (target, s) )

/* void glMultiTexCoord1iv (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMultiTexCoord1iv (void);
#define   gdk_gl_glMultiTexCoord1iv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD1IVPROC) (proc)) (target, v) )

/* void glMultiTexCoord1s (GLenum, GLshort) */
GdkGLProc gdk_gl_get_glMultiTexCoord1s (void);
#define   gdk_gl_glMultiTexCoord1s(proc, target, s) \
  ( ((PFNGLMULTITEXCOORD1SPROC) (proc)) (target, s) )

/* void glMultiTexCoord1sv (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glMultiTexCoord1sv (void);
#define   gdk_gl_glMultiTexCoord1sv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD1SVPROC) (proc)) (target, v) )

/* void glMultiTexCoord2d (GLenum, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glMultiTexCoord2d (void);
#define   gdk_gl_glMultiTexCoord2d(proc, target, s, t) \
  ( ((PFNGLMULTITEXCOORD2DPROC) (proc)) (target, s, t) )

/* void glMultiTexCoord2dv (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glMultiTexCoord2dv (void);
#define   gdk_gl_glMultiTexCoord2dv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD2DVPROC) (proc)) (target, v) )

/* void glMultiTexCoord2f (GLenum, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glMultiTexCoord2f (void);
#define   gdk_gl_glMultiTexCoord2f(proc, target, s, t) \
  ( ((PFNGLMULTITEXCOORD2FPROC) (proc)) (target, s, t) )

/* void glMultiTexCoord2fv (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMultiTexCoord2fv (void);
#define   gdk_gl_glMultiTexCoord2fv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD2FVPROC) (proc)) (target, v) )

/* void glMultiTexCoord2i (GLenum, GLint, GLint) */
GdkGLProc gdk_gl_get_glMultiTexCoord2i (void);
#define   gdk_gl_glMultiTexCoord2i(proc, target, s, t) \
  ( ((PFNGLMULTITEXCOORD2IPROC) (proc)) (target, s, t) )

/* void glMultiTexCoord2iv (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMultiTexCoord2iv (void);
#define   gdk_gl_glMultiTexCoord2iv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD2IVPROC) (proc)) (target, v) )

/* void glMultiTexCoord2s (GLenum, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glMultiTexCoord2s (void);
#define   gdk_gl_glMultiTexCoord2s(proc, target, s, t) \
  ( ((PFNGLMULTITEXCOORD2SPROC) (proc)) (target, s, t) )

/* void glMultiTexCoord2sv (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glMultiTexCoord2sv (void);
#define   gdk_gl_glMultiTexCoord2sv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD2SVPROC) (proc)) (target, v) )

/* void glMultiTexCoord3d (GLenum, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glMultiTexCoord3d (void);
#define   gdk_gl_glMultiTexCoord3d(proc, target, s, t, r) \
  ( ((PFNGLMULTITEXCOORD3DPROC) (proc)) (target, s, t, r) )

/* void glMultiTexCoord3dv (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glMultiTexCoord3dv (void);
#define   gdk_gl_glMultiTexCoord3dv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD3DVPROC) (proc)) (target, v) )

/* void glMultiTexCoord3f (GLenum, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glMultiTexCoord3f (void);
#define   gdk_gl_glMultiTexCoord3f(proc, target, s, t, r) \
  ( ((PFNGLMULTITEXCOORD3FPROC) (proc)) (target, s, t, r) )

/* void glMultiTexCoord3fv (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMultiTexCoord3fv (void);
#define   gdk_gl_glMultiTexCoord3fv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD3FVPROC) (proc)) (target, v) )

/* void glMultiTexCoord3i (GLenum, GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glMultiTexCoord3i (void);
#define   gdk_gl_glMultiTexCoord3i(proc, target, s, t, r) \
  ( ((PFNGLMULTITEXCOORD3IPROC) (proc)) (target, s, t, r) )

/* void glMultiTexCoord3iv (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMultiTexCoord3iv (void);
#define   gdk_gl_glMultiTexCoord3iv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD3IVPROC) (proc)) (target, v) )

/* void glMultiTexCoord3s (GLenum, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glMultiTexCoord3s (void);
#define   gdk_gl_glMultiTexCoord3s(proc, target, s, t, r) \
  ( ((PFNGLMULTITEXCOORD3SPROC) (proc)) (target, s, t, r) )

/* void glMultiTexCoord3sv (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glMultiTexCoord3sv (void);
#define   gdk_gl_glMultiTexCoord3sv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD3SVPROC) (proc)) (target, v) )

/* void glMultiTexCoord4d (GLenum, GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glMultiTexCoord4d (void);
#define   gdk_gl_glMultiTexCoord4d(proc, target, s, t, r, q) \
  ( ((PFNGLMULTITEXCOORD4DPROC) (proc)) (target, s, t, r, q) )

/* void glMultiTexCoord4dv (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glMultiTexCoord4dv (void);
#define   gdk_gl_glMultiTexCoord4dv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD4DVPROC) (proc)) (target, v) )

/* void glMultiTexCoord4f (GLenum, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glMultiTexCoord4f (void);
#define   gdk_gl_glMultiTexCoord4f(proc, target, s, t, r, q) \
  ( ((PFNGLMULTITEXCOORD4FPROC) (proc)) (target, s, t, r, q) )

/* void glMultiTexCoord4fv (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMultiTexCoord4fv (void);
#define   gdk_gl_glMultiTexCoord4fv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD4FVPROC) (proc)) (target, v) )

/* void glMultiTexCoord4i (GLenum, GLint, GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glMultiTexCoord4i (void);
#define   gdk_gl_glMultiTexCoord4i(proc, target, s, t, r, q) \
  ( ((PFNGLMULTITEXCOORD4IPROC) (proc)) (target, s, t, r, q) )

/* void glMultiTexCoord4iv (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMultiTexCoord4iv (void);
#define   gdk_gl_glMultiTexCoord4iv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD4IVPROC) (proc)) (target, v) )

/* void glMultiTexCoord4s (GLenum, GLshort, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glMultiTexCoord4s (void);
#define   gdk_gl_glMultiTexCoord4s(proc, target, s, t, r, q) \
  ( ((PFNGLMULTITEXCOORD4SPROC) (proc)) (target, s, t, r, q) )

/* void glMultiTexCoord4sv (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glMultiTexCoord4sv (void);
#define   gdk_gl_glMultiTexCoord4sv(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD4SVPROC) (proc)) (target, v) )

/* void glLoadTransposeMatrixf (const GLfloat *) */
GdkGLProc gdk_gl_get_glLoadTransposeMatrixf (void);
#define   gdk_gl_glLoadTransposeMatrixf(proc, m) \
  ( ((PFNGLLOADTRANSPOSEMATRIXFPROC) (proc)) (m) )

/* void glLoadTransposeMatrixd (const GLdouble *) */
GdkGLProc gdk_gl_get_glLoadTransposeMatrixd (void);
#define   gdk_gl_glLoadTransposeMatrixd(proc, m) \
  ( ((PFNGLLOADTRANSPOSEMATRIXDPROC) (proc)) (m) )

/* void glMultTransposeMatrixf (const GLfloat *) */
GdkGLProc gdk_gl_get_glMultTransposeMatrixf (void);
#define   gdk_gl_glMultTransposeMatrixf(proc, m) \
  ( ((PFNGLMULTTRANSPOSEMATRIXFPROC) (proc)) (m) )

/* void glMultTransposeMatrixd (const GLdouble *) */
GdkGLProc gdk_gl_get_glMultTransposeMatrixd (void);
#define   gdk_gl_glMultTransposeMatrixd(proc, m) \
  ( ((PFNGLMULTTRANSPOSEMATRIXDPROC) (proc)) (m) )

/* void glSampleCoverage (GLclampf, GLboolean) */
GdkGLProc gdk_gl_get_glSampleCoverage (void);
#define   gdk_gl_glSampleCoverage(proc, value, invert) \
  ( ((PFNGLSAMPLECOVERAGEPROC) (proc)) (value, invert) )

/* void glCompressedTexImage3D (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexImage3D (void);
#define   gdk_gl_glCompressedTexImage3D(proc, target, level, internalformat, width, height, depth, border, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXIMAGE3DPROC) (proc)) (target, level, internalformat, width, height, depth, border, imageSize, data) )

/* void glCompressedTexImage2D (GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexImage2D (void);
#define   gdk_gl_glCompressedTexImage2D(proc, target, level, internalformat, width, height, border, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXIMAGE2DPROC) (proc)) (target, level, internalformat, width, height, border, imageSize, data) )

/* void glCompressedTexImage1D (GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexImage1D (void);
#define   gdk_gl_glCompressedTexImage1D(proc, target, level, internalformat, width, border, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXIMAGE1DPROC) (proc)) (target, level, internalformat, width, border, imageSize, data) )

/* void glCompressedTexSubImage3D (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexSubImage3D (void);
#define   gdk_gl_glCompressedTexSubImage3D(proc, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (proc)) (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) )

/* void glCompressedTexSubImage2D (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexSubImage2D (void);
#define   gdk_gl_glCompressedTexSubImage2D(proc, target, level, xoffset, yoffset, width, height, format, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (proc)) (target, level, xoffset, yoffset, width, height, format, imageSize, data) )

/* void glCompressedTexSubImage1D (GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexSubImage1D (void);
#define   gdk_gl_glCompressedTexSubImage1D(proc, target, level, xoffset, width, format, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (proc)) (target, level, xoffset, width, format, imageSize, data) )

/* void glGetCompressedTexImage (GLenum, GLint, void *) */
GdkGLProc gdk_gl_get_glGetCompressedTexImage (void);
#define   gdk_gl_glGetCompressedTexImage(proc, target, level, img) \
  ( ((PFNGLGETCOMPRESSEDTEXIMAGEPROC) (proc)) (target, level, img) )

/* 
 * GL_VERSION_1_4
 */

/* void glBlendFuncSeparate (GLenum, GLenum, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glBlendFuncSeparate (void);
#define   gdk_gl_glBlendFuncSeparate(proc, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) \
  ( ((PFNGLBLENDFUNCSEPARATEPROC) (proc)) (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) )

/* void glFogCoordf (GLfloat) */
GdkGLProc gdk_gl_get_glFogCoordf (void);
#define   gdk_gl_glFogCoordf(proc, coord) \
  ( ((PFNGLFOGCOORDFPROC) (proc)) (coord) )

/* void glFogCoordfv (const GLfloat *) */
GdkGLProc gdk_gl_get_glFogCoordfv (void);
#define   gdk_gl_glFogCoordfv(proc, coord) \
  ( ((PFNGLFOGCOORDFVPROC) (proc)) (coord) )

/* void glFogCoordd (GLdouble) */
GdkGLProc gdk_gl_get_glFogCoordd (void);
#define   gdk_gl_glFogCoordd(proc, coord) \
  ( ((PFNGLFOGCOORDDPROC) (proc)) (coord) )

/* void glFogCoorddv (const GLdouble *) */
GdkGLProc gdk_gl_get_glFogCoorddv (void);
#define   gdk_gl_glFogCoorddv(proc, coord) \
  ( ((PFNGLFOGCOORDDVPROC) (proc)) (coord) )

/* void glFogCoordPointer (GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glFogCoordPointer (void);
#define   gdk_gl_glFogCoordPointer(proc, type, stride, pointer) \
  ( ((PFNGLFOGCOORDPOINTERPROC) (proc)) (type, stride, pointer) )

/* void glMultiDrawArrays (GLenum, GLint *, GLsizei *, GLsizei) */
GdkGLProc gdk_gl_get_glMultiDrawArrays (void);
#define   gdk_gl_glMultiDrawArrays(proc, mode, first, count, primcount) \
  ( ((PFNGLMULTIDRAWARRAYSPROC) (proc)) (mode, first, count, primcount) )

/* void glMultiDrawElements (GLenum, const GLsizei *, GLenum, const GLvoid* *, GLsizei) */
GdkGLProc gdk_gl_get_glMultiDrawElements (void);
#define   gdk_gl_glMultiDrawElements(proc, mode, count, type, indices, primcount) \
  ( ((PFNGLMULTIDRAWELEMENTSPROC) (proc)) (mode, count, type, indices, primcount) )

/* void glPointParameterf (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glPointParameterf (void);
#define   gdk_gl_glPointParameterf(proc, pname, param) \
  ( ((PFNGLPOINTPARAMETERFPROC) (proc)) (pname, param) )

/* void glPointParameterfv (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glPointParameterfv (void);
#define   gdk_gl_glPointParameterfv(proc, pname, params) \
  ( ((PFNGLPOINTPARAMETERFVPROC) (proc)) (pname, params) )

/* void glPointParameteri (GLenum, GLint) */
GdkGLProc gdk_gl_get_glPointParameteri (void);
#define   gdk_gl_glPointParameteri(proc, pname, param) \
  ( ((PFNGLPOINTPARAMETERIPROC) (proc)) (pname, param) )

/* void glPointParameteriv (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glPointParameteriv (void);
#define   gdk_gl_glPointParameteriv(proc, pname, params) \
  ( ((PFNGLPOINTPARAMETERIVPROC) (proc)) (pname, params) )

/* void glSecondaryColor3b (GLbyte, GLbyte, GLbyte) */
GdkGLProc gdk_gl_get_glSecondaryColor3b (void);
#define   gdk_gl_glSecondaryColor3b(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3BPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3bv (const GLbyte *) */
GdkGLProc gdk_gl_get_glSecondaryColor3bv (void);
#define   gdk_gl_glSecondaryColor3bv(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3BVPROC) (proc)) (v) )

/* void glSecondaryColor3d (GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glSecondaryColor3d (void);
#define   gdk_gl_glSecondaryColor3d(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3DPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3dv (const GLdouble *) */
GdkGLProc gdk_gl_get_glSecondaryColor3dv (void);
#define   gdk_gl_glSecondaryColor3dv(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3DVPROC) (proc)) (v) )

/* void glSecondaryColor3f (GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glSecondaryColor3f (void);
#define   gdk_gl_glSecondaryColor3f(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3FPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3fv (const GLfloat *) */
GdkGLProc gdk_gl_get_glSecondaryColor3fv (void);
#define   gdk_gl_glSecondaryColor3fv(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3FVPROC) (proc)) (v) )

/* void glSecondaryColor3i (GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glSecondaryColor3i (void);
#define   gdk_gl_glSecondaryColor3i(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3IPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3iv (const GLint *) */
GdkGLProc gdk_gl_get_glSecondaryColor3iv (void);
#define   gdk_gl_glSecondaryColor3iv(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3IVPROC) (proc)) (v) )

/* void glSecondaryColor3s (GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glSecondaryColor3s (void);
#define   gdk_gl_glSecondaryColor3s(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3SPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3sv (const GLshort *) */
GdkGLProc gdk_gl_get_glSecondaryColor3sv (void);
#define   gdk_gl_glSecondaryColor3sv(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3SVPROC) (proc)) (v) )

/* void glSecondaryColor3ub (GLubyte, GLubyte, GLubyte) */
GdkGLProc gdk_gl_get_glSecondaryColor3ub (void);
#define   gdk_gl_glSecondaryColor3ub(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3UBPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3ubv (const GLubyte *) */
GdkGLProc gdk_gl_get_glSecondaryColor3ubv (void);
#define   gdk_gl_glSecondaryColor3ubv(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3UBVPROC) (proc)) (v) )

/* void glSecondaryColor3ui (GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glSecondaryColor3ui (void);
#define   gdk_gl_glSecondaryColor3ui(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3UIPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3uiv (const GLuint *) */
GdkGLProc gdk_gl_get_glSecondaryColor3uiv (void);
#define   gdk_gl_glSecondaryColor3uiv(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3UIVPROC) (proc)) (v) )

/* void glSecondaryColor3us (GLushort, GLushort, GLushort) */
GdkGLProc gdk_gl_get_glSecondaryColor3us (void);
#define   gdk_gl_glSecondaryColor3us(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3USPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3usv (const GLushort *) */
GdkGLProc gdk_gl_get_glSecondaryColor3usv (void);
#define   gdk_gl_glSecondaryColor3usv(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3USVPROC) (proc)) (v) )

/* void glSecondaryColorPointer (GLint, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glSecondaryColorPointer (void);
#define   gdk_gl_glSecondaryColorPointer(proc, size, type, stride, pointer) \
  ( ((PFNGLSECONDARYCOLORPOINTERPROC) (proc)) (size, type, stride, pointer) )

/* void glWindowPos2d (GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glWindowPos2d (void);
#define   gdk_gl_glWindowPos2d(proc, x, y) \
  ( ((PFNGLWINDOWPOS2DPROC) (proc)) (x, y) )

/* void glWindowPos2dv (const GLdouble *) */
GdkGLProc gdk_gl_get_glWindowPos2dv (void);
#define   gdk_gl_glWindowPos2dv(proc, v) \
  ( ((PFNGLWINDOWPOS2DVPROC) (proc)) (v) )

/* void glWindowPos2f (GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glWindowPos2f (void);
#define   gdk_gl_glWindowPos2f(proc, x, y) \
  ( ((PFNGLWINDOWPOS2FPROC) (proc)) (x, y) )

/* void glWindowPos2fv (const GLfloat *) */
GdkGLProc gdk_gl_get_glWindowPos2fv (void);
#define   gdk_gl_glWindowPos2fv(proc, v) \
  ( ((PFNGLWINDOWPOS2FVPROC) (proc)) (v) )

/* void glWindowPos2i (GLint, GLint) */
GdkGLProc gdk_gl_get_glWindowPos2i (void);
#define   gdk_gl_glWindowPos2i(proc, x, y) \
  ( ((PFNGLWINDOWPOS2IPROC) (proc)) (x, y) )

/* void glWindowPos2iv (const GLint *) */
GdkGLProc gdk_gl_get_glWindowPos2iv (void);
#define   gdk_gl_glWindowPos2iv(proc, v) \
  ( ((PFNGLWINDOWPOS2IVPROC) (proc)) (v) )

/* void glWindowPos2s (GLshort, GLshort) */
GdkGLProc gdk_gl_get_glWindowPos2s (void);
#define   gdk_gl_glWindowPos2s(proc, x, y) \
  ( ((PFNGLWINDOWPOS2SPROC) (proc)) (x, y) )

/* void glWindowPos2sv (const GLshort *) */
GdkGLProc gdk_gl_get_glWindowPos2sv (void);
#define   gdk_gl_glWindowPos2sv(proc, v) \
  ( ((PFNGLWINDOWPOS2SVPROC) (proc)) (v) )

/* void glWindowPos3d (GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glWindowPos3d (void);
#define   gdk_gl_glWindowPos3d(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3DPROC) (proc)) (x, y, z) )

/* void glWindowPos3dv (const GLdouble *) */
GdkGLProc gdk_gl_get_glWindowPos3dv (void);
#define   gdk_gl_glWindowPos3dv(proc, v) \
  ( ((PFNGLWINDOWPOS3DVPROC) (proc)) (v) )

/* void glWindowPos3f (GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glWindowPos3f (void);
#define   gdk_gl_glWindowPos3f(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3FPROC) (proc)) (x, y, z) )

/* void glWindowPos3fv (const GLfloat *) */
GdkGLProc gdk_gl_get_glWindowPos3fv (void);
#define   gdk_gl_glWindowPos3fv(proc, v) \
  ( ((PFNGLWINDOWPOS3FVPROC) (proc)) (v) )

/* void glWindowPos3i (GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glWindowPos3i (void);
#define   gdk_gl_glWindowPos3i(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3IPROC) (proc)) (x, y, z) )

/* void glWindowPos3iv (const GLint *) */
GdkGLProc gdk_gl_get_glWindowPos3iv (void);
#define   gdk_gl_glWindowPos3iv(proc, v) \
  ( ((PFNGLWINDOWPOS3IVPROC) (proc)) (v) )

/* void glWindowPos3s (GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glWindowPos3s (void);
#define   gdk_gl_glWindowPos3s(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3SPROC) (proc)) (x, y, z) )

/* void glWindowPos3sv (const GLshort *) */
GdkGLProc gdk_gl_get_glWindowPos3sv (void);
#define   gdk_gl_glWindowPos3sv(proc, v) \
  ( ((PFNGLWINDOWPOS3SVPROC) (proc)) (v) )

/* 
 * GL_ARB_multitexture
 */

/* void glActiveTextureARB (GLenum) */
GdkGLProc gdk_gl_get_glActiveTextureARB (void);
#define   gdk_gl_glActiveTextureARB(proc, texture) \
  ( ((PFNGLACTIVETEXTUREARBPROC) (proc)) (texture) )

/* void glClientActiveTextureARB (GLenum) */
GdkGLProc gdk_gl_get_glClientActiveTextureARB (void);
#define   gdk_gl_glClientActiveTextureARB(proc, texture) \
  ( ((PFNGLCLIENTACTIVETEXTUREARBPROC) (proc)) (texture) )

/* void glMultiTexCoord1dARB (GLenum, GLdouble) */
GdkGLProc gdk_gl_get_glMultiTexCoord1dARB (void);
#define   gdk_gl_glMultiTexCoord1dARB(proc, target, s) \
  ( ((PFNGLMULTITEXCOORD1DARBPROC) (proc)) (target, s) )

/* void glMultiTexCoord1dvARB (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glMultiTexCoord1dvARB (void);
#define   gdk_gl_glMultiTexCoord1dvARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD1DVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord1fARB (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glMultiTexCoord1fARB (void);
#define   gdk_gl_glMultiTexCoord1fARB(proc, target, s) \
  ( ((PFNGLMULTITEXCOORD1FARBPROC) (proc)) (target, s) )

/* void glMultiTexCoord1fvARB (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMultiTexCoord1fvARB (void);
#define   gdk_gl_glMultiTexCoord1fvARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD1FVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord1iARB (GLenum, GLint) */
GdkGLProc gdk_gl_get_glMultiTexCoord1iARB (void);
#define   gdk_gl_glMultiTexCoord1iARB(proc, target, s) \
  ( ((PFNGLMULTITEXCOORD1IARBPROC) (proc)) (target, s) )

/* void glMultiTexCoord1ivARB (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMultiTexCoord1ivARB (void);
#define   gdk_gl_glMultiTexCoord1ivARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD1IVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord1sARB (GLenum, GLshort) */
GdkGLProc gdk_gl_get_glMultiTexCoord1sARB (void);
#define   gdk_gl_glMultiTexCoord1sARB(proc, target, s) \
  ( ((PFNGLMULTITEXCOORD1SARBPROC) (proc)) (target, s) )

/* void glMultiTexCoord1svARB (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glMultiTexCoord1svARB (void);
#define   gdk_gl_glMultiTexCoord1svARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD1SVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord2dARB (GLenum, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glMultiTexCoord2dARB (void);
#define   gdk_gl_glMultiTexCoord2dARB(proc, target, s, t) \
  ( ((PFNGLMULTITEXCOORD2DARBPROC) (proc)) (target, s, t) )

/* void glMultiTexCoord2dvARB (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glMultiTexCoord2dvARB (void);
#define   gdk_gl_glMultiTexCoord2dvARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD2DVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord2fARB (GLenum, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glMultiTexCoord2fARB (void);
#define   gdk_gl_glMultiTexCoord2fARB(proc, target, s, t) \
  ( ((PFNGLMULTITEXCOORD2FARBPROC) (proc)) (target, s, t) )

/* void glMultiTexCoord2fvARB (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMultiTexCoord2fvARB (void);
#define   gdk_gl_glMultiTexCoord2fvARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD2FVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord2iARB (GLenum, GLint, GLint) */
GdkGLProc gdk_gl_get_glMultiTexCoord2iARB (void);
#define   gdk_gl_glMultiTexCoord2iARB(proc, target, s, t) \
  ( ((PFNGLMULTITEXCOORD2IARBPROC) (proc)) (target, s, t) )

/* void glMultiTexCoord2ivARB (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMultiTexCoord2ivARB (void);
#define   gdk_gl_glMultiTexCoord2ivARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD2IVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord2sARB (GLenum, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glMultiTexCoord2sARB (void);
#define   gdk_gl_glMultiTexCoord2sARB(proc, target, s, t) \
  ( ((PFNGLMULTITEXCOORD2SARBPROC) (proc)) (target, s, t) )

/* void glMultiTexCoord2svARB (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glMultiTexCoord2svARB (void);
#define   gdk_gl_glMultiTexCoord2svARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD2SVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord3dARB (GLenum, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glMultiTexCoord3dARB (void);
#define   gdk_gl_glMultiTexCoord3dARB(proc, target, s, t, r) \
  ( ((PFNGLMULTITEXCOORD3DARBPROC) (proc)) (target, s, t, r) )

/* void glMultiTexCoord3dvARB (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glMultiTexCoord3dvARB (void);
#define   gdk_gl_glMultiTexCoord3dvARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD3DVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord3fARB (GLenum, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glMultiTexCoord3fARB (void);
#define   gdk_gl_glMultiTexCoord3fARB(proc, target, s, t, r) \
  ( ((PFNGLMULTITEXCOORD3FARBPROC) (proc)) (target, s, t, r) )

/* void glMultiTexCoord3fvARB (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMultiTexCoord3fvARB (void);
#define   gdk_gl_glMultiTexCoord3fvARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD3FVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord3iARB (GLenum, GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glMultiTexCoord3iARB (void);
#define   gdk_gl_glMultiTexCoord3iARB(proc, target, s, t, r) \
  ( ((PFNGLMULTITEXCOORD3IARBPROC) (proc)) (target, s, t, r) )

/* void glMultiTexCoord3ivARB (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMultiTexCoord3ivARB (void);
#define   gdk_gl_glMultiTexCoord3ivARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD3IVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord3sARB (GLenum, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glMultiTexCoord3sARB (void);
#define   gdk_gl_glMultiTexCoord3sARB(proc, target, s, t, r) \
  ( ((PFNGLMULTITEXCOORD3SARBPROC) (proc)) (target, s, t, r) )

/* void glMultiTexCoord3svARB (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glMultiTexCoord3svARB (void);
#define   gdk_gl_glMultiTexCoord3svARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD3SVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord4dARB (GLenum, GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glMultiTexCoord4dARB (void);
#define   gdk_gl_glMultiTexCoord4dARB(proc, target, s, t, r, q) \
  ( ((PFNGLMULTITEXCOORD4DARBPROC) (proc)) (target, s, t, r, q) )

/* void glMultiTexCoord4dvARB (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glMultiTexCoord4dvARB (void);
#define   gdk_gl_glMultiTexCoord4dvARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD4DVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord4fARB (GLenum, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glMultiTexCoord4fARB (void);
#define   gdk_gl_glMultiTexCoord4fARB(proc, target, s, t, r, q) \
  ( ((PFNGLMULTITEXCOORD4FARBPROC) (proc)) (target, s, t, r, q) )

/* void glMultiTexCoord4fvARB (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMultiTexCoord4fvARB (void);
#define   gdk_gl_glMultiTexCoord4fvARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD4FVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord4iARB (GLenum, GLint, GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glMultiTexCoord4iARB (void);
#define   gdk_gl_glMultiTexCoord4iARB(proc, target, s, t, r, q) \
  ( ((PFNGLMULTITEXCOORD4IARBPROC) (proc)) (target, s, t, r, q) )

/* void glMultiTexCoord4ivARB (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMultiTexCoord4ivARB (void);
#define   gdk_gl_glMultiTexCoord4ivARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD4IVARBPROC) (proc)) (target, v) )

/* void glMultiTexCoord4sARB (GLenum, GLshort, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glMultiTexCoord4sARB (void);
#define   gdk_gl_glMultiTexCoord4sARB(proc, target, s, t, r, q) \
  ( ((PFNGLMULTITEXCOORD4SARBPROC) (proc)) (target, s, t, r, q) )

/* void glMultiTexCoord4svARB (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glMultiTexCoord4svARB (void);
#define   gdk_gl_glMultiTexCoord4svARB(proc, target, v) \
  ( ((PFNGLMULTITEXCOORD4SVARBPROC) (proc)) (target, v) )

/* 
 * GL_ARB_transpose_matrix
 */

/* void glLoadTransposeMatrixfARB (const GLfloat *) */
GdkGLProc gdk_gl_get_glLoadTransposeMatrixfARB (void);
#define   gdk_gl_glLoadTransposeMatrixfARB(proc, m) \
  ( ((PFNGLLOADTRANSPOSEMATRIXFARBPROC) (proc)) (m) )

/* void glLoadTransposeMatrixdARB (const GLdouble *) */
GdkGLProc gdk_gl_get_glLoadTransposeMatrixdARB (void);
#define   gdk_gl_glLoadTransposeMatrixdARB(proc, m) \
  ( ((PFNGLLOADTRANSPOSEMATRIXDARBPROC) (proc)) (m) )

/* void glMultTransposeMatrixfARB (const GLfloat *) */
GdkGLProc gdk_gl_get_glMultTransposeMatrixfARB (void);
#define   gdk_gl_glMultTransposeMatrixfARB(proc, m) \
  ( ((PFNGLMULTTRANSPOSEMATRIXFARBPROC) (proc)) (m) )

/* void glMultTransposeMatrixdARB (const GLdouble *) */
GdkGLProc gdk_gl_get_glMultTransposeMatrixdARB (void);
#define   gdk_gl_glMultTransposeMatrixdARB(proc, m) \
  ( ((PFNGLMULTTRANSPOSEMATRIXDARBPROC) (proc)) (m) )

/* 
 * GL_ARB_multisample
 */

/* void glSampleCoverageARB (GLclampf, GLboolean) */
GdkGLProc gdk_gl_get_glSampleCoverageARB (void);
#define   gdk_gl_glSampleCoverageARB(proc, value, invert) \
  ( ((PFNGLSAMPLECOVERAGEARBPROC) (proc)) (value, invert) )

/* 
 * GL_ARB_texture_compression
 */

/* void glCompressedTexImage3DARB (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexImage3DARB (void);
#define   gdk_gl_glCompressedTexImage3DARB(proc, target, level, internalformat, width, height, depth, border, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXIMAGE3DARBPROC) (proc)) (target, level, internalformat, width, height, depth, border, imageSize, data) )

/* void glCompressedTexImage2DARB (GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexImage2DARB (void);
#define   gdk_gl_glCompressedTexImage2DARB(proc, target, level, internalformat, width, height, border, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXIMAGE2DARBPROC) (proc)) (target, level, internalformat, width, height, border, imageSize, data) )

/* void glCompressedTexImage1DARB (GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexImage1DARB (void);
#define   gdk_gl_glCompressedTexImage1DARB(proc, target, level, internalformat, width, border, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXIMAGE1DARBPROC) (proc)) (target, level, internalformat, width, border, imageSize, data) )

/* void glCompressedTexSubImage3DARB (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexSubImage3DARB (void);
#define   gdk_gl_glCompressedTexSubImage3DARB(proc, target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC) (proc)) (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data) )

/* void glCompressedTexSubImage2DARB (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexSubImage2DARB (void);
#define   gdk_gl_glCompressedTexSubImage2DARB(proc, target, level, xoffset, yoffset, width, height, format, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC) (proc)) (target, level, xoffset, yoffset, width, height, format, imageSize, data) )

/* void glCompressedTexSubImage1DARB (GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glCompressedTexSubImage1DARB (void);
#define   gdk_gl_glCompressedTexSubImage1DARB(proc, target, level, xoffset, width, format, imageSize, data) \
  ( ((PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC) (proc)) (target, level, xoffset, width, format, imageSize, data) )

/* void glGetCompressedTexImageARB (GLenum, GLint, void *) */
GdkGLProc gdk_gl_get_glGetCompressedTexImageARB (void);
#define   gdk_gl_glGetCompressedTexImageARB(proc, target, level, img) \
  ( ((PFNGLGETCOMPRESSEDTEXIMAGEARBPROC) (proc)) (target, level, img) )

/* 
 * GL_ARB_point_parameters
 */

/* void glPointParameterfARB (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glPointParameterfARB (void);
#define   gdk_gl_glPointParameterfARB(proc, pname, param) \
  ( ((PFNGLPOINTPARAMETERFARBPROC) (proc)) (pname, param) )

/* void glPointParameterfvARB (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glPointParameterfvARB (void);
#define   gdk_gl_glPointParameterfvARB(proc, pname, params) \
  ( ((PFNGLPOINTPARAMETERFVARBPROC) (proc)) (pname, params) )

/* 
 * GL_ARB_vertex_blend
 */

/* void glWeightbvARB (GLint, const GLbyte *) */
GdkGLProc gdk_gl_get_glWeightbvARB (void);
#define   gdk_gl_glWeightbvARB(proc, size, weights) \
  ( ((PFNGLWEIGHTBVARBPROC) (proc)) (size, weights) )

/* void glWeightsvARB (GLint, const GLshort *) */
GdkGLProc gdk_gl_get_glWeightsvARB (void);
#define   gdk_gl_glWeightsvARB(proc, size, weights) \
  ( ((PFNGLWEIGHTSVARBPROC) (proc)) (size, weights) )

/* void glWeightivARB (GLint, const GLint *) */
GdkGLProc gdk_gl_get_glWeightivARB (void);
#define   gdk_gl_glWeightivARB(proc, size, weights) \
  ( ((PFNGLWEIGHTIVARBPROC) (proc)) (size, weights) )

/* void glWeightfvARB (GLint, const GLfloat *) */
GdkGLProc gdk_gl_get_glWeightfvARB (void);
#define   gdk_gl_glWeightfvARB(proc, size, weights) \
  ( ((PFNGLWEIGHTFVARBPROC) (proc)) (size, weights) )

/* void glWeightdvARB (GLint, const GLdouble *) */
GdkGLProc gdk_gl_get_glWeightdvARB (void);
#define   gdk_gl_glWeightdvARB(proc, size, weights) \
  ( ((PFNGLWEIGHTDVARBPROC) (proc)) (size, weights) )

/* void glWeightubvARB (GLint, const GLubyte *) */
GdkGLProc gdk_gl_get_glWeightubvARB (void);
#define   gdk_gl_glWeightubvARB(proc, size, weights) \
  ( ((PFNGLWEIGHTUBVARBPROC) (proc)) (size, weights) )

/* void glWeightusvARB (GLint, const GLushort *) */
GdkGLProc gdk_gl_get_glWeightusvARB (void);
#define   gdk_gl_glWeightusvARB(proc, size, weights) \
  ( ((PFNGLWEIGHTUSVARBPROC) (proc)) (size, weights) )

/* void glWeightuivARB (GLint, const GLuint *) */
GdkGLProc gdk_gl_get_glWeightuivARB (void);
#define   gdk_gl_glWeightuivARB(proc, size, weights) \
  ( ((PFNGLWEIGHTUIVARBPROC) (proc)) (size, weights) )

/* void glWeightPointerARB (GLint, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glWeightPointerARB (void);
#define   gdk_gl_glWeightPointerARB(proc, size, type, stride, pointer) \
  ( ((PFNGLWEIGHTPOINTERARBPROC) (proc)) (size, type, stride, pointer) )

/* void glVertexBlendARB (GLint) */
GdkGLProc gdk_gl_get_glVertexBlendARB (void);
#define   gdk_gl_glVertexBlendARB(proc, count) \
  ( ((PFNGLVERTEXBLENDARBPROC) (proc)) (count) )

/* 
 * GL_ARB_matrix_palette
 */

/* void glCurrentPaletteMatrixARB (GLint) */
GdkGLProc gdk_gl_get_glCurrentPaletteMatrixARB (void);
#define   gdk_gl_glCurrentPaletteMatrixARB(proc, index) \
  ( ((PFNGLCURRENTPALETTEMATRIXARBPROC) (proc)) (index) )

/* void glMatrixIndexubvARB (GLint, const GLubyte *) */
GdkGLProc gdk_gl_get_glMatrixIndexubvARB (void);
#define   gdk_gl_glMatrixIndexubvARB(proc, size, indices) \
  ( ((PFNGLMATRIXINDEXUBVARBPROC) (proc)) (size, indices) )

/* void glMatrixIndexusvARB (GLint, const GLushort *) */
GdkGLProc gdk_gl_get_glMatrixIndexusvARB (void);
#define   gdk_gl_glMatrixIndexusvARB(proc, size, indices) \
  ( ((PFNGLMATRIXINDEXUSVARBPROC) (proc)) (size, indices) )

/* void glMatrixIndexuivARB (GLint, const GLuint *) */
GdkGLProc gdk_gl_get_glMatrixIndexuivARB (void);
#define   gdk_gl_glMatrixIndexuivARB(proc, size, indices) \
  ( ((PFNGLMATRIXINDEXUIVARBPROC) (proc)) (size, indices) )

/* void glMatrixIndexPointerARB (GLint, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glMatrixIndexPointerARB (void);
#define   gdk_gl_glMatrixIndexPointerARB(proc, size, type, stride, pointer) \
  ( ((PFNGLMATRIXINDEXPOINTERARBPROC) (proc)) (size, type, stride, pointer) )

/* 
 * GL_ARB_window_pos
 */

/* void glWindowPos2dARB (GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glWindowPos2dARB (void);
#define   gdk_gl_glWindowPos2dARB(proc, x, y) \
  ( ((PFNGLWINDOWPOS2DARBPROC) (proc)) (x, y) )

/* void glWindowPos2dvARB (const GLdouble *) */
GdkGLProc gdk_gl_get_glWindowPos2dvARB (void);
#define   gdk_gl_glWindowPos2dvARB(proc, v) \
  ( ((PFNGLWINDOWPOS2DVARBPROC) (proc)) (v) )

/* void glWindowPos2fARB (GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glWindowPos2fARB (void);
#define   gdk_gl_glWindowPos2fARB(proc, x, y) \
  ( ((PFNGLWINDOWPOS2FARBPROC) (proc)) (x, y) )

/* void glWindowPos2fvARB (const GLfloat *) */
GdkGLProc gdk_gl_get_glWindowPos2fvARB (void);
#define   gdk_gl_glWindowPos2fvARB(proc, v) \
  ( ((PFNGLWINDOWPOS2FVARBPROC) (proc)) (v) )

/* void glWindowPos2iARB (GLint, GLint) */
GdkGLProc gdk_gl_get_glWindowPos2iARB (void);
#define   gdk_gl_glWindowPos2iARB(proc, x, y) \
  ( ((PFNGLWINDOWPOS2IARBPROC) (proc)) (x, y) )

/* void glWindowPos2ivARB (const GLint *) */
GdkGLProc gdk_gl_get_glWindowPos2ivARB (void);
#define   gdk_gl_glWindowPos2ivARB(proc, v) \
  ( ((PFNGLWINDOWPOS2IVARBPROC) (proc)) (v) )

/* void glWindowPos2sARB (GLshort, GLshort) */
GdkGLProc gdk_gl_get_glWindowPos2sARB (void);
#define   gdk_gl_glWindowPos2sARB(proc, x, y) \
  ( ((PFNGLWINDOWPOS2SARBPROC) (proc)) (x, y) )

/* void glWindowPos2svARB (const GLshort *) */
GdkGLProc gdk_gl_get_glWindowPos2svARB (void);
#define   gdk_gl_glWindowPos2svARB(proc, v) \
  ( ((PFNGLWINDOWPOS2SVARBPROC) (proc)) (v) )

/* void glWindowPos3dARB (GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glWindowPos3dARB (void);
#define   gdk_gl_glWindowPos3dARB(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3DARBPROC) (proc)) (x, y, z) )

/* void glWindowPos3dvARB (const GLdouble *) */
GdkGLProc gdk_gl_get_glWindowPos3dvARB (void);
#define   gdk_gl_glWindowPos3dvARB(proc, v) \
  ( ((PFNGLWINDOWPOS3DVARBPROC) (proc)) (v) )

/* void glWindowPos3fARB (GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glWindowPos3fARB (void);
#define   gdk_gl_glWindowPos3fARB(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3FARBPROC) (proc)) (x, y, z) )

/* void glWindowPos3fvARB (const GLfloat *) */
GdkGLProc gdk_gl_get_glWindowPos3fvARB (void);
#define   gdk_gl_glWindowPos3fvARB(proc, v) \
  ( ((PFNGLWINDOWPOS3FVARBPROC) (proc)) (v) )

/* void glWindowPos3iARB (GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glWindowPos3iARB (void);
#define   gdk_gl_glWindowPos3iARB(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3IARBPROC) (proc)) (x, y, z) )

/* void glWindowPos3ivARB (const GLint *) */
GdkGLProc gdk_gl_get_glWindowPos3ivARB (void);
#define   gdk_gl_glWindowPos3ivARB(proc, v) \
  ( ((PFNGLWINDOWPOS3IVARBPROC) (proc)) (v) )

/* void glWindowPos3sARB (GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glWindowPos3sARB (void);
#define   gdk_gl_glWindowPos3sARB(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3SARBPROC) (proc)) (x, y, z) )

/* void glWindowPos3svARB (const GLshort *) */
GdkGLProc gdk_gl_get_glWindowPos3svARB (void);
#define   gdk_gl_glWindowPos3svARB(proc, v) \
  ( ((PFNGLWINDOWPOS3SVARBPROC) (proc)) (v) )

/* 
 * GL_ARB_vertex_program
 */

/* void glVertexAttrib1dARB (GLuint, GLdouble) */
GdkGLProc gdk_gl_get_glVertexAttrib1dARB (void);
#define   gdk_gl_glVertexAttrib1dARB(proc, index, x) \
  ( ((PFNGLVERTEXATTRIB1DARBPROC) (proc)) (index, x) )

/* void glVertexAttrib1dvARB (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttrib1dvARB (void);
#define   gdk_gl_glVertexAttrib1dvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB1DVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib1fARB (GLuint, GLfloat) */
GdkGLProc gdk_gl_get_glVertexAttrib1fARB (void);
#define   gdk_gl_glVertexAttrib1fARB(proc, index, x) \
  ( ((PFNGLVERTEXATTRIB1FARBPROC) (proc)) (index, x) )

/* void glVertexAttrib1fvARB (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttrib1fvARB (void);
#define   gdk_gl_glVertexAttrib1fvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB1FVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib1sARB (GLuint, GLshort) */
GdkGLProc gdk_gl_get_glVertexAttrib1sARB (void);
#define   gdk_gl_glVertexAttrib1sARB(proc, index, x) \
  ( ((PFNGLVERTEXATTRIB1SARBPROC) (proc)) (index, x) )

/* void glVertexAttrib1svARB (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib1svARB (void);
#define   gdk_gl_glVertexAttrib1svARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB1SVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib2dARB (GLuint, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexAttrib2dARB (void);
#define   gdk_gl_glVertexAttrib2dARB(proc, index, x, y) \
  ( ((PFNGLVERTEXATTRIB2DARBPROC) (proc)) (index, x, y) )

/* void glVertexAttrib2dvARB (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttrib2dvARB (void);
#define   gdk_gl_glVertexAttrib2dvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB2DVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib2fARB (GLuint, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexAttrib2fARB (void);
#define   gdk_gl_glVertexAttrib2fARB(proc, index, x, y) \
  ( ((PFNGLVERTEXATTRIB2FARBPROC) (proc)) (index, x, y) )

/* void glVertexAttrib2fvARB (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttrib2fvARB (void);
#define   gdk_gl_glVertexAttrib2fvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB2FVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib2sARB (GLuint, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexAttrib2sARB (void);
#define   gdk_gl_glVertexAttrib2sARB(proc, index, x, y) \
  ( ((PFNGLVERTEXATTRIB2SARBPROC) (proc)) (index, x, y) )

/* void glVertexAttrib2svARB (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib2svARB (void);
#define   gdk_gl_glVertexAttrib2svARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB2SVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib3dARB (GLuint, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexAttrib3dARB (void);
#define   gdk_gl_glVertexAttrib3dARB(proc, index, x, y, z) \
  ( ((PFNGLVERTEXATTRIB3DARBPROC) (proc)) (index, x, y, z) )

/* void glVertexAttrib3dvARB (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttrib3dvARB (void);
#define   gdk_gl_glVertexAttrib3dvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB3DVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib3fARB (GLuint, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexAttrib3fARB (void);
#define   gdk_gl_glVertexAttrib3fARB(proc, index, x, y, z) \
  ( ((PFNGLVERTEXATTRIB3FARBPROC) (proc)) (index, x, y, z) )

/* void glVertexAttrib3fvARB (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttrib3fvARB (void);
#define   gdk_gl_glVertexAttrib3fvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB3FVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib3sARB (GLuint, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexAttrib3sARB (void);
#define   gdk_gl_glVertexAttrib3sARB(proc, index, x, y, z) \
  ( ((PFNGLVERTEXATTRIB3SARBPROC) (proc)) (index, x, y, z) )

/* void glVertexAttrib3svARB (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib3svARB (void);
#define   gdk_gl_glVertexAttrib3svARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB3SVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4NbvARB (GLuint, const GLbyte *) */
GdkGLProc gdk_gl_get_glVertexAttrib4NbvARB (void);
#define   gdk_gl_glVertexAttrib4NbvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4NBVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4NivARB (GLuint, const GLint *) */
GdkGLProc gdk_gl_get_glVertexAttrib4NivARB (void);
#define   gdk_gl_glVertexAttrib4NivARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4NIVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4NsvARB (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib4NsvARB (void);
#define   gdk_gl_glVertexAttrib4NsvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4NSVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4NubARB (GLuint, GLubyte, GLubyte, GLubyte, GLubyte) */
GdkGLProc gdk_gl_get_glVertexAttrib4NubARB (void);
#define   gdk_gl_glVertexAttrib4NubARB(proc, index, x, y, z, w) \
  ( ((PFNGLVERTEXATTRIB4NUBARBPROC) (proc)) (index, x, y, z, w) )

/* void glVertexAttrib4NubvARB (GLuint, const GLubyte *) */
GdkGLProc gdk_gl_get_glVertexAttrib4NubvARB (void);
#define   gdk_gl_glVertexAttrib4NubvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4NUBVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4NuivARB (GLuint, const GLuint *) */
GdkGLProc gdk_gl_get_glVertexAttrib4NuivARB (void);
#define   gdk_gl_glVertexAttrib4NuivARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4NUIVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4NusvARB (GLuint, const GLushort *) */
GdkGLProc gdk_gl_get_glVertexAttrib4NusvARB (void);
#define   gdk_gl_glVertexAttrib4NusvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4NUSVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4bvARB (GLuint, const GLbyte *) */
GdkGLProc gdk_gl_get_glVertexAttrib4bvARB (void);
#define   gdk_gl_glVertexAttrib4bvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4BVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4dARB (GLuint, GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexAttrib4dARB (void);
#define   gdk_gl_glVertexAttrib4dARB(proc, index, x, y, z, w) \
  ( ((PFNGLVERTEXATTRIB4DARBPROC) (proc)) (index, x, y, z, w) )

/* void glVertexAttrib4dvARB (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttrib4dvARB (void);
#define   gdk_gl_glVertexAttrib4dvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4DVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4fARB (GLuint, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexAttrib4fARB (void);
#define   gdk_gl_glVertexAttrib4fARB(proc, index, x, y, z, w) \
  ( ((PFNGLVERTEXATTRIB4FARBPROC) (proc)) (index, x, y, z, w) )

/* void glVertexAttrib4fvARB (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttrib4fvARB (void);
#define   gdk_gl_glVertexAttrib4fvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4FVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4ivARB (GLuint, const GLint *) */
GdkGLProc gdk_gl_get_glVertexAttrib4ivARB (void);
#define   gdk_gl_glVertexAttrib4ivARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4IVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4sARB (GLuint, GLshort, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexAttrib4sARB (void);
#define   gdk_gl_glVertexAttrib4sARB(proc, index, x, y, z, w) \
  ( ((PFNGLVERTEXATTRIB4SARBPROC) (proc)) (index, x, y, z, w) )

/* void glVertexAttrib4svARB (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib4svARB (void);
#define   gdk_gl_glVertexAttrib4svARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4SVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4ubvARB (GLuint, const GLubyte *) */
GdkGLProc gdk_gl_get_glVertexAttrib4ubvARB (void);
#define   gdk_gl_glVertexAttrib4ubvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4UBVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4uivARB (GLuint, const GLuint *) */
GdkGLProc gdk_gl_get_glVertexAttrib4uivARB (void);
#define   gdk_gl_glVertexAttrib4uivARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4UIVARBPROC) (proc)) (index, v) )

/* void glVertexAttrib4usvARB (GLuint, const GLushort *) */
GdkGLProc gdk_gl_get_glVertexAttrib4usvARB (void);
#define   gdk_gl_glVertexAttrib4usvARB(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4USVARBPROC) (proc)) (index, v) )

/* void glVertexAttribPointerARB (GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glVertexAttribPointerARB (void);
#define   gdk_gl_glVertexAttribPointerARB(proc, index, size, type, normalized, stride, pointer) \
  ( ((PFNGLVERTEXATTRIBPOINTERARBPROC) (proc)) (index, size, type, normalized, stride, pointer) )

/* void glEnableVertexAttribArrayARB (GLuint) */
GdkGLProc gdk_gl_get_glEnableVertexAttribArrayARB (void);
#define   gdk_gl_glEnableVertexAttribArrayARB(proc, index) \
  ( ((PFNGLENABLEVERTEXATTRIBARRAYARBPROC) (proc)) (index) )

/* void glDisableVertexAttribArrayARB (GLuint) */
GdkGLProc gdk_gl_get_glDisableVertexAttribArrayARB (void);
#define   gdk_gl_glDisableVertexAttribArrayARB(proc, index) \
  ( ((PFNGLDISABLEVERTEXATTRIBARRAYARBPROC) (proc)) (index) )

/* void glProgramStringARB (GLenum, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glProgramStringARB (void);
#define   gdk_gl_glProgramStringARB(proc, target, format, len, string) \
  ( ((PFNGLPROGRAMSTRINGARBPROC) (proc)) (target, format, len, string) )

/* void glBindProgramARB (GLenum, GLuint) */
GdkGLProc gdk_gl_get_glBindProgramARB (void);
#define   gdk_gl_glBindProgramARB(proc, target, program) \
  ( ((PFNGLBINDPROGRAMARBPROC) (proc)) (target, program) )

/* void glDeleteProgramsARB (GLsizei, const GLuint *) */
GdkGLProc gdk_gl_get_glDeleteProgramsARB (void);
#define   gdk_gl_glDeleteProgramsARB(proc, n, programs) \
  ( ((PFNGLDELETEPROGRAMSARBPROC) (proc)) (n, programs) )

/* void glGenProgramsARB (GLsizei, GLuint *) */
GdkGLProc gdk_gl_get_glGenProgramsARB (void);
#define   gdk_gl_glGenProgramsARB(proc, n, programs) \
  ( ((PFNGLGENPROGRAMSARBPROC) (proc)) (n, programs) )

/* void glProgramEnvParameter4dARB (GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glProgramEnvParameter4dARB (void);
#define   gdk_gl_glProgramEnvParameter4dARB(proc, target, index, x, y, z, w) \
  ( ((PFNGLPROGRAMENVPARAMETER4DARBPROC) (proc)) (target, index, x, y, z, w) )

/* void glProgramEnvParameter4dvARB (GLenum, GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glProgramEnvParameter4dvARB (void);
#define   gdk_gl_glProgramEnvParameter4dvARB(proc, target, index, params) \
  ( ((PFNGLPROGRAMENVPARAMETER4DVARBPROC) (proc)) (target, index, params) )

/* void glProgramEnvParameter4fARB (GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glProgramEnvParameter4fARB (void);
#define   gdk_gl_glProgramEnvParameter4fARB(proc, target, index, x, y, z, w) \
  ( ((PFNGLPROGRAMENVPARAMETER4FARBPROC) (proc)) (target, index, x, y, z, w) )

/* void glProgramEnvParameter4fvARB (GLenum, GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glProgramEnvParameter4fvARB (void);
#define   gdk_gl_glProgramEnvParameter4fvARB(proc, target, index, params) \
  ( ((PFNGLPROGRAMENVPARAMETER4FVARBPROC) (proc)) (target, index, params) )

/* void glProgramLocalParameter4dARB (GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glProgramLocalParameter4dARB (void);
#define   gdk_gl_glProgramLocalParameter4dARB(proc, target, index, x, y, z, w) \
  ( ((PFNGLPROGRAMLOCALPARAMETER4DARBPROC) (proc)) (target, index, x, y, z, w) )

/* void glProgramLocalParameter4dvARB (GLenum, GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glProgramLocalParameter4dvARB (void);
#define   gdk_gl_glProgramLocalParameter4dvARB(proc, target, index, params) \
  ( ((PFNGLPROGRAMLOCALPARAMETER4DVARBPROC) (proc)) (target, index, params) )

/* void glProgramLocalParameter4fARB (GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glProgramLocalParameter4fARB (void);
#define   gdk_gl_glProgramLocalParameter4fARB(proc, target, index, x, y, z, w) \
  ( ((PFNGLPROGRAMLOCALPARAMETER4FARBPROC) (proc)) (target, index, x, y, z, w) )

/* void glProgramLocalParameter4fvARB (GLenum, GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glProgramLocalParameter4fvARB (void);
#define   gdk_gl_glProgramLocalParameter4fvARB(proc, target, index, params) \
  ( ((PFNGLPROGRAMLOCALPARAMETER4FVARBPROC) (proc)) (target, index, params) )

/* void glGetProgramEnvParameterdvARB (GLenum, GLuint, GLdouble *) */
GdkGLProc gdk_gl_get_glGetProgramEnvParameterdvARB (void);
#define   gdk_gl_glGetProgramEnvParameterdvARB(proc, target, index, params) \
  ( ((PFNGLGETPROGRAMENVPARAMETERDVARBPROC) (proc)) (target, index, params) )

/* void glGetProgramEnvParameterfvARB (GLenum, GLuint, GLfloat *) */
GdkGLProc gdk_gl_get_glGetProgramEnvParameterfvARB (void);
#define   gdk_gl_glGetProgramEnvParameterfvARB(proc, target, index, params) \
  ( ((PFNGLGETPROGRAMENVPARAMETERFVARBPROC) (proc)) (target, index, params) )

/* void glGetProgramLocalParameterdvARB (GLenum, GLuint, GLdouble *) */
GdkGLProc gdk_gl_get_glGetProgramLocalParameterdvARB (void);
#define   gdk_gl_glGetProgramLocalParameterdvARB(proc, target, index, params) \
  ( ((PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC) (proc)) (target, index, params) )

/* void glGetProgramLocalParameterfvARB (GLenum, GLuint, GLfloat *) */
GdkGLProc gdk_gl_get_glGetProgramLocalParameterfvARB (void);
#define   gdk_gl_glGetProgramLocalParameterfvARB(proc, target, index, params) \
  ( ((PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC) (proc)) (target, index, params) )

/* void glGetProgramivARB (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetProgramivARB (void);
#define   gdk_gl_glGetProgramivARB(proc, target, pname, params) \
  ( ((PFNGLGETPROGRAMIVARBPROC) (proc)) (target, pname, params) )

/* void glGetProgramStringARB (GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetProgramStringARB (void);
#define   gdk_gl_glGetProgramStringARB(proc, target, pname, string) \
  ( ((PFNGLGETPROGRAMSTRINGARBPROC) (proc)) (target, pname, string) )

/* void glGetVertexAttribdvARB (GLuint, GLenum, GLdouble *) */
GdkGLProc gdk_gl_get_glGetVertexAttribdvARB (void);
#define   gdk_gl_glGetVertexAttribdvARB(proc, index, pname, params) \
  ( ((PFNGLGETVERTEXATTRIBDVARBPROC) (proc)) (index, pname, params) )

/* void glGetVertexAttribfvARB (GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetVertexAttribfvARB (void);
#define   gdk_gl_glGetVertexAttribfvARB(proc, index, pname, params) \
  ( ((PFNGLGETVERTEXATTRIBFVARBPROC) (proc)) (index, pname, params) )

/* void glGetVertexAttribivARB (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetVertexAttribivARB (void);
#define   gdk_gl_glGetVertexAttribivARB(proc, index, pname, params) \
  ( ((PFNGLGETVERTEXATTRIBIVARBPROC) (proc)) (index, pname, params) )

/* void glGetVertexAttribPointervARB (GLuint, GLenum, GLvoid* *) */
GdkGLProc gdk_gl_get_glGetVertexAttribPointervARB (void);
#define   gdk_gl_glGetVertexAttribPointervARB(proc, index, pname, pointer) \
  ( ((PFNGLGETVERTEXATTRIBPOINTERVARBPROC) (proc)) (index, pname, pointer) )

/* GLboolean glIsProgramARB (GLuint) */
GdkGLProc gdk_gl_get_glIsProgramARB (void);
#define   gdk_gl_glIsProgramARB(proc, program) \
  ( ((PFNGLISPROGRAMARBPROC) (proc)) (program) )

/* 
 * GL_EXT_blend_color
 */

/* void glBlendColorEXT (GLclampf, GLclampf, GLclampf, GLclampf) */
GdkGLProc gdk_gl_get_glBlendColorEXT (void);
#define   gdk_gl_glBlendColorEXT(proc, red, green, blue, alpha) \
  ( ((PFNGLBLENDCOLOREXTPROC) (proc)) (red, green, blue, alpha) )

/* 
 * GL_EXT_polygon_offset
 */

/* void glPolygonOffsetEXT (GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glPolygonOffsetEXT (void);
#define   gdk_gl_glPolygonOffsetEXT(proc, factor, bias) \
  ( ((PFNGLPOLYGONOFFSETEXTPROC) (proc)) (factor, bias) )

/* 
 * GL_EXT_texture3D
 */

/* void glTexImage3DEXT (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexImage3DEXT (void);
#define   gdk_gl_glTexImage3DEXT(proc, target, level, internalformat, width, height, depth, border, format, type, pixels) \
  ( ((PFNGLTEXIMAGE3DEXTPROC) (proc)) (target, level, internalformat, width, height, depth, border, format, type, pixels) )

/* void glTexSubImage3DEXT (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexSubImage3DEXT (void);
#define   gdk_gl_glTexSubImage3DEXT(proc, target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) \
  ( ((PFNGLTEXSUBIMAGE3DEXTPROC) (proc)) (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels) )

/* 
 * GL_SGIS_texture_filter4
 */

/* void glGetTexFilterFuncSGIS (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetTexFilterFuncSGIS (void);
#define   gdk_gl_glGetTexFilterFuncSGIS(proc, target, filter, weights) \
  ( ((PFNGLGETTEXFILTERFUNCSGISPROC) (proc)) (target, filter, weights) )

/* void glTexFilterFuncSGIS (GLenum, GLenum, GLsizei, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexFilterFuncSGIS (void);
#define   gdk_gl_glTexFilterFuncSGIS(proc, target, filter, n, weights) \
  ( ((PFNGLTEXFILTERFUNCSGISPROC) (proc)) (target, filter, n, weights) )

/* 
 * GL_EXT_subtexture
 */

/* void glTexSubImage1DEXT (GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexSubImage1DEXT (void);
#define   gdk_gl_glTexSubImage1DEXT(proc, target, level, xoffset, width, format, type, pixels) \
  ( ((PFNGLTEXSUBIMAGE1DEXTPROC) (proc)) (target, level, xoffset, width, format, type, pixels) )

/* void glTexSubImage2DEXT (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexSubImage2DEXT (void);
#define   gdk_gl_glTexSubImage2DEXT(proc, target, level, xoffset, yoffset, width, height, format, type, pixels) \
  ( ((PFNGLTEXSUBIMAGE2DEXTPROC) (proc)) (target, level, xoffset, yoffset, width, height, format, type, pixels) )

/* 
 * GL_EXT_copy_texture
 */

/* void glCopyTexImage1DEXT (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint) */
GdkGLProc gdk_gl_get_glCopyTexImage1DEXT (void);
#define   gdk_gl_glCopyTexImage1DEXT(proc, target, level, internalformat, x, y, width, border) \
  ( ((PFNGLCOPYTEXIMAGE1DEXTPROC) (proc)) (target, level, internalformat, x, y, width, border) )

/* void glCopyTexImage2DEXT (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint) */
GdkGLProc gdk_gl_get_glCopyTexImage2DEXT (void);
#define   gdk_gl_glCopyTexImage2DEXT(proc, target, level, internalformat, x, y, width, height, border) \
  ( ((PFNGLCOPYTEXIMAGE2DEXTPROC) (proc)) (target, level, internalformat, x, y, width, height, border) )

/* void glCopyTexSubImage1DEXT (GLenum, GLint, GLint, GLint, GLint, GLsizei) */
GdkGLProc gdk_gl_get_glCopyTexSubImage1DEXT (void);
#define   gdk_gl_glCopyTexSubImage1DEXT(proc, target, level, xoffset, x, y, width) \
  ( ((PFNGLCOPYTEXSUBIMAGE1DEXTPROC) (proc)) (target, level, xoffset, x, y, width) )

/* void glCopyTexSubImage2DEXT (GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) */
GdkGLProc gdk_gl_get_glCopyTexSubImage2DEXT (void);
#define   gdk_gl_glCopyTexSubImage2DEXT(proc, target, level, xoffset, yoffset, x, y, width, height) \
  ( ((PFNGLCOPYTEXSUBIMAGE2DEXTPROC) (proc)) (target, level, xoffset, yoffset, x, y, width, height) )

/* void glCopyTexSubImage3DEXT (GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) */
GdkGLProc gdk_gl_get_glCopyTexSubImage3DEXT (void);
#define   gdk_gl_glCopyTexSubImage3DEXT(proc, target, level, xoffset, yoffset, zoffset, x, y, width, height) \
  ( ((PFNGLCOPYTEXSUBIMAGE3DEXTPROC) (proc)) (target, level, xoffset, yoffset, zoffset, x, y, width, height) )

/* 
 * GL_EXT_histogram
 */

/* void glGetHistogramEXT (GLenum, GLboolean, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetHistogramEXT (void);
#define   gdk_gl_glGetHistogramEXT(proc, target, reset, format, type, values) \
  ( ((PFNGLGETHISTOGRAMEXTPROC) (proc)) (target, reset, format, type, values) )

/* void glGetHistogramParameterfvEXT (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetHistogramParameterfvEXT (void);
#define   gdk_gl_glGetHistogramParameterfvEXT(proc, target, pname, params) \
  ( ((PFNGLGETHISTOGRAMPARAMETERFVEXTPROC) (proc)) (target, pname, params) )

/* void glGetHistogramParameterivEXT (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetHistogramParameterivEXT (void);
#define   gdk_gl_glGetHistogramParameterivEXT(proc, target, pname, params) \
  ( ((PFNGLGETHISTOGRAMPARAMETERIVEXTPROC) (proc)) (target, pname, params) )

/* void glGetMinmaxEXT (GLenum, GLboolean, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetMinmaxEXT (void);
#define   gdk_gl_glGetMinmaxEXT(proc, target, reset, format, type, values) \
  ( ((PFNGLGETMINMAXEXTPROC) (proc)) (target, reset, format, type, values) )

/* void glGetMinmaxParameterfvEXT (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetMinmaxParameterfvEXT (void);
#define   gdk_gl_glGetMinmaxParameterfvEXT(proc, target, pname, params) \
  ( ((PFNGLGETMINMAXPARAMETERFVEXTPROC) (proc)) (target, pname, params) )

/* void glGetMinmaxParameterivEXT (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetMinmaxParameterivEXT (void);
#define   gdk_gl_glGetMinmaxParameterivEXT(proc, target, pname, params) \
  ( ((PFNGLGETMINMAXPARAMETERIVEXTPROC) (proc)) (target, pname, params) )

/* void glHistogramEXT (GLenum, GLsizei, GLenum, GLboolean) */
GdkGLProc gdk_gl_get_glHistogramEXT (void);
#define   gdk_gl_glHistogramEXT(proc, target, width, internalformat, sink) \
  ( ((PFNGLHISTOGRAMEXTPROC) (proc)) (target, width, internalformat, sink) )

/* void glMinmaxEXT (GLenum, GLenum, GLboolean) */
GdkGLProc gdk_gl_get_glMinmaxEXT (void);
#define   gdk_gl_glMinmaxEXT(proc, target, internalformat, sink) \
  ( ((PFNGLMINMAXEXTPROC) (proc)) (target, internalformat, sink) )

/* void glResetHistogramEXT (GLenum) */
GdkGLProc gdk_gl_get_glResetHistogramEXT (void);
#define   gdk_gl_glResetHistogramEXT(proc, target) \
  ( ((PFNGLRESETHISTOGRAMEXTPROC) (proc)) (target) )

/* void glResetMinmaxEXT (GLenum) */
GdkGLProc gdk_gl_get_glResetMinmaxEXT (void);
#define   gdk_gl_glResetMinmaxEXT(proc, target) \
  ( ((PFNGLRESETMINMAXEXTPROC) (proc)) (target) )

/* 
 * GL_EXT_convolution
 */

/* void glConvolutionFilter1DEXT (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glConvolutionFilter1DEXT (void);
#define   gdk_gl_glConvolutionFilter1DEXT(proc, target, internalformat, width, format, type, image) \
  ( ((PFNGLCONVOLUTIONFILTER1DEXTPROC) (proc)) (target, internalformat, width, format, type, image) )

/* void glConvolutionFilter2DEXT (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glConvolutionFilter2DEXT (void);
#define   gdk_gl_glConvolutionFilter2DEXT(proc, target, internalformat, width, height, format, type, image) \
  ( ((PFNGLCONVOLUTIONFILTER2DEXTPROC) (proc)) (target, internalformat, width, height, format, type, image) )

/* void glConvolutionParameterfEXT (GLenum, GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glConvolutionParameterfEXT (void);
#define   gdk_gl_glConvolutionParameterfEXT(proc, target, pname, params) \
  ( ((PFNGLCONVOLUTIONPARAMETERFEXTPROC) (proc)) (target, pname, params) )

/* void glConvolutionParameterfvEXT (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glConvolutionParameterfvEXT (void);
#define   gdk_gl_glConvolutionParameterfvEXT(proc, target, pname, params) \
  ( ((PFNGLCONVOLUTIONPARAMETERFVEXTPROC) (proc)) (target, pname, params) )

/* void glConvolutionParameteriEXT (GLenum, GLenum, GLint) */
GdkGLProc gdk_gl_get_glConvolutionParameteriEXT (void);
#define   gdk_gl_glConvolutionParameteriEXT(proc, target, pname, params) \
  ( ((PFNGLCONVOLUTIONPARAMETERIEXTPROC) (proc)) (target, pname, params) )

/* void glConvolutionParameterivEXT (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glConvolutionParameterivEXT (void);
#define   gdk_gl_glConvolutionParameterivEXT(proc, target, pname, params) \
  ( ((PFNGLCONVOLUTIONPARAMETERIVEXTPROC) (proc)) (target, pname, params) )

/* void glCopyConvolutionFilter1DEXT (GLenum, GLenum, GLint, GLint, GLsizei) */
GdkGLProc gdk_gl_get_glCopyConvolutionFilter1DEXT (void);
#define   gdk_gl_glCopyConvolutionFilter1DEXT(proc, target, internalformat, x, y, width) \
  ( ((PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC) (proc)) (target, internalformat, x, y, width) )

/* void glCopyConvolutionFilter2DEXT (GLenum, GLenum, GLint, GLint, GLsizei, GLsizei) */
GdkGLProc gdk_gl_get_glCopyConvolutionFilter2DEXT (void);
#define   gdk_gl_glCopyConvolutionFilter2DEXT(proc, target, internalformat, x, y, width, height) \
  ( ((PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC) (proc)) (target, internalformat, x, y, width, height) )

/* void glGetConvolutionFilterEXT (GLenum, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetConvolutionFilterEXT (void);
#define   gdk_gl_glGetConvolutionFilterEXT(proc, target, format, type, image) \
  ( ((PFNGLGETCONVOLUTIONFILTEREXTPROC) (proc)) (target, format, type, image) )

/* void glGetConvolutionParameterfvEXT (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetConvolutionParameterfvEXT (void);
#define   gdk_gl_glGetConvolutionParameterfvEXT(proc, target, pname, params) \
  ( ((PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC) (proc)) (target, pname, params) )

/* void glGetConvolutionParameterivEXT (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetConvolutionParameterivEXT (void);
#define   gdk_gl_glGetConvolutionParameterivEXT(proc, target, pname, params) \
  ( ((PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC) (proc)) (target, pname, params) )

/* void glGetSeparableFilterEXT (GLenum, GLenum, GLenum, GLvoid *, GLvoid *, GLvoid *) */
GdkGLProc gdk_gl_get_glGetSeparableFilterEXT (void);
#define   gdk_gl_glGetSeparableFilterEXT(proc, target, format, type, row, column, span) \
  ( ((PFNGLGETSEPARABLEFILTEREXTPROC) (proc)) (target, format, type, row, column, span) )

/* void glSeparableFilter2DEXT (GLenum, GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *, const GLvoid *) */
GdkGLProc gdk_gl_get_glSeparableFilter2DEXT (void);
#define   gdk_gl_glSeparableFilter2DEXT(proc, target, internalformat, width, height, format, type, row, column) \
  ( ((PFNGLSEPARABLEFILTER2DEXTPROC) (proc)) (target, internalformat, width, height, format, type, row, column) )

/* 
 * GL_SGI_color_table
 */

/* void glColorTableSGI (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glColorTableSGI (void);
#define   gdk_gl_glColorTableSGI(proc, target, internalformat, width, format, type, table) \
  ( ((PFNGLCOLORTABLESGIPROC) (proc)) (target, internalformat, width, format, type, table) )

/* void glColorTableParameterfvSGI (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glColorTableParameterfvSGI (void);
#define   gdk_gl_glColorTableParameterfvSGI(proc, target, pname, params) \
  ( ((PFNGLCOLORTABLEPARAMETERFVSGIPROC) (proc)) (target, pname, params) )

/* void glColorTableParameterivSGI (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glColorTableParameterivSGI (void);
#define   gdk_gl_glColorTableParameterivSGI(proc, target, pname, params) \
  ( ((PFNGLCOLORTABLEPARAMETERIVSGIPROC) (proc)) (target, pname, params) )

/* void glCopyColorTableSGI (GLenum, GLenum, GLint, GLint, GLsizei) */
GdkGLProc gdk_gl_get_glCopyColorTableSGI (void);
#define   gdk_gl_glCopyColorTableSGI(proc, target, internalformat, x, y, width) \
  ( ((PFNGLCOPYCOLORTABLESGIPROC) (proc)) (target, internalformat, x, y, width) )

/* void glGetColorTableSGI (GLenum, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetColorTableSGI (void);
#define   gdk_gl_glGetColorTableSGI(proc, target, format, type, table) \
  ( ((PFNGLGETCOLORTABLESGIPROC) (proc)) (target, format, type, table) )

/* void glGetColorTableParameterfvSGI (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetColorTableParameterfvSGI (void);
#define   gdk_gl_glGetColorTableParameterfvSGI(proc, target, pname, params) \
  ( ((PFNGLGETCOLORTABLEPARAMETERFVSGIPROC) (proc)) (target, pname, params) )

/* void glGetColorTableParameterivSGI (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetColorTableParameterivSGI (void);
#define   gdk_gl_glGetColorTableParameterivSGI(proc, target, pname, params) \
  ( ((PFNGLGETCOLORTABLEPARAMETERIVSGIPROC) (proc)) (target, pname, params) )

/* 
 * GL_SGIX_pixel_texture
 */

/* void glPixelTexGenSGIX (GLenum) */
GdkGLProc gdk_gl_get_glPixelTexGenSGIX (void);
#define   gdk_gl_glPixelTexGenSGIX(proc, mode) \
  ( ((PFNGLPIXELTEXGENSGIXPROC) (proc)) (mode) )

/* 
 * GL_SGIS_pixel_texture
 */

/* void glPixelTexGenParameteriSGIS (GLenum, GLint) */
GdkGLProc gdk_gl_get_glPixelTexGenParameteriSGIS (void);
#define   gdk_gl_glPixelTexGenParameteriSGIS(proc, pname, param) \
  ( ((PFNGLPIXELTEXGENPARAMETERISGISPROC) (proc)) (pname, param) )

/* void glPixelTexGenParameterivSGIS (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glPixelTexGenParameterivSGIS (void);
#define   gdk_gl_glPixelTexGenParameterivSGIS(proc, pname, params) \
  ( ((PFNGLPIXELTEXGENPARAMETERIVSGISPROC) (proc)) (pname, params) )

/* void glPixelTexGenParameterfSGIS (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glPixelTexGenParameterfSGIS (void);
#define   gdk_gl_glPixelTexGenParameterfSGIS(proc, pname, param) \
  ( ((PFNGLPIXELTEXGENPARAMETERFSGISPROC) (proc)) (pname, param) )

/* void glPixelTexGenParameterfvSGIS (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glPixelTexGenParameterfvSGIS (void);
#define   gdk_gl_glPixelTexGenParameterfvSGIS(proc, pname, params) \
  ( ((PFNGLPIXELTEXGENPARAMETERFVSGISPROC) (proc)) (pname, params) )

/* void glGetPixelTexGenParameterivSGIS (GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetPixelTexGenParameterivSGIS (void);
#define   gdk_gl_glGetPixelTexGenParameterivSGIS(proc, pname, params) \
  ( ((PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC) (proc)) (pname, params) )

/* void glGetPixelTexGenParameterfvSGIS (GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetPixelTexGenParameterfvSGIS (void);
#define   gdk_gl_glGetPixelTexGenParameterfvSGIS(proc, pname, params) \
  ( ((PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC) (proc)) (pname, params) )

/* 
 * GL_SGIS_texture4D
 */

/* void glTexImage4DSGIS (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexImage4DSGIS (void);
#define   gdk_gl_glTexImage4DSGIS(proc, target, level, internalformat, width, height, depth, size4d, border, format, type, pixels) \
  ( ((PFNGLTEXIMAGE4DSGISPROC) (proc)) (target, level, internalformat, width, height, depth, size4d, border, format, type, pixels) )

/* void glTexSubImage4DSGIS (GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexSubImage4DSGIS (void);
#define   gdk_gl_glTexSubImage4DSGIS(proc, target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels) \
  ( ((PFNGLTEXSUBIMAGE4DSGISPROC) (proc)) (target, level, xoffset, yoffset, zoffset, woffset, width, height, depth, size4d, format, type, pixels) )

/* 
 * GL_EXT_texture_object
 */

/* GLboolean glAreTexturesResidentEXT (GLsizei, const GLuint *, GLboolean *) */
GdkGLProc gdk_gl_get_glAreTexturesResidentEXT (void);
#define   gdk_gl_glAreTexturesResidentEXT(proc, n, textures, residences) \
  ( ((PFNGLARETEXTURESRESIDENTEXTPROC) (proc)) (n, textures, residences) )

/* void glBindTextureEXT (GLenum, GLuint) */
GdkGLProc gdk_gl_get_glBindTextureEXT (void);
#define   gdk_gl_glBindTextureEXT(proc, target, texture) \
  ( ((PFNGLBINDTEXTUREEXTPROC) (proc)) (target, texture) )

/* void glDeleteTexturesEXT (GLsizei, const GLuint *) */
GdkGLProc gdk_gl_get_glDeleteTexturesEXT (void);
#define   gdk_gl_glDeleteTexturesEXT(proc, n, textures) \
  ( ((PFNGLDELETETEXTURESEXTPROC) (proc)) (n, textures) )

/* void glGenTexturesEXT (GLsizei, GLuint *) */
GdkGLProc gdk_gl_get_glGenTexturesEXT (void);
#define   gdk_gl_glGenTexturesEXT(proc, n, textures) \
  ( ((PFNGLGENTEXTURESEXTPROC) (proc)) (n, textures) )

/* GLboolean glIsTextureEXT (GLuint) */
GdkGLProc gdk_gl_get_glIsTextureEXT (void);
#define   gdk_gl_glIsTextureEXT(proc, texture) \
  ( ((PFNGLISTEXTUREEXTPROC) (proc)) (texture) )

/* void glPrioritizeTexturesEXT (GLsizei, const GLuint *, const GLclampf *) */
GdkGLProc gdk_gl_get_glPrioritizeTexturesEXT (void);
#define   gdk_gl_glPrioritizeTexturesEXT(proc, n, textures, priorities) \
  ( ((PFNGLPRIORITIZETEXTURESEXTPROC) (proc)) (n, textures, priorities) )

/* 
 * GL_SGIS_detail_texture
 */

/* void glDetailTexFuncSGIS (GLenum, GLsizei, const GLfloat *) */
GdkGLProc gdk_gl_get_glDetailTexFuncSGIS (void);
#define   gdk_gl_glDetailTexFuncSGIS(proc, target, n, points) \
  ( ((PFNGLDETAILTEXFUNCSGISPROC) (proc)) (target, n, points) )

/* void glGetDetailTexFuncSGIS (GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetDetailTexFuncSGIS (void);
#define   gdk_gl_glGetDetailTexFuncSGIS(proc, target, points) \
  ( ((PFNGLGETDETAILTEXFUNCSGISPROC) (proc)) (target, points) )

/* 
 * GL_SGIS_sharpen_texture
 */

/* void glSharpenTexFuncSGIS (GLenum, GLsizei, const GLfloat *) */
GdkGLProc gdk_gl_get_glSharpenTexFuncSGIS (void);
#define   gdk_gl_glSharpenTexFuncSGIS(proc, target, n, points) \
  ( ((PFNGLSHARPENTEXFUNCSGISPROC) (proc)) (target, n, points) )

/* void glGetSharpenTexFuncSGIS (GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetSharpenTexFuncSGIS (void);
#define   gdk_gl_glGetSharpenTexFuncSGIS(proc, target, points) \
  ( ((PFNGLGETSHARPENTEXFUNCSGISPROC) (proc)) (target, points) )

/* 
 * GL_SGIS_multisample
 */

/* void glSampleMaskSGIS (GLclampf, GLboolean) */
GdkGLProc gdk_gl_get_glSampleMaskSGIS (void);
#define   gdk_gl_glSampleMaskSGIS(proc, value, invert) \
  ( ((PFNGLSAMPLEMASKSGISPROC) (proc)) (value, invert) )

/* void glSamplePatternSGIS (GLenum) */
GdkGLProc gdk_gl_get_glSamplePatternSGIS (void);
#define   gdk_gl_glSamplePatternSGIS(proc, pattern) \
  ( ((PFNGLSAMPLEPATTERNSGISPROC) (proc)) (pattern) )

/* 
 * GL_EXT_vertex_array
 */

/* void glArrayElementEXT (GLint) */
GdkGLProc gdk_gl_get_glArrayElementEXT (void);
#define   gdk_gl_glArrayElementEXT(proc, i) \
  ( ((PFNGLARRAYELEMENTEXTPROC) (proc)) (i) )

/* void glColorPointerEXT (GLint, GLenum, GLsizei, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glColorPointerEXT (void);
#define   gdk_gl_glColorPointerEXT(proc, size, type, stride, count, pointer) \
  ( ((PFNGLCOLORPOINTEREXTPROC) (proc)) (size, type, stride, count, pointer) )

/* void glDrawArraysEXT (GLenum, GLint, GLsizei) */
GdkGLProc gdk_gl_get_glDrawArraysEXT (void);
#define   gdk_gl_glDrawArraysEXT(proc, mode, first, count) \
  ( ((PFNGLDRAWARRAYSEXTPROC) (proc)) (mode, first, count) )

/* void glEdgeFlagPointerEXT (GLsizei, GLsizei, const GLboolean *) */
GdkGLProc gdk_gl_get_glEdgeFlagPointerEXT (void);
#define   gdk_gl_glEdgeFlagPointerEXT(proc, stride, count, pointer) \
  ( ((PFNGLEDGEFLAGPOINTEREXTPROC) (proc)) (stride, count, pointer) )

/* void glGetPointervEXT (GLenum, GLvoid* *) */
GdkGLProc gdk_gl_get_glGetPointervEXT (void);
#define   gdk_gl_glGetPointervEXT(proc, pname, params) \
  ( ((PFNGLGETPOINTERVEXTPROC) (proc)) (pname, params) )

/* void glIndexPointerEXT (GLenum, GLsizei, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glIndexPointerEXT (void);
#define   gdk_gl_glIndexPointerEXT(proc, type, stride, count, pointer) \
  ( ((PFNGLINDEXPOINTEREXTPROC) (proc)) (type, stride, count, pointer) )

/* void glNormalPointerEXT (GLenum, GLsizei, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glNormalPointerEXT (void);
#define   gdk_gl_glNormalPointerEXT(proc, type, stride, count, pointer) \
  ( ((PFNGLNORMALPOINTEREXTPROC) (proc)) (type, stride, count, pointer) )

/* void glTexCoordPointerEXT (GLint, GLenum, GLsizei, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glTexCoordPointerEXT (void);
#define   gdk_gl_glTexCoordPointerEXT(proc, size, type, stride, count, pointer) \
  ( ((PFNGLTEXCOORDPOINTEREXTPROC) (proc)) (size, type, stride, count, pointer) )

/* void glVertexPointerEXT (GLint, GLenum, GLsizei, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glVertexPointerEXT (void);
#define   gdk_gl_glVertexPointerEXT(proc, size, type, stride, count, pointer) \
  ( ((PFNGLVERTEXPOINTEREXTPROC) (proc)) (size, type, stride, count, pointer) )

/* 
 * GL_EXT_blend_minmax
 */

/* void glBlendEquationEXT (GLenum) */
GdkGLProc gdk_gl_get_glBlendEquationEXT (void);
#define   gdk_gl_glBlendEquationEXT(proc, mode) \
  ( ((PFNGLBLENDEQUATIONEXTPROC) (proc)) (mode) )

/* 
 * GL_SGIX_sprite
 */

/* void glSpriteParameterfSGIX (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glSpriteParameterfSGIX (void);
#define   gdk_gl_glSpriteParameterfSGIX(proc, pname, param) \
  ( ((PFNGLSPRITEPARAMETERFSGIXPROC) (proc)) (pname, param) )

/* void glSpriteParameterfvSGIX (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glSpriteParameterfvSGIX (void);
#define   gdk_gl_glSpriteParameterfvSGIX(proc, pname, params) \
  ( ((PFNGLSPRITEPARAMETERFVSGIXPROC) (proc)) (pname, params) )

/* void glSpriteParameteriSGIX (GLenum, GLint) */
GdkGLProc gdk_gl_get_glSpriteParameteriSGIX (void);
#define   gdk_gl_glSpriteParameteriSGIX(proc, pname, param) \
  ( ((PFNGLSPRITEPARAMETERISGIXPROC) (proc)) (pname, param) )

/* void glSpriteParameterivSGIX (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glSpriteParameterivSGIX (void);
#define   gdk_gl_glSpriteParameterivSGIX(proc, pname, params) \
  ( ((PFNGLSPRITEPARAMETERIVSGIXPROC) (proc)) (pname, params) )

/* 
 * GL_EXT_point_parameters
 */

/* void glPointParameterfEXT (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glPointParameterfEXT (void);
#define   gdk_gl_glPointParameterfEXT(proc, pname, param) \
  ( ((PFNGLPOINTPARAMETERFEXTPROC) (proc)) (pname, param) )

/* void glPointParameterfvEXT (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glPointParameterfvEXT (void);
#define   gdk_gl_glPointParameterfvEXT(proc, pname, params) \
  ( ((PFNGLPOINTPARAMETERFVEXTPROC) (proc)) (pname, params) )

/* 
 * GL_SGIS_point_parameters
 */

/* void glPointParameterfSGIS (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glPointParameterfSGIS (void);
#define   gdk_gl_glPointParameterfSGIS(proc, pname, param) \
  ( ((PFNGLPOINTPARAMETERFSGISPROC) (proc)) (pname, param) )

/* void glPointParameterfvSGIS (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glPointParameterfvSGIS (void);
#define   gdk_gl_glPointParameterfvSGIS(proc, pname, params) \
  ( ((PFNGLPOINTPARAMETERFVSGISPROC) (proc)) (pname, params) )

/* 
 * GL_SGIX_instruments
 */

/* GLint glGetInstrumentsSGIX (void) */
GdkGLProc gdk_gl_get_glGetInstrumentsSGIX (void);
#define   gdk_gl_glGetInstrumentsSGIX(proc) \
  ( ((PFNGLGETINSTRUMENTSSGIXPROC) (proc)) () )

/* void glInstrumentsBufferSGIX (GLsizei, GLint *) */
GdkGLProc gdk_gl_get_glInstrumentsBufferSGIX (void);
#define   gdk_gl_glInstrumentsBufferSGIX(proc, size, buffer) \
  ( ((PFNGLINSTRUMENTSBUFFERSGIXPROC) (proc)) (size, buffer) )

/* GLint glPollInstrumentsSGIX (GLint *) */
GdkGLProc gdk_gl_get_glPollInstrumentsSGIX (void);
#define   gdk_gl_glPollInstrumentsSGIX(proc, marker_p) \
  ( ((PFNGLPOLLINSTRUMENTSSGIXPROC) (proc)) (marker_p) )

/* void glReadInstrumentsSGIX (GLint) */
GdkGLProc gdk_gl_get_glReadInstrumentsSGIX (void);
#define   gdk_gl_glReadInstrumentsSGIX(proc, marker) \
  ( ((PFNGLREADINSTRUMENTSSGIXPROC) (proc)) (marker) )

/* void glStartInstrumentsSGIX (void) */
GdkGLProc gdk_gl_get_glStartInstrumentsSGIX (void);
#define   gdk_gl_glStartInstrumentsSGIX(proc) \
  ( ((PFNGLSTARTINSTRUMENTSSGIXPROC) (proc)) () )

/* void glStopInstrumentsSGIX (GLint) */
GdkGLProc gdk_gl_get_glStopInstrumentsSGIX (void);
#define   gdk_gl_glStopInstrumentsSGIX(proc, marker) \
  ( ((PFNGLSTOPINSTRUMENTSSGIXPROC) (proc)) (marker) )

/* 
 * GL_SGIX_framezoom
 */

/* void glFrameZoomSGIX (GLint) */
GdkGLProc gdk_gl_get_glFrameZoomSGIX (void);
#define   gdk_gl_glFrameZoomSGIX(proc, factor) \
  ( ((PFNGLFRAMEZOOMSGIXPROC) (proc)) (factor) )

/* 
 * GL_SGIX_tag_sample_buffer
 */

/* void glTagSampleBufferSGIX (void) */
GdkGLProc gdk_gl_get_glTagSampleBufferSGIX (void);
#define   gdk_gl_glTagSampleBufferSGIX(proc) \
  ( ((PFNGLTAGSAMPLEBUFFERSGIXPROC) (proc)) () )

/* 
 * GL_SGIX_polynomial_ffd
 */

/* void glDeformationMap3dSGIX (GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *) */
GdkGLProc gdk_gl_get_glDeformationMap3dSGIX (void);
#define   gdk_gl_glDeformationMap3dSGIX(proc, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points) \
  ( ((PFNGLDEFORMATIONMAP3DSGIXPROC) (proc)) (target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points) )

/* void glDeformationMap3fSGIX (GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *) */
GdkGLProc gdk_gl_get_glDeformationMap3fSGIX (void);
#define   gdk_gl_glDeformationMap3fSGIX(proc, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points) \
  ( ((PFNGLDEFORMATIONMAP3FSGIXPROC) (proc)) (target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, w1, w2, wstride, worder, points) )

/* void glDeformSGIX (GLbitfield) */
GdkGLProc gdk_gl_get_glDeformSGIX (void);
#define   gdk_gl_glDeformSGIX(proc, mask) \
  ( ((PFNGLDEFORMSGIXPROC) (proc)) (mask) )

/* void glLoadIdentityDeformationMapSGIX (GLbitfield) */
GdkGLProc gdk_gl_get_glLoadIdentityDeformationMapSGIX (void);
#define   gdk_gl_glLoadIdentityDeformationMapSGIX(proc, mask) \
  ( ((PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC) (proc)) (mask) )

/* 
 * GL_SGIX_reference_plane
 */

/* void glReferencePlaneSGIX (const GLdouble *) */
GdkGLProc gdk_gl_get_glReferencePlaneSGIX (void);
#define   gdk_gl_glReferencePlaneSGIX(proc, equation) \
  ( ((PFNGLREFERENCEPLANESGIXPROC) (proc)) (equation) )

/* 
 * GL_SGIX_flush_raster
 */

/* void glFlushRasterSGIX (void) */
GdkGLProc gdk_gl_get_glFlushRasterSGIX (void);
#define   gdk_gl_glFlushRasterSGIX(proc) \
  ( ((PFNGLFLUSHRASTERSGIXPROC) (proc)) () )

/* 
 * GL_SGIS_fog_function
 */

/* void glFogFuncSGIS (GLsizei, const GLfloat *) */
GdkGLProc gdk_gl_get_glFogFuncSGIS (void);
#define   gdk_gl_glFogFuncSGIS(proc, n, points) \
  ( ((PFNGLFOGFUNCSGISPROC) (proc)) (n, points) )

/* void glGetFogFuncSGIS (GLfloat *) */
GdkGLProc gdk_gl_get_glGetFogFuncSGIS (void);
#define   gdk_gl_glGetFogFuncSGIS(proc, points) \
  ( ((PFNGLGETFOGFUNCSGISPROC) (proc)) (points) )

/* 
 * GL_HP_image_transform
 */

/* void glImageTransformParameteriHP (GLenum, GLenum, GLint) */
GdkGLProc gdk_gl_get_glImageTransformParameteriHP (void);
#define   gdk_gl_glImageTransformParameteriHP(proc, target, pname, param) \
  ( ((PFNGLIMAGETRANSFORMPARAMETERIHPPROC) (proc)) (target, pname, param) )

/* void glImageTransformParameterfHP (GLenum, GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glImageTransformParameterfHP (void);
#define   gdk_gl_glImageTransformParameterfHP(proc, target, pname, param) \
  ( ((PFNGLIMAGETRANSFORMPARAMETERFHPPROC) (proc)) (target, pname, param) )

/* void glImageTransformParameterivHP (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glImageTransformParameterivHP (void);
#define   gdk_gl_glImageTransformParameterivHP(proc, target, pname, params) \
  ( ((PFNGLIMAGETRANSFORMPARAMETERIVHPPROC) (proc)) (target, pname, params) )

/* void glImageTransformParameterfvHP (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glImageTransformParameterfvHP (void);
#define   gdk_gl_glImageTransformParameterfvHP(proc, target, pname, params) \
  ( ((PFNGLIMAGETRANSFORMPARAMETERFVHPPROC) (proc)) (target, pname, params) )

/* void glGetImageTransformParameterivHP (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetImageTransformParameterivHP (void);
#define   gdk_gl_glGetImageTransformParameterivHP(proc, target, pname, params) \
  ( ((PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC) (proc)) (target, pname, params) )

/* void glGetImageTransformParameterfvHP (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetImageTransformParameterfvHP (void);
#define   gdk_gl_glGetImageTransformParameterfvHP(proc, target, pname, params) \
  ( ((PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC) (proc)) (target, pname, params) )

/* 
 * GL_EXT_color_subtable
 */

/* void glColorSubTableEXT (GLenum, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glColorSubTableEXT (void);
#define   gdk_gl_glColorSubTableEXT(proc, target, start, count, format, type, data) \
  ( ((PFNGLCOLORSUBTABLEEXTPROC) (proc)) (target, start, count, format, type, data) )

/* void glCopyColorSubTableEXT (GLenum, GLsizei, GLint, GLint, GLsizei) */
GdkGLProc gdk_gl_get_glCopyColorSubTableEXT (void);
#define   gdk_gl_glCopyColorSubTableEXT(proc, target, start, x, y, width) \
  ( ((PFNGLCOPYCOLORSUBTABLEEXTPROC) (proc)) (target, start, x, y, width) )

/* 
 * GL_PGI_misc_hints
 */

/* void glHintPGI (GLenum, GLint) */
GdkGLProc gdk_gl_get_glHintPGI (void);
#define   gdk_gl_glHintPGI(proc, target, mode) \
  ( ((PFNGLHINTPGIPROC) (proc)) (target, mode) )

/* 
 * GL_EXT_paletted_texture
 */

/* void glColorTableEXT (GLenum, GLenum, GLsizei, GLenum, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glColorTableEXT (void);
#define   gdk_gl_glColorTableEXT(proc, target, internalFormat, width, format, type, table) \
  ( ((PFNGLCOLORTABLEEXTPROC) (proc)) (target, internalFormat, width, format, type, table) )

/* void glGetColorTableEXT (GLenum, GLenum, GLenum, GLvoid *) */
GdkGLProc gdk_gl_get_glGetColorTableEXT (void);
#define   gdk_gl_glGetColorTableEXT(proc, target, format, type, data) \
  ( ((PFNGLGETCOLORTABLEEXTPROC) (proc)) (target, format, type, data) )

/* void glGetColorTableParameterivEXT (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetColorTableParameterivEXT (void);
#define   gdk_gl_glGetColorTableParameterivEXT(proc, target, pname, params) \
  ( ((PFNGLGETCOLORTABLEPARAMETERIVEXTPROC) (proc)) (target, pname, params) )

/* void glGetColorTableParameterfvEXT (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetColorTableParameterfvEXT (void);
#define   gdk_gl_glGetColorTableParameterfvEXT(proc, target, pname, params) \
  ( ((PFNGLGETCOLORTABLEPARAMETERFVEXTPROC) (proc)) (target, pname, params) )

/* 
 * GL_SGIX_list_priority
 */

/* void glGetListParameterfvSGIX (GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetListParameterfvSGIX (void);
#define   gdk_gl_glGetListParameterfvSGIX(proc, list, pname, params) \
  ( ((PFNGLGETLISTPARAMETERFVSGIXPROC) (proc)) (list, pname, params) )

/* void glGetListParameterivSGIX (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetListParameterivSGIX (void);
#define   gdk_gl_glGetListParameterivSGIX(proc, list, pname, params) \
  ( ((PFNGLGETLISTPARAMETERIVSGIXPROC) (proc)) (list, pname, params) )

/* void glListParameterfSGIX (GLuint, GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glListParameterfSGIX (void);
#define   gdk_gl_glListParameterfSGIX(proc, list, pname, param) \
  ( ((PFNGLLISTPARAMETERFSGIXPROC) (proc)) (list, pname, param) )

/* void glListParameterfvSGIX (GLuint, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glListParameterfvSGIX (void);
#define   gdk_gl_glListParameterfvSGIX(proc, list, pname, params) \
  ( ((PFNGLLISTPARAMETERFVSGIXPROC) (proc)) (list, pname, params) )

/* void glListParameteriSGIX (GLuint, GLenum, GLint) */
GdkGLProc gdk_gl_get_glListParameteriSGIX (void);
#define   gdk_gl_glListParameteriSGIX(proc, list, pname, param) \
  ( ((PFNGLLISTPARAMETERISGIXPROC) (proc)) (list, pname, param) )

/* void glListParameterivSGIX (GLuint, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glListParameterivSGIX (void);
#define   gdk_gl_glListParameterivSGIX(proc, list, pname, params) \
  ( ((PFNGLLISTPARAMETERIVSGIXPROC) (proc)) (list, pname, params) )

/* 
 * GL_EXT_index_material
 */

/* void glIndexMaterialEXT (GLenum, GLenum) */
GdkGLProc gdk_gl_get_glIndexMaterialEXT (void);
#define   gdk_gl_glIndexMaterialEXT(proc, face, mode) \
  ( ((PFNGLINDEXMATERIALEXTPROC) (proc)) (face, mode) )

/* 
 * GL_EXT_index_func
 */

/* void glIndexFuncEXT (GLenum, GLclampf) */
GdkGLProc gdk_gl_get_glIndexFuncEXT (void);
#define   gdk_gl_glIndexFuncEXT(proc, func, ref) \
  ( ((PFNGLINDEXFUNCEXTPROC) (proc)) (func, ref) )

/* 
 * GL_EXT_compiled_vertex_array
 */

/* void glLockArraysEXT (GLint, GLsizei) */
GdkGLProc gdk_gl_get_glLockArraysEXT (void);
#define   gdk_gl_glLockArraysEXT(proc, first, count) \
  ( ((PFNGLLOCKARRAYSEXTPROC) (proc)) (first, count) )

/* void glUnlockArraysEXT (void) */
GdkGLProc gdk_gl_get_glUnlockArraysEXT (void);
#define   gdk_gl_glUnlockArraysEXT(proc) \
  ( ((PFNGLUNLOCKARRAYSEXTPROC) (proc)) () )

/* 
 * GL_EXT_cull_vertex
 */

/* void glCullParameterdvEXT (GLenum, GLdouble *) */
GdkGLProc gdk_gl_get_glCullParameterdvEXT (void);
#define   gdk_gl_glCullParameterdvEXT(proc, pname, params) \
  ( ((PFNGLCULLPARAMETERDVEXTPROC) (proc)) (pname, params) )

/* void glCullParameterfvEXT (GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glCullParameterfvEXT (void);
#define   gdk_gl_glCullParameterfvEXT(proc, pname, params) \
  ( ((PFNGLCULLPARAMETERFVEXTPROC) (proc)) (pname, params) )

/* 
 * GL_SGIX_fragment_lighting
 */

/* void glFragmentColorMaterialSGIX (GLenum, GLenum) */
GdkGLProc gdk_gl_get_glFragmentColorMaterialSGIX (void);
#define   gdk_gl_glFragmentColorMaterialSGIX(proc, face, mode) \
  ( ((PFNGLFRAGMENTCOLORMATERIALSGIXPROC) (proc)) (face, mode) )

/* void glFragmentLightfSGIX (GLenum, GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glFragmentLightfSGIX (void);
#define   gdk_gl_glFragmentLightfSGIX(proc, light, pname, param) \
  ( ((PFNGLFRAGMENTLIGHTFSGIXPROC) (proc)) (light, pname, param) )

/* void glFragmentLightfvSGIX (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glFragmentLightfvSGIX (void);
#define   gdk_gl_glFragmentLightfvSGIX(proc, light, pname, params) \
  ( ((PFNGLFRAGMENTLIGHTFVSGIXPROC) (proc)) (light, pname, params) )

/* void glFragmentLightiSGIX (GLenum, GLenum, GLint) */
GdkGLProc gdk_gl_get_glFragmentLightiSGIX (void);
#define   gdk_gl_glFragmentLightiSGIX(proc, light, pname, param) \
  ( ((PFNGLFRAGMENTLIGHTISGIXPROC) (proc)) (light, pname, param) )

/* void glFragmentLightivSGIX (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glFragmentLightivSGIX (void);
#define   gdk_gl_glFragmentLightivSGIX(proc, light, pname, params) \
  ( ((PFNGLFRAGMENTLIGHTIVSGIXPROC) (proc)) (light, pname, params) )

/* void glFragmentLightModelfSGIX (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glFragmentLightModelfSGIX (void);
#define   gdk_gl_glFragmentLightModelfSGIX(proc, pname, param) \
  ( ((PFNGLFRAGMENTLIGHTMODELFSGIXPROC) (proc)) (pname, param) )

/* void glFragmentLightModelfvSGIX (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glFragmentLightModelfvSGIX (void);
#define   gdk_gl_glFragmentLightModelfvSGIX(proc, pname, params) \
  ( ((PFNGLFRAGMENTLIGHTMODELFVSGIXPROC) (proc)) (pname, params) )

/* void glFragmentLightModeliSGIX (GLenum, GLint) */
GdkGLProc gdk_gl_get_glFragmentLightModeliSGIX (void);
#define   gdk_gl_glFragmentLightModeliSGIX(proc, pname, param) \
  ( ((PFNGLFRAGMENTLIGHTMODELISGIXPROC) (proc)) (pname, param) )

/* void glFragmentLightModelivSGIX (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glFragmentLightModelivSGIX (void);
#define   gdk_gl_glFragmentLightModelivSGIX(proc, pname, params) \
  ( ((PFNGLFRAGMENTLIGHTMODELIVSGIXPROC) (proc)) (pname, params) )

/* void glFragmentMaterialfSGIX (GLenum, GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glFragmentMaterialfSGIX (void);
#define   gdk_gl_glFragmentMaterialfSGIX(proc, face, pname, param) \
  ( ((PFNGLFRAGMENTMATERIALFSGIXPROC) (proc)) (face, pname, param) )

/* void glFragmentMaterialfvSGIX (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glFragmentMaterialfvSGIX (void);
#define   gdk_gl_glFragmentMaterialfvSGIX(proc, face, pname, params) \
  ( ((PFNGLFRAGMENTMATERIALFVSGIXPROC) (proc)) (face, pname, params) )

/* void glFragmentMaterialiSGIX (GLenum, GLenum, GLint) */
GdkGLProc gdk_gl_get_glFragmentMaterialiSGIX (void);
#define   gdk_gl_glFragmentMaterialiSGIX(proc, face, pname, param) \
  ( ((PFNGLFRAGMENTMATERIALISGIXPROC) (proc)) (face, pname, param) )

/* void glFragmentMaterialivSGIX (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glFragmentMaterialivSGIX (void);
#define   gdk_gl_glFragmentMaterialivSGIX(proc, face, pname, params) \
  ( ((PFNGLFRAGMENTMATERIALIVSGIXPROC) (proc)) (face, pname, params) )

/* void glGetFragmentLightfvSGIX (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetFragmentLightfvSGIX (void);
#define   gdk_gl_glGetFragmentLightfvSGIX(proc, light, pname, params) \
  ( ((PFNGLGETFRAGMENTLIGHTFVSGIXPROC) (proc)) (light, pname, params) )

/* void glGetFragmentLightivSGIX (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetFragmentLightivSGIX (void);
#define   gdk_gl_glGetFragmentLightivSGIX(proc, light, pname, params) \
  ( ((PFNGLGETFRAGMENTLIGHTIVSGIXPROC) (proc)) (light, pname, params) )

/* void glGetFragmentMaterialfvSGIX (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetFragmentMaterialfvSGIX (void);
#define   gdk_gl_glGetFragmentMaterialfvSGIX(proc, face, pname, params) \
  ( ((PFNGLGETFRAGMENTMATERIALFVSGIXPROC) (proc)) (face, pname, params) )

/* void glGetFragmentMaterialivSGIX (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetFragmentMaterialivSGIX (void);
#define   gdk_gl_glGetFragmentMaterialivSGIX(proc, face, pname, params) \
  ( ((PFNGLGETFRAGMENTMATERIALIVSGIXPROC) (proc)) (face, pname, params) )

/* void glLightEnviSGIX (GLenum, GLint) */
GdkGLProc gdk_gl_get_glLightEnviSGIX (void);
#define   gdk_gl_glLightEnviSGIX(proc, pname, param) \
  ( ((PFNGLLIGHTENVISGIXPROC) (proc)) (pname, param) )

/* 
 * GL_EXT_draw_range_elements
 */

/* void glDrawRangeElementsEXT (GLenum, GLuint, GLuint, GLsizei, GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glDrawRangeElementsEXT (void);
#define   gdk_gl_glDrawRangeElementsEXT(proc, mode, start, end, count, type, indices) \
  ( ((PFNGLDRAWRANGEELEMENTSEXTPROC) (proc)) (mode, start, end, count, type, indices) )

/* 
 * GL_EXT_light_texture
 */

/* void glApplyTextureEXT (GLenum) */
GdkGLProc gdk_gl_get_glApplyTextureEXT (void);
#define   gdk_gl_glApplyTextureEXT(proc, mode) \
  ( ((PFNGLAPPLYTEXTUREEXTPROC) (proc)) (mode) )

/* void glTextureLightEXT (GLenum) */
GdkGLProc gdk_gl_get_glTextureLightEXT (void);
#define   gdk_gl_glTextureLightEXT(proc, pname) \
  ( ((PFNGLTEXTURELIGHTEXTPROC) (proc)) (pname) )

/* void glTextureMaterialEXT (GLenum, GLenum) */
GdkGLProc gdk_gl_get_glTextureMaterialEXT (void);
#define   gdk_gl_glTextureMaterialEXT(proc, face, mode) \
  ( ((PFNGLTEXTUREMATERIALEXTPROC) (proc)) (face, mode) )

/* 
 * GL_SGIX_async
 */

/* void glAsyncMarkerSGIX (GLuint) */
GdkGLProc gdk_gl_get_glAsyncMarkerSGIX (void);
#define   gdk_gl_glAsyncMarkerSGIX(proc, marker) \
  ( ((PFNGLASYNCMARKERSGIXPROC) (proc)) (marker) )

/* GLint glFinishAsyncSGIX (GLuint *) */
GdkGLProc gdk_gl_get_glFinishAsyncSGIX (void);
#define   gdk_gl_glFinishAsyncSGIX(proc, markerp) \
  ( ((PFNGLFINISHASYNCSGIXPROC) (proc)) (markerp) )

/* GLint glPollAsyncSGIX (GLuint *) */
GdkGLProc gdk_gl_get_glPollAsyncSGIX (void);
#define   gdk_gl_glPollAsyncSGIX(proc, markerp) \
  ( ((PFNGLPOLLASYNCSGIXPROC) (proc)) (markerp) )

/* GLuint glGenAsyncMarkersSGIX (GLsizei) */
GdkGLProc gdk_gl_get_glGenAsyncMarkersSGIX (void);
#define   gdk_gl_glGenAsyncMarkersSGIX(proc, range) \
  ( ((PFNGLGENASYNCMARKERSSGIXPROC) (proc)) (range) )

/* void glDeleteAsyncMarkersSGIX (GLuint, GLsizei) */
GdkGLProc gdk_gl_get_glDeleteAsyncMarkersSGIX (void);
#define   gdk_gl_glDeleteAsyncMarkersSGIX(proc, marker, range) \
  ( ((PFNGLDELETEASYNCMARKERSSGIXPROC) (proc)) (marker, range) )

/* GLboolean glIsAsyncMarkerSGIX (GLuint) */
GdkGLProc gdk_gl_get_glIsAsyncMarkerSGIX (void);
#define   gdk_gl_glIsAsyncMarkerSGIX(proc, marker) \
  ( ((PFNGLISASYNCMARKERSGIXPROC) (proc)) (marker) )

/* 
 * GL_INTEL_parallel_arrays
 */

/* void glVertexPointervINTEL (GLint, GLenum, const GLvoid* *) */
GdkGLProc gdk_gl_get_glVertexPointervINTEL (void);
#define   gdk_gl_glVertexPointervINTEL(proc, size, type, pointer) \
  ( ((PFNGLVERTEXPOINTERVINTELPROC) (proc)) (size, type, pointer) )

/* void glNormalPointervINTEL (GLenum, const GLvoid* *) */
GdkGLProc gdk_gl_get_glNormalPointervINTEL (void);
#define   gdk_gl_glNormalPointervINTEL(proc, type, pointer) \
  ( ((PFNGLNORMALPOINTERVINTELPROC) (proc)) (type, pointer) )

/* void glColorPointervINTEL (GLint, GLenum, const GLvoid* *) */
GdkGLProc gdk_gl_get_glColorPointervINTEL (void);
#define   gdk_gl_glColorPointervINTEL(proc, size, type, pointer) \
  ( ((PFNGLCOLORPOINTERVINTELPROC) (proc)) (size, type, pointer) )

/* void glTexCoordPointervINTEL (GLint, GLenum, const GLvoid* *) */
GdkGLProc gdk_gl_get_glTexCoordPointervINTEL (void);
#define   gdk_gl_glTexCoordPointervINTEL(proc, size, type, pointer) \
  ( ((PFNGLTEXCOORDPOINTERVINTELPROC) (proc)) (size, type, pointer) )

/* 
 * GL_EXT_pixel_transform
 */

/* void glPixelTransformParameteriEXT (GLenum, GLenum, GLint) */
GdkGLProc gdk_gl_get_glPixelTransformParameteriEXT (void);
#define   gdk_gl_glPixelTransformParameteriEXT(proc, target, pname, param) \
  ( ((PFNGLPIXELTRANSFORMPARAMETERIEXTPROC) (proc)) (target, pname, param) )

/* void glPixelTransformParameterfEXT (GLenum, GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glPixelTransformParameterfEXT (void);
#define   gdk_gl_glPixelTransformParameterfEXT(proc, target, pname, param) \
  ( ((PFNGLPIXELTRANSFORMPARAMETERFEXTPROC) (proc)) (target, pname, param) )

/* void glPixelTransformParameterivEXT (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glPixelTransformParameterivEXT (void);
#define   gdk_gl_glPixelTransformParameterivEXT(proc, target, pname, params) \
  ( ((PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC) (proc)) (target, pname, params) )

/* void glPixelTransformParameterfvEXT (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glPixelTransformParameterfvEXT (void);
#define   gdk_gl_glPixelTransformParameterfvEXT(proc, target, pname, params) \
  ( ((PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC) (proc)) (target, pname, params) )

/* 
 * GL_EXT_secondary_color
 */

/* void glSecondaryColor3bEXT (GLbyte, GLbyte, GLbyte) */
GdkGLProc gdk_gl_get_glSecondaryColor3bEXT (void);
#define   gdk_gl_glSecondaryColor3bEXT(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3BEXTPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3bvEXT (const GLbyte *) */
GdkGLProc gdk_gl_get_glSecondaryColor3bvEXT (void);
#define   gdk_gl_glSecondaryColor3bvEXT(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3BVEXTPROC) (proc)) (v) )

/* void glSecondaryColor3dEXT (GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glSecondaryColor3dEXT (void);
#define   gdk_gl_glSecondaryColor3dEXT(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3DEXTPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3dvEXT (const GLdouble *) */
GdkGLProc gdk_gl_get_glSecondaryColor3dvEXT (void);
#define   gdk_gl_glSecondaryColor3dvEXT(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3DVEXTPROC) (proc)) (v) )

/* void glSecondaryColor3fEXT (GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glSecondaryColor3fEXT (void);
#define   gdk_gl_glSecondaryColor3fEXT(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3FEXTPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3fvEXT (const GLfloat *) */
GdkGLProc gdk_gl_get_glSecondaryColor3fvEXT (void);
#define   gdk_gl_glSecondaryColor3fvEXT(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3FVEXTPROC) (proc)) (v) )

/* void glSecondaryColor3iEXT (GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glSecondaryColor3iEXT (void);
#define   gdk_gl_glSecondaryColor3iEXT(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3IEXTPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3ivEXT (const GLint *) */
GdkGLProc gdk_gl_get_glSecondaryColor3ivEXT (void);
#define   gdk_gl_glSecondaryColor3ivEXT(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3IVEXTPROC) (proc)) (v) )

/* void glSecondaryColor3sEXT (GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glSecondaryColor3sEXT (void);
#define   gdk_gl_glSecondaryColor3sEXT(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3SEXTPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3svEXT (const GLshort *) */
GdkGLProc gdk_gl_get_glSecondaryColor3svEXT (void);
#define   gdk_gl_glSecondaryColor3svEXT(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3SVEXTPROC) (proc)) (v) )

/* void glSecondaryColor3ubEXT (GLubyte, GLubyte, GLubyte) */
GdkGLProc gdk_gl_get_glSecondaryColor3ubEXT (void);
#define   gdk_gl_glSecondaryColor3ubEXT(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3UBEXTPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3ubvEXT (const GLubyte *) */
GdkGLProc gdk_gl_get_glSecondaryColor3ubvEXT (void);
#define   gdk_gl_glSecondaryColor3ubvEXT(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3UBVEXTPROC) (proc)) (v) )

/* void glSecondaryColor3uiEXT (GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glSecondaryColor3uiEXT (void);
#define   gdk_gl_glSecondaryColor3uiEXT(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3UIEXTPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3uivEXT (const GLuint *) */
GdkGLProc gdk_gl_get_glSecondaryColor3uivEXT (void);
#define   gdk_gl_glSecondaryColor3uivEXT(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3UIVEXTPROC) (proc)) (v) )

/* void glSecondaryColor3usEXT (GLushort, GLushort, GLushort) */
GdkGLProc gdk_gl_get_glSecondaryColor3usEXT (void);
#define   gdk_gl_glSecondaryColor3usEXT(proc, red, green, blue) \
  ( ((PFNGLSECONDARYCOLOR3USEXTPROC) (proc)) (red, green, blue) )

/* void glSecondaryColor3usvEXT (const GLushort *) */
GdkGLProc gdk_gl_get_glSecondaryColor3usvEXT (void);
#define   gdk_gl_glSecondaryColor3usvEXT(proc, v) \
  ( ((PFNGLSECONDARYCOLOR3USVEXTPROC) (proc)) (v) )

/* void glSecondaryColorPointerEXT (GLint, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glSecondaryColorPointerEXT (void);
#define   gdk_gl_glSecondaryColorPointerEXT(proc, size, type, stride, pointer) \
  ( ((PFNGLSECONDARYCOLORPOINTEREXTPROC) (proc)) (size, type, stride, pointer) )

/* 
 * GL_EXT_texture_perturb_normal
 */

/* void glTextureNormalEXT (GLenum) */
GdkGLProc gdk_gl_get_glTextureNormalEXT (void);
#define   gdk_gl_glTextureNormalEXT(proc, mode) \
  ( ((PFNGLTEXTURENORMALEXTPROC) (proc)) (mode) )

/* 
 * GL_EXT_multi_draw_arrays
 */

/* void glMultiDrawArraysEXT (GLenum, GLint *, GLsizei *, GLsizei) */
GdkGLProc gdk_gl_get_glMultiDrawArraysEXT (void);
#define   gdk_gl_glMultiDrawArraysEXT(proc, mode, first, count, primcount) \
  ( ((PFNGLMULTIDRAWARRAYSEXTPROC) (proc)) (mode, first, count, primcount) )

/* void glMultiDrawElementsEXT (GLenum, const GLsizei *, GLenum, const GLvoid* *, GLsizei) */
GdkGLProc gdk_gl_get_glMultiDrawElementsEXT (void);
#define   gdk_gl_glMultiDrawElementsEXT(proc, mode, count, type, indices, primcount) \
  ( ((PFNGLMULTIDRAWELEMENTSEXTPROC) (proc)) (mode, count, type, indices, primcount) )

/* 
 * GL_EXT_fog_coord
 */

/* void glFogCoordfEXT (GLfloat) */
GdkGLProc gdk_gl_get_glFogCoordfEXT (void);
#define   gdk_gl_glFogCoordfEXT(proc, coord) \
  ( ((PFNGLFOGCOORDFEXTPROC) (proc)) (coord) )

/* void glFogCoordfvEXT (const GLfloat *) */
GdkGLProc gdk_gl_get_glFogCoordfvEXT (void);
#define   gdk_gl_glFogCoordfvEXT(proc, coord) \
  ( ((PFNGLFOGCOORDFVEXTPROC) (proc)) (coord) )

/* void glFogCoorddEXT (GLdouble) */
GdkGLProc gdk_gl_get_glFogCoorddEXT (void);
#define   gdk_gl_glFogCoorddEXT(proc, coord) \
  ( ((PFNGLFOGCOORDDEXTPROC) (proc)) (coord) )

/* void glFogCoorddvEXT (const GLdouble *) */
GdkGLProc gdk_gl_get_glFogCoorddvEXT (void);
#define   gdk_gl_glFogCoorddvEXT(proc, coord) \
  ( ((PFNGLFOGCOORDDVEXTPROC) (proc)) (coord) )

/* void glFogCoordPointerEXT (GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glFogCoordPointerEXT (void);
#define   gdk_gl_glFogCoordPointerEXT(proc, type, stride, pointer) \
  ( ((PFNGLFOGCOORDPOINTEREXTPROC) (proc)) (type, stride, pointer) )

/* 
 * GL_EXT_coordinate_frame
 */

/* void glTangent3bEXT (GLbyte, GLbyte, GLbyte) */
GdkGLProc gdk_gl_get_glTangent3bEXT (void);
#define   gdk_gl_glTangent3bEXT(proc, tx, ty, tz) \
  ( ((PFNGLTANGENT3BEXTPROC) (proc)) (tx, ty, tz) )

/* void glTangent3bvEXT (const GLbyte *) */
GdkGLProc gdk_gl_get_glTangent3bvEXT (void);
#define   gdk_gl_glTangent3bvEXT(proc, v) \
  ( ((PFNGLTANGENT3BVEXTPROC) (proc)) (v) )

/* void glTangent3dEXT (GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glTangent3dEXT (void);
#define   gdk_gl_glTangent3dEXT(proc, tx, ty, tz) \
  ( ((PFNGLTANGENT3DEXTPROC) (proc)) (tx, ty, tz) )

/* void glTangent3dvEXT (const GLdouble *) */
GdkGLProc gdk_gl_get_glTangent3dvEXT (void);
#define   gdk_gl_glTangent3dvEXT(proc, v) \
  ( ((PFNGLTANGENT3DVEXTPROC) (proc)) (v) )

/* void glTangent3fEXT (GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glTangent3fEXT (void);
#define   gdk_gl_glTangent3fEXT(proc, tx, ty, tz) \
  ( ((PFNGLTANGENT3FEXTPROC) (proc)) (tx, ty, tz) )

/* void glTangent3fvEXT (const GLfloat *) */
GdkGLProc gdk_gl_get_glTangent3fvEXT (void);
#define   gdk_gl_glTangent3fvEXT(proc, v) \
  ( ((PFNGLTANGENT3FVEXTPROC) (proc)) (v) )

/* void glTangent3iEXT (GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glTangent3iEXT (void);
#define   gdk_gl_glTangent3iEXT(proc, tx, ty, tz) \
  ( ((PFNGLTANGENT3IEXTPROC) (proc)) (tx, ty, tz) )

/* void glTangent3ivEXT (const GLint *) */
GdkGLProc gdk_gl_get_glTangent3ivEXT (void);
#define   gdk_gl_glTangent3ivEXT(proc, v) \
  ( ((PFNGLTANGENT3IVEXTPROC) (proc)) (v) )

/* void glTangent3sEXT (GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glTangent3sEXT (void);
#define   gdk_gl_glTangent3sEXT(proc, tx, ty, tz) \
  ( ((PFNGLTANGENT3SEXTPROC) (proc)) (tx, ty, tz) )

/* void glTangent3svEXT (const GLshort *) */
GdkGLProc gdk_gl_get_glTangent3svEXT (void);
#define   gdk_gl_glTangent3svEXT(proc, v) \
  ( ((PFNGLTANGENT3SVEXTPROC) (proc)) (v) )

/* void glBinormal3bEXT (GLbyte, GLbyte, GLbyte) */
GdkGLProc gdk_gl_get_glBinormal3bEXT (void);
#define   gdk_gl_glBinormal3bEXT(proc, bx, by, bz) \
  ( ((PFNGLBINORMAL3BEXTPROC) (proc)) (bx, by, bz) )

/* void glBinormal3bvEXT (const GLbyte *) */
GdkGLProc gdk_gl_get_glBinormal3bvEXT (void);
#define   gdk_gl_glBinormal3bvEXT(proc, v) \
  ( ((PFNGLBINORMAL3BVEXTPROC) (proc)) (v) )

/* void glBinormal3dEXT (GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glBinormal3dEXT (void);
#define   gdk_gl_glBinormal3dEXT(proc, bx, by, bz) \
  ( ((PFNGLBINORMAL3DEXTPROC) (proc)) (bx, by, bz) )

/* void glBinormal3dvEXT (const GLdouble *) */
GdkGLProc gdk_gl_get_glBinormal3dvEXT (void);
#define   gdk_gl_glBinormal3dvEXT(proc, v) \
  ( ((PFNGLBINORMAL3DVEXTPROC) (proc)) (v) )

/* void glBinormal3fEXT (GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glBinormal3fEXT (void);
#define   gdk_gl_glBinormal3fEXT(proc, bx, by, bz) \
  ( ((PFNGLBINORMAL3FEXTPROC) (proc)) (bx, by, bz) )

/* void glBinormal3fvEXT (const GLfloat *) */
GdkGLProc gdk_gl_get_glBinormal3fvEXT (void);
#define   gdk_gl_glBinormal3fvEXT(proc, v) \
  ( ((PFNGLBINORMAL3FVEXTPROC) (proc)) (v) )

/* void glBinormal3iEXT (GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glBinormal3iEXT (void);
#define   gdk_gl_glBinormal3iEXT(proc, bx, by, bz) \
  ( ((PFNGLBINORMAL3IEXTPROC) (proc)) (bx, by, bz) )

/* void glBinormal3ivEXT (const GLint *) */
GdkGLProc gdk_gl_get_glBinormal3ivEXT (void);
#define   gdk_gl_glBinormal3ivEXT(proc, v) \
  ( ((PFNGLBINORMAL3IVEXTPROC) (proc)) (v) )

/* void glBinormal3sEXT (GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glBinormal3sEXT (void);
#define   gdk_gl_glBinormal3sEXT(proc, bx, by, bz) \
  ( ((PFNGLBINORMAL3SEXTPROC) (proc)) (bx, by, bz) )

/* void glBinormal3svEXT (const GLshort *) */
GdkGLProc gdk_gl_get_glBinormal3svEXT (void);
#define   gdk_gl_glBinormal3svEXT(proc, v) \
  ( ((PFNGLBINORMAL3SVEXTPROC) (proc)) (v) )

/* void glTangentPointerEXT (GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glTangentPointerEXT (void);
#define   gdk_gl_glTangentPointerEXT(proc, type, stride, pointer) \
  ( ((PFNGLTANGENTPOINTEREXTPROC) (proc)) (type, stride, pointer) )

/* void glBinormalPointerEXT (GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glBinormalPointerEXT (void);
#define   gdk_gl_glBinormalPointerEXT(proc, type, stride, pointer) \
  ( ((PFNGLBINORMALPOINTEREXTPROC) (proc)) (type, stride, pointer) )

/* 
 * GL_SUNX_constant_data
 */

/* void glFinishTextureSUNX (void) */
GdkGLProc gdk_gl_get_glFinishTextureSUNX (void);
#define   gdk_gl_glFinishTextureSUNX(proc) \
  ( ((PFNGLFINISHTEXTURESUNXPROC) (proc)) () )

/* 
 * GL_SUN_global_alpha
 */

/* void glGlobalAlphaFactorbSUN (GLbyte) */
GdkGLProc gdk_gl_get_glGlobalAlphaFactorbSUN (void);
#define   gdk_gl_glGlobalAlphaFactorbSUN(proc, factor) \
  ( ((PFNGLGLOBALALPHAFACTORBSUNPROC) (proc)) (factor) )

/* void glGlobalAlphaFactorsSUN (GLshort) */
GdkGLProc gdk_gl_get_glGlobalAlphaFactorsSUN (void);
#define   gdk_gl_glGlobalAlphaFactorsSUN(proc, factor) \
  ( ((PFNGLGLOBALALPHAFACTORSSUNPROC) (proc)) (factor) )

/* void glGlobalAlphaFactoriSUN (GLint) */
GdkGLProc gdk_gl_get_glGlobalAlphaFactoriSUN (void);
#define   gdk_gl_glGlobalAlphaFactoriSUN(proc, factor) \
  ( ((PFNGLGLOBALALPHAFACTORISUNPROC) (proc)) (factor) )

/* void glGlobalAlphaFactorfSUN (GLfloat) */
GdkGLProc gdk_gl_get_glGlobalAlphaFactorfSUN (void);
#define   gdk_gl_glGlobalAlphaFactorfSUN(proc, factor) \
  ( ((PFNGLGLOBALALPHAFACTORFSUNPROC) (proc)) (factor) )

/* void glGlobalAlphaFactordSUN (GLdouble) */
GdkGLProc gdk_gl_get_glGlobalAlphaFactordSUN (void);
#define   gdk_gl_glGlobalAlphaFactordSUN(proc, factor) \
  ( ((PFNGLGLOBALALPHAFACTORDSUNPROC) (proc)) (factor) )

/* void glGlobalAlphaFactorubSUN (GLubyte) */
GdkGLProc gdk_gl_get_glGlobalAlphaFactorubSUN (void);
#define   gdk_gl_glGlobalAlphaFactorubSUN(proc, factor) \
  ( ((PFNGLGLOBALALPHAFACTORUBSUNPROC) (proc)) (factor) )

/* void glGlobalAlphaFactorusSUN (GLushort) */
GdkGLProc gdk_gl_get_glGlobalAlphaFactorusSUN (void);
#define   gdk_gl_glGlobalAlphaFactorusSUN(proc, factor) \
  ( ((PFNGLGLOBALALPHAFACTORUSSUNPROC) (proc)) (factor) )

/* void glGlobalAlphaFactoruiSUN (GLuint) */
GdkGLProc gdk_gl_get_glGlobalAlphaFactoruiSUN (void);
#define   gdk_gl_glGlobalAlphaFactoruiSUN(proc, factor) \
  ( ((PFNGLGLOBALALPHAFACTORUISUNPROC) (proc)) (factor) )

/* 
 * GL_SUN_triangle_list
 */

/* void glReplacementCodeuiSUN (GLuint) */
GdkGLProc gdk_gl_get_glReplacementCodeuiSUN (void);
#define   gdk_gl_glReplacementCodeuiSUN(proc, code) \
  ( ((PFNGLREPLACEMENTCODEUISUNPROC) (proc)) (code) )

/* void glReplacementCodeusSUN (GLushort) */
GdkGLProc gdk_gl_get_glReplacementCodeusSUN (void);
#define   gdk_gl_glReplacementCodeusSUN(proc, code) \
  ( ((PFNGLREPLACEMENTCODEUSSUNPROC) (proc)) (code) )

/* void glReplacementCodeubSUN (GLubyte) */
GdkGLProc gdk_gl_get_glReplacementCodeubSUN (void);
#define   gdk_gl_glReplacementCodeubSUN(proc, code) \
  ( ((PFNGLREPLACEMENTCODEUBSUNPROC) (proc)) (code) )

/* void glReplacementCodeuivSUN (const GLuint *) */
GdkGLProc gdk_gl_get_glReplacementCodeuivSUN (void);
#define   gdk_gl_glReplacementCodeuivSUN(proc, code) \
  ( ((PFNGLREPLACEMENTCODEUIVSUNPROC) (proc)) (code) )

/* void glReplacementCodeusvSUN (const GLushort *) */
GdkGLProc gdk_gl_get_glReplacementCodeusvSUN (void);
#define   gdk_gl_glReplacementCodeusvSUN(proc, code) \
  ( ((PFNGLREPLACEMENTCODEUSVSUNPROC) (proc)) (code) )

/* void glReplacementCodeubvSUN (const GLubyte *) */
GdkGLProc gdk_gl_get_glReplacementCodeubvSUN (void);
#define   gdk_gl_glReplacementCodeubvSUN(proc, code) \
  ( ((PFNGLREPLACEMENTCODEUBVSUNPROC) (proc)) (code) )

/* void glReplacementCodePointerSUN (GLenum, GLsizei, const GLvoid* *) */
GdkGLProc gdk_gl_get_glReplacementCodePointerSUN (void);
#define   gdk_gl_glReplacementCodePointerSUN(proc, type, stride, pointer) \
  ( ((PFNGLREPLACEMENTCODEPOINTERSUNPROC) (proc)) (type, stride, pointer) )

/* 
 * GL_SUN_vertex
 */

/* void glColor4ubVertex2fSUN (GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glColor4ubVertex2fSUN (void);
#define   gdk_gl_glColor4ubVertex2fSUN(proc, r, g, b, a, x, y) \
  ( ((PFNGLCOLOR4UBVERTEX2FSUNPROC) (proc)) (r, g, b, a, x, y) )

/* void glColor4ubVertex2fvSUN (const GLubyte *, const GLfloat *) */
GdkGLProc gdk_gl_get_glColor4ubVertex2fvSUN (void);
#define   gdk_gl_glColor4ubVertex2fvSUN(proc, c, v) \
  ( ((PFNGLCOLOR4UBVERTEX2FVSUNPROC) (proc)) (c, v) )

/* void glColor4ubVertex3fSUN (GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glColor4ubVertex3fSUN (void);
#define   gdk_gl_glColor4ubVertex3fSUN(proc, r, g, b, a, x, y, z) \
  ( ((PFNGLCOLOR4UBVERTEX3FSUNPROC) (proc)) (r, g, b, a, x, y, z) )

/* void glColor4ubVertex3fvSUN (const GLubyte *, const GLfloat *) */
GdkGLProc gdk_gl_get_glColor4ubVertex3fvSUN (void);
#define   gdk_gl_glColor4ubVertex3fvSUN(proc, c, v) \
  ( ((PFNGLCOLOR4UBVERTEX3FVSUNPROC) (proc)) (c, v) )

/* void glColor3fVertex3fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glColor3fVertex3fSUN (void);
#define   gdk_gl_glColor3fVertex3fSUN(proc, r, g, b, x, y, z) \
  ( ((PFNGLCOLOR3FVERTEX3FSUNPROC) (proc)) (r, g, b, x, y, z) )

/* void glColor3fVertex3fvSUN (const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glColor3fVertex3fvSUN (void);
#define   gdk_gl_glColor3fVertex3fvSUN(proc, c, v) \
  ( ((PFNGLCOLOR3FVERTEX3FVSUNPROC) (proc)) (c, v) )

/* void glNormal3fVertex3fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glNormal3fVertex3fSUN (void);
#define   gdk_gl_glNormal3fVertex3fSUN(proc, nx, ny, nz, x, y, z) \
  ( ((PFNGLNORMAL3FVERTEX3FSUNPROC) (proc)) (nx, ny, nz, x, y, z) )

/* void glNormal3fVertex3fvSUN (const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glNormal3fVertex3fvSUN (void);
#define   gdk_gl_glNormal3fVertex3fvSUN(proc, n, v) \
  ( ((PFNGLNORMAL3FVERTEX3FVSUNPROC) (proc)) (n, v) )

/* void glColor4fNormal3fVertex3fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glColor4fNormal3fVertex3fSUN (void);
#define   gdk_gl_glColor4fNormal3fVertex3fSUN(proc, r, g, b, a, nx, ny, nz, x, y, z) \
  ( ((PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC) (proc)) (r, g, b, a, nx, ny, nz, x, y, z) )

/* void glColor4fNormal3fVertex3fvSUN (const GLfloat *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glColor4fNormal3fVertex3fvSUN (void);
#define   gdk_gl_glColor4fNormal3fVertex3fvSUN(proc, c, n, v) \
  ( ((PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (proc)) (c, n, v) )

/* void glTexCoord2fVertex3fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glTexCoord2fVertex3fSUN (void);
#define   gdk_gl_glTexCoord2fVertex3fSUN(proc, s, t, x, y, z) \
  ( ((PFNGLTEXCOORD2FVERTEX3FSUNPROC) (proc)) (s, t, x, y, z) )

/* void glTexCoord2fVertex3fvSUN (const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexCoord2fVertex3fvSUN (void);
#define   gdk_gl_glTexCoord2fVertex3fvSUN(proc, tc, v) \
  ( ((PFNGLTEXCOORD2FVERTEX3FVSUNPROC) (proc)) (tc, v) )

/* void glTexCoord4fVertex4fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glTexCoord4fVertex4fSUN (void);
#define   gdk_gl_glTexCoord4fVertex4fSUN(proc, s, t, p, q, x, y, z, w) \
  ( ((PFNGLTEXCOORD4FVERTEX4FSUNPROC) (proc)) (s, t, p, q, x, y, z, w) )

/* void glTexCoord4fVertex4fvSUN (const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexCoord4fVertex4fvSUN (void);
#define   gdk_gl_glTexCoord4fVertex4fvSUN(proc, tc, v) \
  ( ((PFNGLTEXCOORD4FVERTEX4FVSUNPROC) (proc)) (tc, v) )

/* void glTexCoord2fColor4ubVertex3fSUN (GLfloat, GLfloat, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glTexCoord2fColor4ubVertex3fSUN (void);
#define   gdk_gl_glTexCoord2fColor4ubVertex3fSUN(proc, s, t, r, g, b, a, x, y, z) \
  ( ((PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC) (proc)) (s, t, r, g, b, a, x, y, z) )

/* void glTexCoord2fColor4ubVertex3fvSUN (const GLfloat *, const GLubyte *, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexCoord2fColor4ubVertex3fvSUN (void);
#define   gdk_gl_glTexCoord2fColor4ubVertex3fvSUN(proc, tc, c, v) \
  ( ((PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC) (proc)) (tc, c, v) )

/* void glTexCoord2fColor3fVertex3fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glTexCoord2fColor3fVertex3fSUN (void);
#define   gdk_gl_glTexCoord2fColor3fVertex3fSUN(proc, s, t, r, g, b, x, y, z) \
  ( ((PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC) (proc)) (s, t, r, g, b, x, y, z) )

/* void glTexCoord2fColor3fVertex3fvSUN (const GLfloat *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexCoord2fColor3fVertex3fvSUN (void);
#define   gdk_gl_glTexCoord2fColor3fVertex3fvSUN(proc, tc, c, v) \
  ( ((PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC) (proc)) (tc, c, v) )

/* void glTexCoord2fNormal3fVertex3fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glTexCoord2fNormal3fVertex3fSUN (void);
#define   gdk_gl_glTexCoord2fNormal3fVertex3fSUN(proc, s, t, nx, ny, nz, x, y, z) \
  ( ((PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC) (proc)) (s, t, nx, ny, nz, x, y, z) )

/* void glTexCoord2fNormal3fVertex3fvSUN (const GLfloat *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexCoord2fNormal3fVertex3fvSUN (void);
#define   gdk_gl_glTexCoord2fNormal3fVertex3fvSUN(proc, tc, n, v) \
  ( ((PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) (proc)) (tc, n, v) )

/* void glTexCoord2fColor4fNormal3fVertex3fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glTexCoord2fColor4fNormal3fVertex3fSUN (void);
#define   gdk_gl_glTexCoord2fColor4fNormal3fVertex3fSUN(proc, s, t, r, g, b, a, nx, ny, nz, x, y, z) \
  ( ((PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) (proc)) (s, t, r, g, b, a, nx, ny, nz, x, y, z) )

/* void glTexCoord2fColor4fNormal3fVertex3fvSUN (const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexCoord2fColor4fNormal3fVertex3fvSUN (void);
#define   gdk_gl_glTexCoord2fColor4fNormal3fVertex3fvSUN(proc, tc, c, n, v) \
  ( ((PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (proc)) (tc, c, n, v) )

/* void glTexCoord4fColor4fNormal3fVertex4fSUN (GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glTexCoord4fColor4fNormal3fVertex4fSUN (void);
#define   gdk_gl_glTexCoord4fColor4fNormal3fVertex4fSUN(proc, s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w) \
  ( ((PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC) (proc)) (s, t, p, q, r, g, b, a, nx, ny, nz, x, y, z, w) )

/* void glTexCoord4fColor4fNormal3fVertex4fvSUN (const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexCoord4fColor4fNormal3fVertex4fvSUN (void);
#define   gdk_gl_glTexCoord4fColor4fNormal3fVertex4fvSUN(proc, tc, c, n, v) \
  ( ((PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC) (proc)) (tc, c, n, v) )

/* void glReplacementCodeuiVertex3fSUN (GLuint, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glReplacementCodeuiVertex3fSUN (void);
#define   gdk_gl_glReplacementCodeuiVertex3fSUN(proc, rc, x, y, z) \
  ( ((PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC) (proc)) (rc, x, y, z) )

/* void glReplacementCodeuiVertex3fvSUN (const GLuint *, const GLfloat *) */
GdkGLProc gdk_gl_get_glReplacementCodeuiVertex3fvSUN (void);
#define   gdk_gl_glReplacementCodeuiVertex3fvSUN(proc, rc, v) \
  ( ((PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC) (proc)) (rc, v) )

/* void glReplacementCodeuiColor4ubVertex3fSUN (GLuint, GLubyte, GLubyte, GLubyte, GLubyte, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glReplacementCodeuiColor4ubVertex3fSUN (void);
#define   gdk_gl_glReplacementCodeuiColor4ubVertex3fSUN(proc, rc, r, g, b, a, x, y, z) \
  ( ((PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC) (proc)) (rc, r, g, b, a, x, y, z) )

/* void glReplacementCodeuiColor4ubVertex3fvSUN (const GLuint *, const GLubyte *, const GLfloat *) */
GdkGLProc gdk_gl_get_glReplacementCodeuiColor4ubVertex3fvSUN (void);
#define   gdk_gl_glReplacementCodeuiColor4ubVertex3fvSUN(proc, rc, c, v) \
  ( ((PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC) (proc)) (rc, c, v) )

/* void glReplacementCodeuiColor3fVertex3fSUN (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glReplacementCodeuiColor3fVertex3fSUN (void);
#define   gdk_gl_glReplacementCodeuiColor3fVertex3fSUN(proc, rc, r, g, b, x, y, z) \
  ( ((PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC) (proc)) (rc, r, g, b, x, y, z) )

/* void glReplacementCodeuiColor3fVertex3fvSUN (const GLuint *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glReplacementCodeuiColor3fVertex3fvSUN (void);
#define   gdk_gl_glReplacementCodeuiColor3fVertex3fvSUN(proc, rc, c, v) \
  ( ((PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC) (proc)) (rc, c, v) )

/* void glReplacementCodeuiNormal3fVertex3fSUN (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glReplacementCodeuiNormal3fVertex3fSUN (void);
#define   gdk_gl_glReplacementCodeuiNormal3fVertex3fSUN(proc, rc, nx, ny, nz, x, y, z) \
  ( ((PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC) (proc)) (rc, nx, ny, nz, x, y, z) )

/* void glReplacementCodeuiNormal3fVertex3fvSUN (const GLuint *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glReplacementCodeuiNormal3fVertex3fvSUN (void);
#define   gdk_gl_glReplacementCodeuiNormal3fVertex3fvSUN(proc, rc, n, v) \
  ( ((PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC) (proc)) (rc, n, v) )

/* void glReplacementCodeuiColor4fNormal3fVertex3fSUN (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glReplacementCodeuiColor4fNormal3fVertex3fSUN (void);
#define   gdk_gl_glReplacementCodeuiColor4fNormal3fVertex3fSUN(proc, rc, r, g, b, a, nx, ny, nz, x, y, z) \
  ( ((PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC) (proc)) (rc, r, g, b, a, nx, ny, nz, x, y, z) )

/* void glReplacementCodeuiColor4fNormal3fVertex3fvSUN (const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glReplacementCodeuiColor4fNormal3fVertex3fvSUN (void);
#define   gdk_gl_glReplacementCodeuiColor4fNormal3fVertex3fvSUN(proc, rc, c, n, v) \
  ( ((PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC) (proc)) (rc, c, n, v) )

/* void glReplacementCodeuiTexCoord2fVertex3fSUN (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glReplacementCodeuiTexCoord2fVertex3fSUN (void);
#define   gdk_gl_glReplacementCodeuiTexCoord2fVertex3fSUN(proc, rc, s, t, x, y, z) \
  ( ((PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC) (proc)) (rc, s, t, x, y, z) )

/* void glReplacementCodeuiTexCoord2fVertex3fvSUN (const GLuint *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glReplacementCodeuiTexCoord2fVertex3fvSUN (void);
#define   gdk_gl_glReplacementCodeuiTexCoord2fVertex3fvSUN(proc, rc, tc, v) \
  ( ((PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC) (proc)) (rc, tc, v) )

/* void glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN (void);
#define   gdk_gl_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(proc, rc, s, t, nx, ny, nz, x, y, z) \
  ( ((PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC) (proc)) (rc, s, t, nx, ny, nz, x, y, z) )

/* void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN (const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN (void);
#define   gdk_gl_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(proc, rc, tc, n, v) \
  ( ((PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC) (proc)) (rc, tc, n, v) )

/* void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN (GLuint, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN (void);
#define   gdk_gl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(proc, rc, s, t, r, g, b, a, nx, ny, nz, x, y, z) \
  ( ((PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC) (proc)) (rc, s, t, r, g, b, a, nx, ny, nz, x, y, z) )

/* void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN (const GLuint *, const GLfloat *, const GLfloat *, const GLfloat *, const GLfloat *) */
GdkGLProc gdk_gl_get_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN (void);
#define   gdk_gl_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(proc, rc, tc, c, n, v) \
  ( ((PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC) (proc)) (rc, tc, c, n, v) )

/* 
 * GL_EXT_blend_func_separate
 */

/* void glBlendFuncSeparateEXT (GLenum, GLenum, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glBlendFuncSeparateEXT (void);
#define   gdk_gl_glBlendFuncSeparateEXT(proc, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) \
  ( ((PFNGLBLENDFUNCSEPARATEEXTPROC) (proc)) (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) )

/* 
 * GL_INGR_blend_func_separate
 */

/* void glBlendFuncSeparateINGR (GLenum, GLenum, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glBlendFuncSeparateINGR (void);
#define   gdk_gl_glBlendFuncSeparateINGR(proc, sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) \
  ( ((PFNGLBLENDFUNCSEPARATEINGRPROC) (proc)) (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) )

/* 
 * GL_EXT_vertex_weighting
 */

/* void glVertexWeightfEXT (GLfloat) */
GdkGLProc gdk_gl_get_glVertexWeightfEXT (void);
#define   gdk_gl_glVertexWeightfEXT(proc, weight) \
  ( ((PFNGLVERTEXWEIGHTFEXTPROC) (proc)) (weight) )

/* void glVertexWeightfvEXT (const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexWeightfvEXT (void);
#define   gdk_gl_glVertexWeightfvEXT(proc, weight) \
  ( ((PFNGLVERTEXWEIGHTFVEXTPROC) (proc)) (weight) )

/* void glVertexWeightPointerEXT (GLsizei, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glVertexWeightPointerEXT (void);
#define   gdk_gl_glVertexWeightPointerEXT(proc, size, type, stride, pointer) \
  ( ((PFNGLVERTEXWEIGHTPOINTEREXTPROC) (proc)) (size, type, stride, pointer) )

/* 
 * GL_NV_vertex_array_range
 */

/* void glFlushVertexArrayRangeNV (void) */
GdkGLProc gdk_gl_get_glFlushVertexArrayRangeNV (void);
#define   gdk_gl_glFlushVertexArrayRangeNV(proc) \
  ( ((PFNGLFLUSHVERTEXARRAYRANGENVPROC) (proc)) () )

/* void glVertexArrayRangeNV (GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glVertexArrayRangeNV (void);
#define   gdk_gl_glVertexArrayRangeNV(proc, length, pointer) \
  ( ((PFNGLVERTEXARRAYRANGENVPROC) (proc)) (length, pointer) )

/* 
 * GL_NV_register_combiners
 */

/* void glCombinerParameterfvNV (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glCombinerParameterfvNV (void);
#define   gdk_gl_glCombinerParameterfvNV(proc, pname, params) \
  ( ((PFNGLCOMBINERPARAMETERFVNVPROC) (proc)) (pname, params) )

/* void glCombinerParameterfNV (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glCombinerParameterfNV (void);
#define   gdk_gl_glCombinerParameterfNV(proc, pname, param) \
  ( ((PFNGLCOMBINERPARAMETERFNVPROC) (proc)) (pname, param) )

/* void glCombinerParameterivNV (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glCombinerParameterivNV (void);
#define   gdk_gl_glCombinerParameterivNV(proc, pname, params) \
  ( ((PFNGLCOMBINERPARAMETERIVNVPROC) (proc)) (pname, params) )

/* void glCombinerParameteriNV (GLenum, GLint) */
GdkGLProc gdk_gl_get_glCombinerParameteriNV (void);
#define   gdk_gl_glCombinerParameteriNV(proc, pname, param) \
  ( ((PFNGLCOMBINERPARAMETERINVPROC) (proc)) (pname, param) )

/* void glCombinerInputNV (GLenum, GLenum, GLenum, GLenum, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glCombinerInputNV (void);
#define   gdk_gl_glCombinerInputNV(proc, stage, portion, variable, input, mapping, componentUsage) \
  ( ((PFNGLCOMBINERINPUTNVPROC) (proc)) (stage, portion, variable, input, mapping, componentUsage) )

/* void glCombinerOutputNV (GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLenum, GLboolean, GLboolean, GLboolean) */
GdkGLProc gdk_gl_get_glCombinerOutputNV (void);
#define   gdk_gl_glCombinerOutputNV(proc, stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum) \
  ( ((PFNGLCOMBINEROUTPUTNVPROC) (proc)) (stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum) )

/* void glFinalCombinerInputNV (GLenum, GLenum, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glFinalCombinerInputNV (void);
#define   gdk_gl_glFinalCombinerInputNV(proc, variable, input, mapping, componentUsage) \
  ( ((PFNGLFINALCOMBINERINPUTNVPROC) (proc)) (variable, input, mapping, componentUsage) )

/* void glGetCombinerInputParameterfvNV (GLenum, GLenum, GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetCombinerInputParameterfvNV (void);
#define   gdk_gl_glGetCombinerInputParameterfvNV(proc, stage, portion, variable, pname, params) \
  ( ((PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC) (proc)) (stage, portion, variable, pname, params) )

/* void glGetCombinerInputParameterivNV (GLenum, GLenum, GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetCombinerInputParameterivNV (void);
#define   gdk_gl_glGetCombinerInputParameterivNV(proc, stage, portion, variable, pname, params) \
  ( ((PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC) (proc)) (stage, portion, variable, pname, params) )

/* void glGetCombinerOutputParameterfvNV (GLenum, GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetCombinerOutputParameterfvNV (void);
#define   gdk_gl_glGetCombinerOutputParameterfvNV(proc, stage, portion, pname, params) \
  ( ((PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC) (proc)) (stage, portion, pname, params) )

/* void glGetCombinerOutputParameterivNV (GLenum, GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetCombinerOutputParameterivNV (void);
#define   gdk_gl_glGetCombinerOutputParameterivNV(proc, stage, portion, pname, params) \
  ( ((PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC) (proc)) (stage, portion, pname, params) )

/* void glGetFinalCombinerInputParameterfvNV (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetFinalCombinerInputParameterfvNV (void);
#define   gdk_gl_glGetFinalCombinerInputParameterfvNV(proc, variable, pname, params) \
  ( ((PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC) (proc)) (variable, pname, params) )

/* void glGetFinalCombinerInputParameterivNV (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetFinalCombinerInputParameterivNV (void);
#define   gdk_gl_glGetFinalCombinerInputParameterivNV(proc, variable, pname, params) \
  ( ((PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC) (proc)) (variable, pname, params) )

/* 
 * GL_MESA_resize_buffers
 */

/* void glResizeBuffersMESA (void) */
GdkGLProc gdk_gl_get_glResizeBuffersMESA (void);
#define   gdk_gl_glResizeBuffersMESA(proc) \
  ( ((PFNGLRESIZEBUFFERSMESAPROC) (proc)) () )

/* 
 * GL_MESA_window_pos
 */

/* void glWindowPos2dMESA (GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glWindowPos2dMESA (void);
#define   gdk_gl_glWindowPos2dMESA(proc, x, y) \
  ( ((PFNGLWINDOWPOS2DMESAPROC) (proc)) (x, y) )

/* void glWindowPos2dvMESA (const GLdouble *) */
GdkGLProc gdk_gl_get_glWindowPos2dvMESA (void);
#define   gdk_gl_glWindowPos2dvMESA(proc, v) \
  ( ((PFNGLWINDOWPOS2DVMESAPROC) (proc)) (v) )

/* void glWindowPos2fMESA (GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glWindowPos2fMESA (void);
#define   gdk_gl_glWindowPos2fMESA(proc, x, y) \
  ( ((PFNGLWINDOWPOS2FMESAPROC) (proc)) (x, y) )

/* void glWindowPos2fvMESA (const GLfloat *) */
GdkGLProc gdk_gl_get_glWindowPos2fvMESA (void);
#define   gdk_gl_glWindowPos2fvMESA(proc, v) \
  ( ((PFNGLWINDOWPOS2FVMESAPROC) (proc)) (v) )

/* void glWindowPos2iMESA (GLint, GLint) */
GdkGLProc gdk_gl_get_glWindowPos2iMESA (void);
#define   gdk_gl_glWindowPos2iMESA(proc, x, y) \
  ( ((PFNGLWINDOWPOS2IMESAPROC) (proc)) (x, y) )

/* void glWindowPos2ivMESA (const GLint *) */
GdkGLProc gdk_gl_get_glWindowPos2ivMESA (void);
#define   gdk_gl_glWindowPos2ivMESA(proc, v) \
  ( ((PFNGLWINDOWPOS2IVMESAPROC) (proc)) (v) )

/* void glWindowPos2sMESA (GLshort, GLshort) */
GdkGLProc gdk_gl_get_glWindowPos2sMESA (void);
#define   gdk_gl_glWindowPos2sMESA(proc, x, y) \
  ( ((PFNGLWINDOWPOS2SMESAPROC) (proc)) (x, y) )

/* void glWindowPos2svMESA (const GLshort *) */
GdkGLProc gdk_gl_get_glWindowPos2svMESA (void);
#define   gdk_gl_glWindowPos2svMESA(proc, v) \
  ( ((PFNGLWINDOWPOS2SVMESAPROC) (proc)) (v) )

/* void glWindowPos3dMESA (GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glWindowPos3dMESA (void);
#define   gdk_gl_glWindowPos3dMESA(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3DMESAPROC) (proc)) (x, y, z) )

/* void glWindowPos3dvMESA (const GLdouble *) */
GdkGLProc gdk_gl_get_glWindowPos3dvMESA (void);
#define   gdk_gl_glWindowPos3dvMESA(proc, v) \
  ( ((PFNGLWINDOWPOS3DVMESAPROC) (proc)) (v) )

/* void glWindowPos3fMESA (GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glWindowPos3fMESA (void);
#define   gdk_gl_glWindowPos3fMESA(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3FMESAPROC) (proc)) (x, y, z) )

/* void glWindowPos3fvMESA (const GLfloat *) */
GdkGLProc gdk_gl_get_glWindowPos3fvMESA (void);
#define   gdk_gl_glWindowPos3fvMESA(proc, v) \
  ( ((PFNGLWINDOWPOS3FVMESAPROC) (proc)) (v) )

/* void glWindowPos3iMESA (GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glWindowPos3iMESA (void);
#define   gdk_gl_glWindowPos3iMESA(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3IMESAPROC) (proc)) (x, y, z) )

/* void glWindowPos3ivMESA (const GLint *) */
GdkGLProc gdk_gl_get_glWindowPos3ivMESA (void);
#define   gdk_gl_glWindowPos3ivMESA(proc, v) \
  ( ((PFNGLWINDOWPOS3IVMESAPROC) (proc)) (v) )

/* void glWindowPos3sMESA (GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glWindowPos3sMESA (void);
#define   gdk_gl_glWindowPos3sMESA(proc, x, y, z) \
  ( ((PFNGLWINDOWPOS3SMESAPROC) (proc)) (x, y, z) )

/* void glWindowPos3svMESA (const GLshort *) */
GdkGLProc gdk_gl_get_glWindowPos3svMESA (void);
#define   gdk_gl_glWindowPos3svMESA(proc, v) \
  ( ((PFNGLWINDOWPOS3SVMESAPROC) (proc)) (v) )

/* void glWindowPos4dMESA (GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glWindowPos4dMESA (void);
#define   gdk_gl_glWindowPos4dMESA(proc, x, y, z, w) \
  ( ((PFNGLWINDOWPOS4DMESAPROC) (proc)) (x, y, z, w) )

/* void glWindowPos4dvMESA (const GLdouble *) */
GdkGLProc gdk_gl_get_glWindowPos4dvMESA (void);
#define   gdk_gl_glWindowPos4dvMESA(proc, v) \
  ( ((PFNGLWINDOWPOS4DVMESAPROC) (proc)) (v) )

/* void glWindowPos4fMESA (GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glWindowPos4fMESA (void);
#define   gdk_gl_glWindowPos4fMESA(proc, x, y, z, w) \
  ( ((PFNGLWINDOWPOS4FMESAPROC) (proc)) (x, y, z, w) )

/* void glWindowPos4fvMESA (const GLfloat *) */
GdkGLProc gdk_gl_get_glWindowPos4fvMESA (void);
#define   gdk_gl_glWindowPos4fvMESA(proc, v) \
  ( ((PFNGLWINDOWPOS4FVMESAPROC) (proc)) (v) )

/* void glWindowPos4iMESA (GLint, GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glWindowPos4iMESA (void);
#define   gdk_gl_glWindowPos4iMESA(proc, x, y, z, w) \
  ( ((PFNGLWINDOWPOS4IMESAPROC) (proc)) (x, y, z, w) )

/* void glWindowPos4ivMESA (const GLint *) */
GdkGLProc gdk_gl_get_glWindowPos4ivMESA (void);
#define   gdk_gl_glWindowPos4ivMESA(proc, v) \
  ( ((PFNGLWINDOWPOS4IVMESAPROC) (proc)) (v) )

/* void glWindowPos4sMESA (GLshort, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glWindowPos4sMESA (void);
#define   gdk_gl_glWindowPos4sMESA(proc, x, y, z, w) \
  ( ((PFNGLWINDOWPOS4SMESAPROC) (proc)) (x, y, z, w) )

/* void glWindowPos4svMESA (const GLshort *) */
GdkGLProc gdk_gl_get_glWindowPos4svMESA (void);
#define   gdk_gl_glWindowPos4svMESA(proc, v) \
  ( ((PFNGLWINDOWPOS4SVMESAPROC) (proc)) (v) )

/* 
 * GL_IBM_multimode_draw_arrays
 */

/* void glMultiModeDrawArraysIBM (GLenum, const GLint *, const GLsizei *, GLsizei, GLint) */
GdkGLProc gdk_gl_get_glMultiModeDrawArraysIBM (void);
#define   gdk_gl_glMultiModeDrawArraysIBM(proc, mode, first, count, primcount, modestride) \
  ( ((PFNGLMULTIMODEDRAWARRAYSIBMPROC) (proc)) (mode, first, count, primcount, modestride) )

/* void glMultiModeDrawElementsIBM (const GLenum *, const GLsizei *, GLenum, const GLvoid* *, GLsizei, GLint) */
GdkGLProc gdk_gl_get_glMultiModeDrawElementsIBM (void);
#define   gdk_gl_glMultiModeDrawElementsIBM(proc, mode, count, type, indices, primcount, modestride) \
  ( ((PFNGLMULTIMODEDRAWELEMENTSIBMPROC) (proc)) (mode, count, type, indices, primcount, modestride) )

/* 
 * GL_IBM_vertex_array_lists
 */

/* void glColorPointerListIBM (GLint, GLenum, GLint, const GLvoid* *, GLint) */
GdkGLProc gdk_gl_get_glColorPointerListIBM (void);
#define   gdk_gl_glColorPointerListIBM(proc, size, type, stride, pointer, ptrstride) \
  ( ((PFNGLCOLORPOINTERLISTIBMPROC) (proc)) (size, type, stride, pointer, ptrstride) )

/* void glSecondaryColorPointerListIBM (GLint, GLenum, GLint, const GLvoid* *, GLint) */
GdkGLProc gdk_gl_get_glSecondaryColorPointerListIBM (void);
#define   gdk_gl_glSecondaryColorPointerListIBM(proc, size, type, stride, pointer, ptrstride) \
  ( ((PFNGLSECONDARYCOLORPOINTERLISTIBMPROC) (proc)) (size, type, stride, pointer, ptrstride) )

/* void glEdgeFlagPointerListIBM (GLint, const GLboolean* *, GLint) */
GdkGLProc gdk_gl_get_glEdgeFlagPointerListIBM (void);
#define   gdk_gl_glEdgeFlagPointerListIBM(proc, stride, pointer, ptrstride) \
  ( ((PFNGLEDGEFLAGPOINTERLISTIBMPROC) (proc)) (stride, pointer, ptrstride) )

/* void glFogCoordPointerListIBM (GLenum, GLint, const GLvoid* *, GLint) */
GdkGLProc gdk_gl_get_glFogCoordPointerListIBM (void);
#define   gdk_gl_glFogCoordPointerListIBM(proc, type, stride, pointer, ptrstride) \
  ( ((PFNGLFOGCOORDPOINTERLISTIBMPROC) (proc)) (type, stride, pointer, ptrstride) )

/* void glIndexPointerListIBM (GLenum, GLint, const GLvoid* *, GLint) */
GdkGLProc gdk_gl_get_glIndexPointerListIBM (void);
#define   gdk_gl_glIndexPointerListIBM(proc, type, stride, pointer, ptrstride) \
  ( ((PFNGLINDEXPOINTERLISTIBMPROC) (proc)) (type, stride, pointer, ptrstride) )

/* void glNormalPointerListIBM (GLenum, GLint, const GLvoid* *, GLint) */
GdkGLProc gdk_gl_get_glNormalPointerListIBM (void);
#define   gdk_gl_glNormalPointerListIBM(proc, type, stride, pointer, ptrstride) \
  ( ((PFNGLNORMALPOINTERLISTIBMPROC) (proc)) (type, stride, pointer, ptrstride) )

/* void glTexCoordPointerListIBM (GLint, GLenum, GLint, const GLvoid* *, GLint) */
GdkGLProc gdk_gl_get_glTexCoordPointerListIBM (void);
#define   gdk_gl_glTexCoordPointerListIBM(proc, size, type, stride, pointer, ptrstride) \
  ( ((PFNGLTEXCOORDPOINTERLISTIBMPROC) (proc)) (size, type, stride, pointer, ptrstride) )

/* void glVertexPointerListIBM (GLint, GLenum, GLint, const GLvoid* *, GLint) */
GdkGLProc gdk_gl_get_glVertexPointerListIBM (void);
#define   gdk_gl_glVertexPointerListIBM(proc, size, type, stride, pointer, ptrstride) \
  ( ((PFNGLVERTEXPOINTERLISTIBMPROC) (proc)) (size, type, stride, pointer, ptrstride) )

/* 
 * GL_3DFX_tbuffer
 */

/* void glTbufferMask3DFX (GLuint) */
GdkGLProc gdk_gl_get_glTbufferMask3DFX (void);
#define   gdk_gl_glTbufferMask3DFX(proc, mask) \
  ( ((PFNGLTBUFFERMASK3DFXPROC) (proc)) (mask) )

/* 
 * GL_EXT_multisample
 */

/* void glSampleMaskEXT (GLclampf, GLboolean) */
GdkGLProc gdk_gl_get_glSampleMaskEXT (void);
#define   gdk_gl_glSampleMaskEXT(proc, value, invert) \
  ( ((PFNGLSAMPLEMASKEXTPROC) (proc)) (value, invert) )

/* void glSamplePatternEXT (GLenum) */
GdkGLProc gdk_gl_get_glSamplePatternEXT (void);
#define   gdk_gl_glSamplePatternEXT(proc, pattern) \
  ( ((PFNGLSAMPLEPATTERNEXTPROC) (proc)) (pattern) )

/* 
 * GL_SGIS_texture_color_mask
 */

/* void glTextureColorMaskSGIS (GLboolean, GLboolean, GLboolean, GLboolean) */
GdkGLProc gdk_gl_get_glTextureColorMaskSGIS (void);
#define   gdk_gl_glTextureColorMaskSGIS(proc, red, green, blue, alpha) \
  ( ((PFNGLTEXTURECOLORMASKSGISPROC) (proc)) (red, green, blue, alpha) )

/* 
 * GL_SGIX_igloo_interface
 */

/* void glIglooInterfaceSGIX (GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glIglooInterfaceSGIX (void);
#define   gdk_gl_glIglooInterfaceSGIX(proc, pname, params) \
  ( ((PFNGLIGLOOINTERFACESGIXPROC) (proc)) (pname, params) )

/* 
 * GL_NV_fence
 */

/* void glDeleteFencesNV (GLsizei, const GLuint *) */
GdkGLProc gdk_gl_get_glDeleteFencesNV (void);
#define   gdk_gl_glDeleteFencesNV(proc, n, fences) \
  ( ((PFNGLDELETEFENCESNVPROC) (proc)) (n, fences) )

/* void glGenFencesNV (GLsizei, GLuint *) */
GdkGLProc gdk_gl_get_glGenFencesNV (void);
#define   gdk_gl_glGenFencesNV(proc, n, fences) \
  ( ((PFNGLGENFENCESNVPROC) (proc)) (n, fences) )

/* GLboolean glIsFenceNV (GLuint) */
GdkGLProc gdk_gl_get_glIsFenceNV (void);
#define   gdk_gl_glIsFenceNV(proc, fence) \
  ( ((PFNGLISFENCENVPROC) (proc)) (fence) )

/* GLboolean glTestFenceNV (GLuint) */
GdkGLProc gdk_gl_get_glTestFenceNV (void);
#define   gdk_gl_glTestFenceNV(proc, fence) \
  ( ((PFNGLTESTFENCENVPROC) (proc)) (fence) )

/* void glGetFenceivNV (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetFenceivNV (void);
#define   gdk_gl_glGetFenceivNV(proc, fence, pname, params) \
  ( ((PFNGLGETFENCEIVNVPROC) (proc)) (fence, pname, params) )

/* void glFinishFenceNV (GLuint) */
GdkGLProc gdk_gl_get_glFinishFenceNV (void);
#define   gdk_gl_glFinishFenceNV(proc, fence) \
  ( ((PFNGLFINISHFENCENVPROC) (proc)) (fence) )

/* void glSetFenceNV (GLuint, GLenum) */
GdkGLProc gdk_gl_get_glSetFenceNV (void);
#define   gdk_gl_glSetFenceNV(proc, fence, condition) \
  ( ((PFNGLSETFENCENVPROC) (proc)) (fence, condition) )

/* 
 * GL_NV_evaluators
 */

/* void glMapControlPointsNV (GLenum, GLuint, GLenum, GLsizei, GLsizei, GLint, GLint, GLboolean, const GLvoid *) */
GdkGLProc gdk_gl_get_glMapControlPointsNV (void);
#define   gdk_gl_glMapControlPointsNV(proc, target, index, type, ustride, vstride, uorder, vorder, packed, points) \
  ( ((PFNGLMAPCONTROLPOINTSNVPROC) (proc)) (target, index, type, ustride, vstride, uorder, vorder, packed, points) )

/* void glMapParameterivNV (GLenum, GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glMapParameterivNV (void);
#define   gdk_gl_glMapParameterivNV(proc, target, pname, params) \
  ( ((PFNGLMAPPARAMETERIVNVPROC) (proc)) (target, pname, params) )

/* void glMapParameterfvNV (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glMapParameterfvNV (void);
#define   gdk_gl_glMapParameterfvNV(proc, target, pname, params) \
  ( ((PFNGLMAPPARAMETERFVNVPROC) (proc)) (target, pname, params) )

/* void glGetMapControlPointsNV (GLenum, GLuint, GLenum, GLsizei, GLsizei, GLboolean, GLvoid *) */
GdkGLProc gdk_gl_get_glGetMapControlPointsNV (void);
#define   gdk_gl_glGetMapControlPointsNV(proc, target, index, type, ustride, vstride, packed, points) \
  ( ((PFNGLGETMAPCONTROLPOINTSNVPROC) (proc)) (target, index, type, ustride, vstride, packed, points) )

/* void glGetMapParameterivNV (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetMapParameterivNV (void);
#define   gdk_gl_glGetMapParameterivNV(proc, target, pname, params) \
  ( ((PFNGLGETMAPPARAMETERIVNVPROC) (proc)) (target, pname, params) )

/* void glGetMapParameterfvNV (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetMapParameterfvNV (void);
#define   gdk_gl_glGetMapParameterfvNV(proc, target, pname, params) \
  ( ((PFNGLGETMAPPARAMETERFVNVPROC) (proc)) (target, pname, params) )

/* void glGetMapAttribParameterivNV (GLenum, GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetMapAttribParameterivNV (void);
#define   gdk_gl_glGetMapAttribParameterivNV(proc, target, index, pname, params) \
  ( ((PFNGLGETMAPATTRIBPARAMETERIVNVPROC) (proc)) (target, index, pname, params) )

/* void glGetMapAttribParameterfvNV (GLenum, GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetMapAttribParameterfvNV (void);
#define   gdk_gl_glGetMapAttribParameterfvNV(proc, target, index, pname, params) \
  ( ((PFNGLGETMAPATTRIBPARAMETERFVNVPROC) (proc)) (target, index, pname, params) )

/* void glEvalMapsNV (GLenum, GLenum) */
GdkGLProc gdk_gl_get_glEvalMapsNV (void);
#define   gdk_gl_glEvalMapsNV(proc, target, mode) \
  ( ((PFNGLEVALMAPSNVPROC) (proc)) (target, mode) )

/* 
 * GL_NV_register_combiners2
 */

/* void glCombinerStageParameterfvNV (GLenum, GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glCombinerStageParameterfvNV (void);
#define   gdk_gl_glCombinerStageParameterfvNV(proc, stage, pname, params) \
  ( ((PFNGLCOMBINERSTAGEPARAMETERFVNVPROC) (proc)) (stage, pname, params) )

/* void glGetCombinerStageParameterfvNV (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetCombinerStageParameterfvNV (void);
#define   gdk_gl_glGetCombinerStageParameterfvNV(proc, stage, pname, params) \
  ( ((PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC) (proc)) (stage, pname, params) )

/* 
 * GL_NV_vertex_program
 */

/* GLboolean glAreProgramsResidentNV (GLsizei, const GLuint *, GLboolean *) */
GdkGLProc gdk_gl_get_glAreProgramsResidentNV (void);
#define   gdk_gl_glAreProgramsResidentNV(proc, n, programs, residences) \
  ( ((PFNGLAREPROGRAMSRESIDENTNVPROC) (proc)) (n, programs, residences) )

/* void glBindProgramNV (GLenum, GLuint) */
GdkGLProc gdk_gl_get_glBindProgramNV (void);
#define   gdk_gl_glBindProgramNV(proc, target, id) \
  ( ((PFNGLBINDPROGRAMNVPROC) (proc)) (target, id) )

/* void glDeleteProgramsNV (GLsizei, const GLuint *) */
GdkGLProc gdk_gl_get_glDeleteProgramsNV (void);
#define   gdk_gl_glDeleteProgramsNV(proc, n, programs) \
  ( ((PFNGLDELETEPROGRAMSNVPROC) (proc)) (n, programs) )

/* void glExecuteProgramNV (GLenum, GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glExecuteProgramNV (void);
#define   gdk_gl_glExecuteProgramNV(proc, target, id, params) \
  ( ((PFNGLEXECUTEPROGRAMNVPROC) (proc)) (target, id, params) )

/* void glGenProgramsNV (GLsizei, GLuint *) */
GdkGLProc gdk_gl_get_glGenProgramsNV (void);
#define   gdk_gl_glGenProgramsNV(proc, n, programs) \
  ( ((PFNGLGENPROGRAMSNVPROC) (proc)) (n, programs) )

/* void glGetProgramParameterdvNV (GLenum, GLuint, GLenum, GLdouble *) */
GdkGLProc gdk_gl_get_glGetProgramParameterdvNV (void);
#define   gdk_gl_glGetProgramParameterdvNV(proc, target, index, pname, params) \
  ( ((PFNGLGETPROGRAMPARAMETERDVNVPROC) (proc)) (target, index, pname, params) )

/* void glGetProgramParameterfvNV (GLenum, GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetProgramParameterfvNV (void);
#define   gdk_gl_glGetProgramParameterfvNV(proc, target, index, pname, params) \
  ( ((PFNGLGETPROGRAMPARAMETERFVNVPROC) (proc)) (target, index, pname, params) )

/* void glGetProgramivNV (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetProgramivNV (void);
#define   gdk_gl_glGetProgramivNV(proc, id, pname, params) \
  ( ((PFNGLGETPROGRAMIVNVPROC) (proc)) (id, pname, params) )

/* void glGetProgramStringNV (GLuint, GLenum, GLubyte *) */
GdkGLProc gdk_gl_get_glGetProgramStringNV (void);
#define   gdk_gl_glGetProgramStringNV(proc, id, pname, program) \
  ( ((PFNGLGETPROGRAMSTRINGNVPROC) (proc)) (id, pname, program) )

/* void glGetTrackMatrixivNV (GLenum, GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetTrackMatrixivNV (void);
#define   gdk_gl_glGetTrackMatrixivNV(proc, target, address, pname, params) \
  ( ((PFNGLGETTRACKMATRIXIVNVPROC) (proc)) (target, address, pname, params) )

/* void glGetVertexAttribdvNV (GLuint, GLenum, GLdouble *) */
GdkGLProc gdk_gl_get_glGetVertexAttribdvNV (void);
#define   gdk_gl_glGetVertexAttribdvNV(proc, index, pname, params) \
  ( ((PFNGLGETVERTEXATTRIBDVNVPROC) (proc)) (index, pname, params) )

/* void glGetVertexAttribfvNV (GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetVertexAttribfvNV (void);
#define   gdk_gl_glGetVertexAttribfvNV(proc, index, pname, params) \
  ( ((PFNGLGETVERTEXATTRIBFVNVPROC) (proc)) (index, pname, params) )

/* void glGetVertexAttribivNV (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetVertexAttribivNV (void);
#define   gdk_gl_glGetVertexAttribivNV(proc, index, pname, params) \
  ( ((PFNGLGETVERTEXATTRIBIVNVPROC) (proc)) (index, pname, params) )

/* void glGetVertexAttribPointervNV (GLuint, GLenum, GLvoid* *) */
GdkGLProc gdk_gl_get_glGetVertexAttribPointervNV (void);
#define   gdk_gl_glGetVertexAttribPointervNV(proc, index, pname, pointer) \
  ( ((PFNGLGETVERTEXATTRIBPOINTERVNVPROC) (proc)) (index, pname, pointer) )

/* GLboolean glIsProgramNV (GLuint) */
GdkGLProc gdk_gl_get_glIsProgramNV (void);
#define   gdk_gl_glIsProgramNV(proc, id) \
  ( ((PFNGLISPROGRAMNVPROC) (proc)) (id) )

/* void glLoadProgramNV (GLenum, GLuint, GLsizei, const GLubyte *) */
GdkGLProc gdk_gl_get_glLoadProgramNV (void);
#define   gdk_gl_glLoadProgramNV(proc, target, id, len, program) \
  ( ((PFNGLLOADPROGRAMNVPROC) (proc)) (target, id, len, program) )

/* void glProgramParameter4dNV (GLenum, GLuint, GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glProgramParameter4dNV (void);
#define   gdk_gl_glProgramParameter4dNV(proc, target, index, x, y, z, w) \
  ( ((PFNGLPROGRAMPARAMETER4DNVPROC) (proc)) (target, index, x, y, z, w) )

/* void glProgramParameter4dvNV (GLenum, GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glProgramParameter4dvNV (void);
#define   gdk_gl_glProgramParameter4dvNV(proc, target, index, v) \
  ( ((PFNGLPROGRAMPARAMETER4DVNVPROC) (proc)) (target, index, v) )

/* void glProgramParameter4fNV (GLenum, GLuint, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glProgramParameter4fNV (void);
#define   gdk_gl_glProgramParameter4fNV(proc, target, index, x, y, z, w) \
  ( ((PFNGLPROGRAMPARAMETER4FNVPROC) (proc)) (target, index, x, y, z, w) )

/* void glProgramParameter4fvNV (GLenum, GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glProgramParameter4fvNV (void);
#define   gdk_gl_glProgramParameter4fvNV(proc, target, index, v) \
  ( ((PFNGLPROGRAMPARAMETER4FVNVPROC) (proc)) (target, index, v) )

/* void glProgramParameters4dvNV (GLenum, GLuint, GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glProgramParameters4dvNV (void);
#define   gdk_gl_glProgramParameters4dvNV(proc, target, index, count, v) \
  ( ((PFNGLPROGRAMPARAMETERS4DVNVPROC) (proc)) (target, index, count, v) )

/* void glProgramParameters4fvNV (GLenum, GLuint, GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glProgramParameters4fvNV (void);
#define   gdk_gl_glProgramParameters4fvNV(proc, target, index, count, v) \
  ( ((PFNGLPROGRAMPARAMETERS4FVNVPROC) (proc)) (target, index, count, v) )

/* void glRequestResidentProgramsNV (GLsizei, const GLuint *) */
GdkGLProc gdk_gl_get_glRequestResidentProgramsNV (void);
#define   gdk_gl_glRequestResidentProgramsNV(proc, n, programs) \
  ( ((PFNGLREQUESTRESIDENTPROGRAMSNVPROC) (proc)) (n, programs) )

/* void glTrackMatrixNV (GLenum, GLuint, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glTrackMatrixNV (void);
#define   gdk_gl_glTrackMatrixNV(proc, target, address, matrix, transform) \
  ( ((PFNGLTRACKMATRIXNVPROC) (proc)) (target, address, matrix, transform) )

/* void glVertexAttribPointerNV (GLuint, GLint, GLenum, GLsizei, const GLvoid *) */
GdkGLProc gdk_gl_get_glVertexAttribPointerNV (void);
#define   gdk_gl_glVertexAttribPointerNV(proc, index, fsize, type, stride, pointer) \
  ( ((PFNGLVERTEXATTRIBPOINTERNVPROC) (proc)) (index, fsize, type, stride, pointer) )

/* void glVertexAttrib1dNV (GLuint, GLdouble) */
GdkGLProc gdk_gl_get_glVertexAttrib1dNV (void);
#define   gdk_gl_glVertexAttrib1dNV(proc, index, x) \
  ( ((PFNGLVERTEXATTRIB1DNVPROC) (proc)) (index, x) )

/* void glVertexAttrib1dvNV (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttrib1dvNV (void);
#define   gdk_gl_glVertexAttrib1dvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB1DVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib1fNV (GLuint, GLfloat) */
GdkGLProc gdk_gl_get_glVertexAttrib1fNV (void);
#define   gdk_gl_glVertexAttrib1fNV(proc, index, x) \
  ( ((PFNGLVERTEXATTRIB1FNVPROC) (proc)) (index, x) )

/* void glVertexAttrib1fvNV (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttrib1fvNV (void);
#define   gdk_gl_glVertexAttrib1fvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB1FVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib1sNV (GLuint, GLshort) */
GdkGLProc gdk_gl_get_glVertexAttrib1sNV (void);
#define   gdk_gl_glVertexAttrib1sNV(proc, index, x) \
  ( ((PFNGLVERTEXATTRIB1SNVPROC) (proc)) (index, x) )

/* void glVertexAttrib1svNV (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib1svNV (void);
#define   gdk_gl_glVertexAttrib1svNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB1SVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib2dNV (GLuint, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexAttrib2dNV (void);
#define   gdk_gl_glVertexAttrib2dNV(proc, index, x, y) \
  ( ((PFNGLVERTEXATTRIB2DNVPROC) (proc)) (index, x, y) )

/* void glVertexAttrib2dvNV (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttrib2dvNV (void);
#define   gdk_gl_glVertexAttrib2dvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB2DVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib2fNV (GLuint, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexAttrib2fNV (void);
#define   gdk_gl_glVertexAttrib2fNV(proc, index, x, y) \
  ( ((PFNGLVERTEXATTRIB2FNVPROC) (proc)) (index, x, y) )

/* void glVertexAttrib2fvNV (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttrib2fvNV (void);
#define   gdk_gl_glVertexAttrib2fvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB2FVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib2sNV (GLuint, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexAttrib2sNV (void);
#define   gdk_gl_glVertexAttrib2sNV(proc, index, x, y) \
  ( ((PFNGLVERTEXATTRIB2SNVPROC) (proc)) (index, x, y) )

/* void glVertexAttrib2svNV (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib2svNV (void);
#define   gdk_gl_glVertexAttrib2svNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB2SVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib3dNV (GLuint, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexAttrib3dNV (void);
#define   gdk_gl_glVertexAttrib3dNV(proc, index, x, y, z) \
  ( ((PFNGLVERTEXATTRIB3DNVPROC) (proc)) (index, x, y, z) )

/* void glVertexAttrib3dvNV (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttrib3dvNV (void);
#define   gdk_gl_glVertexAttrib3dvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB3DVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib3fNV (GLuint, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexAttrib3fNV (void);
#define   gdk_gl_glVertexAttrib3fNV(proc, index, x, y, z) \
  ( ((PFNGLVERTEXATTRIB3FNVPROC) (proc)) (index, x, y, z) )

/* void glVertexAttrib3fvNV (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttrib3fvNV (void);
#define   gdk_gl_glVertexAttrib3fvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB3FVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib3sNV (GLuint, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexAttrib3sNV (void);
#define   gdk_gl_glVertexAttrib3sNV(proc, index, x, y, z) \
  ( ((PFNGLVERTEXATTRIB3SNVPROC) (proc)) (index, x, y, z) )

/* void glVertexAttrib3svNV (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib3svNV (void);
#define   gdk_gl_glVertexAttrib3svNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB3SVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib4dNV (GLuint, GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexAttrib4dNV (void);
#define   gdk_gl_glVertexAttrib4dNV(proc, index, x, y, z, w) \
  ( ((PFNGLVERTEXATTRIB4DNVPROC) (proc)) (index, x, y, z, w) )

/* void glVertexAttrib4dvNV (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttrib4dvNV (void);
#define   gdk_gl_glVertexAttrib4dvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4DVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib4fNV (GLuint, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexAttrib4fNV (void);
#define   gdk_gl_glVertexAttrib4fNV(proc, index, x, y, z, w) \
  ( ((PFNGLVERTEXATTRIB4FNVPROC) (proc)) (index, x, y, z, w) )

/* void glVertexAttrib4fvNV (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttrib4fvNV (void);
#define   gdk_gl_glVertexAttrib4fvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4FVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib4sNV (GLuint, GLshort, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexAttrib4sNV (void);
#define   gdk_gl_glVertexAttrib4sNV(proc, index, x, y, z, w) \
  ( ((PFNGLVERTEXATTRIB4SNVPROC) (proc)) (index, x, y, z, w) )

/* void glVertexAttrib4svNV (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttrib4svNV (void);
#define   gdk_gl_glVertexAttrib4svNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4SVNVPROC) (proc)) (index, v) )

/* void glVertexAttrib4ubNV (GLuint, GLubyte, GLubyte, GLubyte, GLubyte) */
GdkGLProc gdk_gl_get_glVertexAttrib4ubNV (void);
#define   gdk_gl_glVertexAttrib4ubNV(proc, index, x, y, z, w) \
  ( ((PFNGLVERTEXATTRIB4UBNVPROC) (proc)) (index, x, y, z, w) )

/* void glVertexAttrib4ubvNV (GLuint, const GLubyte *) */
GdkGLProc gdk_gl_get_glVertexAttrib4ubvNV (void);
#define   gdk_gl_glVertexAttrib4ubvNV(proc, index, v) \
  ( ((PFNGLVERTEXATTRIB4UBVNVPROC) (proc)) (index, v) )

/* void glVertexAttribs1dvNV (GLuint, GLsizei, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttribs1dvNV (void);
#define   gdk_gl_glVertexAttribs1dvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS1DVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs1fvNV (GLuint, GLsizei, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttribs1fvNV (void);
#define   gdk_gl_glVertexAttribs1fvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS1FVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs1svNV (GLuint, GLsizei, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttribs1svNV (void);
#define   gdk_gl_glVertexAttribs1svNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS1SVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs2dvNV (GLuint, GLsizei, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttribs2dvNV (void);
#define   gdk_gl_glVertexAttribs2dvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS2DVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs2fvNV (GLuint, GLsizei, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttribs2fvNV (void);
#define   gdk_gl_glVertexAttribs2fvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS2FVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs2svNV (GLuint, GLsizei, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttribs2svNV (void);
#define   gdk_gl_glVertexAttribs2svNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS2SVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs3dvNV (GLuint, GLsizei, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttribs3dvNV (void);
#define   gdk_gl_glVertexAttribs3dvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS3DVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs3fvNV (GLuint, GLsizei, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttribs3fvNV (void);
#define   gdk_gl_glVertexAttribs3fvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS3FVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs3svNV (GLuint, GLsizei, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttribs3svNV (void);
#define   gdk_gl_glVertexAttribs3svNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS3SVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs4dvNV (GLuint, GLsizei, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexAttribs4dvNV (void);
#define   gdk_gl_glVertexAttribs4dvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS4DVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs4fvNV (GLuint, GLsizei, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexAttribs4fvNV (void);
#define   gdk_gl_glVertexAttribs4fvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS4FVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs4svNV (GLuint, GLsizei, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexAttribs4svNV (void);
#define   gdk_gl_glVertexAttribs4svNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS4SVNVPROC) (proc)) (index, count, v) )

/* void glVertexAttribs4ubvNV (GLuint, GLsizei, const GLubyte *) */
GdkGLProc gdk_gl_get_glVertexAttribs4ubvNV (void);
#define   gdk_gl_glVertexAttribs4ubvNV(proc, index, count, v) \
  ( ((PFNGLVERTEXATTRIBS4UBVNVPROC) (proc)) (index, count, v) )

/* 
 * GL_ATI_envmap_bumpmap
 */

/* void glTexBumpParameterivATI (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glTexBumpParameterivATI (void);
#define   gdk_gl_glTexBumpParameterivATI(proc, pname, param) \
  ( ((PFNGLTEXBUMPPARAMETERIVATIPROC) (proc)) (pname, param) )

/* void glTexBumpParameterfvATI (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glTexBumpParameterfvATI (void);
#define   gdk_gl_glTexBumpParameterfvATI(proc, pname, param) \
  ( ((PFNGLTEXBUMPPARAMETERFVATIPROC) (proc)) (pname, param) )

/* void glGetTexBumpParameterivATI (GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetTexBumpParameterivATI (void);
#define   gdk_gl_glGetTexBumpParameterivATI(proc, pname, param) \
  ( ((PFNGLGETTEXBUMPPARAMETERIVATIPROC) (proc)) (pname, param) )

/* void glGetTexBumpParameterfvATI (GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetTexBumpParameterfvATI (void);
#define   gdk_gl_glGetTexBumpParameterfvATI(proc, pname, param) \
  ( ((PFNGLGETTEXBUMPPARAMETERFVATIPROC) (proc)) (pname, param) )

/* 
 * GL_ATI_fragment_shader
 */

/* GLuint glGenFragmentShadersATI (GLuint) */
GdkGLProc gdk_gl_get_glGenFragmentShadersATI (void);
#define   gdk_gl_glGenFragmentShadersATI(proc, range) \
  ( ((PFNGLGENFRAGMENTSHADERSATIPROC) (proc)) (range) )

/* void glBindFragmentShaderATI (GLuint) */
GdkGLProc gdk_gl_get_glBindFragmentShaderATI (void);
#define   gdk_gl_glBindFragmentShaderATI(proc, id) \
  ( ((PFNGLBINDFRAGMENTSHADERATIPROC) (proc)) (id) )

/* void glDeleteFragmentShaderATI (GLuint) */
GdkGLProc gdk_gl_get_glDeleteFragmentShaderATI (void);
#define   gdk_gl_glDeleteFragmentShaderATI(proc, id) \
  ( ((PFNGLDELETEFRAGMENTSHADERATIPROC) (proc)) (id) )

/* void glBeginFragmentShaderATI (void) */
GdkGLProc gdk_gl_get_glBeginFragmentShaderATI (void);
#define   gdk_gl_glBeginFragmentShaderATI(proc) \
  ( ((PFNGLBEGINFRAGMENTSHADERATIPROC) (proc)) () )

/* void glEndFragmentShaderATI (void) */
GdkGLProc gdk_gl_get_glEndFragmentShaderATI (void);
#define   gdk_gl_glEndFragmentShaderATI(proc) \
  ( ((PFNGLENDFRAGMENTSHADERATIPROC) (proc)) () )

/* void glPassTexCoordATI (GLuint, GLuint, GLenum) */
GdkGLProc gdk_gl_get_glPassTexCoordATI (void);
#define   gdk_gl_glPassTexCoordATI(proc, dst, coord, swizzle) \
  ( ((PFNGLPASSTEXCOORDATIPROC) (proc)) (dst, coord, swizzle) )

/* void glSampleMapATI (GLuint, GLuint, GLenum) */
GdkGLProc gdk_gl_get_glSampleMapATI (void);
#define   gdk_gl_glSampleMapATI(proc, dst, interp, swizzle) \
  ( ((PFNGLSAMPLEMAPATIPROC) (proc)) (dst, interp, swizzle) )

/* void glColorFragmentOp1ATI (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glColorFragmentOp1ATI (void);
#define   gdk_gl_glColorFragmentOp1ATI(proc, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod) \
  ( ((PFNGLCOLORFRAGMENTOP1ATIPROC) (proc)) (op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod) )

/* void glColorFragmentOp2ATI (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glColorFragmentOp2ATI (void);
#define   gdk_gl_glColorFragmentOp2ATI(proc, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) \
  ( ((PFNGLCOLORFRAGMENTOP2ATIPROC) (proc)) (op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) )

/* void glColorFragmentOp3ATI (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glColorFragmentOp3ATI (void);
#define   gdk_gl_glColorFragmentOp3ATI(proc, op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) \
  ( ((PFNGLCOLORFRAGMENTOP3ATIPROC) (proc)) (op, dst, dstMask, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) )

/* void glAlphaFragmentOp1ATI (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glAlphaFragmentOp1ATI (void);
#define   gdk_gl_glAlphaFragmentOp1ATI(proc, op, dst, dstMod, arg1, arg1Rep, arg1Mod) \
  ( ((PFNGLALPHAFRAGMENTOP1ATIPROC) (proc)) (op, dst, dstMod, arg1, arg1Rep, arg1Mod) )

/* void glAlphaFragmentOp2ATI (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glAlphaFragmentOp2ATI (void);
#define   gdk_gl_glAlphaFragmentOp2ATI(proc, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) \
  ( ((PFNGLALPHAFRAGMENTOP2ATIPROC) (proc)) (op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod) )

/* void glAlphaFragmentOp3ATI (GLenum, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glAlphaFragmentOp3ATI (void);
#define   gdk_gl_glAlphaFragmentOp3ATI(proc, op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) \
  ( ((PFNGLALPHAFRAGMENTOP3ATIPROC) (proc)) (op, dst, dstMod, arg1, arg1Rep, arg1Mod, arg2, arg2Rep, arg2Mod, arg3, arg3Rep, arg3Mod) )

/* void glSetFragmentShaderConstantATI (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glSetFragmentShaderConstantATI (void);
#define   gdk_gl_glSetFragmentShaderConstantATI(proc, dst, value) \
  ( ((PFNGLSETFRAGMENTSHADERCONSTANTATIPROC) (proc)) (dst, value) )

/* 
 * GL_ATI_pn_triangles
 */

/* void glPNTrianglesiATI (GLenum, GLint) */
GdkGLProc gdk_gl_get_glPNTrianglesiATI (void);
#define   gdk_gl_glPNTrianglesiATI(proc, pname, param) \
  ( ((PFNGLPNTRIANGLESIATIPROC) (proc)) (pname, param) )

/* void glPNTrianglesfATI (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glPNTrianglesfATI (void);
#define   gdk_gl_glPNTrianglesfATI(proc, pname, param) \
  ( ((PFNGLPNTRIANGLESFATIPROC) (proc)) (pname, param) )

/* 
 * GL_ATI_vertex_array_object
 */

/* GLuint glNewObjectBufferATI (GLsizei, const GLvoid *, GLenum) */
GdkGLProc gdk_gl_get_glNewObjectBufferATI (void);
#define   gdk_gl_glNewObjectBufferATI(proc, size, pointer, usage) \
  ( ((PFNGLNEWOBJECTBUFFERATIPROC) (proc)) (size, pointer, usage) )

/* GLboolean glIsObjectBufferATI (GLuint) */
GdkGLProc gdk_gl_get_glIsObjectBufferATI (void);
#define   gdk_gl_glIsObjectBufferATI(proc, buffer) \
  ( ((PFNGLISOBJECTBUFFERATIPROC) (proc)) (buffer) )

/* void glUpdateObjectBufferATI (GLuint, GLuint, GLsizei, const GLvoid *, GLenum) */
GdkGLProc gdk_gl_get_glUpdateObjectBufferATI (void);
#define   gdk_gl_glUpdateObjectBufferATI(proc, buffer, offset, size, pointer, preserve) \
  ( ((PFNGLUPDATEOBJECTBUFFERATIPROC) (proc)) (buffer, offset, size, pointer, preserve) )

/* void glGetObjectBufferfvATI (GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetObjectBufferfvATI (void);
#define   gdk_gl_glGetObjectBufferfvATI(proc, buffer, pname, params) \
  ( ((PFNGLGETOBJECTBUFFERFVATIPROC) (proc)) (buffer, pname, params) )

/* void glGetObjectBufferivATI (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetObjectBufferivATI (void);
#define   gdk_gl_glGetObjectBufferivATI(proc, buffer, pname, params) \
  ( ((PFNGLGETOBJECTBUFFERIVATIPROC) (proc)) (buffer, pname, params) )

/* void glDeleteObjectBufferATI (GLuint) */
GdkGLProc gdk_gl_get_glDeleteObjectBufferATI (void);
#define   gdk_gl_glDeleteObjectBufferATI(proc, buffer) \
  ( ((PFNGLDELETEOBJECTBUFFERATIPROC) (proc)) (buffer) )

/* void glArrayObjectATI (GLenum, GLint, GLenum, GLsizei, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glArrayObjectATI (void);
#define   gdk_gl_glArrayObjectATI(proc, array, size, type, stride, buffer, offset) \
  ( ((PFNGLARRAYOBJECTATIPROC) (proc)) (array, size, type, stride, buffer, offset) )

/* void glGetArrayObjectfvATI (GLenum, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetArrayObjectfvATI (void);
#define   gdk_gl_glGetArrayObjectfvATI(proc, array, pname, params) \
  ( ((PFNGLGETARRAYOBJECTFVATIPROC) (proc)) (array, pname, params) )

/* void glGetArrayObjectivATI (GLenum, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetArrayObjectivATI (void);
#define   gdk_gl_glGetArrayObjectivATI(proc, array, pname, params) \
  ( ((PFNGLGETARRAYOBJECTIVATIPROC) (proc)) (array, pname, params) )

/* void glVariantArrayObjectATI (GLuint, GLenum, GLsizei, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glVariantArrayObjectATI (void);
#define   gdk_gl_glVariantArrayObjectATI(proc, id, type, stride, buffer, offset) \
  ( ((PFNGLVARIANTARRAYOBJECTATIPROC) (proc)) (id, type, stride, buffer, offset) )

/* void glGetVariantArrayObjectfvATI (GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetVariantArrayObjectfvATI (void);
#define   gdk_gl_glGetVariantArrayObjectfvATI(proc, id, pname, params) \
  ( ((PFNGLGETVARIANTARRAYOBJECTFVATIPROC) (proc)) (id, pname, params) )

/* void glGetVariantArrayObjectivATI (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetVariantArrayObjectivATI (void);
#define   gdk_gl_glGetVariantArrayObjectivATI(proc, id, pname, params) \
  ( ((PFNGLGETVARIANTARRAYOBJECTIVATIPROC) (proc)) (id, pname, params) )

/* 
 * GL_EXT_vertex_shader
 */

/* void glBeginVertexShaderEXT (void) */
GdkGLProc gdk_gl_get_glBeginVertexShaderEXT (void);
#define   gdk_gl_glBeginVertexShaderEXT(proc) \
  ( ((PFNGLBEGINVERTEXSHADEREXTPROC) (proc)) () )

/* void glEndVertexShaderEXT (void) */
GdkGLProc gdk_gl_get_glEndVertexShaderEXT (void);
#define   gdk_gl_glEndVertexShaderEXT(proc) \
  ( ((PFNGLENDVERTEXSHADEREXTPROC) (proc)) () )

/* void glBindVertexShaderEXT (GLuint) */
GdkGLProc gdk_gl_get_glBindVertexShaderEXT (void);
#define   gdk_gl_glBindVertexShaderEXT(proc, id) \
  ( ((PFNGLBINDVERTEXSHADEREXTPROC) (proc)) (id) )

/* GLuint glGenVertexShadersEXT (GLuint) */
GdkGLProc gdk_gl_get_glGenVertexShadersEXT (void);
#define   gdk_gl_glGenVertexShadersEXT(proc, range) \
  ( ((PFNGLGENVERTEXSHADERSEXTPROC) (proc)) (range) )

/* void glDeleteVertexShaderEXT (GLuint) */
GdkGLProc gdk_gl_get_glDeleteVertexShaderEXT (void);
#define   gdk_gl_glDeleteVertexShaderEXT(proc, id) \
  ( ((PFNGLDELETEVERTEXSHADEREXTPROC) (proc)) (id) )

/* void glShaderOp1EXT (GLenum, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glShaderOp1EXT (void);
#define   gdk_gl_glShaderOp1EXT(proc, op, res, arg1) \
  ( ((PFNGLSHADEROP1EXTPROC) (proc)) (op, res, arg1) )

/* void glShaderOp2EXT (GLenum, GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glShaderOp2EXT (void);
#define   gdk_gl_glShaderOp2EXT(proc, op, res, arg1, arg2) \
  ( ((PFNGLSHADEROP2EXTPROC) (proc)) (op, res, arg1, arg2) )

/* void glShaderOp3EXT (GLenum, GLuint, GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glShaderOp3EXT (void);
#define   gdk_gl_glShaderOp3EXT(proc, op, res, arg1, arg2, arg3) \
  ( ((PFNGLSHADEROP3EXTPROC) (proc)) (op, res, arg1, arg2, arg3) )

/* void glSwizzleEXT (GLuint, GLuint, GLenum, GLenum, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glSwizzleEXT (void);
#define   gdk_gl_glSwizzleEXT(proc, res, in, outX, outY, outZ, outW) \
  ( ((PFNGLSWIZZLEEXTPROC) (proc)) (res, in, outX, outY, outZ, outW) )

/* void glWriteMaskEXT (GLuint, GLuint, GLenum, GLenum, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glWriteMaskEXT (void);
#define   gdk_gl_glWriteMaskEXT(proc, res, in, outX, outY, outZ, outW) \
  ( ((PFNGLWRITEMASKEXTPROC) (proc)) (res, in, outX, outY, outZ, outW) )

/* void glInsertComponentEXT (GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glInsertComponentEXT (void);
#define   gdk_gl_glInsertComponentEXT(proc, res, src, num) \
  ( ((PFNGLINSERTCOMPONENTEXTPROC) (proc)) (res, src, num) )

/* void glExtractComponentEXT (GLuint, GLuint, GLuint) */
GdkGLProc gdk_gl_get_glExtractComponentEXT (void);
#define   gdk_gl_glExtractComponentEXT(proc, res, src, num) \
  ( ((PFNGLEXTRACTCOMPONENTEXTPROC) (proc)) (res, src, num) )

/* GLuint glGenSymbolsEXT (GLenum, GLenum, GLenum, GLuint) */
GdkGLProc gdk_gl_get_glGenSymbolsEXT (void);
#define   gdk_gl_glGenSymbolsEXT(proc, datatype, storagetype, range, components) \
  ( ((PFNGLGENSYMBOLSEXTPROC) (proc)) (datatype, storagetype, range, components) )

/* void glSetInvariantEXT (GLuint, GLenum, const void *) */
GdkGLProc gdk_gl_get_glSetInvariantEXT (void);
#define   gdk_gl_glSetInvariantEXT(proc, id, type, addr) \
  ( ((PFNGLSETINVARIANTEXTPROC) (proc)) (id, type, addr) )

/* void glSetLocalConstantEXT (GLuint, GLenum, const void *) */
GdkGLProc gdk_gl_get_glSetLocalConstantEXT (void);
#define   gdk_gl_glSetLocalConstantEXT(proc, id, type, addr) \
  ( ((PFNGLSETLOCALCONSTANTEXTPROC) (proc)) (id, type, addr) )

/* void glVariantbvEXT (GLuint, const GLbyte *) */
GdkGLProc gdk_gl_get_glVariantbvEXT (void);
#define   gdk_gl_glVariantbvEXT(proc, id, addr) \
  ( ((PFNGLVARIANTBVEXTPROC) (proc)) (id, addr) )

/* void glVariantsvEXT (GLuint, const GLshort *) */
GdkGLProc gdk_gl_get_glVariantsvEXT (void);
#define   gdk_gl_glVariantsvEXT(proc, id, addr) \
  ( ((PFNGLVARIANTSVEXTPROC) (proc)) (id, addr) )

/* void glVariantivEXT (GLuint, const GLint *) */
GdkGLProc gdk_gl_get_glVariantivEXT (void);
#define   gdk_gl_glVariantivEXT(proc, id, addr) \
  ( ((PFNGLVARIANTIVEXTPROC) (proc)) (id, addr) )

/* void glVariantfvEXT (GLuint, const GLfloat *) */
GdkGLProc gdk_gl_get_glVariantfvEXT (void);
#define   gdk_gl_glVariantfvEXT(proc, id, addr) \
  ( ((PFNGLVARIANTFVEXTPROC) (proc)) (id, addr) )

/* void glVariantdvEXT (GLuint, const GLdouble *) */
GdkGLProc gdk_gl_get_glVariantdvEXT (void);
#define   gdk_gl_glVariantdvEXT(proc, id, addr) \
  ( ((PFNGLVARIANTDVEXTPROC) (proc)) (id, addr) )

/* void glVariantubvEXT (GLuint, const GLubyte *) */
GdkGLProc gdk_gl_get_glVariantubvEXT (void);
#define   gdk_gl_glVariantubvEXT(proc, id, addr) \
  ( ((PFNGLVARIANTUBVEXTPROC) (proc)) (id, addr) )

/* void glVariantusvEXT (GLuint, const GLushort *) */
GdkGLProc gdk_gl_get_glVariantusvEXT (void);
#define   gdk_gl_glVariantusvEXT(proc, id, addr) \
  ( ((PFNGLVARIANTUSVEXTPROC) (proc)) (id, addr) )

/* void glVariantuivEXT (GLuint, const GLuint *) */
GdkGLProc gdk_gl_get_glVariantuivEXT (void);
#define   gdk_gl_glVariantuivEXT(proc, id, addr) \
  ( ((PFNGLVARIANTUIVEXTPROC) (proc)) (id, addr) )

/* void glVariantPointerEXT (GLuint, GLenum, GLuint, const void *) */
GdkGLProc gdk_gl_get_glVariantPointerEXT (void);
#define   gdk_gl_glVariantPointerEXT(proc, id, type, stride, addr) \
  ( ((PFNGLVARIANTPOINTEREXTPROC) (proc)) (id, type, stride, addr) )

/* void glEnableVariantClientStateEXT (GLuint) */
GdkGLProc gdk_gl_get_glEnableVariantClientStateEXT (void);
#define   gdk_gl_glEnableVariantClientStateEXT(proc, id) \
  ( ((PFNGLENABLEVARIANTCLIENTSTATEEXTPROC) (proc)) (id) )

/* void glDisableVariantClientStateEXT (GLuint) */
GdkGLProc gdk_gl_get_glDisableVariantClientStateEXT (void);
#define   gdk_gl_glDisableVariantClientStateEXT(proc, id) \
  ( ((PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC) (proc)) (id) )

/* GLuint glBindLightParameterEXT (GLenum, GLenum) */
GdkGLProc gdk_gl_get_glBindLightParameterEXT (void);
#define   gdk_gl_glBindLightParameterEXT(proc, light, value) \
  ( ((PFNGLBINDLIGHTPARAMETEREXTPROC) (proc)) (light, value) )

/* GLuint glBindMaterialParameterEXT (GLenum, GLenum) */
GdkGLProc gdk_gl_get_glBindMaterialParameterEXT (void);
#define   gdk_gl_glBindMaterialParameterEXT(proc, face, value) \
  ( ((PFNGLBINDMATERIALPARAMETEREXTPROC) (proc)) (face, value) )

/* GLuint glBindTexGenParameterEXT (GLenum, GLenum, GLenum) */
GdkGLProc gdk_gl_get_glBindTexGenParameterEXT (void);
#define   gdk_gl_glBindTexGenParameterEXT(proc, unit, coord, value) \
  ( ((PFNGLBINDTEXGENPARAMETEREXTPROC) (proc)) (unit, coord, value) )

/* GLuint glBindTextureUnitParameterEXT (GLenum, GLenum) */
GdkGLProc gdk_gl_get_glBindTextureUnitParameterEXT (void);
#define   gdk_gl_glBindTextureUnitParameterEXT(proc, unit, value) \
  ( ((PFNGLBINDTEXTUREUNITPARAMETEREXTPROC) (proc)) (unit, value) )

/* GLuint glBindParameterEXT (GLenum) */
GdkGLProc gdk_gl_get_glBindParameterEXT (void);
#define   gdk_gl_glBindParameterEXT(proc, value) \
  ( ((PFNGLBINDPARAMETEREXTPROC) (proc)) (value) )

/* GLboolean glIsVariantEnabledEXT (GLuint, GLenum) */
GdkGLProc gdk_gl_get_glIsVariantEnabledEXT (void);
#define   gdk_gl_glIsVariantEnabledEXT(proc, id, cap) \
  ( ((PFNGLISVARIANTENABLEDEXTPROC) (proc)) (id, cap) )

/* void glGetVariantBooleanvEXT (GLuint, GLenum, GLboolean *) */
GdkGLProc gdk_gl_get_glGetVariantBooleanvEXT (void);
#define   gdk_gl_glGetVariantBooleanvEXT(proc, id, value, data) \
  ( ((PFNGLGETVARIANTBOOLEANVEXTPROC) (proc)) (id, value, data) )

/* void glGetVariantIntegervEXT (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetVariantIntegervEXT (void);
#define   gdk_gl_glGetVariantIntegervEXT(proc, id, value, data) \
  ( ((PFNGLGETVARIANTINTEGERVEXTPROC) (proc)) (id, value, data) )

/* void glGetVariantFloatvEXT (GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetVariantFloatvEXT (void);
#define   gdk_gl_glGetVariantFloatvEXT(proc, id, value, data) \
  ( ((PFNGLGETVARIANTFLOATVEXTPROC) (proc)) (id, value, data) )

/* void glGetVariantPointervEXT (GLuint, GLenum, GLvoid* *) */
GdkGLProc gdk_gl_get_glGetVariantPointervEXT (void);
#define   gdk_gl_glGetVariantPointervEXT(proc, id, value, data) \
  ( ((PFNGLGETVARIANTPOINTERVEXTPROC) (proc)) (id, value, data) )

/* void glGetInvariantBooleanvEXT (GLuint, GLenum, GLboolean *) */
GdkGLProc gdk_gl_get_glGetInvariantBooleanvEXT (void);
#define   gdk_gl_glGetInvariantBooleanvEXT(proc, id, value, data) \
  ( ((PFNGLGETINVARIANTBOOLEANVEXTPROC) (proc)) (id, value, data) )

/* void glGetInvariantIntegervEXT (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetInvariantIntegervEXT (void);
#define   gdk_gl_glGetInvariantIntegervEXT(proc, id, value, data) \
  ( ((PFNGLGETINVARIANTINTEGERVEXTPROC) (proc)) (id, value, data) )

/* void glGetInvariantFloatvEXT (GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetInvariantFloatvEXT (void);
#define   gdk_gl_glGetInvariantFloatvEXT(proc, id, value, data) \
  ( ((PFNGLGETINVARIANTFLOATVEXTPROC) (proc)) (id, value, data) )

/* void glGetLocalConstantBooleanvEXT (GLuint, GLenum, GLboolean *) */
GdkGLProc gdk_gl_get_glGetLocalConstantBooleanvEXT (void);
#define   gdk_gl_glGetLocalConstantBooleanvEXT(proc, id, value, data) \
  ( ((PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC) (proc)) (id, value, data) )

/* void glGetLocalConstantIntegervEXT (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetLocalConstantIntegervEXT (void);
#define   gdk_gl_glGetLocalConstantIntegervEXT(proc, id, value, data) \
  ( ((PFNGLGETLOCALCONSTANTINTEGERVEXTPROC) (proc)) (id, value, data) )

/* void glGetLocalConstantFloatvEXT (GLuint, GLenum, GLfloat *) */
GdkGLProc gdk_gl_get_glGetLocalConstantFloatvEXT (void);
#define   gdk_gl_glGetLocalConstantFloatvEXT(proc, id, value, data) \
  ( ((PFNGLGETLOCALCONSTANTFLOATVEXTPROC) (proc)) (id, value, data) )

/* 
 * GL_ATI_vertex_streams
 */

/* void glVertexStream1sATI (GLenum, GLshort) */
GdkGLProc gdk_gl_get_glVertexStream1sATI (void);
#define   gdk_gl_glVertexStream1sATI(proc, stream, x) \
  ( ((PFNGLVERTEXSTREAM1SATIPROC) (proc)) (stream, x) )

/* void glVertexStream1svATI (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexStream1svATI (void);
#define   gdk_gl_glVertexStream1svATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM1SVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream1iATI (GLenum, GLint) */
GdkGLProc gdk_gl_get_glVertexStream1iATI (void);
#define   gdk_gl_glVertexStream1iATI(proc, stream, x) \
  ( ((PFNGLVERTEXSTREAM1IATIPROC) (proc)) (stream, x) )

/* void glVertexStream1ivATI (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glVertexStream1ivATI (void);
#define   gdk_gl_glVertexStream1ivATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM1IVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream1fATI (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glVertexStream1fATI (void);
#define   gdk_gl_glVertexStream1fATI(proc, stream, x) \
  ( ((PFNGLVERTEXSTREAM1FATIPROC) (proc)) (stream, x) )

/* void glVertexStream1fvATI (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexStream1fvATI (void);
#define   gdk_gl_glVertexStream1fvATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM1FVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream1dATI (GLenum, GLdouble) */
GdkGLProc gdk_gl_get_glVertexStream1dATI (void);
#define   gdk_gl_glVertexStream1dATI(proc, stream, x) \
  ( ((PFNGLVERTEXSTREAM1DATIPROC) (proc)) (stream, x) )

/* void glVertexStream1dvATI (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexStream1dvATI (void);
#define   gdk_gl_glVertexStream1dvATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM1DVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream2sATI (GLenum, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexStream2sATI (void);
#define   gdk_gl_glVertexStream2sATI(proc, stream, x, y) \
  ( ((PFNGLVERTEXSTREAM2SATIPROC) (proc)) (stream, x, y) )

/* void glVertexStream2svATI (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexStream2svATI (void);
#define   gdk_gl_glVertexStream2svATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM2SVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream2iATI (GLenum, GLint, GLint) */
GdkGLProc gdk_gl_get_glVertexStream2iATI (void);
#define   gdk_gl_glVertexStream2iATI(proc, stream, x, y) \
  ( ((PFNGLVERTEXSTREAM2IATIPROC) (proc)) (stream, x, y) )

/* void glVertexStream2ivATI (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glVertexStream2ivATI (void);
#define   gdk_gl_glVertexStream2ivATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM2IVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream2fATI (GLenum, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexStream2fATI (void);
#define   gdk_gl_glVertexStream2fATI(proc, stream, x, y) \
  ( ((PFNGLVERTEXSTREAM2FATIPROC) (proc)) (stream, x, y) )

/* void glVertexStream2fvATI (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexStream2fvATI (void);
#define   gdk_gl_glVertexStream2fvATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM2FVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream2dATI (GLenum, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexStream2dATI (void);
#define   gdk_gl_glVertexStream2dATI(proc, stream, x, y) \
  ( ((PFNGLVERTEXSTREAM2DATIPROC) (proc)) (stream, x, y) )

/* void glVertexStream2dvATI (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexStream2dvATI (void);
#define   gdk_gl_glVertexStream2dvATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM2DVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream3sATI (GLenum, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexStream3sATI (void);
#define   gdk_gl_glVertexStream3sATI(proc, stream, x, y, z) \
  ( ((PFNGLVERTEXSTREAM3SATIPROC) (proc)) (stream, x, y, z) )

/* void glVertexStream3svATI (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexStream3svATI (void);
#define   gdk_gl_glVertexStream3svATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM3SVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream3iATI (GLenum, GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glVertexStream3iATI (void);
#define   gdk_gl_glVertexStream3iATI(proc, stream, x, y, z) \
  ( ((PFNGLVERTEXSTREAM3IATIPROC) (proc)) (stream, x, y, z) )

/* void glVertexStream3ivATI (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glVertexStream3ivATI (void);
#define   gdk_gl_glVertexStream3ivATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM3IVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream3fATI (GLenum, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexStream3fATI (void);
#define   gdk_gl_glVertexStream3fATI(proc, stream, x, y, z) \
  ( ((PFNGLVERTEXSTREAM3FATIPROC) (proc)) (stream, x, y, z) )

/* void glVertexStream3fvATI (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexStream3fvATI (void);
#define   gdk_gl_glVertexStream3fvATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM3FVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream3dATI (GLenum, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexStream3dATI (void);
#define   gdk_gl_glVertexStream3dATI(proc, stream, x, y, z) \
  ( ((PFNGLVERTEXSTREAM3DATIPROC) (proc)) (stream, x, y, z) )

/* void glVertexStream3dvATI (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexStream3dvATI (void);
#define   gdk_gl_glVertexStream3dvATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM3DVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream4sATI (GLenum, GLshort, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glVertexStream4sATI (void);
#define   gdk_gl_glVertexStream4sATI(proc, stream, x, y, z, w) \
  ( ((PFNGLVERTEXSTREAM4SATIPROC) (proc)) (stream, x, y, z, w) )

/* void glVertexStream4svATI (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glVertexStream4svATI (void);
#define   gdk_gl_glVertexStream4svATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM4SVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream4iATI (GLenum, GLint, GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glVertexStream4iATI (void);
#define   gdk_gl_glVertexStream4iATI(proc, stream, x, y, z, w) \
  ( ((PFNGLVERTEXSTREAM4IATIPROC) (proc)) (stream, x, y, z, w) )

/* void glVertexStream4ivATI (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glVertexStream4ivATI (void);
#define   gdk_gl_glVertexStream4ivATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM4IVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream4fATI (GLenum, GLfloat, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glVertexStream4fATI (void);
#define   gdk_gl_glVertexStream4fATI(proc, stream, x, y, z, w) \
  ( ((PFNGLVERTEXSTREAM4FATIPROC) (proc)) (stream, x, y, z, w) )

/* void glVertexStream4fvATI (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glVertexStream4fvATI (void);
#define   gdk_gl_glVertexStream4fvATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM4FVATIPROC) (proc)) (stream, coords) )

/* void glVertexStream4dATI (GLenum, GLdouble, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glVertexStream4dATI (void);
#define   gdk_gl_glVertexStream4dATI(proc, stream, x, y, z, w) \
  ( ((PFNGLVERTEXSTREAM4DATIPROC) (proc)) (stream, x, y, z, w) )

/* void glVertexStream4dvATI (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glVertexStream4dvATI (void);
#define   gdk_gl_glVertexStream4dvATI(proc, stream, coords) \
  ( ((PFNGLVERTEXSTREAM4DVATIPROC) (proc)) (stream, coords) )

/* void glNormalStream3bATI (GLenum, GLbyte, GLbyte, GLbyte) */
GdkGLProc gdk_gl_get_glNormalStream3bATI (void);
#define   gdk_gl_glNormalStream3bATI(proc, stream, nx, ny, nz) \
  ( ((PFNGLNORMALSTREAM3BATIPROC) (proc)) (stream, nx, ny, nz) )

/* void glNormalStream3bvATI (GLenum, const GLbyte *) */
GdkGLProc gdk_gl_get_glNormalStream3bvATI (void);
#define   gdk_gl_glNormalStream3bvATI(proc, stream, coords) \
  ( ((PFNGLNORMALSTREAM3BVATIPROC) (proc)) (stream, coords) )

/* void glNormalStream3sATI (GLenum, GLshort, GLshort, GLshort) */
GdkGLProc gdk_gl_get_glNormalStream3sATI (void);
#define   gdk_gl_glNormalStream3sATI(proc, stream, nx, ny, nz) \
  ( ((PFNGLNORMALSTREAM3SATIPROC) (proc)) (stream, nx, ny, nz) )

/* void glNormalStream3svATI (GLenum, const GLshort *) */
GdkGLProc gdk_gl_get_glNormalStream3svATI (void);
#define   gdk_gl_glNormalStream3svATI(proc, stream, coords) \
  ( ((PFNGLNORMALSTREAM3SVATIPROC) (proc)) (stream, coords) )

/* void glNormalStream3iATI (GLenum, GLint, GLint, GLint) */
GdkGLProc gdk_gl_get_glNormalStream3iATI (void);
#define   gdk_gl_glNormalStream3iATI(proc, stream, nx, ny, nz) \
  ( ((PFNGLNORMALSTREAM3IATIPROC) (proc)) (stream, nx, ny, nz) )

/* void glNormalStream3ivATI (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glNormalStream3ivATI (void);
#define   gdk_gl_glNormalStream3ivATI(proc, stream, coords) \
  ( ((PFNGLNORMALSTREAM3IVATIPROC) (proc)) (stream, coords) )

/* void glNormalStream3fATI (GLenum, GLfloat, GLfloat, GLfloat) */
GdkGLProc gdk_gl_get_glNormalStream3fATI (void);
#define   gdk_gl_glNormalStream3fATI(proc, stream, nx, ny, nz) \
  ( ((PFNGLNORMALSTREAM3FATIPROC) (proc)) (stream, nx, ny, nz) )

/* void glNormalStream3fvATI (GLenum, const GLfloat *) */
GdkGLProc gdk_gl_get_glNormalStream3fvATI (void);
#define   gdk_gl_glNormalStream3fvATI(proc, stream, coords) \
  ( ((PFNGLNORMALSTREAM3FVATIPROC) (proc)) (stream, coords) )

/* void glNormalStream3dATI (GLenum, GLdouble, GLdouble, GLdouble) */
GdkGLProc gdk_gl_get_glNormalStream3dATI (void);
#define   gdk_gl_glNormalStream3dATI(proc, stream, nx, ny, nz) \
  ( ((PFNGLNORMALSTREAM3DATIPROC) (proc)) (stream, nx, ny, nz) )

/* void glNormalStream3dvATI (GLenum, const GLdouble *) */
GdkGLProc gdk_gl_get_glNormalStream3dvATI (void);
#define   gdk_gl_glNormalStream3dvATI(proc, stream, coords) \
  ( ((PFNGLNORMALSTREAM3DVATIPROC) (proc)) (stream, coords) )

/* void glClientActiveVertexStreamATI (GLenum) */
GdkGLProc gdk_gl_get_glClientActiveVertexStreamATI (void);
#define   gdk_gl_glClientActiveVertexStreamATI(proc, stream) \
  ( ((PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC) (proc)) (stream) )

/* void glVertexBlendEnviATI (GLenum, GLint) */
GdkGLProc gdk_gl_get_glVertexBlendEnviATI (void);
#define   gdk_gl_glVertexBlendEnviATI(proc, pname, param) \
  ( ((PFNGLVERTEXBLENDENVIATIPROC) (proc)) (pname, param) )

/* void glVertexBlendEnvfATI (GLenum, GLfloat) */
GdkGLProc gdk_gl_get_glVertexBlendEnvfATI (void);
#define   gdk_gl_glVertexBlendEnvfATI(proc, pname, param) \
  ( ((PFNGLVERTEXBLENDENVFATIPROC) (proc)) (pname, param) )

/* 
 * GL_ATI_element_array
 */

/* void glElementPointerATI (GLenum, const GLvoid *) */
GdkGLProc gdk_gl_get_glElementPointerATI (void);
#define   gdk_gl_glElementPointerATI(proc, type, pointer) \
  ( ((PFNGLELEMENTPOINTERATIPROC) (proc)) (type, pointer) )

/* void glDrawElementArrayATI (GLenum, GLsizei) */
GdkGLProc gdk_gl_get_glDrawElementArrayATI (void);
#define   gdk_gl_glDrawElementArrayATI(proc, mode, count) \
  ( ((PFNGLDRAWELEMENTARRAYATIPROC) (proc)) (mode, count) )

/* void glDrawRangeElementArrayATI (GLenum, GLuint, GLuint, GLsizei) */
GdkGLProc gdk_gl_get_glDrawRangeElementArrayATI (void);
#define   gdk_gl_glDrawRangeElementArrayATI(proc, mode, start, end, count) \
  ( ((PFNGLDRAWRANGEELEMENTARRAYATIPROC) (proc)) (mode, start, end, count) )

/* 
 * GL_SUN_mesh_array
 */

/* void glDrawMeshArraysSUN (GLenum, GLint, GLsizei, GLsizei) */
GdkGLProc gdk_gl_get_glDrawMeshArraysSUN (void);
#define   gdk_gl_glDrawMeshArraysSUN(proc, mode, first, count, width) \
  ( ((PFNGLDRAWMESHARRAYSSUNPROC) (proc)) (mode, first, count, width) )

/* 
 * GL_NV_occlusion_query
 */

/* void glGenOcclusionQueriesNV (GLsizei, GLuint *) */
GdkGLProc gdk_gl_get_glGenOcclusionQueriesNV (void);
#define   gdk_gl_glGenOcclusionQueriesNV(proc, n, ids) \
  ( ((PFNGLGENOCCLUSIONQUERIESNVPROC) (proc)) (n, ids) )

/* void glDeleteOcclusionQueriesNV (GLsizei, const GLuint *) */
GdkGLProc gdk_gl_get_glDeleteOcclusionQueriesNV (void);
#define   gdk_gl_glDeleteOcclusionQueriesNV(proc, n, ids) \
  ( ((PFNGLDELETEOCCLUSIONQUERIESNVPROC) (proc)) (n, ids) )

/* GLboolean glIsOcclusionQueryNV (GLuint) */
GdkGLProc gdk_gl_get_glIsOcclusionQueryNV (void);
#define   gdk_gl_glIsOcclusionQueryNV(proc, id) \
  ( ((PFNGLISOCCLUSIONQUERYNVPROC) (proc)) (id) )

/* void glBeginOcclusionQueryNV (GLuint) */
GdkGLProc gdk_gl_get_glBeginOcclusionQueryNV (void);
#define   gdk_gl_glBeginOcclusionQueryNV(proc, id) \
  ( ((PFNGLBEGINOCCLUSIONQUERYNVPROC) (proc)) (id) )

/* void glEndOcclusionQueryNV (void) */
GdkGLProc gdk_gl_get_glEndOcclusionQueryNV (void);
#define   gdk_gl_glEndOcclusionQueryNV(proc) \
  ( ((PFNGLENDOCCLUSIONQUERYNVPROC) (proc)) () )

/* void glGetOcclusionQueryivNV (GLuint, GLenum, GLint *) */
GdkGLProc gdk_gl_get_glGetOcclusionQueryivNV (void);
#define   gdk_gl_glGetOcclusionQueryivNV(proc, id, pname, params) \
  ( ((PFNGLGETOCCLUSIONQUERYIVNVPROC) (proc)) (id, pname, params) )

/* void glGetOcclusionQueryuivNV (GLuint, GLenum, GLuint *) */
GdkGLProc gdk_gl_get_glGetOcclusionQueryuivNV (void);
#define   gdk_gl_glGetOcclusionQueryuivNV(proc, id, pname, params) \
  ( ((PFNGLGETOCCLUSIONQUERYUIVNVPROC) (proc)) (id, pname, params) )

/* 
 * GL_NV_point_sprite
 */

/* void glPointParameteriNV (GLenum, GLint) */
GdkGLProc gdk_gl_get_glPointParameteriNV (void);
#define   gdk_gl_glPointParameteriNV(proc, pname, param) \
  ( ((PFNGLPOINTPARAMETERINVPROC) (proc)) (pname, param) )

/* void glPointParameterivNV (GLenum, const GLint *) */
GdkGLProc gdk_gl_get_glPointParameterivNV (void);
#define   gdk_gl_glPointParameterivNV(proc, pname, params) \
  ( ((PFNGLPOINTPARAMETERIVNVPROC) (proc)) (pname, params) )

/* 
 * GL_EXT_stencil_two_side
 */

/* void glActiveStencilFaceEXT (GLenum) */
GdkGLProc gdk_gl_get_glActiveStencilFaceEXT (void);
#define   gdk_gl_glActiveStencilFaceEXT(proc, face) \
  ( ((PFNGLACTIVESTENCILFACEEXTPROC) (proc)) (face) )

G_END_DECLS

#endif /* __GDK_GL_GLEXT_H__ */
