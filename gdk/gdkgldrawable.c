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

#include "gdkglprivate.h"
#include "gdkgldrawable.h"

GType
gdk_gl_drawable_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLDrawableClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL
      };

      type = g_type_register_static (G_TYPE_INTERFACE,
                                     "GdkGLDrawable",
                                     &type_info, 0);
    }

  return type;
}

gboolean
gdk_gl_drawable_make_current (GdkGLDrawable *gldrawable,
                              GdkGLContext  *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_DRAWABLE (gldrawable), FALSE);

  return GDK_GL_DRAWABLE_GET_CLASS (gldrawable)->make_context_current (gldrawable,
                                                                       gldrawable,
                                                                       glcontext);
}

void
gdk_gl_drawable_swap_buffers (GdkGLDrawable *gldrawable)
{
  g_return_if_fail (GDK_IS_GL_DRAWABLE (gldrawable));

  GDK_GL_DRAWABLE_GET_CLASS (gldrawable)->swap_buffers (gldrawable);
}
