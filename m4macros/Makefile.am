## -*- Makefile -*-
## Makefile.am for gtkglext/m4macros

EXTRA_DIST = \
	gtkglext.m4

API_VER = @GTKGLEXT_API_VERSION@

gtkglext-$(API_VER).m4: gtkglext.m4
	rm -f $@ && cp gtkglext.m4 $@

m4datadir = $(datadir)/aclocal
m4data_DATA = gtkglext-$(API_VER).m4

$(m4data_DATA): ../config.status

DISTCLEANFILES = gtkglext-$(API_VER).m4

.PHONY: files

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

