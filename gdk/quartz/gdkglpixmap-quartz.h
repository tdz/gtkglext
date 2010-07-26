#ifndef __GDK_GL_PIXMAP_QUARTZ_H__
#define __GDK_GL_PIXMAP_QUARTZ_H__

#include <gdk/gdkglpixmap.h>
#include <gdk/quartz/gdkglquartz.h>

G_BEGIN_DECLS

typedef struct _GdkGLPixmapImplQuartz      GdkGLPixmapImplQuartz;
typedef struct _GdkGLPixmapImplQuartzClass GdkGLPixmapImplQuartzClass;
  
#define GDK_TYPE_GL_PIXMAP_IMPL_QUARTZ              (gdk_gl_pixmap_impl_quartz_get_type ())
#define GDK_GL_PIXMAP_IMPL_QUARTZ(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), GDK_TYPE_GL_PIXMAP_IMPL_QUARTZ, GdkGLPixmapImplQuartz))
#define GDK_GL_PIXMAP_IMPL_QUARTZ_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), GDK_TYPE_GL_PIXMAP_IMPL_QUARTZ, GdkGLPixmapImplQuartzClass))
#define GDK_IS_GL_PIXMAP_IMPL_QUARTZ(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), GDK_TYPE_GL_PIXMAP_IMPL_QUARTZ))
#define GDK_IS_GL_PIXMAP_IMPL_QUARTZ_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), GDK_TYPE_GL_PIXMAP_IMPL_QUARTZ))
#define GDK_GL_PIXMAP_IMPL_QUARTZ_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), GDK_TYPE_GL_PIXMAP_IMPL_QUARTZ, GdkGLPixmapImplQuartzClass))
  
struct _GdkGLPixmapImplQuartz
  {
    GdkGLPixmap parent_instance;
    
//    GdkPixmap   *bufPixmap;
    NSOpenGLContext    *quartzContext;
    
//    int width;
//    int height;
//    int depth;
    
    GdkPixbuf *glPixbuf;
    
    GdkGLConfig *glconfig;
    
    
    guint is_destroyed : 1;
  };

struct _GdkGLPixmapImplQuartzClass
{
  GdkGLPixmapClass parent_class;
};

GType gdk_gl_pixmap_impl_quartz_get_type (void);


G_END_DECLS


#endif
