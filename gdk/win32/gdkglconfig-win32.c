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

#include "gdkglwin32.h"
#include "gdkglprivate-win32.h"
#include "gdkglconfig-win32.h"

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
#include <gdk/gdkscreen.h>
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

enum {
  PROP_0,
  PROP_PFD
};

/* Forward declarations */

static GdkColormap *gdk_gl_config_setup_colormap   (GdkScreen                   *screen,
                                                    PIXELFORMATDESCRIPTOR       *pfd,
                                                    gboolean                     is_rgba);

static GdkGLConfig *gdk_gl_config_new_common       (GdkScreen                   *screen,
                                                    CONST PIXELFORMATDESCRIPTOR *pfd);

static gboolean     gdk_win32_gl_config_get_attrib (GdkGLConfig                 *glconfig,
                                                    gint                         attribute,
                                                    gint                        *value);

static void     gdk_gl_config_impl_win32_init         (GdkGLConfigImplWin32      *impl);
static void     gdk_gl_config_impl_win32_class_init   (GdkGLConfigImplWin32Class *klass);

static GObject *gdk_gl_config_impl_win32_constructor  (GType                      type,
                                                       guint                      n_construct_properties,
                                                       GObjectConstructParam     *construct_properties);
static void     gdk_gl_config_impl_win32_set_property (GObject                   *object,
                                                       guint                      property_id,
                                                       const GValue              *value,
                                                       GParamSpec                *pspec);
static void     gdk_gl_config_impl_win32_get_property (GObject                   *object,
                                                       guint                      property_id,
                                                       GValue                    *value,
                                                       GParamSpec                *pspec);
static void     gdk_gl_config_impl_win32_finalize     (GObject                   *object);

static gpointer parent_class = NULL;

GType
gdk_gl_config_impl_win32_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLConfigImplWin32Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_config_impl_win32_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLConfigImplWin32),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_config_impl_win32_init,
      };

      type = g_type_register_static (GDK_TYPE_GL_CONFIG,
                                     "GdkGLConfigImplWin32",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_config_impl_win32_init (GdkGLConfigImplWin32 *impl)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_win32_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_config_impl_win32_class_init (GdkGLConfigImplWin32Class *klass)
{
  GdkGLConfigClass *glconfig_class = GDK_GL_CONFIG_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_win32_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor  = gdk_gl_config_impl_win32_constructor;
  object_class->set_property = gdk_gl_config_impl_win32_set_property;
  object_class->get_property = gdk_gl_config_impl_win32_get_property;
  object_class->finalize     = gdk_gl_config_impl_win32_finalize;

  glconfig_class->get_attrib = gdk_win32_gl_config_get_attrib;

  g_object_class_install_property (object_class,
                                   PROP_PFD,
                                   g_param_spec_pointer ("pfd",
                                                         "Pixel format descriptor",
                                                         "Pointer to the pixel format descriptor.",
                                                         G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

/* 
 * Setup colormap.
 */

/* 
 * !!! RGB palette management should be implemented...
 */

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT

static GdkColormap *
gdk_gl_config_setup_colormap (GdkScreen             *screen,
                              PIXELFORMATDESCRIPTOR *pfd,
                              gboolean               is_rgba)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_setup_colormap ()"));

  if (is_rgba)
    {
      /*
       * For RGBA mode.
       */

      /* System default colormap. */

      GDK_GL_NOTE (MISC, g_message (" -- Colormap: system default"));

      return g_object_ref (G_OBJECT (gdk_screen_get_system_colormap (screen)));
    }
  else
    {
      /*
       * For color index mode.
       */

      /* New private colormap. */

      GDK_GL_NOTE (MISC, g_message (" -- Colormap: new allocated writable"));

      return gdk_colormap_new (gdk_screen_get_system_visual (screen), TRUE);
    }

  /* not reached */
  return NULL;
}

#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */

static GdkColormap *
gdk_gl_config_setup_colormap (GdkScreen             *screen,
                              PIXELFORMATDESCRIPTOR *pfd,
                              gboolean               is_rgba)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_setup_colormap ()"));

  if (is_rgba)
    {
      /*
       * For RGBA mode.
       */

      /* Default colormap. */

      GDK_GL_NOTE (MISC, g_message (" -- Colormap: system default"));

      return g_object_ref (G_OBJECT (gdk_colormap_get_system ()));
    }
  else
    {
      /*
       * For color index mode.
       */

      /* New private colormap. */

      GDK_GL_NOTE (MISC, g_message (" -- Colormap: new allocated writable"));

      return gdk_colormap_new (gdk_visual_get_system (), TRUE);
    }

  /* not reached */
  return NULL;
}

#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

static GObject *
gdk_gl_config_impl_win32_constructor (GType                  type,
                                      guint                  n_construct_properties,
                                      GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLConfig *glconfig;
  GdkGLConfigImplWin32 *impl;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_win32_constructor ()"));

  glconfig = GDK_GL_CONFIG (object);
  impl = GDK_GL_CONFIG_IMPL_WIN32 (object);

  /*
   * Set depth (number of bits per pixel).
   */

  glconfig->depth = impl->pfd.cRedBits +
                    impl->pfd.cGreenBits +
                    impl->pfd.cBlueBits;

  /*
   * Get colormap.
   */

  /* RGBA mode? */
  glconfig->is_rgba = (impl->pfd.iPixelType == PFD_TYPE_RGBA) ? TRUE : FALSE;

  /* get an appropriate colormap. */
  glconfig->colormap = gdk_gl_config_setup_colormap (glconfig->screen,
                                                     &(impl->pfd),
                                                     glconfig->is_rgba);

  /*
   * Get configuration results.
   */

  /* Layer plane. */
  if (impl->pfd.bReserved != 0)
    {
      glconfig->layer_plane = impl->pfd.bReserved & 0x0f;
      if (glconfig->layer_plane == 0)
        glconfig->layer_plane = -1 * ((impl->pfd.bReserved & 0xf0) >> 4);
    }
  else
    {
      glconfig->layer_plane = 0;
    }

  /* Double buffering is supported? */
  glconfig->is_double_buffered = (impl->pfd.dwFlags & PFD_DOUBLEBUFFER) ? TRUE : FALSE;

  /* Stereo is supported? (not work on Windows) */
  glconfig->is_stereo = (impl->pfd.dwFlags & PFD_STEREO) ? TRUE : FALSE;

  /* Has alpha bits? */
  glconfig->has_alpha = impl->pfd.cAlphaBits ? TRUE : FALSE;

  /* Has depth buffer? */
  glconfig->has_depth_buffer = impl->pfd.cDepthBits ? TRUE : FALSE;

  /* Has stencil buffer? */
  glconfig->has_stencil_buffer = impl->pfd.cStencilBits ? TRUE : FALSE;

  /* Has accumulation buffer? */
  glconfig->has_accum_buffer = impl->pfd.cAccumBits ? TRUE : FALSE;

  /* Support multisample antialiasing? */
  glconfig->is_multisample = FALSE;

  /* Support luminance color model? */
  glconfig->is_luminance = FALSE;

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

  return object;
}

static void
gdk_gl_config_impl_win32_set_property (GObject      *object,
                                       guint         property_id,
                                       const GValue *value,
                                       GParamSpec   *pspec)
{
  GdkGLConfigImplWin32 *impl = GDK_GL_CONFIG_IMPL_WIN32 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_win32_set_property ()"));

  switch (property_id)
    {
    case PROP_PFD:
      impl->pfd = *((PIXELFORMATDESCRIPTOR *) g_value_get_pointer (value));
      g_object_notify (object, "pfd");
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_config_impl_win32_get_property (GObject    *object,
                                       guint       property_id,
                                       GValue     *value,
                                       GParamSpec *pspec)
{
  switch (property_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_config_impl_win32_finalize (GObject *object)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_win32_finalize ()"));

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GdkGLConfig *
gdk_gl_config_new_common (GdkScreen                   *screen,
                          CONST PIXELFORMATDESCRIPTOR *pfd)
{
  GdkGLConfig *glconfig;
  GdkGLConfigImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_new_common ()"));

  /*
   * Instanciate the GdkGLConfigImplWin32 object.
   */

  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_WIN32,
                           "screen", screen,
                           "pfd",    pfd,
                           NULL);
  impl = GDK_GL_CONFIG_IMPL_WIN32 (glconfig);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glconfig));
      return NULL;
    }

  return glconfig;
}

/*
 * This code is based on lib/glut/win32_glx.c of GLUT by Nate Robins.
 */
static void
gdk_gl_config_parse_attrib_list (const int             *attrib_list,
                                 PIXELFORMATDESCRIPTOR *pfd)
{
  int *p;
  gboolean buffer_size_is_specified = FALSE;
  BYTE buffer_size;
  int layer_plane;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_parse_attrib_list ()"));

  memset (&pfd, 0, sizeof (PIXELFORMATDESCRIPTOR));

  /* Specifies the size of this data structure. */
  pfd->nSize = sizeof (PIXELFORMATDESCRIPTOR);
  /* Specifies the version of this data structure. This value should be set to 1. */
  pfd->nVersion = 1;

  /* Defaults. */

  /* A set of bit flags that specify properties of the pixel buffer.
     PFD_SUPPORT_GDI and PFD_DOUBLEBUFFER are mutually exclusive in
     the current generic implementation. */
  /* PFD_DRAW_TO_WINDOW or PFD_DRAW_TO_BITMAP is not specified at this stage.
     The Flag is specified by _gdk_win32_gl_(window|pixmap)_hdc_get (). */
  pfd->dwFlags = PFD_SUPPORT_OPENGL |
                 PFD_SUPPORT_GDI;

  /* Specifies the type of pixel data. */
  pfd->iPixelType = PFD_TYPE_COLORINDEX;

  /* Specifies the number of color bitplanes in each color buffer.
     For RGBA pixel types, it is the size of the color buffer, excluding the alpha bitplanes.
     For color-index pixels, it is the size of the color-index buffer. */
  pfd->cColorBits = 32;		/* Max */

  /* Ignored. Earlier implementations of OpenGL used this member,
     but it is no longer used. */
  layer_plane = 0;
  pfd->iLayerType = PFD_MAIN_PLANE;

  p = (int *) attrib_list;
  while (*p != GDK_GL_ATTRIB_LIST_NONE)
    {
      switch (*p)
        {
        case GDK_GL_USE_GL:
	  /* The buffer supports OpenGL drawing. */
          pfd->dwFlags |= PFD_SUPPORT_OPENGL;
          break;
        case GDK_GL_BUFFER_SIZE:
	  /* Specifies the number of color bitplanes in each color buffer. */
          pfd->cColorBits = *(++p);
	  buffer_size_is_specified = TRUE;
          break;
        case GDK_GL_LEVEL:
          layer_plane = *(++p);
	  /* Ignored. Earlier implementations of OpenGL used this member,
	     but it is no longer used. */
	  if (layer_plane > 0)
	    pfd->iLayerType = PFD_OVERLAY_PLANE;
	  else if (layer_plane < 0)
	    pfd->iLayerType = PFD_UNDERLAY_PLANE;
          break;
        case GDK_GL_RGBA:
	  /* RGBA pixels. */
          pfd->iPixelType = PFD_TYPE_RGBA;
          break;
        case GDK_GL_DOUBLEBUFFER:
	  /* The buffer is double-buffered. */
	  pfd->dwFlags &= ~PFD_SUPPORT_GDI;
          pfd->dwFlags |= PFD_DOUBLEBUFFER;
          break;
        case GDK_GL_STEREO:
	  /* The buffer is stereoscopic.
	     This flag is not supported in the current generic implementation. */
          pfd->dwFlags |= PFD_STEREO;
          break;
        case GDK_GL_AUX_BUFFERS:
	  /* Specifies the number of auxiliary buffers.
	     Auxiliary buffers are not supported. */
          pfd->cAuxBuffers = *(++p);
          break;
        case GDK_GL_RED_SIZE:
	  /* Specifies the number of red bitplanes in each RGBA color buffer.
	     Not used by ChoosePixelFormat. */
          pfd->cRedBits = *(++p);
          break;
        case GDK_GL_GREEN_SIZE:
	  /* Specifies the number of green bitplanes in each RGBA color buffer.
	     Not used by ChoosePixelFormat. */
          pfd->cGreenBits = *(++p);
          break;
        case GDK_GL_BLUE_SIZE:
	  /* Specifies the number of blue bitplanes in each RGBA color buffer.
	     Not used by ChoosePixelFormat. */
          pfd->cBlueBits = *(++p);
          break;
        case GDK_GL_ALPHA_SIZE:
	  /* Specifies the number of alpha bitplanes in each RGBA color buffer.
	     Alpha bitplanes are not supported.  */
	  pfd->cAlphaBits = *(++p);
          break;
        case GDK_GL_DEPTH_SIZE:
	  /* Specifies the depth of the depth (z-axis) buffer. */
          pfd->cDepthBits = *(++p);
          break;
        case GDK_GL_STENCIL_SIZE:
	  /* Specifies the depth of the stencil buffer. */
          pfd->cStencilBits = *(++p);
          break;
        case GDK_GL_ACCUM_RED_SIZE:
	  /* Specifies the number of red bitplanes in the accumulation buffer.
	     Not used by ChoosePixelFormat. */
	  pfd->cAccumRedBits = *(++p);
	  break;
        case GDK_GL_ACCUM_GREEN_SIZE:
	  /* Specifies the number of green bitplanes in the accumulation buffer.
	     Not used by ChoosePixelFormat. */
	  pfd->cAccumGreenBits = *(++p);
	  break;
        case GDK_GL_ACCUM_BLUE_SIZE:
	  /* Specifies the number of blue bitplanes in the accumulation buffer.
	     Not used by ChoosePixelFormat. */
	  pfd->cAccumBlueBits = *(++p);
	  break;
        case GDK_GL_ACCUM_ALPHA_SIZE:
	  /* Specifies the number of alpha bitplanes in the accumulation buffer.
	     Not used by ChoosePixelFormat.*/
	  pfd->cAccumAlphaBits = *(++p);
          break;
        }
      ++p;
    }

  /* If GDK_GL_BUFFER_SIZE is not specified. */
  if (!buffer_size_is_specified)
    {
      buffer_size = pfd->cRedBits + pfd->cGreenBits + pfd->cBlueBits;
      if (buffer_size != 0)
	pfd->cColorBits = buffer_size;
    }

  /* Specifies the total number of bitplanes in the accumulation buffer. */
  /* Nate Robins says ...
     I believe that WGL only used the cAccumRedBits,
     cAccumBlueBits, cAccumGreenBits, and cAccumAlphaBits fields
     when returning info about the accumulation buffer precision.
     Only cAccumBits is used for requesting an accumulation buffer. */
  pfd->cAccumBits = pfd->cAccumRedBits +
                    pfd->cAccumGreenBits +
                    pfd->cAccumBlueBits +
                    pfd->cAccumAlphaBits;
}

/*
 * Find an appropriate pixel format.
 * Basic idea of this code is ripped from FLTK.
 */
int
_gdk_win32_gl_config_find_pixel_format (HDC                          hdc,
					CONST PIXELFORMATDESCRIPTOR *req_pfd,
					PIXELFORMATDESCRIPTOR       *found_pfd)
{
  PIXELFORMATDESCRIPTOR pfd, chosen_pfd;
  int pixel_format = 0;
  int i;

  GDK_GL_NOTE (FUNC, g_message (" -- _gdk_win32_gl_config_find_pixel_format ()"));

  memset (&chosen_pfd, 0, sizeof (chosen_pfd));

  for (i = 1; ; i++)
    {
      if (DescribePixelFormat (hdc, i, sizeof (pfd), &pfd) == 0)
	break;

      if (~(pfd.dwFlags)   &  req_pfd->dwFlags)      continue;
      if (pfd.iPixelType   != req_pfd->iPixelType)   continue;
      if (pfd.cColorBits   <  req_pfd->cColorBits)   continue;
      if (pfd.cAlphaBits   <  req_pfd->cAlphaBits)   continue;
      if (pfd.cAccumBits   <  req_pfd->cAccumBits)   continue;
      if (pfd.cDepthBits   <  req_pfd->cDepthBits)   continue;
      if (pfd.cStencilBits <  req_pfd->cStencilBits) continue;
      if (pfd.cAuxBuffers  <  req_pfd->cAuxBuffers)  continue;
      /* if (pfd.iLayerType   != req_pfd->iLayerType)   continue; */

      /* Check whether pfd is better than chosen_pfd. */
      if (pixel_format != 0)
	{
	  /* Offering overlay is better. */
	  if ((pfd.bReserved & 0x0f) && !(chosen_pfd.bReserved & 0x0f)) {}
	  /* More color bitplanes is better. */
	  else if (pfd.cColorBits > chosen_pfd.cColorBits) {}
	  /* pfd is not better than chosen_pfd. */
	  else continue;
	}

      pixel_format = i;
      chosen_pfd = pfd;
    }

  *found_pfd = chosen_pfd;

  return pixel_format;
}

GdkGLConfig *
gdk_gl_config_new (const int *attrib_list)
{
  GdkScreen *screen;
  HDC hdc;
  PIXELFORMATDESCRIPTOR pfd;
  int pixel_format;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_new ()"));

  g_return_val_if_fail (attrib_list != NULL, NULL);

  /*
   * Parse GLX style attrib_list.
   */

  gdk_gl_config_parse_attrib_list (attrib_list, &pfd);

#ifdef G_ENABLE_DEBUG
  _gdk_win32_gl_print_pfd (&pfd);
#endif

  /*
   * Determine whether requested pixel format is supported.
   */

  /* Get DC. */
  hdc = GetDC (NULL);
  if (hdc == NULL)
    {
      g_warning ("cannot get DC");
      return NULL;
    }

  pixel_format = _gdk_win32_gl_config_find_pixel_format (hdc, &pfd, &pfd);

  /* Release DC. */
  ReleaseDC (NULL, hdc);

  if (pixel_format == 0)
    return NULL;

  GDK_GL_NOTE (MISC, g_message (" -- found pixel_format = 0x%x", pixel_format));

#ifdef G_ENABLE_DEBUG
  _gdk_win32_gl_print_pfd (&pfd);
#endif

  /*
   * Instanciate the GdkGLConfigImplWin32 object.
   */

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  screen = gdk_screen_get_default ();
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
  screen = NULL;
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

  return gdk_gl_config_new_common (screen, &pfd);
}

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT

GdkGLConfig *
gdk_gl_config_new_for_screen (GdkScreen *screen,
                              const int *attrib_list)
{
  HDC hdc;
  PIXELFORMATDESCRIPTOR pfd;
  int pixel_format;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_new_for_screen ()"));

  g_return_val_if_fail (attrib_list != NULL, NULL);

  /*
   * Parse GLX style attrib_list.
   */

  gdk_gl_config_parse_attrib_list (attrib_list, &pfd);

#ifdef G_ENABLE_DEBUG
  _gdk_win32_gl_print_pfd (&pfd);
#endif

  /*
   * Determine whether requested pixel format is supported.
   */

  /* Get DC. */
  hdc = GetDC (NULL);
  if (hdc == NULL)
    {
      g_warning ("cannot get DC");
      return NULL;
    }

  pixel_format = _gdk_win32_gl_config_find_pixel_format (hdc, &pfd, &pfd);

  /* Release DC. */
  ReleaseDC (NULL, hdc);

  if (pixel_format == 0)
    return NULL;

  GDK_GL_NOTE (MISC, g_message (" -- found pixel_format = 0x%x", pixel_format));

#ifdef G_ENABLE_DEBUG
  _gdk_win32_gl_print_pfd (&pfd);
#endif

  /*
   * Instanciate the GdkGLConfigImplWin32 object.
   */

  return gdk_gl_config_new_common (screen, &pfd);
}

#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

GdkGLConfig *
gdk_win32_gl_config_new_from_pixel_format (int pixel_format)
{
  GdkScreen *screen;
  HDC hdc;
  PIXELFORMATDESCRIPTOR pfd;
  int result;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_win32_gl_config_new_from_pixel_format ()"));

  /*
   * Get PFD.
   */

  /* Get DC. */
  hdc = GetDC (NULL);
  if (hdc == NULL)
    {
      g_warning ("cannot get DC");
      return NULL;
    }

  result = DescribePixelFormat (hdc, pixel_format, sizeof (pfd), &pfd);

  /* Release DC. */
  ReleaseDC (NULL, hdc);

  if (result == 0)
    return NULL;

  GDK_GL_NOTE (MISC, g_message (" -- pixel_format = 0x%x", pixel_format));

#ifdef G_ENABLE_DEBUG
  _gdk_win32_gl_print_pfd (&pfd);
#endif

  /*
   * Instanciate the GdkGLConfigImplWin32 object.
   */

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  screen = gdk_screen_get_default ();
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
  screen = NULL;
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

  return gdk_gl_config_new_common (screen, &pfd);
}

PIXELFORMATDESCRIPTOR *
gdk_win32_gl_config_get_pfd (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return &(GDK_GL_CONFIG_IMPL_WIN32 (glconfig)->pfd);
}

/*
 * This code is based on lib/glut/win32_glx.c of GLUT by Nate Robins.
 */
static gboolean
gdk_win32_gl_config_get_attrib (GdkGLConfig *glconfig,
                                int          attribute,
                                int         *value)
{
  GdkGLConfigImplWin32 *impl;

  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  impl = GDK_GL_CONFIG_IMPL_WIN32 (glconfig);

  switch (attribute)
    {
    case GDK_GL_USE_GL:
      if (impl->pfd.dwFlags & PFD_SUPPORT_OPENGL)
        {
	  *value = 1;

          /* Mark J. Kilgard says ...
	     XXX Brad's Matrox Millenium II has problems creating
             color index windows in 24-bit mode (lead to GDI crash)
             and 32-bit mode (lead to black window).  The cColorBits
             filed of the PIXELFORMATDESCRIPTOR returned claims to
             have 24 and 32 bits respectively of color indices. 2^24
             and 2^32 are ridiculously huge writable colormaps.
             Assume that if we get back a color index
             PIXELFORMATDESCRIPTOR with 24 or more bits, the
             PIXELFORMATDESCRIPTOR doesn't really work and skip it.
             -mjk */
#if 0
          if (impl->pfd.iPixelType == PFD_TYPE_COLORINDEX &&
	      impl->pfd.cColorBits >= 24)
            *value = 0;
          else
            *value = 1;
#endif
        }
      else
        {
          *value = 0;
        }
      break;
    case GDK_GL_BUFFER_SIZE:
      /* Nate Robins says ...
	 KLUDGE: if we're RGBA, return the number of bits/pixel,
         otherwise, return 8 (we guessed at 256 colors in CI mode). */
      if (impl->pfd.iPixelType == PFD_TYPE_RGBA)
        *value = impl->pfd.cColorBits;
      else
        *value = 8;
      break;
    case GDK_GL_LEVEL:
      *value = glconfig->layer_plane;
      break;
    case GDK_GL_RGBA:
      *value = impl->pfd.iPixelType == PFD_TYPE_RGBA;
      break;
    case GDK_GL_DOUBLEBUFFER:
      *value = impl->pfd.dwFlags & PFD_DOUBLEBUFFER;
      break;
    case GDK_GL_STEREO:
      *value = impl->pfd.dwFlags & PFD_STEREO;
      break;
    case GDK_GL_AUX_BUFFERS:
      *value = impl->pfd.cAuxBuffers;
      break;
    case GDK_GL_RED_SIZE:
      *value = impl->pfd.cRedBits;
      break;
    case GDK_GL_GREEN_SIZE:
      *value = impl->pfd.cGreenBits;
      break;
    case GDK_GL_BLUE_SIZE:
      *value = impl->pfd.cBlueBits;
      break;
    case GDK_GL_ALPHA_SIZE:
      *value = impl->pfd.cAlphaBits;
      break;
    case GDK_GL_DEPTH_SIZE:
      *value = impl->pfd.cDepthBits;
      break;
    case GDK_GL_STENCIL_SIZE:
      *value = impl->pfd.cStencilBits;
      break;
    case GDK_GL_ACCUM_RED_SIZE:
      *value = impl->pfd.cAccumRedBits;
      break;
    case GDK_GL_ACCUM_GREEN_SIZE:
      *value = impl->pfd.cAccumGreenBits;
      break;
    case GDK_GL_ACCUM_BLUE_SIZE:
      *value = impl->pfd.cAccumBlueBits;
      break;
    case GDK_GL_ACCUM_ALPHA_SIZE:
      *value = impl->pfd.cAccumAlphaBits;
      break;
    default:
      return FALSE;
    }

  return TRUE;
}

void
_gdk_win32_gl_print_pfd (PIXELFORMATDESCRIPTOR *pfd)
{
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_DRAW_TO_WINDOW      = %s",
                                (pfd->dwFlags & PFD_DRAW_TO_WINDOW)      ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_DRAW_TO_BITMAP      = %s",
                                (pfd->dwFlags & PFD_DRAW_TO_BITMAP)      ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_SUPPORT_GDI         = %s",
                                (pfd->dwFlags & PFD_SUPPORT_GDI)         ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_SUPPORT_OPENGL      = %s",
                                (pfd->dwFlags & PFD_SUPPORT_OPENGL)      ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_GENERIC_ACCELERATED = %s",
                                (pfd->dwFlags & PFD_GENERIC_ACCELERATED) ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_GENERIC_FORMAT      = %s",
                                (pfd->dwFlags & PFD_GENERIC_FORMAT)      ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_NEED_PALETTE        = %s",
                                (pfd->dwFlags & PFD_NEED_PALETTE)        ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_NEED_SYSTEM_PALETTE = %s",
                                (pfd->dwFlags & PFD_NEED_SYSTEM_PALETTE) ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_DOUBLEBUFFER        = %s",
                                (pfd->dwFlags & PFD_DOUBLEBUFFER)        ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_STEREO              = %s",
                                (pfd->dwFlags & PFD_STEREO)              ? "TRUE" : "FALSE"));
  /*
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_SWAP_LAYER_BUFFERS  = %s",
                                (pfd->dwFlags & PFD_SWAP_LAYER_BUFFERS)  ? "TRUE" : "FALSE"));
  */

  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_DEPTH_DONTCARE        = %s",
                                (pfd->dwFlags & PFD_DEPTH_DONTCARE)        ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_DOUBLEBUFFER_DONTCARE = %s",
                                (pfd->dwFlags & PFD_DOUBLEBUFFER_DONTCARE) ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_STEREO_DONTCARE       = %s",
                                (pfd->dwFlags & PFD_STEREO_DONTCARE)       ? "TRUE" : "FALSE"));

  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_SWAP_COPY     = %s",
                                (pfd->dwFlags & PFD_SWAP_COPY)     ? "TRUE" : "FALSE"));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwFlags & PFD_SWAP_EXCHANGE = %s",
                                (pfd->dwFlags & PFD_SWAP_EXCHANGE) ? "TRUE" : "FALSE"));

  GDK_GL_NOTE (MISC, g_message (" -- pfd->iPixelType = %d (%s)",
                                pfd->iPixelType,
                                (pfd->iPixelType == PFD_TYPE_RGBA) ? "PFD_TYPE_RGBA" : "PFD_TYPE_COLORINDEX"));

  GDK_GL_NOTE (MISC, g_message (" -- pfd->cColorBits      = %d", pfd->cColorBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cRedBits        = %d", pfd->cRedBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cRedShift       = %d", pfd->cRedShift));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cGreenBits      = %d", pfd->cGreenBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cGreenShift     = %d", pfd->cGreenShift));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cBlueBits       = %d", pfd->cBlueBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cBlueShift      = %d", pfd->cBlueShift));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cAlphaBits      = %d", pfd->cAlphaBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cAlphaShift     = %d", pfd->cAlphaShift));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cAccumBits      = %d", pfd->cAccumBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cAccumRedBits   = %d", pfd->cAccumRedBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cAccumGreenBits = %d", pfd->cAccumGreenBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cAccumBlueBits  = %d", pfd->cAccumBlueBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cAccumAlphaBits = %d", pfd->cAccumAlphaBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cDepthBits      = %d", pfd->cDepthBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cStencilBits    = %d", pfd->cStencilBits));
  GDK_GL_NOTE (MISC, g_message (" -- pfd->cAuxBuffers     = %d", pfd->cAuxBuffers));

  /* Ignored */
  GDK_GL_NOTE (MISC, g_message (" -- pfd->iLayerType = %d", pfd->iLayerType));

  GDK_GL_NOTE (MISC, g_message (" -- pfd->bReserved & 0x0f        = %d", pfd->bReserved & 0x0f));
  GDK_GL_NOTE (MISC, g_message (" -- (pfd->bReserved & 0xf0) >> 4 = %d", (pfd->bReserved & 0xf0) >> 4));

  /* Ignored */
  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwLayerMask = 0x%lx", pfd->dwLayerMask));

  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwVisibleMask = 0x%lx", pfd->dwVisibleMask));

  GDK_GL_NOTE (MISC, g_message (" -- pfd->dwDamageMask = 0x%lx", pfd->dwDamageMask));
}
