/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002-2004  Naofumi Yasufuku
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

#include <mach-o/dyld.h>

#include "gdkglquartz.h"
#include "gdkglprivate-quartz.h"
#include "gdkglconfig-quartz.h"
#include "gdkglquery.h"

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
#include <gdk/gdkdisplay.h>
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

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
  return TRUE;
}


/**
 * gdk_gl_query_extension_for_display:
 * @display: the #GdkDisplay where the query is sent to.
 *
 * Indicates whether the window system supports the OpenGL extension
 * (GLX, WGL, etc.).
 *
 * Return value: TRUE if OpenGL is supported, FALSE otherwise.
 **/
gboolean
gdk_gl_query_extension_for_display (GdkDisplay *display)
{
  return TRUE;
}


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
  *major = 1;
  *minor = 0;
  return TRUE;
}


/**
 * gdk_gl_query_version_for_display:
 * @display: the #GdkDisplay where the query is sent to.
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
gdk_gl_query_version_for_display (GdkDisplay *display,
                                  int        *major,
                                  int        *minor)
{
  *major = 1;
  *minor = 0;
  return TRUE;
}




/**
 * gdk_gl_get_proc_address:
 * @proc_name: function name.
 *
 * Returns the address of the OpenGL, GLU, or GLX function.
 *
 * Return value: the address of the function named by @proc_name.
 **/



#define _GDK_GL_LIBGL_PATH  "/System/Library/Frameworks/OpenGL.framework/Libraries/libGL.dylib"
#define _GDK_GL_LIBGLU_PATH "/System/Library/Frameworks/OpenGL.framework/Libraries/libGLU.dylib"

GdkGLProc
gdk_gl_get_proc_address (const char *proc_name)
{
  const char *image_name;
  static const struct mach_header *libgl_image = NULL;
  static const struct mach_header *libglu_image = NULL;
  NSSymbol symbol;
  char *symbol_name;


  GDK_GL_NOTE_FUNC ();

  if (strncmp ("glu", proc_name, 3) != 0)
    {
      /* libGL */

      if (libgl_image == NULL)
        {
          image_name = g_getenv ("GDK_GL_LIBGL_PATH");
          if (image_name == NULL)
            image_name = _GDK_GL_LIBGL_PATH;

          GDK_GL_NOTE (MISC, g_message (" - Add Mach-O image %s", image_name));

          libgl_image = NSAddImage (image_name, NSADDIMAGE_OPTION_RETURN_ON_ERROR);
          if (libgl_image == NULL)
            {
              g_warning ("Cannot add Mach-O image %s", image_name);
              return NULL;
            }
        }




      /* Try Mach-O dyld */

      symbol_name = g_strconcat ("_", proc_name, NULL);

      symbol = NSLookupSymbolInImage (libgl_image,
                                      symbol_name,
                                      NSLOOKUPSYMBOLINIMAGE_OPTION_BIND |
                                      NSLOOKUPSYMBOLINIMAGE_OPTION_RETURN_ON_ERROR);
      GDK_GL_NOTE (MISC, g_message (" - NSLookupSymbolInImage () - %s",
                                    symbol ? "succeeded" : "failed"));

      g_free (symbol_name);

      if (symbol != NULL)
        return NSAddressOfSymbol (symbol);
    }
  else
    {
      /* libGLU */

      if (libglu_image == NULL)
        {
          image_name = g_getenv ("GDK_GL_LIBGLU_PATH");
          if (image_name == NULL)
            image_name = _GDK_GL_LIBGLU_PATH;

          GDK_GL_NOTE (MISC, g_message (" - Add Mach-O image %s", image_name));

          libglu_image = NSAddImage (image_name, NSADDIMAGE_OPTION_RETURN_ON_ERROR);
          if (libglu_image == NULL)
            {
              g_warning ("Cannot add Mach-O image %s", image_name);
              return NULL;
            }
        }

      symbol_name = g_strconcat ("_", proc_name, NULL);

      symbol = NSLookupSymbolInImage (libglu_image,
                                      symbol_name,
                                      NSLOOKUPSYMBOLINIMAGE_OPTION_BIND |
                                      NSLOOKUPSYMBOLINIMAGE_OPTION_RETURN_ON_ERROR);
      GDK_GL_NOTE (MISC, g_message (" - NSLookupSymbolInImage () - %s",
                                    symbol ? "succeeded" : "failed"));

      g_free (symbol_name);

      if (symbol != NULL)
        return NSAddressOfSymbol (symbol);
    }

  return NULL;
}
