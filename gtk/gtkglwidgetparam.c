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

#include "gtkglprivate.h"
#include "gtkglwidgetparam.h"

static GtkGLWidgetParam *gtk_gl_widget_param_copy (GtkGLWidgetParam *param);
static void              gtk_gl_widget_param_free (GtkGLWidgetParam *param);

static GMemChunk *param_chunk = NULL;

GType
gtk_gl_widget_param_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_boxed_type_register_static ("GtkGLWidgetParam",
                                         (GBoxedCopyFunc) gtk_gl_widget_param_copy,
                                         (GBoxedFreeFunc) gtk_gl_widget_param_free);

  return type;
}

static GtkGLWidgetParam *
gtk_gl_widget_param_copy (GtkGLWidgetParam *param)
{
  GtkGLWidgetParam *new_param;
  
  g_return_val_if_fail (param != NULL, NULL);

  if (param_chunk == NULL)
    param_chunk = g_mem_chunk_new ("gtk-gl-widget-param",
				   sizeof (GtkGLWidgetParam),
				   4096,
				   G_ALLOC_AND_FREE);

  new_param = g_chunk_new (GtkGLWidgetParam, param_chunk);
  *new_param = *param;

  return new_param;
}

static void
gtk_gl_widget_param_free (GtkGLWidgetParam *param)
{
  g_assert (param_chunk != NULL);
  g_return_if_fail (param != NULL);

  g_mem_chunk_free (param_chunk, param);
}
