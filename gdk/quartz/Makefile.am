## -*- Makefile -*-
## Makefile.am for gtkglext/gdk/quartz

AM_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"GdkGLExt\"	\
	-DGDK_GL_COMPILATION		\
	-DINSIDE_GDK_GL_QUARTZ		\
	-I$(top_srcdir)			\
	-I$(top_srcdir)/gdk		\
	-I$(top_builddir)/gdk		\
	$(GTKGLEXT_DEBUG_FLAGS)		\
	$(GDK_CFLAGS)			\
	$(GL_CFLAGS)			\
        $(GDKGLEXT_WIN_CFLAGS)		\
	-DG_DISABLE_DEPRECATED		\
	-DGDK_DISABLE_DEPRECATED	\
	-DGDK_PIXBUF_DISABLE_DEPRECATED

AM_LDFLAGS = $(GDK_LIBS) $(GL_LIBS) $(GDKGLEXT_WIN_LIBS)

gdkglext_quartz_public_h_sources = 
gdkglext_quartz_private_h_sources = \
	gdkglconfig-quartz.h	\
	gdkglcontext-quartz.h	\
	gdkglpixmap-quartz.h	\
	gdkglwindow-quartz.h	\
	gdkglprivate-quartz.h

gdkglext_quartz_c_sources = \
	gdkglquery-quartz.m	\
	gdkglconfig-quartz.m	\
	gdkglcontext-quartz.m	\
	gdkgldrawable-quartz.m	\
	gdkglpixmap-quartz.m	\
	gdkglwindow-quartz.m	

gdkglext_quartz_headers = \
	$(gdkglext_quartz_public_h_sources)

gdkglext_quartz_sources = \
	$(gdkglext_quartz_private_h_sources)	\
	$(gdkglext_quartz_c_sources)

gdkglextquartzincludedir = $(includedir)/gtkglext-@GTKGLEXT_API_VERSION@/gdk/quartz
gdkglextquartzinclude_HEADERS = $(gdkglext_quartz_headers)

noinst_LTLIBRARIES = libgdkglext-quartz.la

libgdkglext_quartz_la_SOURCES = $(gdkglext_quartz_sources)
