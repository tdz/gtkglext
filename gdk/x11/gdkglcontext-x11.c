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

#include <gdk/gdk.h>

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkgldrawable.h"
#include "gdkglconfig-x11.h"
#include "gdkglcontext-x11.h"

static void          gdk_x11_gl_context_insert (GdkGLContext *glcontext);
static void          gdk_x11_gl_context_remove (GdkGLContext *glcontext);
static guint         gdk_x11_gl_context_hash   (GLXContext   *glxcontext);
static gboolean      gdk_x11_gl_context_equal  (GLXContext   *a,
                                                GLXContext   *b);

static GHashTable *gl_context_ht = NULL;

static void     gdk_gl_context_impl_x11_init        (GdkGLContextImplX11      *impl);
static void     gdk_gl_context_impl_x11_class_init  (GdkGLContextImplX11Class *klass);

static GObject *gdk_gl_context_impl_x11_constructor (GType                     type,
                                                     guint                     n_construct_properties,
                                                     GObjectConstructParam    *construct_properties);
static void     gdk_gl_context_impl_x11_finalize    (GObject                  *object);

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

  object_class->constructor = gdk_gl_context_impl_x11_constructor;
  object_class->finalize    = gdk_gl_context_impl_x11_finalize;
}

static GObject *
gdk_gl_context_impl_x11_constructor (GType                  type,
                                     guint                  n_construct_properties,
                                     GObjectConstructParam *construct_properties)
{
  GObject *object;
  GdkGLContext *glcontext;
  GdkGLContextImplX11 *impl;

  GdkGLContextImplX11 *share_impl = NULL;
  GLXContext share_glxcontext = NULL;

  Display *xdisplay;
  XVisualInfo *xvinfo;

  object = G_OBJECT_CLASS (parent_class)->constructor (type,
                                                       n_construct_properties,
                                                       construct_properties);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_constructor ()"));

  glcontext = GDK_GL_CONTEXT (object);
  impl = GDK_GL_CONTEXT_IMPL_X11 (object);

  /*
   * Create an OpenGL rendering context.
   */

  if (glcontext->share_list != NULL)
    {
      share_impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext->share_list);
      share_glxcontext = share_impl->glxcontext;
    }

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glcontext->glconfig);
  xvinfo = GDK_GL_CONFIG_XVINFO (glcontext->glconfig);

  GDK_GL_NOTE (IMPL, g_message (" * glXCreateContext ()"));

  impl->glxcontext = glXCreateContext (xdisplay,
                                       xvinfo,
                                       share_glxcontext,
                                       glcontext->is_direct == TRUE ? True : False );
  if (impl->glxcontext == NULL)
    goto FAIL;

  glcontext->is_direct = glXIsDirect (xdisplay, impl->glxcontext) ? TRUE : FALSE;

  /*
   * Successfully constructed?
   */

  impl->is_constructed = TRUE;

 FAIL:
  return object;
}

static void
gdk_gl_context_impl_x11_finalize (GObject *object)
{
  GdkGLContext *glcontext = GDK_GL_CONTEXT (object);
  GdkGLContextImplX11 *impl = GDK_GL_CONTEXT_IMPL_X11 (object);
  Display *xdisplay;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_finalize ()"));

  gdk_x11_gl_context_remove (glcontext);

  if (impl->glxcontext != NULL)
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

GdkGLContext *
_gdk_x11_gl_context_new (GdkGLDrawable *gldrawable,
                         GdkGLConfig   *glconfig,
                         GdkGLContext  *share_list,
                         gboolean       direct,
                         int            render_type)
{
  GdkGLContext *glcontext;
  GdkGLContextImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_new ()"));

  /*
   * Instanciate the GdkGLContextImplX11 object.
   */

  glcontext = g_object_new (GDK_TYPE_GL_CONTEXT_IMPL_X11,
                            "gldrawable",      gldrawable,
                            "gldrawable_read", NULL,
                            "glconfig",        glconfig,
                            "share_list",      share_list,
                            "is_direct",       direct,
                            "render_type",     render_type,
                            NULL);
  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  if (!impl->is_constructed)
    {
      g_object_unref (G_OBJECT (glcontext));
      return NULL;
    }

  gdk_x11_gl_context_insert (glcontext);

  return glcontext;
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
  GLXContext glxcontext;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_get_current ()"));

  glxcontext = glXGetCurrentContext ();

  if (!glxcontext)
    return NULL;

  return gdk_x11_gl_context_lookup (glxcontext);
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

static void
gdk_x11_gl_context_insert (GdkGLContext *glcontext)
{
  GdkGLContextImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_x11_gl_context_insert ()"));

  g_return_if_fail (GDK_IS_GL_CONTEXT (glcontext));

  if (!gl_context_ht)
    gl_context_ht = g_hash_table_new ((GHashFunc) gdk_x11_gl_context_hash,
                                      (GEqualFunc) gdk_x11_gl_context_equal);

  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  g_hash_table_insert (gl_context_ht, &(impl->glxcontext), glcontext);
}

static void
gdk_x11_gl_context_remove (GdkGLContext *glcontext)
{
  GdkGLContextImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_x11_gl_context_remove ()"));

  g_return_if_fail (GDK_IS_GL_CONTEXT (glcontext));

  if (!gl_context_ht)
    gl_context_ht = g_hash_table_new ((GHashFunc) gdk_x11_gl_context_hash,
                                      (GEqualFunc) gdk_x11_gl_context_equal);

  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  g_hash_table_remove (gl_context_ht, &(impl->glxcontext));
}

GdkGLContext *
gdk_x11_gl_context_lookup (GLXContext glxcontext)
{
  GDK_GL_NOTE (FUNC, g_message (" -- gdk_x11_gl_context_lookup ()"));

  if (!gl_context_ht)
    return NULL;

  return g_hash_table_lookup (gl_context_ht, &glxcontext);
}

static guint
gdk_x11_gl_context_hash (GLXContext *glxcontext)
{
  return (guint) *glxcontext;
}

static gboolean
gdk_x11_gl_context_equal (GLXContext *a,
                          GLXContext *b)
{
  return (*a == *b);
}
