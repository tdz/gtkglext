/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002-2003  Naofumi Yasufuku
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

#include "gdkglx.h"
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

GdkGL_GLX_VERSION_1_3 *
gdk_gl_get_GLX_VERSION_1_3 (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_VERSION_1_3 ()"));

  if (!init)
    {
      supported &= (gdk_gl_get_glXGetFBConfigs ()           != NULL);
      supported &= (gdk_gl_get_glXChooseFBConfig ()         != NULL);
      supported &= (gdk_gl_get_glXGetFBConfigAttrib ()      != NULL);
      supported &= (gdk_gl_get_glXGetVisualFromFBConfig ()  != NULL);
      supported &= (gdk_gl_get_glXCreateWindow ()           != NULL);
      supported &= (gdk_gl_get_glXDestroyWindow ()          != NULL);
      supported &= (gdk_gl_get_glXCreatePixmap ()           != NULL);
      supported &= (gdk_gl_get_glXDestroyPixmap ()          != NULL);
      supported &= (gdk_gl_get_glXCreatePbuffer ()          != NULL);
      supported &= (gdk_gl_get_glXDestroyPbuffer ()         != NULL);
      supported &= (gdk_gl_get_glXQueryDrawable ()          != NULL);
      supported &= (gdk_gl_get_glXCreateNewContext ()       != NULL);
      supported &= (gdk_gl_get_glXMakeContextCurrent ()     != NULL);
      supported &= (gdk_gl_get_glXGetCurrentReadDrawable () != NULL);
      supported &= (gdk_gl_get_glXGetCurrentDisplay ()      != NULL);
      supported &= (gdk_gl_get_glXQueryContext ()           != NULL);
      supported &= (gdk_gl_get_glXSelectEvent ()            != NULL);
      supported &= (gdk_gl_get_glXGetSelectedEvent ()       != NULL);

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_3));
}

/* 
 * GLX_VERSION_1_4
 */

static GdkGL_GLX_VERSION_1_4 _GDK_GL_PROCS (GdkGL_GLX_VERSION_1_4) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_4), glXGetProcAddress)

GdkGL_GLX_VERSION_1_4 *
gdk_gl_get_GLX_VERSION_1_4 (void)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_VERSION_1_4 ()"));

  if (!init)
    {
      supported &= (gdk_gl_get_glXGetProcAddress () != NULL);

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_VERSION_1_4));
}

/* 
 * GLX_ARB_get_proc_address
 */

static GdkGL_GLX_ARB_get_proc_address _GDK_GL_PROCS (GdkGL_GLX_ARB_get_proc_address) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_ARB_get_proc_address), glXGetProcAddressARB)

GdkGL_GLX_ARB_get_proc_address *
gdk_gl_get_GLX_ARB_get_proc_address (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_ARB_get_proc_address ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_ARB_get_proc_address");

      if (supported)
        {
          supported &= (gdk_gl_get_glXGetProcAddressARB () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_ARB_get_proc_address));
}

/* 
 * GLX_SGI_swap_control
 */

static GdkGL_GLX_SGI_swap_control _GDK_GL_PROCS (GdkGL_GLX_SGI_swap_control) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_swap_control), glXSwapIntervalSGI)

GdkGL_GLX_SGI_swap_control *
gdk_gl_get_GLX_SGI_swap_control (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGI_swap_control ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGI_swap_control");

      if (supported)
        {
          supported &= (gdk_gl_get_glXSwapIntervalSGI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGI_swap_control));
}

/* 
 * GLX_SGI_video_sync
 */

static GdkGL_GLX_SGI_video_sync _GDK_GL_PROCS (GdkGL_GLX_SGI_video_sync) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_video_sync), glXGetVideoSyncSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_video_sync), glXWaitVideoSyncSGI)

GdkGL_GLX_SGI_video_sync *
gdk_gl_get_GLX_SGI_video_sync (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGI_video_sync ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGI_video_sync");

      if (supported)
        {
          supported &= (gdk_gl_get_glXGetVideoSyncSGI ()  != NULL);
          supported &= (gdk_gl_get_glXWaitVideoSyncSGI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGI_video_sync));
}

/* 
 * GLX_SGI_make_current_read
 */

static GdkGL_GLX_SGI_make_current_read _GDK_GL_PROCS (GdkGL_GLX_SGI_make_current_read) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_make_current_read), glXMakeCurrentReadSGI)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_make_current_read), glXGetCurrentReadDrawableSGI)

GdkGL_GLX_SGI_make_current_read *
gdk_gl_get_GLX_SGI_make_current_read (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGI_make_current_read ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGI_make_current_read");

      if (supported)
        {
          supported &= (gdk_gl_get_glXMakeCurrentReadSGI ()        != NULL);
          supported &= (gdk_gl_get_glXGetCurrentReadDrawableSGI () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGI_make_current_read));
}

/* 
 * GLX_SGIX_video_source
 */

#ifdef _VL_H

static GdkGL_GLX_SGIX_video_source _GDK_GL_PROCS (GdkGL_GLX_SGIX_video_source) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_source), glXCreateGLXVideoSourceSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_source), glXDestroyGLXVideoSourceSGIX)

GdkGL_GLX_SGIX_video_source *
gdk_gl_get_GLX_SGIX_video_source (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGIX_video_source ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGIX_video_source");

      if (supported)
        {
          supported &= (gdk_gl_get_glXCreateGLXVideoSourceSGIX ()  != NULL);
          supported &= (gdk_gl_get_glXDestroyGLXVideoSourceSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_source));
}

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

GdkGL_GLX_EXT_import_context *
gdk_gl_get_GLX_EXT_import_context (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_EXT_import_context ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_EXT_import_context");

      if (supported)
        {
          supported &= (gdk_gl_get_glXGetCurrentDisplayEXT () != NULL);
          supported &= (gdk_gl_get_glXQueryContextInfoEXT ()  != NULL);
          supported &= (gdk_gl_get_glXGetContextIDEXT ()      != NULL);
          supported &= (gdk_gl_get_glXImportContextEXT ()     != NULL);
          supported &= (gdk_gl_get_glXFreeContextEXT ()       != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_EXT_import_context));
}

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

GdkGL_GLX_SGIX_fbconfig *
gdk_gl_get_GLX_SGIX_fbconfig (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGIX_fbconfig ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGIX_fbconfig");

      if (supported)
        {
          supported &= (gdk_gl_get_glXGetFBConfigAttribSGIX ()         != NULL);
          supported &= (gdk_gl_get_glXChooseFBConfigSGIX ()            != NULL);
          supported &= (gdk_gl_get_glXCreateGLXPixmapWithConfigSGIX () != NULL);
          supported &= (gdk_gl_get_glXCreateContextWithConfigSGIX ()   != NULL);
          supported &= (gdk_gl_get_glXGetVisualFromFBConfigSGIX ()     != NULL);
          supported &= (gdk_gl_get_glXGetFBConfigFromVisualSGIX ()     != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGIX_fbconfig));
}

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

GdkGL_GLX_SGIX_pbuffer *
gdk_gl_get_GLX_SGIX_pbuffer (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGIX_pbuffer ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGIX_pbuffer");

      if (supported)
        {
          supported &= (gdk_gl_get_glXCreateGLXPbufferSGIX ()  != NULL);
          supported &= (gdk_gl_get_glXDestroyGLXPbufferSGIX () != NULL);
          supported &= (gdk_gl_get_glXQueryGLXPbufferSGIX ()   != NULL);
          supported &= (gdk_gl_get_glXSelectEventSGIX ()       != NULL);
          supported &= (gdk_gl_get_glXGetSelectedEventSGIX ()  != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGIX_pbuffer));
}

/* 
 * GLX_SGI_cushion
 */

static GdkGL_GLX_SGI_cushion _GDK_GL_PROCS (GdkGL_GLX_SGI_cushion) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGI_cushion), glXCushionSGI)

GdkGL_GLX_SGI_cushion *
gdk_gl_get_GLX_SGI_cushion (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGI_cushion ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGI_cushion");

      if (supported)
        {
          supported &= (gdk_gl_get_glXCushionSGI ()  != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGI_cushion));
}

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

GdkGL_GLX_SGIX_video_resize *
gdk_gl_get_GLX_SGIX_video_resize (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGIX_video_resize ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGIX_video_resize");

      if (supported)
        {
          supported &= (gdk_gl_get_glXBindChannelToWindowSGIX () != NULL);
          supported &= (gdk_gl_get_glXChannelRectSGIX ()         != NULL);
          supported &= (gdk_gl_get_glXQueryChannelRectSGIX ()    != NULL);
          supported &= (gdk_gl_get_glXQueryChannelDeltasSGIX ()  != NULL);
          supported &= (gdk_gl_get_glXChannelRectSyncSGIX ()     != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGIX_video_resize));
}

/* 
 * GLX_SGIX_dmbuffer
 */

#ifdef _DM_BUFFER_H_

static GdkGL_GLX_SGIX_dmbuffer _GDK_GL_PROCS (GdkGL_GLX_SGIX_dmbuffer) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_dmbuffer), glXAssociateDMPbufferSGIX)

GdkGL_GLX_SGIX_dmbuffer *
gdk_gl_get_GLX_SGIX_dmbuffer (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGIX_dmbuffer ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGIX_dmbuffer");

      if (supported)
        {
          supported &= (gdk_gl_get_glXAssociateDMPbufferSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGIX_dmbuffer));
}

#endif /* _DM_BUFFER_H_ */

/* 
 * GLX_SGIX_swap_group
 */

static GdkGL_GLX_SGIX_swap_group _GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_group) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_group), glXJoinSwapGroupSGIX)

GdkGL_GLX_SGIX_swap_group *
gdk_gl_get_GLX_SGIX_swap_group (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGIX_swap_group ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGIX_swap_group");

      if (supported)
        {
          supported &= (gdk_gl_get_glXJoinSwapGroupSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_group));
}

/* 
 * GLX_SGIX_swap_barrier
 */

static GdkGL_GLX_SGIX_swap_barrier _GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_barrier) = {
  NULL, NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_barrier), glXBindSwapBarrierSGIX)
_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_barrier), glXQueryMaxSwapBarriersSGIX)

GdkGL_GLX_SGIX_swap_barrier *
gdk_gl_get_GLX_SGIX_swap_barrier (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SGIX_swap_barrier ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SGIX_swap_barrier");

      if (supported)
        {
          supported &= (gdk_gl_get_glXBindSwapBarrierSGIX ()      != NULL);
          supported &= (gdk_gl_get_glXQueryMaxSwapBarriersSGIX () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SGIX_swap_barrier));
}

/* 
 * GLX_SUN_get_transparent_index
 */

static GdkGL_GLX_SUN_get_transparent_index _GDK_GL_PROCS (GdkGL_GLX_SUN_get_transparent_index) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_SUN_get_transparent_index), glXGetTransparentIndexSUN)

GdkGL_GLX_SUN_get_transparent_index *
gdk_gl_get_GLX_SUN_get_transparent_index (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_SUN_get_transparent_index ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_SUN_get_transparent_index");

      if (supported)
        {
          supported &= (gdk_gl_get_glXGetTransparentIndexSUN () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_SUN_get_transparent_index));
}

/*
 * GLX_MESA_copy_sub_buffer
 */

static GdkGL_GLX_MESA_copy_sub_buffer _GDK_GL_PROCS (GdkGL_GLX_MESA_copy_sub_buffer) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_MESA_copy_sub_buffer), glXCopySubBufferMESA)

GdkGL_GLX_MESA_copy_sub_buffer *
gdk_gl_get_GLX_MESA_copy_sub_buffer (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_MESA_copy_sub_buffer ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_MESA_copy_sub_buffer");

      if (supported)
        {
          supported &= (gdk_gl_get_glXCopySubBufferMESA () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_MESA_copy_sub_buffer));
}

/*
 * GLX_MESA_pixmap_colormap
 */

static GdkGL_GLX_MESA_pixmap_colormap _GDK_GL_PROCS (GdkGL_GLX_MESA_pixmap_colormap) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_MESA_pixmap_colormap), glXCreateGLXPixmapMESA)

GdkGL_GLX_MESA_pixmap_colormap *
gdk_gl_get_GLX_MESA_pixmap_colormap (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_MESA_pixmap_colormap ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_MESA_pixmap_colormap");

      if (supported)
        {
          supported &= (gdk_gl_get_glXCreateGLXPixmapMESA () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_MESA_pixmap_colormap));
}

/*
 * GLX_MESA_release_buffers
 */

static GdkGL_GLX_MESA_release_buffers _GDK_GL_PROCS (GdkGL_GLX_MESA_release_buffers) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_MESA_release_buffers), glXReleaseBuffersMESA)

GdkGL_GLX_MESA_release_buffers *
gdk_gl_get_GLX_MESA_release_buffers (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_MESA_release_buffers ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_MESA_release_buffers");

      if (supported)
        {
          supported &= (gdk_gl_get_glXReleaseBuffersMESA () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_MESA_release_buffers));
}

/*
 * GLX_MESA_set_3dfx_mode
 */

static GdkGL_GLX_MESA_set_3dfx_mode _GDK_GL_PROCS (GdkGL_GLX_MESA_set_3dfx_mode) = {
  NULL
};

_GDK_GL_GET_PROC (_GDK_GL_PROCS (GdkGL_GLX_MESA_set_3dfx_mode), glXSet3DfxModeMESA)

GdkGL_GLX_MESA_set_3dfx_mode *
gdk_gl_get_GLX_MESA_set_3dfx_mode (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_MESA_set_3dfx_mode ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_MESA_set_3dfx_mode");

      if (supported)
        {
          supported &= (gdk_gl_get_glXSet3DfxModeMESA () != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_MESA_set_3dfx_mode));
}

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

GdkGL_GLX_OML_sync_control *
gdk_gl_get_GLX_OML_sync_control (GdkGLConfig *glconfig)
{
  static gboolean init = FALSE;
  static gboolean supported = TRUE;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_get_GLX_OML_sync_control ()"));

  if (!init)
    {
      supported = gdk_x11_gl_query_glx_extension (glconfig, "GLX_OML_sync_control");

      if (supported)
        {
          supported &= (gdk_gl_get_glXGetSyncValuesOML ()  != NULL);
          supported &= (gdk_gl_get_glXGetMscRateOML ()     != NULL);
          supported &= (gdk_gl_get_glXSwapBuffersMscOML () != NULL);
          supported &= (gdk_gl_get_glXWaitForMscOML ()     != NULL);
          supported &= (gdk_gl_get_glXWaitForSbcOML ()     != NULL);
        }

      init = TRUE;
    }

  if (!supported)
    return NULL;

  return &(_GDK_GL_PROCS (GdkGL_GLX_OML_sync_control));
}
