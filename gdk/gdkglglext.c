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

#ifdef G_OS_WIN32

#include "win32/gdkglwin32.h"

#define _GDK_GL_GET_PROC(proc_name)                                                     \
GdkGLProc                                                                               \
_GDK_GL_CONCAT(gdk_gl_get_, proc_name) (void)                                           \
{                                                                                       \
  static gboolean init = FALSE;                                                         \
  static GdkGLProc proc_address = NULL;                                                 \
                                                                                        \
  if (!init)                                                                            \
    {                                                                                   \
      proc_address = gdk_gl_query_get_proc_address (#proc_name);                        \
                                                                                        \
      GDK_GL_NOTE (IMPL, g_message (" * gdk_gl_get_%s () - %s",                         \
                                    #proc_name,                                         \
                                    proc_address ? "supported" : "not supported"));     \
                                                                                        \
      if (proc_address || wglGetCurrentContext())                                       \
        init = TRUE;                                                                    \
    }                                                                                   \
                                                                                        \
  return proc_address;                                                                  \
}

#else  /* G_OS_WIN32 */

#define _GDK_GL_GET_PROC(proc_name)                                                     \
GdkGLProc                                                                               \
_GDK_GL_CONCAT(gdk_gl_get_, proc_name) (void)                                           \
{                                                                                       \
  static gboolean init = FALSE;                                                         \
  static GdkGLProc proc_address = NULL;                                                 \
                                                                                        \
  if (!init)                                                                            \
    {                                                                                   \
      proc_address = gdk_gl_query_get_proc_address (#proc_name);                        \
                                                                                        \
      GDK_GL_NOTE (IMPL, g_message (" * gdk_gl_get_%s () - %s",                         \
                                    #proc_name,                                         \
                                    proc_address ? "supported" : "not supported"));     \
                                                                                        \
      init = TRUE;                                                                      \
    }                                                                                   \
                                                                                        \
  return proc_address;                                                                  \
}

#endif /* G_OS_WIN32 */

/* 
 * GL_VERSION_1_2
 */

_GDK_GL_GET_PROC(glBlendColor)

_GDK_GL_GET_PROC(glBlendEquation)

_GDK_GL_GET_PROC(glDrawRangeElements)

_GDK_GL_GET_PROC(glColorTable)

_GDK_GL_GET_PROC(glColorTableParameterfv)

_GDK_GL_GET_PROC(glColorTableParameteriv)

_GDK_GL_GET_PROC(glCopyColorTable)

_GDK_GL_GET_PROC(glGetColorTable)

_GDK_GL_GET_PROC(glGetColorTableParameterfv)

_GDK_GL_GET_PROC(glGetColorTableParameteriv)

_GDK_GL_GET_PROC(glColorSubTable)

_GDK_GL_GET_PROC(glCopyColorSubTable)

_GDK_GL_GET_PROC(glConvolutionFilter1D)

_GDK_GL_GET_PROC(glConvolutionFilter2D)

_GDK_GL_GET_PROC(glConvolutionParameterf)

_GDK_GL_GET_PROC(glConvolutionParameterfv)

_GDK_GL_GET_PROC(glConvolutionParameteri)

_GDK_GL_GET_PROC(glConvolutionParameteriv)

_GDK_GL_GET_PROC(glCopyConvolutionFilter1D)

_GDK_GL_GET_PROC(glCopyConvolutionFilter2D)

_GDK_GL_GET_PROC(glGetConvolutionFilter)

_GDK_GL_GET_PROC(glGetConvolutionParameterfv)

_GDK_GL_GET_PROC(glGetConvolutionParameteriv)

_GDK_GL_GET_PROC(glGetSeparableFilter)

_GDK_GL_GET_PROC(glSeparableFilter2D)

_GDK_GL_GET_PROC(glGetHistogram)

_GDK_GL_GET_PROC(glGetHistogramParameterfv)

_GDK_GL_GET_PROC(glGetHistogramParameteriv)

_GDK_GL_GET_PROC(glGetMinmax)

_GDK_GL_GET_PROC(glGetMinmaxParameterfv)

_GDK_GL_GET_PROC(glGetMinmaxParameteriv)

_GDK_GL_GET_PROC(glHistogram)

_GDK_GL_GET_PROC(glMinmax)

_GDK_GL_GET_PROC(glResetHistogram)

_GDK_GL_GET_PROC(glResetMinmax)

_GDK_GL_GET_PROC(glTexImage3D)

_GDK_GL_GET_PROC(glTexSubImage3D)

_GDK_GL_GET_PROC(glCopyTexSubImage3D)

/* 
 * GL_VERSION_1_3
 */

_GDK_GL_GET_PROC(glActiveTexture)

_GDK_GL_GET_PROC(glClientActiveTexture)

_GDK_GL_GET_PROC(glMultiTexCoord1d)

_GDK_GL_GET_PROC(glMultiTexCoord1dv)

_GDK_GL_GET_PROC(glMultiTexCoord1f)

_GDK_GL_GET_PROC(glMultiTexCoord1fv)

_GDK_GL_GET_PROC(glMultiTexCoord1i)

_GDK_GL_GET_PROC(glMultiTexCoord1iv)

_GDK_GL_GET_PROC(glMultiTexCoord1s)

_GDK_GL_GET_PROC(glMultiTexCoord1sv)

_GDK_GL_GET_PROC(glMultiTexCoord2d)

_GDK_GL_GET_PROC(glMultiTexCoord2dv)

_GDK_GL_GET_PROC(glMultiTexCoord2f)

_GDK_GL_GET_PROC(glMultiTexCoord2fv)

_GDK_GL_GET_PROC(glMultiTexCoord2i)

_GDK_GL_GET_PROC(glMultiTexCoord2iv)

_GDK_GL_GET_PROC(glMultiTexCoord2s)

_GDK_GL_GET_PROC(glMultiTexCoord2sv)

_GDK_GL_GET_PROC(glMultiTexCoord3d)

_GDK_GL_GET_PROC(glMultiTexCoord3dv)

_GDK_GL_GET_PROC(glMultiTexCoord3f)

_GDK_GL_GET_PROC(glMultiTexCoord3fv)

_GDK_GL_GET_PROC(glMultiTexCoord3i)

_GDK_GL_GET_PROC(glMultiTexCoord3iv)

_GDK_GL_GET_PROC(glMultiTexCoord3s)

_GDK_GL_GET_PROC(glMultiTexCoord3sv)

_GDK_GL_GET_PROC(glMultiTexCoord4d)

_GDK_GL_GET_PROC(glMultiTexCoord4dv)

_GDK_GL_GET_PROC(glMultiTexCoord4f)

_GDK_GL_GET_PROC(glMultiTexCoord4fv)

_GDK_GL_GET_PROC(glMultiTexCoord4i)

_GDK_GL_GET_PROC(glMultiTexCoord4iv)

_GDK_GL_GET_PROC(glMultiTexCoord4s)

_GDK_GL_GET_PROC(glMultiTexCoord4sv)

_GDK_GL_GET_PROC(glLoadTransposeMatrixf)

_GDK_GL_GET_PROC(glLoadTransposeMatrixd)

_GDK_GL_GET_PROC(glMultTransposeMatrixf)

_GDK_GL_GET_PROC(glMultTransposeMatrixd)

_GDK_GL_GET_PROC(glSampleCoverage)

_GDK_GL_GET_PROC(glCompressedTexImage3D)

_GDK_GL_GET_PROC(glCompressedTexImage2D)

_GDK_GL_GET_PROC(glCompressedTexImage1D)

_GDK_GL_GET_PROC(glCompressedTexSubImage3D)

_GDK_GL_GET_PROC(glCompressedTexSubImage2D)

_GDK_GL_GET_PROC(glCompressedTexSubImage1D)

_GDK_GL_GET_PROC(glGetCompressedTexImage)

/* 
 * GL_VERSION_1_4
 */

_GDK_GL_GET_PROC(glBlendFuncSeparate)

_GDK_GL_GET_PROC(glFogCoordf)

_GDK_GL_GET_PROC(glFogCoordfv)

_GDK_GL_GET_PROC(glFogCoordd)

_GDK_GL_GET_PROC(glFogCoorddv)

_GDK_GL_GET_PROC(glFogCoordPointer)

_GDK_GL_GET_PROC(glMultiDrawArrays)

_GDK_GL_GET_PROC(glMultiDrawElements)

_GDK_GL_GET_PROC(glPointParameterf)

_GDK_GL_GET_PROC(glPointParameterfv)

_GDK_GL_GET_PROC(glPointParameteri)

_GDK_GL_GET_PROC(glPointParameteriv)

_GDK_GL_GET_PROC(glSecondaryColor3b)

_GDK_GL_GET_PROC(glSecondaryColor3bv)

_GDK_GL_GET_PROC(glSecondaryColor3d)

_GDK_GL_GET_PROC(glSecondaryColor3dv)

_GDK_GL_GET_PROC(glSecondaryColor3f)

_GDK_GL_GET_PROC(glSecondaryColor3fv)

_GDK_GL_GET_PROC(glSecondaryColor3i)

_GDK_GL_GET_PROC(glSecondaryColor3iv)

_GDK_GL_GET_PROC(glSecondaryColor3s)

_GDK_GL_GET_PROC(glSecondaryColor3sv)

_GDK_GL_GET_PROC(glSecondaryColor3ub)

_GDK_GL_GET_PROC(glSecondaryColor3ubv)

_GDK_GL_GET_PROC(glSecondaryColor3ui)

_GDK_GL_GET_PROC(glSecondaryColor3uiv)

_GDK_GL_GET_PROC(glSecondaryColor3us)

_GDK_GL_GET_PROC(glSecondaryColor3usv)

_GDK_GL_GET_PROC(glSecondaryColorPointer)

_GDK_GL_GET_PROC(glWindowPos2d)

_GDK_GL_GET_PROC(glWindowPos2dv)

_GDK_GL_GET_PROC(glWindowPos2f)

_GDK_GL_GET_PROC(glWindowPos2fv)

_GDK_GL_GET_PROC(glWindowPos2i)

_GDK_GL_GET_PROC(glWindowPos2iv)

_GDK_GL_GET_PROC(glWindowPos2s)

_GDK_GL_GET_PROC(glWindowPos2sv)

_GDK_GL_GET_PROC(glWindowPos3d)

_GDK_GL_GET_PROC(glWindowPos3dv)

_GDK_GL_GET_PROC(glWindowPos3f)

_GDK_GL_GET_PROC(glWindowPos3fv)

_GDK_GL_GET_PROC(glWindowPos3i)

_GDK_GL_GET_PROC(glWindowPos3iv)

_GDK_GL_GET_PROC(glWindowPos3s)

_GDK_GL_GET_PROC(glWindowPos3sv)

/* 
 * GL_ARB_multitexture
 */

_GDK_GL_GET_PROC(glActiveTextureARB)

_GDK_GL_GET_PROC(glClientActiveTextureARB)

_GDK_GL_GET_PROC(glMultiTexCoord1dARB)

_GDK_GL_GET_PROC(glMultiTexCoord1dvARB)

_GDK_GL_GET_PROC(glMultiTexCoord1fARB)

_GDK_GL_GET_PROC(glMultiTexCoord1fvARB)

_GDK_GL_GET_PROC(glMultiTexCoord1iARB)

_GDK_GL_GET_PROC(glMultiTexCoord1ivARB)

_GDK_GL_GET_PROC(glMultiTexCoord1sARB)

_GDK_GL_GET_PROC(glMultiTexCoord1svARB)

_GDK_GL_GET_PROC(glMultiTexCoord2dARB)

_GDK_GL_GET_PROC(glMultiTexCoord2dvARB)

_GDK_GL_GET_PROC(glMultiTexCoord2fARB)

_GDK_GL_GET_PROC(glMultiTexCoord2fvARB)

_GDK_GL_GET_PROC(glMultiTexCoord2iARB)

_GDK_GL_GET_PROC(glMultiTexCoord2ivARB)

_GDK_GL_GET_PROC(glMultiTexCoord2sARB)

_GDK_GL_GET_PROC(glMultiTexCoord2svARB)

_GDK_GL_GET_PROC(glMultiTexCoord3dARB)

_GDK_GL_GET_PROC(glMultiTexCoord3dvARB)

_GDK_GL_GET_PROC(glMultiTexCoord3fARB)

_GDK_GL_GET_PROC(glMultiTexCoord3fvARB)

_GDK_GL_GET_PROC(glMultiTexCoord3iARB)

_GDK_GL_GET_PROC(glMultiTexCoord3ivARB)

_GDK_GL_GET_PROC(glMultiTexCoord3sARB)

_GDK_GL_GET_PROC(glMultiTexCoord3svARB)

_GDK_GL_GET_PROC(glMultiTexCoord4dARB)

_GDK_GL_GET_PROC(glMultiTexCoord4dvARB)

_GDK_GL_GET_PROC(glMultiTexCoord4fARB)

_GDK_GL_GET_PROC(glMultiTexCoord4fvARB)

_GDK_GL_GET_PROC(glMultiTexCoord4iARB)

_GDK_GL_GET_PROC(glMultiTexCoord4ivARB)

_GDK_GL_GET_PROC(glMultiTexCoord4sARB)

_GDK_GL_GET_PROC(glMultiTexCoord4svARB)

/* 
 * GL_ARB_transpose_matrix
 */

_GDK_GL_GET_PROC(glLoadTransposeMatrixfARB)

_GDK_GL_GET_PROC(glLoadTransposeMatrixdARB)

_GDK_GL_GET_PROC(glMultTransposeMatrixfARB)

_GDK_GL_GET_PROC(glMultTransposeMatrixdARB)

/* 
 * GL_ARB_multisample
 */

_GDK_GL_GET_PROC(glSampleCoverageARB)

/* 
 * GL_ARB_texture_compression
 */

_GDK_GL_GET_PROC(glCompressedTexImage3DARB)

_GDK_GL_GET_PROC(glCompressedTexImage2DARB)

_GDK_GL_GET_PROC(glCompressedTexImage1DARB)

_GDK_GL_GET_PROC(glCompressedTexSubImage3DARB)

_GDK_GL_GET_PROC(glCompressedTexSubImage2DARB)

_GDK_GL_GET_PROC(glCompressedTexSubImage1DARB)

_GDK_GL_GET_PROC(glGetCompressedTexImageARB)

/* 
 * GL_ARB_point_parameters
 */

_GDK_GL_GET_PROC(glPointParameterfARB)

_GDK_GL_GET_PROC(glPointParameterfvARB)

/* 
 * GL_ARB_vertex_blend
 */

_GDK_GL_GET_PROC(glWeightbvARB)

_GDK_GL_GET_PROC(glWeightsvARB)

_GDK_GL_GET_PROC(glWeightivARB)

_GDK_GL_GET_PROC(glWeightfvARB)

_GDK_GL_GET_PROC(glWeightdvARB)

_GDK_GL_GET_PROC(glWeightubvARB)

_GDK_GL_GET_PROC(glWeightusvARB)

_GDK_GL_GET_PROC(glWeightuivARB)

_GDK_GL_GET_PROC(glWeightPointerARB)

_GDK_GL_GET_PROC(glVertexBlendARB)

/* 
 * GL_ARB_matrix_palette
 */

_GDK_GL_GET_PROC(glCurrentPaletteMatrixARB)

_GDK_GL_GET_PROC(glMatrixIndexubvARB)

_GDK_GL_GET_PROC(glMatrixIndexusvARB)

_GDK_GL_GET_PROC(glMatrixIndexuivARB)

_GDK_GL_GET_PROC(glMatrixIndexPointerARB)

/* 
 * GL_ARB_window_pos
 */

_GDK_GL_GET_PROC(glWindowPos2dARB)

_GDK_GL_GET_PROC(glWindowPos2dvARB)

_GDK_GL_GET_PROC(glWindowPos2fARB)

_GDK_GL_GET_PROC(glWindowPos2fvARB)

_GDK_GL_GET_PROC(glWindowPos2iARB)

_GDK_GL_GET_PROC(glWindowPos2ivARB)

_GDK_GL_GET_PROC(glWindowPos2sARB)

_GDK_GL_GET_PROC(glWindowPos2svARB)

_GDK_GL_GET_PROC(glWindowPos3dARB)

_GDK_GL_GET_PROC(glWindowPos3dvARB)

_GDK_GL_GET_PROC(glWindowPos3fARB)

_GDK_GL_GET_PROC(glWindowPos3fvARB)

_GDK_GL_GET_PROC(glWindowPos3iARB)

_GDK_GL_GET_PROC(glWindowPos3ivARB)

_GDK_GL_GET_PROC(glWindowPos3sARB)

_GDK_GL_GET_PROC(glWindowPos3svARB)

/* 
 * GL_ARB_vertex_program
 */

_GDK_GL_GET_PROC(glVertexAttrib1dARB)

_GDK_GL_GET_PROC(glVertexAttrib1dvARB)

_GDK_GL_GET_PROC(glVertexAttrib1fARB)

_GDK_GL_GET_PROC(glVertexAttrib1fvARB)

_GDK_GL_GET_PROC(glVertexAttrib1sARB)

_GDK_GL_GET_PROC(glVertexAttrib1svARB)

_GDK_GL_GET_PROC(glVertexAttrib2dARB)

_GDK_GL_GET_PROC(glVertexAttrib2dvARB)

_GDK_GL_GET_PROC(glVertexAttrib2fARB)

_GDK_GL_GET_PROC(glVertexAttrib2fvARB)

_GDK_GL_GET_PROC(glVertexAttrib2sARB)

_GDK_GL_GET_PROC(glVertexAttrib2svARB)

_GDK_GL_GET_PROC(glVertexAttrib3dARB)

_GDK_GL_GET_PROC(glVertexAttrib3dvARB)

_GDK_GL_GET_PROC(glVertexAttrib3fARB)

_GDK_GL_GET_PROC(glVertexAttrib3fvARB)

_GDK_GL_GET_PROC(glVertexAttrib3sARB)

_GDK_GL_GET_PROC(glVertexAttrib3svARB)

_GDK_GL_GET_PROC(glVertexAttrib4NbvARB)

_GDK_GL_GET_PROC(glVertexAttrib4NivARB)

_GDK_GL_GET_PROC(glVertexAttrib4NsvARB)

_GDK_GL_GET_PROC(glVertexAttrib4NubARB)

_GDK_GL_GET_PROC(glVertexAttrib4NubvARB)

_GDK_GL_GET_PROC(glVertexAttrib4NuivARB)

_GDK_GL_GET_PROC(glVertexAttrib4NusvARB)

_GDK_GL_GET_PROC(glVertexAttrib4bvARB)

_GDK_GL_GET_PROC(glVertexAttrib4dARB)

_GDK_GL_GET_PROC(glVertexAttrib4dvARB)

_GDK_GL_GET_PROC(glVertexAttrib4fARB)

_GDK_GL_GET_PROC(glVertexAttrib4fvARB)

_GDK_GL_GET_PROC(glVertexAttrib4ivARB)

_GDK_GL_GET_PROC(glVertexAttrib4sARB)

_GDK_GL_GET_PROC(glVertexAttrib4svARB)

_GDK_GL_GET_PROC(glVertexAttrib4ubvARB)

_GDK_GL_GET_PROC(glVertexAttrib4uivARB)

_GDK_GL_GET_PROC(glVertexAttrib4usvARB)

_GDK_GL_GET_PROC(glVertexAttribPointerARB)

_GDK_GL_GET_PROC(glEnableVertexAttribArrayARB)

_GDK_GL_GET_PROC(glDisableVertexAttribArrayARB)

_GDK_GL_GET_PROC(glProgramStringARB)

_GDK_GL_GET_PROC(glBindProgramARB)

_GDK_GL_GET_PROC(glDeleteProgramsARB)

_GDK_GL_GET_PROC(glGenProgramsARB)

_GDK_GL_GET_PROC(glProgramEnvParameter4dARB)

_GDK_GL_GET_PROC(glProgramEnvParameter4dvARB)

_GDK_GL_GET_PROC(glProgramEnvParameter4fARB)

_GDK_GL_GET_PROC(glProgramEnvParameter4fvARB)

_GDK_GL_GET_PROC(glProgramLocalParameter4dARB)

_GDK_GL_GET_PROC(glProgramLocalParameter4dvARB)

_GDK_GL_GET_PROC(glProgramLocalParameter4fARB)

_GDK_GL_GET_PROC(glProgramLocalParameter4fvARB)

_GDK_GL_GET_PROC(glGetProgramEnvParameterdvARB)

_GDK_GL_GET_PROC(glGetProgramEnvParameterfvARB)

_GDK_GL_GET_PROC(glGetProgramLocalParameterdvARB)

_GDK_GL_GET_PROC(glGetProgramLocalParameterfvARB)

_GDK_GL_GET_PROC(glGetProgramivARB)

_GDK_GL_GET_PROC(glGetProgramStringARB)

_GDK_GL_GET_PROC(glGetVertexAttribdvARB)

_GDK_GL_GET_PROC(glGetVertexAttribfvARB)

_GDK_GL_GET_PROC(glGetVertexAttribivARB)

_GDK_GL_GET_PROC(glGetVertexAttribPointervARB)

_GDK_GL_GET_PROC(glIsProgramARB)

/* 
 * GL_EXT_blend_color
 */

_GDK_GL_GET_PROC(glBlendColorEXT)

/* 
 * GL_EXT_polygon_offset
 */

_GDK_GL_GET_PROC(glPolygonOffsetEXT)

/* 
 * GL_EXT_texture3D
 */

_GDK_GL_GET_PROC(glTexImage3DEXT)

_GDK_GL_GET_PROC(glTexSubImage3DEXT)

/* 
 * GL_SGIS_texture_filter4
 */

_GDK_GL_GET_PROC(glGetTexFilterFuncSGIS)

_GDK_GL_GET_PROC(glTexFilterFuncSGIS)

/* 
 * GL_EXT_subtexture
 */

_GDK_GL_GET_PROC(glTexSubImage1DEXT)

_GDK_GL_GET_PROC(glTexSubImage2DEXT)

/* 
 * GL_EXT_copy_texture
 */

_GDK_GL_GET_PROC(glCopyTexImage1DEXT)

_GDK_GL_GET_PROC(glCopyTexImage2DEXT)

_GDK_GL_GET_PROC(glCopyTexSubImage1DEXT)

_GDK_GL_GET_PROC(glCopyTexSubImage2DEXT)

_GDK_GL_GET_PROC(glCopyTexSubImage3DEXT)

/* 
 * GL_EXT_histogram
 */

_GDK_GL_GET_PROC(glGetHistogramEXT)

_GDK_GL_GET_PROC(glGetHistogramParameterfvEXT)

_GDK_GL_GET_PROC(glGetHistogramParameterivEXT)

_GDK_GL_GET_PROC(glGetMinmaxEXT)

_GDK_GL_GET_PROC(glGetMinmaxParameterfvEXT)

_GDK_GL_GET_PROC(glGetMinmaxParameterivEXT)

_GDK_GL_GET_PROC(glHistogramEXT)

_GDK_GL_GET_PROC(glMinmaxEXT)

_GDK_GL_GET_PROC(glResetHistogramEXT)

_GDK_GL_GET_PROC(glResetMinmaxEXT)

/* 
 * GL_EXT_convolution
 */

_GDK_GL_GET_PROC(glConvolutionFilter1DEXT)

_GDK_GL_GET_PROC(glConvolutionFilter2DEXT)

_GDK_GL_GET_PROC(glConvolutionParameterfEXT)

_GDK_GL_GET_PROC(glConvolutionParameterfvEXT)

_GDK_GL_GET_PROC(glConvolutionParameteriEXT)

_GDK_GL_GET_PROC(glConvolutionParameterivEXT)

_GDK_GL_GET_PROC(glCopyConvolutionFilter1DEXT)

_GDK_GL_GET_PROC(glCopyConvolutionFilter2DEXT)

_GDK_GL_GET_PROC(glGetConvolutionFilterEXT)

_GDK_GL_GET_PROC(glGetConvolutionParameterfvEXT)

_GDK_GL_GET_PROC(glGetConvolutionParameterivEXT)

_GDK_GL_GET_PROC(glGetSeparableFilterEXT)

_GDK_GL_GET_PROC(glSeparableFilter2DEXT)

/* 
 * GL_SGI_color_table
 */

_GDK_GL_GET_PROC(glColorTableSGI)

_GDK_GL_GET_PROC(glColorTableParameterfvSGI)

_GDK_GL_GET_PROC(glColorTableParameterivSGI)

_GDK_GL_GET_PROC(glCopyColorTableSGI)

_GDK_GL_GET_PROC(glGetColorTableSGI)

_GDK_GL_GET_PROC(glGetColorTableParameterfvSGI)

_GDK_GL_GET_PROC(glGetColorTableParameterivSGI)

/* 
 * GL_SGIX_pixel_texture
 */

_GDK_GL_GET_PROC(glPixelTexGenSGIX)

/* 
 * GL_SGIS_pixel_texture
 */

_GDK_GL_GET_PROC(glPixelTexGenParameteriSGIS)

_GDK_GL_GET_PROC(glPixelTexGenParameterivSGIS)

_GDK_GL_GET_PROC(glPixelTexGenParameterfSGIS)

_GDK_GL_GET_PROC(glPixelTexGenParameterfvSGIS)

_GDK_GL_GET_PROC(glGetPixelTexGenParameterivSGIS)

_GDK_GL_GET_PROC(glGetPixelTexGenParameterfvSGIS)

/* 
 * GL_SGIS_texture4D
 */

_GDK_GL_GET_PROC(glTexImage4DSGIS)

_GDK_GL_GET_PROC(glTexSubImage4DSGIS)

/* 
 * GL_EXT_texture_object
 */

_GDK_GL_GET_PROC(glAreTexturesResidentEXT)

_GDK_GL_GET_PROC(glBindTextureEXT)

_GDK_GL_GET_PROC(glDeleteTexturesEXT)

_GDK_GL_GET_PROC(glGenTexturesEXT)

_GDK_GL_GET_PROC(glIsTextureEXT)

_GDK_GL_GET_PROC(glPrioritizeTexturesEXT)

/* 
 * GL_SGIS_detail_texture
 */

_GDK_GL_GET_PROC(glDetailTexFuncSGIS)

_GDK_GL_GET_PROC(glGetDetailTexFuncSGIS)

/* 
 * GL_SGIS_sharpen_texture
 */

_GDK_GL_GET_PROC(glSharpenTexFuncSGIS)

_GDK_GL_GET_PROC(glGetSharpenTexFuncSGIS)

/* 
 * GL_SGIS_multisample
 */

_GDK_GL_GET_PROC(glSampleMaskSGIS)

_GDK_GL_GET_PROC(glSamplePatternSGIS)

/* 
 * GL_EXT_vertex_array
 */

_GDK_GL_GET_PROC(glArrayElementEXT)

_GDK_GL_GET_PROC(glColorPointerEXT)

_GDK_GL_GET_PROC(glDrawArraysEXT)

_GDK_GL_GET_PROC(glEdgeFlagPointerEXT)

_GDK_GL_GET_PROC(glGetPointervEXT)

_GDK_GL_GET_PROC(glIndexPointerEXT)

_GDK_GL_GET_PROC(glNormalPointerEXT)

_GDK_GL_GET_PROC(glTexCoordPointerEXT)

_GDK_GL_GET_PROC(glVertexPointerEXT)

/* 
 * GL_EXT_blend_minmax
 */

_GDK_GL_GET_PROC(glBlendEquationEXT)

/* 
 * GL_SGIX_sprite
 */

_GDK_GL_GET_PROC(glSpriteParameterfSGIX)

_GDK_GL_GET_PROC(glSpriteParameterfvSGIX)

_GDK_GL_GET_PROC(glSpriteParameteriSGIX)

_GDK_GL_GET_PROC(glSpriteParameterivSGIX)

/* 
 * GL_EXT_point_parameters
 */

_GDK_GL_GET_PROC(glPointParameterfEXT)

_GDK_GL_GET_PROC(glPointParameterfvEXT)

/* 
 * GL_SGIS_point_parameters
 */

_GDK_GL_GET_PROC(glPointParameterfSGIS)

_GDK_GL_GET_PROC(glPointParameterfvSGIS)

/* 
 * GL_SGIX_instruments
 */

_GDK_GL_GET_PROC(glGetInstrumentsSGIX)

_GDK_GL_GET_PROC(glInstrumentsBufferSGIX)

_GDK_GL_GET_PROC(glPollInstrumentsSGIX)

_GDK_GL_GET_PROC(glReadInstrumentsSGIX)

_GDK_GL_GET_PROC(glStartInstrumentsSGIX)

_GDK_GL_GET_PROC(glStopInstrumentsSGIX)

/* 
 * GL_SGIX_framezoom
 */

_GDK_GL_GET_PROC(glFrameZoomSGIX)

/* 
 * GL_SGIX_tag_sample_buffer
 */

_GDK_GL_GET_PROC(glTagSampleBufferSGIX)

/* 
 * GL_SGIX_polynomial_ffd
 */

_GDK_GL_GET_PROC(glDeformationMap3dSGIX)

_GDK_GL_GET_PROC(glDeformationMap3fSGIX)

_GDK_GL_GET_PROC(glDeformSGIX)

_GDK_GL_GET_PROC(glLoadIdentityDeformationMapSGIX)

/* 
 * GL_SGIX_reference_plane
 */

_GDK_GL_GET_PROC(glReferencePlaneSGIX)

/* 
 * GL_SGIX_flush_raster
 */

_GDK_GL_GET_PROC(glFlushRasterSGIX)

/* 
 * GL_SGIS_fog_function
 */

_GDK_GL_GET_PROC(glFogFuncSGIS)

_GDK_GL_GET_PROC(glGetFogFuncSGIS)

/* 
 * GL_HP_image_transform
 */

_GDK_GL_GET_PROC(glImageTransformParameteriHP)

_GDK_GL_GET_PROC(glImageTransformParameterfHP)

_GDK_GL_GET_PROC(glImageTransformParameterivHP)

_GDK_GL_GET_PROC(glImageTransformParameterfvHP)

_GDK_GL_GET_PROC(glGetImageTransformParameterivHP)

_GDK_GL_GET_PROC(glGetImageTransformParameterfvHP)

/* 
 * GL_EXT_color_subtable
 */

_GDK_GL_GET_PROC(glColorSubTableEXT)

_GDK_GL_GET_PROC(glCopyColorSubTableEXT)

/* 
 * GL_PGI_misc_hints
 */

_GDK_GL_GET_PROC(glHintPGI)

/* 
 * GL_EXT_paletted_texture
 */

_GDK_GL_GET_PROC(glColorTableEXT)

_GDK_GL_GET_PROC(glGetColorTableEXT)

_GDK_GL_GET_PROC(glGetColorTableParameterivEXT)

_GDK_GL_GET_PROC(glGetColorTableParameterfvEXT)

/* 
 * GL_SGIX_list_priority
 */

_GDK_GL_GET_PROC(glGetListParameterfvSGIX)

_GDK_GL_GET_PROC(glGetListParameterivSGIX)

_GDK_GL_GET_PROC(glListParameterfSGIX)

_GDK_GL_GET_PROC(glListParameterfvSGIX)

_GDK_GL_GET_PROC(glListParameteriSGIX)

_GDK_GL_GET_PROC(glListParameterivSGIX)

/* 
 * GL_EXT_index_material
 */

_GDK_GL_GET_PROC(glIndexMaterialEXT)

/* 
 * GL_EXT_index_func
 */

_GDK_GL_GET_PROC(glIndexFuncEXT)

/* 
 * GL_EXT_compiled_vertex_array
 */

_GDK_GL_GET_PROC(glLockArraysEXT)

_GDK_GL_GET_PROC(glUnlockArraysEXT)

/* 
 * GL_EXT_cull_vertex
 */

_GDK_GL_GET_PROC(glCullParameterdvEXT)

_GDK_GL_GET_PROC(glCullParameterfvEXT)

/* 
 * GL_SGIX_fragment_lighting
 */

_GDK_GL_GET_PROC(glFragmentColorMaterialSGIX)

_GDK_GL_GET_PROC(glFragmentLightfSGIX)

_GDK_GL_GET_PROC(glFragmentLightfvSGIX)

_GDK_GL_GET_PROC(glFragmentLightiSGIX)

_GDK_GL_GET_PROC(glFragmentLightivSGIX)

_GDK_GL_GET_PROC(glFragmentLightModelfSGIX)

_GDK_GL_GET_PROC(glFragmentLightModelfvSGIX)

_GDK_GL_GET_PROC(glFragmentLightModeliSGIX)

_GDK_GL_GET_PROC(glFragmentLightModelivSGIX)

_GDK_GL_GET_PROC(glFragmentMaterialfSGIX)

_GDK_GL_GET_PROC(glFragmentMaterialfvSGIX)

_GDK_GL_GET_PROC(glFragmentMaterialiSGIX)

_GDK_GL_GET_PROC(glFragmentMaterialivSGIX)

_GDK_GL_GET_PROC(glGetFragmentLightfvSGIX)

_GDK_GL_GET_PROC(glGetFragmentLightivSGIX)

_GDK_GL_GET_PROC(glGetFragmentMaterialfvSGIX)

_GDK_GL_GET_PROC(glGetFragmentMaterialivSGIX)

_GDK_GL_GET_PROC(glLightEnviSGIX)

/* 
 * GL_EXT_draw_range_elements
 */

_GDK_GL_GET_PROC(glDrawRangeElementsEXT)

/* 
 * GL_EXT_light_texture
 */

_GDK_GL_GET_PROC(glApplyTextureEXT)

_GDK_GL_GET_PROC(glTextureLightEXT)

_GDK_GL_GET_PROC(glTextureMaterialEXT)

/* 
 * GL_SGIX_async
 */

_GDK_GL_GET_PROC(glAsyncMarkerSGIX)

_GDK_GL_GET_PROC(glFinishAsyncSGIX)

_GDK_GL_GET_PROC(glPollAsyncSGIX)

_GDK_GL_GET_PROC(glGenAsyncMarkersSGIX)

_GDK_GL_GET_PROC(glDeleteAsyncMarkersSGIX)

_GDK_GL_GET_PROC(glIsAsyncMarkerSGIX)

/* 
 * GL_INTEL_parallel_arrays
 */

_GDK_GL_GET_PROC(glVertexPointervINTEL)

_GDK_GL_GET_PROC(glNormalPointervINTEL)

_GDK_GL_GET_PROC(glColorPointervINTEL)

_GDK_GL_GET_PROC(glTexCoordPointervINTEL)

/* 
 * GL_EXT_pixel_transform
 */

_GDK_GL_GET_PROC(glPixelTransformParameteriEXT)

_GDK_GL_GET_PROC(glPixelTransformParameterfEXT)

_GDK_GL_GET_PROC(glPixelTransformParameterivEXT)

_GDK_GL_GET_PROC(glPixelTransformParameterfvEXT)

/* 
 * GL_EXT_secondary_color
 */

_GDK_GL_GET_PROC(glSecondaryColor3bEXT)

_GDK_GL_GET_PROC(glSecondaryColor3bvEXT)

_GDK_GL_GET_PROC(glSecondaryColor3dEXT)

_GDK_GL_GET_PROC(glSecondaryColor3dvEXT)

_GDK_GL_GET_PROC(glSecondaryColor3fEXT)

_GDK_GL_GET_PROC(glSecondaryColor3fvEXT)

_GDK_GL_GET_PROC(glSecondaryColor3iEXT)

_GDK_GL_GET_PROC(glSecondaryColor3ivEXT)

_GDK_GL_GET_PROC(glSecondaryColor3sEXT)

_GDK_GL_GET_PROC(glSecondaryColor3svEXT)

_GDK_GL_GET_PROC(glSecondaryColor3ubEXT)

_GDK_GL_GET_PROC(glSecondaryColor3ubvEXT)

_GDK_GL_GET_PROC(glSecondaryColor3uiEXT)

_GDK_GL_GET_PROC(glSecondaryColor3uivEXT)

_GDK_GL_GET_PROC(glSecondaryColor3usEXT)

_GDK_GL_GET_PROC(glSecondaryColor3usvEXT)

_GDK_GL_GET_PROC(glSecondaryColorPointerEXT)

/* 
 * GL_EXT_texture_perturb_normal
 */

_GDK_GL_GET_PROC(glTextureNormalEXT)

/* 
 * GL_EXT_multi_draw_arrays
 */

_GDK_GL_GET_PROC(glMultiDrawArraysEXT)

_GDK_GL_GET_PROC(glMultiDrawElementsEXT)

/* 
 * GL_EXT_fog_coord
 */

_GDK_GL_GET_PROC(glFogCoordfEXT)

_GDK_GL_GET_PROC(glFogCoordfvEXT)

_GDK_GL_GET_PROC(glFogCoorddEXT)

_GDK_GL_GET_PROC(glFogCoorddvEXT)

_GDK_GL_GET_PROC(glFogCoordPointerEXT)

/* 
 * GL_EXT_coordinate_frame
 */

_GDK_GL_GET_PROC(glTangent3bEXT)

_GDK_GL_GET_PROC(glTangent3bvEXT)

_GDK_GL_GET_PROC(glTangent3dEXT)

_GDK_GL_GET_PROC(glTangent3dvEXT)

_GDK_GL_GET_PROC(glTangent3fEXT)

_GDK_GL_GET_PROC(glTangent3fvEXT)

_GDK_GL_GET_PROC(glTangent3iEXT)

_GDK_GL_GET_PROC(glTangent3ivEXT)

_GDK_GL_GET_PROC(glTangent3sEXT)

_GDK_GL_GET_PROC(glTangent3svEXT)

_GDK_GL_GET_PROC(glBinormal3bEXT)

_GDK_GL_GET_PROC(glBinormal3bvEXT)

_GDK_GL_GET_PROC(glBinormal3dEXT)

_GDK_GL_GET_PROC(glBinormal3dvEXT)

_GDK_GL_GET_PROC(glBinormal3fEXT)

_GDK_GL_GET_PROC(glBinormal3fvEXT)

_GDK_GL_GET_PROC(glBinormal3iEXT)

_GDK_GL_GET_PROC(glBinormal3ivEXT)

_GDK_GL_GET_PROC(glBinormal3sEXT)

_GDK_GL_GET_PROC(glBinormal3svEXT)

_GDK_GL_GET_PROC(glTangentPointerEXT)

_GDK_GL_GET_PROC(glBinormalPointerEXT)

/* 
 * GL_SUNX_constant_data
 */

_GDK_GL_GET_PROC(glFinishTextureSUNX)

/* 
 * GL_SUN_global_alpha
 */

_GDK_GL_GET_PROC(glGlobalAlphaFactorbSUN)

_GDK_GL_GET_PROC(glGlobalAlphaFactorsSUN)

_GDK_GL_GET_PROC(glGlobalAlphaFactoriSUN)

_GDK_GL_GET_PROC(glGlobalAlphaFactorfSUN)

_GDK_GL_GET_PROC(glGlobalAlphaFactordSUN)

_GDK_GL_GET_PROC(glGlobalAlphaFactorubSUN)

_GDK_GL_GET_PROC(glGlobalAlphaFactorusSUN)

_GDK_GL_GET_PROC(glGlobalAlphaFactoruiSUN)

/* 
 * GL_SUN_triangle_list
 */

_GDK_GL_GET_PROC(glReplacementCodeuiSUN)

_GDK_GL_GET_PROC(glReplacementCodeusSUN)

_GDK_GL_GET_PROC(glReplacementCodeubSUN)

_GDK_GL_GET_PROC(glReplacementCodeuivSUN)

_GDK_GL_GET_PROC(glReplacementCodeusvSUN)

_GDK_GL_GET_PROC(glReplacementCodeubvSUN)

_GDK_GL_GET_PROC(glReplacementCodePointerSUN)

/* 
 * GL_SUN_vertex
 */

_GDK_GL_GET_PROC(glColor4ubVertex2fSUN)

_GDK_GL_GET_PROC(glColor4ubVertex2fvSUN)

_GDK_GL_GET_PROC(glColor4ubVertex3fSUN)

_GDK_GL_GET_PROC(glColor4ubVertex3fvSUN)

_GDK_GL_GET_PROC(glColor3fVertex3fSUN)

_GDK_GL_GET_PROC(glColor3fVertex3fvSUN)

_GDK_GL_GET_PROC(glNormal3fVertex3fSUN)

_GDK_GL_GET_PROC(glNormal3fVertex3fvSUN)

_GDK_GL_GET_PROC(glColor4fNormal3fVertex3fSUN)

_GDK_GL_GET_PROC(glColor4fNormal3fVertex3fvSUN)

_GDK_GL_GET_PROC(glTexCoord2fVertex3fSUN)

_GDK_GL_GET_PROC(glTexCoord2fVertex3fvSUN)

_GDK_GL_GET_PROC(glTexCoord4fVertex4fSUN)

_GDK_GL_GET_PROC(glTexCoord4fVertex4fvSUN)

_GDK_GL_GET_PROC(glTexCoord2fColor4ubVertex3fSUN)

_GDK_GL_GET_PROC(glTexCoord2fColor4ubVertex3fvSUN)

_GDK_GL_GET_PROC(glTexCoord2fColor3fVertex3fSUN)

_GDK_GL_GET_PROC(glTexCoord2fColor3fVertex3fvSUN)

_GDK_GL_GET_PROC(glTexCoord2fNormal3fVertex3fSUN)

_GDK_GL_GET_PROC(glTexCoord2fNormal3fVertex3fvSUN)

_GDK_GL_GET_PROC(glTexCoord2fColor4fNormal3fVertex3fSUN)

_GDK_GL_GET_PROC(glTexCoord2fColor4fNormal3fVertex3fvSUN)

_GDK_GL_GET_PROC(glTexCoord4fColor4fNormal3fVertex4fSUN)

_GDK_GL_GET_PROC(glTexCoord4fColor4fNormal3fVertex4fvSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiVertex3fSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiVertex3fvSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiColor4ubVertex3fSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiColor4ubVertex3fvSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiColor3fVertex3fSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiColor3fVertex3fvSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiNormal3fVertex3fSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiNormal3fVertex3fvSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiColor4fNormal3fVertex3fSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiColor4fNormal3fVertex3fvSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiTexCoord2fVertex3fSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiTexCoord2fVertex3fvSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN)

_GDK_GL_GET_PROC(glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN)

/* 
 * GL_EXT_blend_func_separate
 */

_GDK_GL_GET_PROC(glBlendFuncSeparateEXT)

/* 
 * GL_INGR_blend_func_separate
 */

_GDK_GL_GET_PROC(glBlendFuncSeparateINGR)

/* 
 * GL_EXT_vertex_weighting
 */

_GDK_GL_GET_PROC(glVertexWeightfEXT)

_GDK_GL_GET_PROC(glVertexWeightfvEXT)

_GDK_GL_GET_PROC(glVertexWeightPointerEXT)

/* 
 * GL_NV_vertex_array_range
 */

_GDK_GL_GET_PROC(glFlushVertexArrayRangeNV)

_GDK_GL_GET_PROC(glVertexArrayRangeNV)

/* 
 * GL_NV_register_combiners
 */

_GDK_GL_GET_PROC(glCombinerParameterfvNV)

_GDK_GL_GET_PROC(glCombinerParameterfNV)

_GDK_GL_GET_PROC(glCombinerParameterivNV)

_GDK_GL_GET_PROC(glCombinerParameteriNV)

_GDK_GL_GET_PROC(glCombinerInputNV)

_GDK_GL_GET_PROC(glCombinerOutputNV)

_GDK_GL_GET_PROC(glFinalCombinerInputNV)

_GDK_GL_GET_PROC(glGetCombinerInputParameterfvNV)

_GDK_GL_GET_PROC(glGetCombinerInputParameterivNV)

_GDK_GL_GET_PROC(glGetCombinerOutputParameterfvNV)

_GDK_GL_GET_PROC(glGetCombinerOutputParameterivNV)

_GDK_GL_GET_PROC(glGetFinalCombinerInputParameterfvNV)

_GDK_GL_GET_PROC(glGetFinalCombinerInputParameterivNV)

/* 
 * GL_MESA_resize_buffers
 */

_GDK_GL_GET_PROC(glResizeBuffersMESA)

/* 
 * GL_MESA_window_pos
 */

_GDK_GL_GET_PROC(glWindowPos2dMESA)

_GDK_GL_GET_PROC(glWindowPos2dvMESA)

_GDK_GL_GET_PROC(glWindowPos2fMESA)

_GDK_GL_GET_PROC(glWindowPos2fvMESA)

_GDK_GL_GET_PROC(glWindowPos2iMESA)

_GDK_GL_GET_PROC(glWindowPos2ivMESA)

_GDK_GL_GET_PROC(glWindowPos2sMESA)

_GDK_GL_GET_PROC(glWindowPos2svMESA)

_GDK_GL_GET_PROC(glWindowPos3dMESA)

_GDK_GL_GET_PROC(glWindowPos3dvMESA)

_GDK_GL_GET_PROC(glWindowPos3fMESA)

_GDK_GL_GET_PROC(glWindowPos3fvMESA)

_GDK_GL_GET_PROC(glWindowPos3iMESA)

_GDK_GL_GET_PROC(glWindowPos3ivMESA)

_GDK_GL_GET_PROC(glWindowPos3sMESA)

_GDK_GL_GET_PROC(glWindowPos3svMESA)

_GDK_GL_GET_PROC(glWindowPos4dMESA)

_GDK_GL_GET_PROC(glWindowPos4dvMESA)

_GDK_GL_GET_PROC(glWindowPos4fMESA)

_GDK_GL_GET_PROC(glWindowPos4fvMESA)

_GDK_GL_GET_PROC(glWindowPos4iMESA)

_GDK_GL_GET_PROC(glWindowPos4ivMESA)

_GDK_GL_GET_PROC(glWindowPos4sMESA)

_GDK_GL_GET_PROC(glWindowPos4svMESA)

/* 
 * GL_IBM_multimode_draw_arrays
 */

_GDK_GL_GET_PROC(glMultiModeDrawArraysIBM)

_GDK_GL_GET_PROC(glMultiModeDrawElementsIBM)

/* 
 * GL_IBM_vertex_array_lists
 */

_GDK_GL_GET_PROC(glColorPointerListIBM)

_GDK_GL_GET_PROC(glSecondaryColorPointerListIBM)

_GDK_GL_GET_PROC(glEdgeFlagPointerListIBM)

_GDK_GL_GET_PROC(glFogCoordPointerListIBM)

_GDK_GL_GET_PROC(glIndexPointerListIBM)

_GDK_GL_GET_PROC(glNormalPointerListIBM)

_GDK_GL_GET_PROC(glTexCoordPointerListIBM)

_GDK_GL_GET_PROC(glVertexPointerListIBM)

/* 
 * GL_3DFX_tbuffer
 */

_GDK_GL_GET_PROC(glTbufferMask3DFX)

/* 
 * GL_EXT_multisample
 */

_GDK_GL_GET_PROC(glSampleMaskEXT)

_GDK_GL_GET_PROC(glSamplePatternEXT)

/* 
 * GL_SGIS_texture_color_mask
 */

_GDK_GL_GET_PROC(glTextureColorMaskSGIS)

/* 
 * GL_SGIX_igloo_interface
 */

_GDK_GL_GET_PROC(glIglooInterfaceSGIX)

/* 
 * GL_NV_fence
 */

_GDK_GL_GET_PROC(glDeleteFencesNV)

_GDK_GL_GET_PROC(glGenFencesNV)

_GDK_GL_GET_PROC(glIsFenceNV)

_GDK_GL_GET_PROC(glTestFenceNV)

_GDK_GL_GET_PROC(glGetFenceivNV)

_GDK_GL_GET_PROC(glFinishFenceNV)

_GDK_GL_GET_PROC(glSetFenceNV)

/* 
 * GL_NV_evaluators
 */

_GDK_GL_GET_PROC(glMapControlPointsNV)

_GDK_GL_GET_PROC(glMapParameterivNV)

_GDK_GL_GET_PROC(glMapParameterfvNV)

_GDK_GL_GET_PROC(glGetMapControlPointsNV)

_GDK_GL_GET_PROC(glGetMapParameterivNV)

_GDK_GL_GET_PROC(glGetMapParameterfvNV)

_GDK_GL_GET_PROC(glGetMapAttribParameterivNV)

_GDK_GL_GET_PROC(glGetMapAttribParameterfvNV)

_GDK_GL_GET_PROC(glEvalMapsNV)

/* 
 * GL_NV_register_combiners2
 */

_GDK_GL_GET_PROC(glCombinerStageParameterfvNV)

_GDK_GL_GET_PROC(glGetCombinerStageParameterfvNV)

/* 
 * GL_NV_vertex_program
 */

_GDK_GL_GET_PROC(glAreProgramsResidentNV)

_GDK_GL_GET_PROC(glBindProgramNV)

_GDK_GL_GET_PROC(glDeleteProgramsNV)

_GDK_GL_GET_PROC(glExecuteProgramNV)

_GDK_GL_GET_PROC(glGenProgramsNV)

_GDK_GL_GET_PROC(glGetProgramParameterdvNV)

_GDK_GL_GET_PROC(glGetProgramParameterfvNV)

_GDK_GL_GET_PROC(glGetProgramivNV)

_GDK_GL_GET_PROC(glGetProgramStringNV)

_GDK_GL_GET_PROC(glGetTrackMatrixivNV)

_GDK_GL_GET_PROC(glGetVertexAttribdvNV)

_GDK_GL_GET_PROC(glGetVertexAttribfvNV)

_GDK_GL_GET_PROC(glGetVertexAttribivNV)

_GDK_GL_GET_PROC(glGetVertexAttribPointervNV)

_GDK_GL_GET_PROC(glIsProgramNV)

_GDK_GL_GET_PROC(glLoadProgramNV)

_GDK_GL_GET_PROC(glProgramParameter4dNV)

_GDK_GL_GET_PROC(glProgramParameter4dvNV)

_GDK_GL_GET_PROC(glProgramParameter4fNV)

_GDK_GL_GET_PROC(glProgramParameter4fvNV)

_GDK_GL_GET_PROC(glProgramParameters4dvNV)

_GDK_GL_GET_PROC(glProgramParameters4fvNV)

_GDK_GL_GET_PROC(glRequestResidentProgramsNV)

_GDK_GL_GET_PROC(glTrackMatrixNV)

_GDK_GL_GET_PROC(glVertexAttribPointerNV)

_GDK_GL_GET_PROC(glVertexAttrib1dNV)

_GDK_GL_GET_PROC(glVertexAttrib1dvNV)

_GDK_GL_GET_PROC(glVertexAttrib1fNV)

_GDK_GL_GET_PROC(glVertexAttrib1fvNV)

_GDK_GL_GET_PROC(glVertexAttrib1sNV)

_GDK_GL_GET_PROC(glVertexAttrib1svNV)

_GDK_GL_GET_PROC(glVertexAttrib2dNV)

_GDK_GL_GET_PROC(glVertexAttrib2dvNV)

_GDK_GL_GET_PROC(glVertexAttrib2fNV)

_GDK_GL_GET_PROC(glVertexAttrib2fvNV)

_GDK_GL_GET_PROC(glVertexAttrib2sNV)

_GDK_GL_GET_PROC(glVertexAttrib2svNV)

_GDK_GL_GET_PROC(glVertexAttrib3dNV)

_GDK_GL_GET_PROC(glVertexAttrib3dvNV)

_GDK_GL_GET_PROC(glVertexAttrib3fNV)

_GDK_GL_GET_PROC(glVertexAttrib3fvNV)

_GDK_GL_GET_PROC(glVertexAttrib3sNV)

_GDK_GL_GET_PROC(glVertexAttrib3svNV)

_GDK_GL_GET_PROC(glVertexAttrib4dNV)

_GDK_GL_GET_PROC(glVertexAttrib4dvNV)

_GDK_GL_GET_PROC(glVertexAttrib4fNV)

_GDK_GL_GET_PROC(glVertexAttrib4fvNV)

_GDK_GL_GET_PROC(glVertexAttrib4sNV)

_GDK_GL_GET_PROC(glVertexAttrib4svNV)

_GDK_GL_GET_PROC(glVertexAttrib4ubNV)

_GDK_GL_GET_PROC(glVertexAttrib4ubvNV)

_GDK_GL_GET_PROC(glVertexAttribs1dvNV)

_GDK_GL_GET_PROC(glVertexAttribs1fvNV)

_GDK_GL_GET_PROC(glVertexAttribs1svNV)

_GDK_GL_GET_PROC(glVertexAttribs2dvNV)

_GDK_GL_GET_PROC(glVertexAttribs2fvNV)

_GDK_GL_GET_PROC(glVertexAttribs2svNV)

_GDK_GL_GET_PROC(glVertexAttribs3dvNV)

_GDK_GL_GET_PROC(glVertexAttribs3fvNV)

_GDK_GL_GET_PROC(glVertexAttribs3svNV)

_GDK_GL_GET_PROC(glVertexAttribs4dvNV)

_GDK_GL_GET_PROC(glVertexAttribs4fvNV)

_GDK_GL_GET_PROC(glVertexAttribs4svNV)

_GDK_GL_GET_PROC(glVertexAttribs4ubvNV)

/* 
 * GL_ATI_envmap_bumpmap
 */

_GDK_GL_GET_PROC(glTexBumpParameterivATI)

_GDK_GL_GET_PROC(glTexBumpParameterfvATI)

_GDK_GL_GET_PROC(glGetTexBumpParameterivATI)

_GDK_GL_GET_PROC(glGetTexBumpParameterfvATI)

/* 
 * GL_ATI_fragment_shader
 */

_GDK_GL_GET_PROC(glGenFragmentShadersATI)

_GDK_GL_GET_PROC(glBindFragmentShaderATI)

_GDK_GL_GET_PROC(glDeleteFragmentShaderATI)

_GDK_GL_GET_PROC(glBeginFragmentShaderATI)

_GDK_GL_GET_PROC(glEndFragmentShaderATI)

_GDK_GL_GET_PROC(glPassTexCoordATI)

_GDK_GL_GET_PROC(glSampleMapATI)

_GDK_GL_GET_PROC(glColorFragmentOp1ATI)

_GDK_GL_GET_PROC(glColorFragmentOp2ATI)

_GDK_GL_GET_PROC(glColorFragmentOp3ATI)

_GDK_GL_GET_PROC(glAlphaFragmentOp1ATI)

_GDK_GL_GET_PROC(glAlphaFragmentOp2ATI)

_GDK_GL_GET_PROC(glAlphaFragmentOp3ATI)

_GDK_GL_GET_PROC(glSetFragmentShaderConstantATI)

/* 
 * GL_ATI_pn_triangles
 */

_GDK_GL_GET_PROC(glPNTrianglesiATI)

_GDK_GL_GET_PROC(glPNTrianglesfATI)

/* 
 * GL_ATI_vertex_array_object
 */

_GDK_GL_GET_PROC(glNewObjectBufferATI)

_GDK_GL_GET_PROC(glIsObjectBufferATI)

_GDK_GL_GET_PROC(glUpdateObjectBufferATI)

_GDK_GL_GET_PROC(glGetObjectBufferfvATI)

_GDK_GL_GET_PROC(glGetObjectBufferivATI)

_GDK_GL_GET_PROC(glDeleteObjectBufferATI)

_GDK_GL_GET_PROC(glArrayObjectATI)

_GDK_GL_GET_PROC(glGetArrayObjectfvATI)

_GDK_GL_GET_PROC(glGetArrayObjectivATI)

_GDK_GL_GET_PROC(glVariantArrayObjectATI)

_GDK_GL_GET_PROC(glGetVariantArrayObjectfvATI)

_GDK_GL_GET_PROC(glGetVariantArrayObjectivATI)

/* 
 * GL_EXT_vertex_shader
 */

_GDK_GL_GET_PROC(glBeginVertexShaderEXT)

_GDK_GL_GET_PROC(glEndVertexShaderEXT)

_GDK_GL_GET_PROC(glBindVertexShaderEXT)

_GDK_GL_GET_PROC(glGenVertexShadersEXT)

_GDK_GL_GET_PROC(glDeleteVertexShaderEXT)

_GDK_GL_GET_PROC(glShaderOp1EXT)

_GDK_GL_GET_PROC(glShaderOp2EXT)

_GDK_GL_GET_PROC(glShaderOp3EXT)

_GDK_GL_GET_PROC(glSwizzleEXT)

_GDK_GL_GET_PROC(glWriteMaskEXT)

_GDK_GL_GET_PROC(glInsertComponentEXT)

_GDK_GL_GET_PROC(glExtractComponentEXT)

_GDK_GL_GET_PROC(glGenSymbolsEXT)

_GDK_GL_GET_PROC(glSetInvariantEXT)

_GDK_GL_GET_PROC(glSetLocalConstantEXT)

_GDK_GL_GET_PROC(glVariantbvEXT)

_GDK_GL_GET_PROC(glVariantsvEXT)

_GDK_GL_GET_PROC(glVariantivEXT)

_GDK_GL_GET_PROC(glVariantfvEXT)

_GDK_GL_GET_PROC(glVariantdvEXT)

_GDK_GL_GET_PROC(glVariantubvEXT)

_GDK_GL_GET_PROC(glVariantusvEXT)

_GDK_GL_GET_PROC(glVariantuivEXT)

_GDK_GL_GET_PROC(glVariantPointerEXT)

_GDK_GL_GET_PROC(glEnableVariantClientStateEXT)

_GDK_GL_GET_PROC(glDisableVariantClientStateEXT)

_GDK_GL_GET_PROC(glBindLightParameterEXT)

_GDK_GL_GET_PROC(glBindMaterialParameterEXT)

_GDK_GL_GET_PROC(glBindTexGenParameterEXT)

_GDK_GL_GET_PROC(glBindTextureUnitParameterEXT)

_GDK_GL_GET_PROC(glBindParameterEXT)

_GDK_GL_GET_PROC(glIsVariantEnabledEXT)

_GDK_GL_GET_PROC(glGetVariantBooleanvEXT)

_GDK_GL_GET_PROC(glGetVariantIntegervEXT)

_GDK_GL_GET_PROC(glGetVariantFloatvEXT)

_GDK_GL_GET_PROC(glGetVariantPointervEXT)

_GDK_GL_GET_PROC(glGetInvariantBooleanvEXT)

_GDK_GL_GET_PROC(glGetInvariantIntegervEXT)

_GDK_GL_GET_PROC(glGetInvariantFloatvEXT)

_GDK_GL_GET_PROC(glGetLocalConstantBooleanvEXT)

_GDK_GL_GET_PROC(glGetLocalConstantIntegervEXT)

_GDK_GL_GET_PROC(glGetLocalConstantFloatvEXT)

/* 
 * GL_ATI_vertex_streams
 */

_GDK_GL_GET_PROC(glVertexStream1sATI)

_GDK_GL_GET_PROC(glVertexStream1svATI)

_GDK_GL_GET_PROC(glVertexStream1iATI)

_GDK_GL_GET_PROC(glVertexStream1ivATI)

_GDK_GL_GET_PROC(glVertexStream1fATI)

_GDK_GL_GET_PROC(glVertexStream1fvATI)

_GDK_GL_GET_PROC(glVertexStream1dATI)

_GDK_GL_GET_PROC(glVertexStream1dvATI)

_GDK_GL_GET_PROC(glVertexStream2sATI)

_GDK_GL_GET_PROC(glVertexStream2svATI)

_GDK_GL_GET_PROC(glVertexStream2iATI)

_GDK_GL_GET_PROC(glVertexStream2ivATI)

_GDK_GL_GET_PROC(glVertexStream2fATI)

_GDK_GL_GET_PROC(glVertexStream2fvATI)

_GDK_GL_GET_PROC(glVertexStream2dATI)

_GDK_GL_GET_PROC(glVertexStream2dvATI)

_GDK_GL_GET_PROC(glVertexStream3sATI)

_GDK_GL_GET_PROC(glVertexStream3svATI)

_GDK_GL_GET_PROC(glVertexStream3iATI)

_GDK_GL_GET_PROC(glVertexStream3ivATI)

_GDK_GL_GET_PROC(glVertexStream3fATI)

_GDK_GL_GET_PROC(glVertexStream3fvATI)

_GDK_GL_GET_PROC(glVertexStream3dATI)

_GDK_GL_GET_PROC(glVertexStream3dvATI)

_GDK_GL_GET_PROC(glVertexStream4sATI)

_GDK_GL_GET_PROC(glVertexStream4svATI)

_GDK_GL_GET_PROC(glVertexStream4iATI)

_GDK_GL_GET_PROC(glVertexStream4ivATI)

_GDK_GL_GET_PROC(glVertexStream4fATI)

_GDK_GL_GET_PROC(glVertexStream4fvATI)

_GDK_GL_GET_PROC(glVertexStream4dATI)

_GDK_GL_GET_PROC(glVertexStream4dvATI)

_GDK_GL_GET_PROC(glNormalStream3bATI)

_GDK_GL_GET_PROC(glNormalStream3bvATI)

_GDK_GL_GET_PROC(glNormalStream3sATI)

_GDK_GL_GET_PROC(glNormalStream3svATI)

_GDK_GL_GET_PROC(glNormalStream3iATI)

_GDK_GL_GET_PROC(glNormalStream3ivATI)

_GDK_GL_GET_PROC(glNormalStream3fATI)

_GDK_GL_GET_PROC(glNormalStream3fvATI)

_GDK_GL_GET_PROC(glNormalStream3dATI)

_GDK_GL_GET_PROC(glNormalStream3dvATI)

_GDK_GL_GET_PROC(glClientActiveVertexStreamATI)

_GDK_GL_GET_PROC(glVertexBlendEnviATI)

_GDK_GL_GET_PROC(glVertexBlendEnvfATI)

/* 
 * GL_ATI_element_array
 */

_GDK_GL_GET_PROC(glElementPointerATI)

_GDK_GL_GET_PROC(glDrawElementArrayATI)

_GDK_GL_GET_PROC(glDrawRangeElementArrayATI)

/* 
 * GL_SUN_mesh_array
 */

_GDK_GL_GET_PROC(glDrawMeshArraysSUN)

/* 
 * GL_NV_occlusion_query
 */

_GDK_GL_GET_PROC(glGenOcclusionQueriesNV)

_GDK_GL_GET_PROC(glDeleteOcclusionQueriesNV)

_GDK_GL_GET_PROC(glIsOcclusionQueryNV)

_GDK_GL_GET_PROC(glBeginOcclusionQueryNV)

_GDK_GL_GET_PROC(glEndOcclusionQueryNV)

_GDK_GL_GET_PROC(glGetOcclusionQueryivNV)

_GDK_GL_GET_PROC(glGetOcclusionQueryuivNV)

/* 
 * GL_NV_point_sprite
 */

_GDK_GL_GET_PROC(glPointParameteriNV)

_GDK_GL_GET_PROC(glPointParameterivNV)

/* 
 * GL_EXT_stencil_two_side
 */

_GDK_GL_GET_PROC(glActiveStencilFaceEXT)
