## -*- Makefile -*-
## Makefile.am for gtkglext

AUTOMAKE_OPTIONS = dist-bzip2 dist-zip

SUBDIRS = gdk gtk examples docs

EXTRA_DIST = \
	gdkglext.pc.in			\
	gtkglext.pc.in			\
	gdkglext-uninstalled.pc.in	\
	gtkglext-uninstalled.pc.in

## Copy .pc files to target-specific names
PCFILE_EXT = @gdktarget@-@GTKGLEXT_API_VERSION@
PCFILE_API_EXT = @GTKGLEXT_API_VERSION@

gdkglext-$(PCFILE_EXT).pc: gdkglext.pc gdkglext-$(PCFILE_EXT)-uninstalled.pc
	rm -f gdkglext-$(PCFILE_EXT).pc && \
	cp gdkglext.pc gdkglext-$(PCFILE_EXT).pc

gdkglext-$(PCFILE_API_EXT).pc: gdkglext.pc gdkglext-$(PCFILE_API_EXT)-uninstalled.pc
	rm -f gdkglext-$(PCFILE_API_EXT).pc && \
	cp gdkglext.pc gdkglext-$(PCFILE_API_EXT).pc

gtkglext-$(PCFILE_EXT).pc: gtkglext.pc gtkglext-$(PCFILE_EXT)-uninstalled.pc
	rm -f gtkglext-$(PCFILE_EXT).pc && \
	cp gtkglext.pc gtkglext-$(PCFILE_EXT).pc

gtkglext-$(PCFILE_API_EXT).pc: gtkglext.pc gtkglext-$(PCFILE_API_EXT)-uninstalled.pc
	rm -f gtkglext-$(PCFILE_API_EXT).pc && \
	cp gtkglext.pc gtkglext-$(PCFILE_API_EXT).pc

gdkglext-$(PCFILE_EXT)-uninstalled.pc: gdkglext-uninstalled.pc
	rm -f gdkglext-$(PCFILE_EXT)-uninstalled.pc && \
	cp gdkglext-uninstalled.pc gdkglext-$(PCFILE_EXT)-uninstalled.pc

gdkglext-$(PCFILE_API_EXT)-uninstalled.pc: gdkglext-uninstalled.pc gdkglext-$(PCFILE_EXT)-uninstalled.pc
	rm -f gdkglext-$(PCFILE_API_EXT)-uninstalled.pc && \
	cp gdkglext-uninstalled.pc gdkglext-$(PCFILE_API_EXT)-uninstalled.pc

gtkglext-$(PCFILE_EXT)-uninstalled.pc: gtkglext-uninstalled.pc
	rm -f gtkglext-$(PCFILE_EXT)-uninstalled.pc && \
	cp gtkglext-uninstalled.pc gtkglext-$(PCFILE_EXT)-uninstalled.pc

gtkglext-$(PCFILE_API_EXT)-uninstalled.pc: gtkglext-uninstalled.pc gtkglext-$(PCFILE_EXT)-uninstalled.pc
	rm -f gtkglext-$(PCFILE_API_EXT)-uninstalled.pc && \
	cp gtkglext-uninstalled.pc gtkglext-$(PCFILE_API_EXT)-uninstalled.pc

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = \
	gdkglext-$(PCFILE_EXT).pc	\
	gdkglext-$(PCFILE_API_EXT).pc	\
	gtkglext-$(PCFILE_EXT).pc	\
	gtkglext-$(PCFILE_API_EXT).pc
$(pkgconfig_DATA): config.status

DISTCLEANFILES = \
	gdkglext-$(PCFILE_EXT).pc			\
	gdkglext-$(PCFILE_API_EXT).pc			\
	gtkglext-$(PCFILE_EXT).pc			\
	gtkglext-$(PCFILE_API_EXT).pc			\
	gdkglext-$(PCFILE_EXT)-uninstalled.pc		\
	gdkglext-$(PCFILE_API_EXT)-uninstalled.pc	\
	gtkglext-$(PCFILE_EXT)-uninstalled.pc		\
	gtkglext-$(PCFILE_API_EXT)-uninstalled.pc

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

