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

#include "gdkglprivate-win32.h"
#include "gdkglwin32.h"

gboolean
gdk_gl_query_extension (void)
{
  return TRUE;

#if 0
  DWORD version = GetVersion ();
  DWORD major = (DWORD) (LOBYTE (LOWORD (version)));

  if (version < 0x80000000)     /* Windows NT/2000/XP */
    {
      if (major >= 3)
        return TRUE;
    }
  else                          /* Windows 95/98/Me */
    {
      if (major >= 4)
        return TRUE;
    }

  return FALSE;
#endif
}

gboolean
gdk_gl_query_version (gint *major,
                      gint *minor)
{
  DWORD version = GetVersion ();

  /* return Windows version. */
  *major = (gint) (LOBYTE (LOWORD (version)));
  *minor = (gint) (HIBYTE (LOWORD (version)));

  return TRUE;
}

void
gdk_gl_wait_gl (void)
{
  glFinish ();
}

void
gdk_gl_wait_gdk (void)
{
  GdiFlush ();
}
