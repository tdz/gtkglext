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

#ifdef GDK_MULTIHEAD_SAFE
#include <gdk/gdkscreen.h>
#endif /* GDK_MULTIHEAD_SAFE */

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglconfig-x11.h"

#include <X11/Xatom.h>  /* for XA_RGB_DEFAULT_MAP atom */
#if defined(__vms)
#include <Xmu/StdCmap.h>  /* for XmuLookupStandardColormap */
#else
#include <X11/Xmu/StdCmap.h>  /* for XmuLookupStandardColormap */
#endif

enum {
  PROP_0,
  PROP_ATTRIB_LIST
};

/* Forward declarations */

#ifdef _GDK_HAS_COLORMAP_FOREIGN_NEW
static GdkColormap *gdk_gl_config_get_std_rgb_colormap  (GdkScreen               *screen,
                                                         XVisualInfo             *xvinfo,
                                                         gboolean                 is_mesa_glx);
#endif /* _GDK_HAS_COLORMAP_FOREIGN_NEW */
static GdkColormap *gdk_gl_config_setup_colormap        (GdkScreen               *screen,
                                                         XVisualInfo             *xvinfo,
                                                         gboolean                 is_rgba,
                                                         gboolean                 is_mesa_glx);
static void         gdk_gl_config_fb_configuration      (GdkGLConfigImplX11      *impl,
                                                         int                     *attrib_list);

static gboolean     gdk_x11_gl_config_get_attrib        (GdkGLConfig             *glconfig,
                                                         gint                     attribute,
                                                         gint                    *value);

static void         gdk_gl_config_impl_x11_init         (GdkGLConfigImplX11      *impl);
static void         gdk_gl_config_impl_x11_class_init   (GdkGLConfigImplX11Class *klass);

static GObject     *gdk_gl_config_impl_x11_constructor  (GType                    type,
                                                         guint                    n_construct_properties,
                                                         GObjectConstructParam   *construct_properties);
static void         gdk_gl_config_impl_x11_set_property (GObject                 *object,
                                                         guint                    property_id,
                                                         const GValue            *value,
                                                         GParamSpec              *pspec);
static void         gdk_gl_config_impl_x11_get_property (GObject                 *object,
                                                         guint                    property_id,
                                                         GValue                  *value,
                                                         GParamSpec              *pspec);
static void         gdk_gl_config_impl_x11_finalize     (GObject                 *object);

static gpointer parent_class = NULL;

GType
gdk_gl_config_impl_x11_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLConfigImplX11Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_config_impl_x11_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLConfigImplX11),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_config_impl_x11_init,
      };

      type = g_type_register_static (GDK_TYPE_GL_CONFIG,
                                     "GdkGLConfigImplX11",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_config_impl_x11_init (GdkGLConfigImplX11 *impl)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_x11_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_config_impl_x11_class_init (GdkGLConfigImplX11Class *klass)
{
  GdkGLConfigClass *glconfig_class = GDK_GL_CONFIG_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_x11_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor  = gdk_gl_config_impl_x11_constructor;
  object_class->set_property = gdk_gl_config_impl_x11_set_property;
  object_class->get_property = gdk_gl_config_impl_x11_get_property;
  object_class->finalize     = gdk_gl_config_impl_x11_finalize;

  glconfig_class->get_attrib = gdk_x11_gl_config_get_attrib;

  g_object_class_install_property (object_class,
                                   PROP_ATTRIB_LIST,
                                   g_param_spec_pointer ("attrib_list",
                                                        _("Attrib list"),
                                                        _("Pointer to the OpenGL configuration attribute list."),
                                                        G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

static GObject *
gdk_gl_config_impl_x11_constructor (GType                  type,
                                    guint                  n_construct_properties,
                                    GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLConfig *glconfig;
  GdkGLConfigImplX11 *impl;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_x11_constructor ()"));

  glconfig = GDK_GL_CONFIG (object);
  impl = GDK_GL_CONFIG_IMPL_X11 (object);

  /*
   * Successfully constructed?
   */

  if (glconfig->colormap != NULL)
    impl->is_constructed = TRUE;

  return object;
}

/* 
 * Get standard RGB colormap
 */

#ifdef _GDK_HAS_COLORMAP_FOREIGN_NEW

static GdkColormap *
gdk_gl_config_get_std_rgb_colormap (GdkScreen   *screen,
                                    XVisualInfo *xvinfo,
                                    gboolean     is_mesa_glx)
{
  Display *xdisplay;
  int screen_num;
  Window xroot_window;
  Status status;
  Colormap xcolormap = None;
  XStandardColormap *standard_cmaps;
  int i, num_cmaps;
  GdkVisual *visual;
  static Atom xa_hp_cr_maps = -1;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_get_std_rgb_colormap ()"));

  xdisplay = GDK_SCREEN_XDISPLAY (screen);
  screen_num = xvinfo->screen;
  xroot_window = RootWindow (xdisplay, screen_num);

  /*
   * (ripped from GLUT)
   * Hewlett-Packard supports a feature called "HP Color Recovery".
   * Mesa has code to use HP Color Recovery.  For Mesa to use this feature,
   * the atom _HP_RGB_SMOOTH_MAP_LIST must be defined on the root window AND
   * the colormap obtainable by XGetRGBColormaps for that atom must be set on
   * the window.  If that colormap is not set, the output will look stripy.
   */

  if (is_mesa_glx)
    {

      if (xa_hp_cr_maps == -1) {
        xa_hp_cr_maps = XInternAtom (xdisplay, "_HP_RGB_SMOOTH_MAP_LIST", True);
      }

      if (xa_hp_cr_maps &&
          xvinfo->visual->class == TrueColor &&
          xvinfo->depth == 8)
        {
          status = XGetRGBColormaps (xdisplay, xroot_window,
                                     &standard_cmaps, &num_cmaps,
                                     xa_hp_cr_maps);
          if (status)
            {
              for (i = 0; i < num_cmaps; i++)
                {
                  if (standard_cmaps[i].visualid == xvinfo->visualid)
                    {
                      xcolormap = standard_cmaps[i].colormap;
                      break;
                    }
                }
              XFree (standard_cmaps);
            }

          if (xcolormap != None)
            {
              GDK_GL_NOTE (MISC, g_message (" -- colormap: standard RGB for HP Color Recovery"));

              visual = gdk_x11_screen_lookup_visual (screen, xvinfo->visualid);
              return gdk_x11_colormap_foreign_new (visual, xcolormap);
            }
        }
    }

#ifndef SOLARIS_2_4_BUG
  /*
   * (ripped from GLUT)
   * Solaris 2.4 and 2.5 have a bug in their XmuLookupStandardColormap
   * implementations.  Please compile your Solaris 2.4 or 2.5 version of
   * GtkGLExt with -DSOLARIS_2_4_BUG to work around this bug. The symptom
   * of the bug is that programs will get a BadMatch error from XCreateWindow
   * when creating a window because Solaris 2.4 and 2.5 create a corrupted
   * RGB_DEFAULT_MAP property.  Note that this workaround prevents Colormap
   * sharing between applications, perhaps leading unnecessary colormap
   * installations or colormap flashing. Sun fixed this bug in Solaris 2.6.
   */

  status = XmuLookupStandardColormap (xdisplay, screen_num,
                                      xvinfo->visualid, xvinfo->depth,
                                      XA_RGB_DEFAULT_MAP,
                                      False, True);
  if (status)
    {
      status = XGetRGBColormaps (xdisplay, xroot_window,
                                 &standard_cmaps, &num_cmaps,
                                 XA_RGB_DEFAULT_MAP);
      if (status)
        {
          for (i = 0; i < num_cmaps; i++)
            {
              if (standard_cmaps[i].visualid == xvinfo->visualid)
                {
                  xcolormap = standard_cmaps[i].colormap;
                  break;
                }
            }
          XFree (standard_cmaps);
        }

      if (xcolormap != None)
        {
          GDK_GL_NOTE (MISC, g_message (" -- colormap: standard RGB"));

          visual = gdk_x11_screen_lookup_visual (screen, xvinfo->visualid);
          return gdk_x11_colormap_foreign_new (visual, xcolormap);
        }
    }

#endif /* SOLARIS_2_4_BUG */

  return NULL;
}

#endif /* _GDK_HAS_COLORMAP_FOREIGN_NEW */

/* 
 * Setup colormap.
 */

#ifdef GDK_MULTIHEAD_SAFE

static GdkColormap *
gdk_gl_config_setup_colormap (GdkScreen   *screen,
                              XVisualInfo *xvinfo,
                              gboolean     is_rgba,
                              gboolean     is_mesa_glx)
{
  GdkColormap *colormap;
  GdkVisual *visual;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_setup_colormap ()"));

  if (is_rgba)
    {
      /* For RGBA mode. */

      /* Try default colormap. */

      colormap = gdk_screen_get_default_colormap (screen);
      visual = gdk_colormap_get_visual (colormap);
      if (GDK_VISUAL_XVISUAL (visual)->visualid == xvinfo->visualid)
        {
          GDK_GL_NOTE (MISC, g_message (" -- colormap: screen default"));

          g_object_ref (G_OBJECT (colormap));
          return colormap;
        }

      /* Try standard RGB colormap. */

#ifdef _GDK_HAS_COLORMAP_FOREIGN_NEW
      colormap = gdk_gl_config_get_std_rgb_colormap (screen, xvinfo, is_mesa_glx);
      if (colormap)
        return colormap;
#endif /* _GDK_HAS_COLORMAP_FOREIGN_NEW */

      /* New colormap. */

      GDK_GL_NOTE (MISC, g_message (" -- colormap: new non-private"));

      visual = gdk_x11_screen_lookup_visual (screen, xvinfo->visualid);
      colormap = gdk_colormap_new (visual, FALSE);
      return colormap;

    }
  else
    {
      /* For color index mode. */

      GDK_GL_NOTE (MISC, g_message (" -- colormap: new private"));

      visual = gdk_x11_screen_lookup_visual (screen, xvinfo->visualid);
      colormap = gdk_colormap_new (visual, TRUE);
      return colormap;

    }

  /* not reached */
  return NULL;
}

#else  /* GDK_MULTIHEAD_SAFE */

static GdkColormap *
gdk_gl_config_setup_colormap (GdkScreen   *screen,
                              XVisualInfo *xvinfo,
                              gboolean     is_rgba,
                              gboolean     is_mesa_glx)
{
  GdkColormap *colormap;
  GdkVisual *visual;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_setup_colormap ()"));

  if (is_rgba)
    {
      /* For RGBA mode. */

      /* Try default colormap. */

      colormap = gdk_colormap_get_system ();
      visual = gdk_colormap_get_visual (colormap);
      if (GDK_VISUAL_XVISUAL (visual)->visualid == xvinfo->visualid)
        {
          GDK_GL_NOTE (MISC, g_message (" -- colormap: system default"));

          g_object_ref (G_OBJECT (colormap));
          return colormap;
        }

      /* New colormap. */

      GDK_GL_NOTE (MISC, g_message (" -- colormap: new non-private"));

      visual = gdkx_visual_get (xvinfo->visualid);
      colormap = gdk_colormap_new (visual, FALSE);
      return colormap;

    }
  else
    {
      /* For color index mode. */

      GDK_GL_NOTE (MISC, g_message (" -- colormap: new private"));

      visual = gdkx_visual_get (xvinfo->visualid);
      colormap = gdk_colormap_new (visual, TRUE);
      return colormap;

    }

  /* not reached */
  return NULL;
}

#endif /* GDK_MULTIHEAD_SAFE */

/* 
 * Configure OpenGL frame buffer
 */

static void
gdk_gl_config_fb_configuration (GdkGLConfigImplX11 *impl,
                                int                *attrib_list)
{
  GdkGLConfig *glconfig = GDK_GL_CONFIG (impl);
  int value;
  static int is_mesa_glx = -1;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_fb_configuration ()"));

  g_return_if_fail (attrib_list != NULL);

#ifdef GDK_MULTIHEAD_SAFE
  impl->xdisplay = GDK_SCREEN_XDISPLAY (glconfig->screen);
  impl->screen_num = GDK_SCREEN_XNUMBER (glconfig->screen);
#else  /* GDK_MULTIHEAD_SAFE */
  impl->xdisplay = gdk_x11_get_default_xdisplay ();
  impl->screen_num = gdk_x11_get_default_screen ();
#endif /* GDK_MULTIHEAD_SAFE */

  GDK_GL_NOTE (MISC,
               g_message (" -- GLX_VENDOR     : %s",
                          glXGetClientString(impl->xdisplay, GLX_VENDOR)));
  GDK_GL_NOTE (MISC,
               g_message (" -- GLX_VERSION    : %s",
                          glXGetClientString(impl->xdisplay, GLX_VERSION)));
  GDK_GL_NOTE (MISC,
               g_message (" -- GLX_EXTENSIONS : %s",
                          glXGetClientString(impl->xdisplay, GLX_EXTENSIONS)));

  /*
   * Find an OpenGL-capable visual.
   */

  impl->xvinfo = glXChooseVisual (impl->xdisplay, impl->screen_num, attrib_list);
  if (impl->xvinfo == NULL)
    return;

  GDK_GL_NOTE (MISC, g_message (" -- visual id : 0x%lx", impl->xvinfo->visualid));

#define GET_CONFIG(attrib) \
  glXGetConfig (impl->xdisplay, impl->xvinfo, (attrib), &value)

  /*
   * Setup colormap.
   */

  /* RGBA mode? */
  GET_CONFIG (GLX_RGBA);
  glconfig->is_rgba = value ? TRUE : FALSE;

  /* Using Mesa? */
  if (is_mesa_glx == -1)
    {
      if (strstr (glXQueryServerString (impl->xdisplay, impl->screen_num, GLX_VERSION), "Mesa"))
        is_mesa_glx = 1;
      else
        is_mesa_glx = 0;
    }
  impl->is_mesa_glx = is_mesa_glx ? TRUE : FALSE;

  /* get an appropriate colormap. */
  glconfig->colormap = gdk_gl_config_setup_colormap (glconfig->screen,
                                                     impl->xvinfo,
                                                     glconfig->is_rgba,
                                                     impl->is_mesa_glx);

  /*
   * Depth (number of bits per pixel) of the visual.
   */

  glconfig->depth = impl->xvinfo->depth;

  /*
   * Get configuration results.
   */

  /* Layer plane. */
  GET_CONFIG (GLX_LEVEL);
  glconfig->layer_plane = value;

  /* Double buffering is supported? */
  GET_CONFIG (GLX_DOUBLEBUFFER);
  glconfig->is_double_buffered = value ? TRUE : FALSE;

  /* Stereo is supported? */
  GET_CONFIG (GLX_STEREO);
  glconfig->is_stereo = value ? TRUE : FALSE;

  /* Has alpha bits? */
  GET_CONFIG (GLX_ALPHA_SIZE);
  glconfig->has_alpha = value ? TRUE : FALSE;

  /* Has depth buffer? */
  GET_CONFIG (GLX_DEPTH_SIZE);
  glconfig->has_depth_buffer = value ? TRUE : FALSE;

  /* Has stencil buffer? */
  GET_CONFIG (GLX_STENCIL_SIZE);
  glconfig->has_stencil_buffer = value ? TRUE : FALSE;

  /* Has accumulation buffer? */
  GET_CONFIG (GLX_ACCUM_RED_SIZE);
  glconfig->has_accum_buffer = value ? TRUE : FALSE;

  /* Support multisample antialiasing? */
  glconfig->is_multisample = FALSE;

  /* Support luminance color model? */
  glconfig->is_luminance = FALSE;

#undef GET_CONFIG
}

static void
gdk_gl_config_impl_x11_set_property (GObject      *object,
                                     guint         property_id,
                                     const GValue *value,
                                     GParamSpec   *pspec)
{
  GdkGLConfigImplX11 *impl = GDK_GL_CONFIG_IMPL_X11 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_x11_set_property ()"));

  switch (property_id)
    {
    case PROP_ATTRIB_LIST:
      gdk_gl_config_fb_configuration (impl, g_value_get_pointer (value));
      g_object_notify (object, "attrib_list");
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_config_impl_x11_get_property (GObject    *object,
                                     guint       property_id,
                                     GValue     *value,
                                     GParamSpec *pspec)
{
  switch (property_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_config_impl_x11_finalize (GObject *object)
{
  GdkGLConfigImplX11 *impl = GDK_GL_CONFIG_IMPL_X11 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_x11_finalize ()"));

  if (impl->xvinfo != NULL)
    {
      XFree (impl->xvinfo);
      impl->xvinfo = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

/**
 * gdk_gl_config_new:
 * @attrib_list: a list of attribute/value pairs. The last attribute must be GDK_GL_ATTRIB_LIST_NONE.
 *
 * Returns an OpenGL frame buffer configuration that match the specified
 * attributes.
 *
 * Return value: the new #GdkGLConfig.
 **/
GdkGLConfig *
gdk_gl_config_new (const int *attrib_list)
{
  GdkGLConfig *glconfig;
  GdkGLConfigImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_new ()"));

  /*
   * Instanciate the GdkGLConfigImplX11 object.
   */

#ifdef GDK_MULTIHEAD_SAFE
  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_X11,
                           "screen",      gdk_screen_get_default (),
                           "attrib_list", attrib_list,
                           NULL);
#else  /* GDK_MULTIHEAD_SAFE */
  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_X11,
                           "screen",      NULL,
                           "attrib_list", attrib_list,
                           NULL);
#endif /* GDK_MULTIHEAD_SAFE */

  impl = GDK_GL_CONFIG_IMPL_X11 (glconfig);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glconfig));
      return NULL;
    }

  return glconfig;
}

#ifdef GDK_MULTIHEAD_SAFE

GdkGLConfig *
gdk_gl_config_new_for_screen (GdkScreen *screen,
                              const int *attrib_list)
{
  GdkGLConfig *glconfig;
  GdkGLConfigImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_new ()"));

  /*
   * Instanciate the GdkGLConfigImplX11 object.
   */

  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_X11,
                           "screen",      screen,
                           "attrib_list", attrib_list,
                           NULL);
  impl = GDK_GL_CONFIG_IMPL_X11 (glconfig);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glconfig));
      return NULL;
    }

  return glconfig;
}

#endif /* GDK_MULTIHEAD_SAFE */

/**
 * gdk_x11_gl_config_get_xdisplay:
 * @glconfig: a #GdkGLConfig.
 *
 * Get X Display.
 *
 * Return value: pointer to the Display.
 **/
Display *
gdk_x11_gl_config_get_xdisplay (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->xdisplay;
}

/**
 * gdk_x11_gl_config_get_screen_number:
 * @glconfig: a #GdkGLConfig.
 *
 * Get X screen number.
 *
 * Return value: the screen number.
 **/
int
gdk_x11_gl_config_get_screen_number (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), 0);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->screen_num;
}

/**
 * gdk_x11_gl_config_get_xvinfo:
 * @glconfig: a #GdkGLConfig.
 *
 * Get XVisualInfo data.
 *
 * Return value: pointer to the XVisualInfo data.
 **/
XVisualInfo *
gdk_x11_gl_config_get_xvinfo (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->xvinfo;
}

static gboolean
gdk_x11_gl_config_get_attrib (GdkGLConfig *glconfig,
                              int          attribute,
                              int         *value)
{
  GdkGLConfigImplX11 *impl;
  int ret;

  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  impl = GDK_GL_CONFIG_IMPL_X11 (glconfig);

  ret = glXGetConfig (impl->xdisplay, impl->xvinfo, attribute, value);
  if (ret == Success)
    return TRUE;

  /* Error handling? */

  return FALSE;
}
