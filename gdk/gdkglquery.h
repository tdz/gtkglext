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

#ifndef __GDK_GL_QUERY_H__
#define __GDK_GL_QUERY_H__

#include <gdk/gdktypes.h>

G_BEGIN_DECLS

typedef void (*GdkGLFunc)(void);

gboolean gdk_gl_query_extension             (void);

#ifdef GDK_MULTIHEAD_SAFE
gboolean gdk_gl_query_extension_for_display (GdkDisplay *display);
#endif /* GDK_MULTIHEAD_SAFE */

gboolean gdk_gl_query_version               (int        *major,
                                             int        *minor);

#ifdef GDK_MULTIHEAD_SAFE
gboolean gdk_gl_query_version_for_display   (GdkDisplay *display,
                                             int        *major,
                                             int        *minor);
#endif /* GDK_MULTIHEAD_SAFE */

gboolean gdk_gl_query_gl_extension          (const char *extension);

GdkGLFunc gdk_gl_query_get_proc_address (const char *proc_name);

G_END_DECLS

#endif /* __GDK_GL_QUERY_H__ */
