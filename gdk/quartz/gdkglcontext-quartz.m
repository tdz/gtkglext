#include <gdk/gdk.h>            /* for gdk_error_trap_(push|pop) () */

#include "gdkglprivate-quartz.h"
#include "gdkgldrawable.h"
#include "gdkglconfig-quartz.h"
#include "gdkglcontext-quartz.h"
#include "gdkglwindow-quartz.h"
#include "gdkglpixmap-quartz.h"

static void          gdk_gl_context_insert (GdkGLContext *glcontext);
static void          gdk_gl_context_remove (GdkGLContext *glcontext);

static GdkGLContext *gdk_gl_context_lookup (NSOpenGLContext    *quartzContext);


static void gdk_gl_context_impl_quartz_class_init (GdkGLContextImplQuartzClass *klass);
static void gdk_gl_context_impl_quartz_finalize   (GObject                  *object);

static gpointer parent_class = NULL;


GType
gdk_gl_context_impl_quartz_get_type (void)
{
  static GType type = 0;
  
  if (!type)
    {
    static const GTypeInfo type_info = {
      sizeof (GdkGLContextImplQuartzClass),
      (GBaseInitFunc) NULL,
      (GBaseFinalizeFunc) NULL,
      (GClassInitFunc) gdk_gl_context_impl_quartz_class_init,
      (GClassFinalizeFunc) NULL,
      NULL,                   /* class_data */
      sizeof (GdkGLContextImplQuartz),
      0,                      /* n_preallocs */
      (GInstanceInitFunc) NULL
    };
    
    type = g_type_register_static (GDK_TYPE_GL_CONTEXT,
                     "GdkGLContextImplQuartz",
                     &type_info, 0);
    }
  
  return type;
}

static void
gdk_gl_context_impl_quartz_class_init (GdkGLContextImplQuartzClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  parent_class = g_type_class_peek_parent (klass);
  
  object_class->finalize = gdk_gl_context_impl_quartz_finalize;
}

void
_gdk_gl_context_destroy (GdkGLContext *glcontext)
{
  GdkGLContextImplQuartz *impl = GDK_GL_CONTEXT_IMPL_QUARTZ (glcontext);

  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  if (impl->is_destroyed)
    return;
  
  gdk_gl_context_remove (glcontext);
  
  
  
  if (impl->gldrawable != NULL)
    {
    g_object_remove_weak_pointer (G_OBJECT (impl->gldrawable),
                    (gpointer *) &(impl->gldrawable));
    impl->gldrawable = NULL;
    }
  
  
  impl->is_destroyed = TRUE;
}

static void
gdk_gl_context_impl_quartz_finalize (GObject *object)
{
  GdkGLContextImplQuartz *impl = GDK_GL_CONTEXT_IMPL_QUARTZ (object);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  [[NSNotificationCenter defaultCenter] removeObserver:impl->quartzContext];
  [impl->quartzContext release];
  
  _gdk_gl_context_destroy (GDK_GL_CONTEXT (object));
  
//  g_object_unref (G_OBJECT (impl->glconfig));
  
  if (impl->share_list != NULL)
    g_object_unref (G_OBJECT (impl->share_list));
  
  G_OBJECT_CLASS (parent_class)->finalize (object);
}


/*
 * GdkGLContext hash table.
 */

static GHashTable *gl_context_ht = NULL;

static void
gdk_gl_context_insert (GdkGLContext *glcontext)
{
  GdkGLContextImplQuartz *impl;
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  if (gl_context_ht == NULL)
    {
      GDK_GL_NOTE (MISC, g_message (" -- Create GL context hash table."));
      gl_context_ht = g_hash_table_new (g_direct_hash, g_direct_equal);
    }
  impl = GDK_GL_CONTEXT_IMPL_QUARTZ (glcontext);

  g_hash_table_insert (gl_context_ht, impl->quartzContext, glcontext);
}


static void
gdk_gl_context_remove (GdkGLContext *glcontext)
{
  GdkGLContextImplQuartz *impl;
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  if (gl_context_ht == NULL)
    return;

  impl = GDK_GL_CONTEXT_IMPL_QUARTZ (glcontext);

  g_hash_table_remove (gl_context_ht, impl->quartzContext);

  if (g_hash_table_size (gl_context_ht) == 0)
    {
      GDK_GL_NOTE (MISC, g_message (" -- Destroy GL context hash table."));
      g_hash_table_destroy (gl_context_ht);
      gl_context_ht = NULL;
    }
}


GdkGLDrawable *gdk_gl_context_get_gl_drawable (GdkGLContext  *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT_IMPL_QUARTZ (glcontext), NULL);
  
  return GDK_GL_CONTEXT_IMPL_QUARTZ (glcontext)->gldrawable;
}

GdkGLContext *
gdk_gl_context_get_current (void)
{

  static GdkGLContext *current = NULL;
  NSOpenGLContext *quartzContext;
  
  GDK_GL_NOTE_FUNC ();
  
  quartzContext = [NSOpenGLContext currentContext];
  
  if (quartzContext == NULL)
    return NULL;
  
  if (current && GDK_GL_CONTEXT_IMPL_QUARTZ(current)->quartzContext == quartzContext)
    return current;
  
  current = gdk_gl_context_lookup (quartzContext);
  
  return current;
}

static GdkGLContext *
gdk_gl_context_new_common (GdkGLConfig   *glconfig,
                           GdkGLContext  *share_list,
                           int            render_type,
               NSOpenGLContext *quartzContext
            )
{
  GdkGLContext *glcontext;
  GdkGLContextImplQuartz *impl;

  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  /*
   * Instantiate the GdkGLContextImplX11 object.
   */
  
  glcontext = g_object_new (GDK_TYPE_GL_CONTEXT_IMPL_QUARTZ, NULL);
  impl = GDK_GL_CONTEXT_IMPL_QUARTZ (glcontext);
  impl->quartzContext = quartzContext;
  
  if (share_list != NULL && GDK_IS_GL_CONTEXT (share_list))
    {
    impl->share_list = share_list;
    g_object_ref (G_OBJECT (impl->share_list));
    }
  else
    {
    impl->share_list = NULL;
    }
    
  return glcontext;
}


/*< private >*/
GdkGLContext *_gdk_quartz_gl_context_pixmap_new (GdkGLDrawable *gldrawable,
                         GdkGLContext  *share_list,
                         gboolean       direct,
                         int            render_type)
{
  GdkGLConfig *glconfig;
  GdkGLContextImplQuartz *share_impl = NULL;
  NSOpenGLContext *quartzContext;
  static NSOpenGLPixelFormatAttribute attribs[] = {NSOpenGLPFAOffScreen,
    NSOpenGLPFADepthSize , 1,
    NSOpenGLPFAColorSize, 24,
    NSOpenGLPFAAlphaSize, 8,
  0};
  GDK_GL_NOTE_FUNC_PRIVATE ();
  NSOpenGLPixelFormat *quartzPixelFormat;
  /*
   * Create an OpenGL rendering context.
   */
  
  glconfig = gdk_gl_drawable_get_gl_config (gldrawable);
  
  
  if (share_list != NULL && GDK_IS_GL_CONTEXT (share_list))
    {
    share_impl = GDK_GL_CONTEXT_IMPL_QUARTZ (share_list);
    }
  
  //if (glconfig != NULL && GDK_IS_GL_CONFIG_IMPL_QUARTZ(glconfig))
//  {
//    GdkGLConfigImplQuartz *glQuartzConfig = GDK_GL_CONFIG_IMPL_QUARTZ(glconfig) ;
//    quartzPixelFormat =   glQuartzConfig -> quartzPixelFormat;
//  }
//  else 

  quartzPixelFormat = [[[NSOpenGLPixelFormat alloc] initWithAttributes:attribs] autorelease];
  
  quartzContext = [[NSOpenGLContext alloc] initWithFormat:quartzPixelFormat shareContext:nil];
  
  if(GDK_IS_GL_PIXMAP_IMPL_QUARTZ(gldrawable))
  {
    GdkGLPixmapImplQuartz *pixmapQuartz=GDK_GL_PIXMAP_IMPL_QUARTZ (gldrawable);
    GdkPixbuf *pixbuf=pixmapQuartz->glPixbuf;
    
    pixmapQuartz->quartzContext = quartzContext;
        
    [quartzContext setOffScreen:gdk_pixbuf_get_pixels(pixbuf)
             width:gdk_pixbuf_get_width(pixbuf)
             height:gdk_pixbuf_get_height(pixbuf)
             rowbytes:gdk_pixbuf_get_rowstride(pixbuf)];
  }
  
  
  return gdk_gl_context_new_common (glconfig,
                    share_list,
                    render_type,
                    quartzContext
                    );
  
}

GdkGLContext *
_gdk_quartz_gl_context_window_new (GdkGLDrawable *gldrawable,
                         GdkGLContext  *share_list,
                         gboolean       direct,
                         int            render_type)
{
  GdkGLConfig *glconfig;
  GdkGLContextImplQuartz *share_impl = NULL;
  NSOpenGLContext *quartzContext;
  NSOpenGLPixelFormatAttribute attribs[] = {0};
  NSView *quartzView;
  GDK_GL_NOTE_FUNC_PRIVATE ();
  NSOpenGLPixelFormat *quartzPixelFormat;
  /*
   * Create an OpenGL rendering context.
   */
  
  glconfig = gdk_gl_drawable_get_gl_config (gldrawable);
  
  
  if (share_list != NULL && GDK_IS_GL_CONTEXT (share_list))
    {
    share_impl = GDK_GL_CONTEXT_IMPL_QUARTZ (share_list);
    }
  
  if (glconfig != NULL && GDK_IS_GL_CONFIG_IMPL_QUARTZ(glconfig))
  {
    GdkGLConfigImplQuartz *glQuartzConfig = GDK_GL_CONFIG_IMPL_QUARTZ(glconfig) ;
    quartzPixelFormat =   glQuartzConfig -> quartzPixelFormat;
  }
  else quartzPixelFormat = [[[NSOpenGLPixelFormat alloc] initWithAttributes:attribs] autorelease];
  
  quartzContext = [[NSOpenGLContext alloc] initWithFormat:quartzPixelFormat shareContext:nil];
  
  if(GDK_IS_GL_WINDOW_IMPL_QUARTZ(gldrawable))
  {
  GDK_GL_WINDOW_IMPL_QUARTZ (gldrawable)->quartzContext = quartzContext;
  quartzView = GDK_GL_WINDOW_IMPL_QUARTZ (gldrawable)->quartzView;
  [[NSNotificationCenter defaultCenter] 
     addObserver:quartzContext
     selector: @selector(update)
     name: NSViewFrameDidChangeNotification 
     object:quartzView
     ];
    
  }
  
  
  return gdk_gl_context_new_common (glconfig,
                    share_list,
                    render_type,
                    quartzContext
                    );
}

static GdkGLContext *
gdk_gl_context_lookup (NSOpenGLContext *glxcontext)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  if (gl_context_ht == NULL)
    return NULL;
  
  return g_hash_table_lookup (gl_context_ht, &glxcontext);
}
