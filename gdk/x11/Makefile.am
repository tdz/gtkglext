## -*- Makefile -*-
## Makefile.am for gtkglext/gdk/x11

libgdkglextincludedir = $(includedir)/gtkglext-$(GTKGLEXT_API_VERSION)/gdk

INCLUDES = \
	-DG_LOG_DOMAIN=\"GdkGLExt\"	\
	-DINSIDE_GDK_GL_X11		\
	-I$(top_srcdir)			\
	-I$(top_srcdir)/gdk		\
	-I$(top_builddir)/gdk		\
	$(GTKGLEXT_DEBUG_FLAGS)		\
	$(GDKGLEXT_DEP_CFLAGS)		\
	-DGDK_GL_COMPILATION		\
	-DG_DISABLE_DEPRECATED		\
	-DGDK_DISABLE_DEPRECATED	\
	-DGDK_PIXBUF_DISABLE_DEPRECATED

LDADDS = \
	$(GDKGLEXT_DEP_LIBS)

noinst_LTLIBRARIES = libgdkglext-x11.la

libgdkglext_x11_la_SOURCES = \
	gdkglquery-x11.c	\
	gdkglconfig-x11.h	\
	gdkglconfig-x11.c	\
	gdkglcontext-x11.h	\
	gdkglcontext-x11.c	\
	gdkgldrawable-x11.c	\
	gdkglpixmap-x11.h	\
	gdkglpixmap-x11.c	\
	gdkglwindow-x11.h	\
	gdkglwindow-x11.c	\
	gdkglfont-x11.c		\
	gdkglprivate-x11.h

libgdkglextinclude_HEADERS = \
	gdkglx.h

.PHONY: files

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

EXTRA_DIST = 

