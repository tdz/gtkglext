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

#include <gmodule.h>

#ifdef GDK_MULTIHEAD_SAFE
#include <gdk/gdkdisplay.h>
#endif /* GDK_MULTIHEAD_SAFE */

#include "gdkglwin32.h"
#include "gdkglprivate-win32.h"
#include "gdkglquery.h"

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

#ifdef GDK_MULTIHEAD_SAFE

gboolean
gdk_gl_query_extension_for_display (GdkDisplay *display)
{
  g_return_val_if_fail (display == gdk_display_get_default (), FALSE);

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

#endif /* GDK_MULTIHEAD_SAFE */

gboolean
gdk_gl_query_version (int *major,
                      int *minor)
{
  DWORD version = GetVersion ();

  /* return Windows version. */
  *major = (int) (LOBYTE (LOWORD (version)));
  *minor = (int) (HIBYTE (LOWORD (version)));

  return TRUE;
}

#ifdef GDK_MULTIHEAD_SAFE

gboolean
gdk_gl_query_version_for_display (GdkDisplay *display,
                                  int        *major,
                                  int        *minor)
{
  DWORD version;

  g_return_val_if_fail (display == gdk_display_get_default (), FALSE);

  version = GetVersion ();

  /* return Windows version. */
  *major = (int) (LOBYTE (LOWORD (version)));
  *minor = (int) (HIBYTE (LOWORD (version)));

  return TRUE;
}

#endif /* GDK_MULTIHEAD_SAFE */

GdkGLProc
gdk_gl_query_get_proc_address (const char *proc_name)
{
  static GModule *main_module = NULL;
  GdkGLProc proc_address;

  GDK_GL_NOTE (IMPL, g_message (" * gdk_gl_query_get_proc_address ()"));

  /* Try wglGetProcAddress () */

  proc_address = (GdkGLProc) wglGetProcAddress (proc_name);

  if (proc_address != NULL)
    return proc_address;

  GDK_GL_NOTE (IMPL, g_message (" * wglGetProcAddress () - failed"));

  /* Try g_module_symbol () */

  if (!main_module)
    {
      GDK_GL_NOTE (IMPL, g_message (" * get main_module"));

      main_module = g_module_open (NULL, G_MODULE_BIND_LAZY);
    }

  if (main_module)
    g_module_symbol (main_module, proc_name, (gpointer) &proc_address);

  return proc_address;
}
