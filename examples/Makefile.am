## -*- Makefile -*-
## Makefile.am for gtkglext/examples

INCLUDES = \
	-I$(top_srcdir) 		\
	-I$(top_builddir)		\
	$(GTKGLEXT_DEBUG_FLAGS)		\
	$(GTKGLEXT_DEP_CFLAGS)		\
	-DG_DISABLE_DEPRECATED		\
	-DGDK_DISABLE_DEPRECATED	\
	-DGDK_PIXBUF_DISABLE_DEPRECATED	\
	-DGTK_DISABLE_DEPRECATED

DEPS = \
	$(top_builddir)/gdk/$(gdkglext_targetlib)	\
	$(top_builddir)/gtk/$(gtkglext_targetlib)

LDADDS = \
	$(top_builddir)/gdk/$(gdkglext_targetlib)	\
	$(top_builddir)/gtk/$(gtkglext_targetlib)	\
	$(GTKGLEXT_DEP_LIBS)

common_programs = \
	low-level	\
	simple		\
	pixmap		\
	font		\
	gears		\
	viewlw

x11_programs = \
	glxinfo

if PLATFORM_WIN32
EXTRA_PROGRAMS = $(common_programs)
else
EXTRA_PROGRAMS = $(common_programs) $(x11_programs)
endif

low_level_SOURCES = low-level.c
low_level_DEPENDENCIES = $(DEPS)
low_level_LDADD = $(LDADDS)

simple_SOURCES = simple.c
simple_DEPENDENCIES = $(DEPS)
simple_LDADD = $(LDADDS)

pixmap_SOURCES = pixmap.c
pixmap_DEPENDENCIES = $(DEPS)
pixmap_LDADD = $(LDADDS)

font_SOURCES = font.c
font_DEPENDENCIES = $(DEPS)
font_LDADD = $(LDADDS)

gears_SOURCES = gears.c
gears_DEPENDENCIES = $(DEPS)
gears_LDADD = $(LDADDS)

viewlw_SOURCES = viewlw.c lw.h lw.c trackball.h trackball.c
viewlw_DEPENDENCIES = $(DEPS)
viewlw_LDADD = $(LDADDS)

glxinfo_SOURCES = glxinfo.c
glxinfo_DEPENDENCIES = $(DEPS)
glxinfo_LDADD = $(GL_LIBS) $(GDKGLEXT_WIN_LIBS)


.PHONY: examples files

examples: $(EXTRA_PROGRAMS)

clean-local:
	-rm -f $(EXTRA_PROGRAMS)

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

EXTRA_DIST = \
	alien.lwo	\
	penguin.lwo
