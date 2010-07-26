#ifndef __GDK_GL_PRIVATE_QUARTZ_H__
#define __GDK_GL_PRIVATE_QUARTZ_H__

#include <gdk/gdkprivate.h>

#include <gdk/gdkglprivate.h>


G_BEGIN_DECLS

GdkGLContext *_gdk_quartz_gl_context_window_new (GdkGLDrawable *gldrawable,
                                                 GdkGLContext  *share_list,
                                                 gboolean       direct,
                                                 int            render_type);

GdkGLContext *_gdk_quartz_gl_context_pixmap_new (GdkGLDrawable *gldrawable,
                                                 GdkGLContext  *share_list,
                                                 gboolean       direct,
                                                 int            render_type);

void _gdk_gl_drawable_impl_quartz_wait_gl  (GdkGLDrawable *gldrawable);
void _gdk_gl_drawable_impl_quartz_wait_gdk (GdkGLDrawable *gldrawable);

G_BEGIN_DECLS

#endif /* __GDK_GL_PRIVATE_QUARTZ_H__ */
