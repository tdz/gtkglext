/* GdkGLExt - OpenGL Extension to GDK
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

#include "gdkglprivate-x11.h"
#include "gdkgltemplate-x11.h"

static void gdk_gl_template_impl_x11_init       (GdkGLTemplateImplX11      *impl);
static void gdk_gl_template_impl_x11_class_init (GdkGLTemplateImplX11Class *klass);
static void gdk_gl_template_impl_x11_finalize   (GObject                   *object);

static gpointer parent_class = NULL;

GType
gdk_gl_template_impl_x11_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLTemplateImplX11Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_template_impl_x11_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLTemplateImplX11),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_template_impl_x11_init,
      };

      type = g_type_register_static (G_TYPE_OBJECT,
                                     "GdkGLTemplateImplX11",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_template_impl_x11_init (GdkGLTemplateImplX11 *impl)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_template_impl_x11_init ()"));
}

static void
gdk_gl_template_impl_x11_class_init (GdkGLTemplateImplX11Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_template_impl_x11_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->finalize = gdk_gl_template_impl_x11_finalize;
}

static void
gdk_gl_template_impl_x11_finalize (GObject *object)
{
  GdkGLTemplateImplX11 *impl = GDK_GL_TEMPLATE_IMPL_X11 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_template_impl_x11_finalize ()"));

  G_OBJECT_CLASS (parent_class)->finalize (object);
}
