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

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglcontext-x11.h"

void
_gdk_x11_gl_drawable_swap_buffers (GdkGLDrawable *gldrawable)
{
  GdkDrawable *drawable;

  g_return_if_fail (GDK_IS_GL_DRAWABLE (gldrawable));

  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  drawable = GDK_GL_DRAWABLE_GET_CLASS (gldrawable)->real_drawable (gldrawable);

  GDK_GL_NOTE (IMPL, g_message (" * glXSwapBuffers ()"));

  glXSwapBuffers (GDK_DRAWABLE_XDISPLAY (drawable),
                  GDK_DRAWABLE_XID (drawable));
}

void
_gdk_x11_gl_drawable_wait_gl (GdkGLDrawable *gldrawable)
{
  glXWaitGL ();
}

void
_gdk_x11_gl_drawable_wait_gdk (GdkGLDrawable *gldrawable)
{
  glXWaitX ();
}
