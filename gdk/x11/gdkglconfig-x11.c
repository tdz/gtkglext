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

#ifdef GDK_MULTIHEAD_SAFE
#include <gdk/gdkscreen.h>
#endif

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglconfig-x11.h"

enum {
  PROP_0,
  PROP_ATTRIB_LIST
};

/* Forward declarations */
#if 0
static XVisualInfo *gdk_x11_visual_get_xvinfo (GdkVisual *visual);
#endif

static gboolean gdk_x11_gl_config_get_attrib        (GdkGLConfig             *glconfig,
                                                     gint                     attribute,
                                                     gint                    *value);

static void     gdk_gl_config_impl_x11_init         (GdkGLConfigImplX11      *impl);
static void     gdk_gl_config_impl_x11_class_init   (GdkGLConfigImplX11Class *klass);

static GObject *gdk_gl_config_impl_x11_constructor  (GType                    type,
                                                     guint                    n_construct_properties,
                                                     GObjectConstructParam   *construct_properties);
static void     gdk_gl_config_impl_x11_set_property (GObject                 *object,
                                                     guint                    property_id,
                                                     const GValue            *value,
                                                     GParamSpec              *pspec);
static void     gdk_gl_config_impl_x11_get_property (GObject                 *object,
                                                     guint                    property_id,
                                                     GValue                  *value,
                                                     GParamSpec              *pspec);
static void     gdk_gl_config_impl_x11_finalize     (GObject                 *object);

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
  /* 0-initialization is good for all other fields. */

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
 * XXX: Colormap sharing should be supported.
 *      It may need support of fixed gdkx_colormap_get () function
 *      or something.
 */
static GdkColormap *
get_colormap (GdkVisual *visual)
{
#ifdef GDK_MULTIHEAD_SAFE
  GdkScreen *screen = gdk_screen_get_default ();
#endif
  GdkColormap *colormap;

#ifdef GDK_MULTIHEAD_SAFE

  if (visual == gdk_screen_get_system_visual (screen))
    colormap = g_object_ref (G_OBJECT (gdk_screen_get_system_colormap (screen)));
  else
    colormap = gdk_colormap_new (visual, FALSE);

#else

  if (visual == gdk_visual_get_system ())
    colormap = g_object_ref (G_OBJECT (gdk_colormap_get_system ()));
  else
    colormap = gdk_colormap_new (visual, FALSE);

#endif

  return colormap;
}

static void
set_property (GdkGLConfigImplX11 *impl,
              int                *attrib_list)
{
  GdkGLConfig *glconfig = GDK_GL_CONFIG (impl);

#ifdef GDK_MULTIHEAD_SAFE
  GdkScreen *screen = gdk_screen_get_default ();
#endif
  int screen_num;
  GdkVisual *visual;
  int ret, value;

  g_return_if_fail (attrib_list != NULL);

#ifdef GDK_MULTIHEAD_SAFE
  impl->xdisplay = GDK_SCREEN_XDISPLAY (screen);
  screen_num = GDK_SCREEN_XNUMBER (screen);
#else
  impl->xdisplay = gdk_x11_get_default_xdisplay ();
  screen_num = gdk_x11_get_default_screen ();
#endif

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

  impl->xvinfo = glXChooseVisual (impl->xdisplay, screen_num, attrib_list);
  if (impl->xvinfo == NULL)
    return;

  /*
   * Get an appropriate colormap
   */

#ifdef GDK_MULTIHEAD_SAFE
  visual = gdkx_visual_get_for_screen (screen, impl->xvinfo->visualid);
#else
  visual = gdkx_visual_get (impl->xvinfo->visualid);
#endif
  if (visual == NULL)
    return;

  glconfig->colormap = get_colormap (visual);

  /*
   * Depth (number of bits per pixel) of the visual.
   */

  glconfig->depth = impl->xvinfo->depth;

  /*
   * Double buffering is supported?
   */

  glconfig->is_double_buffered = FALSE;
  ret = glXGetConfig (impl->xdisplay, impl->xvinfo, GLX_DOUBLEBUFFER, &value);
  if (ret == Success && value == True)
    glconfig->is_double_buffered = TRUE;

  /*
   * Stereo is supported?
   */

  glconfig->is_stereo = FALSE;
  ret = glXGetConfig (impl->xdisplay, impl->xvinfo, GLX_STEREO, &value);
  if (ret == Success && value == True)
    glconfig->is_stereo = TRUE;
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
      set_property (impl, g_value_get_pointer (value));
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
gdk_gl_config_new (const gint *attrib_list)
{
  GdkGLConfig *glconfig;
  GdkGLConfigImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_new ()"));

  /*
   * Instanciate the GdkGLConfigImplX11 object.
   */

  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_X11,
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

#if 0

/*
 * XVisualInfo returned by this function should be freed by XFree ().
 */
static XVisualInfo *
gdk_x11_visual_get_xvinfo (GdkVisual *visual)
{
  XVisualInfo xvinfo_template;
  XVisualInfo *xvinfo_list;
  int nitems_return;

  xvinfo_template.visualid = XVisualIDFromVisual (GDK_VISUAL_XVISUAL (visual));
  xvinfo_template.screen = gdk_x11_get_default_screen ();

  xvinfo_list = XGetVisualInfo (gdk_x11_get_default_xdisplay (),
                                VisualIDMask | VisualScreenMask,
                                &xvinfo_template,
                                &nitems_return);

  /* Returned XVisualInfo needs to be unique */
  g_assert (xvinfo_list != NULL && nitems_return == 1);

  return xvinfo_list;
}

#endif

Display *
gdk_x11_gl_config_get_xdisplay (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->xdisplay;
}

XVisualInfo *
gdk_x11_gl_config_get_xvinfo (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return GDK_GL_CONFIG_IMPL_X11 (glconfig)->xvinfo;
}

static gboolean
gdk_x11_gl_config_get_attrib (GdkGLConfig *glconfig,
                              gint         attribute,
                              gint        *value)
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
