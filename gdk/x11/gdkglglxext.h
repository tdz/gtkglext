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

#ifndef __GDK_GL_GLXEXT_H__
#define __GDK_GL_GLXEXT_H__

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <GL/glx.h>
#include <GL/gl.h>

#include <gdk/gdkglquery.h>

G_BEGIN_DECLS

#ifndef GLX_VERSION_1_3
typedef struct __GLXFBConfigRec *GLXFBConfig;
typedef XID GLXFBConfigID;
typedef XID GLXContextID;
typedef XID GLXWindow;
typedef XID GLXPbuffer;
#endif

#if !defined(__glxext_h_) && defined(GLX_ARB_get_proc_address)
/* for __GLXextFuncPtr typedef in glxext.h */
#  undef GLX_ARB_get_proc_address
#endif
#include <gdk/glext/glxext.h>

/* 
 * GLX_ARB_get_proc_address
 */

/* glXGetProcAddressARB */
GdkGLProc gdk_gl_get_glXGetProcAddressARB (void);
#define   gdk_gl_glXGetProcAddressARB(proc, procName) \
  (((PFNGLXGETPROCADDRESSARBPROC) (proc)) (procName))

/* 
 * GLX_SGI_swap_control
 */

/* glXSwapIntervalSGI */
GdkGLProc gdk_gl_get_glXSwapIntervalSGI (void);
#define   gdk_gl_glXSwapIntervalSGI(proc, interval) \
  (((PFNGLXSWAPINTERVALSGIPROC) (proc)) (interval))

/* 
 * GLX_SGI_video_sync
 */

/* glXGetVideoSyncSGI */
GdkGLProc gdk_gl_get_glXGetVideoSyncSGI (void);
#define   gdk_gl_glXGetVideoSyncSGI(proc, count) \
  (((PFNGLXGETVIDEOSYNCSGIPROC) (proc)) (count))

/* glXWaitVideoSyncSGI */
GdkGLProc gdk_gl_get_glXWaitVideoSyncSGI (void);
#define   gdk_gl_glXWaitVideoSyncSGI(proc, divisor, remainder, count) \
  (((PFNGLXWAITVIDEOSYNCSGIPROC) (proc)) (divisor, remainder, count))

/* 
 * GLX_SGI_make_current_read
 */

/* glXMakeCurrentReadSGI */
GdkGLProc gdk_gl_get_glXMakeCurrentReadSGI (void);
#define   gdk_gl_glXMakeCurrentReadSGI(proc, dpy, draw, read, ctx) \
  (((PFNGLXMAKECURRENTREADSGIPROC) (proc)) (dpy, draw, read, ctx))

/* glXGetCurrentReadDrawableSGI */
GdkGLProc gdk_gl_get_glXGetCurrentReadDrawableSGI (void);
#define   gdk_gl_glXGetCurrentReadDrawableSGI(proc) \
  (((PFNGLXGETCURRENTREADDRAWABLESGIPROC) (proc)) ())

/* 
 * GLX_SGIX_video_source
 */

#ifdef _VL_H

/* glXCreateGLXVideoSourceSGIX */
GdkGLProc gdk_gl_get_glXCreateGLXVideoSourceSGIX (void);
#define   gdk_gl_glXCreateGLXVideoSourceSGIX(proc, display, screen, server, path, nodeClass, drainNode) \
  (((PFNGLXCREATEGLXVIDEOSOURCESGIXPROC) (proc)) (display, screen, server, path, nodeClass, drainNode))

/* glXDestroyGLXVideoSourceSGIX */
GdkGLProc gdk_gl_get_glXDestroyGLXVideoSourceSGIX (void);
#define   gdk_gl_glXDestroyGLXVideoSourceSGIX(proc, dpy, glxvideosource) \
  (((PFNGLXDESTROYGLXVIDEOSOURCESGIXPROC) (proc)) (dpy, glxvideosource))

#endif /* _VL_H */

/* 
 * GLX_EXT_import_context
 */

/* glXGetCurrentDisplayEXT */
GdkGLProc gdk_gl_get_glXGetCurrentDisplayEXT (void);
#define   gdk_gl_glXGetCurrentDisplayEXT(proc) \
  (((PFNGLXGETCURRENTDISPLAYEXTPROC) (proc)) ())

/* glXQueryContextInfoEXT */
GdkGLProc gdk_gl_get_glXQueryContextInfoEXT (void);
#define   gdk_gl_glXQueryContextInfoEXT(proc, dpy, context, attribute, value) \
  (((PFNGLXQUERYCONTEXTINFOEXTPROC) (proc)) (dpy, context, attribute, value))

/* glXGetContextIDEXT */
GdkGLProc gdk_gl_get_glXGetContextIDEXT (void);
#define   gdk_gl_glXGetContextIDEXT(proc, context) \
  (((PFNGLXGETCONTEXTIDEXTPROC) (proc)) (context))

/* glXImportContextEXT */
GdkGLProc gdk_gl_get_glXImportContextEXT (void);
#define   gdk_gl_glXImportContextEXT(proc, dpy, contextID) \
  (((PFNGLXIMPORTCONTEXTEXTPROC) (proc)) (dpy, contextID))

/* glXFreeContextEXT */
GdkGLProc gdk_gl_get_glXFreeContextEXT (void);
#define   gdk_gl_glXFreeContextEXT(proc, dpy, context) \
  (((PFNGLXFREECONTEXTEXTPROC) (proc)) (dpy, context))

/* 
 * GLX_SGIX_fbconfig
 */

/* glXGetFBConfigAttribSGIX */
GdkGLProc gdk_gl_get_glXGetFBConfigAttribSGIX (void);
#define   gdk_gl_glXGetFBConfigAttribSGIX(proc, dpy, config, attribute, value) \
  (((PFNGLXGETFBCONFIGATTRIBSGIXPROC) (proc)) (dpy, config, attribute, value))

/* glXChooseFBConfigSGIX */
GdkGLProc gdk_gl_get_glXChooseFBConfigSGIX (void);
#define   gdk_gl_glXChooseFBConfigSGIX(proc, dpy, screen, attrib_list, nelements) \
  (((PFNGLXCHOOSEFBCONFIGSGIXPROC) (proc)) (dpy, screen, attrib_list, nelements))

/* glXCreateGLXPixmapWithConfigSGIX */
GdkGLProc gdk_gl_get_glXCreateGLXPixmapWithConfigSGIX (void);
#define   gdk_gl_glXCreateGLXPixmapWithConfigSGIX(proc, dpy, config, pixmap) \
  (((PFNGLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC) (proc)) (dpy, config, pixmap))

/* glXCreateContextWithConfigSGIX */
GdkGLProc gdk_gl_get_glXCreateContextWithConfigSGIX (void);
#define   gdk_gl_glXCreateContextWithConfigSGIX(proc, dpy, config, render_type, share_list, direct) \
  (((PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC) (proc)) (dpy, config, render_type, share_list, direct))

/* glXGetVisualFromFBConfigSGIX */
GdkGLProc gdk_gl_get_glXGetVisualFromFBConfigSGIX (void);
#define   gdk_gl_glXGetVisualFromFBConfigSGIX(proc, dpy, config) \
  (((PFNGLXCREATECONTEXTWITHCONFIGSGIXPROC) (proc)) (dpy, config))

/* glXGetFBConfigFromVisualSGIX */
GdkGLProc gdk_gl_get_glXGetFBConfigFromVisualSGIX (void);
#define   gdk_gl_glXGetFBConfigFromVisualSGIX(proc, dpy, vis) \
  (((PFNGLXGETFBCONFIGFROMVISUALSGIXPROC) (proc)) (dpy, vis))

/* 
 * GLX_SGIX_pbuffer
 */

/* glXCreateGLXPbufferSGIX */
GdkGLProc gdk_gl_get_glXCreateGLXPbufferSGIX (void);
#define   gdk_gl_glXCreateGLXPbufferSGIX(proc, dpy, config, width, height, attrib_list) \
  (((PFNGLXCREATEGLXPBUFFERSGIXPROC) (proc)) (dpy, config, width, height, attrib_list))

/* glXDestroyGLXPbufferSGIX */
GdkGLProc gdk_gl_get_glXDestroyGLXPbufferSGIX (void);
#define   gdk_gl_glXDestroyGLXPbufferSGIX(proc, dpy, pbuf) \
  (((PFNGLXDESTROYGLXPBUFFERSGIXPROC) (proc)) (dpy, pbuf))

/* glXQueryGLXPbufferSGIX */
GdkGLProc gdk_gl_get_glXQueryGLXPbufferSGIX (void);
#define   gdk_gl_glXQueryGLXPbufferSGIX(proc, dpy, pbuf, attribute, value) \
  (((PFNGLXDESTROYGLXPBUFFERSGIXPROC) (proc)) (dpy, pbuf, attribute, value))

/* glXSelectEventSGIX */
GdkGLProc gdk_gl_get_glXSelectEventSGIX (void);
#define   gdk_gl_glXSelectEventSGIX(proc, dpy, drawable, mask) \
  (((PFNGLXSELECTEVENTSGIXPROC) (proc)) (dpy, drawable, mask))

/* glXGetSelectedEventSGIX */
GdkGLProc gdk_gl_get_glXGetSelectedEventSGIX (void);
#define   gdk_gl_glXGetSelectedEventSGIX(proc, dpy, drawable, mask) \
  (((PFNGLXGETSELECTEDEVENTSGIXPROC) (proc)) (dpy, drawable, mask))

/* 
 * GLX_SGI_cushion
 */

/* glXCushionSGI */
GdkGLProc gdk_gl_get_glXCushionSGI (void);
#define   gdk_gl_glXCushionSGI(proc, dpy, window, cushion) \
  (((PFNGLXCUSHIONSGIPROC) (proc)) (dpy, window, cushion))

/* 
 * GLX_SGIX_video_resize
 */

/* glXBindChannelToWindowSGIX */
GdkGLProc gdk_gl_get_glXBindChannelToWindowSGIX (void);
#define   gdk_gl_glXBindChannelToWindowSGIX(proc, display, screen, channel, window) \
  (((PFNGLXBINDCHANNELTOWINDOWSGIXPROC) (proc)) (display, screen, channel, window))

/* glXChannelRectSGIX */
GdkGLProc gdk_gl_get_glXChannelRectSGIX (void);
#define   gdk_gl_glXChannelRectSGIX(proc, display, screen, channel, x, y, w, h) \
  (((PFNGLXCHANNELRECTSGIXPROC) (proc)) (display, screen, channel, x, y, w, h))

/* glXQueryChannelRectSGIX */
GdkGLProc gdk_gl_get_glXQueryChannelRectSGIX (void);
#define   gdk_gl_glXQueryChannelRectSGIX(proc, display, screen, channel, dx, dy, dw, dh) \
  (((PFNGLXQUERYCHANNELRECTSGIXPROC) (proc)) (display, screen, channel, dx, dy, dw, dh))

/* glXQueryChannelDeltasSGIX */
GdkGLProc gdk_gl_get_glXQueryChannelDeltasSGIX (void);
#define   gdk_gl_glXQueryChannelDeltasSGIX(proc, display, screen, channel, x, y, w, h) \
  (((PFNGLXQUERYCHANNELDELTASSGIXPROC) (proc)) (display, screen, channel, x, y, w, h))

/* glXChannelRectSyncSGIX */
GdkGLProc gdk_gl_get_glXChannelRectSyncSGIX (void);
#define   gdk_gl_glXChannelRectSyncSGIX(proc, display, screen, channel, synctype) \
  (((PFNGLXCHANNELRECTSYNCSGIXPROC) (proc)) (display, screen, channel, synctype))

/* 
 * GLX_SGIX_dmbuffer
 */

#ifdef _DM_BUFFER_H_

/* glXAssociateDMPbufferSGIX */
GdkGLProc gdk_gl_get_glXAssociateDMPbufferSGIX (void);
#define   gdk_gl_glXAssociateDMPbufferSGIX(proc, dpy, pbuffer, params, dmbuffer) \
  (((PFNGLXASSOCIATEDMPBUFFERSGIXPROC) (proc)) (dpy, pbuffer, params, dmbuffer))

#endif /* _DM_BUFFER_H_ */

/* 
 * GLX_SGIX_swap_group
 */

/* glXJoinSwapGroupSGIX */
GdkGLProc gdk_gl_get_glXJoinSwapGroupSGIX (void);
#define   gdk_gl_glXJoinSwapGroupSGIX(proc, dpy, drawable, member) \
  (((PFNGLXJOINSWAPGROUPSGIXPROC) (proc)) (dpy, drawable, member))

/* 
 * GLX_SGIX_swap_barrier
 */

/* glXBindSwapBarrierSGIX */
GdkGLProc gdk_gl_get_glXBindSwapBarrierSGIX (void);
#define   gdk_gl_glXBindSwapBarrierSGIX(proc, dpy, drawable, barrier) \
  (((PFNGLXBINDSWAPBARRIERSGIXPROC) (proc)) (dpy, drawable, barrier))

/* glXQueryMaxSwapBarriersSGIX */
GdkGLProc gdk_gl_get_glXQueryMaxSwapBarriersSGIX (void);
#define   gdk_gl_glXQueryMaxSwapBarriersSGIX(proc, dpy, screen, max) \
  (((PFNGLXQUERYMAXSWAPBARRIERSSGIXPROC) (proc)) (dpy, screen, max))

/* 
 * GLX_SUN_get_transparent_index
 */

/* glXGetTransparentIndexSUN */
GdkGLProc gdk_gl_get_glXGetTransparentIndexSUN (void);
#define   gdk_gl_glXGetTransparentIndexSUN(proc, dpy, overlay, underlay, pTransparentIndex) \
  (((PFNGLXGETTRANSPARENTINDEXSUNPROC) (proc)) (dpy, overlay, underlay, pTransparentIndex))

/*
 * GLX_MESA_copy_sub_buffer
 */

/* glXCopySubBufferMESA */
GdkGLProc gdk_gl_get_glXCopySubBufferMESA (void);
#define   gdk_gl_glXCopySubBufferMESA(proc, dpy, drawable, x, y, width, height) \
  (((PFNGLXCOPYSUBBUFFERMESAPROC) (proc)) (dpy, drawable, x, y, width, height))

/*
 * GLX_MESA_pixmap_colormap
 */

/* glXCreateGLXPixmapMESA */
GdkGLProc gdk_gl_get_glXCreateGLXPixmapMESA (void);
#define   gdk_gl_glXCreateGLXPixmapMESA(proc, dpy, visual, pixmap, cmap) \
  (((PFNGLXCREATEGLXPIXMAPMESAPROC) (proc)) (dpy, visual, pixmap, cmap))

/*
 * GLX_MESA_release_buffers
 */

/* glXReleaseBuffersMESA */
GdkGLProc gdk_gl_get_glXReleaseBuffersMESA (void);
#define   gdk_gl_glXReleaseBuffersMESA(proc, dpy, drawable) \
  (((PFNGLXRELEASEBUFFERSMESAPROC) (proc)) (dpy, drawable))

/*
 * GLX_MESA_set_3dfx_mode
 */

/* glXSet3DfxModeMESA */
GdkGLProc gdk_gl_get_glXSet3DfxModeMESA (void);
#define   gdk_gl_glXSet3DfxModeMESA(proc, mode) \
  (((PFNGLXSET3DFXMODEMESAPROC) (proc)) (mode))

/* 
 * GLX_OML_sync_control
 */

/* glXGetSyncValuesOML */
GdkGLProc gdk_gl_get_glXGetSyncValuesOML (void);
#define   gdk_gl_glXGetSyncValuesOML(proc, dpy, drawable, ust, msc, sbc) \
  (((PFNGLXGETSYNCVALUESOMLPROC) (proc)) (dpy, drawable, ust, msc, sbc))

/* glXGetMscRateOML */
GdkGLProc gdk_gl_get_glXGetMscRateOML (void);
#define   gdk_gl_glXGetMscRateOML(proc, dpy, drawable, numerator, denominator) \
  (((PFNGLXGETMSCRATEOMLPROC) (proc)) (dpy, drawable, numerator, denominator))

/* glXSwapBuffersMscOML */
GdkGLProc gdk_gl_get_glXSwapBuffersMscOML (void);
#define   gdk_gl_glXSwapBuffersMscOML(proc, dpy, drawable, target_msc, divisor, remainder) \
  (((PFNGLXSWAPBUFFERSMSCOMLPROC) (proc)) (dpy, drawable, target_msc, divisor, remainder))

/* glXWaitForMscOML */
GdkGLProc gdk_gl_get_glXWaitForMscOML (void);
#define   gdk_gl_glXWaitForMscOML(proc, dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc) \
  (((PFNGLXWAITFORMSCOMLPROC) (proc)) (dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc))

/* glXWaitForSbcOML */
GdkGLProc gdk_gl_get_glXWaitForSbcOML (void);
#define   gdk_gl_glXWaitForSbcOML(proc, dpy, drawable, target_sbc, ust, msc, sbc) \
  (((PFNGLXWAITFORSBCOMLPROC) (proc)) (dpy, drawable, target_sbc, ust, msc, sbc))

G_END_DECLS

#endif /* __GDK_GL_GLXEXT_H__ */
