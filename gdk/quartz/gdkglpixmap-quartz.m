#include "gdkglprivate-quartz.h"
#include "gdkglconfig-quartz.h"
#include "gdkglcontext-quartz.h"
#include "gdkglpixmap-quartz.h"

static void gdk_gl_pixmap_sync_gl  (GdkGLPixmap *glpixmap);
static void gdk_gl_pixmap_sync_buffers  (GdkGLPixmap *glpixmap);
static void gdk_gl_pixmap_sync_gdk (GdkGLPixmap *glpixmap);


static gboolean     gdk_gl_pixmap_impl_quartz_make_context_current (GdkGLDrawable *draw,
                                                                 GdkGLDrawable *read,
                                                                 GdkGLContext  *glcontext);
static gboolean     gdk_gl_pixmap_impl_quartz_is_double_buffered   (GdkGLDrawable *gldrawable);
static void         gdk_gl_pixmap_impl_quartz_swap_buffers         (GdkGLDrawable *gldrawable);

static void         gdk_gl_pixmap_impl_quartz_wait_gl              (GdkGLDrawable *gldrawable);
static void         gdk_gl_pixmap_impl_quartz_wait_gdk             (GdkGLDrawable *gldrawable);

static gboolean     gdk_gl_pixmap_impl_quartz_gl_begin             (GdkGLDrawable *draw,
                                                                    GdkGLDrawable *read,
                                                                    GdkGLContext  *glcontext);
static void         gdk_gl_pixmap_impl_quartz_gl_end               (GdkGLDrawable *gldrawable);
static GdkGLConfig *gdk_gl_pixmap_impl_quartz_get_gl_config        (GdkGLDrawable *gldrawable);

static void gdk_gl_pixmap_impl_quartz_class_init (GdkGLPixmapImplQuartzClass *klass);
static void gdk_gl_pixmap_impl_quartz_finalize   (GObject                 *object);
static void gdk_gl_pixmap_impl_quartz_gl_drawable_interface_init (GdkGLDrawableClass *iface);

static gpointer parent_class = NULL;

GType
gdk_gl_pixmap_impl_quartz_get_type (void)
{
  static GType type = 0;
  
  if (!type)
    {
    static const GTypeInfo type_info = {
      sizeof (GdkGLPixmapImplQuartzClass),
      (GBaseInitFunc) NULL,
      (GBaseFinalizeFunc) NULL,
      (GClassInitFunc) gdk_gl_pixmap_impl_quartz_class_init,
      (GClassFinalizeFunc) NULL,
      NULL,                   /* class_data */
      sizeof (GdkGLPixmapImplQuartz),
      0,                      /* n_preallocs */
      (GInstanceInitFunc) NULL
    };
    static const GInterfaceInfo gl_drawable_interface_info = {
      (GInterfaceInitFunc) gdk_gl_pixmap_impl_quartz_gl_drawable_interface_init,
      (GInterfaceFinalizeFunc) NULL,
      NULL                    /* interface_data */
    };
    
    type = g_type_register_static (GDK_TYPE_GL_PIXMAP,
                     "GdkGLPixmapImplQuartz",
                     &type_info, 0);
    g_type_add_interface_static (type,
                   GDK_TYPE_GL_DRAWABLE,
                   &gl_drawable_interface_info);
    }
  
  return type;
}

static void
gdk_gl_pixmap_impl_quartz_class_init (GdkGLPixmapImplQuartzClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  parent_class = g_type_class_peek_parent (klass);
  
  object_class->finalize = gdk_gl_pixmap_impl_quartz_finalize;
}

void
_gdk_gl_pixmap_destroy (GdkGLPixmap *glpixmap)
{
  GdkGLPixmapImplQuartz *impl = GDK_GL_PIXMAP_IMPL_QUARTZ (glpixmap);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  if (impl->is_destroyed)
    return;
  
  impl->is_destroyed = TRUE;
}

static void
gdk_gl_pixmap_impl_quartz_finalize (GObject *object)
{
  GdkGLPixmapImplQuartz *impl = GDK_GL_PIXMAP_IMPL_QUARTZ (object);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  _gdk_gl_pixmap_destroy (GDK_GL_PIXMAP (object));
  
  g_object_unref (G_OBJECT (impl->glconfig));
  
  g_object_unref (G_OBJECT (impl->glPixbuf));
  
  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_pixmap_impl_quartz_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  iface->create_new_context   = _gdk_quartz_gl_context_pixmap_new;
  iface->make_context_current =  gdk_gl_pixmap_impl_quartz_make_context_current;
  iface->is_double_buffered   =  gdk_gl_pixmap_impl_quartz_is_double_buffered;
  iface->swap_buffers         =  gdk_gl_pixmap_impl_quartz_swap_buffers;
  iface->wait_gl              =  gdk_gl_pixmap_impl_quartz_wait_gl;
  iface->wait_gdk             =  gdk_gl_pixmap_impl_quartz_wait_gdk;
  iface->gl_begin             =  gdk_gl_pixmap_impl_quartz_make_context_current;
  iface->gl_end               =  gdk_gl_pixmap_impl_quartz_gl_end;
  iface->get_gl_config        =  gdk_gl_pixmap_impl_quartz_get_gl_config;
  iface->get_size             = _gdk_gl_pixmap_get_size;
}

GdkGLPixmap *
gdk_gl_pixmap_new (GdkGLConfig *glconfig,
                   GdkPixmap   *pixmap,
                   const int   *attrib_list)
{
  GdkGLPixmap *glpixmap;
  GdkGLPixmapImplQuartz *impl;
  
  gint width, height;
//  gint depth;  

  
  GDK_GL_NOTE_FUNC ();
  
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_QUARTZ (glconfig), NULL);
  g_return_val_if_fail (GDK_IS_PIXMAP (pixmap), NULL);
  
  /*
   * Create offscreen rendering area.
   */
  
  gdk_drawable_get_size (GDK_DRAWABLE (pixmap), &width, &height);
  
//  depth = gdk_drawable_get_depth (GDK_DRAWABLE (pixmap));
//  if(depth != 32) goto FAIL;
//  depth = 32;
  
  glpixmap = g_object_new (GDK_TYPE_GL_PIXMAP_IMPL_QUARTZ, NULL);
  impl = GDK_GL_PIXMAP_IMPL_QUARTZ (glpixmap);
  
  glpixmap->drawable = GDK_DRAWABLE (pixmap);
  g_object_add_weak_pointer (G_OBJECT (glpixmap->drawable),
                 (gpointer *) &(glpixmap->drawable));
  
  
  impl->glPixbuf  = gdk_pixbuf_new (GDK_COLORSPACE_RGB, TRUE, 8, width, height);
  
//  impl->width = width;
//  impl->height = height;
//  impl->depth = depth;
//  impl->bufPixmap = pixmap;
  
  impl->glconfig = glconfig;
  g_object_ref (G_OBJECT (impl->glconfig));
    
  impl->is_destroyed = FALSE;
  
  return glpixmap;
  
FAIL:
  
  return NULL;  
}

static gboolean
gdk_gl_pixmap_impl_quartz_make_context_current (GdkGLDrawable *draw,
                                             GdkGLDrawable *read,
                                             GdkGLContext  *glcontext)
{
  NSOpenGLContext *quartzContext = GDK_GL_CONTEXT_IMPL_QUARTZ(glcontext)->quartzContext; 
  GdkGLPixmapImplQuartz *impl = GDK_GL_PIXMAP_IMPL_QUARTZ(draw);
  GdkPixbuf    *pixbuf = impl->glPixbuf;
  impl->quartzContext = quartzContext;
  
  
  [quartzContext setOffScreen:gdk_pixbuf_get_pixels(pixbuf)
              width:gdk_pixbuf_get_width(pixbuf)
             height:gdk_pixbuf_get_height(pixbuf)
             rowbytes:gdk_pixbuf_get_rowstride(pixbuf)];
  
  [quartzContext makeCurrentContext];
  return TRUE;
}

static gboolean
gdk_gl_pixmap_impl_quartz_is_double_buffered (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP_IMPL_QUARTZ (gldrawable), FALSE);
  
  return gdk_gl_config_is_double_buffered (GDK_GL_PIXMAP_IMPL_QUARTZ (gldrawable)->glconfig);
}

static void
gdk_gl_pixmap_impl_quartz_swap_buffers (GdkGLDrawable *gldrawable)
{
  
  NSOpenGLContext *quartzContext=GDK_GL_PIXMAP_IMPL_QUARTZ (gldrawable)->quartzContext;
  [quartzContext flushBuffer];
  
}

static void gdk_gl_pixmap_sync_buffers  (GdkGLPixmap *glpixmap)
{
//  GdkPixmap   *pixmap = glpixmap->drawable;
  GdkPixbuf    *pixbuf = GDK_GL_PIXMAP_IMPL_QUARTZ (glpixmap)->glPixbuf;
//  gint     width, height;
  gint     pwidth, pheight;
  NSOpenGLContext *quartzContext=GDK_GL_PIXMAP_IMPL_QUARTZ (glpixmap)->quartzContext;
  
//  gdk_drawable_get_size (GDK_DRAWABLE (pixmap), &width, &height);
  
  pwidth = gdk_pixbuf_get_width(pixbuf);
  pheight = gdk_pixbuf_get_height(pixbuf);
  
//  if(pwidth==width && pheight==height) return;
  
//  g_object_unref (G_OBJECT (pixbuf));
//  pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, TRUE, 8, width, height);
//  GDK_GL_PIXMAP_IMPL_QUARTZ (glpixmap)->glPixbuf =  pixbuf;
  
  [quartzContext setOffScreen:gdk_pixbuf_get_pixels(pixbuf)
              width:pwidth
             height:pheight
             rowbytes:gdk_pixbuf_get_rowstride(pixbuf)];
}

static void gdk_gl_pixmap_sync_gl  (GdkGLPixmap *glpixmap)
{
  GdkPixmap   *pixmap = glpixmap->drawable;
  GdkPixbuf    *pixbuf = GDK_GL_PIXMAP_IMPL_QUARTZ (glpixmap)->glPixbuf;
  
  
  gdk_draw_pixbuf(pixmap,
                    NULL,
                    pixbuf,
                    0,  0,
                    0 , 0,
                    gdk_pixbuf_get_width(pixbuf),
          gdk_pixbuf_get_height(pixbuf),
                    GDK_RGB_DITHER_NORMAL,
                    0, 0);
}

static void gdk_gl_pixmap_sync_gdk (GdkGLPixmap *glpixmap)
{
  gdk_gl_pixmap_sync_gl  (glpixmap);
}

static void         gdk_gl_pixmap_impl_quartz_wait_gl              (GdkGLDrawable *gldrawable)
{
  glFinish ();
  
  /* Sync. */
  gdk_gl_pixmap_sync_gl (GDK_GL_PIXMAP (gldrawable));
}
static void         gdk_gl_pixmap_impl_quartz_wait_gdk             (GdkGLDrawable *gldrawable)
{

//  gdk_gl_pixmap_sync_buffers( GDK_GL_PIXMAP(gldrawable));
}

static gboolean
 gdk_gl_pixmap_impl_quartz_gl_begin (GdkGLDrawable *draw,
 GdkGLDrawable *read,
 GdkGLContext  *glcontext)
{
  gboolean ret;
  
  ret = gdk_gl_pixmap_impl_quartz_make_context_current (draw, read, glcontext);
  if (!ret)
    return FALSE;
  
  gdk_gl_pixmap_impl_quartz_wait_gdk (draw);
  
  return TRUE;
}


static void
gdk_gl_pixmap_impl_quartz_gl_end (GdkGLDrawable *gldrawable)
{
   gdk_gl_pixmap_impl_quartz_wait_gl (gldrawable);
}

static GdkGLConfig *
gdk_gl_pixmap_impl_quartz_get_gl_config (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_PIXMAP_IMPL_QUARTZ (gldrawable), NULL);
  
  return GDK_GL_PIXMAP_IMPL_QUARTZ (gldrawable)->glconfig;
}
