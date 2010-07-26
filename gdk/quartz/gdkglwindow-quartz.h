#ifndef __GDK_GL_WINDOW_QUARTZ_H__
#define __GDK_GL_WINDOW_QUARTZ_H__

#include <gdk/gdkglwindow.h>
#include <gdk/quartz/gdkglquartz.h>

G_BEGIN_DECLS
                         
typedef struct _GdkGLWindowImplQuartz      GdkGLWindowImplQuartz;
typedef struct _GdkGLWindowImplQuartzClass GdkGLWindowImplQuartzClass;
  
#define GDK_TYPE_GL_WINDOW_IMPL_QUARTZ              (gdk_gl_window_impl_quartz_get_type ())
#define GDK_GL_WINDOW_IMPL_QUARTZ(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_GL_WINDOW_IMPL_QUARTZ, GdkGLWindowImplQuartz))
#define GDK_GL_WINDOW_IMPL_QUARTZ_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_GL_WINDOW_IMPL_QUARTZ, GdkGLWindowImplQuartzClass))
#define GDK_IS_GL_WINDOW_IMPL_QUARTZ(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_GL_WINDOW_IMPL_QUARTZ))
#define GDK_IS_GL_WINDOW_IMPL_QUARTZ_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_GL_WINDOW_IMPL_QUARTZ))
#define GDK_GL_WINDOW_IMPL_QUARTZ_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_GL_WINDOW_IMPL_QUARTZ, GdkGLWindowImplQuartzClass))
  
struct _GdkGLWindowImplQuartz
{
  GdkGLWindow parent_instance;

  NSView        *quartzView;
  NSOpenGLContext    *quartzContext;

  GdkGLConfig *glconfig;
    
  guint is_destroyed : 1;
};

struct _GdkGLWindowImplQuartzClass
{
  GdkGLWindowClass parent_class;
};

GType gdk_gl_window_impl_quartz_get_type (void);

G_END_DECLS


#endif
