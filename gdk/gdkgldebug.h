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

#ifndef __GDK_GL_DEBUG_H__
#define __GDK_GL_DEBUG_H__

#include <glib.h>

G_BEGIN_DECLS

typedef enum {
  GDK_GL_DEBUG_MISC        = 1 << 0,
  GDK_GL_DEBUG_FUNC        = 1 << 1,
  GDK_GL_DEBUG_IMPL        = 1 << 2
} GdkGLDebugFlag;

#ifdef G_ENABLE_DEBUG

#define GDK_GL_NOTE(type, action)                G_STMT_START { \
    if (gdk_gl_debug_flags & GDK_GL_DEBUG_##type)               \
       { action; };                              } G_STMT_END

#else /* !G_ENABLE_DEBUG */

#define GDK_GL_NOTE(type, action)
      
#endif /* G_ENABLE_DEBUG */

#ifdef G_OS_WIN32
#  ifdef GDK_GL_COMPILATION
#    define GDKGLVAR __declspec(dllexport)
#  else
#    define GDKGLVAR extern __declspec(dllimport)
#  endif
#else
#  define GDKGLVAR extern
#endif

GDKGLVAR guint gdk_gl_debug_flags;

G_END_DECLS

#endif /* __GDK_GL_DEBUG_H__ */
