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

#include "gdkglconfig.h"
#include "gdkglprivate-win32.h"
#include "gdkglcontext-win32.h"

static void          gdk_gl_context_insert (GdkGLContext *glcontext);
static void          gdk_gl_context_remove (GdkGLContext *glcontext);
static GdkGLContext *gdk_gl_context_lookup (HGLRC         hglrc);
static guint         gdk_gl_context_hash   (HGLRC        *hglrc);
static gboolean      gdk_gl_context_equal  (HGLRC        *a,
                                            HGLRC        *b);

static GHashTable *gl_context_ht = NULL;

static void     gdk_gl_context_impl_win32_init        (GdkGLContextImplWin32      *impl);
static void     gdk_gl_context_impl_win32_class_init  (GdkGLContextImplWin32Class *klass);

static GObject *gdk_gl_context_impl_win32_constructor (GType                       type,
                                                       guint                       n_construct_properties,
                                                       GObjectConstructParam      *construct_properties);
static void     gdk_gl_context_impl_win32_finalize    (GObject                    *object);

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

  object_class->constructor = gdk_gl_context_impl_win32_constructor;
  object_class->finalize    = gdk_gl_context_impl_win32_finalize;
}

static GObject *
gdk_gl_context_impl_win32_constructor (GType                  type,
                                       guint                  n_construct_properties,
                                       GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLContext *glcontext;
  GdkGLContextImplWin32 *impl;

  GdkGLContextImplWin32 *share_impl = NULL;

  HDC hdc;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_constructor ()"));

  glcontext = GDK_GL_CONTEXT (object);
  impl = GDK_GL_CONTEXT_IMPL_WIN32 (object);

  /*
   * Get DC.
   */

  hdc = gdk_win32_gl_drawable_hdc_get (glcontext->gldrawable);
  if (hdc == NULL)
    goto FAIL;

  /*
   * Create an OpenGL rendering context.
   */

  impl->hglrc = wglCreateContext (hdc);
  if (impl->hglrc == NULL)
    goto FAIL;

  if (glcontext->share_list != NULL)
    {
      share_impl = GDK_GL_CONTEXT_IMPL_WIN32 (glcontext->share_list);
      if (!wglShareLists (share_impl->hglrc, impl->hglrc))
        goto FAIL;
    }

  /*
   * Release DC.
   */

  gdk_win32_gl_drawable_hdc_release (glcontext->gldrawable);

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

  return object;

 FAIL:

  if (impl->hglrc != NULL)
    wglDeleteContext (impl->hglrc);

  if (hdc != NULL)
    gdk_win32_gl_drawable_hdc_release (glcontext->gldrawable);

  impl->hglrc = NULL;

  return object;
}

static void
gdk_gl_context_impl_win32_finalize (GObject *object)
{
  GdkGLContextImplWin32 *impl = GDK_GL_CONTEXT_IMPL_WIN32 (object);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_win32_finalize ()"));

  gdk_gl_context_remove (glcontext);

  /*
   * Destroy rendering context.
   */

  if (impl->hglrc != NULL)
    {
      if (impl->hglrc == wglGetCurrentContext ())
        wglMakeCurrent (NULL, NULL);

      wglDeleteContext (impl->hglrc);
      impl->hglrc = NULL;
    }

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

GdkGLContext *
_gdk_win32_gl_context_new (GdkGLDrawable *gldrawable,
                           GdkGLConfig   *glconfig,
                           GdkGLContext  *share_list,
                           gboolean       direct,
                           int            render_type)
{
  GdkGLContext *glcontext;
  GdkGLContextImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_new ()"));

  /*
   * Instanciate the GdkGLContextImplWin32 object.
   */

  glcontext = g_object_new (GDK_TYPE_GL_CONTEXT_IMPL_WIN32,
                            "gldrawable",      gldrawable,
                            "gldrawable_read", NULL,
                            "glconfig",        glconfig,
                            "share_list",      share_list,
                            "is_direct",       direct,
                            "render_type",     render_type,
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

gboolean
gdk_gl_context_copy (GdkGLContext  *dst_glcontext,
                     GdkGLContext  *src_glcontext,
                     unsigned long  mask)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (dst_glcontext), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (src_glcontext), FALSE);

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

static void
gdk_gl_context_insert (GdkGLContext *glcontext)
{
  GdkGLContextImplWin32 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_insert ()"));

  g_return_if_fail (GDK_IS_GL_CONTEXT (glcontext));

  if (!gl_context_ht)
    gl_context_ht = g_hash_table_new ((GHashFunc) gdk_gl_context_hash,
                                      (GEqualFunc) gdk_gl_context_equal);

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
    gl_context_ht = g_hash_table_new ((GHashFunc) gdk_gl_context_hash,
                                      (GEqualFunc) gdk_gl_context_equal);

  impl = GDK_GL_CONTEXT_IMPL_WIN32 (glcontext);

  g_hash_table_remove (gl_context_ht, &(impl->hglrc));
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
