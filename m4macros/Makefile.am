## -*- Makefile -*-
## Makefile.am for gtkglext/m4macros

EXTRA_DIST = \
	gtkglext.m4

M4MACRO_EXT = @GTKGLEXT_API_VERSION@

gtkglext-$(M4MACRO_EXT).m4: gtkglext.m4
	rm -f $@ && cp gtkglext.m4 $@

m4datadir = $(datadir)/aclocal
m4data_DATA = \
	gtkglext-$(M4MACRO_EXT).m4
$(m4data_DATA): ../config.status

DISTCLEANFILES = \
	gtkglext-$(M4MACRO_EXT).m4

.PHONY: files

files:
	@files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
	  echo $$p; \
	done

