#!/usr/bin/perl -w
#
# gen-gdkglwglext-h.pl
#
# Script for generating gdk/win32/gdkglwglext.h from SGI's OpenGL extension
# header.
#
# written by Naofumi Yasufuku <naofumi@users.sourceforge.net>
#

@input_headers = ("wglext.h", "wglext-extra.h");

#---------------
print <<EOF;
/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002-2003  Naofumi Yasufuku
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA.
 */

/*
 * This is a generated file.  Please modify `gen-gdkglwglext-h.pl'.
 */

#ifndef __GDK_GL_WGLEXT_H__
#define __GDK_GL_WGLEXT_H__

#include <glib.h>

#ifdef G_OS_WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#define __wglext_h_
#include <GL/gl.h>
#undef __wglext_h_

#include <gdk/gdkgldefs.h>
#include <gdk/gdkglquery.h>
#include <gdk/gdkglconfig.h>

#include <gdk/GL/wglext.h>
#include <gdk/GL/wglext-extra.h>

G_BEGIN_DECLS

EOF
#---------------

foreach $in (@input_headers) {
    open(IN, $in) || die "cannot open $in";

    while (<IN>) {
	if (/#ifndef\s+WGL_[a-zA-Z0-9]+_[a-z0-9_]+/) {
	    @line = split;
	    $_ = <IN>;
	    if (/#define\s+$line[1]/) {
		while (<IN>) {
		    if (/#ifdef\s+WGL_WGLEXT_PROTOTYPES/) {

			$extension = $line[1];

			# function prototypes
			@functions = ();
			while (<IN>) {
			    if (/#endif/) {
				last;
			    }
			    ($func) = /(wgl\w+)/;
			    push(@functions, $func);
			}

			# typedefs
			@typedefs = ();
			while (<IN>) {
			    if (/#endif/) {
				last;
			    }
			    chomp;
			    push(@typedefs, $_);
			}

			generate_code();

			last;

		    } elsif (/#endif/) {
			last;
		    }
		}
	    }
	}
    }

    close(IN);
}

#---------------
print <<EOF;
G_END_DECLS

#endif /* __GDK_GL_WGLEXT_H__ */
EOF
#---------------

# code generator
sub generate_code {
    print "/*\n";
    print " * $extension\n";
    print " */\n\n";

    $i = 0;
    foreach $func (@functions) {
	print "/* $func */\n";

	$type = $typedefs[$i++];
	$type =~ s/PFN\w+/GdkGLProc_$func/;
	print "$type\n";

	print "GdkGLProc    gdk_gl_get_$func (void);\n";

	$_ = $type;
	($args) = /\(.*\)\s+(\(.*\))/;
	$args =~ s/\(|\)//g;
	@args_list = split(/,\s+/, $args);
	foreach $a (@args_list) {
	    $_ = $a;
	    ($a) = /.*\s+\**(\w+)$/;
	    if (!$a) {
		$a = "";
	    }
	}
	$args = join(", ", @args_list);

	if ($args eq "") {
	    print "#define      gdk_gl_$func(proc) \\\n";
	    print "  ( ((GdkGLProc_$func) (proc)) () )\n";
	} else {
	    print "#define      gdk_gl_$func(proc, $args) \\\n";
	    print "  ( ((GdkGLProc_$func) (proc)) ($args) )\n";
	}

	print "\n";
    }

    print "/* proc struct */\n\n";

    print "typedef struct _GdkGL_$extension GdkGL_$extension;\n\n";

    print "struct _GdkGL_$extension\n";
    print "{\n";
    foreach $func (@functions) {
	print "  GdkGLProc_$func $func;\n";
    }
    print "};\n\n";

    print "GdkGL_$extension *gdk_gl_get_$extension (GdkGLConfig *glconfig);\n\n";
}
