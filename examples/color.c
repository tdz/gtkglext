/*
 * color.c:
 * Color management example.
 *
 * written by Naofumi Yasufuku  <naofumi@users.sourceforge.net>
 */

#include <stdlib.h>
#include <string.h>

#include <gtk/gtk.h>

#include <gtk/gtkgl.h>

#include <GL/gl.h>
#include <GL/glu.h>

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

/*
 * Colors.
 */

#define NUM_COLORS 4

static GdkColor colors[NUM_COLORS] = {
  /* pixel   red     green   blue */
  {  0,      0x0,    0x0,    0x0    }, /* black */
  {  0,      0xffff, 0x0,    0x0    }, /* red */
  {  0,      0x0,    0xffff, 0x0    }, /* green */
  {  0,      0x0,    0x0,    0xffff }  /* blue */
};

#define BLACK colors[0].pixel
#define RED   colors[1].pixel
#define GREEN colors[2].pixel
#define BLUE  colors[3].pixel

static gboolean
reshape (GtkWidget         *widget,
         GdkEventConfigure *event,
         gpointer           data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
    goto NO_GL;

  glViewport (0, 0,
              widget->allocation.width, widget->allocation.height);

  gdk_gl_drawable_gl_end (gldrawable);
  /*** OpenGL END ***/

 NO_GL:

  return TRUE;
}

static gboolean
display (GtkWidget      *widget,
         GdkEventExpose *event,
         gpointer        data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
    goto NO_GL;

  glClear (GL_COLOR_BUFFER_BIT);

  glBegin (GL_TRIANGLES);
    glIndexi (RED);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2i (0, 1);
    glIndexi (GREEN);
    glColor3f (0.0, 1.0, 0.0);
    glVertex2i (-1, -1);
    glIndexi (BLUE);
    glColor3f (0.0, 0.0, 1.0);
    glVertex2i (1, -1);  
  glEnd ();

  if (gdk_gl_drawable_is_double_buffered (gldrawable))
    gdk_gl_drawable_swap_buffers (gldrawable);
  else
    glFlush ();

  gdk_gl_drawable_gl_end (gldrawable);
  /*** OpenGL END ***/

 NO_GL:

  return TRUE;
}

static gint
quit (GtkWidget *widget,
      GdkEvent  *event,
      gpointer   data)
{
  gtk_main_quit ();

  return FALSE;
}

int
main (int argc,
      char *argv[])
{
  GdkGLConfigMode mode;
  GdkGLConfig *glconfig;
  GdkColormap *colormap;
  gboolean is_rgba, success;
  gint major, minor;
  int i;

  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *drawing_area;
  GtkWidget *button;

  gtk_init (&argc, &argv);

  /*
   * Display mode.
   */

  mode = GDK_GL_MODE_INDEX;

  for (i = 0; i < argc; i++)
    {
      if (strcmp (argv[i], "-rgb") == 0)
        mode = GDK_GL_MODE_RGB;
    }

  /*
   * OpenGL is supported?
   */

  if (!gdk_gl_query_extension ())
    {
      g_print ("\n*** OpenGL is not supported.\n");
      exit (1);
    }

  gdk_gl_query_version (&major, &minor);
  g_print ("\nOpenGL is supported - version %d.%d\n",
           major, minor);

  /*
   * Configure OpenGL-capable visual.
   */

  /* Try double-buffered visual */
  glconfig = gdk_gl_config_new_by_mode (mode | GDK_GL_MODE_DOUBLE);
  if (glconfig == NULL)
    {
      g_print ("*** Cannot find the double-buffered visual.\n");
      g_print ("*** Trying single-buffered visual.\n");

      /* Try single-buffered visual */
      glconfig = gdk_gl_config_new_by_mode (mode);
      if (glconfig == NULL)
        {
          g_print ("*** No appropriate OpenGL-capable visual found.\n");
          exit (1);
        }
    }

  examine_gl_config_attrib (glconfig);

  is_rgba = gdk_gl_config_is_rgba (glconfig);

  /*
   * Allocate colors.
   */

  colormap = gdk_gl_config_get_colormap (glconfig);

  if (!is_rgba)
    {
      g_print ("\nAllocate colors.\n");

      gdk_colormap_alloc_colors (colormap, colors, 4, FALSE, FALSE, &success);
      if (!success)
        g_print ("*** Color allocation failed.\n");
      else
        g_print ("Colors ware successfully allocated.\n");

      for (i = 0; i < NUM_COLORS; i++)
        {
          g_print ("colors[%d] = { %u, 0x%x, 0x%x, 0x%x }\n",
                   i, colors[i].pixel,
                   colors[i].red, colors[i].green, colors[i].blue);
        }
      g_print ("\n");
    }

  /*
   * Top-level window.
   */

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "color");

  /*
   * NOTICE!
   * If window manager doesn't watch the WM_COLORMAP_WINDOWS property on
   * a top-level window, we have to set OpenGL window's colormap to the
   * top-level window, especially in color index mode (color index mode
   * uses own private writable colormap).
   */
  gtk_widget_set_colormap (window, gdk_gl_config_get_colormap (glconfig));

  g_signal_connect (G_OBJECT (window), "delete_event",
                    G_CALLBACK (quit), NULL);

  vbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (window), vbox);
  gtk_widget_show (vbox);

  /*
   * Drawing area for drawing OpenGL scene.
   */

  drawing_area = gtk_drawing_area_new ();
  gtk_widget_set_size_request (drawing_area, 200, 200);

  /* Set OpenGL-capability to the widget. */
  gtk_widget_set_gl_capability (drawing_area,
                                glconfig,
                                NULL,
                                TRUE,
                                is_rgba ? GDK_GL_RGBA_TYPE : GDK_GL_COLOR_INDEX_TYPE);

  gtk_box_pack_start (GTK_BOX (vbox), drawing_area, TRUE, TRUE, 0);

  gtk_widget_set_events (drawing_area,
                         GDK_EXPOSURE_MASK |
                         GDK_BUTTON_PRESS_MASK);

  g_signal_connect (G_OBJECT (drawing_area), "configure_event",
		    G_CALLBACK (reshape), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "expose_event",
		    G_CALLBACK (display), NULL);

  gtk_widget_show (drawing_area);

  /*
   * Simple quit button.
   */

  button = gtk_button_new_with_label ("Quit");
  gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0);

  g_signal_connect (G_OBJECT (button), "clicked",
                    G_CALLBACK (quit), NULL);

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
