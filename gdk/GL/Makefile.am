## -*- Makefile -*-
## Makefile.am for gtkglext/gdk/GL

EXTRA_DIST = \
	README			\
	list-ext.pl		\
	gen-gdkglglext-c.pl	\
	gen-gdkglglext-h.pl	\
	gen-gdkglglxext-c.pl	\
	gen-gdkglglxext-h.pl	\
	gen-gdkglwglext-c.pl	\
	gen-gdkglwglext-h.pl

gdkglext_gl_public_h_sources = \
	glext.h		\
	glxext.h	\
	wglext.h	\
	glext-extra.h	\
	glxext-extra.h	\
	wglext-extra.h

gdkglextglincludedir = $(includedir)/gtkglext-@GTKGLEXT_API_VERSION@/gdk/GL
gdkglextglinclude_HEADERS = $(gdkglext_gl_public_h_sources)

