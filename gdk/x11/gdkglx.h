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

#ifndef __GDK_GL_X_H__
#define __GDK_GL_X_H__

#include <gdk/gdkx.h>

#include <gdk/gdkglprivate.h>

#include <GL/glx.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

G_BEGIN_DECLS

Display     *gdk_x11_gl_config_get_xdisplay    (GdkGLConfig *glconfig);
XVisualInfo *gdk_x11_gl_config_get_xvinfo      (GdkGLConfig *glconfig);

Display     *gdk_x11_gl_context_get_xdisplay   (GdkGLContext *glcontext);
GLXContext   gdk_x11_gl_context_get_glxcontext (GdkGLContext *glcontext);

Display     *gdk_x11_gl_pixmap_get_xdisplay    (GdkGLPixmap *glpixmap);
GLXPixmap    gdk_x11_gl_pixmap_get_glxpixmap   (GdkGLPixmap *glpixmap);

Display     *gdk_x11_gl_window_get_xdisplay    (GdkGLWindow *glwindow);
Window       gdk_x11_gl_window_get_glxwindow   (GdkGLWindow *glwindow);

G_END_DECLS

#endif /* __GDK_GL_X_H__ */
