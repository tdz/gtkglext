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

#include "gdkglprivate.h"
#include "gdkgldrawable.h"
#include "gdkglconfig.h"
#include "gdkglcontext.h"

gboolean _gdk_gl_context_force_indirect = FALSE;

G_DEFINE_TYPE (GdkGLContext,    \
               gdk_gl_context,  \
               G_TYPE_OBJECT)

static void
gdk_gl_context_init (GdkGLContext *self)
{
}

static void
gdk_gl_context_class_init (GdkGLContextClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE_FUNC_PRIVATE ();
}

/**
 * gdk_gl_context_new:
 * @gldrawable: a #GdkGLDrawable.
 * @share_list: the #GdkGLContext with which to share display lists and texture
 *              objects. NULL indicates that no sharing is to take place.
 * @direct: whether rendering is to be done with a direct connection to
 *          the graphics system.
 * @render_type: GDK_GL_RGBA_TYPE or GDK_GL_COLOR_INDEX_TYPE (currently not
 *               used).
 *
 * Creates a new OpenGL rendering context.
 *
 * Return value: the new #GdkGLContext.
 **/
GdkGLContext *
gdk_gl_context_new (GdkGLDrawable *gldrawable,
                    GdkGLContext  *share_list,
                    gboolean       direct,
                    int            render_type)
{
  g_return_val_if_fail (GDK_IS_GL_DRAWABLE (gldrawable), NULL);

  return GDK_GL_DRAWABLE_GET_CLASS (gldrawable)->create_new_context (gldrawable,
                                                                     share_list,
                                                                     direct,
                                                                     render_type);
}
