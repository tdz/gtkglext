/**************************************************************************
 * template.c
 *
 * Copyright (c) 2002 Alif Wahid <awah005@varsity.co.nz>
 *
 * This is a template of the essential source code to write useful but
 * simple programs using GtkGLExt and Gtk. It compiles into an executable
 * but obviously the lack of any OpenGL functions in this demonstrates
 * the generic nature. It's heavily commented to aid beginners (especially
 * tertiary students like myself). So use/change it at will.
 *
 * This program is in the public domain and you are using it at
 * your own risk.
 *
 **************************************************************************/

/* 
 * Follow the GTK coding style.
 *   Naofumi Yasufuku  <naofumi@users.sourceforge.net>
 */

/**************************************************************************
 * Header file inclusions.
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

#include <gtk/gtkgl.h>
/*** Use OpenGL extensions. ***/
/* #include <gdk/gdkglglext.h> */

#include <GL/gl.h>
#include <GL/glu.h>


/**************************************************************************
 * The following section contains all the macro definitions.
 **************************************************************************/

/***
 *** Change these three macros to customise the
 *** default width and height of the drawing
 *** area, plus the default title of the window.
 ***/
#define DEFAULT_WIDTH  200
#define DEFAULT_HEIGHT 200
#define DEFAULT_TITLE  "GtkGLExt Template"


/**************************************************************************
 * The following section contains all the callback function definitions.
 **************************************************************************/

/***
 *** The "realize" signal handler. All the OpenGL initialization
 *** should be performed here, such as default background colour,
 *** certain states etc.
 ***/
static void
realize (GtkWidget *widget,
	 gpointer   data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

  g_print ("%s: \"realize\"\n", gtk_widget_get_name (widget));

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
    return;

  /*** Fill in the details here. ***/

  gdk_gl_drawable_gl_end (gldrawable);
  /*** OpenGL END ***/

  return;
}

/***
 *** The "configure_event" signal handler. Any processing required when
 *** the OpenGL capable drawing area is re-configured should be done here.
 *** Almost always it will be used to resize the OpenGL viewport when
 *** the window is resized.
 ***/
static gboolean
configure_event (GtkWidget         *widget,
		 GdkEventConfigure *event,
		 gpointer           data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

  GLfloat w = widget->allocation.width;
  GLfloat h = widget->allocation.height;

  g_print ("%s: \"configure_event\"\n", gtk_widget_get_name (widget));

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
    return FALSE;

  /*** Fill in the details here. ***/

  glViewport (0, 0, w, h);

  gdk_gl_drawable_gl_end (gldrawable);
  /*** OpenGL END ***/

  return TRUE;
}

/***
 *** The "expose_event" signal handler. All the OpenGL re-drawing should
 *** be done here. This is repeatedly called as the painting routine
 *** every time the 'expose'/'draw' event is signalled.
 ***/
static gboolean
expose_event (GtkWidget      *widget,
	      GdkEventExpose *event,
	      gpointer        data)
{
  GdkGLContext *glcontext = gtk_widget_get_gl_context (widget);
  GdkGLDrawable *gldrawable = gtk_widget_get_gl_drawable (widget);

  g_print ("%s: \"expose_event\"\n", gtk_widget_get_name (widget));

  /*** OpenGL BEGIN ***/
  if (!gdk_gl_drawable_gl_begin (gldrawable, glcontext))
    return FALSE;

  /*** Fill in the details here. ***/

  /* Swap buffers */
  if (gdk_gl_drawable_is_double_buffered (gldrawable))
    gdk_gl_drawable_swap_buffers (gldrawable);
  else
    glFlush ();

  gdk_gl_drawable_gl_end (gldrawable);
  /*** OpenGL END ***/

  return TRUE;
}

/***
 *** The idle function. Often in animations,
 *** idle functions are suitable for continous
 *** frame updates.
 ***/
static gboolean
idle (gpointer data)
{
  g_print (".");

  /*** Fill in the details here ***/

  return TRUE;
}

static guint idle_id = 0;

static void
idle_add (GtkWidget *widget)
{
  if (idle_id == 0) {
    idle_id = gtk_idle_add_priority (GDK_PRIORITY_REDRAW,
				     (GtkFunction)idle,
				     widget);
  }
}

static void
idle_remove (GtkWidget *widget)
{
  if (idle_id != 0) {
    gtk_idle_remove (idle_id);
    idle_id = 0;
  }
}

/***
 *** The "map_event" signal handler. Any processing required when the
 *** OpenGL capable drawing area is mapped should be done here.
 ***/
static gboolean
map_event (GtkWidget *widget,
	   GdkEvent  *event,
	   gpointer   data)
{
  g_print ("%s: \"map_event\"\n", gtk_widget_get_name (widget));

  /*** Fill in the details here. ***/

#if 0
  idle_add(widget);
#endif

  return TRUE;
}

/***
 *** The "unmap_event" signal handler. Any processing required when the
 *** OpenGL capable drawing area is unmapped should be done here.
 ***/
static gboolean
unmap_event (GtkWidget *widget,
	     GdkEvent  *event,
	     gpointer   data)
{
  g_print ("%s: \"unmap_event\"\n", gtk_widget_get_name (widget));

  /*** Fill in the details here. ***/

#if 0
  idle_remove(widget);
#endif

  return TRUE;
}

/***
 *** The "visibility_notify_event" signal handler. Any processing required when
 *** the OpenGL capable drawing area is visually obscured should be done here.
 ***/
static gboolean
visibility_notify_event (GtkWidget          *widget,
			 GdkEventVisibility *event,
			 gpointer            data)
{
  g_print ("%s: \"visibility_notify_event\"\n", gtk_widget_get_name (widget));

  /*** Fill in the details here. ***/

#if 0
  if (event->state == GDK_VISIBILITY_FULLY_OBSCURED)
    idle_remove(widget);
  else
    idle_add(widget);
#endif

  return TRUE;
}

/***
 *** The "motion_notify_event" signal handler. Any processing required when the
 *** OpenGL capable drawing area is under drag motion should be done here.
 ***/
static gboolean
motion_notify_event (GtkWidget      *widget,
		     GdkEventMotion *event,
		     gpointer        data)
{
  g_print ("%s: \"motion_notify_event\": button", gtk_widget_get_name (widget));

  /*** Fill in the details here. ***/

  if (event->state & GDK_BUTTON1_MASK)
    {
      g_print (" 1");
    }

  if (event->state & GDK_BUTTON2_MASK)
    {
      g_print (" 2");
    }

  if (event->state & GDK_BUTTON3_MASK)
    {
      g_print (" 3");
    }

  g_print ("\n");

  return FALSE;
}

/***
 *** The "button_press_event" signal handler. Any processing required when
 *** mouse buttons (only left and middle buttons) are pressed on the OpenGL-
 *** capable drawing area should be done here.
 ***/
static gboolean
button_press_event (GtkWidget      *widget,
		    GdkEventButton *event,
		    gpointer        data)
{
  g_print ("%s: \"button_press_event\": ", gtk_widget_get_name (widget));

  switch (event->button)
    {
    case 1:
      /*** Fill in the details here. ***/
      g_print ("button 1\n");
      break;

    case 2:
      /*** Fill in the details here. ***/
      g_print ("button 2\n");
      break;

    case 3:
      /*** Fill in the details here. ***/
      g_print ("button 3\n");
      break;

    default:
      return FALSE;
    }

  return TRUE;
}

/***
 *** The "key_press_event" signal handler. Any processing required when key
 *** presses occur should be done here.
 ***/
static gboolean
key_press_event (GtkWidget   *widget,
		 GdkEventKey *event,
		 gpointer     data)
{
  g_print ("%s: \"key_press_event\": ", gtk_widget_get_name (widget));

  switch (event->keyval)
    {
      /*** Fill in the details here. ***/

    case GDK_Escape:
      g_print ("Escape key\n");
      gtk_main_quit();
      break;

    default:
      return FALSE;
    }

  return TRUE;
}

/***
 *** The "destroy" signal handler. Any processing required when
 *** the OpenGL capable drawing area is destroyed should be done here.
 ***/
static gboolean
destroy (GtkWidget *widget,
	 GdkEvent  *event,
	 gpointer   data)
{
  g_print ("%s: \"destroy\"\n", gtk_widget_get_name (widget));

  /*** Fill in the details here ***/

  return FALSE;
}


/**************************************************************************
 * The following section contains the GUI building function definitions.
 **************************************************************************/

/*** Creates the simple application window with one
 *** drawing area that is an OpenGL capable visual.
 ***/
static GtkWidget *
create_window (GdkGLConfig *glconfig)
{
  GtkWidget *window;
  GtkWidget *drawing_area;

  /* Top-level window. */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), DEFAULT_TITLE);

  /* Drawing area to draw OpenGL scene. */
  drawing_area = gtk_drawing_area_new ();
  gtk_widget_set_size_request (drawing_area, DEFAULT_WIDTH, DEFAULT_HEIGHT);

  gtk_widget_set_events (drawing_area,
			 GDK_EXPOSURE_MASK          |
			 GDK_BUTTON1_MOTION_MASK    |
			 GDK_BUTTON2_MOTION_MASK    |
			 GDK_BUTTON_PRESS_MASK      |
			 GDK_VISIBILITY_NOTIFY_MASK);

  gtk_container_add (GTK_CONTAINER (window), drawing_area);
  gtk_widget_show (drawing_area);

  /* Set OpenGL-capability to the widget */
  gtk_widget_set_gl_capability (drawing_area,
				glconfig,
				NULL,
				TRUE,
				GDK_GL_RGBA_TYPE);

  /* Connect signal handlers to the window */
  g_signal_connect (G_OBJECT (window), "delete_event",
		    G_CALLBACK (gtk_main_quit), NULL);
  g_signal_connect_swapped (G_OBJECT (window), "key_press_event",
			    G_CALLBACK (key_press_event), drawing_area);

  /* Connect signal handlers to the drawing area */
  g_signal_connect (G_OBJECT (drawing_area), "realize",
		    G_CALLBACK (realize), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "configure_event",
		    G_CALLBACK (configure_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "expose_event",
		    G_CALLBACK (expose_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "map_event",
		    G_CALLBACK (map_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "unmap_event",
		    G_CALLBACK (unmap_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "visibility_notify_event",
		    G_CALLBACK (visibility_notify_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "motion_notify_event",
		    G_CALLBACK (motion_notify_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "button_press_event",
		    G_CALLBACK (button_press_event), NULL);
  g_signal_connect (G_OBJECT (drawing_area), "destroy",
		    G_CALLBACK (destroy), NULL);

  return window;
}


/**************************************************************************
 * The following section contains utility function definitions.
 **************************************************************************/

/***
 *** Utility function to configure the OpenGL framebuffer.
 ***/
static GdkGLConfig *
configure_gl (void)
{
  GdkGLConfig *glconfig;

  if (!gdk_gl_query_extension ())
    {
      g_print("\n*** OpenGL is not supported.\n");
      exit(1);
    }

  /* Try double-buffered visual */
  glconfig = gdk_gl_config_new_by_mode (GDK_GL_MODE_RGB    |
					GDK_GL_MODE_DEPTH  |
					GDK_GL_MODE_DOUBLE);
  if (glconfig == NULL)
    {
      g_print("\n*** Cannot find the double-buffered visual.\n");
      g_print("\n*** Trying single-buffered visual.\n");

      /* Try single-buffered visual */
      glconfig = gdk_gl_config_new_by_mode (GDK_GL_MODE_RGB   |
					    GDK_GL_MODE_DEPTH);
      if (glconfig == NULL)
	{
	  g_print("*** No appropriate OpenGL-capable visual found.\n");
	  exit(1);
	}
    }

  return glconfig;
}


/**************************************************************************
 * The main function is rather trivial.
 **************************************************************************/

int
main (int    argc,
      char **argv)
{
  GtkWidget *window;
  GdkGLConfig *glconfig;

  /* Initialize Gtk. */
  gtk_set_locale ();
  gtk_init (&argc, &argv);

  /* Configure OpenGL framebuffer. */
  glconfig = configure_gl ();

  /* Create and show the application window. */
  window = create_window (glconfig);
  gtk_widget_show (window);

  gtk_main ();

  return 0;
}


/**************************************************************************
 * End of file.
 **************************************************************************/
