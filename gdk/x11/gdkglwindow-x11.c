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
#include "gdkglwindow-x11.h"

/* Forward declarations */
static gboolean gdk_x11_gl_window_make_context_current (GdkGLDrawable           *draw,
                                                        GdkGLDrawable           *read,
                                                        GdkGLContext            *glcontext);

static void     gdk_gl_window_impl_x11_init            (GdkGLWindowImplX11      *impl);
static void     gdk_gl_window_impl_x11_class_init      (GdkGLWindowImplX11Class *klass);

static GObject *gdk_gl_window_impl_x11_constructor     (GType                    type,
                                                        guint                    n_construct_properties,
                                                        GObjectConstructParam   *construct_properties);
static void     gdk_gl_window_impl_x11_finalize        (GObject                 *object);

static void     gdk_gl_window_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface);

static gpointer parent_class = NULL;

GType
gdk_gl_window_impl_x11_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLWindowImplX11Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_window_impl_x11_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLWindowImplX11),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_window_impl_x11_init,
      };
      static const GInterfaceInfo gl_drawable_interface_info = {
        (GInterfaceInitFunc) gdk_gl_window_impl_x11_gl_drawable_interface_init,
        (GInterfaceFinalizeFunc) NULL,
        NULL                    /* interface_data */
      };

      type = g_type_register_static (GDK_TYPE_GL_WINDOW,
                                     "GdkGLWindowImplX11",
                                     &type_info, 0);
      g_type_add_interface_static (type,
                                   GDK_TYPE_GL_DRAWABLE,
                                   &gl_drawable_interface_info);
    }

  return type;
}

static void
gdk_gl_window_impl_x11_init (GdkGLWindowImplX11 *impl)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_window_impl_x11_class_init (GdkGLWindowImplX11Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor = gdk_gl_window_impl_x11_constructor;
  object_class->finalize    = gdk_gl_window_impl_x11_finalize;
}

static GObject *
gdk_gl_window_impl_x11_constructor (GType                  type,
                                    guint                  n_construct_properties,
                                    GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLWindow *glwindow;
  GdkGLWindowImplX11 *impl;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_constructor ()"));

  glwindow = GDK_GL_WINDOW (object);
  impl = GDK_GL_WINDOW_IMPL_X11 (object);

  /*
   * XXX GdkGLWindow is not GdkWindow for the moment :-<
   *     use glwindow->wrapper.
   */
  impl->xdisplay = gdk_x11_drawable_get_xdisplay (glwindow->wrapper);
  impl->glxwindow = gdk_x11_drawable_get_xid (glwindow->wrapper);

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

  return object;
}

static void
gdk_gl_window_impl_x11_finalize (GObject *object)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_finalize ()"));

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_window_impl_x11_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_window_impl_x11_gl_drawable_interface_init ()"));

  iface->create_new_context   = _gdk_x11_gl_context_new;
  iface->make_context_current = gdk_x11_gl_window_make_context_current;
  iface->swap_buffers         = _gdk_x11_gl_drawable_swap_buffers;

  /*< private >*/
  /* XXX GdkGLDrawable is not GdkDrawable for the moment :-< */
  iface->real_drawable        = _gdk_gl_window_real_drawable;
}

static gboolean
gdk_x11_gl_window_make_context_current (GdkGLDrawable *draw,
                                        GdkGLDrawable *read,
                                        GdkGLContext  *glcontext)
{
  GdkGLWindowImplX11 *impl;
  GLXContext glxcontext;

  g_return_val_if_fail (GDK_IS_GL_WINDOW (draw), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  impl = GDK_GL_WINDOW_IMPL_X11 (draw);

  glxcontext = gdk_x11_gl_context_get_glxcontext (glcontext);

  if (impl->xdisplay == glXGetCurrentDisplay () &&
      impl->glxwindow == glXGetCurrentDrawable () &&
      glxcontext == glXGetCurrentContext ())
    return TRUE;

  GDK_GL_NOTE (IMPL, g_message (" * glXMakeCurrent ()"));

  if (!glXMakeCurrent (impl->xdisplay, impl->glxwindow, glxcontext))
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
/**
 * gdk_gl_window_new:
 * @glconfig: a #GdkGLConfig.
 * @window: the #GdkWindow to be used as the rendering area.
 * @attrib_list: this must be set to NULL or empty (first attribute of None).
 *
 * Create an on-screen rendering area.
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 *
 * Return value: the new #GdkGLWindow.
 **/
GdkGLWindow *
gdk_gl_window_new (GdkGLConfig *glconfig,
                   GdkWindow   *window,
                   const gint  *attrib_list)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_window_new ()"));

  /*
   * Instanciate the GdkGLWindowImplX11 object.
   */
  glwindow = g_object_new (GDK_TYPE_GL_WINDOW_IMPL_X11,
                           "glconfig", glconfig,
                           "wrapper",  GDK_DRAWABLE (window),
                           NULL);
  impl = GDK_GL_WINDOW_IMPL_X11 (glwindow);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glwindow));
      return NULL;
    }

  return glwindow;
}

Display *
gdk_x11_gl_window_get_xdisplay (GdkGLWindow *glwindow)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (glwindow), NULL);

  return GDK_GL_WINDOW_IMPL_X11 (glwindow)->xdisplay;
}

Window
gdk_x11_gl_window_get_glxwindow (GdkGLWindow *glwindow)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (glwindow), None);

  return GDK_GL_WINDOW_IMPL_X11 (glwindow)->glxwindow;
}
