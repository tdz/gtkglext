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

#include "gdkglprivate-x11.h"
#include "gdkglglxext.h"

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
      init = TRUE;                                                                      \
    }                                                                                   \
                                                                                        \
  return (GdkGLProc) (__procs.__proc_name);                                             \
}

/* 
 * GLX_VERSION_1_3
 */

static GdkGL_GLX_VERSION_1_3 _GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3) = {
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXGetFBConfigs)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXChooseFBConfig)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXGetFBConfigAttrib)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXGetVisualFromFBConfig)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXCreateWindow)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXDestroyWindow)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXCreatePixmap)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXDestroyPixmap)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXCreatePbuffer)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXDestroyPbuffer)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXQueryDrawable)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXCreateNewContext)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXMakeContextCurrent)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXGetCurrentReadDrawable)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXGetCurrentDisplay)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXQueryContext)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXSelectEvent)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3), glXGetSelectedEvent)

/* 
 * GLX_VERSION_1_4
 */

static GdkGL_GLX_VERSION_1_4 _GDK_GL_PROCS (GdkGL_GLX_VERSION_1_4) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_4), glXGetProcAddress)

/* 
 * GLX_ARB_get_proc_address
 */

static GdkGL_GLX_ARB_get_proc_address _GDK_GL_PROCS (GdkGL_GLX_ARB_get_proc_address) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_ARB_get_proc_address), glXGetProcAddressARB)

/* 
 * GLX_SGI_swap_control
 */

static GdkGL_GLX_SGI_swap_control _GDK_GL_PROCS (GdkGL_GLX_SGI_swap_control) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_swap_control), glXSwapIntervalSGI)

/* 
 * GLX_SGI_video_sync
 */

static GdkGL_GLX_SGI_video_sync _GDK_GL_PROCS (GdkGL_GLX_SGI_video_sync) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_video_sync), glXGetVideoSyncSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_video_sync), glXWaitVideoSyncSGI)

/* 
 * GLX_SGI_make_current_read
 */

static GdkGL_GLX_SGI_make_current_read _GDK_GL_PROCS (GdkGL_GLX_SGI_make_current_read) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_make_current_read), glXMakeCurrentReadSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_make_current_read), glXGetCurrentReadDrawableSGI)

/* 
 * GLX_SGIX_video_source
 */

#ifdef _VL_H

static GdkGL_GLX_SGIX_video_source _GDK_GL_PROCS (GdkGL_GLX_SGIX_video_source) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_source), glXCreateGLXVideoSourceSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_source), glXDestroyGLXVideoSourceSGIX)

#endif /* _VL_H */

/* 
 * GLX_EXT_import_context
 */

static GdkGL_GLX_EXT_import_context _GDK_GL_PROCS (GdkGL_GLX_EXT_import_context) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_EXT_import_context), glXGetCurrentDisplayEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_EXT_import_context), glXQueryContextInfoEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_EXT_import_context), glXGetContextIDEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_EXT_import_context), glXImportContextEXT)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_EXT_import_context), glXFreeContextEXT)

/* 
 * GLX_SGIX_fbconfig
 */

static GdkGL_GLX_SGIX_fbconfig _GDK_GL_PROCS (GdkGL_GLX_SGIX_fbconfig) = {
  NULL, NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_fbconfig), glXGetFBConfigAttribSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_fbconfig), glXChooseFBConfigSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_fbconfig), glXCreateGLXPixmapWithConfigSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_fbconfig), glXCreateContextWithConfigSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_fbconfig), glXGetVisualFromFBConfigSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_fbconfig), glXGetFBConfigFromVisualSGIX)

/* 
 * GLX_SGIX_pbuffer
 */

static GdkGL_GLX_SGIX_pbuffer _GDK_GL_PROCS (GdkGL_GLX_SGIX_pbuffer) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_pbuffer), glXCreateGLXPbufferSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_pbuffer), glXDestroyGLXPbufferSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_pbuffer), glXQueryGLXPbufferSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_pbuffer), glXSelectEventSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_pbuffer), glXGetSelectedEventSGIX)

/* 
 * GLX_SGI_cushion
 */

static GdkGL_GLX_SGI_cushion _GDK_GL_PROCS (GdkGL_GLX_SGI_cushion) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_cushion), glXCushionSGI)

/* 
 * GLX_SGIX_video_resize
 */

static GdkGL_GLX_SGIX_video_resize _GDK_GL_PROCS (GdkGL_GLX_SGIX_video_resize) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_resize), glXBindChannelToWindowSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_resize), glXChannelRectSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_resize), glXQueryChannelRectSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_resize), glXQueryChannelDeltasSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_resize), glXChannelRectSyncSGIX)

/* 
 * GLX_SGIX_dmbuffer
 */

#ifdef _DM_BUFFER_H_

static GdkGL_GLX_SGIX_dmbuffer _GDK_GL_PROCS (GdkGL_GLX_SGIX_dmbuffer) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_dmbuffer), glXAssociateDMPbufferSGIX)

#endif /* _DM_BUFFER_H_ */

/* 
 * GLX_SGIX_swap_group
 */

static GdkGL_GLX_SGIX_swap_group _GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_group) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_group), glXJoinSwapGroupSGIX)

/* 
 * GLX_SGIX_swap_barrier
 */

static GdkGL_GLX_SGIX_swap_barrier _GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_barrier) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_barrier), glXBindSwapBarrierSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_barrier), glXQueryMaxSwapBarriersSGIX)

/* 
 * GLX_SUN_get_transparent_index
 */

static GdkGL_GLX_SUN_get_transparent_index _GDK_GL_PROCS (GdkGL_GLX_SUN_get_transparent_index) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SUN_get_transparent_index), glXGetTransparentIndexSUN)

/*
 * GLX_MESA_copy_sub_buffer
 */

static GdkGL_GLX_MESA_copy_sub_buffer _GDK_GL_PROCS (GdkGL_GLX_MESA_copy_sub_buffer) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_MESA_copy_sub_buffer), glXCopySubBufferMESA)

/*
 * GLX_MESA_pixmap_colormap
 */

static GdkGL_GLX_MESA_pixmap_colormap _GDK_GL_PROCS (GdkGL_GLX_MESA_pixmap_colormap) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_MESA_pixmap_colormap), glXCreateGLXPixmapMESA)

/*
 * GLX_MESA_release_buffers
 */

static GdkGL_GLX_MESA_release_buffers _GDK_GL_PROCS (GdkGL_GLX_MESA_release_buffers) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_MESA_release_buffers), glXReleaseBuffersMESA)

/*
 * GLX_MESA_set_3dfx_mode
 */

static GdkGL_GLX_MESA_set_3dfx_mode _GDK_GL_PROCS (GdkGL_GLX_MESA_set_3dfx_mode) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_MESA_set_3dfx_mode), glXSet3DfxModeMESA)

/* 
 * GLX_OML_sync_control
 */

static GdkGL_GLX_OML_sync_control _GDK_GL_PROCS (GdkGL_GLX_OML_sync_control) = {
  NULL, NULL, NULL, NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_OML_sync_control), glXGetSyncValuesOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_OML_sync_control), glXGetMscRateOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_OML_sync_control), glXSwapBuffersMscOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_OML_sync_control), glXWaitForMscOML)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_OML_sync_control), glXWaitForSbcOML)
