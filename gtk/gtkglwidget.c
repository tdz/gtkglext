/* GtkGLExt - OpenGL Extension to GTK+
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

#include <gtk/gtkmain.h>

#include "gtkglprivate.h"
#include "gtkglwidget.h"

static const gchar quark_gl_config_string[] = "gtk-gl-widget-gl-config";
static GQuark quark_gl_config = 0;

static const gchar quark_gl_context_string[] = "gtk-gl-widget-gl-context";
static GQuark quark_gl_context = 0;

static void
gl_config_destroy (GdkGLConfig *glconfig)
{
  if (glconfig != NULL)
    g_object_unref (G_OBJECT (glconfig));
}

static void
gl_context_destroy (GdkGLContext *glcontext)
{
  if (glcontext != NULL)
    g_object_unref (G_OBJECT (glcontext));
}

static gboolean
gtk_widget_destroy_gl_context (GtkWidget *widget)
{
  if (widget->window != NULL)
    gdk_window_unset_gl_capability (widget->window);

  if (quark_gl_config != 0)
    g_object_set_qdata (G_OBJECT (widget), quark_gl_config, NULL);

  if (quark_gl_context != 0)
    g_object_set_qdata (G_OBJECT (widget), quark_gl_context, NULL);

  return FALSE;
}

static void
gtk_widget_gl_realize (GtkWidget        *widget,
                       GtkGLWidgetParam *param)
{
  GdkGLWindow *glwindow;
  GdkGLContext *glcontext;

  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_realize ()"));

  if (quark_gl_context == 0)
    quark_gl_context = g_quark_from_static_string (quark_gl_context_string);

  /* Already OpenGL-capable */
  if (g_object_get_qdata (G_OBJECT (widget), quark_gl_context) != NULL)
    return;

  /*
   * Set OpenGL-capability to widget->window.
   */

  gdk_window_set_gl_capability (widget->window,
                                param->glconfig,
                                NULL);

  glwindow = gdk_window_get_gl_window (widget->window);

  /*
   * Create OpenGL rendering context.
   */

  glcontext = gdk_gl_context_new (GDK_GL_DRAWABLE (glwindow),
                                  param->glconfig,
                                  param->render_type,
                                  param->share_list,
                                  param->direct);
  if (glcontext == NULL)
    {
      g_warning ("cannot create GdkGLContext\n");
      return;
    }

  g_object_set_qdata_full (G_OBJECT (widget), quark_gl_context, glcontext,
                           (GDestroyNotify) gl_context_destroy);

  /* Destroy OpenGL rendering context explicitly. */
  gtk_quit_add (gtk_main_level () + 1,
                (GtkFunction) gtk_widget_destroy_gl_context, widget);
}

static gboolean
gtk_widget_gl_configure_event (GtkWidget         *widget,
                               GdkEventConfigure *event,
                               GtkGLWidgetParam  *param)
{
  GdkGLWindow *glwindow;
  GdkGLContext *glcontext;

  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_configure_event ()"));

  if (quark_gl_context == 0)
    quark_gl_context = g_quark_from_static_string (quark_gl_context_string);

  /* Already OpenGL-capable */
  if (g_object_get_qdata (G_OBJECT (widget), quark_gl_context) != NULL)
    goto DONE;

  /*
   * Set OpenGL-capability to widget->window.
   */

  gdk_window_set_gl_capability (widget->window,
                                param->glconfig,
                                NULL);

  glwindow = gdk_window_get_gl_window (widget->window);

  /*
   * Create OpenGL rendering context.
   */

  glcontext = gdk_gl_context_new (GDK_GL_DRAWABLE (glwindow),
                                  param->glconfig,
                                  param->render_type,
                                  param->share_list,
                                  param->direct);
  if (glcontext == NULL)
    {
      g_warning ("cannot create GdkGLContext\n");
      goto DONE;
    }

  g_object_set_qdata_full (G_OBJECT (widget), quark_gl_context, glcontext,
                           (GDestroyNotify) gl_context_destroy);

  /* Destroy OpenGL rendering context explicitly. */
  gtk_quit_add (gtk_main_level () + 1,
                (GtkFunction) gtk_widget_destroy_gl_context, widget);

 DONE:

#if 1
  g_signal_handlers_disconnect_by_func (widget,
                                        G_CALLBACK (gtk_widget_gl_configure_event),
                                        (gpointer) param);
#endif

  return FALSE;
}

static void
gtk_widget_gl_unrealize (GtkWidget *widget,
                         gpointer   data)
{
  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_unrealize ()"));

  if (quark_gl_context == 0)
    return;

  if (g_object_get_qdata (G_OBJECT (widget), quark_gl_context) != NULL)
    {
      gdk_window_unset_gl_capability (widget->window);
      g_object_set_qdata (G_OBJECT (widget), quark_gl_context, NULL);
      gtk_quit_remove_by_data (widget);
    }
}

/**
 * gtk_widget_set_gl_capability:
 * @widget: the #GtkWidget to be used as the rendering area.
 * @glconfig: a #GdkGLConfig.
 * @render_type: GDK_GL_RGBA_TYPE or GDK_GL_COLOR_INDEX_TYPE (currently not used).
 * @share_list: the #GdkGLContext which to share display lists. NULL indicates that no sharing is to take place.
 * @direct: whether rendering is to be done with a direct connection to the graphics system.
 *
 * Set the OpenGL-capability to the #GtkWidget.
 * The call setup the callbacks to realize a OpenGL-capable window.
 *
 * Return value: TRUE if it is successful, FALSE otherwise.
 **/
gboolean
gtk_widget_set_gl_capability (GtkWidget    *widget,
                              GdkGLConfig  *glconfig,
                              gint          render_type,
                              GdkGLContext *share_list,
                              gboolean      direct)
{
  GtkGLWidgetParam param;

  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_set_gl_capability ()"));

  g_return_val_if_fail (GTK_IS_WIDGET (widget), FALSE);
  g_return_val_if_fail (!GTK_WIDGET_REALIZED (widget), FALSE);

  /*
   * Set OpenGL-capable visual configuration.
   */

  if (quark_gl_config == 0)
    quark_gl_config = g_quark_from_static_string (quark_gl_config_string);

  g_object_set_qdata_full (G_OBJECT (widget), quark_gl_config, glconfig,
                           (GDestroyNotify) gl_config_destroy);
  g_object_ref (G_OBJECT (glconfig));

  /*
   * Set OpenGL-capable colormap.
   */

  gtk_widget_set_colormap (widget, gdk_gl_config_get_colormap (glconfig));

  /*
   * Disable backing store feature of the widget.
   */

  gtk_widget_set_double_buffered (widget, FALSE);

  /*
   * Signal handler for realizing a OpenGL-capable GdkWindow.
   */

  param.glconfig = glconfig;
  param.render_type = render_type;
  param.share_list = share_list;
  param.direct = direct;

  g_signal_connect (G_OBJECT (widget), "realize",
		    G_CALLBACK (gtk_widget_gl_realize),
                    g_boxed_copy (GTK_TYPE_GL_WIDGET_PARAM, (gconstpointer) &param));

  /* gtk_drawing_area sends configure_event when it is realized. */
  g_signal_connect (G_OBJECT (widget), "configure_event",
                    G_CALLBACK (gtk_widget_gl_configure_event),
                    g_boxed_copy (GTK_TYPE_GL_WIDGET_PARAM, (gconstpointer) &param));

  g_signal_connect (G_OBJECT (widget), "unrealize",
		    G_CALLBACK (gtk_widget_gl_unrealize),
                    NULL);

  return TRUE;
}

/**
 * gtk_widget_is_gl_capable:
 * @widget: a #GtkWidget.
 *
 * Return whether the #GtkWidget is OpenGL-capable.
 *
 * Return value: TRUE if the #GtkWidget is OpenGL-capable, FALSE otherwise.
 **/
gboolean
gtk_widget_is_gl_capable (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), FALSE);

  return g_object_get_qdata (G_OBJECT (widget), quark_gl_context) != NULL ? TRUE : FALSE;
}

/**
 * gtk_widget_get_gl_config:
 * @widget: a #GtkWidget.
 *
 * Return the #GdkGLConfig referred by the #GtkWidget.
 *
 * Return value: the #GdkGLConfig.
 **/
GdkGLConfig *
gtk_widget_get_gl_config (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  return g_object_get_qdata (G_OBJECT (widget), quark_gl_config);
}

/**
 * gtk_widget_get_gl_context:
 * @widget: a #GtkWidget.
 *
 * Return the #GdkGLContext holded by the #GtkWidget.
 *
 * Return value: the #GdkGLContext.
 **/
GdkGLContext *
gtk_widget_get_gl_context (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  return g_object_get_qdata (G_OBJECT (widget), quark_gl_context);
}

/**
 * gtk_widget_get_gl_window:
 * @widget: a #GtkWidget.
 *
 * Return the #GdkGLWindow holded by the #GtkWidget.
 *
 * Return value: the #GdkGLWindow.
 **/
GdkGLWindow *
gtk_widget_get_gl_window (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  return gdk_window_get_gl_window (widget->window);
}
