/*
 * shapes.c:
 * shapes demo.
 *
 * written by Naofumi Yasufuku  <naofumi@users.sourceforge.net>
 */

#include <stdlib.h>
#include <math.h>

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include <gtk/gtkgl.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "trackball.h"

#ifndef M_PI
#define M_PI   3.14159265358979323846
#endif

#define DIG_2_RAD (M_PI / 180.0)
#define RAD_2_DIG (180.0 / M_PI)

#define ANIMATE_THRESHOLD 25.0

#define VIEW_SCALE_MAX 2.0
#define VIEW_SCALE_MIN 0.5

#define NUM_SHAPES 9

static const GLuint shape_cube         = 0;
static const GLuint shape_sphere       = 1;
static const GLuint shape_cone         = 2;
static const GLuint shape_torus        = 3;
static const GLuint shape_tetrahedron  = 4;
static const GLuint shape_octahedron   = 5;
static const GLuint shape_dodecahedron = 6;
static const GLuint shape_icosahedron  = 7;
static const GLuint shape_teapot       = 8;

static GLuint shape_list_base = 0;
static GLuint shape_current = 8;

static float view_quat_diff[4] = { 0.0, 0.0, 0.0, 1.0 };
static float view_quat[4] = { 0.0, 0.0, 0.0, 1.0 };
static float view_scale = 1.0;

static gboolean animate = FALSE;

static void toggle_animation (GtkWidget *widget);

static void
init_view (void)
{
  view_quat[0] = view_quat_diff[0] = 0.0;
  view_quat[1] = view_quat_diff[1] = 0.0;
  view_quat[2] = view_quat_diff[2] = 0.0;
  view_quat[3] = view_quat_diff[3] = 1.0;
  view_scale = 1.0;
}

static void
realize (GtkWidget *widget,
	 gpointer   data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

  GLfloat ambient[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat position[] = {0.0, 3.0, 3.0, 0.0};

  GLfloat lmodel_ambient[] = {0.2, 0.2, 0.2, 1.0};
  GLfloat local_view[] = {0.0};

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
    return;

  glClearColor (0.5, 0.5, 0.8, 1.0);
  glClearDepth (1.0);

  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, position);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
  glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

  glFrontFace(GL_CW);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  /* Shape display lists */
  shape_list_base = glGenLists (NUM_SHAPES);

  /* Cube */
  glNewList (shape_list_base + shape_cube, GL_COMPILE);
    gdk_gl_solid_cube (1.5);
  glEndList ();

  /* Sphere */
  glNewList (shape_list_base + shape_sphere, GL_COMPILE);
    gdk_gl_solid_sphere (1.0, 30, 30);
  glEndList ();

  /* Cone */
  glNewList (shape_list_base + shape_cone, GL_COMPILE);
    glPushMatrix ();
      glTranslatef (0.0, 0.0, -1.0);
      gdk_gl_solid_cone (1.0, 2.0, 30, 30);
    glPopMatrix ();
  glEndList ();

  /* Torus */
  glNewList (shape_list_base + shape_torus, GL_COMPILE);
    gdk_gl_solid_torus (0.4, 0.8, 30, 30);
  glEndList ();

  /* Tetrahedron */
  glNewList (shape_list_base + shape_tetrahedron, GL_COMPILE);
    glPushMatrix ();
      glScalef (1.2, 1.2, 1.2);
      gdk_gl_solid_tetrahedron ();
    glPopMatrix ();
  glEndList ();

  /* Octahedron */
  glNewList (shape_list_base + shape_octahedron, GL_COMPILE);
    glPushMatrix ();
      glScalef (1.2, 1.2, 1.2);
      gdk_gl_solid_octahedron ();
    glPopMatrix ();
  glEndList ();

  /* Dodecahedron */
  glNewList (shape_list_base + shape_dodecahedron, GL_COMPILE);
    glPushMatrix ();
      glScalef (0.7, 0.7, 0.7);
      gdk_gl_solid_dodecahedron ();
    glPopMatrix ();
  glEndList ();

  /* Icosahedron */
  glNewList (shape_list_base + shape_icosahedron, GL_COMPILE);
    glPushMatrix ();
      glScalef (1.2, 1.2, 1.2);
      gdk_gl_solid_icosahedron ();
    glPopMatrix ();
  glEndList ();

  /* Teapot */
  glNewList (shape_list_base + shape_teapot, GL_COMPILE);
    gdk_gl_solid_teapot (1.0);
  glEndList ();

  gdk_gl_drawable_gl_end (gldrawable);
  /*** OpenGL END ***/

  return;
}

static gboolean
configure_event (GtkWidget         *widget,
		 GdkEventConfigure *event,
		 gpointer           data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

  GLfloat w = widget->allocation.width;
  GLfloat h = widget->allocation.height;
  GLfloat aspect = h / w;

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
    return FALSE;

  glViewport(0, 0, w, h);

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glFrustum (-1.0, 1.0, -aspect, aspect, 5.0, 60.0);

  glMatrixMode (GL_MODELVIEW);

  gdk_gl_drawable_gl_end (gldrawable);
  /*** OpenGL END ***/

  return TRUE;
}

/* Render shape */
void
render_shape (GLfloat x, GLfloat y,
              GLfloat ambr, GLfloat ambg, GLfloat ambb,
              GLfloat difr, GLfloat difg, GLfloat difb,
              GLfloat specr, GLfloat specg, GLfloat specb,
              GLfloat shine,
              GLuint list)
{
  float mat[4];

  glPushMatrix();

    glTranslatef(x, y, 0.0);

    mat[0] = ambr;
    mat[1] = ambg;
    mat[2] = ambb;
    mat[3] = 1.0;
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat);

    mat[0] = difr;
    mat[1] = difg;
    mat[2] = difb;
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);

    mat[0] = specr;
    mat[1] = specg;
    mat[2] = specb;
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat);

    glMaterialf(GL_FRONT, GL_SHININESS, shine * 128.0);

    glCallList(list);

  glPopMatrix();
}

static gboolean
expose_event (GtkWidget      *widget,
	      GdkEventExpose *event,
	      gpointer        data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

  float m[4][4];

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
    return FALSE;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity ();

  /* View transformation. */
  glTranslatef (0.0, 0.0, -10.0);
  glScalef (view_scale, view_scale, view_scale);
  add_quats (view_quat_diff, view_quat, view_quat);
  build_rotmatrix (m, view_quat);
  glMultMatrixf (&m[0][0]);

  /* Render shape */
  render_shape (0.0, 0.0,
                0.0, 0.0, 0.0,
                0.55, 0.55, 0.55,
                0.70, 0.70, 0.70,
                0.25,
                shape_list_base + shape_current);

  /* Swap buffers */
  if (gdk_gl_drawable_is_double_buffered (gldrawable))
    gdk_gl_drawable_swap_buffers (gldrawable);
  else
    glFlush ();

  gdk_gl_drawable_gl_end (gldrawable);
  /*** OpenGL END ***/

  return TRUE;
}

static float begin_x = 0.0;
static float begin_y = 0.0;

static float dx = 0.0;
static float dy = 0.0;

static gboolean
button_press_event (GtkWidget      *widget,
		    GdkEventButton *event,
		    gpointer        data)
{
  if (event->button == 1)
    {
      if (animate)
        toggle_animation (widget);
    }

  begin_x = event->x;
  begin_y = event->y;

  return FALSE;
}

static gboolean
button_release_event (GtkWidget      *widget,
                      GdkEventButton *event,
                      gpointer        data)
{
  if (event->button == 1)
    {
      if (!animate &&
          ((dx*dx + dy*dy) > ANIMATE_THRESHOLD))
        toggle_animation (widget);
    }

  dx = 0.0;
  dy = 0.0;

  return FALSE;
}

static gboolean
motion_notify_event (GtkWidget      *widget,
		     GdkEventMotion *event,
		     gpointer        data)
{
  float w = widget->allocation.width;
  float h = widget->allocation.height;
  float x = event->x;
  float y = event->y;
  gboolean redraw = FALSE;

  /* Rotation. */
  if (event->state & GDK_BUTTON1_MASK)
    {
      trackball (view_quat_diff,
		 (2.0 * begin_x - w) / w,
		 (h - 2.0 * begin_y) / h,
		 (2.0 * x - w) / w,
		 (h - 2.0 * y) / h);

      dx = x - begin_x;
      dy = y - begin_y;

      redraw = TRUE;
    }

  /* Scaling. */
  if (event->state & GDK_BUTTON2_MASK)
    {
      view_scale = view_scale * (1.0 + (y - begin_y) / h);
      if (view_scale > VIEW_SCALE_MAX)
	view_scale = VIEW_SCALE_MAX;
      else if (view_scale < VIEW_SCALE_MIN)
	view_scale = VIEW_SCALE_MIN;

      redraw = TRUE;
    }

  begin_x = x;
  begin_y = y;

  if (redraw && !animate)
    gtk_widget_queue_draw (widget);

  return TRUE;
}

static gboolean
key_press_event (GtkWidget   *widget,
		 GdkEventKey *event,
		 gpointer     data)
{
  g_print ("%s: \"key_press_event\": ", gtk_widget_get_name (widget));

  switch (event->keyval)
    {
    case GDK_Escape:
      g_print ("Escape key\n");
      gtk_main_quit ();
      break;

    default:
      return FALSE;
    }

  return TRUE;
}

static gboolean
idle (GtkWidget *widget)
{
  gtk_widget_queue_draw (widget);

  return TRUE;
}

static guint idle_id = 0;

static void
idle_add (GtkWidget *widget)
{
  if (idle_id == 0)
    {
      idle_id = gtk_idle_add_priority (GDK_PRIORITY_REDRAW,
				       (GtkFunction) idle,
				       widget);
    }
}

static void
idle_remove (GtkWidget *widget)
{
  if (idle_id != 0)
    {
      gtk_idle_remove (idle_id);
      idle_id = 0;
    }
}

static gboolean
map_event (GtkWidget *widget,
	   GdkEvent  *event,
	   gpointer   data)
{
  if (animate)
    idle_add (widget);

  return TRUE;
}

static gboolean
unmap_event (GtkWidget *widget,
	     GdkEvent  *event,
	     gpointer   data)
{
  idle_remove (widget);

  return TRUE;
}

static gboolean
visibility_notify_event (GtkWidget          *widget,
			 GdkEventVisibility *event,
			 gpointer            data)
{
  if (animate)
    {
      if (event->state == GDK_VISIBILITY_FULLY_OBSCURED)
	idle_remove (widget);
      else
	idle_add (widget);
    }

  return TRUE;
}

/* Toggle animation.*/
static void
toggle_animation (GtkWidget *widget)
{
  animate = !animate;

  if (animate)
    idle_add (widget);
  else
    idle_remove (widget);
}

static void
change_shape (GtkMenuItem  *menuitem,
              const GLuint *shape)
{
  shape_current = *shape;

  init_view ();
}

/* For popup menu. */
static gboolean
button_press_event_popup_menu (GtkWidget      *widget,
			       GdkEventButton *event,
			       gpointer        data)
{
  if (event->button == 3)
    {
      /* Popup menu. */
      gtk_menu_popup (GTK_MENU (widget), NULL, NULL, NULL, NULL,
		      event->button, event->time);
      return TRUE;
    }

  return FALSE;
}

/* Creates the popup menu.*/
static GtkWidget *
create_popup_menu (GtkWidget *drawing_area)
{
  GtkWidget *menu;
  GtkWidget *menu_item;

  menu = gtk_menu_new ();

  /* Cube */
  menu_item = gtk_menu_item_new_with_label ("Cube");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_cube);
  gtk_widget_show (menu_item);

  /* Sphere */
  menu_item = gtk_menu_item_new_with_label ("Sphere");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_sphere);
  gtk_widget_show (menu_item);

  /* Cone */
  menu_item = gtk_menu_item_new_with_label ("Cone");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_cone);
  gtk_widget_show (menu_item);

  /* Torus */
  menu_item = gtk_menu_item_new_with_label ("Torus");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_torus);
  gtk_widget_show (menu_item);

  /* Tetrahedron */
  menu_item = gtk_menu_item_new_with_label ("Tetrahedron");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_tetrahedron);
  gtk_widget_show (menu_item);

  /* Octahedron */
  menu_item = gtk_menu_item_new_with_label ("Octahedron");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_octahedron);
  gtk_widget_show (menu_item);

  /* Dodecahedron */
  menu_item = gtk_menu_item_new_with_label ("Dodecahedron");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_dodecahedron);
  gtk_widget_show (menu_item);

  /* Icosahedron */
  menu_item = gtk_menu_item_new_with_label ("Icosahedron");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_icosahedron);
  gtk_widget_show (menu_item);

  /* Teapot */
  menu_item = gtk_menu_item_new_with_label ("Teapot");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
                    G_CALLBACK (change_shape), (gpointer) &shape_teapot);
  gtk_widget_show (menu_item);

  /* Quit */
  menu_item = gtk_menu_item_new_with_label ("Quit");
  gtk_menu_shell_append (GTK_MENU_SHELL (menu), menu_item);
  g_signal_connect (G_OBJECT (menu_item), "activate",
		    G_CALLBACK (gtk_main_quit), NULL);
  gtk_widget_show (menu_item);
	
  return menu;
}

static void
print_gl_config_attrib (GdkGLConfig *glconfig,
                        const gchar *attrib_str,
                        int          attrib,
                        gboolean     is_boolean)
{
  int value;

  g_print ("%s = ", attrib_str);
  if (gdk_gl_config_get_attrib (glconfig, attrib, &value))
    {
      if (is_boolean)
        g_print ("%s\n", value == TRUE ? "TRUE" : "FALSE");
      else
        g_print ("%d\n", value);
    }
  else
    g_print ("*** Cannot get %s attribute value\n", attrib_str);
}

static void
examine_gl_config_attrib (GdkGLConfig *glconfig)
{
  g_print ("\nOpenGL visual configurations :\n\n");

  g_print ("gdk_gl_config_is_rgba (glconfig) = %s\n",
           gdk_gl_config_is_rgba (glconfig) ? "TRUE" : "FALSE");
  g_print ("gdk_gl_config_is_double_buffered (glconfig) = %s\n",
           gdk_gl_config_is_double_buffered (glconfig) ? "TRUE" : "FALSE");
  g_print ("gdk_gl_config_is_stereo (glconfig) = %s\n",
           gdk_gl_config_is_stereo (glconfig) ? "TRUE" : "FALSE");
  g_print ("gdk_gl_config_has_alpha (glconfig) = %s\n",
           gdk_gl_config_has_alpha (glconfig) ? "TRUE" : "FALSE");
  g_print ("gdk_gl_config_has_depth_buffer (glconfig) = %s\n",
           gdk_gl_config_has_depth_buffer (glconfig) ? "TRUE" : "FALSE");
  g_print ("gdk_gl_config_has_stencil_buffer (glconfig) = %s\n",
           gdk_gl_config_has_stencil_buffer (glconfig) ? "TRUE" : "FALSE");
  g_print ("gdk_gl_config_has_accum_buffer (glconfig) = %s\n",
           gdk_gl_config_has_accum_buffer (glconfig) ? "TRUE" : "FALSE");

  g_print ("\n");

  print_gl_config_attrib (glconfig, "GDK_GL_USE_GL",           GDK_GL_USE_GL,           TRUE);
  print_gl_config_attrib (glconfig, "GDK_GL_BUFFER_SIZE",      GDK_GL_BUFFER_SIZE,      FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_LEVEL",            GDK_GL_LEVEL,            FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_RGBA",             GDK_GL_RGBA,             TRUE);
  print_gl_config_attrib (glconfig, "GDK_GL_DOUBLEBUFFER",     GDK_GL_DOUBLEBUFFER,     TRUE);
  print_gl_config_attrib (glconfig, "GDK_GL_STEREO",           GDK_GL_STEREO,           TRUE);
  print_gl_config_attrib (glconfig, "GDK_GL_AUX_BUFFERS",      GDK_GL_AUX_BUFFERS,      FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_RED_SIZE",         GDK_GL_RED_SIZE,         FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_GREEN_SIZE",       GDK_GL_GREEN_SIZE,       FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_BLUE_SIZE",        GDK_GL_BLUE_SIZE,        FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_ALPHA_SIZE",       GDK_GL_ALPHA_SIZE,       FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_DEPTH_SIZE",       GDK_GL_DEPTH_SIZE,       FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_STENCIL_SIZE",     GDK_GL_STENCIL_SIZE,     FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_ACCUM_RED_SIZE",   GDK_GL_ACCUM_RED_SIZE,   FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_ACCUM_GREEN_SIZE", GDK_GL_ACCUM_GREEN_SIZE, FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_ACCUM_BLUE_SIZE",  GDK_GL_ACCUM_BLUE_SIZE,  FALSE);
  print_gl_config_attrib (glconfig, "GDK_GL_ACCUM_ALPHA_SIZE", GDK_GL_ACCUM_ALPHA_SIZE, FALSE);

  g_print ("\n");
}

int
main (int   argc,
      char *argv[])
{
  GdkGLConfig *glconfig;
  gint major, minor;

  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *drawing_area;
  GtkWidget *menu;
  GtkWidget *button;

  /* Initialize GTK. */
  gtk_init (&argc, &argv);

  /* Initialize GtkGLExt. */
  gtk_gl_init (&argc, &argv);

  /*
   * Query OpenGL extension version.
   */

  gdk_gl_query_version (&major, &minor);
  g_print ("\nOpenGL extension version - %d.%d\n",
           major, minor);

  /*
   * Configure OpenGL-capable visual.
   */

  /* Try double-buffered visual */
  glconfig = gdk_gl_config_new_by_mode (GDK_GL_MODE_RGB |
					GDK_GL_MODE_DEPTH |
					GDK_GL_MODE_DOUBLE);
  if (glconfig == NULL)
    {
      g_print ("*** Cannot find the double-buffered visual.\n");
      g_print ("*** Trying single-buffered visual.\n");

      /* Try single-buffered visual */
      glconfig = gdk_gl_config_new_by_mode (GDK_GL_MODE_RGB |
					    GDK_GL_MODE_DEPTH);
      if (glconfig == NULL)
	{
	  g_print ("*** No appropriate OpenGL-capable visual found.\n");
	  exit (1);
	}
    }

  examine_gl_config_attrib (glconfig);

  /*
   * Top-level window.
   */

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "shapes");

  g_signal_connect (G_OBJECT (window), "delete_event",
		    G_CALLBACK (gtk_main_quit), NULL);

  vbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (window), vbox);
  gtk_widget_show (vbox);

  /*
   * Drawing area for drawing OpenGL scene.
   */

  drawing_area = gtk_drawing_area_new ();
  gtk_widget_set_size_request (drawing_area, 300, 300);

  /* Set OpenGL-capability to the widget. */
  gtk_widget_set_gl_capability (drawing_area,
				glconfig,
				NULL,
				TRUE,
				GDK_GL_RGBA_TYPE);

  gtk_box_pack_start (GTK_BOX (vbox), drawing_area, TRUE, TRUE, 0);

  gtk_widget_set_events (drawing_area,
			 GDK_EXPOSURE_MASK |
			 GDK_BUTTON1_MOTION_MASK |
			 GDK_BUTTON2_MOTION_MASK |
			 GDK_BUTTON_PRESS_MASK |
                         GDK_BUTTON_RELEASE_MASK |
			 GDK_VISIBILITY_NOTIFY_MASK);

  g_signal_connect (G_OBJECT (drawing_area), "realize",
		    G_CALLBACK (realize), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "configure_event",
		    G_CALLBACK (configure_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "expose_event",
		    G_CALLBACK (expose_event), NULL);

  g_signal_connect (G_OBJECT (drawing_area), "button_press_event",
		    G_CALLBACK (button_press_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "button_release_event",
		    G_CALLBACK (button_release_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "motion_notify_event",
		    G_CALLBACK (motion_notify_event), NULL);

  g_signal_connect (G_OBJECT (drawing_area), "map_event",
		    G_CALLBACK (map_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "unmap_event",
		    G_CALLBACK (unmap_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "visibility_notify_event",
		    G_CALLBACK (visibility_notify_event), NULL);

  g_signal_connect_swapped (G_OBJECT (window), "key_press_event",
			    G_CALLBACK (key_press_event), drawing_area);

  gtk_widget_show (drawing_area);

  /*
   * Popup menu.
   */

  menu = create_popup_menu (drawing_area);

  /* Signal handler */
  g_signal_connect_swapped (G_OBJECT (drawing_area), "button_press_event",
                            G_CALLBACK (button_press_event_popup_menu), menu);

  /*
   * Simple quit button.
   */

  button = gtk_button_new_with_label ("Quit");
  gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);

  g_signal_connect (G_OBJECT (button), "clicked",
                    G_CALLBACK (gtk_main_quit), NULL);

  gtk_widget_show (button);

  /*
   * Show window.
   */

  gtk_widget_show (window);

  /*
   * Main loop.
   */

  gtk_main ();

  return 0;
}
