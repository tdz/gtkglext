## -*- Makefile -*-
## Makefile.am for gtkglext/gdk

SUBDIRS=$(gdktarget)
DIST_SUBDIRS=x11 win32

if PLATFORM_WIN32
no_undefined = -no-undefined
endif

if OS_WIN32
gdkglext_def = gdkglext.def
gdkglext_win32_symbols = -export-symbols $(gdkglext_def)

install-libtool-import-lib:
	$(INSTALL) .libs/libgdkglext-win32-@GTKGLEXT_API_VERSION@.dll.a $(DESTDIR)$(libdir)
uninstall-libtool-import-lib:
	-rm $(DESTDIR)$(libdir)/libgdkglext-win32-@GTKGLEXT_API_VERSION@.dll.a
else
install-libtool-import-lib:
uninstall-libtool-import-lib:
endif

if MS_LIB_AVAILABLE
noinst_DATA = gdkglext-win32-@GTKGLEXT_API_VERSION@.lib

gdkglext-win32-@GTKGLEXT_API_VERSION@.lib: libgdkglext-win32-@GTKGLEXT_API_VERSION@.la $(gdkglext_def)
	lib -name:libgdkglext-win32-@GTKGLEXT_API_VERSION@-@LT_CURRENT_MINUS_AGE@.dll -def:$(gdkglext_def) -out:$@

install-ms-lib:
	$(INSTALL) gdkglext-win32-@GTKGLEXT_API_VERSION@.lib $(DESTDIR)$(libdir)

uninstall-ms-lib:
	-rm $(DESTDIR)$(libdir)/gdkglext-win32-@GTKGLEXT_API_VERSION@.lib
else
install-ms-lib:
uninstall-ms-lib:
endif

common_includes = \
	-DG_LOG_DOMAIN=\"GdkGLExt\"	\
	-I$(top_srcdir)			\
	-I$(top_builddir)/gdk		\
	$(GTKGLEXT_DEBUG_FLAGS)		\
	$(GDKGLEXT_DEP_CFLAGS)		\
	-DGDK_GL_COMPILATION		\
	-DG_DISABLE_DEPRECATED		\
	-DGDK_DISABLE_DEPRECATED

common_ldflags = \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) 	\
	-export-dynamic 					\
	-rpath $(libdir) 					\
	$(no_undefined)						\
	@LIBTOOL_EXPORT_OPTIONS@				\
	$(gdkglext_win32_symbols)

common_libadd = \
	$(GDKGLEXT_DEP_LIBS)

#
# setup source file variables
#

gdkglext_headers = \
	gdkgl.h			\
	gdkgltokens.h		\
	gdkgltypes.h		\
	gdkglquery.h		\
	gdkglconfig.h		\
	gdkglcontext.h		\
	gdkgldrawable.h		\
	gdkglpixmap.h		\
	gdkglwindow.h		\
	gdkglfont.h		\
	gdkgldebug.h		\
	gdkglprivate.h

gdkglext_c_sources = \
	gdkglconfig.c		\
	gdkglcontext.c		\
	gdkgldrawable.c		\
	gdkglpixmap.c		\
	gdkglwindow.c		\
	gdkgldebug.c

#
# setup GdkGLExt sources and their dependancies
#

gdkglextincludedir = $(includedir)/gtkglext-@GTKGLEXT_API_VERSION@/gdk
gdkglextinclude_HEADERS = $(gdkglext_headers)

INCLUDES = $(common_includes)

lib_LTLIBRARIES = $(gdkglext_targetlib)

EXTRA_LTLIBRARIES = \
	libgdkglext-x11-@GTKGLEXT_API_MAJOR_VERSION@.@GTKGLEXT_API_MINOR_VERSION@.la	\
	libgdkglext-win32-@GTKGLEXT_API_MAJOR_VERSION@.@GTKGLEXT_API_MINOR_VERSION@.la

libgdkglext_x11_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_SOURCES = \
	$(gdkglext_c_sources)
libgdkglext_x11_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_LDFLAGS = \
	$(common_ldflags)
libgdkglext_x11_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_LIBADD = \
	x11/libgdkglext-x11.la	\
	$(common_libadd)

libgdkglext_win32_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_SOURCES = \
	$(gdkglext_c_sources)
libgdkglext_win32_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_LDFLAGS = \
	$(common_ldflags)
libgdkglext_win32_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_LIBADD = \
	win32/libgdkglext-win32.la	\
	$(common_libadd)
libgdkglext_win32_@GTKGLEXT_API_MAJOR_VERSION@_@GTKGLEXT_API_MINOR_VERSION@_la_DEPENDENCIES = \
	$(gdkglext_def)

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
	@for subdir in $(DIST_SUBDIRS); do \
	  files=`cd $$subdir; $(MAKE) files | grep -v "make\[[1-9]\]"`; \
	  for file in $$files; do \
	    echo $$subdir/$$file; \
	  done; \
	done

EXTRA_DIST = \
	gdkglext.def
