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

#include "gdkglcontext.h"
#include "gdkglpixmap.h"
#include "gdkglwindow.h"
#include "gdkglwin32.h"
#include "gdkglprivate-win32.h"

void
_gdk_win32_gl_drawable_swap_buffers (GdkGLDrawable *gldrawable)
{
  HDC hdc;

  g_return_if_fail (GDK_IS_GL_DRAWABLE (gldrawable));

  /*
   * Get DC.
   */
  if (GDK_IS_GL_PIXMAP (gldrawable))
    hdc = gdk_win32_gl_pixmap_get_hdc (GDK_GL_PIXMAP (gldrawable));
  else if (GDK_IS_GL_WINDOW (gldrawable))
    hdc = gdk_win32_gl_window_get_hdc (GDK_GL_WINDOW (gldrawable));
  else
    {
      g_warning (G_STRLOC " GLDrawable is not a GLPixmap or GLWindow");
      return;
    }

  if (hdc == NULL)
    {
      g_warning (G_STRLOC " cannot get DC");
      return;
    }

  GDK_GL_NOTE (IMPL, g_message (" * glXSwapBuffers ()"));

  SwapBuffers (hdc);
}
