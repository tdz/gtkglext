## -*- Makefile -*-
## Makefile.am for gtkglext

AUTOMAKE_OPTIONS = 1.6 dist-bzip2 dist-zip

SUBDIRS = gdk gtk examples docs m4macros

EXTRA_DIST = \
	README.win32			\
	gdkglext.pc.in			\
	gtkglext.pc.in			\
	gdkglext-uninstalled.pc.in	\
	gtkglext-uninstalled.pc.in	\
	gtkglext.spec.in		\
	gtkglext.spec			\
	gtkglext.nsi.in			\
	gtkglext.nsi
	setup-gtkglext.sh

## Copy .pc files to target-specific names
GDK_TARGET = @gdktarget@
API_VER = @GTKGLEXT_API_VERSION@

gdkglext-$(GDK_TARGET)-$(API_VER).pc: gdkglext.pc gdkglext-$(GDK_TARGET)-$(API_VER)-uninstalled.pc
	rm -f $@ && cp gdkglext.pc $@

gdkglext-$(API_VER).pc: gdkglext.pc gdkglext-$(API_VER)-uninstalled.pc
	rm -f $@ && cp gdkglext.pc $@

gtkglext-$(GDK_TARGET)-$(API_VER).pc: gtkglext.pc gtkglext-$(GDK_TARGET)-$(API_VER)-uninstalled.pc
	rm -f $@ && cp gtkglext.pc $@

gtkglext-$(API_VER).pc: gtkglext.pc gtkglext-$(API_VER)-uninstalled.pc
	rm -f $@ && cp gtkglext.pc $@

gdkglext-$(GDK_TARGET)-$(API_VER)-uninstalled.pc: gdkglext-uninstalled.pc
	rm -f $@ && cp gdkglext-uninstalled.pc $@

gdkglext-$(API_VER)-uninstalled.pc: gdkglext-uninstalled.pc gdkglext-$(GDK_TARGET)-$(API_VER)-uninstalled.pc
	rm -f $@ && cp gdkglext-uninstalled.pc $@

gtkglext-$(GDK_TARGET)-$(API_VER)-uninstalled.pc: gtkglext-uninstalled.pc
	rm -f $@ && cp gtkglext-uninstalled.pc $@

gtkglext-$(API_VER)-uninstalled.pc: gtkglext-uninstalled.pc gtkglext-$(GDK_TARGET)-$(API_VER)-uninstalled.pc
	rm -f $@ && cp gtkglext-uninstalled.pc $@

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = \
	gdkglext-$(GDK_TARGET)-$(API_VER).pc	\
	gdkglext-$(API_VER).pc			\
	gtkglext-$(GDK_TARGET)-$(API_VER).pc	\
	gtkglext-$(API_VER).pc
$(pkgconfig_DATA): config.status

DISTCLEANFILES = \
	gdkglext-$(GDK_TARGET)-$(API_VER).pc			\
	gdkglext-$(API_VER).pc					\
	gtkglext-$(GDK_TARGET)-$(API_VER).pc			\
	gtkglext-$(API_VER).pc					\
	gdkglext-$(GDK_TARGET)-$(API_VER)-uninstalled.pc	\
	gdkglext-$(API_VER)-uninstalled.pc			\
	gtkglext-$(GDK_TARGET)-$(API_VER)-uninstalled.pc	\
	gtkglext-$(API_VER)-uninstalled.pc

.PHONY: examples files

examples: all
	(cd $(top_builddir)/examples && $(MAKE) $(MFLAGS) examples)

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done
	@for subdir in $(SUBDIRS); do \
	  files=`cd $$subdir; $(MAKE) files | grep -v "make\[[1-9]\]"`; \
	  for file in $$files; do \
	    echo $$subdir/$$file; \
	  done; \
	done

