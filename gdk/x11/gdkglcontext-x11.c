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

#include <gdk/gdk.h>            /* for gdk_error_trap_(push|pop) () */

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkgldrawable.h"
#include "gdkglconfig-x11.h"
#include "gdkglcontext-x11.h"

enum {
  PROP_0,
  PROP_GLXCONTEXT,
  PROP_IS_FOREIGN
};

static void          gdk_gl_context_insert (GdkGLContext *glcontext);
static void          gdk_gl_context_remove (GdkGLContext *glcontext);
static GdkGLContext *gdk_gl_context_lookup (GLXContext    glxcontext);
static guint         gdk_gl_context_hash   (GLXContext   *glxcontext);
static gboolean      gdk_gl_context_equal  (GLXContext   *a,
                                            GLXContext   *b);

static void     gdk_gl_context_impl_x11_init         (GdkGLContextImplX11      *impl);
static void     gdk_gl_context_impl_x11_class_init   (GdkGLContextImplX11Class *klass);

static GObject *gdk_gl_context_impl_x11_constructor  (GType                     type,
                                                      guint                     n_construct_properties,
                                                      GObjectConstructParam    *construct_properties);
static void     gdk_gl_context_impl_x11_set_property (GObject                  *object,
                                                      guint                     property_id,
                                                      const GValue             *value,
                                                      GParamSpec               *pspec);
static void     gdk_gl_context_impl_x11_get_property (GObject                  *object,
                                                      guint                     property_id,
                                                      GValue                   *value,
                                                      GParamSpec               *pspec);
static void     gdk_gl_context_impl_x11_finalize     (GObject                  *object);

static gpointer parent_class = NULL;

GType
gdk_gl_context_impl_x11_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLContextImplX11Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_context_impl_x11_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLContextImplX11),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_context_impl_x11_init,
      };

      type = g_type_register_static (GDK_TYPE_GL_CONTEXT,
                                     "GdkGLContextImplX11",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_context_impl_x11_init (GdkGLContextImplX11 *impl)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_context_impl_x11_class_init (GdkGLContextImplX11Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor  = gdk_gl_context_impl_x11_constructor;
  object_class->set_property = gdk_gl_context_impl_x11_set_property;
  object_class->get_property = gdk_gl_context_impl_x11_get_property;
  object_class->finalize     = gdk_gl_context_impl_x11_finalize;

  g_object_class_install_property (object_class,
                                   PROP_GLXCONTEXT,
                                   g_param_spec_pointer ("glxcontext",
                                                         "GLXContext",
                                                         "Pointer to the GLXContext.",
                                                         G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
  g_object_class_install_property (object_class,
                                   PROP_IS_FOREIGN,
                                   g_param_spec_boolean ("is_foreign",
                                                         "Is foreign",
                                                         "Foreign GLXContext.",
                                                         FALSE,
                                                         G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

static GObject *
gdk_gl_context_impl_x11_constructor (GType                  type,
                                     guint                  n_construct_properties,
                                     GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLContext *glcontext;
  GdkGLContextImplX11 *impl;

  Display *xdisplay;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_constructor ()"));

  glcontext = GDK_GL_CONTEXT (object);
  impl = GDK_GL_CONTEXT_IMPL_X11 (object);

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glcontext->glconfig);

  glcontext->is_direct = glXIsDirect (xdisplay, impl->glxcontext) ? TRUE : FALSE;

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

  return object;
}

static void
gdk_gl_context_impl_x11_set_property (GObject      *object,
                                      guint         property_id,
                                      const GValue *value,
                                      GParamSpec   *pspec)
{
  GdkGLContextImplX11 *impl = GDK_GL_CONTEXT_IMPL_X11 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_set_property ()"));

  switch (property_id)
    {
    case PROP_GLXCONTEXT:
      impl->glxcontext = *((GLXContext *) g_value_get_pointer (value));
      g_object_notify (object, "glxcontext");
      break;
    case PROP_IS_FOREIGN:
      impl->is_foreign = g_value_get_boolean (value);
      g_object_notify (object, "is_foreign");
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
    }
}

static void
gdk_gl_context_impl_x11_get_property (GObject    *object,
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
gdk_gl_context_impl_x11_finalize (GObject *object)
{
  GdkGLContext *glcontext = GDK_GL_CONTEXT (object);
  GdkGLContextImplX11 *impl = GDK_GL_CONTEXT_IMPL_X11 (object);
  Display *xdisplay;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_finalize ()"));

  gdk_gl_context_remove (glcontext);

  if (impl->glxcontext != NULL && !impl->is_foreign)
    {
      xdisplay = GDK_GL_CONFIG_XDISPLAY (glcontext->glconfig);

      GDK_GL_NOTE (IMPL, g_message (" * glXMakeCurrent ()"));

      if (impl->glxcontext == glXGetCurrentContext ())
        glXMakeCurrent (xdisplay, None, NULL);

      GDK_GL_NOTE (IMPL, g_message (" * glXDestroyContext ()"));

      glXDestroyContext (xdisplay, impl->glxcontext);
      impl->glxcontext = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GdkGLContext *
gdk_gl_context_new_common (GdkGLDrawable *gldrawable,
                           GdkGLConfig   *glconfig,
                           GdkGLContext  *share_list,
                           gboolean       is_direct,
                           int            render_type,
                           GLXContext    *glxcontext,
                           gboolean       is_foreign)
{
  GdkGLContext *glcontext;
  GdkGLContextImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_new_common ()"));

  /*
   * Instanciate the GdkGLContextImplX11 object.
   */

  glcontext = g_object_new (GDK_TYPE_GL_CONTEXT_IMPL_X11,
                            "gldrawable",      gldrawable,
                            "gldrawable_read", NULL,
                            "glconfig",        glconfig,
                            "share_list",      share_list,
                            "is_direct",       is_direct,
                            "render_type",     render_type,
                            "glxcontext",      glxcontext,
                            "is_foreign",      is_foreign,
                            NULL);
  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glcontext));
      return NULL;
    }

  gdk_gl_context_insert (glcontext);

  return glcontext;
}

GdkGLContext *
_gdk_x11_gl_context_new (GdkGLDrawable *gldrawable,
                         GdkGLConfig   *glconfig,
                         GdkGLContext  *share_list,
                         gboolean       direct,
                         int            render_type)
{
  GdkGLContextImplX11 *share_impl = NULL;
  GLXContext share_glxcontext = NULL;

  Display *xdisplay;
  XVisualInfo *xvinfo;
  GLXContext glxcontext;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_new ()"));

  /*
   * Create an OpenGL rendering context.
   */

  if (share_list != NULL)
    {
      share_impl = GDK_GL_CONTEXT_IMPL_X11 (share_list);
      share_glxcontext = share_impl->glxcontext;
    }

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glconfig);
  xvinfo = GDK_GL_CONFIG_XVINFO (glconfig);

  GDK_GL_NOTE (IMPL, g_message (" * glXCreateContext ()"));

  glxcontext = glXCreateContext (xdisplay,
                                 xvinfo,
                                 share_glxcontext,
                                 (direct == TRUE) ? True : False);
  if (glxcontext == NULL)
    return NULL;

  GDK_GL_NOTE (MISC,
    g_message (" -- Context: screen number = %d", xvinfo->screen));
  GDK_GL_NOTE (MISC,
    g_message (" -- Context: visual id = 0x%lx", xvinfo->visualid));

  /*
   * Instanciate the GdkGLContextImplX11 object.
   */

  return gdk_gl_context_new_common (gldrawable,
                                    glconfig,
                                    share_list,
                                    direct,
                                    render_type,
                                    &glxcontext,
                                    FALSE);
}

GdkGLContext *
gdk_x11_gl_context_foreign_new (GdkGLConfig  *glconfig,
                                GdkGLContext *share_list,
                                GLXContext    glxcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);
  g_return_val_if_fail (glxcontext != NULL, NULL);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_x11_gl_context_foreign_new ()"));

  /*
   * Instanciate the GdkGLContextImplX11 object.
   */

  return gdk_gl_context_new_common (NULL,
                                    glconfig,
                                    share_list,
                                    FALSE, /* is_direct is set by constructor() */
                                    (glconfig->is_rgba) ? GDK_GL_RGBA_TYPE : GDK_GL_COLOR_INDEX_TYPE,
                                    &glxcontext,
                                    TRUE);
}

/**
 * gdk_gl_context_copy:
 * @dst_glcontext: the destination context.
 * @src_glcontext: the source context.
 * @mask: which portions of @src_glcontext state are to be copied to @dst_glcontext.
 *
 * Copy state from one rendering context to another.
 *
 * Notice that dst and src arguments' order is different from glXCopyContext().
 *
 * @mask contains the bitwise-OR of the same symbolic names that are passed to
 * the glPushAttrib() function. You can use GL_ALL_ATTRIB_BITS to copy all the
 * rendering state information. 
 *
 * Return value: FALSE if it fails, TRUE otherwise.
 **/
gboolean
gdk_gl_context_copy (GdkGLContext  *dst_glcontext,
                     GdkGLContext  *src_glcontext,
                     unsigned long  mask)
{
  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_copy ()"));

  g_return_val_if_fail (GDK_IS_GL_CONTEXT (dst_glcontext), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (src_glcontext), FALSE);

  gdk_error_trap_push ();

  glXCopyContext (GDK_GL_CONFIG_XDISPLAY (dst_glcontext->glconfig),
                  GDK_GL_CONTEXT_GLXCONTEXT (src_glcontext),
                  GDK_GL_CONTEXT_GLXCONTEXT (dst_glcontext),
                  mask);

  return gdk_error_trap_pop () == Success;
}

/**
 * gdk_gl_context_get_current:
 *
 * Returns the current #GdkGLContext.
 *
 * Return value: the current #GdkGLContext or NULL if there is no current context.
 **/
GdkGLContext *
gdk_gl_context_get_current (void)
{
  static GdkGLContext *current = NULL;
  GLXContext glxcontext;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_get_current ()"));

  glxcontext = glXGetCurrentContext ();

  if (!glxcontext)
    return NULL;

  if (current && GDK_GL_CONTEXT_GLXCONTEXT (current) == glxcontext)
    return current;

  current = gdk_gl_context_lookup (glxcontext);

  return current;
}

/**
 * gdk_x11_gl_context_get_glxcontext:
 * @glcontext: a #GdkGLContext.
 *
 * Get GLXContext.
 *
 * Return value: the GLXContext.
 **/
GLXContext
gdk_x11_gl_context_get_glxcontext (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), NULL);

  return GDK_GL_CONTEXT_IMPL_X11 (glcontext)->glxcontext;
}

/*
 * GdkGLContext hash table.
 */

static GHashTable *gl_context_ht = NULL;

static void
gdk_gl_context_insert (GdkGLContext *glcontext)
{
  GdkGLContextImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_insert ()"));

  if (!gl_context_ht)
    {
      GDK_GL_NOTE (MISC, g_message (" -- Create GL context hash table."));
      gl_context_ht = g_hash_table_new ((GHashFunc) gdk_gl_context_hash,
                                        (GEqualFunc) gdk_gl_context_equal);
    }

  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  g_hash_table_insert (gl_context_ht, &(impl->glxcontext), glcontext);
}

static void
gdk_gl_context_remove (GdkGLContext *glcontext)
{
  GdkGLContextImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_remove ()"));

  if (!gl_context_ht)
    return;

  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  g_hash_table_remove (gl_context_ht, &(impl->glxcontext));

  if (g_hash_table_size (gl_context_ht) == 0)
    {
      GDK_GL_NOTE (MISC, g_message (" -- Destroy GL context hash table."));
      g_hash_table_destroy (gl_context_ht);
      gl_context_ht = NULL;
    }
}

static GdkGLContext *
gdk_gl_context_lookup (GLXContext glxcontext)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_lookup ()"));

  if (!gl_context_ht)
    return NULL;

  return g_hash_table_lookup (gl_context_ht, &glxcontext);
}

static guint
gdk_gl_context_hash (GLXContext *glxcontext)
{
  return (guint) *glxcontext;
}

static gboolean
gdk_gl_context_equal (GLXContext *a,
                      GLXContext *b)
{
  return (*a == *b);
}
