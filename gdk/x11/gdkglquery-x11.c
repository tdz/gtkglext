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

#include <string.h>

#include <gmodule.h>

#ifdef GDK_MULTIHEAD_SAFE
#include <gdk/gdkdisplay.h>
#endif /* GDK_MULTIHEAD_SAFE */

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglconfig-x11.h"
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
 * gdk_x11_gl_query_glx_extension:
 * @glconfig: a #GdkGLConfig.
 * @extension: name of GLX extension.
 *
 * Determines whether a given GLX extension is supported.
 *
 * Return value: TRUE if the GLX extension is supported, FALSE if not supported.
 **/
gboolean
gdk_x11_gl_query_glx_extension (GdkGLConfig *glconfig,
                                const char  *extension)
{
  static const char *extensions = NULL;
  const char *start;
  char *where, *terminator;
  int major, minor;

  /* Extension names should not have spaces. */
  where = strchr (extension, ' ');
  if (where || *extension == '\0')
    return FALSE;

  if (!extensions)
    {
      /* Be careful not to call glXQueryExtensionsString if it
         looks like the server doesn't support GLX 1.1.
         Unfortunately, the original GLX 1.0 didn't have the notion
         of GLX extensions. */

      glXQueryVersion (GDK_GL_CONFIG_XDISPLAY (glconfig),
                       &major, &minor);

      if ((major == 1 && minor < 1) || (major < 1))
        return FALSE;

      extensions = glXQueryExtensionsString (GDK_GL_CONFIG_XDISPLAY (glconfig),
                                             GDK_GL_CONFIG_SCREEN_XNUMBER (glconfig));
    }

  /* It takes a bit of care to be fool-proof about parsing
     the GLX extensions string.  Don't be fooled by
     sub-strings,  etc. */
  start = extensions;
  for (;;)
    {
      where = strstr (start, extension);
      if (!where)
        break;

      terminator = where + strlen(extension);

      if (where == start || *(where - 1) == ' ')
        if (*terminator == ' ' || *terminator == '\0')
          return TRUE;

      start = terminator;
    }

  return FALSE;
}

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
  typedef GdkGLProc (*__glXGetProcAddressProc) (const GLubyte *);
  static __glXGetProcAddressProc glx_get_proc_address = NULL;
  static gboolean init_glx_get_proc_address = FALSE;
  static GModule *main_module = NULL;
  GdkGLProc proc_address = NULL;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_query_get_proc_address ()"));

  if (!init_glx_get_proc_address)
    {
      /*
       * Look up glXGetProcAddress () function.
       */

      GDK_GL_NOTE (MISC, g_message (" - get main_module"));

      main_module = g_module_open (NULL, G_MODULE_BIND_LAZY);
      g_return_val_if_fail (main_module != NULL, NULL);

      g_module_symbol (main_module, "glXGetProcAddress",
                       (gpointer) &glx_get_proc_address);
      if (!glx_get_proc_address)
        g_module_symbol (main_module, "glXGetProcAddressARB",
                         (gpointer) &glx_get_proc_address);
      if (!glx_get_proc_address)
        g_module_symbol (main_module, "glXGetProcAddressEXT",
                         (gpointer) &glx_get_proc_address);

      /* main_module is resident */
      /* g_module_close (main_module); */

      GDK_GL_NOTE (MISC, g_message (" - glXGetProcAddress () - %s",
                                    glx_get_proc_address ? "supported" : "not supported"));

      init_glx_get_proc_address = TRUE;
    }

  /* Try glXGetProcAddress () */

  if (glx_get_proc_address)
    {
      proc_address = glx_get_proc_address (proc_name);

      GDK_GL_NOTE (IMPL, g_message (" * glXGetProcAddress () - %s",
                                    proc_address ? "succeeded" : "failed"));
    }

  /* Try g_module_symbol () */

  if (!proc_address)
    {
      g_module_symbol (main_module, proc_name, (gpointer) &proc_address);

      GDK_GL_NOTE (MISC, g_message (" - g_module_symbol () - %s",
                                    proc_address ? "succeeded" : "failed"));
    }

  return proc_address;
}
