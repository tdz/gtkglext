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

#ifndef __GTK_GL_WIDGET_H__
#define __GTK_GL_WIDGET_H__

#include <gdk/gdk.h>

#include <gdk/gdkgl.h>

#include <gtk/gtkwidget.h>

G_BEGIN_DECLS

/*
 * attrib_list is currently unused. This must be set to NULL or empty
 * (first attribute of None).
 */
gboolean      gtk_widget_set_gl_capability (GtkWidget    *widget,
                                            const gint   *attrib_list,
                                            gint          render_type,
                                            GdkGLContext *share_list,
                                            gboolean      direct);

gboolean      gtk_widget_is_gl_capable     (GtkWidget    *widget);


GdkGLConfig  *gtk_widget_get_gl_config     (GtkWidget    *widget);

GdkGLContext *gtk_widget_get_gl_context    (GtkWidget    *widget);

GdkGLWindow  *gtk_widget_get_gl_window     (GtkWidget    *widget);

#define       gtk_widget_get_gl_drawable(widget)        \
  GDK_GL_DRAWABLE (gtk_widget_get_gl_window (widget))


#define       gtk_widget_gl_make_current(widget)                        \
  gdk_gl_drawable_make_current (gtk_widget_get_gl_drawable (widget),    \
                                gtk_widget_get_gl_context (widget))

#define       gtk_widget_gl_is_double_buffer(widget)                    \
  gdk_gl_config_is_double_buffer (gtk_widget_get_gl_config (widget))

#define       gtk_widget_gl_swap_buffers(widget)                        \
  gdk_gl_drawable_swap_buffers (gtk_widget_get_gl_drawable (widget))


#define       gtk_widget_gl_begin(widget)				\
  do									\
    {									\
      if (gtk_widget_gl_make_current (widget))				\
        {								\
          gdk_gl_drawable_wait_gdk (gtk_widget_get_gl_drawable(widget))

#define       gtk_widget_gl_end(widget)					\
          gdk_gl_drawable_wait_gl (gtk_widget_get_gl_drawable(widget));	\
        }								\
    }									\
  while (0)


G_END_DECLS

#endif /* __GTK_GL_WIDGET_H__ */
