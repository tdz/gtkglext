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

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkglconfig-x11.h"
#include "gdkglcontext-x11.h"
#include "gdkglpixmap-x11.h"

#include <string.h>

/* Forward declarations */
static gboolean gdk_x11_gl_pixmap_make_context_current (GdkGLDrawable           *draw,
                                                        GdkGLDrawable           *read,
                                                        GdkGLContext            *glcontext);
static void     gdk_x11_gl_pixmap_swap_buffers         (GdkGLDrawable           *gldrawable);

static void     gdk_gl_pixmap_impl_x11_init            (GdkGLPixmapImplX11      *impl);
static void     gdk_gl_pixmap_impl_x11_class_init      (GdkGLPixmapImplX11Class *klass);

static GObject *gdk_gl_pixmap_impl_x11_constructor     (GType                    type,
                                                        guint                    n_construct_properties,
                                                        GObjectConstructParam   *construct_properties);
static void     gdk_gl_pixmap_impl_x11_finalize        (GObject                 *object);

static void     gdk_gl_pixmap_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface);

static gpointer parent_class = NULL;

GType
gdk_gl_pixmap_impl_x11_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLPixmapImplX11Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_pixmap_impl_x11_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLPixmapImplX11),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_pixmap_impl_x11_init,
      };
      static const GInterfaceInfo gl_drawable_interface_info = {
        (GInterfaceInitFunc) gdk_gl_pixmap_impl_x11_gl_drawable_interface_init,
        (GInterfaceFinalizeFunc) NULL,
        NULL                    /* interface_data */
      };

      type = g_type_register_static (GDK_TYPE_GL_PIXMAP,
                                     "GdkGLPixmapImplX11",
                                     &type_info, 0);
      g_type_add_interface_static (type,
                                   GDK_TYPE_GL_DRAWABLE,
                                   &gl_drawable_interface_info);
    }

  return type;
}

static void
gdk_gl_pixmap_impl_x11_init (GdkGLPixmapImplX11 *impl)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_x11_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_pixmap_impl_x11_class_init (GdkGLPixmapImplX11Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_x11_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor = gdk_gl_pixmap_impl_x11_constructor;
  object_class->finalize    = gdk_gl_pixmap_impl_x11_finalize;
}

static GObject *
gdk_gl_pixmap_impl_x11_constructor (GType                  type,
                                    guint                  n_construct_properties,
                                    GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplX11 *impl;

  Display *xdisplay;
  int screen_num;
  XVisualInfo *xvinfo;
  Pixmap xpixmap;

  Window root_return;
  int x_return, y_return;
  unsigned int width_return, height_return;
  unsigned int border_width_return;
  unsigned int depth_return;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_x11_constructor ()"));

  glpixmap = GDK_GL_PIXMAP (object);
  impl = GDK_GL_PIXMAP_IMPL_X11 (object);

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glpixmap->glconfig);
  screen_num = GDK_GL_CONFIG_SCREEN_XNUMBER (glpixmap->glconfig);
  xvinfo = GDK_GL_CONFIG_XVINFO (glpixmap->glconfig);

  /*
   * Get X Pixmap.
   */

  /*
   * XXX GdkGLPixmap is not GdkPixmap for the moment :-<
   *     use glpixmap->wrapper.
   */
  xpixmap = GDK_DRAWABLE_XID (glpixmap->wrapper);

  /*
   * Check depth of the X pixmap.
   */

  if (!XGetGeometry(xdisplay, xpixmap,
                    &root_return,
                    &x_return, &y_return,
                    &width_return, &height_return,
                    &border_width_return,
                    &depth_return))
    goto FAIL;

  if (depth_return != xvinfo->depth)
    goto FAIL;

  /*
   * Create an OpenGL off-screen rendering area.
   */

#if defined(GLX_MESA_pixmap_colormap) && defined(GTKGLEXT_ENABLE_MESA_EXT)

  if (strstr (glXQueryExtensionsString (xdisplay, screen_num), "GLX_MESA_pixmap_colormap"))
    {
      GDK_GL_NOTE (IMPL, g_message (" * glXCreateGLXPixmapMESA ()"));

      impl->glxpixmap = glXCreateGLXPixmapMESA (xdisplay,
                                                xvinfo,
                                                xpixmap,
                                                GDK_GL_CONFIG_XCOLORMAP (glpixmap->glconfig));
    }
  else
    {
      GDK_GL_NOTE (IMPL, g_message (" * glXCreateGLXPixmap ()"));

      impl->glxpixmap = glXCreateGLXPixmap (xdisplay,
                                            xvinfo,
                                            xpixmap);
    }

#else  /* defined(GLX_MESA_pixmap_colormap) && defined(GTKGLEXT_ENABLE_MESA_EXT) */

  GDK_GL_NOTE (IMPL, g_message (" * glXCreateGLXPixmap ()"));

  impl->glxpixmap = glXCreateGLXPixmap (xdisplay,
                                        xvinfo,
                                        xpixmap);

#endif /* defined(GLX_MESA_pixmap_colormap) && defined(GTKGLEXT_ENABLE_MESA_EXT) */

  if (impl->glxpixmap == None)
    goto FAIL;

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

 FAIL:
  return object;
}

static void
gdk_gl_pixmap_impl_x11_finalize (GObject *object)
{
  GdkGLPixmap *glpixmap = GDK_GL_PIXMAP (object);
  GdkGLPixmapImplX11 *impl = GDK_GL_PIXMAP_IMPL_X11 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_x11_finalize ()"));

  if (impl->glxpixmap != None)
    {
      GDK_GL_NOTE (IMPL, g_message (" * glXDestroyGLXPixmap ()"));

      glXDestroyGLXPixmap (GDK_GL_CONFIG_XDISPLAY (glpixmap->glconfig),
                           impl->glxpixmap);
      glXWaitGL ();
      impl->glxpixmap = None;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_pixmap_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_x11_gl_drawable_interface_init ()"));

  iface->create_new_context   = _gdk_x11_gl_context_new;
  iface->make_context_current = gdk_x11_gl_pixmap_make_context_current;
  iface->is_double_buffered   = _gdk_gl_pixmap_is_double_buffered;
  iface->swap_buffers         = gdk_x11_gl_pixmap_swap_buffers;
  iface->wait_gl              = _gdk_x11_gl_drawable_wait_gl;
  iface->wait_gdk             = _gdk_x11_gl_drawable_wait_gdk;
  iface->get_gl_config        = _gdk_gl_pixmap_get_gl_config;
}

static gboolean
gdk_x11_gl_pixmap_make_context_current (GdkGLDrawable *draw,
                                        GdkGLDrawable *read,
                                        GdkGLContext  *glcontext)
{
  GdkGLPixmap *glpixmap;
  Display *xdisplay;
  GLXPixmap glxpixmap;
  GLXContext glxcontext;

  g_return_val_if_fail (GDK_IS_GL_PIXMAP (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  glpixmap = GDK_GL_PIXMAP (draw);

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glpixmap->glconfig);
  glxpixmap = GDK_GL_PIXMAP_GLXPIXMAP (glpixmap);
  glxcontext = GDK_GL_CONTEXT_GLXCONTEXT (glcontext);

  if (xdisplay == glXGetCurrentDisplay () &&
      glxpixmap == glXGetCurrentDrawable () &&
      glxcontext == glXGetCurrentContext ())
    return TRUE;

  GDK_GL_NOTE (IMPL, g_message (" * glXMakeCurrent ()"));

  if (!glXMakeCurrent (xdisplay, glxpixmap, glxcontext))
    {
      _gdk_gl_context_set_gl_drawable (glcontext, NULL);
      return FALSE;
    }

  _gdk_gl_context_set_gl_drawable (glcontext, draw);

  if (GDK_GL_CONFIG_AS_SINGLE_MODE(glpixmap->glconfig))
    {
      /* We do this because we are treating a double-buffered frame
         buffer as a single-buffered frame buffer because the system
         does not appear to export any suitable single-buffered
         visuals (in which the following are necessary). */
      glDrawBuffer(GL_FRONT);
      glReadBuffer(GL_FRONT);
    }

  return TRUE;
}

static void
gdk_x11_gl_pixmap_swap_buffers (GdkGLDrawable *gldrawable)
{
  GdkDrawable *drawable;

  g_return_if_fail (GDK_IS_GL_PIXMAP (gldrawable));

  /*
   * XXX GdkGLPixmap is not GdkDrawable for the moment :-<
   *     use glpixmap->wrapper.
   */
  drawable = GDK_GL_PIXMAP (gldrawable)->wrapper;

  GDK_GL_NOTE (IMPL, g_message (" * glXSwapBuffers ()"));

  glXSwapBuffers (GDK_DRAWABLE_XDISPLAY (drawable),
                  GDK_DRAWABLE_XID (drawable));
}

/**
 * gdk_gl_pixmap_new:
 * @glconfig: a #GdkGLConfig.
 * @pixmap: the #GdkPixmap to be used as the rendering area.
 * @attrib_list: this must be set to NULL or empty (first attribute of None).
 *
 * Create an off-screen rendering area.
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 *
 * Return value: the new #GdkGLPixmap.
 **/
GdkGLPixmap *
gdk_gl_pixmap_new (GdkGLConfig *glconfig,
                   GdkPixmap   *pixmap,
                   const gint  *attrib_list)
{
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_new ()"));

  /*
   * Instanciate the GdkGLPixmapImplX11 object.
   */
  glpixmap = g_object_new (GDK_TYPE_GL_PIXMAP_IMPL_X11,
                           "glconfig", glconfig,
                           "wrapper",  GDK_DRAWABLE (pixmap),
                           NULL);
  impl = GDK_GL_PIXMAP_IMPL_X11 (glpixmap);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glpixmap));
      return NULL;
    }

  return glpixmap;
}

/**
 * gdk_x11_gl_pixmap_get_glxpixmap:
 * @glpixmap: a #GdkGLPixmap.
 *
 * Get GLXPixmap.
 *
 * Return value: the GLXPixmap.
 **/
GLXPixmap
gdk_x11_gl_pixmap_get_glxpixmap (GdkGLPixmap *glpixmap)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (glpixmap), None);

  return GDK_GL_PIXMAP_IMPL_X11 (glpixmap)->glxpixmap;
}
