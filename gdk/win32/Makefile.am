## -*- Makefile -*-
## Makefile.am for gtkglext/gdk/win32

libgdkglextincludedir = $(includedir)/gtkglext-$(GTKGLEXT_API_VERSION)/gdk

INCLUDES = \
	-DG_LOG_DOMAIN=\"GdkGLExt\"	\
	-I$(top_srcdir)			\
	-I$(top_srcdir)/gdk		\
	-I$(top_builddir)/gdk		\
	$(GTKGLEXT_DEBUG_FLAGS)		\
	$(GDKGLEXT_DEP_CFLAGS)		\
	-DGDK_GL_COMPILATION

LDADDS = \
	$(GDKGLEXT_DEP_LIBS)

noinst_LTLIBRARIES = libgdkglext-win32.la

libgdkglext_win32_la_SOURCES = \
	gdkgl-win32.c		\
	gdkglconfig-win32.h	\
	gdkglconfig-win32.c	\
	gdkglcontext-win32.h	\
	gdkglcontext-win32.c	\
	gdkgldrawable-win32.c	\
	gdkglpixmap-win32.h	\
	gdkglpixmap-win32.c	\
	gdkglwindow-win32.h	\
	gdkglwindow-win32.c	\
	gdkglfont-win32.c	\
	gdkglprivate-win32.h	\
	gdkinternal-win32.h

libgdkglextinclude_HEADERS = \
	gdkglwin32.h

.PHONY: files

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

EXTRA_DIST = 

