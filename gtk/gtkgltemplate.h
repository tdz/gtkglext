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

#ifndef __GTK_GL_TEMPLATE_H__
#define __GTK_GL_TEMPLATE_H__

#include <gdk/gdk.h>

#include <gdk/gdkgl.h>

G_BEGIN_DECLS

typedef struct _GtkGLTemplate      GtkGLTemplate;
typedef struct _GtkGLTemplateClass GtkGLTemplateClass;

#define GTK_TYPE_GL_TEMPLATE              (gtk_gl_template_get_type ())
#define GTK_GL_TEMPLATE(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GTK_TYPE_GL_TEMPLATE, GtkGLTemplate))
#define GTK_GL_TEMPLATE_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GTK_TYPE_GL_TEMPLATE, GtkGLTemplateClass))
#define GTK_IS_GL_TEMPLATE(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GTK_TYPE_GL_TEMPLATE))
#define GTK_IS_GL_TEMPLATE_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GTK_TYPE_GL_TEMPLATE))
#define GTK_GL_TEMPLATE_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GTK_TYPE_GL_TEMPLATE, GtkGLTemplateClass))

struct _GtkGLTemplate
{
  GObject parent_instance;
};

struct _GtkGLTemplateClass
{
  GObjectClass parent_class;
};

GType         gtk_gl_template_get_type (void);

G_END_DECLS

#endif /* __GTK_GL_TEMPLATE_H__ */
