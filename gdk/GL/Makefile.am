## -*- Makefile -*-
## Makefile.am for gtkglext/gdk/GL

EXTRA_DIST = \
	README

includedir = $(prefix)/include/gtkglext-$(GTKGLEXT_API_VERSION)/gdk/GL

nobase_include_HEADERS = \
	glext.h		\
	glxext.h	\
	wglext.h

.PHONY: files

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

