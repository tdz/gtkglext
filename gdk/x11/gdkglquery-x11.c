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

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglquery.h"

/**
 * gdk_gl_query_extension:
 *
 * Indicates whether the window system supports the OpenGL extension
 * (GLX, WGL, etc.).
 *
 * Return value: TRUE if OpenGL is supported, FALSE otherwise.
 **/
gboolean
gdk_gl_query_extension (void)
{
#ifdef GDK_MULTIHEAD_SAFE
  return glXQueryExtension (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
                            NULL, NULL);
#else  /* GDK_MULTIHEAD_SAFE */
  return glXQueryExtension (gdk_x11_get_default_xdisplay (),
                            NULL, NULL);
#endif /* GDK_MULTIHEAD_SAFE */
}

#ifdef GDK_MULTIHEAD_SAFE

gboolean
gdk_gl_query_extension_for_display (GdkDisplay *display)
{
  g_return_val_if_fail (GDK_IS_DISPLAY (display), FALSE);

  return glXQueryExtension (GDK_DISPLAY_XDISPLAY (display),
                            NULL, NULL);
}

#endif /* GDK_MULTIHEAD_SAFE */

/**
 * gdk_gl_query_version:
 * @major: returns the major version number of the OpenGL extension.
 * @minor: returns the minor version number of the OpenGL extension.
 *
 * Returns the version numbers of the OpenGL extension to the window system.
 *
 * In the X Window System, it returns the GLX version.
 *
 * In the Microsoft Windows, it returns the Windows version.
 *
 * Return value: FALSE if it fails, TRUE otherwise.
 **/
gboolean
gdk_gl_query_version (int *major,
                      int *minor)
{
#ifdef GDK_MULTIHEAD_SAFE
  return glXQueryVersion (GDK_DISPLAY_XDISPLAY (gdk_display_get_default ()),
                          major, minor);
#else  /* GDK_MULTIHEAD_SAFE */
  return glXQueryVersion (gdk_x11_get_default_xdisplay (),
                          major, minor);
#endif /* GDK_MULTIHEAD_SAFE */
}

#ifdef GDK_MULTIHEAD_SAFE

gboolean
gdk_gl_query_version_for_display (GdkDisplay *display,
                                  int        *major,
                                  int        *minor)
{
  g_return_val_if_fail (GDK_IS_DISPLAY (display), FALSE);

  return glXQueryVersion (GDK_DISPLAY_XDISPLAY (display),
                          major, minor);
}

#endif /* GDK_MULTIHEAD_SAFE */

/**
 * gdk_gl_query_get_proc_address:
 * @proc_name: extension function name.
 *
 * Returns the address of the OpenGL extension functions.
 *
 * Return value: the address of the extension function named by @proc_name.
 **/
GdkGLProc
gdk_gl_query_get_proc_address (const char *proc_name)
{
  typedef GdkGLProc (*__GLXGetProcAddressFunc) (const GLubyte *);
  static __GLXGetProcAddressFunc glx_get_proc_address = NULL;
  static gboolean init_glx_get_proc_address = FALSE;
  GModule *module;
  GdkGLProc proc_address;

  if (!init_glx_get_proc_address)
    {
      /*
       * Look up glXGetProcAddress () function.
       */

      module = g_module_open (NULL, G_MODULE_BIND_LAZY);
      g_return_val_if_fail (module != NULL, NULL);

      g_module_symbol (module, "glXGetProcAddressARB",
                       (gpointer) &glx_get_proc_address);
      if (glx_get_proc_address == NULL)
        g_module_symbol (module, "glXGetProcAddressEXT",
                         (gpointer) &glx_get_proc_address);
      if (glx_get_proc_address == NULL)
        g_module_symbol (module, "glXGetProcAddress",
                         (gpointer) &glx_get_proc_address);

      g_module_close (module);

      init_glx_get_proc_address = TRUE;
    }

  if (glx_get_proc_address == NULL)
    {
      /* glXGetProcAddress () is not supported. */

      GDK_GL_NOTE (IMPL, g_message (" * glXGetProcAddress () is not supported."));

      module = g_module_open (NULL, G_MODULE_BIND_LAZY);
      g_return_val_if_fail (module != NULL, NULL);

      g_module_symbol (module, proc_name, (gpointer) &proc_address);

      g_module_close (module);
    }
  else
    {
      /* glXGetProcAddress () is supported. */

      GDK_GL_NOTE (IMPL, g_message (" * glXGetProcAddress () is supported."));

      proc_address = glx_get_proc_address (proc_name);
    }

  return proc_address;
}
