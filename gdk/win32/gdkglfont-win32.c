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

#include "gdkglwin32.h"
#include "gdkglfont.h"

void
gdk_gl_font_use_gdk_font (GdkFont *font,
                          gint     first,
                          gint     count,
                          gint     list_base)
{
  HDC hdc;
  HANDLE old_handle;

  g_return_if_fail (font != NULL);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_font_use_gdk_font ()"));

  hdc = CreateCompatibleDC (NULL);
  old_handle = SelectObject (hdc, (HGDIOBJ) gdk_font_id (font));

  wglUseFontBitmaps (hdc, first, count, list_base);

  SelectObject (hdc, old_handle);
  DeleteDC (hdc);
}
