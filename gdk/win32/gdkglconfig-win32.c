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
  PROP_ATTRIB_LIST
};

/* Forward declarations */
static gboolean gdk_win32_gl_config_get_attrib        (GdkGLConfig               *glconfig,
                                                       gint                       attribute,
                                                       gint                      *value);

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
                                   PROP_ATTRIB_LIST,
                                   g_param_spec_pointer ("attrib_list",
                                                        _("Attrib list"),
                                                        _("Pointer to the OpenGL configuration attribute list."),
                                                        G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

/*
 * Find an appropriate pixel format.
 * Basic idea of this code is ripped from FLTK.
 */
int
_gdk_win32_gl_config_find_pixel_format (HDC                          hdc,
					CONST PIXELFORMATDESCRIPTOR* req_pfd,
					PIXELFORMATDESCRIPTOR*       found_pfd)
{
  PIXELFORMATDESCRIPTOR pfd, chosen_pfd;
  int pixel_format = 0;
  int i;

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

static GObject *
gdk_gl_config_impl_win32_constructor (GType                  type,
                                      guint                  n_construct_properties,
                                      GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLConfig *glconfig;
  GdkGLConfigImplWin32 *impl;

  HDC hdc;
  PIXELFORMATDESCRIPTOR found_pfd;
  int pixel_format;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_win32_constructor ()"));

  glconfig = GDK_GL_CONFIG (object);
  impl = GDK_GL_CONFIG_IMPL_WIN32 (object);

  /*
   * Get DC.
   */

  hdc = GetDC (NULL);
  if (hdc == NULL)
    {
      g_warning ("cannot get DC");
      goto FAIL;
    }

  /*
   * Determine whether requested pixel format is supported.
   */

  pixel_format = _gdk_win32_gl_config_find_pixel_format (hdc,
							 &(impl->pfd),
							 &found_pfd);
  if (pixel_format == 0)
    goto FAIL;

  /*
   * Setup PFD from the found description.
   */

  impl->pfd = found_pfd;

  /*
   * Set depth (number of bits per pixel).
   */

  glconfig->depth = found_pfd.cRedBits +
                    found_pfd.cGreenBits +
                    found_pfd.cBlueBits;

  /*
   * Get colormap.
   */

  glconfig->colormap = g_object_ref (G_OBJECT (gdk_colormap_get_system ()));

  /*
   * Get configuration results.
   */

  /* RGBA mode? */
  glconfig->is_rgba = (impl->pfd.iPixelType == PFD_TYPE_RGBA) ? TRUE : FALSE;

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

 FAIL:

  /*
   * Release DC.
   */

  if (hdc != NULL)
    ReleaseDC (NULL, hdc);

  return object;
}

/*
 * This code is based on lib/glut/win32_glx.c of GLUT by Nate Robins.
 */
static void
parse_attrib_list (GdkGLConfig *glconfig,
		   int         *attrib_list)
{
  GdkGLConfigImplWin32 *impl = GDK_GL_CONFIG_IMPL_WIN32 (glconfig);
  PIXELFORMATDESCRIPTOR *pfd = &(impl->pfd);
  int *p;
  gboolean buffer_size_is_specified = FALSE;
  BYTE buffer_size;

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
  glconfig->layer_plane = 0;
  pfd->iLayerType = PFD_MAIN_PLANE;

  p = attrib_list;
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
	  glconfig->layer_plane = *(++p);
	  /* Ignored. Earlier implementations of OpenGL used this member,
	     but it is no longer used. */
	  if (glconfig->layer_plane > 0)
	    pfd->iLayerType = PFD_OVERLAY_PLANE;
	  else if (glconfig->layer_plane < 0)
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

static void
gdk_gl_config_impl_win32_set_property (GObject      *object,
                                       guint         property_id,
                                       const GValue *value,
                                       GParamSpec   *pspec)
{
  GdkGLConfig *glconfig = GDK_GL_CONFIG (object);
  int *attrib_list;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_config_impl_win32_set_property ()"));

  switch (property_id)
    {
    case PROP_ATTRIB_LIST:
      attrib_list = g_value_get_pointer (value);
      if (attrib_list != NULL)
	parse_attrib_list (glconfig, attrib_list);
      g_object_notify (object, "attrib_list");
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

GdkGLConfig *
gdk_gl_config_new (const int *attrib_list)
{
  GdkGLConfig *glconfig;
  GdkGLConfigImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_new ()"));

  /*
   * Instanciate the GdkGLConfigImplWin32 object.
   */

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT
  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_WIN32,
                           "screen",      gdk_screen_get_default (),
                           "attrib_list", attrib_list,
                           NULL);
#else  /* GDKGLEXT_MULTIHEAD_SUPPORT */
  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_WIN32,
                           "screen",      NULL,
                           "attrib_list", attrib_list,
                           NULL);
#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

  impl = GDK_GL_CONFIG_IMPL_WIN32 (glconfig);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glconfig));
      return NULL;
    }

  return glconfig;
}

#ifdef GDKGLEXT_MULTIHEAD_SUPPORT

GdkGLConfig *
gdk_gl_config_new_for_screen (GdkScreen *screen,
                              const int *attrib_list)
{
  GdkGLConfig *glconfig;
  GdkGLConfigImplWin32 *impl;

  g_return_val_if_fail (screen == gdk_screen_get_default (), NULL);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_new ()"));

  /*
   * Instanciate the GdkGLConfigImplWin32 object.
   */

  glconfig = g_object_new (GDK_TYPE_GL_CONFIG_IMPL_WIN32,
                           "screen",      screen,
                           "attrib_list", attrib_list,
                           NULL);
  impl = GDK_GL_CONFIG_IMPL_WIN32 (glconfig);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glconfig));
      return NULL;
    }

  return glconfig;
}

#endif /* GDKGLEXT_MULTIHEAD_SUPPORT */

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
