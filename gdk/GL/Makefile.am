## -*- Makefile -*-
## Makefile.am for gtkglext/gdk/GL

EXTRA_DIST = \
	README

gdkglext_gl_public_h_sources = \
	glext.h		\
	glxext.h	\
	wglext.h

gdkglextglincludedir = $(includedir)/gtkglext-@GTKGLEXT_API_VERSION@/gdk/GL
gdkglextglinclude_HEADERS = $(gdkglext_gl_public_h_sources)

.PHONY: files

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

