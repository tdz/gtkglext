/**************************************************************************
 * rotatingSquare.c
 *
 * Copyright (c) 2002 Alif Wahid <awah005@varsity.co.nz>
 *
 * A simple animation to demonstrate GtkGLExt.
 *
 * This program is in the public domain and you are using it at
 * your own risk.
 *
 **************************************************************************
 */

/**************************************************************************
 * Header file inclusions.
 **************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <gtk/gtk.h>
#include <gtk/gtkgl.h>
#include <gdk/gdkkeysyms.h>

#include <GL/gl.h>
#include <GL/glu.h>


/**************************************************************************
 * The following section contains all the macro definitions.
 **************************************************************************
 */

#define DEFAULT_WIDTH	200
#define DEFAULT_HEIGHT	200
#define DEFAULT_TITLE	"Rotating Square"


/**************************************************************************
 * Global variable declarations.
 **************************************************************************
 */

static float spin=0.0;
static int idleId=0;


/**************************************************************************
 * The following section contains all the callback function definitions.
 **************************************************************************
 */

/* Animation frame update function.
 */
static gboolean idle (gpointer data)
{
	spin += 2.0;
	if (spin > 360.0) spin -= 360.0;

	gtk_widget_queue_draw(GTK_WIDGET(data));

	return TRUE;
}

/* OpenGL initialisation at the time of the
 * widget realization.
 */
static void realize (GtkWidget* widget, gpointer data)
{
	GdkGLContext*	glcontext = gtk_widget_get_gl_context(widget);
	GdkGLDrawable*	gldrawable = gtk_widget_get_gl_drawable(widget);

	/*** OpenGL BEGIN ***/
	if (!gdk_gl_drawable_gl_begin(gldrawable, glcontext)) return;

	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);

	gdk_gl_drawable_gl_end(gldrawable);
	/*** OpenGL END ***/

	return;
}

/* Starts animating as soon as the widget has been mapped.
 */
static gboolean map (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	if (!idleId)
	{
		idleId = gtk_idle_add(idle, widget);
	}

	return TRUE;
}

/* Stops animating as soon as the widget has been unmapped.
 */
static gboolean unmap (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	if (idleId)
	{
		gtk_idle_remove(idleId);
		idleId = 0;
	}

	return TRUE;
}

/* Renders the actual OpenGL scene.
 */
static gboolean expose (GtkWidget* widget, GdkEventExpose* event, gpointer data)
{
	GdkGLContext*	glcontext = gtk_widget_get_gl_context(widget);
	GdkGLDrawable*	gldrawable = gtk_widget_get_gl_drawable(widget);

	/*** OpenGL BEGIN ***/
	if (!gdk_gl_drawable_gl_begin(gldrawable, glcontext)) return FALSE;

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();

	/* Swap buffers */
	if (gdk_gl_drawable_is_double_buffered(gldrawable))
		gdk_gl_drawable_swap_buffers(gldrawable);
	else
		glFlush();

	gdk_gl_drawable_gl_end(gldrawable);
	/*** OpenGL END ***/

	return TRUE;
}

/* Resizes the OpenGL viewport every time the
 * window is re-configured.
 */
static gboolean configure (GtkWidget* widget, GdkEventConfigure* event, gpointer data)
{
	GLfloat w = widget->allocation.width;
	GLfloat h = widget->allocation.height;

	GdkGLContext*	glcontext = gtk_widget_get_gl_context(widget);
	GdkGLDrawable*	gldrawable = gtk_widget_get_gl_drawable(widget);

	/*** OpenGL BEGIN ***/
	if (!gdk_gl_drawable_gl_begin(gldrawable, glcontext)) return FALSE;

	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gdk_gl_drawable_gl_end(gldrawable);
	/*** OpenGL END ***/

	return TRUE;
}

/*** The 'visibility_notify' event callback. Any processing required when the
 *** OpenGL capable drawing area is visually obscured should be done here.
 ***/
static gboolean visibilityNotify (GtkWidget* widget, GdkEventVisibility* event, gpointer data)
{
	/*** Fill in the details here. ***/

	return FALSE;
}

/* Starts/Stops animation according mouse button clicks.
 */
static gboolean buttonPress (GtkWidget* widget, GdkEventButton* event, gpointer data)
{
	switch (event->button)
	{
		case 1:
			if (!idleId)
			{
				idleId = gtk_idle_add(idle, widget);
			}
			break;

		case 2:
			if (idleId)
			{
				gtk_idle_remove(idleId);
				idleId = 0;
			}
			break;

		default:
			return FALSE;
	}

	return TRUE;
}

/*** The 'motion_notify' event callback. Any processing required when the
 *** OpenGL capable drawing area is under drag motion should be done here.
 ***/
static gboolean motionNotify (GtkWidget* widget, GdkEventMotion* event, gpointer data)
{
	/*** Fill in the details here. ***/

	return FALSE;
}

/* Convenience keys for performing the same actions as
 * can be performed by the mouse.
 */
static gboolean keyPress (GtkWidget* widget, GdkEventKey* event, gpointer data)
{
	switch (event->keyval)
	{
		case GDK_Left:
			/* Rotate left. */
			if (!idleId)
			{
				spin += 2.0;
				if (spin > 360.0) spin -= 360.0;
			}
			break;

		case GDK_Right:
			/* Rotate right. */
			if (!idleId)
			{
				spin -= 2.0;
				if (spin < 360.0) spin += 360.0;
			}
			break;

		case GDK_Up:
			/* Start animation. */
			if (!idleId)
			{
				idleId = gtk_idle_add(idle, widget);
			}
			break;

		case GDK_Down:
			/* Stop animation. */
			if (idleId)
			{
				gtk_idle_remove(idleId);
				idleId = 0;
			}
			break;

		default:
			return FALSE;
	}

	gtk_widget_queue_draw(widget);

	return TRUE;
}

/*** The 'button_press' event callback for right-clicks. Any processing
 *** required when the right mouse button is pressed on the OpenGL capable
 *** drawing area should be done here.
 ***/
static gboolean rightClick (GtkWidget* widget, GdkEventButton* event, gpointer data)
{
	switch (event->button)
	{
		case 3:
			/*** Fill in the details here. ***/
			break;

		default:
			return FALSE;
	}

	return TRUE;
}

/*** The 'delete_event' callback. Any processing required when
 *** the OpenGL capable drawing area is destroyed should be done here.
 ***/
static gboolean destroy (GtkWidget* widget, GdkEvent* event, gpointer data)
{
	/*** Fill in the details here ***/

	return FALSE;
}


/**************************************************************************
 * The following section contains utility function defitions.
 **************************************************************************
 */

/*** Utility function to initialise GtkGLExt properly.
 ***/
static void gtk_glext_init (GdkGLConfig** glconfig)
{
	if (gdk_gl_query_extension())
	{
		/* Try double-buffered visual */
		*glconfig = gdk_gl_config_new_by_mode(	GDK_GL_MODE_RGB 	|
                                       			GDK_GL_MODE_DEPTH 	|
                                       			GDK_GL_MODE_DOUBLE	);

		if (*glconfig == NULL)
		{
			g_print("\n*** Cannot find the double-buffered visual.\n");
			g_print("\n*** Trying single-buffered visual.\n");

			/* Try single-buffered visual */
			*glconfig = gdk_gl_config_new_by_mode(	GDK_GL_MODE_RGB 	|
                                         			GDK_GL_MODE_DEPTH	);
			if (*glconfig == NULL)
			{
				g_print("*** No appropriate OpenGL-capable visual found.\n");
				exit(1);
			}
		}
	}
	else
	{
		g_print("\n*** OpenGL is not supported.\n");
		exit(1);
	}
}


/**************************************************************************
 * The following section contains the GUI building function definitions.
 **************************************************************************
 */

/*** Creates the simple application window with one
 *** drawing area that is an OpenGL capable visual.
 ***/
static GtkWidget* create_window (GdkGLConfig* glconfig)
{
	GtkWidget* window=NULL;
	GtkWidget* drawable=NULL;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), DEFAULT_TITLE);
	/* The window will be sensitive to key presses and
	 * right clicks. The right click is prodominently used
	 * for popup menus so it should really be connected
	 * to the window.
	 */
	gtk_widget_set_events( window,
					   GDK_KEY_PRESS_MASK			|
					   GDK_KEY_RELEASE_MASK			|
					   GDK_BUTTON3_MASK				);

	drawable = gtk_drawing_area_new();
	g_object_set_data(G_OBJECT(window), "drawable", drawable);
	gtk_widget_set_size_request(drawable, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	/* The drawing area will be sensitive to the left and
	 * middle mouse button presses and drags. These two
	 * buttons are predominently used to perform the actual
	 * actions in a GUI, so they should really be connected
	 * to the OpenGL capable visual.
	 */
	gtk_widget_set_events( drawable,
                        	   GDK_EXPOSURE_MASK			|
					   GDK_BUTTON1_MASK				|
					   GDK_BUTTON2_MASK				|
					   GDK_BUTTON1_MOTION_MASK		|
					   GDK_BUTTON2_MOTION_MASK		|
					   GDK_VISIBILITY_NOTIFY_MASK		);

	gtk_container_add(GTK_CONTAINER(window), drawable);
	gtk_widget_show(drawable);

	/* Set OpenGL-capability to the widget */
	gtk_widget_set_gl_capability( drawable,
							glconfig,
							NULL,
							TRUE,
							GDK_GL_RGBA_TYPE);

	/* Connect callbacks to the window */
	g_signal_connect(G_OBJECT(window), "delete_event",
				  G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect_swapped(G_OBJECT(window), "button_press_event",
				          G_CALLBACK(rightClick), drawable);
	g_signal_connect_swapped(G_OBJECT(window), "key_press_event",
				          G_CALLBACK(keyPress), drawable);

	/* Connect callbacks to the drawing area */
	g_signal_connect(G_OBJECT(drawable), "realize",
				  G_CALLBACK(realize), NULL);
	g_signal_connect(G_OBJECT(drawable), "configure_event",
				  G_CALLBACK(configure), NULL);
	g_signal_connect(G_OBJECT(drawable), "expose_event",
				  G_CALLBACK(expose), NULL);
	g_signal_connect(G_OBJECT(drawable), "map_event",
				  G_CALLBACK(map), NULL);
	g_signal_connect(G_OBJECT(drawable), "unmap_event",
				  G_CALLBACK(unmap), NULL);
	g_signal_connect(G_OBJECT(drawable), "visibility_notify_event",
				  G_CALLBACK(visibilityNotify), NULL);
	g_signal_connect(G_OBJECT(drawable), "button_press_event",
				  G_CALLBACK(buttonPress), NULL);
	g_signal_connect(G_OBJECT(drawable), "motion_notify_event",
				  G_CALLBACK(motionNotify), NULL);
	g_signal_connect(G_OBJECT(drawable), "delete_event",
				  G_CALLBACK(destroy), NULL);

	return window;
}


/**************************************************************************
 * The main function is rather trivial.
 **************************************************************************
 */

int main (int argc, char** argv)
{
	GtkWidget*	window=NULL;
	GdkGLConfig*	glconfig=NULL;

	/* Initialise Gtk and GtkGLExt. */
	gtk_set_locale();
	gtk_init(&argc, &argv);
	gtk_glext_init(&glconfig);

	/* Create and show the application window. */
	window = create_window(glconfig);
	gtk_widget_show(window);

	gtk_main();
	return 0;
}

/**************************************************************************
 * End of file.
 **************************************************************************
 */
