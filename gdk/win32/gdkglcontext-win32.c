/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002-2003  Naofumi Yasufuku
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

#include "gdkglconfig.h"
#include "gdkglprivate-win32.h"
#include "gdkglcontext-win32.h"

enum {
  PROP_0,
  PROP_HGLRC,
  PROP_IS_FOREIGN
};

static void          gdk_gl_context_insert (GdkGLContext *glcontext);
static void          gdk_gl_context_remove (GdkGLContext *glcontext);
static GdkGLContext *gdk_gl_context_lookup (HGLRC         hglrc);
static guint         gdk_gl_context_hash   (HGLRC        *hglrc);
static gboolean      gdk_gl_context_equal  (HGLRC        *a,
                                            HGLRC        *b);

static void     gdk_gl_context_impl_win32_init         (GdkGLContextImplWin32      *impl);
static void     gdk_gl_context_impl_win32_class_init   (GdkGLContextImplWin32Class *klass);

static GObject *gdk_gl_context_impl_win32_constructor  (GType                       type,
                                                        guint                       n_construct_properties,
                                                        GObjectConstructParam      *construct_properties);
static void     gdk_gl_context_impl_win32_set_property (GObject                    *object,
                                                        guint                       property_id,
                                                        const GValue               *value,
                                                        GParamSpec                 *pspec);
static void     gdk_gl_context_impl_win32_get_property (GObject                    *object,
                                                        guint                       property_id,
                                                        GValue                     *value,
                                                        GParamSpec                 *pspec);
static void     gdk_gl_context_impl_win32_finalize     (GObject                    *object);

static gpointer parent_class = NULL;

GType
gdk_gl_context_impl_win32_get_type (void)
{
  static GType type = 0;

  if (!type)
    {
      static const GTypeInfo type_info = {
        sizeof (GdkGLContextImplWin32Class),
        (GBaseInitFunc) NULL,
        (GBaseFinalizeFunc) NULL,
        (GClassInitFunc) gdk_gl_context_impl_win32_class_init,
        (GClassFinalizeFunc) NULL,
        NULL,                   /* class_data */
        sizeof (GdkGLContextImplWin32),
        0,                      /* n_preallocs */
        (GInstanceInitFunc) gdk_gl_context_impl_win32_init,
      };

      type = g_type_register_static (GDK_TYPE_GL_CONTEXT,
                                     "GdkGLContextImplWin32",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_context_impl_win32_init (GdkGLContextImplWin32 *impl)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_init ()"));

  impl->is_constructed = FALSE;
}

static void
gdk_gl_context_impl_win32_class_init (GdkGLContextImplWin32Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->constructor  = gdk_gl_context_impl_win32_constructor;
  object_class->set_property = gdk_gl_context_impl_win32_set_property;
  object_class->get_property = gdk_gl_context_impl_win32_get_property;
  object_class->finalize     = gdk_gl_context_impl_win32_finalize;

  g_object_class_install_property (object_class,
                                   PROP_HGLRC,
                                   g_param_spec_pointer ("hglrc",
                                                         "HGLRC",
                                                         "Hangle to the OpenGL rendering context.",
                                                         G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
  g_object_class_install_property (object_class,
                                   PROP_IS_FOREIGN,
                                   g_param_spec_boolean ("is_foreign",
                                                         "Is foreign",
                                                         "Foreign HGLRC.",
                                                         FALSE,
                                                         G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
}

static GObject *
gdk_gl_context_impl_win32_constructor (GType                  type,
                                       guint                  n_construct_properties,
                                       GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLContext *glcontext;
  GdkGLContextImplWin32 *impl;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_constructor ()"));

  glcontext = GDK_GL_CONTEXT (object);
  impl = GDK_GL_CONTEXT_IMPL_WIN32 (object);

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

  return object;
}

static void
gdk_gl_context_impl_win32_set_property (GObject      *object,
                                        guint         property_id,
                                        const GValue *value,
                                        GParamSpec   *pspec)
{
  GdkGLContextImplWin32 *impl = GDK_GL_CONTEXT_IMPL_WIN32 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_set_property ()"));

  switch (property_id)
    {
    case PROP_HGLRC:
      impl->hglrc = g_value_get_pointer (value);
      g_object_notify (object, "hglrc");
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
gdk_gl_context_impl_win32_get_property (GObject    *object,
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
gdk_gl_context_impl_win32_finalize (GObject *object)
{
  GdkGLContext *glcontext = GDK_GL_CONTEXT (object);
  GdkGLContextImplWin32 *impl = GDK_GL_CONTEXT_IMPL_WIN32 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_finalize ()"));

  gdk_gl_context_remove (glcontext);

  /*
   * Destroy rendering context.
   */

  if (impl->hglrc != NULL && !impl->is_foreign)
    {
      if (impl->hglrc == wglGetCurrentContext ())
        {
          GDK_GL_NOTE (IMPL, g_message (" * wglMakeCurrent ()"));

          wglMakeCurrent (NULL, NULL);
        }

      GDK_GL_NOTE (IMPL, g_message (" * wglDeleteContext ()"));

      wglDeleteContext (impl->hglrc);
      impl->hglrc = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GdkGLContext *
gdk_gl_context_new_common (GdkGLDrawable *gldrawable,
                           GdkGLConfig   *glconfig,
                           GdkGLContext  *share_list,
                           gboolean       is_direct,
                           int            render_type,
                           HGLRC          hglrc,
                           gboolean       is_foreign)
{
  GdkGLContext *glcontext;
  GdkGLContextImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_new_common ()"));

  /*
   * Instanciate the GdkGLContextImplWin32 object.
   */

  glcontext = g_object_new (GDK_TYPE_GL_CONTEXT_IMPL_WIN32,
                            "gldrawable",      gldrawable,
                            "gldrawable_read", NULL,
                            "glconfig",        glconfig,
                            "share_list",      share_list,
                            "is_direct",       is_direct,
                            "render_type",     render_type,
                            "hglrc",           hglrc,
                            "is_foreign",      is_foreign,
                            NULL);
  impl = GDK_GL_CONTEXT_IMPL_WIN32 (glcontext);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glcontext));
      return NULL;
    }

  gdk_gl_context_insert (glcontext);

  return glcontext;
}

GdkGLContext *
_gdk_win32_gl_context_new (GdkGLDrawable *gldrawable,
                           GdkGLConfig   *glconfig,
                           GdkGLContext  *share_list,
                           gboolean       direct,
                           int            render_type)
{
  HDC hdc;
  HGLRC hglrc;
  GdkGLContextImplWin32 *share_impl = NULL;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_new ()"));

  /*
   * Create an OpenGL rendering context.
   */

  /* Get DC. */
  hdc = gdk_win32_gl_drawable_hdc_get (gldrawable);
  if (hdc == NULL)
    return NULL;

  GDK_GL_NOTE (IMPL, g_message (" * wglCreateContext ()"));

  hglrc = wglCreateContext (hdc);

  /* Release DC. */
  gdk_win32_gl_drawable_hdc_release (gldrawable);

  if (hglrc == NULL)
    return NULL;

  if (share_list != NULL)
    {
      GDK_GL_NOTE (IMPL, g_message (" * wglShareLists ()"));

      share_impl = GDK_GL_CONTEXT_IMPL_WIN32 (share_list);
      if (!wglShareLists (share_impl->hglrc, hglrc))
        {
          wglDeleteContext (hglrc);
          return NULL;
        }
    }

  /*
   * Instanciate the GdkGLContextImplWin32 object.
   */

  return gdk_gl_context_new_common (gldrawable,
                                    glconfig,
                                    share_list,
                                    direct,
                                    render_type,
                                    hglrc,
                                    FALSE);
}

GdkGLContext *
gdk_win32_gl_context_foreign_new (GdkGLConfig  *glconfig,
                                  GdkGLContext *share_list,
                                  HGLRC         hglrc)
{
  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);
  g_return_val_if_fail (hglrc != NULL, NULL);

  GDK_GL_NOTE (FUNC, g_message (" - gdk_win32_gl_context_foreign_new ()"));

  /*
   * Instanciate the GdkGLContextImplWin32 object.
   */

  return gdk_gl_context_new_common (NULL,
                                    glconfig,
                                    share_list,
                                    FALSE,
                                    (glconfig->is_rgba) ? GDK_GL_RGBA_TYPE : GDK_GL_COLOR_INDEX_TYPE,
                                    hglrc,
                                    TRUE);
}

gboolean
gdk_gl_context_copy (GdkGLContext  *dst_glcontext,
                     GdkGLContext  *src_glcontext,
                     unsigned long  mask)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (dst_glcontext), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (src_glcontext), FALSE);

  GDK_GL_NOTE (IMPL, g_message (" * wglCopyContext ()"));

  return wglCopyContext (GDK_GL_CONTEXT_HGLRC (src_glcontext),
                         GDK_GL_CONTEXT_HGLRC (dst_glcontext),
                         mask);
}

GdkGLContext *
gdk_gl_context_get_current (void)
{
  static GdkGLContext *current = NULL;
  HGLRC hglrc;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_get_current ()"));

  hglrc = wglGetCurrentContext ();

  if (!hglrc)
    return NULL;

  if (current && GDK_GL_CONTEXT_HGLRC (current) == hglrc)
    return current;

  current = gdk_gl_context_lookup (hglrc);

  return current;
}

HGLRC
gdk_win32_gl_context_get_hglrc (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), NULL);

  return GDK_GL_CONTEXT_IMPL_WIN32 (glcontext)->hglrc;
}

/*
 * GdkGLContext hash table.
 */

static GHashTable *gl_context_ht = NULL;

static void
gdk_gl_context_insert (GdkGLContext *glcontext)
{
  GdkGLContextImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_insert ()"));

  g_return_if_fail (GDK_IS_GL_CONTEXT (glcontext));

  if (!gl_context_ht)
    {
      GDK_GL_NOTE (MISC, g_message (" -- Create GL context hash table."));
      gl_context_ht = g_hash_table_new ((GHashFunc) gdk_gl_context_hash,
                                        (GEqualFunc) gdk_gl_context_equal);
    }

  impl = GDK_GL_CONTEXT_IMPL_WIN32 (glcontext);

  g_hash_table_insert (gl_context_ht, &(impl->hglrc), glcontext);
}

static void
gdk_gl_context_remove (GdkGLContext *glcontext)
{
  GdkGLContextImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_remove ()"));

  g_return_if_fail (GDK_IS_GL_CONTEXT (glcontext));

  if (!gl_context_ht)
    return;

  impl = GDK_GL_CONTEXT_IMPL_WIN32 (glcontext);

  g_hash_table_remove (gl_context_ht, &(impl->hglrc));

  if (g_hash_table_size (gl_context_ht) == 0)
    {
      GDK_GL_NOTE (MISC, g_message (" -- Destroy GL context hash table."));
      g_hash_table_destroy (gl_context_ht);
      gl_context_ht = NULL;
    }
}

static GdkGLContext *
gdk_gl_context_lookup (HGLRC hglrc)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_lookup ()"));

  if (!gl_context_ht)
    return NULL;

  return g_hash_table_lookup (gl_context_ht, &hglrc);
}

static guint
gdk_gl_context_hash (HGLRC *hglrc)
{
  return (guint) *hglrc;
}

static gboolean
gdk_gl_context_equal (HGLRC *a,
                      HGLRC *b)
{
  return (*a == *b);
}
