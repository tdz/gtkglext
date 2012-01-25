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

#include <gdk/gdk.h>

#include "gdkglprivate.h"
#include "gdkglconfig.h"
#include "gdkglwindow.h"

G_DEFINE_TYPE (GdkGLWindow,                     \
               gdk_gl_window,                   \
               G_TYPE_OBJECT)

static void
gdk_gl_window_init (GdkGLWindow *self)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();

  self->window = NULL;
}

static void
gdk_gl_window_finalize (GObject *object)
{
  GdkGLWindow *glwindow = GDK_GL_WINDOW (object);

  GDK_GL_NOTE_FUNC_PRIVATE ();

  if (glwindow->window != NULL)
    g_object_remove_weak_pointer (G_OBJECT (glwindow->window),
                                  (gpointer *) &(glwindow->window));

  G_OBJECT_CLASS (gdk_gl_window_parent_class)->finalize (object);
}

static void
gdk_gl_window_class_init (GdkGLWindowClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE_FUNC_PRIVATE ();

  object_class->finalize = gdk_gl_window_finalize;
}

/**
 * gdk_gl_window_new:
 * @glconfig: a #GdkGLConfig.
 * @window: the #GdkWindow to be used as the rendering area.
 * @attrib_list: this must be set to NULL or empty (first attribute of None).
 *
 * Creates an on-screen rendering area.
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None). See GLX 1.3 spec.
 *
 * Return value: the new #GdkGLWindow.
 **/
GdkGLWindow *
gdk_gl_window_new (GdkGLConfig *glconfig,
                   GdkWindow   *window,
                   const int   *attrib_list)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return GDK_GL_CONFIG_GET_CLASS (glconfig)->create_new_gl_window (glconfig,
                                                                   window,
                                                                   attrib_list);
}

/**
 * gdk_gl_window_get_window:
 * @glwindow: a #GdkGLWindow.
 *
 * Returns the #GdkWindow associated with @glwindow.
 *
 * Return value: the #GdkWindow associated with @glwindow.
 **/
GdkWindow *
gdk_gl_window_get_window (GdkGLWindow *glwindow)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW (glwindow), NULL);

  return glwindow->window;
}

/*
 * OpenGL extension to GdkWindow
 */

static const gchar quark_gl_window_string[] = "gdk-gl-window-gl-window";
static GQuark quark_gl_window = 0;

/**
 * gdk_window_set_gl_capability:
 * @window: the #GdkWindow to be used as the rendering area.
 * @glconfig: a #GdkGLConfig.
 * @attrib_list: this must be set to NULL or empty (first attribute of None).
 *
 * Set the OpenGL-capability to the @window.
 * This function creates a new #GdkGLWindow held by the @window.
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None).
 *
 * Return value: the #GdkGLWindow used by the @window if it is successful,
 *               NULL otherwise.
 **/
GdkGLWindow *
gdk_window_set_gl_capability (GdkWindow   *window,
                              GdkGLConfig *glconfig,
                              const int   *attrib_list)
{
  GdkGLWindow *glwindow;

  GDK_GL_NOTE_FUNC ();

  g_return_val_if_fail (GDK_IS_WINDOW (window), NULL);
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  if (quark_gl_window == 0)
    quark_gl_window = g_quark_from_static_string (quark_gl_window_string);

  /* If already set */
  glwindow = g_object_get_qdata (G_OBJECT (window), quark_gl_window);
  if (glwindow != NULL)
    return glwindow;

  /*
   * Create GdkGLWindow
   */

  glwindow = gdk_gl_window_new (glconfig, window, attrib_list);
  if (glwindow == NULL)
    {
      g_warning ("cannot create GdkGLWindow\n");
      return NULL;
    }

  g_object_set_qdata_full (G_OBJECT (window), quark_gl_window, glwindow,
                           (GDestroyNotify) g_object_unref);

  /*
   * Set a background of "None" on window to avoid AIX X server crash
   */

  GDK_GL_NOTE (MISC,
    g_message (" - window->bg_pixmap = %p",
               (void*)gdk_window_get_background_pattern (window)));

  gdk_window_set_background_pattern (window, NULL);

  GDK_GL_NOTE (MISC,
    g_message (" - window->bg_pixmap = %p",
               (void*)gdk_window_get_background_pattern (window)));

  return glwindow;
}

/**
 * gdk_window_unset_gl_capability:
 * @window: a #GdkWindow.
 *
 * Unset the OpenGL-capability of the @window.
 * This function destroys the #GdkGLWindow held by the @window.
 *
 **/
void
gdk_window_unset_gl_capability (GdkWindow *window)
{
  GdkGLWindow *glwindow;

  GDK_GL_NOTE_FUNC ();

  if (quark_gl_window == 0)
    quark_gl_window = g_quark_from_static_string (quark_gl_window_string);

  /*
   * Destroy OpenGL resources explicitly, then unref.
   */

  glwindow = g_object_get_qdata (G_OBJECT (window), quark_gl_window);
  if (glwindow == NULL)
    return;

  _gdk_gl_window_destroy (glwindow);

  g_object_set_qdata (G_OBJECT (window), quark_gl_window, NULL);
}

/**
 * gdk_window_is_gl_capable:
 * @window: a #GdkWindow.
 *
 * Returns whether the @window is OpenGL-capable.
 *
 * Return value: TRUE if the @window is OpenGL-capable, FALSE otherwise.
 **/
gboolean
gdk_window_is_gl_capable (GdkWindow *window)
{
  g_return_val_if_fail (GDK_IS_WINDOW (window), FALSE);

  return g_object_get_qdata (G_OBJECT (window), quark_gl_window) != NULL ? TRUE : FALSE;
}

/**
 * gdk_window_get_gl_window:
 * @window: a #GdkWindow.
 *
 * Returns the #GdkGLWindow held by the @window.
 *
 * Return value: the #GdkGLWindow.
 **/
GdkGLWindow *
gdk_window_get_gl_window (GdkWindow *window)
{
  g_return_val_if_fail (GDK_IS_WINDOW (window), NULL);

  return g_object_get_qdata (G_OBJECT (window), quark_gl_window);
}
