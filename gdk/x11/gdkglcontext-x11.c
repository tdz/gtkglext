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

#include <gdk/gdk.h>            /* for gdk_error_trap_(push|pop) () */

#include "gdkglx.h"
#include "gdkglprivate-x11.h"
#include "gdkgldrawable.h"
#include "gdkglconfig-x11.h"
#include "gdkglcontext-x11.h"

static void          gdk_gl_context_insert (GdkGLContext *glcontext);
static void          gdk_gl_context_remove (GdkGLContext *glcontext);
static GdkGLContext *gdk_gl_context_lookup (GLXContext    glxcontext);
static guint         gdk_gl_context_hash   (GLXContext   *glxcontext);
static gboolean      gdk_gl_context_equal  (GLXContext   *a,
                                            GLXContext   *b);

static void gdk_gl_context_impl_x11_class_init (GdkGLContextImplX11Class *klass);
static void gdk_gl_context_impl_x11_finalize   (GObject                  *object);

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
        (GInstanceInitFunc) NULL
      };

      type = g_type_register_static (GDK_TYPE_GL_CONTEXT,
                                     "GdkGLContextImplX11",
                                     &type_info, 0);
    }

  return type;
}

static void
gdk_gl_context_impl_x11_class_init (GdkGLContextImplX11Class *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_class_init ()"));

  parent_class = g_type_class_peek_parent (klass);

  object_class->finalize = gdk_gl_context_impl_x11_finalize;
}

static void
gdk_gl_context_impl_x11_finalize (GObject *object)
{
  GdkGLContext *glcontext = GDK_GL_CONTEXT (object);
  GdkGLContextImplX11 *impl = GDK_GL_CONTEXT_IMPL_X11 (object);
  Display *xdisplay;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_impl_x11_finalize ()"));

  gdk_gl_context_remove (glcontext);

  if (!impl->is_foreign)
    {
      xdisplay = GDK_GL_CONFIG_XDISPLAY (impl->glconfig);

      GDK_GL_NOTE (IMPL, g_message (" * glXMakeCurrent ()"));

      if (impl->glxcontext == glXGetCurrentContext ())
        glXMakeCurrent (xdisplay, None, NULL);

      GDK_GL_NOTE (IMPL, g_message (" * glXDestroyContext ()"));

      glXDestroyContext (xdisplay, impl->glxcontext);
    }

  if (impl->gldrawable != NULL)
    g_object_unref (G_OBJECT (impl->gldrawable));

  /* currently unused. */
  /*
  if (impl->gldrawable_read != NULL)
    g_object_unref (G_OBJECT (impl->gldrawable_read));
  */

  g_object_unref (G_OBJECT (impl->glconfig));

  if (impl->share_list != NULL)
    g_object_unref (G_OBJECT (impl->share_list));

  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static GdkGLContext *
gdk_gl_context_new_common (GdkGLDrawable *gldrawable,
                           GdkGLConfig   *glconfig,
                           GdkGLContext  *share_list,
                           int            render_type,
                           GLXContext     glxcontext,
                           gboolean       is_foreign)
{
  GdkGLContext *glcontext;
  GdkGLContextImplX11 *impl;

  Display *xdisplay;

  GDK_GL_NOTE (FUNC, g_message (" -- gdk_gl_context_new_common ()"));

  /*
   * Instantiate the GdkGLContextImplX11 object.
   */

  glcontext = g_object_new (GDK_TYPE_GL_CONTEXT_IMPL_X11, NULL);
  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  impl->glxcontext = glxcontext;

  if (share_list != NULL && GDK_IS_GL_CONTEXT (share_list))
    {
      impl->share_list = share_list;
      g_object_ref (G_OBJECT (impl->share_list));
    }
  else
    {
      impl->share_list = NULL;
    }

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glconfig);
  impl->is_direct = glXIsDirect (xdisplay, glxcontext) ? TRUE : FALSE;

  impl->render_type = render_type;

  impl->glconfig = glconfig;
  g_object_ref (G_OBJECT (impl->glconfig));

  impl->gldrawable = gldrawable;
  g_object_ref (G_OBJECT (impl->gldrawable));

  impl->gldrawable_read = NULL;

  impl->is_foreign = is_foreign;

  /* 
   * Insert into the GL context hash table.
   */

  gdk_gl_context_insert (glcontext);

  return glcontext;
}

GdkGLContext *
_gdk_x11_gl_context_new (GdkGLDrawable *gldrawable,
                         GdkGLContext  *share_list,
                         gboolean       direct,
                         int            render_type)
{
  GdkGLConfig *glconfig;
  GdkGLContextImplX11 *share_impl = NULL;
  GLXContext share_glxcontext = NULL;

  Display *xdisplay;
  XVisualInfo *xvinfo;
  GLXContext glxcontext;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_new ()"));

  /*
   * Create an OpenGL rendering context.
   */

  glconfig = gdk_gl_drawable_get_gl_config (gldrawable);

  xdisplay = GDK_GL_CONFIG_XDISPLAY (glconfig);
  xvinfo = GDK_GL_CONFIG_XVINFO (glconfig);

  if (share_list != NULL && GDK_IS_GL_CONTEXT (share_list))
    {
      share_impl = GDK_GL_CONTEXT_IMPL_X11 (share_list);
      share_glxcontext = share_impl->glxcontext;
    }

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
                                    render_type,
                                    glxcontext,
                                    FALSE);
}

GdkGLContext *
gdk_x11_gl_context_foreign_new (GdkGLConfig  *glconfig,
                                GdkGLContext *share_list,
                                GLXContext    glxcontext)
{
  GDK_GL_NOTE (FUNC, g_message (" - gdk_x11_gl_context_foreign_new ()"));

  g_return_val_if_fail (GDK_IS_GL_CONFIG (glconfig), NULL);
  g_return_val_if_fail (glxcontext != NULL, NULL);

  /*
   * Instanciate the GdkGLContextImplX11 object.
   */

  return gdk_gl_context_new_common (NULL,
                                    glconfig,
                                    share_list,
                                    (glconfig->is_rgba) ? GDK_GL_RGBA_TYPE : GDK_GL_COLOR_INDEX_TYPE,
                                    glxcontext,
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
  GdkGLConfig *glconfig;

  GDK_GL_NOTE (FUNC, g_message (" - gdk_gl_context_copy ()"));

  g_return_val_if_fail (GDK_IS_GL_CONTEXT (dst_glcontext), FALSE);
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (src_glcontext), FALSE);

  glconfig = GDK_GL_CONTEXT_IMPL_X11 (dst_glcontext)->glconfig;

  gdk_error_trap_push ();

  glXCopyContext (GDK_GL_CONFIG_XDISPLAY (glconfig),
                  GDK_GL_CONTEXT_GLXCONTEXT (src_glcontext),
                  GDK_GL_CONTEXT_GLXCONTEXT (dst_glcontext),
                  mask);

  return gdk_error_trap_pop () == Success;
}

/*< private >*/
void
_gdk_gl_context_set_gl_drawable (GdkGLContext  *glcontext,
                                 GdkGLDrawable *gldrawable)
{
  GdkGLContextImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - _gdk_gl_context_set_gl_drawable ()"));

  g_return_if_fail (GDK_IS_GL_CONTEXT (glcontext));

  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  if (impl->gldrawable == gldrawable)
    return;

  if (impl->gldrawable != NULL)
    {
      g_object_unref (G_OBJECT (impl->gldrawable));
      impl->gldrawable = NULL;
    }

  if (gldrawable != NULL && GDK_IS_GL_DRAWABLE (gldrawable))
    {
      impl->gldrawable = gldrawable;
      g_object_ref (G_OBJECT (impl->gldrawable));
    }
}

/*< private >*/
/* currently unused. */
/*
void
_gdk_gl_context_set_gl_drawable_read (GdkGLContext  *glcontext,
                                      GdkGLDrawable *gldrawable_read)
{
  GdkGLContextImplX11 *impl;

  GDK_GL_NOTE (FUNC, g_message (" - _gdk_gl_context_set_gl_drawable_read ()"));

  g_return_if_fail (GDK_IS_GL_CONTEXT (glcontext));

  impl = GDK_GL_CONTEXT_IMPL_X11 (glcontext);

  if (impl->gldrawable_read == gldrawable_read)
    return;

  if (impl->gldrawable_read != NULL)
    {
      g_object_unref (G_OBJECT (impl->gldrawable_read));
      impl->gldrawable_read = NULL;
    }

  if (gldrawable_read != NULL && GDK_IS_GL_DRAWABLE (gldrawable_read))
    {
      impl->gldrawable_read = gldrawable_read;
      g_object_ref (G_OBJECT (impl->gldrawable_read));
    }
}
*/

/**
 * gdk_gl_context_get_gl_drawable:
 * @glcontext: a #GdkGLContext.
 *
 * Get #GdkGLDrawable to which the @glcontext is binded.
 *
 * Return value: the #GdkGLDrawable.
 **/
GdkGLDrawable *
gdk_gl_context_get_gl_drawable (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), NULL);

  return GDK_GL_CONTEXT_IMPL_X11 (glcontext)->gldrawable;
}

/**
 * gdk_gl_context_get_gl_config:
 * @glcontext: a #GdkGLContext.
 *
 * Get #GdkGLConfig with which the @glcontext is configured.
 *
 * Return value: the #GdkGLConfig.
 **/
GdkGLConfig *
gdk_gl_context_get_gl_config (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), NULL);

  return GDK_GL_CONTEXT_IMPL_X11 (glcontext)->glconfig;
}

/**
 * gdk_gl_context_get_share_list:
 * @glcontext: a #GdkGLContext.
 *
 * Get #GdkGLContext with which the @glcontext shares the display lists.
 *
 * Return value: the #GdkGLContext.
 **/
GdkGLContext *
gdk_gl_context_get_share_list (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), NULL);

  return GDK_GL_CONTEXT_IMPL_X11 (glcontext)->share_list;
}

/**
 * gdk_gl_context_is_direct:
 * @glcontext: a #GdkGLContext.
 *
 * Returns whether the @glcontext is a direct rendering context.
 *
 * Return value: TRUE if the @glcontext is a direct rendering contest.
 **/
gboolean
gdk_gl_context_is_direct (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), FALSE);

  return GDK_GL_CONTEXT_IMPL_X11 (glcontext)->is_direct;
}

/**
 * gdk_gl_context_get_render_type:
 * @glcontext: a #GdkGLContext.
 *
 * Get render_type of the @glcontext.
 *
 * Return value: GDK_GL_RGBA_TYPE or GDK_GL_COLOR_INDEX_TYPE.
 **/
int
gdk_gl_context_get_render_type (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), 0);

  return GDK_GL_CONTEXT_IMPL_X11 (glcontext)->render_type;
}

/**
 * gdk_gl_context_get_colormap:
 * @glcontext: a #GdkGLContext.
 *
 * Get #GdkColormap with which the @glcontext is configured.
 *
 * Return value: the #GdkColormap.
 **/
GdkColormap *
gdk_gl_context_get_colormap (GdkGLContext *glcontext)
{
  g_return_val_if_fail (GDK_IS_GL_CONTEXT (glcontext), NULL);

  return gdk_gl_config_get_colormap (GDK_GL_CONTEXT_IMPL_X11 (glcontext)->glconfig);
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
