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
#include "gtkgltemplate.h"

static void gtk_gl_template_init       (GtkGLTemplate      *gltemplate);
static void gtk_gl_template_class_init (GtkGLTemplateClass *klass);
static void gtk_gl_template_finalize   (GObject            *object);

static gpointer parent_class = NULL;

GType
gtk_gl_template_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GtkGLTemplateClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gtk_gl_template_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GtkGLTemplate),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gtk_gl_template_init,
      };

      type = g_type_register_static (G_TYPE_OBJECT,
                                     "GtkGLTemplate",
                                     &type_info, 0);
    }

  return type;
}

static void
gtk_gl_template_init (GtkGLTemplate *gltemplate)
{
  /* 0-initialization is good for all other fields. */

  GTK_GL_NOTE (FUNC, g_message (" - gtk_gl_template_init ()"));
}

static void
gtk_gl_template_class_init (GtkGLTemplateClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GTK_GL_NOTE (FUNC, g_message (" - gtk_gl_template_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->finalize = gtk_gl_template_finalize;
}

static void
gtk_gl_template_finalize (GObject *object)
{
  GtkGLTemplate *gltemplate = GTK_GL_TEMPLATE (object);

  GTK_GL_NOTE (FUNC, g_message (" - gtk_gl_template_finalize ()"));

  G_OBJECT_CLASS (parent_class)->finalize (object);
}
