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

#include <pango/pangowin32.h>

#include "gdkglwin32.h"
#include "gdkglfont.h"

PangoFont *
gdk_gl_font_use_pango_font (const PangoFontDescription *font_desc,
                            gint                        first,
                            gint                        count,
                            gint                        list_base)
{
  HDC hdc;
  PangoFontMap *font_map;
  PangoWin32FontCache *font_cache;
  PangoFont *font = NULL;
  LOGFONT *logfont;
  HFONT hfont;

  g_return_if_fail (font != NULL);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_font_use_pango_font ()"));

  font_map = pango_win32_font_map_for_display ();
  font_cache = pango_win32_font_map_get_font_cache (font_map);

  font = pango_font_map_load_font (font_map, NULL, font_desc);
  if (font == NULL)
    {
      g_warning ("cannot load PangoFont");
      goto FAIL;
    }

  logfont = pango_win32_font_logfont (font);
  if (logfont == NULL)
    {
      g_warning ("cannot get LOGFONT struct");
      font = NULL;
      goto FAIL;
    }

  hfont = pango_win32_font_cache_load (font_cache, logfont);

  hdc = CreateCompatibleDC (NULL);
  if (hdc == NULL)
    {
      g_warning ("cannot create a memory DC");
      font = NULL;
      goto FAIL;
    }

  SelectObject (hdc, (HGDIOBJ) gdk_font_id (font));

  if (!wglUseFontBitmaps (hdc, first, count, list_base))
    {
      g_warning ("cannot create the font display lists");
      font = NULL;
      goto FAIL;
    }

  if (!DeleteDC (hdc))
    g_warning ("cannot delete the memory DC");

  pango_win32_font_cache_unload (font_cache, hfont);

 FAIL:

  if (logfont != NULL)
    g_free (logfont);

  return font;
}

void
gdk_gl_font_use_gdk_font (GdkFont *font,
                          gint     first,
                          gint     count,
                          gint     list_base)
{
  HDC hdc;

  g_return_if_fail (font != NULL);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_font_use_gdk_font ()"));

  hdc = CreateCompatibleDC (NULL);
  if (hdc == NULL)
    {
      g_warning ("cannot create a memory DC");
      return;
    }

  SelectObject (hdc, (HGDIOBJ) gdk_font_id (font));

  if (!wglUseFontBitmaps (hdc, first, count, list_base))
    g_warning ("cannot create the font display lists");

  if (!DeleteDC (hdc))
    g_warning ("cannot delete the memory DC");
}
