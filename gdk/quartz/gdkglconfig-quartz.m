#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */


#include "gdkglprivate-quartz.h"
#include "gdkglconfig-quartz.h"


static void gdk_gl_config_impl_quartz_class_init (GdkGLConfigImplQuartzClass *klass);
static void gdk_gl_config_impl_quartz_finalize   (GObject                    *object);

static gpointer parent_class = NULL;

GType
gdk_gl_config_impl_quartz_get_type (void)
{
  static GType type = 0;
  
  if (!type)
    {
    static const GTypeInfo type_info = {
      sizeof (GdkGLConfigImplQuartzClass),
      (GBaseInitFunc) NULL,
      (GBaseFinalizeFunc) NULL,
      (GClassInitFunc) gdk_gl_config_impl_quartz_class_init,
      (GClassFinalizeFunc) NULL,
      NULL,                   /* class_data */
      sizeof (GdkGLConfigImplQuartz),
      0,                      /* n_preallocs */
      (GInstanceInitFunc) NULL
    };
    
    type = g_type_register_static (GDK_TYPE_GL_CONFIG,
                     "GdkGLConfigImplQuartz",
                     &type_info, 0);
    }
  
  return type;
}

static void
gdk_gl_config_impl_quartz_class_init (GdkGLConfigImplQuartzClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  
  parent_class = g_type_class_peek_parent (klass);
  object_class->finalize = gdk_gl_config_impl_quartz_finalize;
}

static void
gdk_gl_config_impl_quartz_finalize (GObject *object)
{
  GdkGLConfigImplQuartz *impl = GDK_GL_CONFIG_IMPL_QUARTZ (object);
  
  GDK_GL_NOTE_FUNC_PRIVATE ();
  [impl->quartzPixelFormat release];
  g_object_unref (G_OBJECT (impl->colormap));
  
  G_OBJECT_CLASS (parent_class)->finalize (object);
}


/**
 * gdk_gl_config_get_colormap:
 * @glconfig: a #GdkGLConfig.
 *
 * Gets the #GdkColormap that is appropriate for the OpenGL frame buffer
 * configuration.
 *
 * Return value: the appropriate #GdkColormap.
 **/
GdkColormap *
gdk_gl_config_get_colormap (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_QUARTZ (glconfig), NULL);
  
  return GDK_GL_CONFIG_IMPL_QUARTZ (glconfig)->colormap;
}

/**
 * gdk_gl_config_get_visual:
 * @glconfig: a #GdkGLConfig.
 *
 * Gets the #GdkVisual that is appropriate for the OpenGL frame buffer
 * configuration.
 *
 * Return value: the appropriate #GdkVisual.
 **/
GdkVisual *
gdk_gl_config_get_visual (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_QUARTZ (glconfig), NULL);
  
  return gdk_colormap_get_visual (GDK_GL_CONFIG_IMPL_QUARTZ (glconfig)->colormap);
}

static GdkGLConfig *
gdk_gl_config_new_common (GdkScreen *screen,
                          const int *attrib_list)
{
#define MAX_ATTRS 100
  GdkGLConfig *glconfig;
  GdkGLConfigImplQuartz *impl;
  static NSOpenGLPixelFormatAttribute attrlist[MAX_ATTRS];
  unsigned i=0;
  int *p;
  
  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_QUARTZ, NULL);
  impl = GDK_GL_CONFIG_IMPL_QUARTZ (glconfig);
  
  impl->screen = screen;
  impl->colormap =gdk_screen_get_system_colormap (screen); // gdk_colormap_get_system();
  
  glconfig->is_rgba = TRUE;
  glconfig->is_stereo = FALSE;
  glconfig->is_double_buffered = FALSE;
  glconfig->n_aux_buffers = 0;
  glconfig->layer_plane = 0;
  glconfig->has_alpha = TRUE;
  glconfig->has_depth_buffer = FALSE;
  glconfig->has_stencil_buffer = FALSE;
  glconfig->has_accum_buffer = FALSE;
  glconfig->n_sample_buffers = 0;
  
  
  p = (int *) attrib_list;
  while ((*p != GDK_GL_ATTRIB_LIST_NONE) && (i+2<MAX_ATTRS))
    {
    switch (*p)
        {
      case GDK_GL_BUFFER_SIZE:
        /* Specifies the number of color bitplanes in each color buffer. */
        attrlist[i++] = NSOpenGLPFAColorSize;
        attrlist[i++] = *(++p);
        break;
      case GDK_GL_DOUBLEBUFFER:
        /* The buffer is double-buffered. */
        attrlist[i++] =NSOpenGLPFADoubleBuffer;
        glconfig->is_double_buffered = TRUE;
        break;
      case GDK_GL_STEREO:
        /* The buffer is stereoscopic.
         This flag is not supported in the current generic implementation. */
        attrlist[i++] = NSOpenGLPFAStereo;
        glconfig->is_stereo = TRUE;
        break;
      case GDK_GL_AUX_BUFFERS:
        /* Specifies the number of auxiliary buffers.
         Auxiliary buffers are not supported. */
        attrlist[i++] = NSOpenGLPFAAuxBuffers;
        glconfig->n_aux_buffers = attrlist[i++] =  *(++p);
        break;
      case GDK_GL_DEPTH_SIZE:
        /* Specifies the depth of the depth (z-axis) buffer. */
        attrlist[i++] =  NSOpenGLPFADepthSize ;
        attrlist[i++] = *(++p);
        glconfig->has_depth_buffer = TRUE;
        break;
      case GDK_GL_STENCIL_SIZE:
        /* Specifies the depth of the stencil buffer. */
        attrlist[i++] =  NSOpenGLPFAStencilSize ;
        attrlist[i++] = *(++p);
        glconfig->has_stencil_buffer = TRUE;
        break;
      case GDK_GL_ALPHA_SIZE:        
        attrlist[i++] =  NSOpenGLPFAAlphaSize ;
        attrlist[i++] = *(++p);
        glconfig->has_stencil_buffer = TRUE;
        break;        
      case GDK_GL_USE_GL:        
      case GDK_GL_RGBA:
      case GDK_GL_LEVEL:        
      case GDK_GL_RED_SIZE:
      case GDK_GL_GREEN_SIZE:
      case GDK_GL_BLUE_SIZE:
      case GDK_GL_ACCUM_RED_SIZE:
      case GDK_GL_ACCUM_GREEN_SIZE:
      case GDK_GL_ACCUM_BLUE_SIZE:
      case GDK_GL_ACCUM_ALPHA_SIZE:
        break;
        }
    ++p;
    }
  attrlist[i] = 0;
  impl->quartzPixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrlist];
  
  return glconfig;
#undef MAX_ATTRS  
}

GdkGLConfig *
gdk_gl_config_new (const int *attrib_list)
{
  GdkScreen *screen;
  
  GDK_GL_NOTE_FUNC ();
  
  g_return_val_if_fail (attrib_list != NULL, NULL);
  
  screen = gdk_screen_get_default ();
  
  return gdk_gl_config_new_common (screen, attrib_list);
}

/**
 * gdk_gl_config_new_for_screen:
 * @screen: target screen.
 * @attrib_list: a list of attribute/value pairs. The last attribute must
 *               be GDK_GL_ATTRIB_LIST_NONE.
 *
 * Returns an OpenGL frame buffer configuration that match the specified
 * attributes.
 *
 * Return value: the new #GdkGLConfig.
 **/
GdkGLConfig *
gdk_gl_config_new_for_screen (GdkScreen *screen,
                              const int *attrib_list)
{
  GDK_GL_NOTE_FUNC ();
  
  g_return_val_if_fail (GDK_IS_SCREEN (screen), NULL);
  g_return_val_if_fail (attrib_list != NULL, NULL);
  
  return gdk_gl_config_new_common (screen, attrib_list);
}

/**
 * gdk_gl_config_get_attrib:
 * @glconfig: a #GdkGLConfig.
 * @attribute: the attribute to be returned.
 * @value: returns the requested value.
 *
 * Gets information about a OpenGL frame buffer configuration.
 *
 * Return value: TRUE if it succeeded, FALSE otherwise.
 **/
gboolean
gdk_gl_config_get_attrib (GdkGLConfig *glconfig,
                          int          attribute,
                          int         *value)
{
#if 1
  GdkGLConfigImplQuartz *impl;
  NSOpenGLPixelFormat   *lPixelFormat;
  GLint lScreen=0;
  NSOpenGLPixelFormatAttribute attrib;
  g_return_val_if_fail (GDK_IS_GL_CONFIG_IMPL_QUARTZ(glconfig), FALSE);
  
  impl = GDK_GL_CONFIG_IMPL_QUARTZ (glconfig);
  lPixelFormat = impl->quartzPixelFormat;
  switch (attribute)
    {
    case GDK_GL_USE_GL:
    case GDK_GL_RGBA:      
          *value = 1;
        return TRUE;
        break;
    case GDK_GL_BUFFER_SIZE:
      attrib = NSOpenGLPFAColorSize;
      break;
    case GDK_GL_DOUBLEBUFFER:
      attrib = NSOpenGLPFADoubleBuffer;
      break;
    case GDK_GL_STEREO:
      attrib = NSOpenGLPFAStereo;
      break;
    case GDK_GL_AUX_BUFFERS:
      attrib = NSOpenGLPFAAuxBuffers;
      break;
    case GDK_GL_DEPTH_SIZE:
      attrib = NSOpenGLPFADepthSize;
      break;
    case GDK_GL_STENCIL_SIZE:
      attrib = NSOpenGLPFAStencilSize;      
      break;
    case GDK_GL_ALPHA_SIZE:
      attrib = NSOpenGLPFAAlphaSize;      
      break;
    case GDK_GL_RED_SIZE:
    case GDK_GL_GREEN_SIZE:
    case GDK_GL_BLUE_SIZE:
      //attrib = NSOpenGLPFAColorSize;
      *value=1;
      return TRUE;
      break;
    case GDK_GL_ACCUM_RED_SIZE:
    case GDK_GL_ACCUM_GREEN_SIZE:
    case GDK_GL_ACCUM_BLUE_SIZE:
    case GDK_GL_ACCUM_ALPHA_SIZE:    
      attrib = NSOpenGLPFAAccumSize;
      break;
    case GDK_GL_LEVEL:            
    default:
      return FALSE;
    }
  
  [lPixelFormat getValues:value forAttribute:attrib forVirtualScreen:lScreen];
  return TRUE;
#else
  return FALSE;
#endif
}
