#include "gdkglprivate-quartz.h"
#include "gdkglconfig-quartz.h"
#include "gdkglcontext-quartz.h"
#include "gdkglwindow-quartz.h"

#include <gdk/gdkglquery.h>

static gboolean     gdk_gl_window_impl_quartz_make_context_current (GdkGLDrawable *draw,
                                                                    GdkGLDrawable *read,
                                                                    GdkGLContext  *glcontext);
static gboolean     gdk_gl_window_impl_quartz_is_double_buffered   (GdkGLDrawable *gldrawable);
static void         gdk_gl_window_impl_quartz_swap_buffers         (GdkGLDrawable *gldrawable);

static gboolean        gdk_gl_window_impl_quartz_gl_begin            (GdkGLDrawable *draw,
                                                                      GdkGLDrawable *read,
                                                                      GdkGLContext  *glcontext);

static void         gdk_gl_window_impl_quartz_gl_end               (GdkGLDrawable *gldrawable);
static GdkGLConfig *gdk_gl_window_impl_quartz_get_gl_config        (GdkGLDrawable *gldrawable);

static void gdk_gl_window_impl_quartz_class_init (GdkGLWindowImplQuartzClass *klass);
static void gdk_gl_window_impl_quartz_finalize   (GObject                 *object);
static void gdk_gl_window_impl_quartz_gl_drawable_interface_init (GdkGLDrawableClass *iface);

static gpointer parent_class = NULL;

GType
gdk_gl_window_impl_quartz_get_type (void)
{
  static GType type = 0;
  
  if (!type)
    {
    static const GTypeInfo type_info = {
      sizeof (GdkGLWindowImplQuartzClass),
      (GBaseInitFunc) NULL,
      (GBaseFinalizeFunc) NULL,
      (GClassInitFunc) gdk_gl_window_impl_quartz_class_init,
      (GClassFinalizeFunc) NULL,
      NULL,                   /* class_data */
      sizeof (GdkGLWindowImplQuartz),
      0,                      /* n_preallocs */
      (GInstanceInitFunc) NULL
    };
    static const GInterfaceInfo gl_drawable_interface_info = {
      (GInterfaceInitFunc) gdk_gl_window_impl_quartz_gl_drawable_interface_init,
      (GInterfaceFinalizeFunc) NULL,
      NULL                    /* interface_data */
    };
    
    type = g_type_register_static (GDK_TYPE_GL_WINDOW,
                     "GdkGLWindowImplQuartz",
                     &type_info, 0);
    g_type_add_interface_static (type,
                   GDK_TYPE_GL_DRAWABLE,
                   &gl_drawable_interface_info);
    }
  
  return type;
}

static void
gdk_gl_window_impl_quartz_class_init (GdkGLWindowImplQuartzClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  parent_class = g_type_class_peek_parent (klass);
  
  object_class->finalize = gdk_gl_window_impl_quartz_finalize;
}

void
_gdk_gl_window_destroy (GdkGLWindow *glwindow)
{
  GdkGLWindowImplQuartz *impl = GDK_GL_WINDOW_IMPL_QUARTZ (glwindow);

  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  if (impl->is_destroyed)
    return;
  
  impl->is_destroyed = TRUE;
}

static void
gdk_gl_window_impl_quartz_finalize (GObject *object)
{
  GdkGLWindowImplQuartz *impl = GDK_GL_WINDOW_IMPL_QUARTZ (object);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  _gdk_gl_window_destroy (GDK_GL_WINDOW (object));
  
  g_object_unref (G_OBJECT (impl->glconfig));
  
  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gdk_gl_window_impl_quartz_gl_drawable_interface_init (GdkGLDrawableClass *iface)
{
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  iface->create_new_context   = _gdk_quartz_gl_context_window_new;
  iface->make_context_current =  gdk_gl_window_impl_quartz_make_context_current;
  iface->is_double_buffered   =  gdk_gl_window_impl_quartz_is_double_buffered;
  iface->swap_buffers         =  gdk_gl_window_impl_quartz_swap_buffers;
  iface->wait_gl              = _gdk_gl_drawable_impl_quartz_wait_gl;
  iface->wait_gdk             = _gdk_gl_drawable_impl_quartz_wait_gdk;
  iface->gl_begin             =  gdk_gl_window_impl_quartz_gl_begin;
  iface->gl_end               =  gdk_gl_window_impl_quartz_gl_end;
  iface->get_gl_config        =  gdk_gl_window_impl_quartz_get_gl_config;
  iface->get_size             = _gdk_gl_window_get_size;
}


GdkGLWindow *
gdk_gl_window_new (GdkGLConfig *glconfig,
                   GdkWindow   *window,
                   const int   *attrib_list)
{
  GdkGLWindow *glwindow;
  GdkGLWindowImplQuartz *impl;
  NSView *quartzView;
  
  GDK_GL_NOTE_FUNC ();
  
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_QUARTZ (glconfig), NULL);
  g_return_val_if_fail (GDK_IS_WINDOW (window), NULL);
  
  quartzView = gdk_quartz_window_get_nsview(window);

  
  glwindow = g_object_new (GDK_TYPE_GL_WINDOW_IMPL_QUARTZ, NULL);
  impl = GDK_GL_WINDOW_IMPL_QUARTZ (glwindow);
  
  glwindow->drawable = GDK_DRAWABLE (window);
  g_object_add_weak_pointer (G_OBJECT (glwindow->drawable),
                 (gpointer *) &(glwindow->drawable));
  
  
  impl->glconfig = glconfig;
  g_object_ref (G_OBJECT (impl->glconfig));
  
  impl->quartzView = quartzView;
  
  impl->is_destroyed = FALSE;
  
  return glwindow;
}

static gboolean
gdk_gl_window_impl_quartz_is_double_buffered (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW_IMPL_QUARTZ (gldrawable), FALSE);
  
  return gdk_gl_config_is_double_buffered (GDK_GL_WINDOW_IMPL_QUARTZ (gldrawable)->glconfig);
}

static void
gdk_gl_window_impl_quartz_swap_buffers (GdkGLDrawable *gldrawable)
{
  NSOpenGLContext *quartzContext=GDK_GL_WINDOW_IMPL_QUARTZ (gldrawable)->quartzContext;
  [quartzContext flushBuffer];
}

static gboolean     gdk_gl_window_impl_quartz_make_context_current (GdkGLDrawable *draw,
                                                                    GdkGLDrawable *read,
                                                                    GdkGLContext  *glcontext)
{
  NSOpenGLContext *quartzContext = GDK_GL_CONTEXT_IMPL_QUARTZ(glcontext)->quartzContext; 
  [quartzContext makeCurrentContext];
  return TRUE;
}

static gboolean      gdk_gl_window_impl_quartz_gl_begin            (GdkGLDrawable *draw,
                                                                    GdkGLDrawable *read,
                                                                    GdkGLContext  *glcontext)
{
  NSOpenGLContext *quartzContext = GDK_GL_CONTEXT_IMPL_QUARTZ(glcontext)->quartzContext; 
  NSView      *view = GDK_GL_WINDOW_IMPL_QUARTZ (draw)->quartzView;
  gboolean    ret=gdk_gl_window_impl_quartz_make_context_current (draw, read, glcontext);
  if (([quartzContext view] != view) && ![view isHidden]) {
        [quartzContext setView:view];
    }
  return ret;
}

static void
gdk_gl_window_impl_quartz_gl_end (GdkGLDrawable *gldrawable)
{
  /* do nothing */
}

static GdkGLConfig *
gdk_gl_window_impl_quartz_get_gl_config (GdkGLDrawable *gldrawable)
{
  g_return_val_if_fail (GDK_IS_GL_WINDOW_IMPL_QUARTZ(gldrawable), NULL);
  
  return GDK_GL_WINDOW_IMPL_QUARTZ (gldrawable)->glconfig;
}
