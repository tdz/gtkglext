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

#include "gdkglprivate-x11.h"
#include "gdkglcontext.h"
#include "gdkglpixmap-x11.h"

/* Forward declarations */
static gboolean gdk_x11_gl_pixmap_make_context_current (GdkGLDrawable *draw,
                                                        GdkGLDrawable *read,
                                                        GdkGLContext  *glcontext);

static void gdk_gl_pixmap_impl_x11_init       (GdkGLPixmapImplX11      *impl);
static void gdk_gl_pixmap_impl_x11_class_init (GdkGLPixmapImplX11Class *klass);

static GObject *gdk_gl_pixmap_impl_x11_constructor (GType                  type,
                                                    guint                  n_construct_properties,
                                                    GObjectConstructParam *construct_properties);
static void     gdk_gl_pixmap_impl_x11_finalize    (GObject               *object);

static void gdk_gl_pixmap_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface);

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

  Pixmap xpixmap;
  XVisualInfo *xvinfo;

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

  impl->xdisplay = gdk_x11_gl_config_get_xdisplay (glpixmap->glconfig);
  xvinfo = gdk_x11_gl_config_get_xvinfo (glpixmap->glconfig);

  /*
   * Get X Pixmap.
   */

  /*
   * XXX GdkGLPixmap is not GdkPixmap for the moment :-<
   *     use glpixmap->wrapper.
   */
  xpixmap = gdk_x11_drawable_get_xid (glpixmap->wrapper);

  /*
   * Check depth of the X pixmap.
   */

  if (!XGetGeometry(impl->xdisplay, xpixmap,
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

  impl->glxpixmap = glXCreateGLXPixmap (impl->xdisplay,
                                        xvinfo,
                                        xpixmap);
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
  GdkGLPixmapImplX11 *impl = GDK_GL_PIXMAP_IMPL_X11 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_x11_finalize ()"));

  if (impl->glxpixmap != None)
    {
      glXDestroyGLXPixmap (impl->xdisplay, impl->glxpixmap);
      glXWaitGL ();
      impl->glxpixmap = None;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_pixmap_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_pixmap_impl_x11_gl_drawable_interface_init ()"));

  iface->create_new_context = _gdk_x11_gl_context_new;
  iface->make_context_current = gdk_x11_gl_pixmap_make_context_current;
  iface->swap_buffers = _gdk_x11_gl_drawable_swap_buffers;

  /*< private >*/
  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  iface->real_drawable = _gdk_gl_pixmap_real_drawable;
}

static gboolean
gdk_x11_gl_pixmap_make_context_current (GdkGLDrawable *draw,
                                        GdkGLDrawable *read,
                                        GdkGLContext  *glcontext)
{
  GdkGLPixmapImplX11 *impl;
  GLXContext glxcontext;

  g_return_val_if_fail (GDK_IS_GL_PIXMAP (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  impl = GDK_GL_PIXMAP_IMPL_X11 (draw);

  glxcontext = gdk_x11_gl_context_get_glxcontext (glcontext);

  if (impl->xdisplay == glXGetCurrentDisplay () &&
      impl->glxpixmap == glXGetCurrentDrawable () &&
      glxcontext == glXGetCurrentContext ())
    return TRUE;

  GDK_GL_NOTE (IMPL, g_message (" * glXMakeCurrent ()"));

  if (!glXMakeCurrent (impl->xdisplay, impl->glxpixmap, glxcontext))
    {
      _gdk_gl_context_set_gl_drawable (glcontext, NULL);
      return FALSE;
    }

  _gdk_gl_context_set_gl_drawable (glcontext, draw);

  return TRUE;
}

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 */
GdkGLPixmap *
gdk_gl_pixmap_new (GdkGLConfig *glconfig,
                   GdkPixmap   *pixmap,
                   const gint  *attrib_list)
{
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_pixmap_new ()\n"));

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

Display *
gdk_x11_gl_pixmap_get_xdisplay (GdkGLPixmap *glpixmap)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (glpixmap), NULL);

  return GDK_GL_PIXMAP_IMPL_X11 (glpixmap)->xdisplay;
}

GLXPixmap
gdk_x11_gl_pixmap_get_glxpixmap (GdkGLPixmap *glpixmap)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP (glpixmap), None);

  return GDK_GL_PIXMAP_IMPL_X11 (glpixmap)->glxpixmap;
}
