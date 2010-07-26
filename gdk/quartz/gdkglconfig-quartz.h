#ifndef __GDK_GL_CONFIG_QUARTZ_H__
#define __GDK_GL_CONFIG_QUARTZ_H__

#include <gdk/gdkglconfig.h>
#include <gdk/quartz/gdkglquartz.h>

G_BEGIN_DECLS

typedef struct _GdkGLConfigImplQuartz      GdkGLConfigImplQuartz;
typedef struct _GdkGLConfigImplQuartzClass GdkGLConfigImplQuartzClass;
  
#define GDK_TYPE_GL_CONFIG_IMPL_QUARTZ              (gdk_gl_config_impl_quartz_get_type ())
#define GDK_GL_CONFIG_IMPL_QUARTZ(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_GL_CONFIG_IMPL_QUARTZ, GdkGLConfigImplQuartz))
#define GDK_GL_CONFIG_IMPL_QUARTZ_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_GL_CONFIG_IMPL_QUARTZ, GdkGLConfigImplQuartzClass))
#define GDK_IS_GL_CONFIG_IMPL_QUARTZ(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_GL_CONFIG_IMPL_QUARTZ))
#define GDK_IS_GL_CONFIG_IMPL_QUARTZ_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_GL_CONFIG_IMPL_QUARTZ))
#define GDK_GL_CONFIG_IMPL_QUARTZ_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_GL_CONFIG_IMPL_QUARTZ, GdkGLConfigImplQuartzClass))
  
  struct _GdkGLConfigImplQuartz
  {
    GdkGLConfig parent_instance;
    
    int screen_num;
    
    GdkScreen *screen;
    
    GdkColormap *colormap;
    
    NSOpenGLPixelFormat *quartzPixelFormat;
  };

struct _GdkGLConfigImplQuartzClass
{
  GdkGLConfigClass parent_class;
};

GType gdk_gl_config_impl_quartz_get_type (void);

G_END_DECLS


#endif
