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
  if (!init)                                                                            \
    {                                                                                   \
      __procs.__proc_name =                                                             \
        (_GDK_GL_PROC_TYPE (__proc_name)) gdk_gl_query_get_proc_address (#__proc_name); \
                                                                                        \
      GDK_GL_NOTE (IMPL,                                                                \
                   g_message (" * gdk_gl_get_%s () - %s",                               \
                              #__proc_name,                                             \
                              (__procs.__proc_name) ? "supported" : "not supported"));  \
                                                                                        \
      if (__procs.__proc_name || wglGetCurrentContext())                                \
        init = TRUE;                                                                    \
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
      GDK_GL_NOTE (IMPL,                                                                \
                   g_message (" * gdk_gl_get_%s () - %s",                               \
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

/* 
 * GL_ARB_multisample
 */

static GdkGL_GL_ARB_multisample _GDK_GL_PROCS (GdkGL_GL_ARB_multisample) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_multisample), glSampleCoverageARB)

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

/* 
 * GL_ARB_point_parameters
 */

static GdkGL_GL_ARB_point_parameters _GDK_GL_PROCS (GdkGL_GL_ARB_point_parameters) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_point_parameters), glPointParameterfARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ARB_point_parameters), glPointParameterfvARB)

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

/* 
 * GL_EXT_blend_color
 */

static GdkGL_GL_EXT_blend_color _GDK_GL_PROCS (GdkGL_GL_EXT_blend_color) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_blend_color), glBlendColorEXT)

/* 
 * GL_EXT_polygon_offset
 */

static GdkGL_GL_EXT_polygon_offset _GDK_GL_PROCS (GdkGL_GL_EXT_polygon_offset) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_polygon_offset), glPolygonOffsetEXT)

/* 
 * GL_EXT_texture3D
 */

static GdkGL_GL_EXT_texture3D _GDK_GL_PROCS (GdkGL_GL_EXT_texture3D) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture3D), glTexImage3DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture3D), glTexSubImage3DEXT)

/* 
 * GL_SGIS_texture_filter4
 */

static GdkGL_GL_SGIS_texture_filter4 _GDK_GL_PROCS (GdkGL_GL_SGIS_texture_filter4) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture_filter4), glGetTexFilterFuncSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture_filter4), glTexFilterFuncSGIS)

/* 
 * GL_EXT_subtexture
 */

static GdkGL_GL_EXT_subtexture _GDK_GL_PROCS (GdkGL_GL_EXT_subtexture) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_subtexture), glTexSubImage1DEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_subtexture), glTexSubImage2DEXT)

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

/* 
 * GL_SGIX_pixel_texture
 */

static GdkGL_GL_SGIX_pixel_texture _GDK_GL_PROCS (GdkGL_GL_SGIX_pixel_texture) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_pixel_texture), glPixelTexGenSGIX)

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

/* 
 * GL_SGIS_texture4D
 */

static GdkGL_GL_SGIS_texture4D _GDK_GL_PROCS (GdkGL_GL_SGIS_texture4D) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture4D), glTexImage4DSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture4D), glTexSubImage4DSGIS)

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

/* 
 * GL_SGIS_detail_texture
 */

static GdkGL_GL_SGIS_detail_texture _GDK_GL_PROCS (GdkGL_GL_SGIS_detail_texture) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_detail_texture), glDetailTexFuncSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_detail_texture), glGetDetailTexFuncSGIS)

/* 
 * GL_SGIS_sharpen_texture
 */

static GdkGL_GL_SGIS_sharpen_texture _GDK_GL_PROCS (GdkGL_GL_SGIS_sharpen_texture) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_sharpen_texture), glSharpenTexFuncSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_sharpen_texture), glGetSharpenTexFuncSGIS)

/* 
 * GL_SGIS_multisample
 */

static GdkGL_GL_SGIS_multisample _GDK_GL_PROCS (GdkGL_GL_SGIS_multisample) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_multisample), glSampleMaskSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_multisample), glSamplePatternSGIS)

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

/* 
 * GL_EXT_blend_minmax
 */

static GdkGL_GL_EXT_blend_minmax _GDK_GL_PROCS (GdkGL_GL_EXT_blend_minmax) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_blend_minmax), glBlendEquationEXT)

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

/* 
 * GL_EXT_point_parameters
 */

static GdkGL_GL_EXT_point_parameters _GDK_GL_PROCS (GdkGL_GL_EXT_point_parameters) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_point_parameters), glPointParameterfEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_point_parameters), glPointParameterfvEXT)

/* 
 * GL_SGIS_point_parameters
 */

static GdkGL_GL_SGIS_point_parameters _GDK_GL_PROCS (GdkGL_GL_SGIS_point_parameters) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_point_parameters), glPointParameterfSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_point_parameters), glPointParameterfvSGIS)

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

/* 
 * GL_SGIX_framezoom
 */

static GdkGL_GL_SGIX_framezoom _GDK_GL_PROCS (GdkGL_GL_SGIX_framezoom) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_framezoom), glFrameZoomSGIX)

/* 
 * GL_SGIX_tag_sample_buffer
 */

static GdkGL_GL_SGIX_tag_sample_buffer _GDK_GL_PROCS (GdkGL_GL_SGIX_tag_sample_buffer) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_tag_sample_buffer), glTagSampleBufferSGIX)

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

/* 
 * GL_SGIX_reference_plane
 */

static GdkGL_GL_SGIX_reference_plane _GDK_GL_PROCS (GdkGL_GL_SGIX_reference_plane) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_reference_plane), glReferencePlaneSGIX)

/* 
 * GL_SGIX_flush_raster
 */

static GdkGL_GL_SGIX_flush_raster _GDK_GL_PROCS (GdkGL_GL_SGIX_flush_raster) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_flush_raster), glFlushRasterSGIX)

/* 
 * GL_SGIS_fog_function
 */

static GdkGL_GL_SGIS_fog_function _GDK_GL_PROCS (GdkGL_GL_SGIS_fog_function) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_fog_function), glFogFuncSGIS)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_fog_function), glGetFogFuncSGIS)

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

/* 
 * GL_EXT_color_subtable
 */

static GdkGL_GL_EXT_color_subtable _GDK_GL_PROCS (GdkGL_GL_EXT_color_subtable) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_color_subtable), glColorSubTableEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_color_subtable), glCopyColorSubTableEXT)

/* 
 * GL_PGI_misc_hints
 */

static GdkGL_GL_PGI_misc_hints _GDK_GL_PROCS (GdkGL_GL_PGI_misc_hints) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_PGI_misc_hints), glHintPGI)

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

/* 
 * GL_EXT_index_material
 */

static GdkGL_GL_EXT_index_material _GDK_GL_PROCS (GdkGL_GL_EXT_index_material) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_index_material), glIndexMaterialEXT)

/* 
 * GL_EXT_index_func
 */

static GdkGL_GL_EXT_index_func _GDK_GL_PROCS (GdkGL_GL_EXT_index_func) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_index_func), glIndexFuncEXT)

/* 
 * GL_EXT_compiled_vertex_array
 */

static GdkGL_GL_EXT_compiled_vertex_array _GDK_GL_PROCS (GdkGL_GL_EXT_compiled_vertex_array) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_compiled_vertex_array), glLockArraysEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_compiled_vertex_array), glUnlockArraysEXT)

/* 
 * GL_EXT_cull_vertex
 */

static GdkGL_GL_EXT_cull_vertex _GDK_GL_PROCS (GdkGL_GL_EXT_cull_vertex) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_cull_vertex), glCullParameterdvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_cull_vertex), glCullParameterfvEXT)

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

/* 
 * GL_EXT_draw_range_elements
 */

static GdkGL_GL_EXT_draw_range_elements _GDK_GL_PROCS (GdkGL_GL_EXT_draw_range_elements) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_draw_range_elements), glDrawRangeElementsEXT)

/* 
 * GL_EXT_light_texture
 */

static GdkGL_GL_EXT_light_texture _GDK_GL_PROCS (GdkGL_GL_EXT_light_texture) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_light_texture), glApplyTextureEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_light_texture), glTextureLightEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_light_texture), glTextureMaterialEXT)

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

/* 
 * GL_EXT_texture_perturb_normal
 */

static GdkGL_GL_EXT_texture_perturb_normal _GDK_GL_PROCS (GdkGL_GL_EXT_texture_perturb_normal) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_texture_perturb_normal), glTextureNormalEXT)

/* 
 * GL_EXT_multi_draw_arrays
 */

static GdkGL_GL_EXT_multi_draw_arrays _GDK_GL_PROCS (GdkGL_GL_EXT_multi_draw_arrays) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_multi_draw_arrays), glMultiDrawArraysEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_multi_draw_arrays), glMultiDrawElementsEXT)

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

/* 
 * GL_SUNX_constant_data
 */

static GdkGL_GL_SUNX_constant_data _GDK_GL_PROCS (GdkGL_GL_SUNX_constant_data) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUNX_constant_data), glFinishTextureSUNX)

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

/* 
 * GL_EXT_blend_func_separate
 */

static GdkGL_GL_EXT_blend_func_separate _GDK_GL_PROCS (GdkGL_GL_EXT_blend_func_separate) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_blend_func_separate), glBlendFuncSeparateEXT)

/* 
 * GL_INGR_blend_func_separate
 */

static GdkGL_GL_INGR_blend_func_separate _GDK_GL_PROCS (GdkGL_GL_INGR_blend_func_separate) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_INGR_blend_func_separate), glBlendFuncSeparateINGR)

/* 
 * GL_EXT_vertex_weighting
 */

static GdkGL_GL_EXT_vertex_weighting _GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting), glVertexWeightfEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting), glVertexWeightfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_vertex_weighting), glVertexWeightPointerEXT)

/* 
 * GL_NV_vertex_array_range
 */

static GdkGL_GL_NV_vertex_array_range _GDK_GL_PROCS (GdkGL_GL_NV_vertex_array_range) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_array_range), glFlushVertexArrayRangeNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_vertex_array_range), glVertexArrayRangeNV)

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

/* 
 * GL_MESA_resize_buffers
 */

static GdkGL_GL_MESA_resize_buffers _GDK_GL_PROCS (GdkGL_GL_MESA_resize_buffers) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_MESA_resize_buffers), glResizeBuffersMESA)

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

/* 
 * GL_IBM_multimode_draw_arrays
 */

static GdkGL_GL_IBM_multimode_draw_arrays _GDK_GL_PROCS (GdkGL_GL_IBM_multimode_draw_arrays) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_multimode_draw_arrays), glMultiModeDrawArraysIBM)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_IBM_multimode_draw_arrays), glMultiModeDrawElementsIBM)

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

/* 
 * GL_3DFX_tbuffer
 */

static GdkGL_GL_3DFX_tbuffer _GDK_GL_PROCS (GdkGL_GL_3DFX_tbuffer) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_3DFX_tbuffer), glTbufferMask3DFX)

/* 
 * GL_EXT_multisample
 */

static GdkGL_GL_EXT_multisample _GDK_GL_PROCS (GdkGL_GL_EXT_multisample) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_multisample), glSampleMaskEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_multisample), glSamplePatternEXT)

/* 
 * GL_SGIS_texture_color_mask
 */

static GdkGL_GL_SGIS_texture_color_mask _GDK_GL_PROCS (GdkGL_GL_SGIS_texture_color_mask) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIS_texture_color_mask), glTextureColorMaskSGIS)

/* 
 * GL_SGIX_igloo_interface
 */

static GdkGL_GL_SGIX_igloo_interface _GDK_GL_PROCS (GdkGL_GL_SGIX_igloo_interface) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SGIX_igloo_interface), glIglooInterfaceSGIX)

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

/* 
 * GL_NV_register_combiners2
 */

static GdkGL_GL_NV_register_combiners2 _GDK_GL_PROCS (GdkGL_GL_NV_register_combiners2) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners2), glCombinerStageParameterfvNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_register_combiners2), glGetCombinerStageParameterfvNV)

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

/* 
 * GL_ATI_pn_triangles
 */

static GdkGL_GL_ATI_pn_triangles _GDK_GL_PROCS (GdkGL_GL_ATI_pn_triangles) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_pn_triangles), glPNTrianglesiATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_pn_triangles), glPNTrianglesfATI)

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

/* 
 * GL_ATI_element_array
 */

static GdkGL_GL_ATI_element_array _GDK_GL_PROCS (GdkGL_GL_ATI_element_array) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_element_array), glElementPointerATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_element_array), glDrawElementArrayATI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_ATI_element_array), glDrawRangeElementArrayATI)

/* 
 * GL_SUN_mesh_array
 */

static GdkGL_GL_SUN_mesh_array _GDK_GL_PROCS (GdkGL_GL_SUN_mesh_array) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_SUN_mesh_array), glDrawMeshArraysSUN)

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

/* 
 * GL_NV_point_sprite
 */

static GdkGL_GL_NV_point_sprite _GDK_GL_PROCS (GdkGL_GL_NV_point_sprite) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_point_sprite), glPointParameteriNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_NV_point_sprite), glPointParameterivNV)

/* 
 * GL_EXT_stencil_two_side
 */

static GdkGL_GL_EXT_stencil_two_side _GDK_GL_PROCS (GdkGL_GL_EXT_stencil_two_side) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GL_EXT_stencil_two_side), glActiveStencilFaceEXT)
