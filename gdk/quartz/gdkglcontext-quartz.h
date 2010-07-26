#ifndef __GDK_GL_CONTEXT_QUARTZ_H__
#define __GDK_GL_CONTEXT_QUARTZ_H__

#include <gdk/gdkglcontext.h>

G_BEGIN_DECLS

typedef struct _GdkGLContextImplQuartz      GdkGLContextImplQuartz;
typedef struct _GdkGLContextImplQuartzClass GdkGLContextImplQuartzClass;
  
#define GDK_TYPE_GL_CONTEXT_IMPL_QUARTZ              (gdk_gl_context_impl_quartz_get_type ())
#define GDK_GL_CONTEXT_IMPL_QUARTZ(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_GL_CONTEXT_IMPL_QUARTZ, GdkGLContextImplQuartz))
#define GDK_GL_CONTEXT_IMPL_QUARTZ_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_GL_CONTEXT_IMPL_QUARTZ, GdkGLContextImplQuartzClass))
#define GDK_IS_GL_CONTEXT_IMPL_QUARTZ(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_GL_CONTEXT_IMPL_QUARTZ))
#define GDK_IS_GL_CONTEXT_IMPL_QUARTZ_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_GL_CONTEXT_IMPL_QUARTZ))
#define GDK_GL_CONTEXT_IMPL_QUARTZ_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_GL_CONTEXT_IMPL_QUARTZ, GdkGLContextImplQuartzClass))
  
  struct _GdkGLContextImplQuartz
  {
    GdkGLContext parent_instance;
    
    GdkGLContext *share_list;
    gboolean is_direct;
    int render_type;
    
    GdkGLConfig *glconfig;
    
    GdkGLDrawable *gldrawable;
    
    NSOpenGLContext *quartzContext;
    
    guint is_destroyed : 1;
  };

struct _GdkGLContextImplQuartzClass
{
  GdkGLContextClass parent_class;
};

GType gdk_gl_context_impl_quartz_get_type (void);

G_END_DECLS

#endif
