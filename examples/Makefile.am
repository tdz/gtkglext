## -*- Makefile -*-
## Makefile.am for gtkglext/examples

INCLUDES = \
	-I$(top_srcdir) 	\
	-I$(top_builddir)	\
	$(GTKGLEXT_DEBUG_FLAGS)	\
	$(GTKGLEXT_DEP_CFLAGS)

DEPS = \
	$(top_builddir)/gtk/$(gtkglext_targetlib)	\
	$(top_builddir)/gdk/$(gdkglext_targetlib)

LDADDS = \
	$(top_builddir)/gtk/$(gtkglext_targetlib)	\
	$(top_builddir)/gdk/$(gdkglext_targetlib)	\
	$(GTKGLEXT_DEP_LIBS)

EXTRA_PROGRAMS = \
	low-level	\
	simple		\
	pixmap		\
	font

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


.PHONY: examples clean distclean files

examples: $(EXTRA_PROGRAMS)

clean:
	-rm -f $(EXTRA_PROGRAMS)

distclean:
	-rm -f $(EXTRA_PROGRAMS)

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

