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

#define _GDK_GL_GET_PROC(proc_name)                                     \
GdkGLProc                                                               \
_GDK_GL_CONCAT(gdk_gl_get_, proc_name) (void)                           \
{                                                                       \
  static gboolean init = FALSE;                                         \
  static GdkGLProc proc_address = NULL;                                 \
                                                                        \
  if (!init)                                                            \
    {                                                                   \
      GDK_GL_NOTE (IMPL, g_message (" * Get %s ()", #proc_name));       \
      proc_address = gdk_gl_query_get_proc_address (#proc_name);        \
      init = TRUE;                                                      \
    }                                                                   \
                                                                        \
  return proc_address;                                                  \
}

_GDK_GL_GET_PROC(glXGetProcAddressARB)

_GDK_GL_GET_PROC(glXSwapIntervalSGI)

_GDK_GL_GET_PROC(glXGetVideoSyncSGI)

_GDK_GL_GET_PROC(glXWaitVideoSyncSGI)

_GDK_GL_GET_PROC(glXMakeCurrentReadSGI)

_GDK_GL_GET_PROC(glXGetCurrentReadDrawableSGI)

_GDK_GL_GET_PROC(glXCreateGLXVideoSourceSGIX)

_GDK_GL_GET_PROC(glXDestroyGLXVideoSourceSGIX)

_GDK_GL_GET_PROC(glXGetCurrentDisplayEXT)

_GDK_GL_GET_PROC(glXQueryContextInfoEXT)

_GDK_GL_GET_PROC(glXGetContextIDEXT)

_GDK_GL_GET_PROC(glXImportContextEXT)

_GDK_GL_GET_PROC(glXFreeContextEXT)

_GDK_GL_GET_PROC(glXGetFBConfigAttribSGIX)

_GDK_GL_GET_PROC(glXChooseFBConfigSGIX)

_GDK_GL_GET_PROC(glXCreateGLXPixmapWithConfigSGIX)

_GDK_GL_GET_PROC(glXCreateContextWithConfigSGIX)

_GDK_GL_GET_PROC(glXGetVisualFromFBConfigSGIX)

_GDK_GL_GET_PROC(glXGetFBConfigFromVisualSGIX)

_GDK_GL_GET_PROC(glXCreateGLXPbufferSGIX)

_GDK_GL_GET_PROC(glXDestroyGLXPbufferSGIX)

_GDK_GL_GET_PROC(glXQueryGLXPbufferSGIX)

_GDK_GL_GET_PROC(glXSelectEventSGIX)

_GDK_GL_GET_PROC(glXGetSelectedEventSGIX)

_GDK_GL_GET_PROC(glXCushionSGI)

_GDK_GL_GET_PROC(glXBindChannelToWindowSGIX)

_GDK_GL_GET_PROC(glXChannelRectSGIX)

_GDK_GL_GET_PROC(glXQueryChannelRectSGIX)

_GDK_GL_GET_PROC(glXQueryChannelDeltasSGIX)

_GDK_GL_GET_PROC(glXChannelRectSyncSGIX)

_GDK_GL_GET_PROC(glXAssociateDMPbufferSGIX)

_GDK_GL_GET_PROC(glXJoinSwapGroupSGIX)

_GDK_GL_GET_PROC(glXBindSwapBarrierSGIX)

_GDK_GL_GET_PROC(glXQueryMaxSwapBarriersSGIX)

_GDK_GL_GET_PROC(glXGetTransparentIndexSUN)

_GDK_GL_GET_PROC(glXCopySubBufferMESA)

_GDK_GL_GET_PROC(glXCreateGLXPixmapMESA)

_GDK_GL_GET_PROC(glXReleaseBuffersMESA)

_GDK_GL_GET_PROC(glXSet3DfxModeMESA)

_GDK_GL_GET_PROC(glXGetSyncValuesOML)

_GDK_GL_GET_PROC(glXGetMscRateOML)

_GDK_GL_GET_PROC(glXSwapBuffersMscOML)

_GDK_GL_GET_PROC(glXWaitForMscOML)

_GDK_GL_GET_PROC(glXWaitForSbcOML)
