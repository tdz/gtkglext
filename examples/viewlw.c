/*
 * Copyright (C) 1998 Janne Löf <jlof@mail.student.oulu.fi>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* Modified on 10th June 2002, for porting this program
 * to the 'gtkglext-0.1.0` extension of gtk-2.0.
 *
 * Alif Wahid, <awah005@varsity.co.nz>
 */

#include <string.h>
#include <math.h>
#include <gtk/gtk.h>
#include <gtk/gtkgl.h>
#include <GL/gl.h>
#include <GL/glu.h>


#include "trackball.h"
#include "lw.h"

#define VIEW_ASPECT 1.3

void select_lwobject(void);
gint show_lwobject(const char *lwobject_name);

/* information needed to display lightwave mesh */
typedef struct
{
  gint do_init;         /* true if initgl not yet called */
  lwObject *lwobject;   /* lightwave object mesh */
  float beginx,beginy;  /* position of mouse */
  float quat[4];        /* orientation of object */
  float zoom;           /* field of view in degrees */

} mesh_info;

char help_text[] = "Usage: viewlw [OPTION]... [FILE]...\n"
                   "View LightWave 3D objects.\n"
                   "\n"
                   "Options:\n"
                   "  --help                            display help\n"
                   "\n"
                   "In the program:\n"
                   "  Mouse button 1 + drag             spin (virtual trackball)\n"
                   "  Mouse button 2 + drag             zoom\n"
                   "  Mouse button 3                    popup menu\n"
                   "\n";

static const gint config_attributes[] =
{
     GDK_GL_DOUBLEBUFFER,
     GDK_GL_RGBA,
     GDK_GL_RED_SIZE,        1,
     GDK_GL_GREEN_SIZE,      1,
     GDK_GL_BLUE_SIZE,       1,
     GDK_GL_DEPTH_SIZE,      12,
     GDK_GL_ATTRIB_LIST_NONE
};

static GdkGLConfig *glconfig = NULL;

void initgl (GtkWidget *widget, gpointer   data)
{
     GLfloat light0_pos[4]   = { -50.0, 50.0, 0.0, 0.0 };
     GLfloat light0_color[4] = { .6, .6, .6, 1.0 }; /* white light */
     GLfloat light1_pos[4]   = {  50.0, 50.0, 0.0, 0.0 };
     GLfloat light1_color[4] = { .4, .4, 1, 1.0 };  /* cold blue light */

     /* OpenGL begin. */
     gtk_widget_gl_begin (widget);

     /* remove back faces */
     glDisable(GL_CULL_FACE);
     glEnable(GL_DEPTH_TEST);

     /* speedups */
     glEnable(GL_DITHER);
     glShadeModel(GL_SMOOTH);
     glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
     glHint(GL_POLYGON_SMOOTH_HINT, GL_FASTEST);

     /* light */
     glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
     glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0_color);
     glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
     glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_color);
     glEnable(GL_LIGHT0);
     glEnable(GL_LIGHT1);
     glEnable(GL_LIGHTING);

     glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
     glEnable(GL_COLOR_MATERIAL);

     gtk_widget_gl_end (widget);
     /* OpenGL end. */
}

gint expose(GtkWidget *widget, GdkEventExpose *event)
{
     GLfloat m[4][4];
     mesh_info *info = (mesh_info*)gtk_object_get_data(GTK_OBJECT(widget), "mesh_info");

     /* draw only last expose */
     if (event->count > 0) {
     return TRUE;
     }

     /* basic initialization */
     if (info->do_init == TRUE) {
      initgl(widget, NULL);
      info->do_init = FALSE;
     }

     gtk_widget_gl_begin(widget);

     /* view */
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(info->zoom, VIEW_ASPECT, 1,100);
     glMatrixMode(GL_MODELVIEW);

     /* draw object */
     glClearColor(.3,.4,.6,1);
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

     glLoadIdentity();
     glTranslatef(0,0,-30);
     build_rotmatrix(m,info->quat);
     glMultMatrixf(&m[0][0]);

     lw_object_show(info->lwobject);

     /* swap backbuffer to front */
     gtk_widget_gl_swap_buffers(widget);

     gtk_widget_gl_end(widget);

     return TRUE;
}

gint configure(GtkWidget *widget, GdkEventConfigure *event, gpointer data)
{
     g_return_val_if_fail(widget && event, FALSE);

     /* OpenGL begin. */
     gtk_widget_gl_begin (widget);
     glViewport (0, 0, widget->allocation.width, widget->allocation.height);
     gtk_widget_gl_end (widget);
     /* OpenGL end. */

     return TRUE;
}

gint destroy(GtkWidget *widget)
{
     /* delete mesh info */
     mesh_info *info = (mesh_info*)gtk_object_get_data(GTK_OBJECT(widget), "mesh_info");
     if (info)
     {
          lw_object_free(info->lwobject);
          g_free(info);
     }

     return TRUE;
}

gint button_press(GtkWidget *widget, GdkEventButton *event)
{
     mesh_info *info = (mesh_info*)gtk_object_get_data(GTK_OBJECT(widget), "mesh_info");
     if (event->button == 1)
     {
          /* beginning of drag, reset mouse position */
          info->beginx = event->x;
          info->beginy = event->y;
          return TRUE;
     }

     return FALSE;
}

gint motion_notify(GtkWidget *widget, GdkEventMotion *event)
{
     int x = 0;
     int y = 0;
     GdkModifierType state = 0;
     float width, height;
     mesh_info *info = (mesh_info*)gtk_object_get_data(GTK_OBJECT(widget), "mesh_info");

     if (event->is_hint)
     {
          // fix this!
          #if !defined(WIN32)
          gdk_window_get_pointer(event->window, &x, &y, &state);
          #endif
     }
     else
     {
          x = event->x;
          y = event->y;
          state = event->state;
     }

     width = widget->allocation.width;
     height = widget->allocation.height;

     if (state & GDK_BUTTON1_MASK)
     {
          /* drag in progress, simulate trackball */
          float spin_quat[4];
          trackball( spin_quat,
          	      (2.0*info->beginx -            width) / width,
          	      (          height - 2.0*info->beginy) / height,
          	      (           2.0*x -            width) / width,
          	      (          height -            2.0*y) / height );
          add_quats(spin_quat, info->quat, info->quat);

          /* orientation has changed, redraw mesh */
          gtk_widget_queue_draw(widget);
     }

     if (state & GDK_BUTTON2_MASK)
     {
          /* zooming drag */
          info->zoom += ((y - info->beginy) / height) * 40.0;
          if (info->zoom < 5.0) info->zoom = 5.0;
          if (info->zoom > 120.0) info->zoom = 120.0;
          /* zoom has changed, redraw mesh */
          gtk_widget_queue_draw(widget);
     }

     info->beginx = x;
     info->beginy = y;

     return TRUE;
}


gint popup_menu_handler(GtkWidget *widget, GdkEventButton *event)
{
     if (event->button == 3)
     {
          gtk_menu_popup(GTK_MENU(widget), NULL, NULL, NULL, NULL, event->button, event->time);
          return TRUE;
     }

     return FALSE;
}

void popup_menu_detacher(GtkWidget *attach_widget,GtkMenu *menu)
{
}

void create_popup_menu(GtkWidget *widget)
{
     GtkWidget *menu          = gtk_menu_new();
     GtkWidget *open_item     = gtk_menu_item_new_with_label("Open");
     GtkWidget *quit_item     = gtk_menu_item_new_with_label("Quit");
     GtkWidget *quit_all_item = gtk_menu_item_new_with_label("Quit All");

     gtk_menu_append(GTK_MENU(menu), open_item);
     gtk_menu_append(GTK_MENU(menu), quit_item);
     gtk_menu_append(GTK_MENU(menu), quit_all_item);

     gtk_widget_show(open_item);
     gtk_widget_show(quit_item);
     gtk_widget_show(quit_all_item);

     gtk_menu_attach_to_widget(GTK_MENU(menu),GTK_WIDGET(widget),popup_menu_detacher);

     gtk_signal_connect_object(GTK_OBJECT(widget), "destroy",
     			    GTK_SIGNAL_FUNC(gtk_menu_detach), GTK_OBJECT(menu));

     gtk_signal_connect_object(GTK_OBJECT(widget), "button_press_event",
     			    GTK_SIGNAL_FUNC(popup_menu_handler), GTK_OBJECT(menu));

     gtk_signal_connect(GTK_OBJECT(open_item), "activate",
     		         GTK_SIGNAL_FUNC(select_lwobject), NULL);

     gtk_signal_connect_object(GTK_OBJECT(quit_item), "activate",
     			    GTK_SIGNAL_FUNC(gtk_widget_destroy), GTK_OBJECT(widget));

     gtk_signal_connect(GTK_OBJECT(quit_all_item), "activate",
     		         GTK_SIGNAL_FUNC(gtk_main_quit), NULL);
}

gint window_count = 0; /* number of windows on screen */
gint window_destroy(GtkWidget *widget)
{
     /* if this was last window quit */
     if (--window_count == 0)
          gtk_main_quit();
     return TRUE;
}

gint show_lwobject(const char *lwobject_name)
{
     GtkWidget *window, *frame, *glarea;
     mesh_info *info;
     lwObject *lwobject;

     /* read lightwave object */
     if (!lw_is_lwobject(lwobject_name))
     {
          g_print("%s is not a LightWave 3D object\n", lwobject_name);
          return FALSE;
     }
     lwobject = lw_object_read(lwobject_name);
     if (lwobject == NULL)
     {
          g_print("Can't read LightWave 3D object %s\n", lwobject_name);
          return FALSE;
     }
     lw_object_scale(lwobject, 10.0 / lw_object_radius(lwobject));


     /* create aspect frame */
     frame = gtk_aspect_frame_new(NULL, 0.5,0.5, VIEW_ASPECT, FALSE);

     /* create new OpenGL widget */
     glarea = gtk_drawing_area_new ();
     if (glarea == NULL)
     {
          lw_object_free(lwobject);
          g_print("Can't create GtkDrawingArea widget\n");
          return FALSE;
     }

     /* Set OpenGL-capability to the widget. */
     gtk_widget_set_gl_capability (GTK_WIDGET (glarea),
                                glconfig,
                                GDK_GL_RGBA_TYPE,
                                NULL,
                                TRUE);

     /* set up events and signals for OpenGL widget */
     gtk_widget_set_events(glarea,
     			GDK_EXPOSURE_MASK|
     			GDK_BUTTON_PRESS_MASK|
     			GDK_BUTTON_RELEASE_MASK|
     			GDK_POINTER_MOTION_MASK|
     			GDK_POINTER_MOTION_HINT_MASK);

     gtk_signal_connect (GTK_OBJECT(glarea), "expose_event",
     		      GTK_SIGNAL_FUNC(expose), NULL);

     gtk_signal_connect (GTK_OBJECT(glarea), "motion_notify_event",
     		      GTK_SIGNAL_FUNC(motion_notify), NULL);

     gtk_signal_connect (GTK_OBJECT(glarea), "button_press_event",
     		      GTK_SIGNAL_FUNC(button_press), NULL);

     gtk_signal_connect (GTK_OBJECT(glarea), "configure_event",
     		      GTK_SIGNAL_FUNC(configure), NULL);

     gtk_signal_connect (GTK_OBJECT(glarea), "destroy",
     		      GTK_SIGNAL_FUNC(destroy), NULL);

     gtk_widget_set_size_request(glarea, 200,200/VIEW_ASPECT); /* minimum size */

     /* set up mesh info */
     info = (mesh_info*)g_malloc(sizeof(mesh_info));
     info->do_init = TRUE;
     info->lwobject = lwobject;
     info->beginx = 0;
     info->beginy = 0;
     info->zoom   = 45;
     trackball(info->quat , 0.0, 0.0, 0.0, 0.0);
     gtk_object_set_data(GTK_OBJECT(glarea), "mesh_info", info);


     /* create new top level window */
     window = gtk_window_new( GTK_WINDOW_TOPLEVEL);
     gtk_window_set_title(GTK_WINDOW(window), lwobject_name);
     gtk_container_set_border_width(GTK_CONTAINER(window), 10);
     create_popup_menu(window); /* add popup menu to window */
     gtk_signal_connect (GTK_OBJECT(window), "destroy",
     		          GTK_SIGNAL_FUNC(window_destroy), NULL);
     window_count++;

     /* destroy this window when exiting from gtk_main() */
     gtk_quit_add_destroy(1, GTK_OBJECT(window));

     /* put glarea into window and show it all */
     gtk_container_add(GTK_CONTAINER(window), frame);
     gtk_container_add(GTK_CONTAINER(frame),glarea);
     gtk_widget_show(glarea);
     gtk_widget_show(frame);
     gtk_widget_show(window);

     return TRUE;
}



gint filew_ok(GtkWidget *widget, GtkWidget *filew)
{
     if (show_lwobject(gtk_file_selection_get_filename(GTK_FILE_SELECTION(filew))) == TRUE)
          gtk_widget_destroy(filew);
     return TRUE;
}

void select_lwobject()
{
     GtkWidget *filew = gtk_file_selection_new("Select LightWave 3D object");

     gtk_signal_connect(GTK_OBJECT(GTK_FILE_SELECTION (filew)->ok_button), "clicked",
     		         GTK_SIGNAL_FUNC(filew_ok), filew);

     gtk_signal_connect_object(GTK_OBJECT(GTK_FILE_SELECTION(filew)->cancel_button),
                               "clicked", GTK_SIGNAL_FUNC(gtk_widget_destroy),
                               GTK_OBJECT(filew));

     gtk_signal_connect (GTK_OBJECT(filew), "destroy",
     		          GTK_SIGNAL_FUNC(window_destroy), NULL);

     window_count++;

     gtk_widget_show(filew);
}

int main (int argc, char **argv)
{
     /* initialize gtk */
     gtk_init( &argc, &argv );

     /* Check if OpenGL extension is supported. */
     if (!gdk_gl_query_extension ())
     {
          g_print ("\n*** OpenGL extension is not supported\n");
          gtk_exit (1);
     }

     /* Configure OpenGL-capable visual. */

     /* Try double buffered visual */
     glconfig = gdk_gl_config_new (&config_attributes[0]);
     if (glconfig == NULL)
       {
         g_print ("*** Cannot find the OpenGL-capable visual with double buffering support.\n");
         g_print ("*** Trying single buffering visual.\n");

         /* Try single buffered visual */
         glconfig = gdk_gl_config_new (&config_attributes[1]);
         if (glconfig == NULL)
           {
             g_print ("*** Cannot find an OpenGL-capable visual\n");
             gtk_exit (1);
           }
       }

     /* help? */
     if (argc >= 2 && strcmp(argv[1],"--help")==0)
     {
          g_print("%s", help_text);
          return 0;
     }

     if (argc == 1)
     {
          /* no filenames, show filerequester */
          select_lwobject();
     }
     else
     {
          /* show requested files */
          int i;
          for (i=1; i<argc; i++)
          show_lwobject(argv[i]);
     }

     if (window_count > 0)
          gtk_main();

     return 0;
}
