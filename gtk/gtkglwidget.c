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

static const gchar quark_gl_capable_string[] = "gtk-gl-widget-gl-capable";
static GQuark quark_gl_capable = 0;

static const gboolean gl_capable = TRUE;

static gboolean
gtk_widget_destroy_gl_context (GtkWidget *widget)
{
  if (widget->window != NULL)
    gdk_window_unset_gl_capability (widget->window);

  return FALSE;
}

static void
gtk_widget_gl_realize (GtkWidget        *widget,
                       GtkGLWidgetParam *param)
{
  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_realize ()"));

  if (gdk_window_set_gl_capability (widget->window,
                                    param->glconfig,
                                    param->render_type,
                                    param->share_list,
                                    param->direct,
                                    (const gint *) (param->attrib_list)))
    {
      if (quark_gl_capable == 0)
        quark_gl_capable = g_quark_from_static_string (quark_gl_capable_string);

      g_object_set_qdata (G_OBJECT (widget), quark_gl_capable,
                          (gpointer) &gl_capable);

      /* Destroy OpenGL rendering context explicitly. */
      gtk_quit_add (0, (GtkFunction) gtk_widget_destroy_gl_context, widget);
    }
}

static gboolean
gtk_widget_gl_configure_event (GtkWidget         *widget,
                               GdkEventConfigure *event,
                               GtkGLWidgetParam  *param)
{
  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_gl_configure_event ()"));

  if (gdk_window_set_gl_capability (widget->window,
                                    param->glconfig,
                                    param->render_type,
                                    param->share_list,
                                    param->direct,
                                    (const gint *) (param->attrib_list)))
    {
      if (quark_gl_capable == 0)
        quark_gl_capable = g_quark_from_static_string (quark_gl_capable_string);

      g_object_set_qdata (G_OBJECT (widget), quark_gl_capable,
                          (gpointer) &gl_capable);

      /* Destroy OpenGL rendering context explicitly. */
      gtk_quit_add (0, (GtkFunction) gtk_widget_destroy_gl_context, widget);
    }

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

  if (quark_gl_capable == 0)
    return;

  if (g_object_get_qdata (G_OBJECT (widget), quark_gl_capable) != NULL)
    {
      gdk_window_unset_gl_capability (widget->window);
      gtk_quit_remove_by_data (widget);
    }
}

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None).
 */
gboolean
gtk_widget_set_gl_capability (GtkWidget    *widget,
                              GdkGLConfig  *glconfig,
                              gint          render_type,
                              GdkGLContext *share_list,
                              gboolean      direct,
                              const gint   *attrib_list)
{
  const GtkGLWidgetParam param = { glconfig,
                                   render_type,
                                   share_list,
                                   direct,
                                   (gint *) attrib_list };

  GTK_GL_NOTE (FUNC, g_message (" - gtk_widget_set_gl_capability ()"));

  g_return_val_if_fail (GTK_IS_WIDGET (widget), FALSE);
  g_return_val_if_fail (!GTK_WIDGET_REALIZED (widget), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

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

gboolean
gtk_widget_is_gl_capable (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), FALSE);

  return gdk_window_is_gl_capable (widget->window);
}

GdkGLConfig *
gtk_widget_get_gl_config (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  return gdk_window_get_gl_config (widget->window);
}

GdkGLContext *
gtk_widget_get_gl_context (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  return gdk_window_get_gl_context (widget->window);
}

GdkGLWindow *
gtk_widget_get_gl_window (GtkWidget *widget)
{
  g_return_val_if_fail (GTK_WIDGET_REALIZED (widget), NULL);

  return gdk_window_get_gl_window (widget->window);
}
