/* GtkGLExt - OpenGL Extension to GTK+
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

#include <gtk/gtkmain.h>

#include "gtkglprivate.h"
#include "gtkglwidget.h"

gboolean gtk_gl_widget_install_toplevel_cmap = FALSE;

static const gchar quark_param_string[] = "gtk-gl-widget-param";
static GQuark quark_param = 0;

static const gchar quark_gl_config_string[] = "gtk-gl-widget-gl-config";
static GQuark quark_gl_config = 0;

static const gchar quark_gl_context_string[] = "gtk-gl-widget-gl-context";
static GQuark quark_gl_context = 0;

static void
param_destroy (GtkGLWidgetParam *param)
{
  GTK_GL_NOTE (FUNC, g_message (" - param_destroy ()"));

  if (param != NULL)
    g_boxed_free (GTK_TYPE_GL_WIDGET_PARAM, (gpointer) param);
}

/* 
 * Signal handlers.
 */

static void
gtk_widget_gl_realize (GtkWidget *widget,
                       gpointer   user_data)
{
  GtkGLWidgetParam *param;
  GdkGLWindow *glwindow;

  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_realize ()"));

  /* Already OpenGL-capable */
  if (gdk_window_is_gl_capable (widget->window))
    return;

  /* Get param */
  param = g_object_get_qdata (G_OBJECT (widget), quark_param);
  if (param == NULL)
    return;

  /*
   * Set OpenGL-capability to widget->window.
   */

  glwindow = gdk_window_set_gl_capability (widget->window,
                                           param->glconfig,
                                           NULL);
  if (glwindow == NULL)
    g_warning ("cannot set OpenGL-capability to widget->window\n");
}

static gboolean
gtk_widget_gl_configure_event (GtkWidget         *widget,
                               GdkEventConfigure *event,
                               gpointer           user_data)
{
  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_configure_event ()"));

  /* Realize. */
  gtk_widget_gl_realize (widget, user_data);

  /*
   * Once OpenGL-capable widget is realized,
   * this callback is no longer needed.
   */
  g_signal_handlers_disconnect_by_func (widget,
                                        G_CALLBACK (gtk_widget_gl_configure_event),
                                        NULL);

  return FALSE;
}

static void
gtk_widget_gl_unrealize (GtkWidget *widget,
                         gpointer   user_data)
{
  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_unrealize ()"));

  /*
   * Remove OpenGL-capability from widget->window.
   */

  if (widget->window != NULL)
    gdk_window_unset_gl_capability (widget->window);
}

static void
gtk_widget_gl_parent_set (GtkWidget   *widget,
                          GtkObject   *old_parent,
                          GdkColormap *colormap)
{
  GtkWidget *toplevel;

  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_parent_set ()"));

  toplevel = gtk_widget_get_toplevel (widget);
  if (GTK_WIDGET_TOPLEVEL (toplevel))
    {
      GTK_GL_NOTE (MISC,
        g_message (" - Install colormap to the top-level window."));

      gtk_widget_set_colormap (toplevel, colormap);
    }
}

/**
 * gtk_widget_set_gl_capability:
 * @widget: the #GtkWidget to be used as the rendering area.
 * @glconfig: a #GdkGLConfig.
 * @share_list: the #GdkGLContext which to share display lists. NULL indicates that no sharing is to take place.
 * @direct: whether rendering is to be done with a direct connection to the graphics system.
 * @render_type: GDK_GL_RGBA_TYPE or GDK_GL_COLOR_INDEX_TYPE (currently not used).
 *
 * Set the OpenGL-capability to the @widget.
 * This function prepares the widget for its use with OpenGL.
 *
 * Return value: TRUE if it is successful, FALSE otherwise.
 **/
gboolean
gtk_widget_set_gl_capability (GtkWidget    *widget,
                              GdkGLConfig  *glconfig,
                              GdkGLContext *share_list,
                              gboolean      direct,
                              int           render_type)
{
  GdkColormap *colormap;
  GtkGLWidgetParam param;

  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_set_gl_capability ()"));

  g_return_val_if_fail (GTK_IS_WIDGET (widget), FALSE);
  g_return_val_if_fail (!GTK_WIDGET_REALIZED (widget), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  /* 
   * Init quarks.
   */

  if (quark_param == 0)
    quark_param = g_quark_from_static_string (quark_param_string);

  if (quark_gl_config == 0)
    quark_gl_config = g_quark_from_static_string (quark_gl_config_string);

  if (quark_gl_context == 0)
    quark_gl_context = g_quark_from_static_string (quark_gl_context_string);

  /*
   * Already OpenGL-capable?
   */

  if (g_object_get_qdata (G_OBJECT (widget), quark_gl_config) != NULL)
    return TRUE;

  /*
   * Set OpenGL-capable visual configuration.
   */

  g_object_set_qdata_full (G_OBJECT (widget), quark_gl_config, glconfig,
                           (GDestroyNotify) g_object_unref);
  g_object_ref (G_OBJECT (glconfig));

  /*
   * Set OpenGL-capable colormap.
   */

  colormap = gdk_gl_config_get_colormap (glconfig);

  gtk_widget_set_colormap (widget, colormap);

  /* Install colormap to the top-level window. */
  if (gtk_gl_widget_install_toplevel_cmap)
    {
      /*
       * If window manager doesn't watch the WM_COLORMAP_WINDOWS property on
       * the top-level window, we have to set OpenGL window's colormap to the
       * top-level window, especially in color index mode (color index mode
       * uses own private colormap).
       */

      /* Signal handler to set colormap to the top-level window. */
      g_signal_connect (G_OBJECT (widget), "parent_set",
                        G_CALLBACK (gtk_widget_gl_parent_set),
                        colormap);

      /* If given widget has the top-level window, colormap is set here. */
      gtk_widget_gl_parent_set (widget, NULL, colormap);
    }

  /*
   * Disable backing store feature of the widget.
   */

  gtk_widget_set_double_buffered (widget, FALSE);

  /*
   * Set given GL widget parameters.
   */

  param.glconfig = glconfig;
  param.share_list = share_list;
  param.direct = direct;
  param.render_type = render_type;

  g_object_set_qdata_full (G_OBJECT (widget), quark_param,
                           g_boxed_copy (GTK_TYPE_GL_WIDGET_PARAM, (gconstpointer) &param),
                           (GDestroyNotify) param_destroy);

  /*
   * Signal handler for realizing a OpenGL-capable GdkWindow.
   */

  g_signal_connect (G_OBJECT (widget), "realize",
		    G_CALLBACK (gtk_widget_gl_realize),
                    NULL);

  /* gtk_drawing_area sends configure_event when it is realized. */
  g_signal_connect (G_OBJECT (widget), "configure_event",
                    G_CALLBACK (gtk_widget_gl_configure_event),
                    NULL);

  g_signal_connect (G_OBJECT (widget), "unrealize",
		    G_CALLBACK (gtk_widget_gl_unrealize),
                    NULL);

  /*
   * Destroy the OpenGL-capable widget on quit
   * in order to destroy the OpenGL rendering context explicitly.
   */

  gtk_quit_add_destroy (gtk_main_level () + 1, GTK_OBJECT (widget));

  return TRUE;
}

/**
 * gtk_widget_is_gl_capable:
 * @widget: a #GtkWidget.
 *
 * Returns whether the @widget is OpenGL-capable.
 *
 * This function is useful to check if a widget is OpenGL-capable (i.e if
 * it is possible to use OpenGL functions to draw on it).
 *
 * Return value: TRUE if the @widget is OpenGL-capable, FALSE otherwise.
 **/
gboolean
gtk_widget_is_gl_capable (GtkWidget *widget)
{
  return (gtk_widget_get_gl_config (widget) != NULL) ? TRUE : FALSE;
}

/**
 * gtk_widget_get_gl_config:
 * @widget: a #GtkWidget.
 *
 * Returns the #GdkGLConfig referred by the @widget.
 *
 * This returns a GdkGLConfig with the OpenGL configuration of the widget.
 *
 * Return value: the #GdkGLConfig.
 **/
GdkGLConfig *
gtk_widget_get_gl_config (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_IS_WIDGET (widget), NULL);

  return g_object_get_qdata (G_OBJECT (widget), quark_gl_config);
}

/**
 * gtk_widget_create_gl_context:
 * @widget: a #GtkWidget.
 * @share_list: the #GdkGLContext which to share display lists. NULL indicates that no sharing is to take place.
 * @direct: whether rendering is to be done with a direct connection to the graphics system.
 * @render_type: GDK_GL_RGBA_TYPE or GDK_GL_COLOR_INDEX_TYPE (currently not used).
 *
 * Creates a new #GdkGLContext with the appropriate #GdkGLDrawable
 * for this widget. The GL context must be freed when you're
 * finished with it. See also gtk_widget_get_gl_context().
 *
 * Return value: the new #GdkGLContext.
 **/
GdkGLContext *
gtk_widget_create_gl_context (GtkWidget    *widget,
                              GdkGLContext *share_list,
                              gboolean      direct,
                              int           render_type)
{
  GdkGLDrawable *gldrawable;
  GdkGLConfig *glconfig;
  GdkGLContext *glcontext;

  g_return_val_if_fail (GTK_IS_WIDGET (widget), NULL);
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  gldrawable = gdk_window_get_gl_drawable (widget->window);
  if (gldrawable == NULL)
    return NULL;

  glconfig = gdk_gl_drawable_get_gl_config (gldrawable);

  /*
   * Create OpenGL rendering context.
   */

  glcontext = gdk_gl_context_new (gldrawable,
                                  glconfig,
                                  share_list,
                                  direct,
                                  render_type);
  if (glcontext == NULL)
    {
      g_warning ("cannot create GdkGLContext\n");
      return NULL;
    }

  return glcontext;
}

/**
 * gtk_widget_get_gl_context:
 * @widget: a #GtkWidget.
 *
 * Returns the #GdkGLContext with the appropriate #GdkGLDrawable
 * for this widget. Unlike the GL context returned by
 * gtk_widget_create_gl_context(),  this context is owned by the widget.
 *
 * #GdkGLContext is needed for the function gdk_gl_drawable_begin,
 * or for sharing display lists
 * (see gtk_widget_set_gl_capability()).
 *
 * Return value: the #GdkGLContext.
 **/
GdkGLContext *
gtk_widget_get_gl_context (GtkWidget *widget)
{
  GdkGLContext *glcontext;
  GtkGLWidgetParam *param;

  g_return_val_if_fail (GTK_IS_WIDGET (widget), NULL);
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  glcontext = g_object_get_qdata (G_OBJECT (widget), quark_gl_context);
  if (glcontext == NULL)
    {
      /* Get param */
      param = g_object_get_qdata (G_OBJECT (widget), quark_param);
      if (param == NULL)
        return NULL;

      glcontext = gtk_widget_create_gl_context (widget,
                                                param->share_list,
                                                param->direct,
                                                param->render_type);

      g_object_set_qdata_full (G_OBJECT (widget), quark_gl_context, glcontext,
                               (GDestroyNotify) g_object_unref);
    }

  return glcontext;
}

/**
 * gtk_widget_get_gl_window:
 * @widget: a #GtkWidget.
 *
 * Returns the #GdkGLWindow owned by the @widget.
 *
 * Return value: the #GdkGLWindow.
 **/
GdkGLWindow *
gtk_widget_get_gl_window (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_IS_WIDGET (widget), NULL);
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  return gdk_window_get_gl_window (widget->window);
}
