## -*- Makefile -*-
## Makefile.am for gtkglext/examples

SUBDIRS = 
DIST_SUBDIRS = glade

EXTRA_DIST = \
	Makefile.mingw	\
	Makefile.msc	\
	alien.lwo	\
	penguin.lwo	\
	girl.rgb	\
	reflect.rgb

AM_CPPFLAGS = \
	-I$(top_srcdir) 		\
	-I$(top_builddir)/gdk		\
	-I$(top_builddir)/gtk		\
	$(GTKGLEXT_DEBUG_FLAGS)		\
	$(GTK_CFLAGS)			\
	$(GL_CFLAGS)			\
	$(GDKGLEXT_WIN_CFLAGS)		\
	$(EXAMPLES_DEP_CFLAGS)		\
	-DG_DISABLE_DEPRECATED		\
	-DGDK_DISABLE_DEPRECATED	\
	-DGDK_PIXBUF_DISABLE_DEPRECATED	\
	-DGTK_DISABLE_DEPRECATED

LDADD = \
	../gdk/$(gdkglext_targetlib)	\
	../gtk/$(gtkglext_targetlib)

AM_LDFLAGS = \
	$(GTK_LIBS)		\
	$(GLU_LIBS)		\
	$(GDKGLEXT_WIN_LIBS)

noinst_PROGRAMS = \
	low-level		\
	simple			\
	simple-mixed		\
	pixmap			\
	pixmap-mixed		\
	share-lists		\
	color			\
	font			\
	button			\
	shapes			\
	logo			\
	gears			\
	multiarb		\
	viewlw			\
	rotating-square		\
	coolwave		\
	coolwave2		\
	template		\
	scribble-gl		\
	font-pangoft2		\
	font-pangoft2-tex

if PLATFORM_WIN32
noinst_PROGRAMS += wglinfo
else
noinst_PROGRAMS += simple-pbuffer-sgix
noinst_PROGRAMS += glxinfo
endif

low_level_SOURCES = low-level.c

simple_SOURCES = simple.c

simple_mixed_SOURCES = simple-mixed.c

pixmap_SOURCES = pixmap.c

pixmap_mixed_SOURCES = pixmap-mixed.c

share_lists_SOURCES = share-lists.c

color_SOURCES = color.c

font_SOURCES = font.c

button_SOURCES = button.c

shapes_SOURCES = trackball.h trackball.c shapes.c

logo_SOURCES = trackball.h trackball.c logo-model.h logo-model.c logo.c
EXTRA_logo_SOURCES = logo-g.c logo-t.c logo-k.c

gears_SOURCES = gears.c

multiarb_SOURCES = readtex.h readtex.c multiarb.c

viewlw_SOURCES = viewlw.c lw.h lw.c trackball.h trackball.c

rotating_square_SOURCES = rotating-square.c

coolwave_SOURCES = coolwave.c

coolwave2_SOURCES = coolwave2.c

template_SOURCES = template.c

scribble_gl_SOURCES = scribble-gl.c

font_pangoft2_SOURCES = font-pangoft2.c
font_pangoft2_CPPFLAGS = $(AM_CPPFLAGS) $(PANGOFT2_CFLAGS)
font_pangoft2_LDFLAGS = $(AM_LDFLAGS) $(GTKGLEXT_DEP_LIBS_WITH_PANGOFT2)

font_pangoft2_tex_SOURCES = font-pangoft2-tex.c
font_pangoft2_tex_CPPFLAGS = $(AM_CPPFLAGS) $(PANGOFT2_CFLAGS)
font_pangoft2_tex_LDFLAGS = $(AM_LDFLAGS) $(GTKGLEXT_DEP_LIBS_WITH_PANGOFT2)

simple_pbuffer_sgix_SOURCES = simple-pbuffer-sgix.c

glxinfo_SOURCES = glxinfo.c
glxinfo_LDADD = $(GL_LIBS) $(WINDOWING_LIBS) $(MATH_LIB)

wglinfo_SOURCES = wglinfo.c
wglinfo_LDADD = $(GL_LIBS) $(WINDOWING_LIBS)
