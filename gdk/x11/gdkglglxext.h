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
 * GLX_VERSION_1_3
 */

/* glXGetFBConfigs */
typedef GLXFBConfig * ( * GdkGLProc_GLXGETFBCONFIGS) (Display *dpy, int screen, int *nelements);
GdkGLProc    gdk_gl_get_glXGetFBConfigs (void);
#define      gdk_gl_glXGetFBConfigs(proc, dpy, screen, nelements) \
  ( ((GdkGLProc_GLXGETFBCONFIGS) (proc)) (dpy, screen, nelements) )

/* glXChooseFBConfig */
typedef GLXFBConfig * ( * GdkGLProc_GLXCHOOSEFBCONFIG) (Display *dpy, int screen, const int *attrib_list, int *nelements);
GdkGLProc    gdk_gl_get_glXChooseFBConfig (void);
#define      gdk_gl_glXChooseFBConfig(proc, dpy, screen, attrib_list, nelements) \
  ( ((GdkGLProc_GLXCHOOSEFBCONFIG) (proc)) (dpy, screen, attrib_list, nelements) )

/* glXGetFBConfigAttrib */
typedef int ( * GdkGLProc_GLXGETFBCONFIGATTRIB) (Display *dpy, GLXFBConfig config, int attribute, int *value);
GdkGLProc    gdk_gl_get_glXGetFBConfigAttrib (void);
#define      gdk_gl_glXGetFBConfigAttrib(proc, dpy, config, attribute, value) \
  ( ((GdkGLProc_GLXGETFBCONFIGATTRIB) (proc)) (dpy, config, attribute, value) )

/* glXGetVisualFromFBConfig */
typedef XVisualInfo * ( * GdkGLProc_GLXGETVISUALFROMFBCONFIG) (Display *dpy, GLXFBConfig config);
GdkGLProc    gdk_gl_get_glXGetVisualFromFBConfig (void);
#define      gdk_gl_glXGetVisualFromFBConfig(proc, dpy, config) \
  ( ((GdkGLProc_GLXGETVISUALFROMFBCONFIG) (proc)) (dpy, config) )

/* glXCreateWindow */
typedef GLXWindow ( * GdkGLProc_GLXCREATEWINDOW) (Display *dpy, GLXFBConfig config, Window win, const int *attrib_list);
GdkGLProc    gdk_gl_get_glXCreateWindow (void);
#define      gdk_gl_glXCreateWindow(proc, dpy, config, win, attrib_list) \
  ( ((GdkGLProc_GLXCREATEWINDOW) (proc)) (dpy, config, win, attrib_list) )

/* glXDestroyWindow */
typedef void ( * GdkGLProc_GLXDESTROYWINDOW) (Display *dpy, GLXWindow win);
GdkGLProc    gdk_gl_get_glXDestroyWindow (void);
#define      gdk_gl_glXDestroyWindow(proc, dpy, win) \
  ( ((GdkGLProc_GLXDESTROYWINDOW) (proc)) (dpy, win) )

/* glXCreatePixmap */
typedef GLXPixmap ( * GdkGLProc_GLXCREATEPIXMAP) (Display *dpy, GLXFBConfig config, Pixmap pixmap, const int *attrib_list);
GdkGLProc    gdk_gl_get_glXCreatePixmap (void);
#define      gdk_gl_glXCreatePixmap(proc, dpy, config, pixmap, attrib_list) \
  ( ((GdkGLProc_GLXCREATEPIXMAP) (proc)) (dpy, config, pixmap, attrib_list) )

/* glXDestroyPixmap */
typedef void ( * GdkGLProc_GLXDESTROYPIXMAP) (Display *dpy, GLXPixmap pixmap);
GdkGLProc    gdk_gl_get_glXDestroyPixmap (void);
#define      gdk_gl_glXDestroyPixmap(proc, dpy, pixmap) \
  ( ((GdkGLProc_GLXDESTROYPIXMAP) (proc)) (dpy, pixmap) )

/* glXCreatePbuffer */
typedef GLXPbuffer ( * GdkGLProc_GLXCREATEPBUFFER) (Display *dpy, GLXFBConfig config, const int *attrib_list);
GdkGLProc    gdk_gl_get_glXCreatePbuffer (void);
#define      gdk_gl_glXCreatePbuffer(proc, dpy, config, attrib_list) \
  ( ((GdkGLProc_GLXCREATEPBUFFER) (proc)) (dpy, config, attrib_list) )

/* glXDestroyPbuffer */
typedef void ( * GdkGLProc_GLXDESTROYPBUFFER) (Display *dpy, GLXPbuffer pbuf);
GdkGLProc    gdk_gl_get_glXDestroyPbuffer (void);
#define      gdk_gl_glXDestroyPbuffer(proc, dpy, pbuf) \
  ( ((GdkGLProc_GLXDESTROYPBUFFER) (proc)) (dpy, pbuf) )

/* glXQueryDrawable */
typedef void ( * GdkGLProc_GLXQUERYDRAWABLE) (Display *dpy, GLXDrawable draw, int attribute, unsigned int *value);
GdkGLProc    gdk_gl_get_glXQueryDrawable (void);
#define      gdk_gl_glXQueryDrawable(proc, dpy, draw, attribute, value) \
  ( ((GdkGLProc_GLXQUERYDRAWABLE) (proc)) (dpy, draw, attribute, value) )

/* glXCreateNewContext */
typedef GLXContext ( * GdkGLProc_GLXCREATENEWCONTEXT) (Display *dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
GdkGLProc    gdk_gl_get_glXCreateNewContext (void);
#define      gdk_gl_glXCreateNewContext(proc, dpy, config, render_type, share_list, direct) \
  ( ((GdkGLProc_GLXCREATENEWCONTEXT) (proc)) (dpy, config, render_type, share_list, direct) )

/* glXMakeContextCurrent */
typedef Bool ( * GdkGLProc_GLXMAKECONTEXTCURRENT) (Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
GdkGLProc    gdk_gl_get_glXMakeContextCurrent (void);
#define      gdk_gl_glXMakeContextCurrent(proc, dpy, draw, read, ctx) \
  ( ((GdkGLProc_GLXMAKECONTEXTCURRENT) (proc)) (dpy, draw, read, ctx) )

/* glXGetCurrentReadDrawable */
typedef GLXDrawable ( * GdkGLProc_GLXGETCURRENTREADDRAWABLE) (void);
GdkGLProc    gdk_gl_get_glXGetCurrentReadDrawable (void);
#define      gdk_gl_glXGetCurrentReadDrawable(proc) \
  ( ((GdkGLProc_GLXGETCURRENTREADDRAWABLE) (proc)) () )

/* glXGetCurrentDisplay */
typedef Display * ( * GdkGLProc_GLXGETCURRENTDISPLAY) (void);
GdkGLProc    gdk_gl_get_glXGetCurrentDisplay (void);
#define      gdk_gl_glXGetCurrentDisplay(proc) \
  ( ((GdkGLProc_GLXGETCURRENTDISPLAY) (proc)) () )

/* glXQueryContext */
typedef int ( * GdkGLProc_GLXQUERYCONTEXT) (Display *dpy, GLXContext ctx, int attribute, int *value);
GdkGLProc    gdk_gl_get_glXQueryContext (void);
#define      gdk_gl_glXQueryContext(proc, dpy, ctx, attribute, value) \
  ( ((GdkGLProc_GLXQUERYCONTEXT) (proc)) (dpy, ctx, attribute, value) )

/* glXSelectEvent */
typedef void ( * GdkGLProc_GLXSELECTEVENT) (Display *dpy, GLXDrawable draw, unsigned long event_mask);
GdkGLProc    gdk_gl_get_glXSelectEvent (void);
#define      gdk_gl_glXSelectEvent(proc, dpy, draw, event_mask) \
  ( ((GdkGLProc_GLXSELECTEVENT) (proc)) (dpy, draw, event_mask) )

/* glXGetSelectedEvent */
typedef void ( * GdkGLProc_GLXGETSELECTEDEVENT) (Display *dpy, GLXDrawable draw, unsigned long *event_mask);
GdkGLProc    gdk_gl_get_glXGetSelectedEvent (void);
#define      gdk_gl_glXGetSelectedEvent(proc, dpy, draw, event_mask) \
  ( ((GdkGLProc_GLXGETSELECTEDEVENT) (proc)) (dpy, draw, event_mask) )

/* 
 * GLX_VERSION_1_4
 */

/* glXGetProcAddress */
typedef GdkGLProc ( * GdkGLProc_GLXGETPROCADDRESS) (const GLubyte *procName);
GdkGLProc    gdk_gl_get_glXGetProcAddress (void);
#define      gdk_gl_glXGetProcAddress(proc, procName) \
  ( ((GdkGLProc_GLXGETPROCADDRESS) (proc)) (procName) )

/* 
 * GLX_ARB_get_proc_address
 */

/* glXGetProcAddressARB */
typedef GdkGLProc ( * GdkGLProc_GLXGETPROCADDRESSARB) (const GLubyte *procName);
GdkGLProc    gdk_gl_get_glXGetProcAddressARB (void);
#define      gdk_gl_glXGetProcAddressARB(proc, procName) \
  ( ((GdkGLProc_GLXGETPROCADDRESSARB) (proc)) (procName) )

/* 
 * GLX_SGI_swap_control
 */

/* glXSwapIntervalSGI */
typedef int ( * GdkGLProc_GLXSWAPINTERVALSGI) (int interval);
GdkGLProc    gdk_gl_get_glXSwapIntervalSGI (void);
#define      gdk_gl_glXSwapIntervalSGI(proc, interval) \
  ( ((GdkGLProc_GLXSWAPINTERVALSGI) (proc)) (interval) )

/* 
 * GLX_SGI_video_sync
 */

/* glXGetVideoSyncSGI */
typedef int ( * GdkGLProc_GLXGETVIDEOSYNCSGI) (unsigned int *count);
GdkGLProc    gdk_gl_get_glXGetVideoSyncSGI (void);
#define      gdk_gl_glXGetVideoSyncSGI(proc, count) \
  ( ((GdkGLProc_GLXGETVIDEOSYNCSGI) (proc)) (count) )

/* glXWaitVideoSyncSGI */
typedef int ( * GdkGLProc_GLXWAITVIDEOSYNCSGI) (int divisor, int remainder, unsigned int *count);
GdkGLProc    gdk_gl_get_glXWaitVideoSyncSGI (void);
#define      gdk_gl_glXWaitVideoSyncSGI(proc, divisor, remainder, count) \
  ( ((GdkGLProc_GLXWAITVIDEOSYNCSGI) (proc)) (divisor, remainder, count) )

/* 
 * GLX_SGI_make_current_read
 */

/* glXMakeCurrentReadSGI */
typedef Bool ( * GdkGLProc_GLXMAKECURRENTREADSGI) (Display *dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
GdkGLProc    gdk_gl_get_glXMakeCurrentReadSGI (void);
#define      gdk_gl_glXMakeCurrentReadSGI(proc, dpy, draw, read, ctx) \
  ( ((GdkGLProc_GLXMAKECURRENTREADSGI) (proc)) (dpy, draw, read, ctx) )

/* glXGetCurrentReadDrawableSGI */
typedef GLXDrawable ( * GdkGLProc_GLXGETCURRENTREADDRAWABLESGI) (void);
GdkGLProc    gdk_gl_get_glXGetCurrentReadDrawableSGI (void);
#define      gdk_gl_glXGetCurrentReadDrawableSGI(proc) \
  ( ((GdkGLProc_GLXGETCURRENTREADDRAWABLESGI) (proc)) () )

/* 
 * GLX_SGIX_video_source
 */

#ifdef _VL_H

/* glXCreateGLXVideoSourceSGIX */
typedef GLXVideoSourceSGIX ( * GdkGLProc_GLXCREATEGLXVIDEOSOURCESGIX) (Display *display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode);
GdkGLProc    gdk_gl_get_glXCreateGLXVideoSourceSGIX (void);
#define      gdk_gl_glXCreateGLXVideoSourceSGIX(proc, display, screen, server, path, nodeClass, drainNode) \
  ( ((GdkGLProc_GLXCREATEGLXVIDEOSOURCESGIX) (proc)) (display, screen, server, path, nodeClass, drainNode) )

/* glXDestroyGLXVideoSourceSGIX */
typedef void ( * GdkGLProc_GLXDESTROYGLXVIDEOSOURCESGIX) (Display *dpy, GLXVideoSourceSGIX glxvideosource);
GdkGLProc    gdk_gl_get_glXDestroyGLXVideoSourceSGIX (void);
#define      gdk_gl_glXDestroyGLXVideoSourceSGIX(proc, dpy, glxvideosource) \
  ( ((GdkGLProc_GLXDESTROYGLXVIDEOSOURCESGIX) (proc)) (dpy, glxvideosource) )

#endif /* _VL_H */

/* 
 * GLX_EXT_import_context
 */

/* glXGetCurrentDisplayEXT */
typedef Display * ( * GdkGLProc_GLXGETCURRENTDISPLAYEXT) (void);
GdkGLProc    gdk_gl_get_glXGetCurrentDisplayEXT (void);
#define      gdk_gl_glXGetCurrentDisplayEXT(proc) \
  ( ((GdkGLProc_GLXGETCURRENTDISPLAYEXT) (proc)) () )

/* glXQueryContextInfoEXT */
typedef int ( * GdkGLProc_GLXQUERYCONTEXTINFOEXT) (Display *dpy, GLXContext context, int attribute, int *value);
GdkGLProc    gdk_gl_get_glXQueryContextInfoEXT (void);
#define      gdk_gl_glXQueryContextInfoEXT(proc, dpy, context, attribute, value) \
  ( ((GdkGLProc_GLXQUERYCONTEXTINFOEXT) (proc)) (dpy, context, attribute, value) )

/* glXGetContextIDEXT */
typedef GLXContextID ( * GdkGLProc_GLXGETCONTEXTIDEXT) (const GLXContext context);
GdkGLProc    gdk_gl_get_glXGetContextIDEXT (void);
#define      gdk_gl_glXGetContextIDEXT(proc, context) \
  ( ((GdkGLProc_GLXGETCONTEXTIDEXT) (proc)) (context) )

/* glXImportContextEXT */
typedef GLXContext ( * GdkGLProc_GLXIMPORTCONTEXTEXT) (Display *dpy, GLXContextID contextID);
GdkGLProc    gdk_gl_get_glXImportContextEXT (void);
#define      gdk_gl_glXImportContextEXT(proc, dpy, contextID) \
  ( ((GdkGLProc_GLXIMPORTCONTEXTEXT) (proc)) (dpy, contextID) )

/* glXFreeContextEXT */
typedef void ( * GdkGLProc_GLXFREECONTEXTEXT) (Display *dpy, GLXContext context);
GdkGLProc    gdk_gl_get_glXFreeContextEXT (void);
#define      gdk_gl_glXFreeContextEXT(proc, dpy, context) \
  ( ((GdkGLProc_GLXFREECONTEXTEXT) (proc)) (dpy, context) )

/* 
 * GLX_SGIX_fbconfig
 */

/* glXGetFBConfigAttribSGIX */
typedef int ( * GdkGLProc_GLXGETFBCONFIGATTRIBSGIX) (Display *dpy, GLXFBConfigSGIX config, int attribute, int *value);
GdkGLProc    gdk_gl_get_glXGetFBConfigAttribSGIX (void);
#define      gdk_gl_glXGetFBConfigAttribSGIX(proc, dpy, config, attribute, value) \
  ( ((GdkGLProc_GLXGETFBCONFIGATTRIBSGIX) (proc)) (dpy, config, attribute, value) )

/* glXChooseFBConfigSGIX */
typedef GLXFBConfigSGIX * ( * GdkGLProc_GLXCHOOSEFBCONFIGSGIX) (Display *dpy, int screen, int *attrib_list, int *nelements);
GdkGLProc    gdk_gl_get_glXChooseFBConfigSGIX (void);
#define      gdk_gl_glXChooseFBConfigSGIX(proc, dpy, screen, attrib_list, nelements) \
  ( ((GdkGLProc_GLXCHOOSEFBCONFIGSGIX) (proc)) (dpy, screen, attrib_list, nelements) )

/* glXCreateGLXPixmapWithConfigSGIX */
typedef GLXPixmap ( * GdkGLProc_GLXCREATEGLXPIXMAPWITHCONFIGSGIX) (Display *dpy, GLXFBConfigSGIX config, Pixmap pixmap);
GdkGLProc    gdk_gl_get_glXCreateGLXPixmapWithConfigSGIX (void);
#define      gdk_gl_glXCreateGLXPixmapWithConfigSGIX(proc, dpy, config, pixmap) \
  ( ((GdkGLProc_GLXCREATEGLXPIXMAPWITHCONFIGSGIX) (proc)) (dpy, config, pixmap) )

/* glXCreateContextWithConfigSGIX */
typedef GLXContext ( * GdkGLProc_GLXCREATECONTEXTWITHCONFIGSGIX) (Display *dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
GdkGLProc    gdk_gl_get_glXCreateContextWithConfigSGIX (void);
#define      gdk_gl_glXCreateContextWithConfigSGIX(proc, dpy, config, render_type, share_list, direct) \
  ( ((GdkGLProc_GLXCREATECONTEXTWITHCONFIGSGIX) (proc)) (dpy, config, render_type, share_list, direct) )

/* glXGetVisualFromFBConfigSGIX */
typedef XVisualInfo * ( * GdkGLProc_GLXGETVISUALFROMFBCONFIGSGIX) (Display *dpy, GLXFBConfigSGIX config);
GdkGLProc    gdk_gl_get_glXGetVisualFromFBConfigSGIX (void);
#define      gdk_gl_glXGetVisualFromFBConfigSGIX(proc, dpy, config) \
  ( ((GdkGLProc_GLXGETVISUALFROMFBCONFIGSGIX) (proc)) (dpy, config) )

/* glXGetFBConfigFromVisualSGIX */
typedef GLXFBConfigSGIX ( * GdkGLProc_GLXGETFBCONFIGFROMVISUALSGIX) (Display *dpy, XVisualInfo *vis);
GdkGLProc    gdk_gl_get_glXGetFBConfigFromVisualSGIX (void);
#define      gdk_gl_glXGetFBConfigFromVisualSGIX(proc, dpy, vis) \
  ( ((GdkGLProc_GLXGETFBCONFIGFROMVISUALSGIX) (proc)) (dpy, vis) )

/* 
 * GLX_SGIX_pbuffer
 */

/* glXCreateGLXPbufferSGIX */
typedef GLXPbufferSGIX ( * GdkGLProc_GLXCREATEGLXPBUFFERSGIX) (Display *dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int *attrib_list);
GdkGLProc    gdk_gl_get_glXCreateGLXPbufferSGIX (void);
#define      gdk_gl_glXCreateGLXPbufferSGIX(proc, dpy, config, width, height, attrib_list) \
  ( ((GdkGLProc_GLXCREATEGLXPBUFFERSGIX) (proc)) (dpy, config, width, height, attrib_list) )

/* glXDestroyGLXPbufferSGIX */
typedef void ( * GdkGLProc_GLXDESTROYGLXPBUFFERSGIX) (Display *dpy, GLXPbufferSGIX pbuf);
GdkGLProc    gdk_gl_get_glXDestroyGLXPbufferSGIX (void);
#define      gdk_gl_glXDestroyGLXPbufferSGIX(proc, dpy, pbuf) \
  ( ((GdkGLProc_GLXDESTROYGLXPBUFFERSGIX) (proc)) (dpy, pbuf) )

/* glXQueryGLXPbufferSGIX */
typedef int ( * GdkGLProc_GLXQUERYGLXPBUFFERSGIX) (Display *dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int *value);
GdkGLProc    gdk_gl_get_glXQueryGLXPbufferSGIX (void);
#define      gdk_gl_glXQueryGLXPbufferSGIX(proc, dpy, pbuf, attribute, value) \
  ( ((GdkGLProc_GLXQUERYGLXPBUFFERSGIX) (proc)) (dpy, pbuf, attribute, value) )

/* glXSelectEventSGIX */
typedef void ( * GdkGLProc_GLXSELECTEVENTSGIX) (Display *dpy, GLXDrawable drawable, unsigned long mask);
GdkGLProc    gdk_gl_get_glXSelectEventSGIX (void);
#define      gdk_gl_glXSelectEventSGIX(proc, dpy, drawable, mask) \
  ( ((GdkGLProc_GLXSELECTEVENTSGIX) (proc)) (dpy, drawable, mask) )

/* glXGetSelectedEventSGIX */
typedef void ( * GdkGLProc_GLXGETSELECTEDEVENTSGIX) (Display *dpy, GLXDrawable drawable, unsigned long *mask);
GdkGLProc    gdk_gl_get_glXGetSelectedEventSGIX (void);
#define      gdk_gl_glXGetSelectedEventSGIX(proc, dpy, drawable, mask) \
  ( ((GdkGLProc_GLXGETSELECTEDEVENTSGIX) (proc)) (dpy, drawable, mask) )

/* 
 * GLX_SGI_cushion
 */

/* glXCushionSGI */
typedef void ( * GdkGLProc_GLXCUSHIONSGI) (Display *dpy, Window window, float cushion);
GdkGLProc    gdk_gl_get_glXCushionSGI (void);
#define      gdk_gl_glXCushionSGI(proc, dpy, window, cushion) \
  ( ((GdkGLProc_GLXCUSHIONSGI) (proc)) (dpy, window, cushion) )

/* 
 * GLX_SGIX_video_resize
 */

/* glXBindChannelToWindowSGIX */
typedef int ( * GdkGLProc_GLXBINDCHANNELTOWINDOWSGIX) (Display *display, int screen, int channel, Window window);
GdkGLProc    gdk_gl_get_glXBindChannelToWindowSGIX (void);
#define      gdk_gl_glXBindChannelToWindowSGIX(proc, display, screen, channel, window) \
  ( ((GdkGLProc_GLXBINDCHANNELTOWINDOWSGIX) (proc)) (display, screen, channel, window) )

/* glXChannelRectSGIX */
typedef int ( * GdkGLProc_GLXCHANNELRECTSGIX) (Display *display, int screen, int channel, int x, int y, int w, int h);
GdkGLProc    gdk_gl_get_glXChannelRectSGIX (void);
#define      gdk_gl_glXChannelRectSGIX(proc, display, screen, channel, x, y, w, h) \
  ( ((GdkGLProc_GLXCHANNELRECTSGIX) (proc)) (display, screen, channel, x, y, w, h) )

/* glXQueryChannelRectSGIX */
typedef int ( * GdkGLProc_GLXQUERYCHANNELRECTSGIX) (Display *display, int screen, int channel, int *dx, int *dy, int *dw, int *dh);
GdkGLProc    gdk_gl_get_glXQueryChannelRectSGIX (void);
#define      gdk_gl_glXQueryChannelRectSGIX(proc, display, screen, channel, dx, dy, dw, dh) \
  ( ((GdkGLProc_GLXQUERYCHANNELRECTSGIX) (proc)) (display, screen, channel, dx, dy, dw, dh) )

/* glXQueryChannelDeltasSGIX */
typedef int ( * GdkGLProc_GLXQUERYCHANNELDELTASSGIX) (Display *display, int screen, int channel, int *x, int *y, int *w, int *h);
GdkGLProc    gdk_gl_get_glXQueryChannelDeltasSGIX (void);
#define      gdk_gl_glXQueryChannelDeltasSGIX(proc, display, screen, channel, x, y, w, h) \
  ( ((GdkGLProc_GLXQUERYCHANNELDELTASSGIX) (proc)) (display, screen, channel, x, y, w, h) )

/* glXChannelRectSyncSGIX */
typedef int ( * GdkGLProc_GLXCHANNELRECTSYNCSGIX) (Display *display, int screen, int channel, GLenum synctype);
GdkGLProc    gdk_gl_get_glXChannelRectSyncSGIX (void);
#define      gdk_gl_glXChannelRectSyncSGIX(proc, display, screen, channel, synctype) \
  ( ((GdkGLProc_GLXCHANNELRECTSYNCSGIX) (proc)) (display, screen, channel, synctype) )

/* 
 * GLX_SGIX_dmbuffer
 */

#ifdef _DM_BUFFER_H_

/* glXAssociateDMPbufferSGIX */
typedef Bool ( * GdkGLProc_GLXASSOCIATEDMPBUFFERSGIX) (Display *dpy, GLXPbufferSGIX pbuffer, DMparams *params, DMbuffer dmbuffer);
GdkGLProc    gdk_gl_get_glXAssociateDMPbufferSGIX (void);
#define      gdk_gl_glXAssociateDMPbufferSGIX(proc, dpy, pbuffer, params, dmbuffer) \
  ( ((GdkGLProc_GLXASSOCIATEDMPBUFFERSGIX) (proc)) (dpy, pbuffer, params, dmbuffer) )

#endif /* _DM_BUFFER_H_ */

/* 
 * GLX_SGIX_swap_group
 */

/* glXJoinSwapGroupSGIX */
typedef void ( * GdkGLProc_GLXJOINSWAPGROUPSGIX) (Display *dpy, GLXDrawable drawable, GLXDrawable member);
GdkGLProc    gdk_gl_get_glXJoinSwapGroupSGIX (void);
#define      gdk_gl_glXJoinSwapGroupSGIX(proc, dpy, drawable, member) \
  ( ((GdkGLProc_GLXJOINSWAPGROUPSGIX) (proc)) (dpy, drawable, member) )

/* 
 * GLX_SGIX_swap_barrier
 */

/* glXBindSwapBarrierSGIX */
typedef void ( * GdkGLProc_GLXBINDSWAPBARRIERSGIX) (Display *dpy, GLXDrawable drawable, int barrier);
GdkGLProc    gdk_gl_get_glXBindSwapBarrierSGIX (void);
#define      gdk_gl_glXBindSwapBarrierSGIX(proc, dpy, drawable, barrier) \
  ( ((GdkGLProc_GLXBINDSWAPBARRIERSGIX) (proc)) (dpy, drawable, barrier) )

/* glXQueryMaxSwapBarriersSGIX */
typedef Bool ( * GdkGLProc_GLXQUERYMAXSWAPBARRIERSSGIX) (Display *dpy, int screen, int *max);
GdkGLProc    gdk_gl_get_glXQueryMaxSwapBarriersSGIX (void);
#define      gdk_gl_glXQueryMaxSwapBarriersSGIX(proc, dpy, screen, max) \
  ( ((GdkGLProc_GLXQUERYMAXSWAPBARRIERSSGIX) (proc)) (dpy, screen, max) )

/* 
 * GLX_SUN_get_transparent_index
 */

/* glXGetTransparentIndexSUN */
typedef Status ( * GdkGLProc_GLXGETTRANSPARENTINDEXSUN) (Display *dpy, Window overlay, Window underlay, long *pTransparentIndex);
GdkGLProc    gdk_gl_get_glXGetTransparentIndexSUN (void);
#define      gdk_gl_glXGetTransparentIndexSUN(proc, dpy, overlay, underlay, pTransparentIndex) \
  ( ((GdkGLProc_GLXGETTRANSPARENTINDEXSUN) (proc)) (dpy, overlay, underlay, pTransparentIndex) )

/*
 * GLX_MESA_copy_sub_buffer
 */

/* glXCopySubBufferMESA */
typedef void ( * GdkGLProc_GLXCOPYSUBBUFFERMESA) (Display *dpy, GLXDrawable drawable, int x, int y, int width, int height);
GdkGLProc    gdk_gl_get_glXCopySubBufferMESA (void);
#define      gdk_gl_glXCopySubBufferMESA(proc, dpy, drawable, x, y, width, height) \
  ( ((GdkGLProc_GLXCOPYSUBBUFFERMESA) (proc)) (dpy, drawable, x, y, width, height) )

/*
 * GLX_MESA_pixmap_colormap
 */

/* glXCreateGLXPixmapMESA */
typedef GLXPixmap ( * GdkGLProc_GLXCREATEGLXPIXMAPMESA) (Display *dpy, XVisualInfo *visual, Pixmap pixmap, Colormap cmap);
GdkGLProc    gdk_gl_get_glXCreateGLXPixmapMESA (void);
#define      gdk_gl_glXCreateGLXPixmapMESA(proc, dpy, visual, pixmap, cmap) \
  ( ((GdkGLProc_GLXCREATEGLXPIXMAPMESA) (proc)) (dpy, visual, pixmap, cmap) )

/*
 * GLX_MESA_release_buffers
 */

/* glXReleaseBuffersMESA */
typedef Bool ( * GdkGLProc_GLXRELEASEBUFFERSMESA) (Display *dpy, GLXDrawable drawable);
GdkGLProc    gdk_gl_get_glXReleaseBuffersMESA (void);
#define      gdk_gl_glXReleaseBuffersMESA(proc, dpy, drawable) \
  ( ((GdkGLProc_GLXRELEASEBUFFERSMESA) (proc)) (dpy, drawable) )

/*
 * GLX_MESA_set_3dfx_mode
 */

/* glXSet3DfxModeMESA */
typedef Bool ( * GdkGLProc_GLXSET3DFXMODEMESA) (int mode);
GdkGLProc    gdk_gl_get_glXSet3DfxModeMESA (void);
#define      gdk_gl_glXSet3DfxModeMESA(proc, mode) \
  ( ((GdkGLProc_GLXSET3DFXMODEMESA) (proc)) (mode) )

/* 
 * GLX_OML_sync_control
 */

/* glXGetSyncValuesOML */
typedef Bool ( * GdkGLProc_GLXGETSYNCVALUESOML) (Display *dpy, GLXDrawable drawable, int64_t *ust, int64_t *msc, int64_t *sbc);
GdkGLProc    gdk_gl_get_glXGetSyncValuesOML (void);
#define      gdk_gl_glXGetSyncValuesOML(proc, dpy, drawable, ust, msc, sbc) \
  ( ((GdkGLProc_GLXGETSYNCVALUESOML) (proc)) (dpy, drawable, ust, msc, sbc) )

/* glXGetMscRateOML */
typedef Bool ( * GdkGLProc_GLXGETMSCRATEOML) (Display *dpy, GLXDrawable drawable, int32_t *numerator, int32_t *denominator);
GdkGLProc    gdk_gl_get_glXGetMscRateOML (void);
#define      gdk_gl_glXGetMscRateOML(proc, dpy, drawable, numerator, denominator) \
  ( ((GdkGLProc_GLXGETMSCRATEOML) (proc)) (dpy, drawable, numerator, denominator) )

/* glXSwapBuffersMscOML */
typedef int64_t ( * GdkGLProc_GLXSWAPBUFFERSMSCOML) (Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
GdkGLProc    gdk_gl_get_glXSwapBuffersMscOML (void);
#define      gdk_gl_glXSwapBuffersMscOML(proc, dpy, drawable, target_msc, divisor, remainder) \
  ( ((GdkGLProc_GLXSWAPBUFFERSMSCOML) (proc)) (dpy, drawable, target_msc, divisor, remainder) )

/* glXWaitForMscOML */
typedef Bool ( * GdkGLProc_GLXWAITFORMSCOML) (Display *dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t *ust, int64_t *msc, int64_t *sbc);
GdkGLProc    gdk_gl_get_glXWaitForMscOML (void);
#define      gdk_gl_glXWaitForMscOML(proc, dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc) \
  ( ((GdkGLProc_GLXWAITFORMSCOML) (proc)) (dpy, drawable, target_msc, divisor, remainder, ust, msc, sbc) )

/* glXWaitForSbcOML */
typedef Bool ( * GdkGLProc_GLXWAITFORSBCOML) (Display *dpy, GLXDrawable drawable, int64_t target_sbc, int64_t *ust, int64_t *msc, int64_t *sbc);
GdkGLProc    gdk_gl_get_glXWaitForSbcOML (void);
#define      gdk_gl_glXWaitForSbcOML(proc, dpy, drawable, target_sbc, ust, msc, sbc) \
  ( ((GdkGLProc_GLXWAITFORSBCOML) (proc)) (dpy, drawable, target_sbc, ust, msc, sbc) )

G_END_DECLS

#endif /* __GDK_GL_GLXEXT_H__ */
