/**************************************************************************
 * coolwave.c
 *
 * Copyright (c) 2002 Alif Wahid <awah005@varsity.co.nz>
 *
 * A program to demonstrate GtkGLExt. It's a modified version
 * of the old IrisGL demo 'newave', first ported to OpenGL and
 * Glut by Erik Larsen. Now I have modified it to use Gtk and GtkGLExt
 * comprehensively along with ofcourse OpenGL.
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

#define DEFAULT_WIDTH	300
#define DEFAULT_HEIGHT	200
#define DEFAULT_TITLE	"CoolWave"

#if defined(GL_EXT_polygon_offset) && !defined(GL_VERSION_1_1)
	#define glPolygonOffset(A,B)     glPolygonOffsetEXT(A,B)
	#define GL_POLYGON_OFFSET_FILL   GL_POLYGON_OFFSET_EXT
#endif

#define MAXGRID 63
#define SQRTOFTWOINV (1.0 / 1.414213562)
#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif


/**************************************************************************
 * Global variable declarations.
 **************************************************************************
 */

static int grid = (MAXGRID/2);
static int beginX, beginY;
static int idleId = 0;

static float force[MAXGRID][MAXGRID];
static float veloc[MAXGRID][MAXGRID];
static float posit[MAXGRID][MAXGRID];

static float dt = 0.008;
static float sphi=90.0;
static float stheta=45.0;
static float sdepth = 5.0/4.0 * (MAXGRID/2);
static float zNear=(MAXGRID/2)/10.0;
static float zFar=(MAXGRID/2)*3.0;
static float aspect = 5.0/4.0;

static float lightPosition[4] = { 0.0, 0.0, 1.0, 1.0};


/**************************************************************************
 * The waving functions.
 **************************************************************************
 */

void getforce (void)
{
	int i=0, j=0;
	float d;

	for(i=0;i<grid;i++)
	{
		for(j=0;j<grid;j++)
		{
			force[i][j]=0.0;
		}
	}

	for(i=2;i<grid-2;i++)
	{
		for(j=2;j<grid-2;j++)
		{
			d=posit[i][j]-posit[i][j-1];
			force[i][j] -= d;
			force[i][j-1] += d;

			d=posit[i][j]-posit[i-1][j];
			force[i][j] -= d;
			force[i-1][j] += d;

			d= (posit[i][j]-posit[i][j+1]);
			force[i][j] -= d ;
			force[i][j+1] += d;

			d= (posit[i][j]-posit[i+1][j]);
			force[i][j] -= d ;
			force[i+1][j] += d;

			d= (posit[i][j]-posit[i+1][j+1])*SQRTOFTWOINV;
			force[i][j] -= d ;
			force[i+1][j+1] += d;

			d= (posit[i][j]-posit[i-1][j-1])*SQRTOFTWOINV;
			force[i][j] -= d ;
			force[i-1][j-1] += d;

			d= (posit[i][j]-posit[i+1][j-1])*SQRTOFTWOINV;
			force[i][j] -= d ;
			force[i+1][j-1] += d;

			d= (posit[i][j]-posit[i-1][j+1])*SQRTOFTWOINV;
			force[i][j] -= d ;
			force[i- 1][j+1] += d;
		}
	}
}

void getvelocity (void)
{
	int i=0, j=0;

	for(i=0;i<grid;i++)
	{
		for(j=0;j<grid;j++) veloc[i][j]+=force[i][j] * dt;
	}
}

void getposition (void)
{
	int i=0, j=0;

	for(i=0;i<grid;i++)
	{
		for(j=0;j<grid;j++) posit[i][j]+=veloc[i][j];
	}
}

void drawWireframe (void)
{
	int i=0, j=0;

	glColor3f(1.0, 1.0, 1.0);

	for(i=0;i<grid;i++)
	{
		glBegin(GL_LINE_STRIP);
		for(j=0;j<grid;j++) glVertex3f((float)i,(float)j,(float)posit[i][j]);
		glEnd();
	}

	for(i=0;i<grid;i++)
	{
		glBegin(GL_LINE_STRIP);
		for(j=0;j<grid;j++) glVertex3f((float)j,(float)i,(float)posit[j][i]);
		glEnd();
	}
}

void resetWireframe (void)
{
	int i=0, j=0;

	for(i=0;i<grid;i++)
	{
		for(j=0;j<grid;j++)
		{
			force[i][j]=0.0;
			veloc[i][j]=0.0;

			posit[i][j]= 	(sin(M_PI*2 * ((float)i/(float)grid)) +
						 sin(M_PI*2 * ((float)j/(float)grid)))* grid/6.0;

			if (i==0||j==0||i==grid-1||j==grid-1) posit[i][j]=0.0;
		}
	}
}


/**************************************************************************
 * The following section contains all the callback function definitions.
 **************************************************************************
 */

/* Animation frame update function.
 */
static gboolean idle (gpointer data)
{
	getforce();
	getvelocity();
	getposition();

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

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPolygonOffset(1.0, 1.0);
	glEnable(GL_CULL_FACE);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glLightfv (GL_LIGHT0, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_FLAT);
	glDisable(GL_LIGHTING);

	resetWireframe();

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

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(64.0, aspect, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0,0.0,-sdepth);
	glRotatef(-stheta, 1.0, 0.0, 0.0);
	glRotatef(sphi, 0.0, 0.0, 1.0);
	glTranslatef(-(float)((grid+1)/2-1), -(float)((grid+1)/2-1), 0.0);

	drawWireframe();

	/* Swap buffers */
	if (gdk_gl_drawable_is_double_buffered(gldrawable))
		gdk_gl_drawable_swap_buffers(gldrawable);
	else
		glFlush();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

	aspect = (float)w/(float)h;
	glViewport(0, 0, w, h);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gdk_gl_drawable_gl_end(gldrawable);
	/*** OpenGL END ***/

	return TRUE;
}

/* Once the visibility of the window has been fully
 * obscured, then stops animating.
 */
static gboolean visibilityNotify (GtkWidget* widget, GdkEventVisibility* event, gpointer data)
{
	if (event->state == GDK_VISIBILITY_FULLY_OBSCURED)
	{
		if (!idleId)
		{
			idleId = gtk_idle_add(idle, widget);
		}
	}
	else
	{
		if (idleId)
		{
			gtk_idle_remove(idleId);
			idleId = 0;
		}
	}

	return TRUE;
}

/* Stores the x and y coordinates at the start of any drag motions.
 */
static gboolean buttonPress (GtkWidget* widget, GdkEventButton* event, gpointer data)
{
	switch (event->button)
	{
		case 1:
			beginX = event->x;
			beginY = event->y;
			break;

		case 2:
			/*** Fill in the details here. ***/
			break;

		default:
			return FALSE;
	}

	return TRUE;
}

/* Handles the mouse button drag motion. Left button drag results
 * in a trackball and the middle button drag results in zooming.
 */
static gboolean motionNotify (GtkWidget* widget, GdkEventMotion* event, gpointer data)
{
	if (event->state & GDK_BUTTON1_MASK)
	{
		sphi += (float)(event->x - beginX) / 4.0;
		stheta += (float)(beginY - event->y) / 4.0;

		gtk_widget_queue_draw(widget);
	}

	if (event->state & GDK_BUTTON2_MASK)
	{
		sdepth -= ((event->y - beginY)/(widget->allocation.height))*(MAXGRID/2);

		gtk_widget_queue_draw(widget);
	}

	beginX = event->x;
	beginY = event->y;

	return TRUE;
}

/* Convenience keys for performing the same actions as
 * can be performed by the mouse.
 */
static gboolean keyPress (GtkWidget* widget, GdkEventKey* event, gpointer data)
{
	switch (event->keyval)
	{
		case GDK_r:
			resetWireframe();
			break;

		case GDK_Up:
			if (!idleId)
			{
				idleId = gtk_idle_add(idle, widget);
			}
			break;

		case GDK_Down:
			if (idleId)
			{
				gtk_idle_remove(idleId);
				idleId = 0;
			}
			break;

		case GDK_plus:
			sdepth -= 2.0;
			break;

		case GDK_minus:
			sdepth += 2.0;
			break;

		default:
			return FALSE;
	}

	gtk_widget_queue_draw(widget);

	return TRUE;
}

/* Popup menu displayer.
 */
static gboolean rightClick (GtkWidget* widget, GdkEventButton* event, gpointer data)
{
	switch (event->button)
	{
		case 3:
			gtk_menu_popup(GTK_MENU(widget), NULL, NULL, NULL, NULL,
						event->button, event->time);
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
 * Popup menu callback functions.
 **************************************************************************
 */
static void toggleWaveAnim (GtkWidget* widget)
{
	if (!idleId)
	{
		idleId = gtk_idle_add(idle, widget);
	}
	else if (idleId)
	{
		gtk_idle_remove(idleId);
		idleId = 0;
	}
}

static void initWireframe (GtkWidget* widget)
{
	resetWireframe();
	gtk_widget_queue_draw(widget);
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

/*** Creates the popup menu to be displayed.
 ***/
static GtkWidget* create_popup (GtkWidget* drawable)
{
	GtkWidget* menu=NULL;
	GtkWidget* menuItem=NULL;

	menu = gtk_menu_new();

	menuItem = gtk_menu_item_new_with_label("Toggle Animation");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuItem);
	g_signal_connect_swapped(G_OBJECT(menuItem), "activate",
						G_CALLBACK(toggleWaveAnim), drawable);
	gtk_widget_show(menuItem);

	menuItem = gtk_menu_item_new_with_label("Initialise");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuItem);
	g_signal_connect_swapped(G_OBJECT(menuItem), "activate",
						G_CALLBACK(initWireframe), drawable);
	gtk_widget_show(menuItem);

	menuItem = gtk_menu_item_new_with_label("Quit");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuItem);
	g_signal_connect(G_OBJECT(menuItem), "activate",
				  G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show(menuItem);
	
	return menu;
}

/*** Creates the simple application window with one
 *** drawing area that is an OpenGL capable visual.
 ***/
static GtkWidget* create_window (GdkGLConfig* glconfig)
{
	GtkWidget* window=NULL;
	GtkWidget* drawable=NULL;
	GtkWidget* popup=NULL;

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

	popup = create_popup(drawable);

	/* Connect callbacks to the window */
	g_signal_connect(G_OBJECT(window), "delete_event",
				  G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect_swapped(G_OBJECT(window), "button_press_event",
				          G_CALLBACK(rightClick), popup);
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
