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

#ifndef __GDK_GL_SHAPES_H__
#define __GDK_GL_SHAPES_H__

#include <gdk/gdktypes.h>

#include <gdk/gdkgldefs.h>
#include <gdk/gdkgldebug.h>

#ifdef G_OS_WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

G_BEGIN_DECLS

void gdk_gl_solid_cube         (GLdouble size);
void gdk_gl_wire_cube          (GLdouble size);

void gdk_gl_solid_sphere       (GLdouble radius,
                                GLint    slices,
                                GLint    stacks);
void gdk_gl_wire_sphere        (GLdouble radius,
                                GLint    slices,
                                GLint    stacks);

void gdk_gl_solid_cone         (GLdouble base,
                                GLdouble height,
                                GLint    slices,
                                GLint    stacks);
void gdk_gl_wire_cone          (GLdouble base,
                                GLdouble height,
                                GLint    slices,
                                GLint    stacks);

void gdk_gl_solid_torus        (GLdouble inner_radius,
                                GLdouble outer_radius,
                                GLint    nsides,
                                GLint    rings);
void gdk_gl_wire_torus         (GLdouble inner_radius,
                                GLdouble outer_radius,
                                GLint    nsides,
                                GLint    rings);

void gdk_gl_solid_tetrahedron  (void);
void gdk_gl_wire_tetrahedron   (void);

void gdk_gl_solid_octahedron   (void);
void gdk_gl_wire_octahedron    (void);

void gdk_gl_solid_dodecahedron (void);
void gdk_gl_wire_dodecahedron  (void);

void gdk_gl_solid_icosahedron  (void);
void gdk_gl_wire_icosahedron   (void);

void gdk_gl_solid_teapot       (GLdouble scale);
void gdk_gl_wire_teapot        (GLdouble scale);

G_END_DECLS

#endif /* __GDK_GL_SHAPES_H__ */
