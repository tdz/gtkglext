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

#include <gdk/gdkwindow.h>
#include "gdkglprivate.h"
#include "gdkglconfig.h"

enum {
  PROP_0,
  PROP_WINDOW,
};

static void     gdk_gl_config_init         (GdkGLConfig           *glconfig);
static void     gdk_gl_config_class_init   (GdkGLConfigClass      *klass);

static GObject *gdk_gl_config_constructor  (GType                  type,
					    guint                  n_construct_properties,
					    GObjectConstructParam *construct_properties);
static void     gdk_gl_config_set_property (GObject               *object,
					    guint                  property_id,
					    const GValue          *value,
					    GParamSpec            *pspec);
static void     gdk_gl_config_get_property (GObject               *object,
					    guint                  property_id,
					    GValue                *value,
					    GParamSpec            *pspec);
static void     gdk_gl_config_finalize     (GObject               *object);

static gpointer parent_class = NULL;

GType
gdk_gl_config_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLConfigClass),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_config_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLConfig),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_config_init,
      };

      type = g_type_register_static (G_TYPE_OBJECT,
                                     "GdkGLConfig",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_config_init (GdkGLConfig *glconfig)
{
  /* 0-initialization is good for all other fields. */

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_init ()"));

  glconfig->is_double_buffer = FALSE;
  glconfig->is_stereo = FALSE;
}

static void
gdk_gl_config_class_init (GdkGLConfigClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor  = gdk_gl_config_constructor;
  object_class->set_property = gdk_gl_config_set_property;
  object_class->get_property = gdk_gl_config_get_property;
  object_class->finalize     = gdk_gl_config_finalize;
  
  g_object_class_install_property (object_class,
                                   PROP_WINDOW,
                                   g_param_spec_object ("window",
							_("Window"),
							_("GdkWindow object."),
							GDK_TYPE_WINDOW,
							G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

static GObject *
gdk_gl_config_constructor (GType                  type,
			   guint                  n_construct_properties,
			   GObjectConstructParam *construct_properties)
{
  GObject *object;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_constructor ()"));

  return object;
}

static void
gdk_gl_config_set_property (GObject      *object,
			    guint         property_id,
			    const GValue *value,
			    GParamSpec   *pspec)
{
  GdkGLConfig *glconfig = GDK_GL_CONFIG (object);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_set_property ()"));

  switch (property_id)
    {
    case PROP_WINDOW:
      glconfig->window = g_value_get_object (value);
      g_object_ref (G_OBJECT (glconfig->window));
      g_object_notify (object, "window");
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_config_get_property (GObject    *object,
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
gdk_gl_config_finalize (GObject *object)
{
  GdkGLConfig *glconfig = GDK_GL_CONFIG (object);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_config_finalize ()"));

  if (glconfig->window != NULL)
    {
      g_object_unref (G_OBJECT (glconfig->window));
      glconfig->window = NULL;
    }

  if (glconfig->colormap != NULL)
    {
      g_object_unref (G_OBJECT (glconfig->colormap));
      glconfig->colormap = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

gboolean
gdk_gl_config_get_attrib (GdkGLConfig *glconfig,
                          gint         attribute,
                          gint        *value)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return GDK_GL_CONFIG_GET_CLASS (glconfig)->get_attrib (glconfig, attribute, value);
}

GdkWindow *
gdk_gl_config_get_window (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return glconfig->window;
}

GdkColormap *
gdk_gl_config_get_colormap (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);

  return glconfig->colormap;
}

gint
gdk_gl_config_get_depth (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->depth;
}

gboolean
gdk_gl_config_is_double_buffer (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->is_double_buffer;
}

gboolean
gdk_gl_config_is_stereo (GdkGLConfig *glconfig)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), FALSE);

  return glconfig->is_stereo;
}
