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
#include "gdkglx.h"

/**
 * gdk_gl_query_extension:
 *
 * Indicate whether the OpenGL extension is supported.
 *
 * Return value: TRUE if the OpenGL extension is supported, FALSE otherwise.
 **/
gboolean
gdk_gl_query_extension (void)
{
  return glXQueryExtension (gdk_x11_get_default_xdisplay (),
                            NULL, NULL);
}

/**
 * gdk_gl_query_version:
 * @major: returns the major version number of the OpenGL extension.
 * @minor: returns the minor version number of the OpenGL extension.
 *
 * Return the version numbers of the OpenGL extension.
 *
 * Return value: FALSE if it fails, TRUE otherwise.
 **/
gboolean
gdk_gl_query_version (gint *major,
                      gint *minor)
{
  return glXQueryVersion (gdk_x11_get_default_xdisplay (),
                          major, minor);
}
