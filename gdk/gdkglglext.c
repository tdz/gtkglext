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

#include "gdkglprivate.h"
#include "gdkglquery.h"
#include "gdkglglext.h"

#define _GDK_GL_PROCS(__ext_name) \
  _GDK_GL_CONCAT (_proc_, __ext_name)

#define _GDK_GL_PROC_TYPE(__proc_name) \
  _GDK_GL_CONCAT (GdkGLProc_, __proc_name)

#ifdef G_OS_WIN32

#include "win32/gdkglwin32.h"

#define _GDK_GL_GET_PROC(__procs, __proc_name)                                          \
GdkGLProc                                                                               \
_GDK_GL_CONCAT (gdk_gl_get_, __proc_name) (void)                                        \
{                                                                                       \
  static gboolean init = FALSE;                                                         \
                                                                                        \
  if (!wglGetCurrentContext ())                                                         \
    return NULL;                                                                        \
                                                                                        \
  if (!init)                                                                            \
    {                                                                                   \
      __procs.__proc_name =                                                             \
        (_GDK_GL_PROC_TYPE (__proc_name)) gdk_gl_query_get_proc_address (#__proc_name); \
                                                                                        \
      GDK_GL_NOTE (MISC,                                                                \
                   g_message (" - gdk_gl_get_%s () - %s",                               \
                              #__proc_name,                                             \
                              (__procs.__proc_name) ? "supported" : "not supported"));  \
                                                                                        \
      init = TRUE;                                                                      \
    }                                                                                   \
                                                                                        \
  return (GdkGLProc) (__procs.__proc_name);                                             \
}

#else  /* G_OS_WIN32 */

#define _GDK_GL_GET_PROC(__procs, __proc_name)                                          \
GdkGLProc                                                                               \
_GDK_GL_CONCAT (gdk_gl_get_, __proc_name) (void)                                        \
{                                                                                       \
  static gboolean init = FALSE;                                                         \
                                                                                        \
  if (!init)                                                                            \
    {                                                                                   \
      __procs.__proc_name =                                                             \
        (_GDK_GL_PROC_TYPE (__proc_name)) gdk_gl_query_get_proc_address (#__proc_name); \
                                                                                        \
      GDK_GL_NOTE (MISC,                                                                \
                   g_message (" - gdk_gl_get_%s () - %s",                               \
                              #__proc_name,                                             \
                              (__procs.__proc_name) ? "supported" : "not supported"));  \
                                                                                        \
      init = TRUE;                                                                      \
    }                                                                                   \
                                                                                        \
  return (GdkGLProc) (__procs.__proc_name);                                             \
}

#endif /* G_OS_WIN32 */

/* 
 * GL_VERSION_1_2
 */

static GdkGL_GL_VERSION_1_2 _GDK_GL_PROCS (GdkGL_GL_VERSION_1_2) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glBlendColor)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glBlendEquation)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glDrawRangeElements)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glColorTable)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glColorTableParameterfv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glColorTableParameteriv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glCopyColorTable)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetColorTable)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetColorTableParameterfv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetColorTableParameteriv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glColorSubTable)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glCopyColorSubTable)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glConvolutionFilter1D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glConvolutionFilter2D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glConvolutionParameterf)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glConvolutionParameterfv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glConvolutionParameteri)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glConvolutionParameteriv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glCopyConvolutionFilter1D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glCopyConvolutionFilter2D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetConvolutionFilter)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetConvolutionParameterfv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetConvolutionParameteriv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetSeparableFilter)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glSeparableFilter2D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetHistogram)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetHistogramParameterfv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetHistogramParameteriv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetMinmax)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetMinmaxParameterfv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glGetMinmaxParameteriv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glHistogram)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glMinmax)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glResetHistogram)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glResetMinmax)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glTexImage3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glTexSubImage3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2), glCopyTexSubImage3D)

GdkGL_GL_VERSION_1_2 *
gdk_gl_get_GL_VERSION_1_2 (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_VERSION_1_2 ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported &= (gdk_gl_get_glBlendColor ()                != NULL);
      supported &= (gdk_gl_get_glBlendEquation ()             != NULL);
      supported &= (gdk_gl_get_glDrawRangeElements ()         != NULL);
      supported &= (gdk_gl_get_glColorTable ()                != NULL);
      supported &= (gdk_gl_get_glColorTableParameterfv ()     != NULL);
      supported &= (gdk_gl_get_glColorTableParameteriv ()     != NULL);
      supported &= (gdk_gl_get_glCopyColorTable ()            != NULL);
      supported &= (gdk_gl_get_glGetColorTable ()             != NULL);
      supported &= (gdk_gl_get_glGetColorTableParameterfv ()  != NULL);
      supported &= (gdk_gl_get_glGetColorTableParameteriv ()  != NULL);
      supported &= (gdk_gl_get_glColorSubTable ()             != NULL);
      supported &= (gdk_gl_get_glCopyColorSubTable ()         != NULL);
      supported &= (gdk_gl_get_glConvolutionFilter1D ()       != NULL);
      supported &= (gdk_gl_get_glConvolutionFilter2D ()       != NULL);
      supported &= (gdk_gl_get_glConvolutionParameterf ()     != NULL);
      supported &= (gdk_gl_get_glConvolutionParameterfv ()    != NULL);
      supported &= (gdk_gl_get_glConvolutionParameteri ()     != NULL);
      supported &= (gdk_gl_get_glConvolutionParameteriv ()    != NULL);
      supported &= (gdk_gl_get_glCopyConvolutionFilter1D ()   != NULL);
      supported &= (gdk_gl_get_glCopyConvolutionFilter2D ()   != NULL);
      supported &= (gdk_gl_get_glGetConvolutionFilter ()      != NULL);
      supported &= (gdk_gl_get_glGetConvolutionParameterfv () != NULL);
      supported &= (gdk_gl_get_glGetConvolutionParameteriv () != NULL);
      supported &= (gdk_gl_get_glGetSeparableFilter ()        != NULL);
      supported &= (gdk_gl_get_glSeparableFilter2D ()         != NULL);
      supported &= (gdk_gl_get_glGetHistogram ()              != NULL);
      supported &= (gdk_gl_get_glGetHistogramParameterfv ()   != NULL);
      supported &= (gdk_gl_get_glGetHistogramParameteriv ()   != NULL);
      supported &= (gdk_gl_get_glGetMinmax ()                 != NULL);
      supported &= (gdk_gl_get_glGetMinmaxParameterfv ()      != NULL);
      supported &= (gdk_gl_get_glGetMinmaxParameteriv ()      != NULL);
      supported &= (gdk_gl_get_glHistogram ()                 != NULL);
      supported &= (gdk_gl_get_glMinmax ()                    != NULL);
      supported &= (gdk_gl_get_glResetHistogram ()            != NULL);
      supported &= (gdk_gl_get_glResetMinmax ()               != NULL);
      supported &= (gdk_gl_get_glTexImage3D ()                != NULL);
      supported &= (gdk_gl_get_glTexSubImage3D ()             != NULL);
      supported &= (gdk_gl_get_glCopyTexSubImage3D ()         != NULL);

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_VERSION_1_2));
}

/* 
 * GL_VERSION_1_3
 */

static GdkGL_GL_VERSION_1_3 _GDK_GL_PROCS (GdkGL_GL_VERSION_1_3) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glActiveTexture)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glClientActiveTexture)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord1d)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord1dv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord1f)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord1fv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord1i)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord1iv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord1s)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord1sv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord2d)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord2dv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord2f)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord2fv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord2i)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord2iv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord2s)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord2sv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord3d)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord3dv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord3f)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord3fv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord3i)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord3iv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord3s)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord3sv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord4d)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord4dv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord4f)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord4fv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord4i)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord4iv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord4s)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultiTexCoord4sv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glLoadTransposeMatrixf)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glLoadTransposeMatrixd)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultTransposeMatrixf)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glMultTransposeMatrixd)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glSampleCoverage)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glCompressedTexImage3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glCompressedTexImage2D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glCompressedTexImage1D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glCompressedTexSubImage3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glCompressedTexSubImage2D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glCompressedTexSubImage1D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3), glGetCompressedTexImage)

GdkGL_GL_VERSION_1_3 *
gdk_gl_get_GL_VERSION_1_3 (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_VERSION_1_3 ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported &= (gdk_gl_get_glActiveTexture ()           != NULL);
      supported &= (gdk_gl_get_glClientActiveTexture ()     != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord1d ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord1dv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord1f ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord1fv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord1i ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord1iv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord1s ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord1sv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord2d ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord2dv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord2f ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord2fv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord2i ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord2iv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord2s ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord2sv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord3d ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord3dv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord3f ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord3fv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord3i ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord3iv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord3s ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord3sv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord4d ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord4dv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord4f ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord4fv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord4i ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord4iv ()        != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord4s ()         != NULL);
      supported &= (gdk_gl_get_glMultiTexCoord4sv ()        != NULL);
      supported &= (gdk_gl_get_glLoadTransposeMatrixf ()    != NULL);
      supported &= (gdk_gl_get_glLoadTransposeMatrixd ()    != NULL);
      supported &= (gdk_gl_get_glMultTransposeMatrixf ()    != NULL);
      supported &= (gdk_gl_get_glMultTransposeMatrixd ()    != NULL);
      supported &= (gdk_gl_get_glSampleCoverage ()          != NULL);
      supported &= (gdk_gl_get_glCompressedTexImage3D ()    != NULL);
      supported &= (gdk_gl_get_glCompressedTexImage2D ()    != NULL);
      supported &= (gdk_gl_get_glCompressedTexImage1D ()    != NULL);
      supported &= (gdk_gl_get_glCompressedTexSubImage3D () != NULL);
      supported &= (gdk_gl_get_glCompressedTexSubImage2D () != NULL);
      supported &= (gdk_gl_get_glCompressedTexSubImage1D () != NULL);
      supported &= (gdk_gl_get_glGetCompressedTexImage ()   != NULL);

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_VERSION_1_3));
}

/* 
 * GL_VERSION_1_4
 */

static GdkGL_GL_VERSION_1_4 _GDK_GL_PROCS (GdkGL_GL_VERSION_1_4) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glBlendFuncSeparate)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glFogCoordf)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glFogCoordfv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glFogCoordd)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glFogCoorddv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glFogCoordPointer)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glMultiDrawArrays)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glMultiDrawElements)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glPointParameterf)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glPointParameterfv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glPointParameteri)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glPointParameteriv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3b)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3bv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3d)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3dv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3f)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3fv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3i)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3iv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3s)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3sv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3ub)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3ubv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3ui)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3uiv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3us)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColor3usv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glSecondaryColorPointer)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos2d)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos2dv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos2f)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos2fv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos2i)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos2iv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos2s)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos2sv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos3d)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos3dv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos3f)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos3fv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos3i)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos3iv)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos3s)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4), glWindowPos3sv)

GdkGL_GL_VERSION_1_4 *
gdk_gl_get_GL_VERSION_1_4 (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_VERSION_1_4 ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported &= (gdk_gl_get_glBlendFuncSeparate ()     != NULL);
      supported &= (gdk_gl_get_glFogCoordf ()             != NULL);
      supported &= (gdk_gl_get_glFogCoordfv ()            != NULL);
      supported &= (gdk_gl_get_glFogCoordd ()             != NULL);
      supported &= (gdk_gl_get_glFogCoorddv ()            != NULL);
      supported &= (gdk_gl_get_glFogCoordPointer ()       != NULL);
      supported &= (gdk_gl_get_glMultiDrawArrays ()       != NULL);
      supported &= (gdk_gl_get_glMultiDrawElements ()     != NULL);
      supported &= (gdk_gl_get_glPointParameterf ()       != NULL);
      supported &= (gdk_gl_get_glPointParameterfv ()      != NULL);
      supported &= (gdk_gl_get_glPointParameteri ()       != NULL);
      supported &= (gdk_gl_get_glPointParameteriv ()      != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3b ()      != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3bv ()     != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3d ()      != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3dv ()     != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3f ()      != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3fv ()     != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3i ()      != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3iv ()     != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3s ()      != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3sv ()     != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3ub ()     != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3ubv ()    != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3ui ()     != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3uiv ()    != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3us ()     != NULL);
      supported &= (gdk_gl_get_glSecondaryColor3usv ()    != NULL);
      supported &= (gdk_gl_get_glSecondaryColorPointer () != NULL);
      supported &= (gdk_gl_get_glWindowPos2d ()           != NULL);
      supported &= (gdk_gl_get_glWindowPos2dv ()          != NULL);
      supported &= (gdk_gl_get_glWindowPos2f ()           != NULL);
      supported &= (gdk_gl_get_glWindowPos2fv ()          != NULL);
      supported &= (gdk_gl_get_glWindowPos2i ()           != NULL);
      supported &= (gdk_gl_get_glWindowPos2iv ()          != NULL);
      supported &= (gdk_gl_get_glWindowPos2s ()           != NULL);
      supported &= (gdk_gl_get_glWindowPos2sv ()          != NULL);
      supported &= (gdk_gl_get_glWindowPos3d ()           != NULL);
      supported &= (gdk_gl_get_glWindowPos3dv ()          != NULL);
      supported &= (gdk_gl_get_glWindowPos3f ()           != NULL);
      supported &= (gdk_gl_get_glWindowPos3fv ()          != NULL);
      supported &= (gdk_gl_get_glWindowPos3i ()           != NULL);
      supported &= (gdk_gl_get_glWindowPos3iv ()          != NULL);
      supported &= (gdk_gl_get_glWindowPos3s ()           != NULL);
      supported &= (gdk_gl_get_glWindowPos3sv ()          != NULL);

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_VERSION_1_4));
}

/* 
 * GL_ARB_multitexture
 */

static GdkGL_GL_ARB_multitexture _GDK_GL_PROCS (GdkGL_GL_ARB_multitexture) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glActiveTextureARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glClientActiveTextureARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord1dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord1dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord1fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord1fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord1iARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord1ivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord1sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord1svARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord2dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord2dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord2fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord2fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord2iARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord2ivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord2sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord2svARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord3dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord3dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord3fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord3fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord3iARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord3ivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord3sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord3svARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord4dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord4dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord4fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord4fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord4iARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord4ivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord4sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture), glMultiTexCoord4svARB)

GdkGL_GL_ARB_multitexture *
gdk_gl_get_GL_ARB_multitexture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_multitexture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_multitexture");

      if (supported)
        {
          supported &= (gdk_gl_get_glActiveTextureARB ()       != NULL);
          supported &= (gdk_gl_get_glClientActiveTextureARB () != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord1dARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord1dvARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord1fARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord1fvARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord1iARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord1ivARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord1sARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord1svARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord2dARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord2dvARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord2fARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord2fvARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord2iARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord2ivARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord2sARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord2svARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord3dARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord3dvARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord3fARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord3fvARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord3iARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord3ivARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord3sARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord3svARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord4dARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord4dvARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord4fARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord4fvARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord4iARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord4ivARB ()    != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord4sARB ()     != NULL);
          supported &= (gdk_gl_get_glMultiTexCoord4svARB ()    != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_multitexture));
}

/* 
 * GL_ARB_transpose_matrix
 */

static GdkGL_GL_ARB_transpose_matrix _GDK_GL_PROCS (GdkGL_GL_ARB_transpose_matrix) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_transpose_matrix), glLoadTransposeMatrixfARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_transpose_matrix), glLoadTransposeMatrixdARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_transpose_matrix), glMultTransposeMatrixfARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_transpose_matrix), glMultTransposeMatrixdARB)

GdkGL_GL_ARB_transpose_matrix *
gdk_gl_get_GL_ARB_transpose_matrix (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_transpose_matrix ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_transpose_matrix");

      if (supported)
        {
          supported &= (gdk_gl_get_glLoadTransposeMatrixfARB () != NULL);
          supported &= (gdk_gl_get_glLoadTransposeMatrixdARB () != NULL);
          supported &= (gdk_gl_get_glMultTransposeMatrixfARB () != NULL);
          supported &= (gdk_gl_get_glMultTransposeMatrixdARB () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_transpose_matrix));
}

/* 
 * GL_ARB_multisample
 */

static GdkGL_GL_ARB_multisample _GDK_GL_PROCS (GdkGL_GL_ARB_multisample) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multisample), glSampleCoverageARB)

GdkGL_GL_ARB_multisample *
gdk_gl_get_GL_ARB_multisample (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_multisample ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_multisample");

      if (supported)
        {
          supported &= (gdk_gl_get_glSampleCoverageARB () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_multisample));
}

/* 
 * GL_ARB_texture_compression
 */

static GdkGL_GL_ARB_texture_compression _GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression), glCompressedTexImage3DARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression), glCompressedTexImage2DARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression), glCompressedTexImage1DARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression), glCompressedTexSubImage3DARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression), glCompressedTexSubImage2DARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression), glCompressedTexSubImage1DARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression), glGetCompressedTexImageARB)

GdkGL_GL_ARB_texture_compression *
gdk_gl_get_GL_ARB_texture_compression (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_texture_compression ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_texture_compression");

      if (supported)
        {
          supported &= (gdk_gl_get_glCompressedTexImage3DARB ()    != NULL);
          supported &= (gdk_gl_get_glCompressedTexImage2DARB ()    != NULL);
          supported &= (gdk_gl_get_glCompressedTexImage1DARB ()    != NULL);
          supported &= (gdk_gl_get_glCompressedTexSubImage3DARB () != NULL);
          supported &= (gdk_gl_get_glCompressedTexSubImage2DARB () != NULL);
          supported &= (gdk_gl_get_glCompressedTexSubImage1DARB () != NULL);
          supported &= (gdk_gl_get_glGetCompressedTexImageARB ()   != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_texture_compression));
}

/* 
 * GL_ARB_point_parameters
 */

static GdkGL_GL_ARB_point_parameters _GDK_GL_PROCS (GdkGL_GL_ARB_point_parameters) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_point_parameters), glPointParameterfARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_point_parameters), glPointParameterfvARB)

GdkGL_GL_ARB_point_parameters *
gdk_gl_get_GL_ARB_point_parameters (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_point_parameters ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_point_parameters");

      if (supported)
        {
          supported &= (gdk_gl_get_glPointParameterfARB ()  != NULL);
          supported &= (gdk_gl_get_glPointParameterfvARB () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_point_parameters));
}

/* 
 * GL_ARB_vertex_blend
 */

static GdkGL_GL_ARB_vertex_blend _GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightbvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightsvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightfvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightdvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightubvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightusvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightuivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glWeightPointerARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend), glVertexBlendARB)

GdkGL_GL_ARB_vertex_blend *
gdk_gl_get_GL_ARB_vertex_blend (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_vertex_blend ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_vertex_blend");

      if (supported)
        {
          supported &= (gdk_gl_get_glWeightbvARB ()      != NULL);
          supported &= (gdk_gl_get_glWeightsvARB ()      != NULL);
          supported &= (gdk_gl_get_glWeightivARB ()      != NULL);
          supported &= (gdk_gl_get_glWeightfvARB ()      != NULL);
          supported &= (gdk_gl_get_glWeightdvARB ()      != NULL);
          supported &= (gdk_gl_get_glWeightubvARB ()     != NULL);
          supported &= (gdk_gl_get_glWeightusvARB ()     != NULL);
          supported &= (gdk_gl_get_glWeightuivARB ()     != NULL);
          supported &= (gdk_gl_get_glWeightPointerARB () != NULL);
          supported &= (gdk_gl_get_glVertexBlendARB ()   != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_blend));
}

/* 
 * GL_ARB_matrix_palette
 */

static GdkGL_GL_ARB_matrix_palette _GDK_GL_PROCS (GdkGL_GL_ARB_matrix_palette) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_matrix_palette), glCurrentPaletteMatrixARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_matrix_palette), glMatrixIndexubvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_matrix_palette), glMatrixIndexusvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_matrix_palette), glMatrixIndexuivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_matrix_palette), glMatrixIndexPointerARB)

GdkGL_GL_ARB_matrix_palette *
gdk_gl_get_GL_ARB_matrix_palette (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_matrix_palette ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_matrix_palette");

      if (supported)
        {
          supported &= (gdk_gl_get_glCurrentPaletteMatrixARB () != NULL);
          supported &= (gdk_gl_get_glMatrixIndexubvARB ()       != NULL);
          supported &= (gdk_gl_get_glMatrixIndexusvARB ()       != NULL);
          supported &= (gdk_gl_get_glMatrixIndexuivARB ()       != NULL);
          supported &= (gdk_gl_get_glMatrixIndexPointerARB ()   != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_matrix_palette));
}

/* 
 * GL_ARB_window_pos
 */

static GdkGL_GL_ARB_window_pos _GDK_GL_PROCS (GdkGL_GL_ARB_window_pos) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos2dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos2dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos2fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos2fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos2iARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos2ivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos2sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos2svARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos3dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos3dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos3fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos3fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos3iARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos3ivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos3sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos), glWindowPos3svARB)

GdkGL_GL_ARB_window_pos *
gdk_gl_get_GL_ARB_window_pos (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_window_pos ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_window_pos");

      if (supported)
        {
          supported &= (gdk_gl_get_glWindowPos2dARB ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos2dvARB () != NULL);
          supported &= (gdk_gl_get_glWindowPos2fARB ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos2fvARB () != NULL);
          supported &= (gdk_gl_get_glWindowPos2iARB ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos2ivARB () != NULL);
          supported &= (gdk_gl_get_glWindowPos2sARB ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos2svARB () != NULL);
          supported &= (gdk_gl_get_glWindowPos3dARB ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos3dvARB () != NULL);
          supported &= (gdk_gl_get_glWindowPos3fARB ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos3fvARB () != NULL);
          supported &= (gdk_gl_get_glWindowPos3iARB ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos3ivARB () != NULL);
          supported &= (gdk_gl_get_glWindowPos3sARB ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos3svARB () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_window_pos));
}

/* 
 * GL_ARB_vertex_program
 */

static GdkGL_GL_ARB_vertex_program _GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib1dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib1dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib1fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib1fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib1sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib1svARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib2dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib2dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib2fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib2fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib2sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib2svARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib3dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib3dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib3fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib3fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib3sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib3svARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4NbvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4NivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4NsvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4NubARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4NubvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4NuivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4NusvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4bvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4ivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4sARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4svARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4ubvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4uivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttrib4usvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glVertexAttribPointerARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glEnableVertexAttribArrayARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glDisableVertexAttribArrayARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramStringARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glBindProgramARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glDeleteProgramsARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGenProgramsARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramEnvParameter4dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramEnvParameter4dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramEnvParameter4fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramEnvParameter4fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramLocalParameter4dARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramLocalParameter4dvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramLocalParameter4fARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glProgramLocalParameter4fvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetProgramEnvParameterdvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetProgramEnvParameterfvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetProgramLocalParameterdvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetProgramLocalParameterfvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetProgramivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetProgramStringARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetVertexAttribdvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetVertexAttribfvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetVertexAttribivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glGetVertexAttribPointervARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program), glIsProgramARB)

GdkGL_GL_ARB_vertex_program *
gdk_gl_get_GL_ARB_vertex_program (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ARB_vertex_program ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ARB_vertex_program");

      if (supported)
        {
          supported &= (gdk_gl_get_glVertexAttrib1dARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1dvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1fARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1fvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1sARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1svARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2dARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2dvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2fARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2fvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2sARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2svARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3dARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3dvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3fARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3fvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3sARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3svARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4NbvARB ()           != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4NivARB ()           != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4NsvARB ()           != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4NubARB ()           != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4NubvARB ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4NuivARB ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4NusvARB ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4bvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4dARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4dvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4fARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4fvARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4ivARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4sARB ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4svARB ()            != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4ubvARB ()           != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4uivARB ()           != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4usvARB ()           != NULL);
          supported &= (gdk_gl_get_glVertexAttribPointerARB ()        != NULL);
          supported &= (gdk_gl_get_glEnableVertexAttribArrayARB ()    != NULL);
          supported &= (gdk_gl_get_glDisableVertexAttribArrayARB ()   != NULL);
          supported &= (gdk_gl_get_glProgramStringARB ()              != NULL);
          supported &= (gdk_gl_get_glBindProgramARB ()                != NULL);
          supported &= (gdk_gl_get_glDeleteProgramsARB ()             != NULL);
          supported &= (gdk_gl_get_glGenProgramsARB ()                != NULL);
          supported &= (gdk_gl_get_glProgramEnvParameter4dARB ()      != NULL);
          supported &= (gdk_gl_get_glProgramEnvParameter4dvARB ()     != NULL);
          supported &= (gdk_gl_get_glProgramEnvParameter4fARB ()      != NULL);
          supported &= (gdk_gl_get_glProgramEnvParameter4fvARB ()     != NULL);
          supported &= (gdk_gl_get_glProgramLocalParameter4dARB ()    != NULL);
          supported &= (gdk_gl_get_glProgramLocalParameter4dvARB ()   != NULL);
          supported &= (gdk_gl_get_glProgramLocalParameter4fARB ()    != NULL);
          supported &= (gdk_gl_get_glProgramLocalParameter4fvARB ()   != NULL);
          supported &= (gdk_gl_get_glGetProgramEnvParameterdvARB ()   != NULL);
          supported &= (gdk_gl_get_glGetProgramEnvParameterfvARB ()   != NULL);
          supported &= (gdk_gl_get_glGetProgramLocalParameterdvARB () != NULL);
          supported &= (gdk_gl_get_glGetProgramLocalParameterfvARB () != NULL);
          supported &= (gdk_gl_get_glGetProgramivARB ()               != NULL);
          supported &= (gdk_gl_get_glGetProgramStringARB ()           != NULL);
          supported &= (gdk_gl_get_glGetVertexAttribdvARB ()          != NULL);
          supported &= (gdk_gl_get_glGetVertexAttribfvARB ()          != NULL);
          supported &= (gdk_gl_get_glGetVertexAttribivARB ()          != NULL);
          supported &= (gdk_gl_get_glGetVertexAttribPointervARB ()    != NULL);
          supported &= (gdk_gl_get_glIsProgramARB ()                  != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ARB_vertex_program));
}

/* 
 * GL_EXT_blend_color
 */

static GdkGL_GL_EXT_blend_color _GDK_GL_PROCS (GdkGL_GL_EXT_blend_color) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_blend_color), glBlendColorEXT)

GdkGL_GL_EXT_blend_color *
gdk_gl_get_GL_EXT_blend_color (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_blend_color ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_blend_color");

      if (supported)
        {
          supported &= (gdk_gl_get_glBlendColorEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_blend_color));
}

/* 
 * GL_EXT_polygon_offset
 */

static GdkGL_GL_EXT_polygon_offset _GDK_GL_PROCS (GdkGL_GL_EXT_polygon_offset) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_polygon_offset), glPolygonOffsetEXT)

GdkGL_GL_EXT_polygon_offset *
gdk_gl_get_GL_EXT_polygon_offset (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_polygon_offset ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_polygon_offset");

      if (supported)
        {
          supported &= (gdk_gl_get_glPolygonOffsetEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_polygon_offset));
}

/* 
 * GL_EXT_texture3D
 */

static GdkGL_GL_EXT_texture3D _GDK_GL_PROCS (GdkGL_GL_EXT_texture3D) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture3D), glTexImage3DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture3D), glTexSubImage3DEXT)

GdkGL_GL_EXT_texture3D *
gdk_gl_get_GL_EXT_texture3D (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_texture3D ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_texture3D");

      if (supported)
        {
          supported &= (gdk_gl_get_glTexImage3DEXT ()    != NULL);
          supported &= (gdk_gl_get_glTexSubImage3DEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_texture3D));
}

/* 
 * GL_SGIS_texture_filter4
 */

static GdkGL_GL_SGIS_texture_filter4 _GDK_GL_PROCS (GdkGL_GL_SGIS_texture_filter4) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture_filter4), glGetTexFilterFuncSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture_filter4), glTexFilterFuncSGIS)

GdkGL_GL_SGIS_texture_filter4 *
gdk_gl_get_GL_SGIS_texture_filter4 (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_texture_filter4 ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_texture_filter4");

      if (supported)
        {
          supported &= (gdk_gl_get_glGetTexFilterFuncSGIS () != NULL);
          supported &= (gdk_gl_get_glTexFilterFuncSGIS ()    != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_texture_filter4));
}

/* 
 * GL_EXT_subtexture
 */

static GdkGL_GL_EXT_subtexture _GDK_GL_PROCS (GdkGL_GL_EXT_subtexture) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_subtexture), glTexSubImage1DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_subtexture), glTexSubImage2DEXT)

GdkGL_GL_EXT_subtexture *
gdk_gl_get_GL_EXT_subtexture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_subtexture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_subtexture");

      if (supported)
        {
          supported &= (gdk_gl_get_glTexSubImage1DEXT () != NULL);
          supported &= (gdk_gl_get_glTexSubImage2DEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_subtexture));
}

/* 
 * GL_EXT_copy_texture
 */

static GdkGL_GL_EXT_copy_texture _GDK_GL_PROCS (GdkGL_GL_EXT_copy_texture) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_copy_texture), glCopyTexImage1DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_copy_texture), glCopyTexImage2DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_copy_texture), glCopyTexSubImage1DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_copy_texture), glCopyTexSubImage2DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_copy_texture), glCopyTexSubImage3DEXT)

GdkGL_GL_EXT_copy_texture *
gdk_gl_get_GL_EXT_copy_texture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_copy_texture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_copy_texture");

      if (supported)
        {
          supported &= (gdk_gl_get_glCopyTexImage1DEXT ()    != NULL);
          supported &= (gdk_gl_get_glCopyTexImage2DEXT ()    != NULL);
          supported &= (gdk_gl_get_glCopyTexSubImage1DEXT () != NULL);
          supported &= (gdk_gl_get_glCopyTexSubImage2DEXT () != NULL);
          supported &= (gdk_gl_get_glCopyTexSubImage3DEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_copy_texture));
}

/* 
 * GL_EXT_histogram
 */

static GdkGL_GL_EXT_histogram _GDK_GL_PROCS (GdkGL_GL_EXT_histogram) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glGetHistogramEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glGetHistogramParameterfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glGetHistogramParameterivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glGetMinmaxEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glGetMinmaxParameterfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glGetMinmaxParameterivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glHistogramEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glMinmaxEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glResetHistogramEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_histogram), glResetMinmaxEXT)

GdkGL_GL_EXT_histogram *
gdk_gl_get_GL_EXT_histogram (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_histogram ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_histogram");

      if (supported)
        {
          supported &= (gdk_gl_get_glGetHistogramEXT ()            != NULL);
          supported &= (gdk_gl_get_glGetHistogramParameterfvEXT () != NULL);
          supported &= (gdk_gl_get_glGetHistogramParameterivEXT () != NULL);
          supported &= (gdk_gl_get_glGetMinmaxEXT ()               != NULL);
          supported &= (gdk_gl_get_glGetMinmaxParameterfvEXT ()    != NULL);
          supported &= (gdk_gl_get_glGetMinmaxParameterivEXT ()    != NULL);
          supported &= (gdk_gl_get_glHistogramEXT ()               != NULL);
          supported &= (gdk_gl_get_glMinmaxEXT ()                  != NULL);
          supported &= (gdk_gl_get_glResetHistogramEXT ()          != NULL);
          supported &= (gdk_gl_get_glResetMinmaxEXT ()             != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_histogram));
}

/* 
 * GL_EXT_convolution
 */

static GdkGL_GL_EXT_convolution _GDK_GL_PROCS (GdkGL_GL_EXT_convolution) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glConvolutionFilter1DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glConvolutionFilter2DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glConvolutionParameterfEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glConvolutionParameterfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glConvolutionParameteriEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glConvolutionParameterivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glCopyConvolutionFilter1DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glCopyConvolutionFilter2DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glGetConvolutionFilterEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glGetConvolutionParameterfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glGetConvolutionParameterivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glGetSeparableFilterEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_convolution), glSeparableFilter2DEXT)

GdkGL_GL_EXT_convolution *
gdk_gl_get_GL_EXT_convolution (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_convolution ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_convolution");

      if (supported)
        {
          supported &= (gdk_gl_get_glConvolutionFilter1DEXT ()       != NULL);
          supported &= (gdk_gl_get_glConvolutionFilter2DEXT ()       != NULL);
          supported &= (gdk_gl_get_glConvolutionParameterfEXT ()     != NULL);
          supported &= (gdk_gl_get_glConvolutionParameterfvEXT ()    != NULL);
          supported &= (gdk_gl_get_glConvolutionParameteriEXT ()     != NULL);
          supported &= (gdk_gl_get_glConvolutionParameterivEXT ()    != NULL);
          supported &= (gdk_gl_get_glCopyConvolutionFilter1DEXT ()   != NULL);
          supported &= (gdk_gl_get_glCopyConvolutionFilter2DEXT ()   != NULL);
          supported &= (gdk_gl_get_glGetConvolutionFilterEXT ()      != NULL);
          supported &= (gdk_gl_get_glGetConvolutionParameterfvEXT () != NULL);
          supported &= (gdk_gl_get_glGetConvolutionParameterivEXT () != NULL);
          supported &= (gdk_gl_get_glGetSeparableFilterEXT ()        != NULL);
          supported &= (gdk_gl_get_glSeparableFilter2DEXT ()         != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_convolution));
}

/* 
 * GL_SGI_color_table
 */

static GdkGL_GL_SGI_color_table _GDK_GL_PROCS (GdkGL_GL_SGI_color_table) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGI_color_table), glColorTableSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGI_color_table), glColorTableParameterfvSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGI_color_table), glColorTableParameterivSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGI_color_table), glCopyColorTableSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGI_color_table), glGetColorTableSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGI_color_table), glGetColorTableParameterfvSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGI_color_table), glGetColorTableParameterivSGI)

GdkGL_GL_SGI_color_table *
gdk_gl_get_GL_SGI_color_table (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGI_color_table ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGI_color_table");

      if (supported)
        {
          supported &= (gdk_gl_get_glColorTableSGI ()               != NULL);
          supported &= (gdk_gl_get_glColorTableParameterfvSGI ()    != NULL);
          supported &= (gdk_gl_get_glColorTableParameterivSGI ()    != NULL);
          supported &= (gdk_gl_get_glCopyColorTableSGI ()           != NULL);
          supported &= (gdk_gl_get_glGetColorTableSGI ()            != NULL);
          supported &= (gdk_gl_get_glGetColorTableParameterfvSGI () != NULL);
          supported &= (gdk_gl_get_glGetColorTableParameterivSGI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGI_color_table));
}

/* 
 * GL_SGIX_pixel_texture
 */

static GdkGL_GL_SGIX_pixel_texture _GDK_GL_PROCS (GdkGL_GL_SGIX_pixel_texture) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_pixel_texture), glPixelTexGenSGIX)

GdkGL_GL_SGIX_pixel_texture *
gdk_gl_get_GL_SGIX_pixel_texture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_pixel_texture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_pixel_texture");

      if (supported)
        {
          supported &= (gdk_gl_get_glPixelTexGenSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_pixel_texture));
}

/* 
 * GL_SGIS_pixel_texture
 */

static GdkGL_GL_SGIS_pixel_texture _GDK_GL_PROCS (GdkGL_GL_SGIS_pixel_texture) = {
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_pixel_texture), glPixelTexGenParameteriSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_pixel_texture), glPixelTexGenParameterivSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_pixel_texture), glPixelTexGenParameterfSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_pixel_texture), glPixelTexGenParameterfvSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_pixel_texture), glGetPixelTexGenParameterivSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_pixel_texture), glGetPixelTexGenParameterfvSGIS)

GdkGL_GL_SGIS_pixel_texture *
gdk_gl_get_GL_SGIS_pixel_texture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_pixel_texture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_pixel_texture");

      if (supported)
        {
          supported &= (gdk_gl_get_glPixelTexGenParameteriSGIS ()     != NULL);
          supported &= (gdk_gl_get_glPixelTexGenParameterivSGIS ()    != NULL);
          supported &= (gdk_gl_get_glPixelTexGenParameterfSGIS ()     != NULL);
          supported &= (gdk_gl_get_glPixelTexGenParameterfvSGIS ()    != NULL);
          supported &= (gdk_gl_get_glGetPixelTexGenParameterivSGIS () != NULL);
          supported &= (gdk_gl_get_glGetPixelTexGenParameterfvSGIS () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_pixel_texture));
}

/* 
 * GL_SGIS_texture4D
 */

static GdkGL_GL_SGIS_texture4D _GDK_GL_PROCS (GdkGL_GL_SGIS_texture4D) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture4D), glTexImage4DSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture4D), glTexSubImage4DSGIS)

GdkGL_GL_SGIS_texture4D *
gdk_gl_get_GL_SGIS_texture4D (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_texture4D ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_texture4D");

      if (supported)
        {
          supported &= (gdk_gl_get_glTexImage4DSGIS ()    != NULL);
          supported &= (gdk_gl_get_glTexSubImage4DSGIS () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_texture4D));
}

/* 
 * GL_EXT_texture_object
 */

static GdkGL_GL_EXT_texture_object _GDK_GL_PROCS (GdkGL_GL_EXT_texture_object) = {
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture_object), glAreTexturesResidentEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture_object), glBindTextureEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture_object), glDeleteTexturesEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture_object), glGenTexturesEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture_object), glIsTextureEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture_object), glPrioritizeTexturesEXT)

GdkGL_GL_EXT_texture_object *
gdk_gl_get_GL_EXT_texture_object (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_texture_object ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_texture_object");

      if (supported)
        {
          supported &= (gdk_gl_get_glAreTexturesResidentEXT () != NULL);
          supported &= (gdk_gl_get_glBindTextureEXT ()         != NULL);
          supported &= (gdk_gl_get_glDeleteTexturesEXT ()      != NULL);
          supported &= (gdk_gl_get_glGenTexturesEXT ()         != NULL);
          supported &= (gdk_gl_get_glIsTextureEXT ()           != NULL);
          supported &= (gdk_gl_get_glPrioritizeTexturesEXT ()  != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_texture_object));
}

/* 
 * GL_SGIS_detail_texture
 */

static GdkGL_GL_SGIS_detail_texture _GDK_GL_PROCS (GdkGL_GL_SGIS_detail_texture) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_detail_texture), glDetailTexFuncSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_detail_texture), glGetDetailTexFuncSGIS)

GdkGL_GL_SGIS_detail_texture *
gdk_gl_get_GL_SGIS_detail_texture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_detail_texture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_detail_texture");

      if (supported)
        {
          supported &= (gdk_gl_get_glDetailTexFuncSGIS ()    != NULL);
          supported &= (gdk_gl_get_glGetDetailTexFuncSGIS () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_detail_texture));
}

/* 
 * GL_SGIS_sharpen_texture
 */

static GdkGL_GL_SGIS_sharpen_texture _GDK_GL_PROCS (GdkGL_GL_SGIS_sharpen_texture) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_sharpen_texture), glSharpenTexFuncSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_sharpen_texture), glGetSharpenTexFuncSGIS)

GdkGL_GL_SGIS_sharpen_texture *
gdk_gl_get_GL_SGIS_sharpen_texture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_sharpen_texture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_sharpen_texture");

      if (supported)
        {
          supported &= (gdk_gl_get_glSharpenTexFuncSGIS ()    != NULL);
          supported &= (gdk_gl_get_glGetSharpenTexFuncSGIS () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_sharpen_texture));
}

/* 
 * GL_SGIS_multisample
 */

static GdkGL_GL_SGIS_multisample _GDK_GL_PROCS (GdkGL_GL_SGIS_multisample) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_multisample), glSampleMaskSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_multisample), glSamplePatternSGIS)

GdkGL_GL_SGIS_multisample *
gdk_gl_get_GL_SGIS_multisample (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_multisample ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_multisample");

      if (supported)
        {
          supported &= (gdk_gl_get_glSampleMaskSGIS ()    != NULL);
          supported &= (gdk_gl_get_glSamplePatternSGIS () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_multisample));
}

/* 
 * GL_EXT_vertex_array
 */

static GdkGL_GL_EXT_vertex_array _GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glArrayElementEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glColorPointerEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glDrawArraysEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glEdgeFlagPointerEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glGetPointervEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glIndexPointerEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glNormalPointerEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glTexCoordPointerEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array), glVertexPointerEXT)

GdkGL_GL_EXT_vertex_array *
gdk_gl_get_GL_EXT_vertex_array (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_vertex_array ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_vertex_array");

      if (supported)
        {
          supported &= (gdk_gl_get_glArrayElementEXT ()    != NULL);
          supported &= (gdk_gl_get_glColorPointerEXT ()    != NULL);
          supported &= (gdk_gl_get_glDrawArraysEXT ()      != NULL);
          supported &= (gdk_gl_get_glEdgeFlagPointerEXT () != NULL);
          supported &= (gdk_gl_get_glGetPointervEXT ()     != NULL);
          supported &= (gdk_gl_get_glIndexPointerEXT ()    != NULL);
          supported &= (gdk_gl_get_glNormalPointerEXT ()   != NULL);
          supported &= (gdk_gl_get_glTexCoordPointerEXT () != NULL);
          supported &= (gdk_gl_get_glVertexPointerEXT ()   != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_array));
}

/* 
 * GL_EXT_blend_minmax
 */

static GdkGL_GL_EXT_blend_minmax _GDK_GL_PROCS (GdkGL_GL_EXT_blend_minmax) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_blend_minmax), glBlendEquationEXT)

GdkGL_GL_EXT_blend_minmax *
gdk_gl_get_GL_EXT_blend_minmax (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_blend_minmax ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_blend_minmax");

      if (supported)
        {
          supported &= (gdk_gl_get_glBlendEquationEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_blend_minmax));
}

/* 
 * GL_SGIX_sprite
 */

static GdkGL_GL_SGIX_sprite _GDK_GL_PROCS (GdkGL_GL_SGIX_sprite) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_sprite), glSpriteParameterfSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_sprite), glSpriteParameterfvSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_sprite), glSpriteParameteriSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_sprite), glSpriteParameterivSGIX)

GdkGL_GL_SGIX_sprite *
gdk_gl_get_GL_SGIX_sprite (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_sprite ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_sprite");

      if (supported)
        {
          supported &= (gdk_gl_get_glSpriteParameterfSGIX ()  != NULL);
          supported &= (gdk_gl_get_glSpriteParameterfvSGIX () != NULL);
          supported &= (gdk_gl_get_glSpriteParameteriSGIX ()  != NULL);
          supported &= (gdk_gl_get_glSpriteParameterivSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_sprite));
}

/* 
 * GL_EXT_point_parameters
 */

static GdkGL_GL_EXT_point_parameters _GDK_GL_PROCS (GdkGL_GL_EXT_point_parameters) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_point_parameters), glPointParameterfEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_point_parameters), glPointParameterfvEXT)

GdkGL_GL_EXT_point_parameters *
gdk_gl_get_GL_EXT_point_parameters (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_point_parameters ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_point_parameters");

      if (supported)
        {
          supported &= (gdk_gl_get_glPointParameterfEXT ()  != NULL);
          supported &= (gdk_gl_get_glPointParameterfvEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_point_parameters));
}

/* 
 * GL_SGIS_point_parameters
 */

static GdkGL_GL_SGIS_point_parameters _GDK_GL_PROCS (GdkGL_GL_SGIS_point_parameters) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_point_parameters), glPointParameterfSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_point_parameters), glPointParameterfvSGIS)

GdkGL_GL_SGIS_point_parameters *
gdk_gl_get_GL_SGIS_point_parameters (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_point_parameters ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_point_parameters");

      if (supported)
        {
          supported &= (gdk_gl_get_glPointParameterfSGIS ()  != NULL);
          supported &= (gdk_gl_get_glPointParameterfvSGIS () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_point_parameters));
}

/* 
 * GL_SGIX_instruments
 */

static GdkGL_GL_SGIX_instruments _GDK_GL_PROCS (GdkGL_GL_SGIX_instruments) = {
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_instruments), glGetInstrumentsSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_instruments), glInstrumentsBufferSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_instruments), glPollInstrumentsSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_instruments), glReadInstrumentsSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_instruments), glStartInstrumentsSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_instruments), glStopInstrumentsSGIX)

GdkGL_GL_SGIX_instruments *
gdk_gl_get_GL_SGIX_instruments (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_instruments ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_instruments");

      if (supported)
        {
          supported &= (gdk_gl_get_glGetInstrumentsSGIX ()    != NULL);
          supported &= (gdk_gl_get_glInstrumentsBufferSGIX () != NULL);
          supported &= (gdk_gl_get_glPollInstrumentsSGIX ()   != NULL);
          supported &= (gdk_gl_get_glReadInstrumentsSGIX ()   != NULL);
          supported &= (gdk_gl_get_glStartInstrumentsSGIX ()  != NULL);
          supported &= (gdk_gl_get_glStopInstrumentsSGIX ()   != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_instruments));
}

/* 
 * GL_SGIX_framezoom
 */

static GdkGL_GL_SGIX_framezoom _GDK_GL_PROCS (GdkGL_GL_SGIX_framezoom) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_framezoom), glFrameZoomSGIX)

GdkGL_GL_SGIX_framezoom *
gdk_gl_get_GL_SGIX_framezoom (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_framezoom ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_framezoom");

      if (supported)
        {
          supported &= (gdk_gl_get_glFrameZoomSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_framezoom));
}

/* 
 * GL_SGIX_tag_sample_buffer
 */

static GdkGL_GL_SGIX_tag_sample_buffer _GDK_GL_PROCS (GdkGL_GL_SGIX_tag_sample_buffer) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_tag_sample_buffer), glTagSampleBufferSGIX)

GdkGL_GL_SGIX_tag_sample_buffer *
gdk_gl_get_GL_SGIX_tag_sample_buffer (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_tag_sample_buffer ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_tag_sample_buffer");

      if (supported)
        {
          supported &= (gdk_gl_get_glTagSampleBufferSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_tag_sample_buffer));
}

/* 
 * GL_SGIX_polynomial_ffd
 */

static GdkGL_GL_SGIX_polynomial_ffd _GDK_GL_PROCS (GdkGL_GL_SGIX_polynomial_ffd) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_polynomial_ffd), glDeformationMap3dSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_polynomial_ffd), glDeformationMap3fSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_polynomial_ffd), glDeformSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_polynomial_ffd), glLoadIdentityDeformationMapSGIX)

GdkGL_GL_SGIX_polynomial_ffd *
gdk_gl_get_GL_SGIX_polynomial_ffd (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_polynomial_ffd ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_polynomial_ffd");

      if (supported)
        {
          supported &= (gdk_gl_get_glDeformationMap3dSGIX ()           != NULL);
          supported &= (gdk_gl_get_glDeformationMap3fSGIX ()           != NULL);
          supported &= (gdk_gl_get_glDeformSGIX ()                     != NULL);
          supported &= (gdk_gl_get_glLoadIdentityDeformationMapSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_polynomial_ffd));
}

/* 
 * GL_SGIX_reference_plane
 */

static GdkGL_GL_SGIX_reference_plane _GDK_GL_PROCS (GdkGL_GL_SGIX_reference_plane) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_reference_plane), glReferencePlaneSGIX)

GdkGL_GL_SGIX_reference_plane *
gdk_gl_get_GL_SGIX_reference_plane (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_reference_plane ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_reference_plane");

      if (supported)
        {
          supported &= (gdk_gl_get_glReferencePlaneSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_reference_plane));
}

/* 
 * GL_SGIX_flush_raster
 */

static GdkGL_GL_SGIX_flush_raster _GDK_GL_PROCS (GdkGL_GL_SGIX_flush_raster) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_flush_raster), glFlushRasterSGIX)

GdkGL_GL_SGIX_flush_raster *
gdk_gl_get_GL_SGIX_flush_raster (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_flush_raster ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_flush_raster");

      if (supported)
        {
          supported &= (gdk_gl_get_glFlushRasterSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_flush_raster));
}

/* 
 * GL_SGIS_fog_function
 */

static GdkGL_GL_SGIS_fog_function _GDK_GL_PROCS (GdkGL_GL_SGIS_fog_function) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_fog_function), glFogFuncSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_fog_function), glGetFogFuncSGIS)

GdkGL_GL_SGIS_fog_function *
gdk_gl_get_GL_SGIS_fog_function (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_fog_function ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_fog_function");

      if (supported)
        {
          supported &= (gdk_gl_get_glFogFuncSGIS ()    != NULL);
          supported &= (gdk_gl_get_glGetFogFuncSGIS () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_fog_function));
}

/* 
 * GL_HP_image_transform
 */

static GdkGL_GL_HP_image_transform _GDK_GL_PROCS (GdkGL_GL_HP_image_transform) = {
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_HP_image_transform), glImageTransformParameteriHP)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_HP_image_transform), glImageTransformParameterfHP)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_HP_image_transform), glImageTransformParameterivHP)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_HP_image_transform), glImageTransformParameterfvHP)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_HP_image_transform), glGetImageTransformParameterivHP)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_HP_image_transform), glGetImageTransformParameterfvHP)

GdkGL_GL_HP_image_transform *
gdk_gl_get_GL_HP_image_transform (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_HP_image_transform ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_HP_image_transform");

      if (supported)
        {
          supported &= (gdk_gl_get_glImageTransformParameteriHP ()     != NULL);
          supported &= (gdk_gl_get_glImageTransformParameterfHP ()     != NULL);
          supported &= (gdk_gl_get_glImageTransformParameterivHP ()    != NULL);
          supported &= (gdk_gl_get_glImageTransformParameterfvHP ()    != NULL);
          supported &= (gdk_gl_get_glGetImageTransformParameterivHP () != NULL);
          supported &= (gdk_gl_get_glGetImageTransformParameterfvHP () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_HP_image_transform));
}

/* 
 * GL_EXT_color_subtable
 */

static GdkGL_GL_EXT_color_subtable _GDK_GL_PROCS (GdkGL_GL_EXT_color_subtable) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_color_subtable), glColorSubTableEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_color_subtable), glCopyColorSubTableEXT)

GdkGL_GL_EXT_color_subtable *
gdk_gl_get_GL_EXT_color_subtable (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_color_subtable ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_color_subtable");

      if (supported)
        {
          supported &= (gdk_gl_get_glColorSubTableEXT ()     != NULL);
          supported &= (gdk_gl_get_glCopyColorSubTableEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_color_subtable));
}

/* 
 * GL_PGI_misc_hints
 */

static GdkGL_GL_PGI_misc_hints _GDK_GL_PROCS (GdkGL_GL_PGI_misc_hints) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_PGI_misc_hints), glHintPGI)

GdkGL_GL_PGI_misc_hints *
gdk_gl_get_GL_PGI_misc_hints (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_PGI_misc_hints ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_PGI_misc_hints");

      if (supported)
        {
          supported &= (gdk_gl_get_glHintPGI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_PGI_misc_hints));
}

/* 
 * GL_EXT_paletted_texture
 */

static GdkGL_GL_EXT_paletted_texture _GDK_GL_PROCS (GdkGL_GL_EXT_paletted_texture) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_paletted_texture), glColorTableEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_paletted_texture), glGetColorTableEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_paletted_texture), glGetColorTableParameterivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_paletted_texture), glGetColorTableParameterfvEXT)

GdkGL_GL_EXT_paletted_texture *
gdk_gl_get_GL_EXT_paletted_texture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_paletted_texture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_paletted_texture");

      if (supported)
        {
          supported &= (gdk_gl_get_glColorTableEXT ()               != NULL);
          supported &= (gdk_gl_get_glGetColorTableEXT ()            != NULL);
          supported &= (gdk_gl_get_glGetColorTableParameterivEXT () != NULL);
          supported &= (gdk_gl_get_glGetColorTableParameterfvEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_paletted_texture));
}

/* 
 * GL_SGIX_list_priority
 */

static GdkGL_GL_SGIX_list_priority _GDK_GL_PROCS (GdkGL_GL_SGIX_list_priority) = {
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_list_priority), glGetListParameterfvSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_list_priority), glGetListParameterivSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_list_priority), glListParameterfSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_list_priority), glListParameterfvSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_list_priority), glListParameteriSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_list_priority), glListParameterivSGIX)

GdkGL_GL_SGIX_list_priority *
gdk_gl_get_GL_SGIX_list_priority (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_list_priority ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_list_priority");

      if (supported)
        {
          supported &= (gdk_gl_get_glGetListParameterfvSGIX () != NULL);
          supported &= (gdk_gl_get_glGetListParameterivSGIX () != NULL);
          supported &= (gdk_gl_get_glListParameterfSGIX ()     != NULL);
          supported &= (gdk_gl_get_glListParameterfvSGIX ()    != NULL);
          supported &= (gdk_gl_get_glListParameteriSGIX ()     != NULL);
          supported &= (gdk_gl_get_glListParameterivSGIX ()    != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_list_priority));
}

/* 
 * GL_EXT_index_material
 */

static GdkGL_GL_EXT_index_material _GDK_GL_PROCS (GdkGL_GL_EXT_index_material) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_index_material), glIndexMaterialEXT)

GdkGL_GL_EXT_index_material *
gdk_gl_get_GL_EXT_index_material (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_index_material ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_index_material");

      if (supported)
        {
          supported &= (gdk_gl_get_glIndexMaterialEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_index_material));
}

/* 
 * GL_EXT_index_func
 */

static GdkGL_GL_EXT_index_func _GDK_GL_PROCS (GdkGL_GL_EXT_index_func) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_index_func), glIndexFuncEXT)

GdkGL_GL_EXT_index_func *
gdk_gl_get_GL_EXT_index_func (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_index_func ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_index_func");

      if (supported)
        {
          supported &= (gdk_gl_get_glIndexFuncEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_index_func));
}

/* 
 * GL_EXT_compiled_vertex_array
 */

static GdkGL_GL_EXT_compiled_vertex_array _GDK_GL_PROCS (GdkGL_GL_EXT_compiled_vertex_array) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_compiled_vertex_array), glLockArraysEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_compiled_vertex_array), glUnlockArraysEXT)

GdkGL_GL_EXT_compiled_vertex_array *
gdk_gl_get_GL_EXT_compiled_vertex_array (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_compiled_vertex_array ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_compiled_vertex_array");

      if (supported)
        {
          supported &= (gdk_gl_get_glLockArraysEXT ()   != NULL);
          supported &= (gdk_gl_get_glUnlockArraysEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_compiled_vertex_array));
}

/* 
 * GL_EXT_cull_vertex
 */

static GdkGL_GL_EXT_cull_vertex _GDK_GL_PROCS (GdkGL_GL_EXT_cull_vertex) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_cull_vertex), glCullParameterdvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_cull_vertex), glCullParameterfvEXT)

GdkGL_GL_EXT_cull_vertex *
gdk_gl_get_GL_EXT_cull_vertex (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_cull_vertex ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_cull_vertex");

      if (supported)
        {
          supported &= (gdk_gl_get_glCullParameterdvEXT () != NULL);
          supported &= (gdk_gl_get_glCullParameterfvEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_cull_vertex));
}

/* 
 * GL_SGIX_fragment_lighting
 */

static GdkGL_GL_SGIX_fragment_lighting _GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentColorMaterialSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentLightfSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentLightfvSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentLightiSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentLightivSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentLightModelfSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentLightModelfvSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentLightModeliSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentLightModelivSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentMaterialfSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentMaterialfvSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentMaterialiSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glFragmentMaterialivSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glGetFragmentLightfvSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glGetFragmentLightivSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glGetFragmentMaterialfvSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glGetFragmentMaterialivSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting), glLightEnviSGIX)

GdkGL_GL_SGIX_fragment_lighting *
gdk_gl_get_GL_SGIX_fragment_lighting (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_fragment_lighting ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_fragment_lighting");

      if (supported)
        {
          supported &= (gdk_gl_get_glFragmentColorMaterialSGIX () != NULL);
          supported &= (gdk_gl_get_glFragmentLightfSGIX ()        != NULL);
          supported &= (gdk_gl_get_glFragmentLightfvSGIX ()       != NULL);
          supported &= (gdk_gl_get_glFragmentLightiSGIX ()        != NULL);
          supported &= (gdk_gl_get_glFragmentLightivSGIX ()       != NULL);
          supported &= (gdk_gl_get_glFragmentLightModelfSGIX ()   != NULL);
          supported &= (gdk_gl_get_glFragmentLightModelfvSGIX ()  != NULL);
          supported &= (gdk_gl_get_glFragmentLightModeliSGIX ()   != NULL);
          supported &= (gdk_gl_get_glFragmentLightModelivSGIX ()  != NULL);
          supported &= (gdk_gl_get_glFragmentMaterialfSGIX ()     != NULL);
          supported &= (gdk_gl_get_glFragmentMaterialfvSGIX ()    != NULL);
          supported &= (gdk_gl_get_glFragmentMaterialiSGIX ()     != NULL);
          supported &= (gdk_gl_get_glFragmentMaterialivSGIX ()    != NULL);
          supported &= (gdk_gl_get_glGetFragmentLightfvSGIX ()    != NULL);
          supported &= (gdk_gl_get_glGetFragmentLightivSGIX ()    != NULL);
          supported &= (gdk_gl_get_glGetFragmentMaterialfvSGIX () != NULL);
          supported &= (gdk_gl_get_glGetFragmentMaterialivSGIX () != NULL);
          supported &= (gdk_gl_get_glLightEnviSGIX ()             != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_fragment_lighting));
}

/* 
 * GL_EXT_draw_range_elements
 */

static GdkGL_GL_EXT_draw_range_elements _GDK_GL_PROCS (GdkGL_GL_EXT_draw_range_elements) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_draw_range_elements), glDrawRangeElementsEXT)

GdkGL_GL_EXT_draw_range_elements *
gdk_gl_get_GL_EXT_draw_range_elements (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_draw_range_elements ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_draw_range_elements");

      if (supported)
        {
          supported &= (gdk_gl_get_glDrawRangeElementsEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_draw_range_elements));
}

/* 
 * GL_EXT_light_texture
 */

static GdkGL_GL_EXT_light_texture _GDK_GL_PROCS (GdkGL_GL_EXT_light_texture) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_light_texture), glApplyTextureEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_light_texture), glTextureLightEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_light_texture), glTextureMaterialEXT)

GdkGL_GL_EXT_light_texture *
gdk_gl_get_GL_EXT_light_texture (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_light_texture ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_light_texture");

      if (supported)
        {
          supported &= (gdk_gl_get_glApplyTextureEXT ()    != NULL);
          supported &= (gdk_gl_get_glTextureLightEXT ()    != NULL);
          supported &= (gdk_gl_get_glTextureMaterialEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_light_texture));
}

/* 
 * GL_SGIX_async
 */

static GdkGL_GL_SGIX_async _GDK_GL_PROCS (GdkGL_GL_SGIX_async) = {
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_async), glAsyncMarkerSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_async), glFinishAsyncSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_async), glPollAsyncSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_async), glGenAsyncMarkersSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_async), glDeleteAsyncMarkersSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_async), glIsAsyncMarkerSGIX)

GdkGL_GL_SGIX_async *
gdk_gl_get_GL_SGIX_async (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_async ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_async");

      if (supported)
        {
          supported &= (gdk_gl_get_glAsyncMarkerSGIX ()        != NULL);
          supported &= (gdk_gl_get_glFinishAsyncSGIX ()        != NULL);
          supported &= (gdk_gl_get_glPollAsyncSGIX ()          != NULL);
          supported &= (gdk_gl_get_glGenAsyncMarkersSGIX ()    != NULL);
          supported &= (gdk_gl_get_glDeleteAsyncMarkersSGIX () != NULL);
          supported &= (gdk_gl_get_glIsAsyncMarkerSGIX ()      != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_async));
}

/* 
 * GL_INTEL_parallel_arrays
 */

static GdkGL_GL_INTEL_parallel_arrays _GDK_GL_PROCS (GdkGL_GL_INTEL_parallel_arrays) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_INTEL_parallel_arrays), glVertexPointervINTEL)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_INTEL_parallel_arrays), glNormalPointervINTEL)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_INTEL_parallel_arrays), glColorPointervINTEL)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_INTEL_parallel_arrays), glTexCoordPointervINTEL)

GdkGL_GL_INTEL_parallel_arrays *
gdk_gl_get_GL_INTEL_parallel_arrays (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_INTEL_parallel_arrays ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_INTEL_parallel_arrays");

      if (supported)
        {
          supported &= (gdk_gl_get_glVertexPointervINTEL ()   != NULL);
          supported &= (gdk_gl_get_glNormalPointervINTEL ()   != NULL);
          supported &= (gdk_gl_get_glColorPointervINTEL ()    != NULL);
          supported &= (gdk_gl_get_glTexCoordPointervINTEL () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_INTEL_parallel_arrays));
}

/* 
 * GL_EXT_pixel_transform
 */

static GdkGL_GL_EXT_pixel_transform _GDK_GL_PROCS (GdkGL_GL_EXT_pixel_transform) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_pixel_transform), glPixelTransformParameteriEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_pixel_transform), glPixelTransformParameterfEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_pixel_transform), glPixelTransformParameterivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_pixel_transform), glPixelTransformParameterfvEXT)

GdkGL_GL_EXT_pixel_transform *
gdk_gl_get_GL_EXT_pixel_transform (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_pixel_transform ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_pixel_transform");

      if (supported)
        {
          supported &= (gdk_gl_get_glPixelTransformParameteriEXT ()  != NULL);
          supported &= (gdk_gl_get_glPixelTransformParameterfEXT ()  != NULL);
          supported &= (gdk_gl_get_glPixelTransformParameterivEXT () != NULL);
          supported &= (gdk_gl_get_glPixelTransformParameterfvEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_pixel_transform));
}

/* 
 * GL_EXT_secondary_color
 */

static GdkGL_GL_EXT_secondary_color _GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3bEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3bvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3dEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3dvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3fEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3fvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3iEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3ivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3sEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3svEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3ubEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3ubvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3uiEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3uivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3usEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColor3usvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color), glSecondaryColorPointerEXT)

GdkGL_GL_EXT_secondary_color *
gdk_gl_get_GL_EXT_secondary_color (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_secondary_color ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_secondary_color");

      if (supported)
        {
          supported &= (gdk_gl_get_glSecondaryColor3bEXT ()      != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3bvEXT ()     != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3dEXT ()      != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3dvEXT ()     != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3fEXT ()      != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3fvEXT ()     != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3iEXT ()      != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3ivEXT ()     != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3sEXT ()      != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3svEXT ()     != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3ubEXT ()     != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3ubvEXT ()    != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3uiEXT ()     != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3uivEXT ()    != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3usEXT ()     != NULL);
          supported &= (gdk_gl_get_glSecondaryColor3usvEXT ()    != NULL);
          supported &= (gdk_gl_get_glSecondaryColorPointerEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_secondary_color));
}

/* 
 * GL_EXT_texture_perturb_normal
 */

static GdkGL_GL_EXT_texture_perturb_normal _GDK_GL_PROCS (GdkGL_GL_EXT_texture_perturb_normal) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture_perturb_normal), glTextureNormalEXT)

GdkGL_GL_EXT_texture_perturb_normal *
gdk_gl_get_GL_EXT_texture_perturb_normal (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_texture_perturb_normal ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_texture_perturb_normal");

      if (supported)
        {
          supported &= (gdk_gl_get_glTextureNormalEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_texture_perturb_normal));
}

/* 
 * GL_EXT_multi_draw_arrays
 */

static GdkGL_GL_EXT_multi_draw_arrays _GDK_GL_PROCS (GdkGL_GL_EXT_multi_draw_arrays) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_multi_draw_arrays), glMultiDrawArraysEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_multi_draw_arrays), glMultiDrawElementsEXT)

GdkGL_GL_EXT_multi_draw_arrays *
gdk_gl_get_GL_EXT_multi_draw_arrays (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_multi_draw_arrays ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_multi_draw_arrays");

      if (supported)
        {
          supported &= (gdk_gl_get_glMultiDrawArraysEXT ()   != NULL);
          supported &= (gdk_gl_get_glMultiDrawElementsEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_multi_draw_arrays));
}

/* 
 * GL_EXT_fog_coord
 */

static GdkGL_GL_EXT_fog_coord _GDK_GL_PROCS (GdkGL_GL_EXT_fog_coord) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_fog_coord), glFogCoordfEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_fog_coord), glFogCoordfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_fog_coord), glFogCoorddEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_fog_coord), glFogCoorddvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_fog_coord), glFogCoordPointerEXT)

GdkGL_GL_EXT_fog_coord *
gdk_gl_get_GL_EXT_fog_coord (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_fog_coord ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_fog_coord");

      if (supported)
        {
          supported &= (gdk_gl_get_glFogCoordfEXT ()       != NULL);
          supported &= (gdk_gl_get_glFogCoordfvEXT ()      != NULL);
          supported &= (gdk_gl_get_glFogCoorddEXT ()       != NULL);
          supported &= (gdk_gl_get_glFogCoorddvEXT ()      != NULL);
          supported &= (gdk_gl_get_glFogCoordPointerEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_fog_coord));
}

/* 
 * GL_EXT_coordinate_frame
 */

static GdkGL_GL_EXT_coordinate_frame _GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3bEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3bvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3dEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3dvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3fEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3fvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3iEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3ivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3sEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangent3svEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3bEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3bvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3dEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3dvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3fEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3fvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3iEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3ivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3sEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormal3svEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glTangentPointerEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame), glBinormalPointerEXT)

GdkGL_GL_EXT_coordinate_frame *
gdk_gl_get_GL_EXT_coordinate_frame (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_coordinate_frame ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_coordinate_frame");

      if (supported)
        {
          supported &= (gdk_gl_get_glTangent3bEXT ()       != NULL);
          supported &= (gdk_gl_get_glTangent3bvEXT ()      != NULL);
          supported &= (gdk_gl_get_glTangent3dEXT ()       != NULL);
          supported &= (gdk_gl_get_glTangent3dvEXT ()      != NULL);
          supported &= (gdk_gl_get_glTangent3fEXT ()       != NULL);
          supported &= (gdk_gl_get_glTangent3fvEXT ()      != NULL);
          supported &= (gdk_gl_get_glTangent3iEXT ()       != NULL);
          supported &= (gdk_gl_get_glTangent3ivEXT ()      != NULL);
          supported &= (gdk_gl_get_glTangent3sEXT ()       != NULL);
          supported &= (gdk_gl_get_glTangent3svEXT ()      != NULL);
          supported &= (gdk_gl_get_glBinormal3bEXT ()      != NULL);
          supported &= (gdk_gl_get_glBinormal3bvEXT ()     != NULL);
          supported &= (gdk_gl_get_glBinormal3dEXT ()      != NULL);
          supported &= (gdk_gl_get_glBinormal3dvEXT ()     != NULL);
          supported &= (gdk_gl_get_glBinormal3fEXT ()      != NULL);
          supported &= (gdk_gl_get_glBinormal3fvEXT ()     != NULL);
          supported &= (gdk_gl_get_glBinormal3iEXT ()      != NULL);
          supported &= (gdk_gl_get_glBinormal3ivEXT ()     != NULL);
          supported &= (gdk_gl_get_glBinormal3sEXT ()      != NULL);
          supported &= (gdk_gl_get_glBinormal3svEXT ()     != NULL);
          supported &= (gdk_gl_get_glTangentPointerEXT ()  != NULL);
          supported &= (gdk_gl_get_glBinormalPointerEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_coordinate_frame));
}

/* 
 * GL_SUNX_constant_data
 */

static GdkGL_GL_SUNX_constant_data _GDK_GL_PROCS (GdkGL_GL_SUNX_constant_data) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUNX_constant_data), glFinishTextureSUNX)

GdkGL_GL_SUNX_constant_data *
gdk_gl_get_GL_SUNX_constant_data (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SUNX_constant_data ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SUNX_constant_data");

      if (supported)
        {
          supported &= (gdk_gl_get_glFinishTextureSUNX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SUNX_constant_data));
}

/* 
 * GL_SUN_global_alpha
 */

static GdkGL_GL_SUN_global_alpha _GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha), glGlobalAlphaFactorbSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha), glGlobalAlphaFactorsSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha), glGlobalAlphaFactoriSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha), glGlobalAlphaFactorfSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha), glGlobalAlphaFactordSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha), glGlobalAlphaFactorubSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha), glGlobalAlphaFactorusSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha), glGlobalAlphaFactoruiSUN)

GdkGL_GL_SUN_global_alpha *
gdk_gl_get_GL_SUN_global_alpha (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SUN_global_alpha ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SUN_global_alpha");

      if (supported)
        {
          supported &= (gdk_gl_get_glGlobalAlphaFactorbSUN ()  != NULL);
          supported &= (gdk_gl_get_glGlobalAlphaFactorsSUN ()  != NULL);
          supported &= (gdk_gl_get_glGlobalAlphaFactoriSUN ()  != NULL);
          supported &= (gdk_gl_get_glGlobalAlphaFactorfSUN ()  != NULL);
          supported &= (gdk_gl_get_glGlobalAlphaFactordSUN ()  != NULL);
          supported &= (gdk_gl_get_glGlobalAlphaFactorubSUN () != NULL);
          supported &= (gdk_gl_get_glGlobalAlphaFactorusSUN () != NULL);
          supported &= (gdk_gl_get_glGlobalAlphaFactoruiSUN () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SUN_global_alpha));
}

/* 
 * GL_SUN_triangle_list
 */

static GdkGL_GL_SUN_triangle_list _GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list), glReplacementCodeuiSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list), glReplacementCodeusSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list), glReplacementCodeubSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list), glReplacementCodeuivSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list), glReplacementCodeusvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list), glReplacementCodeubvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list), glReplacementCodePointerSUN)

GdkGL_GL_SUN_triangle_list *
gdk_gl_get_GL_SUN_triangle_list (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SUN_triangle_list ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SUN_triangle_list");

      if (supported)
        {
          supported &= (gdk_gl_get_glReplacementCodeuiSUN ()      != NULL);
          supported &= (gdk_gl_get_glReplacementCodeusSUN ()      != NULL);
          supported &= (gdk_gl_get_glReplacementCodeubSUN ()      != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuivSUN ()     != NULL);
          supported &= (gdk_gl_get_glReplacementCodeusvSUN ()     != NULL);
          supported &= (gdk_gl_get_glReplacementCodeubvSUN ()     != NULL);
          supported &= (gdk_gl_get_glReplacementCodePointerSUN () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SUN_triangle_list));
}

/* 
 * GL_SUN_vertex
 */

static GdkGL_GL_SUN_vertex _GDK_GL_PROCS (GdkGL_GL_SUN_vertex) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glColor4ubVertex2fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glColor4ubVertex2fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glColor4ubVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glColor4ubVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glColor3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glColor3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glNormal3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glNormal3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glColor4fNormal3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glColor4fNormal3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord4fVertex4fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord4fVertex4fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fColor4ubVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fColor4ubVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fColor3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fColor3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fNormal3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fNormal3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fColor4fNormal3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord2fColor4fNormal3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord4fColor4fNormal3fVertex4fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glTexCoord4fColor4fNormal3fVertex4fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiColor4ubVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiColor4ubVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiColor3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiColor3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiNormal3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiNormal3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiColor4fNormal3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiColor4fNormal3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiTexCoord2fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiTexCoord2fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_vertex), glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)

GdkGL_GL_SUN_vertex *
gdk_gl_get_GL_SUN_vertex (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SUN_vertex ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SUN_vertex");

      if (supported)
        {
          supported &= (gdk_gl_get_glColor4ubVertex2fSUN ()                                    != NULL);
          supported &= (gdk_gl_get_glColor4ubVertex2fvSUN ()                                   != NULL);
          supported &= (gdk_gl_get_glColor4ubVertex3fSUN ()                                    != NULL);
          supported &= (gdk_gl_get_glColor4ubVertex3fvSUN ()                                   != NULL);
          supported &= (gdk_gl_get_glColor3fVertex3fSUN ()                                     != NULL);
          supported &= (gdk_gl_get_glColor3fVertex3fvSUN ()                                    != NULL);
          supported &= (gdk_gl_get_glNormal3fVertex3fSUN ()                                    != NULL);
          supported &= (gdk_gl_get_glNormal3fVertex3fvSUN ()                                   != NULL);
          supported &= (gdk_gl_get_glColor4fNormal3fVertex3fSUN ()                             != NULL);
          supported &= (gdk_gl_get_glColor4fNormal3fVertex3fvSUN ()                            != NULL);
          supported &= (gdk_gl_get_glTexCoord2fVertex3fSUN ()                                  != NULL);
          supported &= (gdk_gl_get_glTexCoord2fVertex3fvSUN ()                                 != NULL);
          supported &= (gdk_gl_get_glTexCoord4fVertex4fSUN ()                                  != NULL);
          supported &= (gdk_gl_get_glTexCoord4fVertex4fvSUN ()                                 != NULL);
          supported &= (gdk_gl_get_glTexCoord2fColor4ubVertex3fSUN ()                          != NULL);
          supported &= (gdk_gl_get_glTexCoord2fColor4ubVertex3fvSUN ()                         != NULL);
          supported &= (gdk_gl_get_glTexCoord2fColor3fVertex3fSUN ()                           != NULL);
          supported &= (gdk_gl_get_glTexCoord2fColor3fVertex3fvSUN ()                          != NULL);
          supported &= (gdk_gl_get_glTexCoord2fNormal3fVertex3fSUN ()                          != NULL);
          supported &= (gdk_gl_get_glTexCoord2fNormal3fVertex3fvSUN ()                         != NULL);
          supported &= (gdk_gl_get_glTexCoord2fColor4fNormal3fVertex3fSUN ()                   != NULL);
          supported &= (gdk_gl_get_glTexCoord2fColor4fNormal3fVertex3fvSUN ()                  != NULL);
          supported &= (gdk_gl_get_glTexCoord4fColor4fNormal3fVertex4fSUN ()                   != NULL);
          supported &= (gdk_gl_get_glTexCoord4fColor4fNormal3fVertex4fvSUN ()                  != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiVertex3fSUN ()                           != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiVertex3fvSUN ()                          != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiColor4ubVertex3fSUN ()                   != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiColor4ubVertex3fvSUN ()                  != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiColor3fVertex3fSUN ()                    != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiColor3fVertex3fvSUN ()                   != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiNormal3fVertex3fSUN ()                   != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiNormal3fVertex3fvSUN ()                  != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiColor4fNormal3fVertex3fSUN ()            != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiColor4fNormal3fVertex3fvSUN ()           != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiTexCoord2fVertex3fSUN ()                 != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiTexCoord2fVertex3fvSUN ()                != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN ()         != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN ()        != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN ()  != NULL);
          supported &= (gdk_gl_get_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SUN_vertex));
}

/* 
 * GL_EXT_blend_func_separate
 */

static GdkGL_GL_EXT_blend_func_separate _GDK_GL_PROCS (GdkGL_GL_EXT_blend_func_separate) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_blend_func_separate), glBlendFuncSeparateEXT)

GdkGL_GL_EXT_blend_func_separate *
gdk_gl_get_GL_EXT_blend_func_separate (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_blend_func_separate ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_blend_func_separate");

      if (supported)
        {
          supported &= (gdk_gl_get_glBlendFuncSeparateEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_blend_func_separate));
}

/* 
 * GL_INGR_blend_func_separate
 */

static GdkGL_GL_INGR_blend_func_separate _GDK_GL_PROCS (GdkGL_GL_INGR_blend_func_separate) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_INGR_blend_func_separate), glBlendFuncSeparateINGR)

GdkGL_GL_INGR_blend_func_separate *
gdk_gl_get_GL_INGR_blend_func_separate (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_INGR_blend_func_separate ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_INGR_blend_func_separate");

      if (supported)
        {
          supported &= (gdk_gl_get_glBlendFuncSeparateINGR () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_INGR_blend_func_separate));
}

/* 
 * GL_EXT_vertex_weighting
 */

static GdkGL_GL_EXT_vertex_weighting _GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting), glVertexWeightfEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting), glVertexWeightfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting), glVertexWeightPointerEXT)

GdkGL_GL_EXT_vertex_weighting *
gdk_gl_get_GL_EXT_vertex_weighting (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_vertex_weighting ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_vertex_weighting");

      if (supported)
        {
          supported &= (gdk_gl_get_glVertexWeightfEXT ()       != NULL);
          supported &= (gdk_gl_get_glVertexWeightfvEXT ()      != NULL);
          supported &= (gdk_gl_get_glVertexWeightPointerEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting));
}

/* 
 * GL_NV_vertex_array_range
 */

static GdkGL_GL_NV_vertex_array_range _GDK_GL_PROCS (GdkGL_GL_NV_vertex_array_range) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_array_range), glFlushVertexArrayRangeNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_array_range), glVertexArrayRangeNV)

GdkGL_GL_NV_vertex_array_range *
gdk_gl_get_GL_NV_vertex_array_range (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_NV_vertex_array_range ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_NV_vertex_array_range");

      if (supported)
        {
          supported &= (gdk_gl_get_glFlushVertexArrayRangeNV () != NULL);
          supported &= (gdk_gl_get_glVertexArrayRangeNV ()      != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_NV_vertex_array_range));
}

/* 
 * GL_NV_register_combiners
 */

static GdkGL_GL_NV_register_combiners _GDK_GL_PROCS (GdkGL_GL_NV_register_combiners) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glCombinerParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glCombinerParameterfNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glCombinerParameterivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glCombinerParameteriNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glCombinerInputNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glCombinerOutputNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glFinalCombinerInputNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glGetCombinerInputParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glGetCombinerInputParameterivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glGetCombinerOutputParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glGetCombinerOutputParameterivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glGetFinalCombinerInputParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners), glGetFinalCombinerInputParameterivNV)

GdkGL_GL_NV_register_combiners *
gdk_gl_get_GL_NV_register_combiners (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_NV_register_combiners ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_NV_register_combiners");

      if (supported)
        {
          supported &= (gdk_gl_get_glCombinerParameterfvNV ()              != NULL);
          supported &= (gdk_gl_get_glCombinerParameterfNV ()               != NULL);
          supported &= (gdk_gl_get_glCombinerParameterivNV ()              != NULL);
          supported &= (gdk_gl_get_glCombinerParameteriNV ()               != NULL);
          supported &= (gdk_gl_get_glCombinerInputNV ()                    != NULL);
          supported &= (gdk_gl_get_glCombinerOutputNV ()                   != NULL);
          supported &= (gdk_gl_get_glFinalCombinerInputNV ()               != NULL);
          supported &= (gdk_gl_get_glGetCombinerInputParameterfvNV ()      != NULL);
          supported &= (gdk_gl_get_glGetCombinerInputParameterivNV ()      != NULL);
          supported &= (gdk_gl_get_glGetCombinerOutputParameterfvNV ()     != NULL);
          supported &= (gdk_gl_get_glGetCombinerOutputParameterivNV ()     != NULL);
          supported &= (gdk_gl_get_glGetFinalCombinerInputParameterfvNV () != NULL);
          supported &= (gdk_gl_get_glGetFinalCombinerInputParameterivNV () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners));
}

/* 
 * GL_MESA_resize_buffers
 */

static GdkGL_GL_MESA_resize_buffers _GDK_GL_PROCS (GdkGL_GL_MESA_resize_buffers) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_resize_buffers), glResizeBuffersMESA)

GdkGL_GL_MESA_resize_buffers *
gdk_gl_get_GL_MESA_resize_buffers (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_MESA_resize_buffers ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_MESA_resize_buffers");

      if (supported)
        {
          supported &= (gdk_gl_get_glResizeBuffersMESA () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_MESA_resize_buffers));
}

/* 
 * GL_MESA_window_pos
 */

static GdkGL_GL_MESA_window_pos _GDK_GL_PROCS (GdkGL_GL_MESA_window_pos) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos2dMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos2dvMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos2fMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos2fvMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos2iMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos2ivMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos2sMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos2svMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos3dMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos3dvMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos3fMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos3fvMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos3iMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos3ivMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos3sMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos3svMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos4dMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos4dvMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos4fMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos4fvMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos4iMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos4ivMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos4sMESA)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos), glWindowPos4svMESA)

GdkGL_GL_MESA_window_pos *
gdk_gl_get_GL_MESA_window_pos (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_MESA_window_pos ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_MESA_window_pos");

      if (supported)
        {
          supported &= (gdk_gl_get_glWindowPos2dMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos2dvMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos2fMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos2fvMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos2iMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos2ivMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos2sMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos2svMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos3dMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos3dvMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos3fMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos3fvMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos3iMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos3ivMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos3sMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos3svMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos4dMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos4dvMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos4fMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos4fvMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos4iMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos4ivMESA () != NULL);
          supported &= (gdk_gl_get_glWindowPos4sMESA ()  != NULL);
          supported &= (gdk_gl_get_glWindowPos4svMESA () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_MESA_window_pos));
}

/* 
 * GL_IBM_multimode_draw_arrays
 */

static GdkGL_GL_IBM_multimode_draw_arrays _GDK_GL_PROCS (GdkGL_GL_IBM_multimode_draw_arrays) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_multimode_draw_arrays), glMultiModeDrawArraysIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_multimode_draw_arrays), glMultiModeDrawElementsIBM)

GdkGL_GL_IBM_multimode_draw_arrays *
gdk_gl_get_GL_IBM_multimode_draw_arrays (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_IBM_multimode_draw_arrays ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_IBM_multimode_draw_arrays");

      if (supported)
        {
          supported &= (gdk_gl_get_glMultiModeDrawArraysIBM ()   != NULL);
          supported &= (gdk_gl_get_glMultiModeDrawElementsIBM () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_IBM_multimode_draw_arrays));
}

/* 
 * GL_IBM_vertex_array_lists
 */

static GdkGL_GL_IBM_vertex_array_lists _GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists), glColorPointerListIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists), glSecondaryColorPointerListIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists), glEdgeFlagPointerListIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists), glFogCoordPointerListIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists), glIndexPointerListIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists), glNormalPointerListIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists), glTexCoordPointerListIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists), glVertexPointerListIBM)

GdkGL_GL_IBM_vertex_array_lists *
gdk_gl_get_GL_IBM_vertex_array_lists (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_IBM_vertex_array_lists ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_IBM_vertex_array_lists");

      if (supported)
        {
          supported &= (gdk_gl_get_glColorPointerListIBM ()          != NULL);
          supported &= (gdk_gl_get_glSecondaryColorPointerListIBM () != NULL);
          supported &= (gdk_gl_get_glEdgeFlagPointerListIBM ()       != NULL);
          supported &= (gdk_gl_get_glFogCoordPointerListIBM ()       != NULL);
          supported &= (gdk_gl_get_glIndexPointerListIBM ()          != NULL);
          supported &= (gdk_gl_get_glNormalPointerListIBM ()         != NULL);
          supported &= (gdk_gl_get_glTexCoordPointerListIBM ()       != NULL);
          supported &= (gdk_gl_get_glVertexPointerListIBM ()         != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_IBM_vertex_array_lists));
}

/* 
 * GL_3DFX_tbuffer
 */

static GdkGL_GL_3DFX_tbuffer _GDK_GL_PROCS (GdkGL_GL_3DFX_tbuffer) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_3DFX_tbuffer), glTbufferMask3DFX)

GdkGL_GL_3DFX_tbuffer *
gdk_gl_get_GL_3DFX_tbuffer (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_3DFX_tbuffer ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_3DFX_tbuffer");

      if (supported)
        {
          supported &= (gdk_gl_get_glTbufferMask3DFX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_3DFX_tbuffer));
}

/* 
 * GL_EXT_multisample
 */

static GdkGL_GL_EXT_multisample _GDK_GL_PROCS (GdkGL_GL_EXT_multisample) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_multisample), glSampleMaskEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_multisample), glSamplePatternEXT)

GdkGL_GL_EXT_multisample *
gdk_gl_get_GL_EXT_multisample (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_multisample ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_multisample");

      if (supported)
        {
          supported &= (gdk_gl_get_glSampleMaskEXT ()    != NULL);
          supported &= (gdk_gl_get_glSamplePatternEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_multisample));
}

/* 
 * GL_SGIS_texture_color_mask
 */

static GdkGL_GL_SGIS_texture_color_mask _GDK_GL_PROCS (GdkGL_GL_SGIS_texture_color_mask) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture_color_mask), glTextureColorMaskSGIS)

GdkGL_GL_SGIS_texture_color_mask *
gdk_gl_get_GL_SGIS_texture_color_mask (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIS_texture_color_mask ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIS_texture_color_mask");

      if (supported)
        {
          supported &= (gdk_gl_get_glTextureColorMaskSGIS () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIS_texture_color_mask));
}

/* 
 * GL_SGIX_igloo_interface
 */

static GdkGL_GL_SGIX_igloo_interface _GDK_GL_PROCS (GdkGL_GL_SGIX_igloo_interface) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_igloo_interface), glIglooInterfaceSGIX)

GdkGL_GL_SGIX_igloo_interface *
gdk_gl_get_GL_SGIX_igloo_interface (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SGIX_igloo_interface ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SGIX_igloo_interface");

      if (supported)
        {
          supported &= (gdk_gl_get_glIglooInterfaceSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SGIX_igloo_interface));
}

/* 
 * GL_NV_fence
 */

static GdkGL_GL_NV_fence _GDK_GL_PROCS (GdkGL_GL_NV_fence) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_fence), glDeleteFencesNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_fence), glGenFencesNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_fence), glIsFenceNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_fence), glTestFenceNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_fence), glGetFenceivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_fence), glFinishFenceNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_fence), glSetFenceNV)

GdkGL_GL_NV_fence *
gdk_gl_get_GL_NV_fence (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_NV_fence ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_NV_fence");

      if (supported)
        {
          supported &= (gdk_gl_get_glDeleteFencesNV () != NULL);
          supported &= (gdk_gl_get_glGenFencesNV ()    != NULL);
          supported &= (gdk_gl_get_glIsFenceNV ()      != NULL);
          supported &= (gdk_gl_get_glTestFenceNV ()    != NULL);
          supported &= (gdk_gl_get_glGetFenceivNV ()   != NULL);
          supported &= (gdk_gl_get_glFinishFenceNV ()  != NULL);
          supported &= (gdk_gl_get_glSetFenceNV ()     != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_NV_fence));
}

/* 
 * GL_NV_evaluators
 */

static GdkGL_GL_NV_evaluators _GDK_GL_PROCS (GdkGL_GL_NV_evaluators) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glMapControlPointsNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glMapParameterivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glMapParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glGetMapControlPointsNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glGetMapParameterivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glGetMapParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glGetMapAttribParameterivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glGetMapAttribParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_evaluators), glEvalMapsNV)

GdkGL_GL_NV_evaluators *
gdk_gl_get_GL_NV_evaluators (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_NV_evaluators ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_NV_evaluators");

      if (supported)
        {
          supported &= (gdk_gl_get_glMapControlPointsNV ()        != NULL);
          supported &= (gdk_gl_get_glMapParameterivNV ()          != NULL);
          supported &= (gdk_gl_get_glMapParameterfvNV ()          != NULL);
          supported &= (gdk_gl_get_glGetMapControlPointsNV ()     != NULL);
          supported &= (gdk_gl_get_glGetMapParameterivNV ()       != NULL);
          supported &= (gdk_gl_get_glGetMapParameterfvNV ()       != NULL);
          supported &= (gdk_gl_get_glGetMapAttribParameterivNV () != NULL);
          supported &= (gdk_gl_get_glGetMapAttribParameterfvNV () != NULL);
          supported &= (gdk_gl_get_glEvalMapsNV ()                != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_NV_evaluators));
}

/* 
 * GL_NV_register_combiners2
 */

static GdkGL_GL_NV_register_combiners2 _GDK_GL_PROCS (GdkGL_GL_NV_register_combiners2) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners2), glCombinerStageParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners2), glGetCombinerStageParameterfvNV)

GdkGL_GL_NV_register_combiners2 *
gdk_gl_get_GL_NV_register_combiners2 (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_NV_register_combiners2 ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_NV_register_combiners2");

      if (supported)
        {
          supported &= (gdk_gl_get_glCombinerStageParameterfvNV ()    != NULL);
          supported &= (gdk_gl_get_glGetCombinerStageParameterfvNV () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners2));
}

/* 
 * GL_NV_vertex_program
 */

static GdkGL_GL_NV_vertex_program _GDK_GL_PROCS (GdkGL_GL_NV_vertex_program) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glAreProgramsResidentNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glBindProgramNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glDeleteProgramsNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glExecuteProgramNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGenProgramsNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetProgramParameterdvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetProgramParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetProgramivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetProgramStringNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetTrackMatrixivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetVertexAttribdvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetVertexAttribfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetVertexAttribivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glGetVertexAttribPointervNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glIsProgramNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glLoadProgramNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glProgramParameter4dNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glProgramParameter4dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glProgramParameter4fNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glProgramParameter4fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glProgramParameters4dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glProgramParameters4fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glRequestResidentProgramsNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glTrackMatrixNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribPointerNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib1dNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib1dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib1fNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib1fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib1sNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib1svNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib2dNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib2dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib2fNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib2fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib2sNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib2svNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib3dNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib3dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib3fNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib3fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib3sNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib3svNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib4dNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib4dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib4fNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib4fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib4sNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib4svNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib4ubNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttrib4ubvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs1dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs1fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs1svNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs2dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs2fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs2svNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs3dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs3fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs3svNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs4dvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs4fvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs4svNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program), glVertexAttribs4ubvNV)

GdkGL_GL_NV_vertex_program *
gdk_gl_get_GL_NV_vertex_program (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_NV_vertex_program ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_NV_vertex_program");

      if (supported)
        {
          supported &= (gdk_gl_get_glAreProgramsResidentNV ()     != NULL);
          supported &= (gdk_gl_get_glBindProgramNV ()             != NULL);
          supported &= (gdk_gl_get_glDeleteProgramsNV ()          != NULL);
          supported &= (gdk_gl_get_glExecuteProgramNV ()          != NULL);
          supported &= (gdk_gl_get_glGenProgramsNV ()             != NULL);
          supported &= (gdk_gl_get_glGetProgramParameterdvNV ()   != NULL);
          supported &= (gdk_gl_get_glGetProgramParameterfvNV ()   != NULL);
          supported &= (gdk_gl_get_glGetProgramivNV ()            != NULL);
          supported &= (gdk_gl_get_glGetProgramStringNV ()        != NULL);
          supported &= (gdk_gl_get_glGetTrackMatrixivNV ()        != NULL);
          supported &= (gdk_gl_get_glGetVertexAttribdvNV ()       != NULL);
          supported &= (gdk_gl_get_glGetVertexAttribfvNV ()       != NULL);
          supported &= (gdk_gl_get_glGetVertexAttribivNV ()       != NULL);
          supported &= (gdk_gl_get_glGetVertexAttribPointervNV () != NULL);
          supported &= (gdk_gl_get_glIsProgramNV ()               != NULL);
          supported &= (gdk_gl_get_glLoadProgramNV ()             != NULL);
          supported &= (gdk_gl_get_glProgramParameter4dNV ()      != NULL);
          supported &= (gdk_gl_get_glProgramParameter4dvNV ()     != NULL);
          supported &= (gdk_gl_get_glProgramParameter4fNV ()      != NULL);
          supported &= (gdk_gl_get_glProgramParameter4fvNV ()     != NULL);
          supported &= (gdk_gl_get_glProgramParameters4dvNV ()    != NULL);
          supported &= (gdk_gl_get_glProgramParameters4fvNV ()    != NULL);
          supported &= (gdk_gl_get_glRequestResidentProgramsNV () != NULL);
          supported &= (gdk_gl_get_glTrackMatrixNV ()             != NULL);
          supported &= (gdk_gl_get_glVertexAttribPointerNV ()     != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1dNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1dvNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1fNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1fvNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1sNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib1svNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2dNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2dvNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2fNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2fvNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2sNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib2svNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3dNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3dvNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3fNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3fvNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3sNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib3svNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4dNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4dvNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4fNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4fvNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4sNV ()          != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4svNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4ubNV ()         != NULL);
          supported &= (gdk_gl_get_glVertexAttrib4ubvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs1dvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs1fvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs1svNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs2dvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs2fvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs2svNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs3dvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs3fvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs3svNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs4dvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs4fvNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs4svNV ()        != NULL);
          supported &= (gdk_gl_get_glVertexAttribs4ubvNV ()       != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_NV_vertex_program));
}

/* 
 * GL_ATI_envmap_bumpmap
 */

static GdkGL_GL_ATI_envmap_bumpmap _GDK_GL_PROCS (GdkGL_GL_ATI_envmap_bumpmap) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_envmap_bumpmap), glTexBumpParameterivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_envmap_bumpmap), glTexBumpParameterfvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_envmap_bumpmap), glGetTexBumpParameterivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_envmap_bumpmap), glGetTexBumpParameterfvATI)

GdkGL_GL_ATI_envmap_bumpmap *
gdk_gl_get_GL_ATI_envmap_bumpmap (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ATI_envmap_bumpmap ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ATI_envmap_bumpmap");

      if (supported)
        {
          supported &= (gdk_gl_get_glTexBumpParameterivATI ()    != NULL);
          supported &= (gdk_gl_get_glTexBumpParameterfvATI ()    != NULL);
          supported &= (gdk_gl_get_glGetTexBumpParameterivATI () != NULL);
          supported &= (gdk_gl_get_glGetTexBumpParameterfvATI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ATI_envmap_bumpmap));
}

/* 
 * GL_ATI_fragment_shader
 */

static GdkGL_GL_ATI_fragment_shader _GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glGenFragmentShadersATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glBindFragmentShaderATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glDeleteFragmentShaderATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glBeginFragmentShaderATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glEndFragmentShaderATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glPassTexCoordATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glSampleMapATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glColorFragmentOp1ATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glColorFragmentOp2ATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glColorFragmentOp3ATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glAlphaFragmentOp1ATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glAlphaFragmentOp2ATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glAlphaFragmentOp3ATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader), glSetFragmentShaderConstantATI)

GdkGL_GL_ATI_fragment_shader *
gdk_gl_get_GL_ATI_fragment_shader (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ATI_fragment_shader ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ATI_fragment_shader");

      if (supported)
        {
          supported &= (gdk_gl_get_glGenFragmentShadersATI ()        != NULL);
          supported &= (gdk_gl_get_glBindFragmentShaderATI ()        != NULL);
          supported &= (gdk_gl_get_glDeleteFragmentShaderATI ()      != NULL);
          supported &= (gdk_gl_get_glBeginFragmentShaderATI ()       != NULL);
          supported &= (gdk_gl_get_glEndFragmentShaderATI ()         != NULL);
          supported &= (gdk_gl_get_glPassTexCoordATI ()              != NULL);
          supported &= (gdk_gl_get_glSampleMapATI ()                 != NULL);
          supported &= (gdk_gl_get_glColorFragmentOp1ATI ()          != NULL);
          supported &= (gdk_gl_get_glColorFragmentOp2ATI ()          != NULL);
          supported &= (gdk_gl_get_glColorFragmentOp3ATI ()          != NULL);
          supported &= (gdk_gl_get_glAlphaFragmentOp1ATI ()          != NULL);
          supported &= (gdk_gl_get_glAlphaFragmentOp2ATI ()          != NULL);
          supported &= (gdk_gl_get_glAlphaFragmentOp3ATI ()          != NULL);
          supported &= (gdk_gl_get_glSetFragmentShaderConstantATI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ATI_fragment_shader));
}

/* 
 * GL_ATI_pn_triangles
 */

static GdkGL_GL_ATI_pn_triangles _GDK_GL_PROCS (GdkGL_GL_ATI_pn_triangles) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_pn_triangles), glPNTrianglesiATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_pn_triangles), glPNTrianglesfATI)

GdkGL_GL_ATI_pn_triangles *
gdk_gl_get_GL_ATI_pn_triangles (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ATI_pn_triangles ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ATI_pn_triangles");

      if (supported)
        {
          supported &= (gdk_gl_get_glPNTrianglesiATI () != NULL);
          supported &= (gdk_gl_get_glPNTrianglesfATI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ATI_pn_triangles));
}

/* 
 * GL_ATI_vertex_array_object
 */

static GdkGL_GL_ATI_vertex_array_object _GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glNewObjectBufferATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glIsObjectBufferATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glUpdateObjectBufferATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glGetObjectBufferfvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glGetObjectBufferivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glDeleteObjectBufferATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glArrayObjectATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glGetArrayObjectfvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glGetArrayObjectivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glVariantArrayObjectATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glGetVariantArrayObjectfvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object), glGetVariantArrayObjectivATI)

GdkGL_GL_ATI_vertex_array_object *
gdk_gl_get_GL_ATI_vertex_array_object (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ATI_vertex_array_object ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ATI_vertex_array_object");

      if (supported)
        {
          supported &= (gdk_gl_get_glNewObjectBufferATI ()         != NULL);
          supported &= (gdk_gl_get_glIsObjectBufferATI ()          != NULL);
          supported &= (gdk_gl_get_glUpdateObjectBufferATI ()      != NULL);
          supported &= (gdk_gl_get_glGetObjectBufferfvATI ()       != NULL);
          supported &= (gdk_gl_get_glGetObjectBufferivATI ()       != NULL);
          supported &= (gdk_gl_get_glDeleteObjectBufferATI ()      != NULL);
          supported &= (gdk_gl_get_glArrayObjectATI ()             != NULL);
          supported &= (gdk_gl_get_glGetArrayObjectfvATI ()        != NULL);
          supported &= (gdk_gl_get_glGetArrayObjectivATI ()        != NULL);
          supported &= (gdk_gl_get_glVariantArrayObjectATI ()      != NULL);
          supported &= (gdk_gl_get_glGetVariantArrayObjectfvATI () != NULL);
          supported &= (gdk_gl_get_glGetVariantArrayObjectivATI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_array_object));
}

/* 
 * GL_EXT_vertex_shader
 */

static GdkGL_GL_EXT_vertex_shader _GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glBeginVertexShaderEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glEndVertexShaderEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glBindVertexShaderEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGenVertexShadersEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glDeleteVertexShaderEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glShaderOp1EXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glShaderOp2EXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glShaderOp3EXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glSwizzleEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glWriteMaskEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glInsertComponentEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glExtractComponentEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGenSymbolsEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glSetInvariantEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glSetLocalConstantEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantbvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantsvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantdvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantubvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantusvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantuivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glVariantPointerEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glEnableVariantClientStateEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glDisableVariantClientStateEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glBindLightParameterEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glBindMaterialParameterEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glBindTexGenParameterEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glBindTextureUnitParameterEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glBindParameterEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glIsVariantEnabledEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetVariantBooleanvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetVariantIntegervEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetVariantFloatvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetVariantPointervEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetInvariantBooleanvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetInvariantIntegervEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetInvariantFloatvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetLocalConstantBooleanvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetLocalConstantIntegervEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader), glGetLocalConstantFloatvEXT)

GdkGL_GL_EXT_vertex_shader *
gdk_gl_get_GL_EXT_vertex_shader (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_vertex_shader ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_vertex_shader");

      if (supported)
        {
          supported &= (gdk_gl_get_glBeginVertexShaderEXT ()         != NULL);
          supported &= (gdk_gl_get_glEndVertexShaderEXT ()           != NULL);
          supported &= (gdk_gl_get_glBindVertexShaderEXT ()          != NULL);
          supported &= (gdk_gl_get_glGenVertexShadersEXT ()          != NULL);
          supported &= (gdk_gl_get_glDeleteVertexShaderEXT ()        != NULL);
          supported &= (gdk_gl_get_glShaderOp1EXT ()                 != NULL);
          supported &= (gdk_gl_get_glShaderOp2EXT ()                 != NULL);
          supported &= (gdk_gl_get_glShaderOp3EXT ()                 != NULL);
          supported &= (gdk_gl_get_glSwizzleEXT ()                   != NULL);
          supported &= (gdk_gl_get_glWriteMaskEXT ()                 != NULL);
          supported &= (gdk_gl_get_glInsertComponentEXT ()           != NULL);
          supported &= (gdk_gl_get_glExtractComponentEXT ()          != NULL);
          supported &= (gdk_gl_get_glGenSymbolsEXT ()                != NULL);
          supported &= (gdk_gl_get_glSetInvariantEXT ()              != NULL);
          supported &= (gdk_gl_get_glSetLocalConstantEXT ()          != NULL);
          supported &= (gdk_gl_get_glVariantbvEXT ()                 != NULL);
          supported &= (gdk_gl_get_glVariantsvEXT ()                 != NULL);
          supported &= (gdk_gl_get_glVariantivEXT ()                 != NULL);
          supported &= (gdk_gl_get_glVariantfvEXT ()                 != NULL);
          supported &= (gdk_gl_get_glVariantdvEXT ()                 != NULL);
          supported &= (gdk_gl_get_glVariantubvEXT ()                != NULL);
          supported &= (gdk_gl_get_glVariantusvEXT ()                != NULL);
          supported &= (gdk_gl_get_glVariantuivEXT ()                != NULL);
          supported &= (gdk_gl_get_glVariantPointerEXT ()            != NULL);
          supported &= (gdk_gl_get_glEnableVariantClientStateEXT ()  != NULL);
          supported &= (gdk_gl_get_glDisableVariantClientStateEXT () != NULL);
          supported &= (gdk_gl_get_glBindLightParameterEXT ()        != NULL);
          supported &= (gdk_gl_get_glBindMaterialParameterEXT ()     != NULL);
          supported &= (gdk_gl_get_glBindTexGenParameterEXT ()       != NULL);
          supported &= (gdk_gl_get_glBindTextureUnitParameterEXT ()  != NULL);
          supported &= (gdk_gl_get_glBindParameterEXT ()             != NULL);
          supported &= (gdk_gl_get_glIsVariantEnabledEXT ()          != NULL);
          supported &= (gdk_gl_get_glGetVariantBooleanvEXT ()        != NULL);
          supported &= (gdk_gl_get_glGetVariantIntegervEXT ()        != NULL);
          supported &= (gdk_gl_get_glGetVariantFloatvEXT ()          != NULL);
          supported &= (gdk_gl_get_glGetVariantPointervEXT ()        != NULL);
          supported &= (gdk_gl_get_glGetInvariantBooleanvEXT ()      != NULL);
          supported &= (gdk_gl_get_glGetInvariantIntegervEXT ()      != NULL);
          supported &= (gdk_gl_get_glGetInvariantFloatvEXT ()        != NULL);
          supported &= (gdk_gl_get_glGetLocalConstantBooleanvEXT ()  != NULL);
          supported &= (gdk_gl_get_glGetLocalConstantIntegervEXT ()  != NULL);
          supported &= (gdk_gl_get_glGetLocalConstantFloatvEXT ()    != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_shader));
}

/* 
 * GL_ATI_vertex_streams
 */

static GdkGL_GL_ATI_vertex_streams _GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream1sATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream1svATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream1iATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream1ivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream1fATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream1fvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream1dATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream1dvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream2sATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream2svATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream2iATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream2ivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream2fATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream2fvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream2dATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream2dvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream3sATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream3svATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream3iATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream3ivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream3fATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream3fvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream3dATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream3dvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream4sATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream4svATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream4iATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream4ivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream4fATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream4fvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream4dATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexStream4dvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3bATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3bvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3sATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3svATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3iATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3ivATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3fATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3fvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3dATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glNormalStream3dvATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glClientActiveVertexStreamATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexBlendEnviATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams), glVertexBlendEnvfATI)

GdkGL_GL_ATI_vertex_streams *
gdk_gl_get_GL_ATI_vertex_streams (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ATI_vertex_streams ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ATI_vertex_streams");

      if (supported)
        {
          supported &= (gdk_gl_get_glVertexStream1sATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream1svATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream1iATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream1ivATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream1fATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream1fvATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream1dATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream1dvATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream2sATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream2svATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream2iATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream2ivATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream2fATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream2fvATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream2dATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream2dvATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream3sATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream3svATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream3iATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream3ivATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream3fATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream3fvATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream3dATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream3dvATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream4sATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream4svATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream4iATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream4ivATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream4fATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream4fvATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexStream4dATI ()           != NULL);
          supported &= (gdk_gl_get_glVertexStream4dvATI ()          != NULL);
          supported &= (gdk_gl_get_glNormalStream3bATI ()           != NULL);
          supported &= (gdk_gl_get_glNormalStream3bvATI ()          != NULL);
          supported &= (gdk_gl_get_glNormalStream3sATI ()           != NULL);
          supported &= (gdk_gl_get_glNormalStream3svATI ()          != NULL);
          supported &= (gdk_gl_get_glNormalStream3iATI ()           != NULL);
          supported &= (gdk_gl_get_glNormalStream3ivATI ()          != NULL);
          supported &= (gdk_gl_get_glNormalStream3fATI ()           != NULL);
          supported &= (gdk_gl_get_glNormalStream3fvATI ()          != NULL);
          supported &= (gdk_gl_get_glNormalStream3dATI ()           != NULL);
          supported &= (gdk_gl_get_glNormalStream3dvATI ()          != NULL);
          supported &= (gdk_gl_get_glClientActiveVertexStreamATI () != NULL);
          supported &= (gdk_gl_get_glVertexBlendEnviATI ()          != NULL);
          supported &= (gdk_gl_get_glVertexBlendEnvfATI ()          != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ATI_vertex_streams));
}

/* 
 * GL_ATI_element_array
 */

static GdkGL_GL_ATI_element_array _GDK_GL_PROCS (GdkGL_GL_ATI_element_array) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_element_array), glElementPointerATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_element_array), glDrawElementArrayATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_element_array), glDrawRangeElementArrayATI)

GdkGL_GL_ATI_element_array *
gdk_gl_get_GL_ATI_element_array (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_ATI_element_array ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_ATI_element_array");

      if (supported)
        {
          supported &= (gdk_gl_get_glElementPointerATI ()        != NULL);
          supported &= (gdk_gl_get_glDrawElementArrayATI ()      != NULL);
          supported &= (gdk_gl_get_glDrawRangeElementArrayATI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_ATI_element_array));
}

/* 
 * GL_SUN_mesh_array
 */

static GdkGL_GL_SUN_mesh_array _GDK_GL_PROCS (GdkGL_GL_SUN_mesh_array) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_mesh_array), glDrawMeshArraysSUN)

GdkGL_GL_SUN_mesh_array *
gdk_gl_get_GL_SUN_mesh_array (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_SUN_mesh_array ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_SUN_mesh_array");

      if (supported)
        {
          supported &= (gdk_gl_get_glDrawMeshArraysSUN () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_SUN_mesh_array));
}

/* 
 * GL_NV_occlusion_query
 */

static GdkGL_GL_NV_occlusion_query _GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query), glGenOcclusionQueriesNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query), glDeleteOcclusionQueriesNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query), glIsOcclusionQueryNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query), glBeginOcclusionQueryNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query), glEndOcclusionQueryNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query), glGetOcclusionQueryivNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query), glGetOcclusionQueryuivNV)

GdkGL_GL_NV_occlusion_query *
gdk_gl_get_GL_NV_occlusion_query (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_NV_occlusion_query ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_NV_occlusion_query");

      if (supported)
        {
          supported &= (gdk_gl_get_glGenOcclusionQueriesNV ()    != NULL);
          supported &= (gdk_gl_get_glDeleteOcclusionQueriesNV () != NULL);
          supported &= (gdk_gl_get_glIsOcclusionQueryNV ()       != NULL);
          supported &= (gdk_gl_get_glBeginOcclusionQueryNV ()    != NULL);
          supported &= (gdk_gl_get_glEndOcclusionQueryNV ()      != NULL);
          supported &= (gdk_gl_get_glGetOcclusionQueryivNV ()    != NULL);
          supported &= (gdk_gl_get_glGetOcclusionQueryuivNV ()   != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_NV_occlusion_query));
}

/* 
 * GL_NV_point_sprite
 */

static GdkGL_GL_NV_point_sprite _GDK_GL_PROCS (GdkGL_GL_NV_point_sprite) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_point_sprite), glPointParameteriNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_point_sprite), glPointParameterivNV)

GdkGL_GL_NV_point_sprite *
gdk_gl_get_GL_NV_point_sprite (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_NV_point_sprite ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_NV_point_sprite");

      if (supported)
        {
          supported &= (gdk_gl_get_glPointParameteriNV ()  != NULL);
          supported &= (gdk_gl_get_glPointParameterivNV () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_NV_point_sprite));
}

/* 
 * GL_EXT_stencil_two_side
 */

static GdkGL_GL_EXT_stencil_two_side _GDK_GL_PROCS (GdkGL_GL_EXT_stencil_two_side) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_stencil_two_side), glActiveStencilFaceEXT)

GdkGL_GL_EXT_stencil_two_side *
gdk_gl_get_GL_EXT_stencil_two_side (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GL_EXT_stencil_two_side ()"));

#ifdef G_OS_WIN32
  if (!wglGetCurrentContext ())
    return NULL;
#endif

  if (!init)
    {
      supported = gdk_gl_query_gl_extension ("GL_EXT_stencil_two_side");

      if (supported)
        {
          supported &= (gdk_gl_get_glActiveStencilFaceEXT () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GL_EXT_stencil_two_side));
}
