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

#ifndef __GDK_GL_CONFIG_H__
#define __GDK_GL_CONFIG_H__

#include <gdk/gdktypes.h>

#include <gdk/gdkgltypes.h>

G_BEGIN_DECLS

typedef struct _GdkGLConfigClass GdkGLConfigClass;

#define GDK_TYPE_GL_CONFIG              (gdk_gl_config_get_type ())
#define GDK_GL_CONFIG(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_GL_CONFIG, GdkGLConfig))
#define GDK_GL_CONFIG_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_GL_CONFIG, GdkGLConfigClass))
#define GDK_IS_GL_CONFIG(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_GL_CONFIG))
#define GDK_IS_GL_CONFIG_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_GL_CONFIG))
#define GDK_GL_CONFIG_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_GL_CONFIG, GdkGLConfigClass))

struct _GdkGLConfig
{
  GObject parent_instance;

  GdkWindow *window;
  GdkColormap *colormap;
  gint depth;

  guint is_double_buffer : 1;
  guint is_stereo : 1;
};

struct _GdkGLConfigClass
{
  GObjectClass parent_class;

  gboolean (*get_attrib) (GdkGLConfig *glconfig,
                          gint         attribute,
                          gint        *value);
};

GType        gdk_gl_config_get_type         (void);

GdkGLConfig *gdk_gl_config_new              (GdkWindow   *window,
					     const gint  *attrib_list);

gboolean     gdk_gl_config_get_attrib       (GdkGLConfig *glconfig,
                                             gint         attribute,
                                             gint        *value);

GdkDrawable *gdk_gl_config_get_drawable   (GdkGLConfig *glconfig);

GdkColormap *gdk_gl_config_get_colormap   (GdkGLConfig *glconfig);

gint         gdk_gl_config_get_depth        (GdkGLConfig *glconfig);

gboolean     gdk_gl_config_is_double_buffer (GdkGLConfig *glconfig);

gboolean     gdk_gl_config_is_stereo        (GdkGLConfig *glconfig);

G_END_DECLS

#endif /* __GDK_GL_CONFIG_H__ */
