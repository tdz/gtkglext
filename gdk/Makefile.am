## -*- Makefile -*-
## Makefile.am for gtkglext/gdk

SUBDIRS = $(gdktarget) glext
DIST_SUBDIRS = x11 win32

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
	-DGDK_DISABLE_DEPRECATED	\
	-DGDK_PIXBUF_DISABLE_DEPRECATED

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

gdkglext_public_h_sources = \
	gdkgl.h			\
	gdkgldefs.h		\
	gdkglversion.h		\
	gdkgltokens.h		\
	gdkgltypes.h		\
	gdkglquery.h		\
	gdkglconfig.h		\
	gdkglcontext.h		\
	gdkgldrawable.h		\
	gdkglpixmap.h		\
	gdkglwindow.h		\
	gdkglfont.h

gdkglext_headers = \
	$(gdkglext_public_h_sources)	\
	gdkglenumtypes.h		\
	gdkgldebug.h			\
	gdkglprivate.h

gdkglext_c_sources = \
	gdkglversion.c		\
	gdkglquery.c		\
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
	libgdkglext-x11-@API_MJ_LT@.@API_MI_LT@.la	\
	libgdkglext-win32-@API_MJ_LT@.@API_MI_LT@.la

libgdkglext_x11_@API_MJ_LT@_@API_MI_LT@_la_SOURCES = \
	$(gdkglext_c_sources)	\
	gdkglenumtypes.c
libgdkglext_x11_@API_MJ_LT@_@API_MI_LT@_la_LDFLAGS = \
	$(common_ldflags)
libgdkglext_x11_@API_MJ_LT@_@API_MI_LT@_la_LIBADD = \
	x11/libgdkglext-x11.la	\
	$(common_libadd)

libgdkglext_win32_@API_MJ_LT@_@API_MI_LT@_la_SOURCES = \
	$(gdkglext_c_sources)	\
	gdkglenumtypes.c
libgdkglext_win32_@API_MJ_LT@_@API_MI_LT@_la_LDFLAGS = \
	$(common_ldflags)
libgdkglext_win32_@API_MJ_LT@_@API_MI_LT@_la_LIBADD = \
	win32/libgdkglext-win32.la	\
	$(common_libadd)
libgdkglext_win32_@API_MJ_LT@_@API_MI_LT@_la_DEPENDENCIES = \
	$(gdkglext_def)

MAINTAINERCLEANFILES = gdkglenumtypes.h stamp-gdkglenumtypes.h
EXTRA_HEADERS =

BUILT_SOURCES = @REBUILD@ gdkglenumtypes.h

# Generate built header without using automake BUILT_SOURCES
$(libgdkglext_x11_@API_MJ_LT@_@API_MI_LT@_la_OBJECTS) $(libgdkglext_win32_@API_MJ_LT@_@API_MI_LT@_la_OBJECTS): gdkglenumtypes.h

$(srcdir)/gdkglenumtypes.h: stamp-gdkglenumtypes.h
	@true
stamp-gdkglenumtypes.h: @REBUILD@ $(gdkglext_public_h_sources) Makefile
	( cd $(srcdir) && glib-mkenums \
			--fhead "#ifndef __GDK_GL_ENUM_TYPES_H__\n#define __GDK_GL_ENUM_TYPES_H__\n\n#include <glib-object.h>\n\nG_BEGIN_DECLS\n" \
			--fprod "/* enumerations from \"@filename@\" */\n" \
			--vhead "GType @enum_name@_get_type (void);\n#define GDK_TYPE_@ENUMSHORT@ (@enum_name@_get_type())\n" \
			--ftail "G_END_DECLS\n\n#endif /* __GDK_GL_ENUM_TYPES_H__ */" \
		$(gdkglext_public_h_sources) ) >> xgen-geth \
	&& (cmp -s xgen-geth $(srcdir)/gdkglenumtypes.h || cp xgen-geth $(srcdir)/gdkglenumtypes.h ) \
	&& rm -f xgen-geth \
	&& echo timestamp > $(@F)
$(srcdir)/gdkglenumtypes.c: @REBUILD@ $(gdkglext_public_h_sources) Makefile
	( cd $(srcdir) && glib-mkenums \
			--fhead "#define GDK_GL_ENABLE_BROKEN\n#include \"gdkgl.h\"" \
			--fprod "\n/* enumerations from \"@filename@\" */" \
			--vhead "GType\n@enum_name@_get_type (void)\n{\n  static GType etype = 0;\n  if (etype == 0) {\n    static const G@Type@Value values[] = {" \
			--vprod "      { @VALUENAME@, \"@VALUENAME@\", \"@valuenick@\" }," \
			--vtail "      { 0, NULL, NULL }\n    };\n    etype = g_@type@_register_static (\"@EnumName@\", values);\n  }\n  return etype;\n}\n" \
		$(gdkglext_public_h_sources) ) > xgen-getc \
	&& cp xgen-getc $(srcdir)/gdkglenumtypes.c  \
	&& rm -f xgen-getc

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
	gdkglversion.h.in	\
	gdkglext.def
