## -*- Makefile -*-
## Makefile.am for gtkglext/gdk/GL

EXTRA_DIST = \
	README

gdkglextglincludedir = $(includedir)/gtkglext-@GTKGLEXT_API_VERSION@/gdk/GL

gdkglextglinclude_HEADERS = \
	glext.h		\
	glxext.h	\
	wglext.h

.PHONY: files

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

