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

#include "gdkglprivate-win32.h"
#include "gdkglwglext.h"

#define _GDK_GL_PROCS(__ext_name) \
  _GDK_GL_CONCAT (_proc_, __ext_name)

#define _GDK_GL_PROC_TYPE(__proc_name) \
  _GDK_GL_CONCAT (GdkGLProc_, __proc_name)

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

/* 
 * WGL_ARB_buffer_region
 */

static GdkGL_WGL_ARB_buffer_region _GDK_GL_PROCS (GdkGL_WGL_ARB_buffer_region) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_buffer_region), wglCreateBufferRegionARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_buffer_region), wglDeleteBufferRegionARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_buffer_region), wglSaveBufferRegionARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_buffer_region), wglRestoreBufferRegionARB)

/* 
 * WGL_ARB_extensions_string
 */

static GdkGL_WGL_ARB_extensions_string _GDK_GL_PROCS (GdkGL_WGL_ARB_extensions_string) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_extensions_string), wglGetExtensionsStringARB)

/* 
 * WGL_ARB_pixel_format
 */

static GdkGL_WGL_ARB_pixel_format _GDK_GL_PROCS (GdkGL_WGL_ARB_pixel_format) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_pixel_format), wglGetPixelFormatAttribivARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_pixel_format), wglGetPixelFormatAttribfvARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_pixel_format), wglChoosePixelFormatARB)

/* 
 * WGL_ARB_make_current_read
 */

static GdkGL_WGL_ARB_make_current_read _GDK_GL_PROCS (GdkGL_WGL_ARB_make_current_read) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_make_current_read), wglMakeContextCurrentARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_make_current_read), wglGetCurrentReadDCARB)

/* 
 * WGL_ARB_pbuffer
 */

static GdkGL_WGL_ARB_pbuffer _GDK_GL_PROCS (GdkGL_WGL_ARB_pbuffer) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_pbuffer), wglCreatePbufferARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_pbuffer), wglGetPbufferDCARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_pbuffer), wglReleasePbufferDCARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_pbuffer), wglDestroyPbufferARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_pbuffer), wglQueryPbufferARB)

/* 
 * WGL_ARB_render_texture
 */

static GdkGL_WGL_ARB_render_texture _GDK_GL_PROCS (GdkGL_WGL_ARB_render_texture) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_render_texture), wglBindTexImageARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_render_texture), wglReleaseTexImageARB)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_ARB_render_texture), wglSetPbufferAttribARB)

/* 
 * WGL_EXT_display_color_table
 */

static GdkGL_WGL_EXT_display_color_table _GDK_GL_PROCS (GdkGL_WGL_EXT_display_color_table) = {
  NULL, NULL, NULL, NULL, 
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_display_color_table), wglCreateDisplayColorTableEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_display_color_table), wglLoadDisplayColorTableEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_display_color_table), wglBindDisplayColorTableEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_display_color_table), wglDestroyDisplayColorTableEXT)

/* 
 * WGL_EXT_extensions_string
 */

static GdkGL_WGL_EXT_extensions_string _GDK_GL_PROCS (GdkGL_WGL_EXT_extensions_string) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_extensions_string), wglGetExtensionsStringEXT)

/* 
 * WGL_EXT_make_current_read
 */

static GdkGL_WGL_EXT_make_current_read _GDK_GL_PROCS (GdkGL_WGL_EXT_make_current_read) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_make_current_read), wglMakeContextCurrentEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_make_current_read), wglGetCurrentReadDCEXT)

/* 
 * WGL_EXT_pbuffer
 */

static GdkGL_WGL_EXT_pbuffer _GDK_GL_PROCS (GdkGL_WGL_EXT_pbuffer) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_pbuffer), wglCreatePbufferEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_pbuffer), wglGetPbufferDCEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_pbuffer), wglReleasePbufferDCEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_pbuffer), wglDestroyPbufferEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_pbuffer), wglQueryPbufferEXT)

/* 
 * WGL_EXT_pixel_format
 */

static GdkGL_WGL_EXT_pixel_format _GDK_GL_PROCS (GdkGL_WGL_EXT_pixel_format) = {
  NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_pixel_format), wglGetPixelFormatAttribivEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_pixel_format), wglGetPixelFormatAttribfvEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_pixel_format), wglChoosePixelFormatEXT)

/* 
 * WGL_EXT_swap_control
 */

static GdkGL_WGL_EXT_swap_control _GDK_GL_PROCS (GdkGL_WGL_EXT_swap_control) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_swap_control), wglSwapIntervalEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_EXT_swap_control), wglGetSwapIntervalEXT)

/* 
 * WGL_NV_vertex_array_range
 */

static GdkGL_WGL_NV_vertex_array_range _GDK_GL_PROCS (GdkGL_WGL_NV_vertex_array_range) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_NV_vertex_array_range), wglAllocateMemoryNV)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_NV_vertex_array_range), wglFreeMemoryNV)

/* 
 * WGL_OML_sync_control
 */

static GdkGL_WGL_OML_sync_control _GDK_GL_PROCS (GdkGL_WGL_OML_sync_control) = {
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_OML_sync_control), wglGetSyncValuesOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_OML_sync_control), wglGetMscRateOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_OML_sync_control), wglSwapBuffersMscOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_OML_sync_control), wglSwapLayerBuffersMscOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_OML_sync_control), wglWaitForMscOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_OML_sync_control), wglWaitForSbcOML)

/* 
 * WGL_I3D_digital_video_control
 */

static GdkGL_WGL_I3D_digital_video_control _GDK_GL_PROCS (GdkGL_WGL_I3D_digital_video_control) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_digital_video_control), wglGetDigitalVideoParametersI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_digital_video_control), wglSetDigitalVideoParametersI3D)

/* 
 * WGL_I3D_gamma
 */

static GdkGL_WGL_I3D_gamma _GDK_GL_PROCS (GdkGL_WGL_I3D_gamma) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_gamma), wglGetGammaTableParametersI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_gamma), wglSetGammaTableParametersI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_gamma), wglGetGammaTableI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_gamma), wglSetGammaTableI3D)

/* 
 * WGL_I3D_genlock
 */

static GdkGL_WGL_I3D_genlock _GDK_GL_PROCS (GdkGL_WGL_I3D_genlock) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglEnableGenlockI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglDisableGenlockI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglIsEnabledGenlockI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglGenlockSourceI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglGetGenlockSourceI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglGenlockSourceEdgeI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglGetGenlockSourceEdgeI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglGenlockSampleRateI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglGetGenlockSampleRateI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglGenlockSourceDelayI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglGetGenlockSourceDelayI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_genlock), wglQueryGenlockMaxSourceDelayI3D)

/* 
 * WGL_I3D_image_buffer
 */

static GdkGL_WGL_I3D_image_buffer _GDK_GL_PROCS (GdkGL_WGL_I3D_image_buffer) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_image_buffer), wglCreateImageBufferI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_image_buffer), wglDestroyImageBufferI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_image_buffer), wglAssociateImageBufferEventsI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_image_buffer), wglReleaseImageBufferEventsI3D)

/* 
 * WGL_I3D_swap_frame_lock
 */

static GdkGL_WGL_I3D_swap_frame_lock _GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_lock) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_lock), wglEnableFrameLockI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_lock), wglDisableFrameLockI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_lock), wglIsEnabledFrameLockI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_lock), wglQueryFrameLockMasterI3D)

/* 
 * WGL_I3D_swap_frame_usage
 */

static GdkGL_WGL_I3D_swap_frame_usage _GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_usage) = {
  NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_usage), wglGetFrameUsageI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_usage), wglBeginFrameTrackingI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_usage), wglEndFrameTrackingI3D)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_WGL_I3D_swap_frame_usage), wglQueryFrameTrackingI3D)
