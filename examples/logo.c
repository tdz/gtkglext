/*
 * logo.c:
 * GtkGLExt logo demo.
 *
 * written by Naofumi Yasufuku  <naofumi@users.sourceforge.net>
 */

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include <gtk/gtkgl.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "logo-model.h"

#ifdef X
#undef X
#endif
#ifdef Y
#undef Y
#endif
#ifdef Z
#undef Z
#endif

#define X 0
#define Y 1
#define Z 2

#define DEFAULT_ROT_COUNT 300

#define INITIAL_ROT_X 70.0
#define INITIAL_ROT_Y 0.0
#define INITIAL_ROT_Z 0.0

#define LOGO_CUBE       1
#define LOGO_G_FORWARD  2
#define LOGO_G_BACKWARD 3
#define LOGO_T_FORWARD  4
#define LOGO_T_BACKWARD 5
#define LOGO_K_FORWARD  6
#define LOGO_K_BACKWARD 7

static GTimer *timer = NULL;
static gint frames = 0;

static void
realize(GtkWidget *widget,
        gpointer   data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context(widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable(widget);

  static GLfloat light_position[] = { 0.0, 0.0, 30.0, 0.0 };
  static GLfloat light_diffuse[]  = { 1.0, 1.0, 1.0, 1.0 };
  static GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

  static GLfloat mat_specular[]  = { 0.5, 0.5, 0.5, 1.0 };
  static GLfloat mat_shininess[] = { 10.0 };
  static GLfloat mat_black[]     = { 0.0, 0.0, 0.0, 1.0 };
  static GLfloat mat_red[]       = { 1.0, 0.0, 0.0, 1.0 };
  static GLfloat mat_green[]     = { 0.0, 1.0, 0.0, 1.0 };
  static GLfloat mat_blue[]      = { 0.0, 0.0, 1.0, 1.0 };

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin(gldrawable, glcontext))
    return;

  glClearColor(0.5, 0.5, 0.8, 1.0);
  glClearDepth(1.0);

  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_CULL_FACE);

  glShadeModel(GL_SMOOTH);

  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

  /* Center black cube. */
  glNewList(LOGO_CUBE, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_black);
    logo_draw_cube();
  glEndList();

  /* Forward "G". */
  glNewList(LOGO_G_FORWARD, GL_COMPILE);
    glDisable(GL_CULL_FACE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_blue);
    logo_draw_g_plane();
    glEnable(GL_CULL_FACE);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_black);
    logo_draw_g();
  glEndList();

  /* Backward "G". */
  glNewList(LOGO_G_BACKWARD, GL_COMPILE);
    glPushMatrix();
    glRotatef(180.0, 1.0, 0.0, 0.0);

    glDisable(GL_CULL_FACE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_blue);
    logo_draw_g_plane();
    glEnable(GL_CULL_FACE);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_black);
    logo_draw_g();

    glPopMatrix();
  glEndList();

  /* Forward "T". */
  glNewList(LOGO_T_FORWARD, GL_COMPILE);
    glDisable(GL_CULL_FACE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_red);
    logo_draw_t_plane();
    glEnable(GL_CULL_FACE);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_black);
    logo_draw_t();
  glEndList();

  /* Backward "T". */
  glNewList(LOGO_T_BACKWARD, GL_COMPILE);
    glPushMatrix();
    glRotatef(180.0, 1.0, 0.0, 0.0);

    glDisable(GL_CULL_FACE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_red);
    logo_draw_t_plane();
    glEnable(GL_CULL_FACE);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_black);
    logo_draw_t();

    glPopMatrix();
  glEndList();

  /* Forward "K". */
  glNewList(LOGO_K_FORWARD, GL_COMPILE);
    glDisable(GL_CULL_FACE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_green);
    logo_draw_k_plane();
    glEnable(GL_CULL_FACE);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_black);
    logo_draw_k();
  glEndList();

  /* Backward "K". */
  glNewList(LOGO_K_BACKWARD, GL_COMPILE);
    glPushMatrix();
    glRotatef(180.0, 0.0, 0.0, 1.0);

    glDisable(GL_CULL_FACE);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_green);
    logo_draw_k_plane();
    glEnable(GL_CULL_FACE);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_black);
    logo_draw_k();
    glPopMatrix();
  glEndList();

  glEnable(GL_NORMALIZE);

  gdk_gl_drawable_gl_end(gldrawable);
  /*** OpenGL END ***/

  /* create timer */
  if (timer == NULL)
    timer = g_timer_new();

  g_timer_start(timer);
}

static gboolean
configure_event(GtkWidget         *widget,
                GdkEventConfigure *event,
                gpointer           data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context(widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable(widget);

  GLfloat w = widget->allocation.width;
  GLfloat h = widget->allocation.height;
  GLfloat aspect = h / w;

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin(gldrawable, glcontext))
    goto NO_GL;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glFrustum(-1.0, 1.0, -aspect, aspect, 2.0, 60.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -30.0);

  gdk_gl_drawable_gl_end(gldrawable);
  /*** OpenGL END ***/

 NO_GL:

  return TRUE;
}

static gboolean enable_anim = TRUE;

static int rot_count = DEFAULT_ROT_COUNT;

static GLfloat rot[3] = {
  INITIAL_ROT_X, INITIAL_ROT_Y, INITIAL_ROT_Z
};

typedef struct _RotMode
{
  int index;
  float sign;
} RotMode;

static RotMode rot_mode[] = {
  {  X, -1.0 },
  {  Y, -1.0 },
  {  X, -1.0 },
  {  Y,  1.0 },
  {  X, -1.0 },
  {  Y, -1.0 },
  {  X, -1.0 },
  {  Y,  1.0 },
  { -1,  0.0 }  /* terminator */
};

static int mode = 0;

static int counter = 0;

static gboolean
expose_event(GtkWidget      *widget,
             GdkEventExpose *event,
             gpointer        data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context(widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable(widget);

  if (enable_anim) {

    if (counter == rot_count) {
      if (rot_mode[++mode].index < 0)
        mode = 0;
      counter = 0;
    }

    rot[rot_mode[mode].index] += rot_mode[mode].sign * 90.0 / rot_count;

    counter++;

  }

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin(gldrawable, glcontext))
    goto NO_GL;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
    glRotatef(rot[X], 1.0, 0.0, 0.0);
    glRotatef(rot[Y], 0.0, 1.0, 0.0);
    glRotatef(rot[Z], 0.0, 0.0, 1.0);

    glPushMatrix();
      glCallList(LOGO_CUBE);
      glCallList(LOGO_G_FORWARD);
      glCallList(LOGO_G_BACKWARD);
      glCallList(LOGO_T_FORWARD);
      glCallList(LOGO_T_BACKWARD);
      glCallList(LOGO_K_FORWARD);
      glCallList(LOGO_K_BACKWARD);
    glPopMatrix();

  glPopMatrix();

  if (gdk_gl_drawable_is_double_buffered(gldrawable))
    gdk_gl_drawable_swap_buffers(gldrawable);
  else
    glFlush();

  gdk_gl_drawable_gl_end(gldrawable);
  /*** OpenGL END ***/

 NO_GL:

  if (enable_anim) {

    frames++;

    {
      gdouble seconds = g_timer_elapsed(timer, NULL);
      if (seconds >= 5.0) {
        gdouble fps = frames / seconds;
        g_print("%d frames in %6.3f seconds = %6.3f FPS\n",
                frames, seconds, fps);
        g_timer_reset(timer);
        frames = 0;
      }
    }

  }

  return TRUE;
}

static gboolean
idle(GtkWidget *widget)
{
  gtk_widget_queue_draw(widget);

  return TRUE;
}

static guint idle_id = 0;

static void
idle_add(GtkWidget *widget)
{
  if (idle_id == 0) {
    idle_id = gtk_idle_add_priority(GDK_PRIORITY_REDRAW,
                                    (GtkFunction) idle,
                                    widget);
  }
}

static void
idle_remove(GtkWidget *widget)
{
  if (idle_id != 0) {
    gtk_idle_remove(idle_id);
    idle_id = 0;
  }
}

static gboolean
map_event(GtkWidget   *widget,
          GdkEventAny *event,
          gpointer     data)
{
  idle_add(widget);

  return TRUE;
}

static gboolean
unmap_event(GtkWidget   *widget,
            GdkEventAny *event,
            gpointer     data)
{
  idle_remove(widget);

  return TRUE;
}

static gboolean
visibility_notify_event(GtkWidget          *widget,
                        GdkEventVisibility *event,
                        gpointer            data)
{
  if (event->state == GDK_VISIBILITY_FULLY_OBSCURED)
    idle_remove(widget);
  else
    idle_add(widget);

  return TRUE;
}

static void
toggle_anim(GtkWidget *widget)
{
  enable_anim = enable_anim ? FALSE : TRUE;

  if (enable_anim)
    idle_add(widget);
  else
    idle_remove(widget);
}

static void
init_rot(GtkWidget *widget)
{
  rot[X] = INITIAL_ROT_X;
  rot[Y] = INITIAL_ROT_Y;
  rot[Z] = INITIAL_ROT_Z;
  mode = 0;
  counter = 0;

  gtk_widget_queue_draw(widget);
}

static gboolean
button_press_event(GtkWidget      *widget,
                   GdkEventButton *event,
                   gpointer        data)
{
  if (event->button == 3) {
    gtk_menu_popup(GTK_MENU(widget), NULL, NULL, NULL, NULL,
                   event->button, event->time);
    return TRUE;
  }

  return FALSE;
}

static gboolean
key_press_event(GtkWidget   *widget,
                GdkEventKey *event,
                gpointer     data)
{
  switch (event->keyval) {
  case GDK_a:
    toggle_anim(widget);
    break;
  case GDK_i:
    init_rot(widget);
    break;
  case GDK_z:
    rot[Z] += 5.0;
    break;
  case GDK_Z:
    rot[Z] -= 5.0;
    break;
  case GDK_Up:
    rot[X] += 5.0;
    break;
  case GDK_Down:
    rot[X] -= 5.0;
    break;
  case GDK_Left:
    rot[Y] += 5.0;
    break;
  case GDK_Right:
    rot[Y] -= 5.0;
    break;
  case GDK_Escape:
    gtk_main_quit();
    break;
  default:
    return TRUE;
  }

  gtk_widget_queue_draw(widget);

  return TRUE;
}

static void
print_gl_config_attrib(GdkGLConfig *glconfig,
                       const gchar *attrib_str,
                       int          attrib,
                       gboolean     is_boolean)
{
  int value;

  g_print("%s = ", attrib_str);
  if (gdk_gl_config_get_attrib(glconfig, attrib, &value)) {
    if (is_boolean)
      g_print ("%s\n", value == TRUE ? "TRUE" : "FALSE");
    else
      g_print ("%d\n", value);
  } else
    g_print("*** Cannot get %s attribute value\n", attrib_str);
}

static void
examine_gl_config_attrib(GdkGLConfig *glconfig)
{
  g_print("\nOpenGL visual configurations :\n\n");

  g_print("gdk_gl_config_is_rgba (glconfig) = %s\n",
          gdk_gl_config_is_rgba (glconfig) ? "TRUE" : "FALSE");
  g_print("gdk_gl_config_is_double_buffered (glconfig) = %s\n",
          gdk_gl_config_is_double_buffered (glconfig) ? "TRUE" : "FALSE");
  g_print("gdk_gl_config_is_stereo (glconfig) = %s\n",
          gdk_gl_config_is_stereo (glconfig) ? "TRUE" : "FALSE");
  g_print("gdk_gl_config_has_alpha (glconfig) = %s\n",
          gdk_gl_config_has_alpha (glconfig) ? "TRUE" : "FALSE");
  g_print("gdk_gl_config_has_depth_buffer (glconfig) = %s\n",
          gdk_gl_config_has_depth_buffer (glconfig) ? "TRUE" : "FALSE");
  g_print("gdk_gl_config_has_stencil_buffer (glconfig) = %s\n",
          gdk_gl_config_has_stencil_buffer (glconfig) ? "TRUE" : "FALSE");
  g_print("gdk_gl_config_has_accum_buffer (glconfig) = %s\n",
          gdk_gl_config_has_accum_buffer (glconfig) ? "TRUE" : "FALSE");

  g_print("\n");

  print_gl_config_attrib(glconfig, "GDK_GL_USE_GL",           GDK_GL_USE_GL,           TRUE);
  print_gl_config_attrib(glconfig, "GDK_GL_BUFFER_SIZE",      GDK_GL_BUFFER_SIZE,      FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_LEVEL",            GDK_GL_LEVEL,            FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_RGBA",             GDK_GL_RGBA,             TRUE);
  print_gl_config_attrib(glconfig, "GDK_GL_DOUBLEBUFFER",     GDK_GL_DOUBLEBUFFER,     TRUE);
  print_gl_config_attrib(glconfig, "GDK_GL_STEREO",           GDK_GL_STEREO,           TRUE);
  print_gl_config_attrib(glconfig, "GDK_GL_AUX_BUFFERS",      GDK_GL_AUX_BUFFERS,      FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_RED_SIZE",         GDK_GL_RED_SIZE,         FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_GREEN_SIZE",       GDK_GL_GREEN_SIZE,       FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_BLUE_SIZE",        GDK_GL_BLUE_SIZE,        FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_ALPHA_SIZE",       GDK_GL_ALPHA_SIZE,       FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_DEPTH_SIZE",       GDK_GL_DEPTH_SIZE,       FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_STENCIL_SIZE",     GDK_GL_STENCIL_SIZE,     FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_ACCUM_RED_SIZE",   GDK_GL_ACCUM_RED_SIZE,   FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_ACCUM_GREEN_SIZE", GDK_GL_ACCUM_GREEN_SIZE, FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_ACCUM_BLUE_SIZE",  GDK_GL_ACCUM_BLUE_SIZE,  FALSE);
  print_gl_config_attrib(glconfig, "GDK_GL_ACCUM_ALPHA_SIZE", GDK_GL_ACCUM_ALPHA_SIZE, FALSE);

  g_print("\n");
}

int
main(int argc,
     char *argv[])
{
  GdkGLConfig *glconfig;
  gint major, minor;

  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *menu, *menu_item;
  GtkWidget *drawing_area;

  int i;
  gboolean arg_count = FALSE;

  /*
   * Init GTK.
   */

  gtk_init(&argc, &argv);

  /*
   * Parse arguments.
   */

  for (i = 1; i < argc; i++) {
    if (arg_count)
      rot_count = atoi(argv[i]);

    if (strcmp(argv[i], "--help") == 0 ||
        strcmp(argv[i], "-h") == 0) {
      g_print("Usage: %s [-count num] [-noanim] [--help]\n", argv[0]);
      exit(0);
    }

    if (strcmp(argv[i], "-count") == 0)
      arg_count = TRUE;

    if (strcmp(argv[i], "-noanim") == 0)
      enable_anim = FALSE;
  }

  /*
   * OpenGL is supported?
   */

  if (!gdk_gl_query_extension()) {
    g_print("\n*** OpenGL is not supported.\n");
    exit(1);
  }

  gdk_gl_query_version(&major, &minor);
  g_print("\nOpenGL is supported - version %d.%d\n",
          major, minor);

  /*
   * Configure OpenGL-capable visual.
   */

  /* Try double-buffered visual */
  glconfig = gdk_gl_config_new_by_mode(GDK_GL_MODE_RGB |
                                       GDK_GL_MODE_DEPTH |
                                       GDK_GL_MODE_DOUBLE);
  if (glconfig == NULL) {
    g_print("*** Cannot find the double-buffered visual.\n");
    g_print("*** Trying single-buffered visual.\n");

    /* Try single-buffered visual */
    glconfig = gdk_gl_config_new_by_mode(GDK_GL_MODE_RGB |
                                         GDK_GL_MODE_DEPTH);
    if (glconfig == NULL) {
      g_print("*** No appropriate OpenGL-capable visual found.\n");
      exit(1);
    }
  }

  examine_gl_config_attrib(glconfig);

  /*
   * Top-level window.
   */

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "logo");

  g_signal_connect(G_OBJECT(window), "delete_event",
                   G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(window), "key_press_event",
                   G_CALLBACK(key_press_event), NULL);  

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_widget_show(vbox);

  /*
   * Drawing area for drawing OpenGL scene.
   */

  drawing_area = gtk_drawing_area_new();
  gtk_widget_set_size_request(drawing_area, 300, 300);

  /* Set OpenGL-capability to the widget. */
  gtk_widget_set_gl_capability(drawing_area,
                               glconfig,
                               NULL,
                               TRUE,
                               GDK_GL_RGBA_TYPE);

  gtk_box_pack_start(GTK_BOX(vbox), drawing_area, TRUE, TRUE, 0);

  gtk_widget_set_events(drawing_area,
                        GDK_EXPOSURE_MASK |
                        GDK_BUTTON_PRESS_MASK |
                        GDK_VISIBILITY_NOTIFY_MASK);

  g_signal_connect(G_OBJECT(drawing_area), "realize",
                   G_CALLBACK(realize), NULL);
  g_signal_connect(G_OBJECT(drawing_area), "configure_event",
                   G_CALLBACK(configure_event), NULL);
  g_signal_connect(G_OBJECT(drawing_area), "expose_event",
                   G_CALLBACK(expose_event), NULL);
  g_signal_connect(G_OBJECT(drawing_area), "map_event",
                   G_CALLBACK(map_event), NULL);
  g_signal_connect(G_OBJECT(drawing_area), "unmap_event",
                   G_CALLBACK(unmap_event), NULL);
  g_signal_connect(G_OBJECT(drawing_area), "visibility_notify_event",
                   G_CALLBACK(visibility_notify_event), NULL);

  gtk_widget_show(drawing_area);

  /*
   * Popup menu.
   */

  menu = gtk_menu_new();

  /* Toggle animation */
  menu_item = gtk_menu_item_new_with_label("Toggle Animation");
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
  g_signal_connect_swapped(G_OBJECT(menu_item), "activate",
                           G_CALLBACK(toggle_anim), drawing_area);
  gtk_widget_show(menu_item);

  /* Init orientation */
  menu_item = gtk_menu_item_new_with_label("Initialize");
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
  g_signal_connect_swapped(G_OBJECT(menu_item), "activate",
                           G_CALLBACK(init_rot), drawing_area);
  gtk_widget_show(menu_item);

  /* Quit */
  menu_item = gtk_menu_item_new_with_label("Quit");
  gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item);
  g_signal_connect(G_OBJECT(menu_item), "activate",
                   G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_show(menu_item);

  /* Signal handler */
  g_signal_connect_swapped(G_OBJECT(drawing_area), "button_press_event",
                           G_CALLBACK(button_press_event), menu);

  /*
   * Show window.
   */

  gtk_widget_show(window);

  /*
   * Main loop.
   */

  gtk_main();

  return 0;
}
