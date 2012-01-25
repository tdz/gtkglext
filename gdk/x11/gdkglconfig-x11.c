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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <string.h>

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglconfig-x11.h"
#include "gdkglwindow-x11.h"

#include <gdk/gdk.h>

#ifdef HAVE_LIBXMU

#include <X11/Xatom.h>  /* for XA_RGB_DEFAULT_MAP atom */

#ifdef HAVE_XMU_STDCMAP_H
#include <Xmu/StdCmap.h>  /* for XmuLookupStandardColormap */
#else
#include <X11/Xmu/StdCmap.h>  /* for XmuLookupStandardColormap */
#endif

#endif /* HAVE_LIBXMU */

static GdkScreen* _gdk_x11_gl_config_get_screen (GdkGLConfig *glconfig);
static gboolean   _gdk_x11_gl_config_get_attrib (GdkGLConfig *glconfig,
                                                 int          attribute,
                                                 int         *value);
static GdkVisual* _gdk_x11_gl_config_get_visual (GdkGLConfig *glconfig);
static gint       _gdk_x11_gl_config_get_depth  (GdkGLConfig *glconfig);

G_DEFINE_TYPE (GdkGLConfigImplX11,              \
               gdk_gl_config_impl_x11,          \
               GDK_TYPE_GL_CONFIG)

static void
gdk_gl_config_impl_x11_init (GdkGLConfigImplX11 *self)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();

  self->xdisplay = NULL;
  self->screen_num = 0;
  self->xvinfo = NULL;
  self->screen = 0;
  self->is_mesa_glx = 0;
}

static void
gdk_gl_config_impl_x11_finalize (GObject *object)
{
  GdkGLConfigImplX11 *impl = GDK_GL_CONFIG_IMPL_X11 (object);

  GDK_GL_NOTE_FUNC_PRIVATE ();

  XFree (impl->xvinfo);

  G_OBJECT_CLASS (gdk_gl_config_impl_x11_parent_class)->finalize (object);
}

static void
gdk_gl_config_impl_x11_class_init (GdkGLConfigImplX11Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE_FUNC_PRIVATE ();

  klass->parent_class.create_new_gl_window = _gdk_x11_gl_window_new;
  klass->parent_class.get_screen = _gdk_x11_gl_config_get_screen;
  klass->parent_class.get_attrib = _gdk_x11_gl_config_get_attrib;
  klass->parent_class.get_visual = _gdk_x11_gl_config_get_visual;
  klass->parent_class.get_depth  = _gdk_x11_gl_config_get_depth;

  object_class->finalize = gdk_gl_config_impl_x11_finalize;
}

static void
gdk_gl_config_init_attrib (GdkGLConfig *glconfig)
{
  GdkGLConfigImplX11 *impl;
  int value;

  impl = GDK_GL_CONFIG_IMPL_X11 (glconfig);

#define _GET_CONFIG(__attrib) \
  glXGetConfig (impl->xdisplay, impl->xvinfo, __attrib, &value)

  /* RGBA mode? */
  _GET_CONFIG (GLX_RGBA);
  glconfig->is_rgba = value ? TRUE : FALSE;

  /* Layer plane. */
  _GET_CONFIG (GLX_LEVEL);
  glconfig->layer_plane = value;

  /* Double buffering is supported? */
  _GET_CONFIG (GLX_DOUBLEBUFFER);
  glconfig->is_double_buffered = value ? TRUE : FALSE;

  /* Stereo is supported? */
  _GET_CONFIG (GLX_STEREO);
  glconfig->is_stereo = value ? TRUE : FALSE;

  /* Number of aux buffers */
  _GET_CONFIG (GLX_AUX_BUFFERS);
  glconfig->n_aux_buffers = value;

  /* Has alpha bits? */
  _GET_CONFIG (GLX_ALPHA_SIZE);
  glconfig->has_alpha = value ? TRUE : FALSE;

  /* Has depth buffer? */
  _GET_CONFIG (GLX_DEPTH_SIZE);
  glconfig->has_depth_buffer = value ? TRUE : FALSE;

  /* Has stencil buffer? */
  _GET_CONFIG (GLX_STENCIL_SIZE);
  glconfig->has_stencil_buffer = value ? TRUE : FALSE;

  /* Has accumulation buffer? */
  _GET_CONFIG (GLX_ACCUM_RED_SIZE);
  glconfig->has_accum_buffer = value ? TRUE : FALSE;

  /* Number of multisample buffers (not supported yet) */
  glconfig->n_sample_buffers = 0;

#undef _GET_CONFIG
}

static GdkGLConfig *
gdk_gl_config_new_common (GdkScreen *screen,
                          const int *attrib_list)
{
  GdkGLConfig *glconfig;
  GdkGLConfigImplX11 *impl;

  Display *xdisplay;
  int screen_num;
  XVisualInfo *xvinfo;
  int is_rgba;

  GDK_GL_NOTE_FUNC_PRIVATE ();

  xdisplay = GDK_SCREEN_XDISPLAY (screen);
  screen_num = GDK_SCREEN_XNUMBER (screen);

  GDK_GL_NOTE (MISC, _gdk_x11_gl_print_glx_info (xdisplay, screen_num));

  /*
   * Find an OpenGL-capable visual.
   */

  GDK_GL_NOTE_FUNC_IMPL ("glXChooseVisual");

  xvinfo = glXChooseVisual (xdisplay, screen_num, (int *) attrib_list);
  if (xvinfo == NULL)
    return NULL;

  GDK_GL_NOTE (MISC,
    g_message (" -- glXChooseVisual: screen number = %d", xvinfo->screen));
  GDK_GL_NOTE (MISC,
    g_message (" -- glXChooseVisual: visual id = 0x%lx", xvinfo->visualid));

  /*
   * Instantiate the GdkGLConfigImplX11 object.
   */

  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_X11, NULL);
  impl = GDK_GL_CONFIG_IMPL_X11 (glconfig);

  impl->xdisplay = xdisplay;
  impl->screen_num = screen_num;
  impl->xvinfo = xvinfo;

  impl->screen = screen;

  /* Using Mesa? */
  if (strstr (glXQueryServerString (xdisplay, screen_num, GLX_VERSION), "Mesa"))
    impl->is_mesa_glx = TRUE;
  else
    impl->is_mesa_glx = FALSE;

  /*
   * Get an appropriate colormap.
   */

  /* RGBA mode? */
  glXGetConfig (xdisplay, xvinfo, GLX_RGBA, &is_rgba);

  /*
   * Init configuration attributes.
   */

  gdk_gl_config_init_attrib (glconfig);

  return glconfig;
}

GdkGLConfig *
_gdk_x11_gl_config_new (const int *attrib_list)
{
  GdkScreen *screen;

  GDK_GL_NOTE_FUNC ();

  g_return_val_if_fail (attrib_list != NULL, NULL);

  screen = gdk_screen_get_default ();

  return gdk_gl_config_new_common (screen, attrib_list);
}

GdkGLConfig *
_gdk_x11_gl_config_new_for_screen (GdkScreen *screen,
                              const int *attrib_list)
{
  GDK_GL_NOTE_FUNC ();

  g_return_val_if_fail (GDK_IS_SCREEN (screen), NULL);
  g_return_val_if_fail (attrib_list != NULL, NULL);

  return gdk_gl_config_new_common (screen, attrib_list);
}

/*
 * XVisualInfo returned by this function should be freed by XFree ().
 */
static XVisualInfo *
gdk_x11_gl_get_xvinfo (Display  *xdisplay,
                       int       screen_num,
                       VisualID  xvisualid)
{
  XVisualInfo xvinfo_template;
  XVisualInfo *xvinfo_list;
  int nitems_return;

  GDK_GL_NOTE_FUNC_PRIVATE ();

  xvinfo_template.visualid = xvisualid;
  xvinfo_template.screen = screen_num;

  xvinfo_list = XGetVisualInfo (xdisplay,
                                VisualIDMask | VisualScreenMask,
                                &xvinfo_template,
                                &nitems_return);

  /* Returned XVisualInfo needs to be unique */
  g_assert (xvinfo_list != NULL && nitems_return == 1);

  return xvinfo_list;
}

static GdkGLConfig *
gdk_x11_gl_config_new_from_visualid_common (GdkScreen *screen,
                                            VisualID   xvisualid)
{
  GdkGLConfig *glconfig;
  GdkGLConfigImplX11 *impl;

  Display *xdisplay;
  int screen_num;
  XVisualInfo *xvinfo;
  int is_rgba;

  GDK_GL_NOTE_FUNC_PRIVATE ();

  xdisplay = GDK_SCREEN_XDISPLAY (screen);
  screen_num = GDK_SCREEN_XNUMBER (screen);

  GDK_GL_NOTE (MISC,
               g_message (" -- GLX_VENDOR     : %s",
                          glXGetClientString (xdisplay, GLX_VENDOR)));
  GDK_GL_NOTE (MISC,
               g_message (" -- GLX_VERSION    : %s",
                          glXGetClientString (xdisplay, GLX_VERSION)));
  GDK_GL_NOTE (MISC,
               g_message (" -- GLX_EXTENSIONS : %s",
                          glXGetClientString (xdisplay, GLX_EXTENSIONS)));

  /*
   * Get XVisualInfo.
   */

  xvinfo = gdk_x11_gl_get_xvinfo (xdisplay, screen_num, xvisualid);
  if (xvinfo == NULL)
    return NULL;

  GDK_GL_NOTE (MISC,
    g_message (" -- gdk_x11_gl_get_xvinfo: screen number = %d", xvinfo->screen));
  GDK_GL_NOTE (MISC,
    g_message (" -- gdk_x11_gl_get_xvinfo: visual id = 0x%lx", xvinfo->visualid));

  /*
   * Instantiate the GdkGLConfigImplX11 object.
   */

  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_X11, NULL);
  impl = GDK_GL_CONFIG_IMPL_X11 (glconfig);

  impl->xdisplay = xdisplay;
  impl->screen_num = screen_num;
  impl->xvinfo = xvinfo;

  impl->screen = screen;

  /* Using Mesa? */
  if (strstr (glXQueryServerString (xdisplay, screen_num, GLX_VERSION), "Mesa"))
    impl->is_mesa_glx = TRUE;
  else
    impl->is_mesa_glx = FALSE;

  /*
   * Get an appropriate colormap.
   */

  /* RGBA mode? */
  glXGetConfig (xdisplay, xvinfo, GLX_RGBA, &is_rgba);

  /*
   * Init configuration attributes.
   */

  gdk_gl_config_init_attrib (glconfig);

  return glconfig;
}

/**
 * gdk_x11_gl_config_new_from_visualid:
 * @xvisualid: visual ID.
 *
 * Creates #GdkGLConfig from given visual ID that specifies the OpenGL-capable
 * visual.
 *
 * Return value: the new #GdkGLConfig.
 **/
GdkGLConfig *
gdk_x11_gl_config_new_from_visualid (VisualID xvisualid)
{
  GdkScreen *screen;

  GDK_GL_NOTE_FUNC ();

  screen = gdk_screen_get_default ();

  return gdk_x11_gl_config_new_from_visualid_common (screen, xvisualid);
}

/**
 * gdk_x11_gl_config_new_from_visualid_for_screen:
 * @screen: target screen.
 * @xvisualid: visual ID.
 *
 * Creates #GdkGLConfig from given visual ID that specifies the OpenGL-capable
 * visual.
 *
 * Return value: the new #GdkGLConfig.
 **/
GdkGLConfig *
gdk_x11_gl_config_new_from_visualid_for_screen (GdkScreen *screen,
                                                VisualID   xvisualid)
{
  GDK_GL_NOTE_FUNC ();

  g_return_val_if_fail (GDK_IS_SCREEN (screen), NULL);

  return gdk_x11_gl_config_new_from_visualid_common (screen, xvisualid);
}

static GdkScreen *
_gdk_x11_gl_config_get_screen (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), NULL);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->screen;
}

static gboolean
_gdk_x11_gl_config_get_attrib (GdkGLConfig *glconfig,
                               int          attribute,
                               int         *value)
{
  GdkGLConfigImplX11 *impl;
  int ret;

  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), FALSE);

  impl = GDK_GL_CONFIG_IMPL_X11 (glconfig);

  ret = glXGetConfig (impl->xdisplay, impl->xvinfo, attribute, value);

  return (ret == Success);
}

static GdkVisual *
_gdk_x11_gl_config_get_visual (GdkGLConfig *glconfig)
{
  GdkGLConfigImplX11 *impl;

  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), NULL);

  impl = GDK_GL_CONFIG_IMPL_X11 (glconfig);

  return gdk_x11_screen_lookup_visual(impl->screen, impl->xvinfo->visualid);
}

static gint
_gdk_x11_gl_config_get_depth (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), 0);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->xvinfo->depth;
}

/**
 * gdk_x11_gl_config_get_xdisplay:
 * @glconfig: a #GdkGLConfig.
 *
 * Gets X Display.
 *
 * Return value: pointer to the Display.
 **/
Display *
gdk_x11_gl_config_get_xdisplay (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), NULL);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->xdisplay;
}

/**
 * gdk_x11_gl_config_get_screen_number:
 * @glconfig: a #GdkGLConfig.
 *
 * Gets X screen number.
 *
 * Return value: the screen number.
 **/
int
gdk_x11_gl_config_get_screen_number (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), 0);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->screen_num;
}

/**
 * gdk_x11_gl_config_get_xvinfo:
 * @glconfig: a #GdkGLConfig.
 *
 * Gets XVisualInfo data.
 *
 * Return value: pointer to the XVisualInfo data.
 **/
XVisualInfo *
gdk_x11_gl_config_get_xvinfo (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), NULL);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->xvinfo;
}

/**
 * gdk_x11_gl_config_is_mesa_glx:
 * @glconfig: a #GdkGLConfig.
 *
 * Returns whether the server's GLX entension is Mesa.
 *
 * Return value: TRUE if Mesa GLX, FALSE otherwise.
 **/
gboolean
gdk_x11_gl_config_is_mesa_glx (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_X11 (glconfig), FALSE);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->is_mesa_glx;
}
