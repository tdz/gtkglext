## -*- Makefile -*-
## Makefile.am for gtkglext/gtk

common_includes = \
	-DG_LOG_DOMAIN=\"GtkGLExt\"	\
	-I$(top_srcdir)			\
	-I$(top_srcdir)/gdk		\
	-I$(top_builddir)/gtk		\
	-I../gdk			\
	$(GTKGLEXT_DEBUG_FLAGS)		\
	$(GTKGLEXT_DEP_CFLAGS)

INCLUDES = $(common_includes)

if PLATFORM_WIN32
no_undefined = -no-undefined
endif

if OS_WIN32
gtkglext_def = gtkglext.def
gtkglext_win32_symbols = -export-symbols $(gtkglext_def)

install-libtool-import-lib:
	$(INSTALL) .libs/libgtkglext-win32-@GTKGLEXT_API_VERSION@.dll.a $(DESTDIR)$(libdir)
uninstall-libtool-import-lib:
	-rm $(DESTDIR)$(libdir)/libgtkglext-win32-@GTKGLEXT_API_VERSION@.dll.a
else
install-libtool-import-lib:
uninstall-libtool-import-lib:
endif

if MS_LIB_AVAILABLE
noinst_DATA = gtkglext-win32-@GTKGLEXT_API_VERSION@.lib

gtkglext-win32-@GTKGLEXT_API_VERSION@.lib: libgtkglext-win32-@GTKGLEXT_API_VERSION@.la $(gtkglext_def)
	lib -name:libgtkglext-win32-@GTKGLEXT_API_VERSION@-@LT_CURRENT_MINUS_AGE@.dll -def:$(gtkglext_def) -out:$@

install-ms-lib:
	$(INSTALL) gtkglext-win32-@GTKGLEXT_API_VERSION@.lib $(DESTDIR)$(libdir)

uninstall-ms-lib:
	-rm $(DESTDIR)$(libdir)/gtkglext-win32-@GTKGLEXT_API_VERSION@.lib
else
install-ms-lib:
uninstall-ms-lib:
endif

# libtool stuff: set version and export symbols for resolving
# since automake doesn't support conditionalized libsomething_la_LDFLAGS
# we use the general approach here
LDFLAGS = \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) 	\
	-export-dynamic 					\
	-rpath $(libdir) 					\
	$(no_undefined)						\
	@LIBTOOL_EXPORT_OPTIONS@				\
	$(gtkglext_win32_symbols)				\
	$(top_builddir)/gdk/$(gdkglext_targetlib)		\
	$(GTKGLEXT_DEP_LIBS)

#
# setup source file variables
#

gtkglext_headers = \
	gtkgl.h			\
	gtkglwidget.h		\
	gtkglwidgetparam.h	\
	gtkgldebug.h		\
	gtkglprivate.h

gtkglext_c_sources = \
	gtkglwidget.c		\
	gtkglwidgetparam.c	\
	gtkgldebug.c

#
# setup GtkGLExt sources and their dependancies
#

gtkglextincludedir = $(includedir)/gtkglext-@GTKGLEXT_API_VERSION@/gtk
gtkglextinclude_HEADERS = $(gtkglext_headers)

lib_LTLIBRARIES = $(gtkglext_targetlib)

EXTRA_LTLIBRARIES = \
	libgtkglext-x11-@GTKGLEXT_API_MAJOR_VERSION@.@GTKGLEXT_API_MINOR_VERSION@.la	\
	libgtkglext-win32-@GTKGLEXT_API_MAJOR_VERSION@.@GTKGLEXT_API_MINOR_VERSION@.la

libgtkglext_x11_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_SOURCES = \
	$(gtkglext_c_sources)

libgtkglext_win32_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_SOURCES = \
	$(gtkglext_c_sources)
libgtkglext_win32_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_DEPENDENCIES = \
	$(gtkglext_def)

MAINTAINERCLEANFILES =
EXTRA_HEADERS =

#
# Extra rules
#

install-data-local: install-ms-lib install-libtool-import-lib

uninstall-local: uninstall-ms-lib uninstall-libtool-import-lib

.PHONY: files

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

EXTRA_DIST = 

