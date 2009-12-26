## -*- Makefile -*-
## Makefile.am for gtkglext/examples

EXTRA_DIST = \
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

noinst_LTLIBRARIES = libdrawshapes.la
libdrawshapes_la_SOURCES = drawshapes.c drawshapes.h
libdrawshapes_la_LIBADD = $(MATH_LIB) $(GL_LIBS) $(GLU_LIBS)

noinst_PROGRAMS =

noinst_PROGRAMS += low-level
low_level_SOURCES = low-level.c
low_level_LDFLAGS = $(GLU_LIBS)

noinst_PROGRAMS += simple
simple_SOURCES = simple.c

noinst_PROGRAMS += simple-mixed
simple_mixed_SOURCES = simple-mixed.c

noinst_PROGRAMS += pixmap
pixmap_SOURCES = pixmap.c

noinst_PROGRAMS += pixmap-mixed
pixmap_mixed_SOURCES = pixmap-mixed.c

noinst_PROGRAMS += share-lists
share_lists_SOURCES = share-lists.c

noinst_PROGRAMS += color
color_SOURCES = color.c

noinst_PROGRAMS += font
font_SOURCES = font.c

noinst_PROGRAMS += button
button_SOURCES = button.c
button_LDADD = $(LDADD) libdrawshapes.la

noinst_PROGRAMS += shapes
shapes_SOURCES = trackball.h trackball.c shapes.c
shapes_LDADD = $(LDADD) libdrawshapes.la

noinst_PROGRAMS += logo
logo_SOURCES = trackball.h trackball.c logo-model.h logo-model.c logo.c
logo_SOURCES += logo-g.h logo-t.h logo-k.h

noinst_PROGRAMS += gears
gears_SOURCES = gears.c

noinst_PROGRAMS += multiarb
multiarb_SOURCES = readtex.h readtex.c multiarb.c

noinst_PROGRAMS += viewlw
viewlw_SOURCES = viewlw.c lw.h lw.c trackball.h trackball.c

noinst_PROGRAMS += rotating-square
rotating_square_SOURCES = rotating-square.c

noinst_PROGRAMS += coolwave
coolwave_SOURCES = coolwave.c

noinst_PROGRAMS += coolwave2
coolwave2_SOURCES = coolwave2.c

noinst_PROGRAMS += template
template_SOURCES = template.c

noinst_PROGRAMS += scribble-gl
scribble_gl_SOURCES = scribble-gl.c

noinst_PROGRAMS += font-pangoft2
font_pangoft2_SOURCES = font-pangoft2.c
font_pangoft2_CPPFLAGS = $(AM_CPPFLAGS) $(PANGOFT2_CFLAGS)
font_pangoft2_LDFLAGS = $(AM_LDFLAGS) $(PANGOFT2_LIBS) $(GTKGLEXT_DEP_LIBS_WITH_PANGOFT2)

noinst_PROGRAMS += font-pangoft2-tex
font_pangoft2_tex_SOURCES = font-pangoft2-tex.c
font_pangoft2_tex_CPPFLAGS = $(AM_CPPFLAGS) $(PANGOFT2_CFLAGS)
font_pangoft2_tex_LDFLAGS = $(AM_LDFLAGS) $(PANGOFT2_LIBS) $(GTKGLEXT_DEP_LIBS_WITH_PANGOFT2)

if !PLATFORM_WIN32
noinst_PROGRAMS += simple-pbuffer-sgix
simple_pbuffer_sgix_SOURCES = simple-pbuffer-sgix.c
endif

if PLATFORM_WIN32
noinst_PROGRAMS += wglinfo
wglinfo_SOURCES = wglinfo.c
wglinfo_LDADD = $(GL_LIBS) $(WINDOWING_LIBS)
endif

if !PLATFORM_WIN32
noinst_PROGRAMS += glxinfo
glxinfo_SOURCES = glxinfo.c
glxinfo_LDADD = $(GL_LIBS) $(WINDOWING_LIBS) $(MATH_LIB)
endif


EXTRA_DIST += glade/README \
glade/simple.glade \
glade/simple.c \
glade/share-lists.glade	\
glade/share-lists.c

EXTRA_DIST += \
glsl/gears.c \
glsl/shiny.fsh \
glsl/shiny.vsh \
glsl/velvet.fsh \
glsl/velvet.vsh

