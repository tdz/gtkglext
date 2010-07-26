#include "gdkglprivate-quartz.h"
#include <OpenGL/gl.h>

/*< private >*/
void
_gdk_gl_drawable_impl_quartz_wait_gl (GdkGLDrawable *gldrawable)
{
  glFinish ();
}

/*< private >*/
void
_gdk_gl_drawable_impl_quartz_wait_gdk (GdkGLDrawable *gldrawable)
{

}
