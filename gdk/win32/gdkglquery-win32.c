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
  static GModule *opengl32_module = NULL;
  static GModule *glu32_module = NULL;
  GdkGLProc proc_address = wglGetProcAddress (proc_name);

  if (proc_address != NULL)
    return proc_address;

  /*
   * When no current rendering context exists, wglGetProcAddress returns NULL.
   */

  GDK_GL_NOTE (IMPL, g_message (" * wglGetProcAddress () - failed"));

  /* Try to get the symbol from opengl32.dll */

  if (opengl32_module == NULL)
    {
      GDK_GL_NOTE (IMPL, g_message (" * open opengl32.dll"));

      opengl32_module = g_module_open ("opengl32.dll", G_MODULE_BIND_LAZY);

      if (opengl32_module != NULL)
        g_module_make_resident (opengl32_module);
    }

  if (opengl32_module != NULL)
    {
      g_module_symbol (opengl32_module, proc_name, (gpointer) &proc_address);
      if (proc_address != NULL)
        return proc_address;
    }

  /* Try to get the symbol from glu32.dll */

  if (glu32_module == NULL)
    {
      GDK_GL_NOTE (IMPL, g_message (" * open glu32.dll"));

      glu32_module = g_module_open ("glu32.dll", G_MODULE_BIND_LAZY);

      if (glu32_module != NULL)
        g_module_make_resident (glu32_module);
    }

  if (glu32_module != NULL)
    {
      g_module_symbol (glu32_module, proc_name, (gpointer) &proc_address);
    }

  return proc_address;
}
