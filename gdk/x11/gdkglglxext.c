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

#define _GDK_GL_GET_PROC(proc_name)                                                             \
GdkGLProc                                                                                       \
_GDK_GL_CONCAT(gdk_gl_get_, proc_name) (void)                                                   \
{                                                                                               \
  static gboolean init = FALSE;                                                                 \
  static GdkGLProc proc_address = NULL;                                                         \
                                                                                                \
  if (!init)                                                                                    \
    {                                                                                           \
      proc_address = gdk_gl_query_get_proc_address (#proc_name);                                \
                                                                                                \
      GDK_GL_NOTE (IMPL, g_message (" * gdk_gl_get_%s () - %s",                                 \
                                    #proc_name,                                                 \
                                    (proc_address == NULL) ? "not supported" : "supported"));   \
                                                                                                \
      init = TRUE;                                                                              \
    }                                                                                           \
                                                                                                \
  return proc_address;                                                                          \
}

/* 
 * GLX_VERSION_1_3
 */

_GDK_GL_GET_PROC(glXGetFBConfigs)

_GDK_GL_GET_PROC(glXChooseFBConfig)

_GDK_GL_GET_PROC(glXGetFBConfigAttrib)

_GDK_GL_GET_PROC(glXGetVisualFromFBConfig)

_GDK_GL_GET_PROC(glXCreateWindow)

_GDK_GL_GET_PROC(glXDestroyWindow)

_GDK_GL_GET_PROC(glXCreatePixmap)

_GDK_GL_GET_PROC(glXDestroyPixmap)

_GDK_GL_GET_PROC(glXCreatePbuffer)

_GDK_GL_GET_PROC(glXDestroyPbuffer)

_GDK_GL_GET_PROC(glXQueryDrawable)

_GDK_GL_GET_PROC(glXCreateNewContext)

_GDK_GL_GET_PROC(glXMakeContextCurrent)

_GDK_GL_GET_PROC(glXGetCurrentReadDrawable)

_GDK_GL_GET_PROC(glXGetCurrentDisplay)

_GDK_GL_GET_PROC(glXQueryContext)

_GDK_GL_GET_PROC(glXSelectEvent)

_GDK_GL_GET_PROC(glXGetSelectedEvent)

/* 
 * GLX_VERSION_1_4
 */

_GDK_GL_GET_PROC(glXGetProcAddress)

/* 
 * GLX_ARB_get_proc_address
 */

_GDK_GL_GET_PROC(glXGetProcAddressARB)

/* 
 * GLX_SGI_swap_control
 */

_GDK_GL_GET_PROC(glXSwapIntervalSGI)

/* 
 * GLX_SGI_video_sync
 */

_GDK_GL_GET_PROC(glXGetVideoSyncSGI)

_GDK_GL_GET_PROC(glXWaitVideoSyncSGI)

/* 
 * GLX_SGI_make_current_read
 */

_GDK_GL_GET_PROC(glXMakeCurrentReadSGI)

_GDK_GL_GET_PROC(glXGetCurrentReadDrawableSGI)

/* 
 * GLX_SGIX_video_source
 */

_GDK_GL_GET_PROC(glXCreateGLXVideoSourceSGIX)

_GDK_GL_GET_PROC(glXDestroyGLXVideoSourceSGIX)

/* 
 * GLX_EXT_import_context
 */

_GDK_GL_GET_PROC(glXGetCurrentDisplayEXT)

_GDK_GL_GET_PROC(glXQueryContextInfoEXT)

_GDK_GL_GET_PROC(glXGetContextIDEXT)

_GDK_GL_GET_PROC(glXImportContextEXT)

_GDK_GL_GET_PROC(glXFreeContextEXT)

/* 
 * GLX_SGIX_fbconfig
 */

_GDK_GL_GET_PROC(glXGetFBConfigAttribSGIX)

_GDK_GL_GET_PROC(glXChooseFBConfigSGIX)

_GDK_GL_GET_PROC(glXCreateGLXPixmapWithConfigSGIX)

_GDK_GL_GET_PROC(glXCreateContextWithConfigSGIX)

_GDK_GL_GET_PROC(glXGetVisualFromFBConfigSGIX)

_GDK_GL_GET_PROC(glXGetFBConfigFromVisualSGIX)

/* 
 * GLX_SGIX_pbuffer
 */

_GDK_GL_GET_PROC(glXCreateGLXPbufferSGIX)

_GDK_GL_GET_PROC(glXDestroyGLXPbufferSGIX)

_GDK_GL_GET_PROC(glXQueryGLXPbufferSGIX)

_GDK_GL_GET_PROC(glXSelectEventSGIX)

_GDK_GL_GET_PROC(glXGetSelectedEventSGIX)

/* 
 * GLX_SGI_cushion
 */

_GDK_GL_GET_PROC(glXCushionSGI)

/* 
 * GLX_SGIX_video_resize
 */

_GDK_GL_GET_PROC(glXBindChannelToWindowSGIX)

_GDK_GL_GET_PROC(glXChannelRectSGIX)

_GDK_GL_GET_PROC(glXQueryChannelRectSGIX)

_GDK_GL_GET_PROC(glXQueryChannelDeltasSGIX)

_GDK_GL_GET_PROC(glXChannelRectSyncSGIX)

/* 
 * GLX_SGIX_dmbuffer
 */

_GDK_GL_GET_PROC(glXAssociateDMPbufferSGIX)

/* 
 * GLX_SGIX_swap_group
 */

_GDK_GL_GET_PROC(glXJoinSwapGroupSGIX)

/* 
 * GLX_SGIX_swap_barrier
 */

_GDK_GL_GET_PROC(glXBindSwapBarrierSGIX)

_GDK_GL_GET_PROC(glXQueryMaxSwapBarriersSGIX)

/* 
 * GLX_SUN_get_transparent_index
 */

_GDK_GL_GET_PROC(glXGetTransparentIndexSUN)

/*
 * GLX_MESA_copy_sub_buffer
 */

_GDK_GL_GET_PROC(glXCopySubBufferMESA)

/*
 * GLX_MESA_pixmap_colormap
 */

_GDK_GL_GET_PROC(glXCreateGLXPixmapMESA)

/*
 * GLX_MESA_release_buffers
 */

_GDK_GL_GET_PROC(glXReleaseBuffersMESA)

/*
 * GLX_MESA_set_3dfx_mode
 */

_GDK_GL_GET_PROC(glXSet3DfxModeMESA)

/* 
 * GLX_OML_sync_control
 */

_GDK_GL_GET_PROC(glXGetSyncValuesOML)

_GDK_GL_GET_PROC(glXGetMscRateOML)

_GDK_GL_GET_PROC(glXSwapBuffersMscOML)

_GDK_GL_GET_PROC(glXWaitForMscOML)

_GDK_GL_GET_PROC(glXWaitForSbcOML)
