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

#ifndef __GDK_GL_GLX_EXT_H__
#define __GDK_GL_GLX_EXT_H__

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <GL/glx.h>
#include <GL/gl.h>

#include <gdk/gdkglquery.h>

G_BEGIN_DECLS

/* 
 * GLX_VERSION_1_3
 */

typedef GLXFBConfig * ( * GDK_GL_GLXGETFBCONFIGSPROC) (Display *dpy, int screen, int *nelements);
typedef GLXFBConfig * ( * GDK_GL_GLXCHOOSEFBCONFIGPROC) (Display *dpy, int screen, const int *attrib_list, int *nelements);
typedef int ( * GDK_GL_GLXGETFBCONFIGATTRIBPROC) (Display *dpy, GLXFBConfig config, int attribute, int *value);
typedef XVisualInfo * ( * GDK_GL_GLXGETVISUALFROMFBCONFIGPROC) (Display *dpy, GLXFBConfig config);
typedef GLXWindow ( * GDK_GL_GLXCREATEWINDOWPROC) (Display *dpy, GLXFBConfig config, Window win, const int *attrib_list);
typedef void ( * GDK_GL_GLXDESTROYWINDOWPROC) (Display *dpy, GLXWindow win);
typedef GLXPixmap ( * GDK_GL_GLXCREATEPIXMAPPROC) (Display *dpy, GLXFBConfig config, Pixmap pixmap, const int *attrib_list);
typedef void ( * GDK_GL_GLXDESTROYPIXMAPPROC) (Display *dpy, GLXPixmap pixmap);
typedef GLXPbuffer ( * GDK_GL_GLXCREATEPBUFFERPROC) (Display *dpy, GLXFBConfig config, const int *attrib_list);
typedef void ( * GDK_GL_GLXDESTROYPBUFFERPROC) (Display *dpy, GLXPbuffer pbuf);
typedef void ( * GDK_GL_GLXQUERYDRAWABLEPROC) (Display *dpy, GLXDrawable draw, int attribute, unsigned int *value);
typedef GLXContext ( * GDK_GL_GLXCREATENEWCONTEXTPROC) (Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
typedef Bool ( * GDK_GL_GLXMAKECONTEXTCURRENTPROC) (Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef GLXDrawable ( * GDK_GL_GLXGETCURRENTREADDRAWABLEPROC) (void);
typedef Display * ( * GDK_GL_GLXGETCURRENTDISPLAYPROC) (void);
typedef int ( * GDK_GL_GLXQUERYCONTEXTPROC) (Display *dpy, GLXContext ctx, int attribute, int *value);
typedef void ( * GDK_GL_GLXSELECTEVENTPROC) (Display *dpy, GLXDrawable draw, unsigned long event_mask);
typedef void ( * GDK_GL_GLXGETSELECTEDEVENTPROC) (Display *dpy, GLXDrawable draw, unsigned long *event_mask);

/* 
 * GLX_VERSION_1_4
 */

typedef GdkGLFunc ( * GDK_GL_GLXGETPROCADDRESSPROC) (const GLubyte *procName);

/* 
 * GLX_ARB_get_proc_address
 */

/* glXGetProcAddressARB */
typedef GdkGLFunc ( * GDK_GL_GLXGETPROCADDRESSARBPROC) (const GLubyte *procName);
GdkGLFunc gdk_gl_get_glXGetProcAddressARB (void);
#define gdk_gl_glXGetProcAddressARB(proc, procName) \
  ((GDK_GL_GLXGETPROCADDRESSARBPROC) (proc)) (procName)

/* 
 * GLX_SGI_swap_control
 */

/* glXSwapIntervalSGI */
typedef int ( * GDK_GL_GLXSWAPINTERVALSGIPROC) (int interval);
GdkGLFunc gdk_gl_get_glXSwapIntervalSGI (void);
#define gdk_gl_glXSwapIntervalSGI(proc, interval) \
  ((GDK_GL_GLXSWAPINTERVALSGIPROC) (proc)) (interval)

/* 
 * GLX_SGI_video_sync
 */

/* glXGetVideoSyncSGI */
typedef int ( * GDK_GL_GLXGETVIDEOSYNCSGIPROC) (unsigned int *count);
GdkGLFunc gdk_gl_get_glXGetVideoSyncSGI (void);
#define gdk_gl_glXGetVideoSyncSGI(proc) \
  ((GDK_GL_GLXGETVIDEOSYNCSGIPROC) (proc)) ()

/* glXWaitVideoSyncSGI */
typedef int ( * GDK_GL_GLXWAITVIDEOSYNCSGIPROC) (int divisor, int remainder, unsigned int *count);
GdkGLFunc gdk_gl_get_glXWaitVideoSyncSGI (void);
#define gdk_gl_glXWaitVideoSyncSGI(proc, divisor, remainder, count) \
  ((GDK_GL_GLXWAITVIDEOSYNCSGIPROC) (proc)) (divisor, remainder, count)

/* 
 * GLX_SGI_make_current_read
 */

/* glXMakeCurrentReadSGI */
typedef Bool ( * GDK_GL_GLXMAKECURRENTREADSGIPROC) (Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
GdkGLFunc gdk_gl_get_glXMakeCurrentReadSGI (void);
#define gdk_gl_glXMakeCurrentReadSGI(proc, dpy, draw, read, ctx) \
  ((GDK_GL_GLXMAKECURRENTREADSGIPROC) (proc)) (dpy, draw, read, ctx)

/* glXGetCurrentReadDrawableSGI */
typedef GLXDrawable ( * GDK_GL_GLXGETCURRENTREADDRAWABLESGIPROC) (void);
GdkGLFunc gdk_gl_get_glXGetCurrentReadDrawableSGI (void);
#define gdk_gl_glXGetCurrentReadDrawableSGI(proc) \
  ((GDK_GL_GLXGETCURRENTREADDRAWABLESGIPROC) (proc)) ()

/* 
 * GLX_SGIX_video_source
 */

#ifdef _VL_H

/* glXCreateGLXVideoSourceSGIX */
typedef GLXVideoSourceSGIX ( * GDK_GL_GLXCREATEGLXVIDEOSOURCESGIXPROC) (Display *display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode);
GdkGLFunc gdk_gl_get_glXCreateGLXVideoSourceSGIX (void);
#define gdk_gl_glXCreateGLXVideoSourceSGIX(proc, display, screen, server, path, nodeClass, drainNode) \
  ((GDK_GL_GLXCREATEGLXVIDEOSOURCESGIXPROC) (proc)) (display, screen, server, path, nodeClass, drainNode)

/* glXDestroyGLXVideoSourceSGIX */
typedef void ( * GDK_GL_GLXDESTROYGLXVIDEOSOURCESGIXPROC) (Display *dpy, GLXVideoSourceSGIX glxvideosource);
GdkGLFunc gdk_gl_get_glXDestroyGLXVideoSourceSGIX (void);
#define gdk_gl_glXDestroyGLXVideoSourceSGIX(proc, dpy, glxvideosource) \
  ((GDK_GL_GLXDESTROYGLXVIDEOSOURCESGIXPROC) (proc)) (dpy, glxvideosource)

#endif /* _VL_H */

/* 
 * GLX_EXT_import_context
 */

/* glXGetCurrentDisplayEXT */
typedef Display * ( * GDK_GL_GLXGETCURRENTDISPLAYEXTPROC) (void);
GdkGLFunc gdk_gl_get_glXGetCurrentDisplayEXT (void);
#define gdk_gl_glXGetCurrentDisplayEXT(proc) \
  ((GDK_GL_GLXGETCURRENTDISPLAYEXTPROC) (proc)) ()

/* glXQueryContextInfoEXT */
typedef int ( * GDK_GL_GLXQUERYCONTEXTINFOEXTPROC) (Display *dpy, GLXContext context, int attribute, int *value);
GdkGLFunc gdk_gl_get_glXQueryContextInfoEXT (void);
#define gdk_gl_glXQueryContextInfoEXT(proc, dpy, context, attribute, value) \
  ((GDK_GL_GLXQUERYCONTEXTINFOEXTPROC) (proc)) (dpy, context, attribute, value)

/* glXGetContextIDEXT */
typedef GLXContextID ( * GDK_GL_GLXGETCONTEXTIDEXTPROC) (const GLXContext context);
GdkGLFunc gdk_gl_get_glXGetContextIDEXT (void);
#define gdk_gl_glXGetContextIDEXT(proc, context) \
  ((GDK_GL_GLXGETCONTEXTIDEXTPROC) (proc)) (context)

/* glXImportContextEXT */
typedef GLXContext ( * GDK_GL_GLXIMPORTCONTEXTEXTPROC) (Display *dpy, GLXContextID contextID);
GdkGLFunc gdk_gl_get_glXImportContextEXT (void);
#define gdk_gl_glXImportContextEXT(proc, dpy, contextID) \
  ((GDK_GL_GLXIMPORTCONTEXTEXTPROC) (proc)) (dpy, contextID)

/* glXFreeContextEXT */
typedef void ( * GDK_GL_GLXFREECONTEXTEXTPROC) (Display *dpy, GLXContext context);
GdkGLFunc gdk_gl_get_glXFreeContextEXT (void);
#define gdk_gl_glXFreeContextEXT(proc, dpy, context) \
  ((GDK_GL_GLXFREECONTEXTEXTPROC) (proc)) (dpy, context)

/* 
 * GLX_SGIX_fbconfig
 */

/* glXGetFBConfigAttribSGIX */
typedef int ( * GDK_GL_GLXGETFBCONFIGATTRIBSGIXPROC) (Display *dpy, GLXFBConfigSGIX config, int attribute, int *value);
GdkGLFunc gdk_gl_get_glXGetFBConfigAttribSGIX (void);
#define gdk_gl_glXGetFBConfigAttribSGIX(proc, dpy, config, attribute, value) \
  ((GDK_GL_GLXGETFBCONFIGATTRIBSGIXPROC) (proc)) (dpy, config, attribute, value)

/* glXChooseFBConfigSGIX */
typedef GLXFBConfigSGIX * ( * GDK_GL_GLXCHOOSEFBCONFIGSGIXPROC) (Display *dpy, int screen, int *attrib_list, int *nelements);
GdkGLFunc gdk_gl_get_glXChooseFBConfigSGIX (void);
#define gdk_gl_glXChooseFBConfigSGIX(proc, dpy, screen, attrib_list, nelements) \
  ((GDK_GL_GLXCHOOSEFBCONFIGSGIXPROC) (proc)) (dpy, screen, attrib_list, nelements)

/* glXCreateGLXPixmapWithConfigSGIX */
typedef GLXPixmap ( * GDK_GL_GLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC) (Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap);
GdkGLFunc gdk_gl_get_glXCreateGLXPixmapWithConfigSGIX (void);
#define gdk_gl_glXCreateGLXPixmapWithConfigSGIX(proc, dpy, config, pixmap) \
  ((GDK_GL_GLXCREATEGLXPIXMAPWITHCONFIGSGIXPROC) (proc)) (dpy, config, pixmap)

/* glXCreateContextWithConfigSGIX */
typedef GLXContext ( * GDK_GL_GLXCREATECONTEXTWITHCONFIGSGIXPROC) (Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
GdkGLFunc gdk_gl_get_glXCreateContextWithConfigSGIX (void);
#define gdk_gl_glXCreateContextWithConfigSGIX(proc, dpy, config, render_type, share_list, direct) \
  ((GDK_GL_GLXCREATECONTEXTWITHCONFIGSGIXPROC) (proc)) (dpy, config, render_type, share_list, direct)

/* glXGetVisualFromFBConfigSGIX */
typedef XVisualInfo * ( * GDK_GL_GLXGETVISUALFROMFBCONFIGSGIXPROC) (Display *dpy, GLXFBConfigSGIX config);
GdkGLFunc gdk_gl_get_glXGetVisualFromFBConfigSGIX (void);
#define gdk_gl_glXGetVisualFromFBConfigSGIX(proc, dpy, config) \
  ((GDK_GL_GLXCREATECONTEXTWITHCONFIGSGIXPROC) (proc)) (dpy, config)

/* glXGetFBConfigFromVisualSGIX */
typedef GLXFBConfigSGIX ( * GDK_GL_GLXGETFBCONFIGFROMVISUALSGIXPROC) (Display *dpy, XVisualInfo *vis);
GdkGLFunc gdk_gl_get_glXGetFBConfigFromVisualSGIX (void);
#define gdk_gl_glXGetFBConfigFromVisualSGIX(proc, dpy, vis) \
  ((GDK_GL_GLXGETFBCONFIGFROMVISUALSGIXPROC) (proc)) (dpy, vis)

/* 
 * GLX_SGIX_pbuffer
 */

/* glXCreateGLXPbufferSGIX */
typedef GLXPbufferSGIX ( * GDK_GL_GLXCREATEGLXPBUFFERSGIXPROC) (Display *dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int *attrib_list);
GdkGLFunc gdk_gl_get_glXCreateGLXPbufferSGIX (void);
#define gdk_gl_glXCreateGLXPbufferSGIX(proc, dpy, config, width, height, attrib_list) \
  ((GDK_GL_GLXCREATEGLXPBUFFERSGIXPROC) (proc)) (dpy, config, width, height, attrib_list)

/* glXDestroyGLXPbufferSGIX */
typedef void ( * GDK_GL_GLXDESTROYGLXPBUFFERSGIXPROC) (Display *dpy, GLXPbufferSGIX pbuf);
GdkGLFunc gdk_gl_get_glXDestroyGLXPbufferSGIX (void);
#define gdk_gl_glXDestroyGLXPbufferSGIX(proc, dpy, pbuf) \
  ((GDK_GL_GLXDESTROYGLXPBUFFERSGIXPROC) (proc)) (dpy, pbuf)

/* glXQueryGLXPbufferSGIX */
typedef int ( * GDK_GL_GLXQUERYGLXPBUFFERSGIXPROC) (Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value);
GdkGLFunc gdk_gl_get_glXQueryGLXPbufferSGIX (void);
#define gdk_gl_glXQueryGLXPbufferSGIX(proc, dpy, pbuf, attribute, value) \
  ((GDK_GL_GLXDESTROYGLXPBUFFERSGIXPROC) (proc)) (dpy, pbuf, attribute, value)

/* glXSelectEventSGIX */
typedef void ( * GDK_GL_GLXSELECTEVENTSGIXPROC) (Display *dpy, GLXDrawable drawable, unsigned long mask);
GdkGLFunc gdk_gl_get_glXSelectEventSGIX (void);
#define gdk_gl_glXSelectEventSGIX(proc, dpy, drawable, mask) \
  ((GDK_GL_GLXSELECTEVENTSGIXPROC) (proc)) (dpy, drawable, mask)

/* glXGetSelectedEventSGIX */
typedef void ( * GDK_GL_GLXGETSELECTEDEVENTSGIXPROC) (Display *dpy, GLXDrawable drawable, unsigned long *mask);
GdkGLFunc gdk_gl_get_glXGetSelectedEventSGIX (void);
#define gdk_gl_glXGetSelectedEventSGIX(proc, dpy, drawable, mask) \
  ((GDK_GL_GLXGETSELECTEDEVENTSGIXPROC) (proc)) (dpy, drawable, mask)

/* 
 * GLX_SGI_cushion
 */

/* glXCushionSGI */
typedef void ( * GDK_GL_GLXCUSHIONSGIPROC) (Display *dpy, Window window, float cushion);
GdkGLFunc gdk_gl_get_glXCushionSGI (void);
#define gdk_gl_glXCushionSGI(proc, dpy, window, cushion) \
  ((GDK_GL_GLXCUSHIONSGIPROC) (proc)) (dpy, window, cushion)

/* 
 * GLX_SGIX_video_resize
 */

/* glXBindChannelToWindowSGIX */
typedef int ( * GDK_GL_GLXBINDCHANNELTOWINDOWSGIXPROC) (Display *display, int screen, int channel, Window window);
GdkGLFunc gdk_gl_get_glXBindChannelToWindowSGIX (void);
#define gdk_gl_glXBindChannelToWindowSGIX(proc, display, screen, channel, window) \
  ((GDK_GL_GLXBINDCHANNELTOWINDOWSGIXPROC) (proc)) (display, screen, channel, window)

/* glXChannelRectSGIX */
typedef int ( * GDK_GL_GLXCHANNELRECTSGIXPROC) (Display *display, int screen, int channel, int x, int y, int w, int h);
GdkGLFunc gdk_gl_get_glXChannelRectSGIX (void);
#define gdk_gl_glXChannelRectSGIX(proc, display, screen, channel, x, y, w, h) \
  ((GDK_GL_GLXCHANNELRECTSGIXPROC) (proc)) (display, screen, channel, x, y, w, h)

/* glXQueryChannelRectSGIX */
typedef int ( * GDK_GL_GLXQUERYCHANNELRECTSGIXPROC) (Display *display, int screen, int channel, int *dx, int *dy, int *dw, int *dh);
GdkGLFunc gdk_gl_get_glXQueryChannelRectSGIX (void);
#define gdk_gl_glXQueryChannelRectSGIX(proc, display, screen, channel, dx, dy, dw, dh) \
  ((GDK_GL_GLXQUERYCHANNELRECTSGIXPROC) (proc)) (display, screen, channel, dx, dy, dw, dh)

/* glXQueryChannelDeltasSGIX */
typedef int ( * GDK_GL_GLXQUERYCHANNELDELTASSGIXPROC) (Display *display, int screen, int channel, int *x, int *y, int *w, int *h);
GdkGLFunc gdk_gl_get_glXQueryChannelDeltasSGIX (void);
#define gdk_gl_glXQueryChannelDeltasSGIX(proc, display, screen, channel, x, y, w, h) \
  ((GDK_GL_GLXQUERYCHANNELDELTASSGIXPROC) (proc)) (display, screen, channel, x, y, w, h)

/* glXChannelRectSyncSGIX */
typedef int ( * GDK_GL_GLXCHANNELRECTSYNCSGIXPROC) (Display *display, int screen, int channel, GLenum synctype);
GdkGLFunc gdk_gl_get_glXChannelRectSyncSGIX (void);
#define gdk_gl_glXChannelRectSyncSGIX(proc, display, screen, channel, synctype) \
  ((GDK_GL_GLXCHANNELRECTSYNCSGIXPROC) (proc)) (display, screen, channel, synctype)

/* 
 * GLX_SGIX_dmbuffer
 */

#ifdef _DM_BUFFER_H_

/* glXAssociateDMPbufferSGIX */
typedef Bool ( * GDK_GL_GLXASSOCIATEDMPBUFFERSGIXPROC) (Display *dpy, GLXPbufferSGIX pbuffer, DMparams *params, DMbuffer dmbuffer);
GdkGLFunc gdk_gl_get_glXAssociateDMPbufferSGIX (void);
#define gdk_gl_glXAssociateDMPbufferSGIX(proc, dpy, pbuffer, params, dmbuffer) \
  ((GDK_GL_GLXASSOCIATEDMPBUFFERSGIXPROC) (proc)) (dpy, pbuffer, params, dmbuffer)

#endif /* _DM_BUFFER_H_ */

/* 
 * GLX_SGIX_swap_group
 */

/* glXJoinSwapGroupSGIX */
typedef void ( * GDK_GL_GLXJOINSWAPGROUPSGIXPROC) (Display *dpy, GLXDrawable drawable, GLXDrawable member);
GdkGLFunc gdk_gl_get_glXJoinSwapGroupSGIX (void);
#define gdk_gl_glXJoinSwapGroupSGIX(proc, dpy, drawable, member) \
  ((GDK_GL_GLXJOINSWAPGROUPSGIXPROC) (proc)) (dpy, drawable, member)

/* 
 * GLX_SGIX_swap_barrier
 */

/* glXBindSwapBarrierSGIX */
typedef void ( * GDK_GL_GLXBINDSWAPBARRIERSGIXPROC) (Display *dpy, GLXDrawable drawable, int barrier);
GdkGLFunc gdk_gl_get_glXBindSwapBarrierSGIX (void);
#define gdk_gl_glXBindSwapBarrierSGIX(proc, dpy, drawable, barrier) \
  ((GDK_GL_GLXBINDSWAPBARRIERSGIXPROC) (proc)) (dpy, drawable, barrier)

/* glXQueryMaxSwapBarriersSGIX */
typedef Bool ( * GDK_GL_GLXQUERYMAXSWAPBARRIERSSGIXPROC) (Display *dpy, int screen, int *max);
GdkGLFunc gdk_gl_get_glXQueryMaxSwapBarriersSGIX (void);
#define gdk_gl_glXQueryMaxSwapBarriersSGIX(proc, dpy, screen, max) \
  ((GDK_GL_GLXQUERYMAXSWAPBARRIERSSGIXPROC) (proc)) (dpy, screen, max)

/* 
 * GLX_SUN_get_transparent_index
 */

/* glXGetTransparentIndexSUN */
typedef Status ( * GDK_GL_GLXGETTRANSPARENTINDEXSUNPROC) (Display *dpy, Window overlay, Window underlay, long *pTransparentIndex);
GdkGLFunc gdk_gl_get_glXGetTransparentIndexSUN (void);
#define gdk_gl_glXGetTransparentIndexSUN(proc, dpy, overlay, underlay, pTransparentIndex) \
  ((GDK_GL_GLXGETTRANSPARENTINDEXSUNPROC) (proc)) (dpy, overlay, underlay, pTransparentIndex)

/*
 * GLX_MESA_copy_sub_buffer
 */

/* glXCopySubBufferMESA */
typedef void ( * GDK_GL_GLXCOPYSUBBUFFERMESAPROC) (Display *dpy, GLXDrawable drawable, int x, int y, int width, int height);
GdkGLFunc gdk_gl_get_glXCopySubBufferMESA (void);
#define gdk_gl_glXCopySubBufferMESA(proc, dpy, drawable, x, y, width, height) \
  ((GDK_GL_GLXCOPYSUBBUFFERMESAPROC) (proc)) (dpy, drawable, x, y, width, height)

/*
 * GLX_MESA_pixmap_colormap
 */

/* glXCreateGLXPixmapMESA */
typedef GLXPixmap ( * GDK_GL_GLXCREATEGLXPIXMAPMESAPROC) (Display *dpy, XVisualInfo *visual, Pixmap pixmap, Colormap cmap);
GdkGLFunc gdk_gl_get_glXCreateGLXPixmapMESA (void);
#define gdk_gl_glXCreateGLXPixmapMESA(proc, dpy, visual, pixmap, cmap) \
  ((GDK_GL_GLXCREATEGLXPIXMAPMESAPROC) (proc)) (dpy, visual, pixmap, cmap)

/*
 * GLX_MESA_release_buffers
 */

/* glXReleaseBuffersMESA */
typedef Bool ( * GDK_GL_GLXRELEASEBUFFERSMESAPROC) (Display *dpy, GLXDrawable drawable);
GdkGLFunc gdk_gl_get_glXReleaseBuffersMESA (void);
#define gdk_gl_glXReleaseBuffersMESA(proc, dpy, drawable) \
  ((GDK_GL_GLXRELEASEBUFFERSMESAPROC) (proc)) (dpy, drawable)

/*
 * GLX_MESA_set_3dfx_mode
 */

/* glXSet3DfxModeMESA */
typedef Bool ( * GDK_GL_GLXSET3DFXMODEMESAPROC) (int mode);
GdkGLFunc gdk_gl_get_glXSet3DfxModeMESA (void);
#define gdk_gl_glXSet3DfxModeMESA(proc, mode) \
  ((GDK_GL_GLXSET3DFXMODEMESAPROC) (proc)) (mode)

/* 
 * GLX_OML_sync_control
 */

/* glXGetSyncValuesOML */
typedef Bool ( * GDK_GL_GLXGETSYNCVALUESOMLPROC) (Display *dpy, GLXDrawable drawable, int64_t *ust, int64_t *msc, int64_t *sbc);
GdkGLFunc gdk_gl_get_glXGetSyncValuesOML (void);
#define gdk_gl_glXGetSyncValuesOML(proc, dpy, drawable, ust, msc, sbc) \
  ((GDK_GL_GLXGETSYNCVALUESOMLPROC) (proc)) (dpy, drawable, ust, msc, sbc)

/* glXGetMscRateOML */
typedef Bool ( * GDK_GL_GLXGETMSCRATEOMLPROC) (Display *dpy, GLXDrawable drawable, int32_t *numerator, int32_t *denominator);
GdkGLFunc gdk_gl_get_glXGetMscRateOML (void);
#define gdk_gl_glXGetMscRateOML(proc, dpy, drawable, numerator, denominator) \
  ((GDK_GL_GLXGETMSCRATEOMLPROC) (proc)) (dpy, drawable, numerator, denominator)

/* glXSwapBuffersMscOML */
typedef int64_t ( * GDK_GL_GLXSWAPBUFFERSMSCOMLPROC) (Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
GdkGLFunc gdk_gl_get_glXSwapBuffersMscOML (void);
#define gdk_gl_glXSwapBuffersMscOML(proc, dpy, drawable, target_msc, divisor, remainder) \
  ((GDK_GL_GLXSWAPBUFFERSMSCOMLPROC) (proc)) (dpy, drawable, target_msc, divisor, remainder)

/* glXWaitForMscOML */
typedef Bool ( * GDK_GL_GLXWAITFORMSCOMLPROC) (Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t *ust, int64_t *msc, int64_t *sbc);
GdkGLFunc gdk_gl_get_glXWaitForMscOML (void);
#define gdk_gl_glXWaitForMscOML(proc, dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc) \
  ((GDK_GL_GLXWAITFORMSCOMLPROC) (proc)) (dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc)

/* glXWaitForSbcOML */
typedef Bool ( * GDK_GL_GLXWAITFORSBCOMLPROC) (Display *dpy, GLXDrawable drawable, int64_t target_sbc, int64_t *ust, int64_t *msc, int64_t *sbc);
GdkGLFunc gdk_gl_get_glXWaitForSbcOML (void);
#define gdk_gl_glXWaitForSbcOML(proc, dpy, drawable, target_sbc, ust, msc, sbc) \
  ((GDK_GL_GLXWAITFORSBCOMLPROC) (proc)) (dpy, drawable, target_sbc, ust, msc, sbc)


G_END_DECLS

#endif /* __GDK_GL_GLX_EXT_H__ */
