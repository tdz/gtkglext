/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002-2003  Naofumi Yasufuku
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
#include "gdkgloverlay-x11.h"

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
#include <gdk/gdkscreen.h>
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

#ifdef __VMS
#include <GL/vms_x_fix.h>
#endif

#include <X11/Xmd.h>

/* SGI optimization introduced in IRIX 6.3 to avoid X server
   round trips for interning common X atoms. */
#include <X11/Xatom.h>
#if defined(_SGI_EXTRA_PREDEFINES) && !defined(_DISABLE_SGI_FAST_ATOMS)
#include <X11/SGIFastAtom.h>
#else
#define XSGIFastInternAtom(dpy, string, fast_name, how) \
  XInternAtom (dpy, string, how)
#endif

/*
 * SERVER_OVERLAY_VISUALS property entry format
 *
 * format: 32
 *
 * <Name>              <Type>      <Description>
 * overlay_visual      VisualID    Visual ID of visual.
 * transparent_type    CARD32      None (0).
 *                                 TransparentPixel (1).
 *                                 TransparentMask (2).
 * value               CARD32      Pixel value or transparency mask.
 * layer               INT32       The layer the visual resides in.
 */

/*
 * SOV property.
 * (format is 32: the returned data is represented as a long array)
 */

typedef struct
{
  long overlay_visual;
  long transparent_type;
  long value;
  long layer;
} __SOVProp;

/* SOV properties data. */

typedef struct
{
  __SOVProp *props;
  unsigned long num_props;
} __SOVPropsPerScreen;

static __SOVPropsPerScreen *sov_props_per_screen = NULL;

static __SOVProp *
gdk_gl_overlay_get_sov_prop (GdkScreen *screen,
                             GdkVisual *visual)
{
  static Atom xa_sov = (Atom) -1;
  static gboolean init = FALSE;
  Display *xdisplay;
  int screen_count, screen_num;
  Window xroot_window;
  Status status;
  Atom actual_type;
  int actual_format;
  unsigned long nitems, bytes_after;
  __SOVProp *props;
  Visual *xvisual;
  int i, num_props;

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  xdisplay = GDK_SCREEN_XDISPLAY (screen);
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
  xdisplay = gdk_x11_get_default_xdisplay ();
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

  if (xa_sov == (Atom) -1)
    xa_sov = XSGIFastInternAtom (xdisplay,
                                 "SERVER_OVERLAY_VISUALS",
                                 SGI_XA_SERVER_OVERLAY_VISUALS,
                                 True);
  if (xa_sov == None)
    {
      GDK_GL_NOTE (MISC, g_message (" -- SERVER_OVERLAY_VISUALS: not supported"));
      return NULL;
    }

  GDK_GL_NOTE (MISC, g_message (" -- SERVER_OVERLAY_VISUALS: supported"));

  if (!init)
    {
      screen_count = ScreenCount (xdisplay);

      sov_props_per_screen = g_new (__SOVPropsPerScreen, screen_count);

      for (i = 0; i < screen_count; i++)
        {
          xroot_window = RootWindow (xdisplay, i);

          status = XGetWindowProperty (xdisplay, xroot_window,
                                       xa_sov, 0, 10000, False, xa_sov,
                                       &actual_type,
                                       &actual_format,
                                       &nitems,
                                       &bytes_after,
                                       (unsigned char **) &props);

          if (status != Success ||
              actual_type != xa_sov ||
              actual_format != 32 ||
              nitems < 4)
            {
              sov_props_per_screen[i].props = NULL;
              sov_props_per_screen[i].num_props = 0;
            }
          else
            {
              sov_props_per_screen[i].props = props;
              /* Four 32-bit quantities per SERVER_OVERLAY_VISUALS entry. */
              sov_props_per_screen[i].num_props = nitems / 4;

#ifdef G_ENABLE_DEBUG
              if (gdk_gl_debug_flags & GDK_GL_DEBUG_MISC)
                {
                  int j;
                  g_message (" -- SERVER_OVERLAY_VISUALS: properties");
                  g_print ("screen\tvisual\ttype\tvalue\tlayer\n");
                  num_props = sov_props_per_screen[i].num_props;
                  for (j = 0; j < num_props; j++)
                    {
                      g_print ("%d\t0x%lx\t%lu\t%lu\t%ld\n",
                               i,
                               (VisualID) (props[j].overlay_visual),
                               (CARD32)   (props[j].transparent_type),
                               (CARD32)   (props[j].value),
                               (INT32)    (props[j].layer));
                    }
                }
#endif /* G_ENABLE_DEBUG */

            }
        }

      init = TRUE;
    }

  /* look up SOV property for the visual. */

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  screen_num = GDK_SCREEN_XNUMBER (screen);
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
  screen_num = gdk_x11_get_default_screen ();
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

  xvisual = GDK_VISUAL_XVISUAL (visual);

  props     = sov_props_per_screen[screen_num].props;
  num_props = sov_props_per_screen[screen_num].num_props;

  for (i = 0; i < num_props; i++)
    {
      if ((VisualID) (props[i].overlay_visual) == xvisual->visualid)
        {
          GDK_GL_NOTE (MISC, g_message (" -- SERVER_OVERLAY_VISUALS: property was found"));
          return &props[i];
        }
    }

  return NULL;
}

/* private at present... */
gboolean
_gdk_x11_gl_overlay_get_info (GdkScreen        *screen,
                              GdkVisual        *visual,
                              GdkGLOverlayInfo *overlay_info)
{
  __SOVProp *sov_prop;

  GDK_GL_NOTE (FUNC, g_message (" -- _gdk_x11_gl_overlay_get_info ()"));

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  g_return_val_if_fail (GDK_IS_SCREEN (screen), FALSE);
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */
  g_return_val_if_fail (GDK_IS_VISUAL (visual), FALSE);
  g_return_val_if_fail (overlay_info != NULL, FALSE);

  sov_prop = gdk_gl_overlay_get_sov_prop (screen, visual);
  if (sov_prop == NULL)
    {
      GDK_GL_NOTE (MISC, g_message (" -- this visual is not overlay visual"));

      /* meaningless */
      overlay_info->visual           = visual;
      overlay_info->transparent_type = GDK_GL_OVERLAY_TRANSPARENT_NONE;
      overlay_info->value            = 0;
      overlay_info->layer            = 0;
      
      return FALSE;
    }

  GDK_GL_NOTE (MISC, g_message (" -- overlay visual"));

  overlay_info->visual           = visual;
  overlay_info->transparent_type = sov_prop->transparent_type;
  overlay_info->value            = sov_prop->value;
  overlay_info->layer            = sov_prop->layer;

  return TRUE;
}
