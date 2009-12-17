#
# Making releases:
#   gtkglext_micro_version += 1;
#   gtkglext_interface_age += 1;
#   gtkglext_binary_age += 1;
# if any functions have been added, set gtkglext_interface_age to 0.
# if backwards compatibility has been broken,
# set gtkglext_binary_age and gtkglext_interface_age to 0.
#
m4_define([gtkglext_major_version], [1])
m4_define([gtkglext_minor_version], [2])
m4_define([gtkglext_micro_version], [0])
m4_define([gtkglext_interface_age], [0])
m4_define([gtkglext_binary_age],
          [m4_eval(100 * gtkglext_minor_version + gtkglext_micro_version)])
m4_define([gtkglext_version],
          [gtkglext_major_version.gtkglext_minor_version.gtkglext_micro_version])

# This is the X.Y used in -lgtkglext-FOO-X.Y
m4_define([gtkglext_api_major_version], [1])
m4_define([gtkglext_api_minor_version], [0])
m4_define([gtkglext_api_version],
          [gtkglext_api_major_version.gtkglext_api_minor_version])

# libtool version related macros
m4_define([gtkglext_lt_release],
          [gtkglext_major_version.gtkglext_minor_version])
m4_define([gtkglext_lt_current],
          [m4_eval(100 * gtkglext_minor_version + gtkglext_micro_version - gtkglext_interface_age)])
m4_define([gtkglext_lt_revision],
          [gtkglext_interface_age])
m4_define([gtkglext_lt_age],
          [m4_eval(gtkglext_binary_age - gtkglext_interface_age)])
m4_define([gtkglext_lt_current_minus_age],
          [m4_eval(gtkglext_lt_current - gtkglext_lt_age)])

# if the minor version number is odd, then we want debugging.  Otherwise
# we only want minimal debugging support.
m4_define([gtkglext_debug_default],
          [m4_if(m4_eval(gtkglext_minor_version % 2), [1], [yes], [minimum])])dnl

# Process this file with autoconf to produce a configure script.
AC_INIT([gtkglext], [gtkglext_version],
        [gtkglext-list@gnome.org])

AC_PREREQ([2.58])

AC_CONFIG_SRCDIR([gdk/gdkgl.h])
AC_CONFIG_MACRO_DIR([m4macros])

# Save this value here, since automake will set cflags later
cflags_set=${CFLAGS+set}

# Initialize automake stuff
AM_INIT_AUTOMAKE([1.7 no-define dist-bzip2 dist-zip])

# Specify a configuration file
AM_CONFIG_HEADER([config.h])

AC_CANONICAL_HOST

# GtkGLExt version
GTKGLEXT_MAJOR_VERSION=gtkglext_major_version
GTKGLEXT_MINOR_VERSION=gtkglext_minor_version
GTKGLEXT_MICRO_VERSION=gtkglext_micro_version
GTKGLEXT_INTERFACE_AGE=gtkglext_interface_age
GTKGLEXT_BINARY_AGE=gtkglext_binary_age
GTKGLEXT_VERSION=gtkglext_version
# This is the X.Y used in -lgtkglext-FOO-X.Y
GTKGLEXT_API_MAJOR_VERSION=gtkglext_api_major_version
GTKGLEXT_API_MINOR_VERSION=gtkglext_api_minor_version
GTKGLEXT_API_VERSION=gtkglext_api_version
API_MJ=$GTKGLEXT_API_MAJOR_VERSION
API_MI=$GTKGLEXT_API_MINOR_VERSION
AC_SUBST([GTKGLEXT_MAJOR_VERSION])
AC_SUBST([GTKGLEXT_MINOR_VERSION])
AC_SUBST([GTKGLEXT_MICRO_VERSION])
AC_SUBST([GTKGLEXT_INTERFACE_AGE])
AC_SUBST([GTKGLEXT_BINARY_AGE])
AC_SUBST([GTKGLEXT_VERSION])
AC_SUBST([GTKGLEXT_API_MAJOR_VERSION])
AC_SUBST([GTKGLEXT_API_MINOR_VERSION])
AC_SUBST([GTKGLEXT_API_VERSION])
AC_SUBST([API_MJ])
AC_SUBST([API_MI])

# libtool versioning
LT_RELEASE=gtkglext_lt_release
LT_CURRENT=gtkglext_lt_current
LT_REVISION=gtkglext_lt_revision
LT_AGE=gtkglext_lt_age
LT_CURRENT_MINUS_AGE=gtkglext_lt_current_minus_age
AC_SUBST([LT_RELEASE])
AC_SUBST([LT_CURRENT])
AC_SUBST([LT_REVISION])
AC_SUBST([LT_AGE])
AC_SUBST([LT_CURRENT_MINUS_AGE])

dnl Initialize libtool
AM_PROG_CC_C_O
AC_PROG_CPP
#AM_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

AC_CHECK_PROG([ms_librarian], [lib.exe], [yes], [no])

platform_win32=no
AC_MSG_CHECKING([for some Win32 platform])
case "$host_os" in
  *mingw*|*cygwin*)
    platform_win32=yes
    ;;
  *)
    ;;
esac
AC_MSG_RESULT([$platform_win32])
AM_CONDITIONAL([PLATFORM_WIN32], [test "x$platform_win32" = "xyes"])

os_win32=no
MATH_LIB=-lm
AC_MSG_CHECKING([for native Win32])
case "$host_os" in
  *mingw*)
    os_win32=yes
    MATH_LIB=
    ;;
  *)
    ;;
esac
AC_MSG_RESULT([$os_win32])
AM_CONDITIONAL([OS_WIN32], [test "x$os_win32" = "xyes"])
AC_SUBST([MATH_LIB])

AM_CONDITIONAL([MS_LIB_AVAILABLE], [test "x$ms_librarian" = "xyes"])

if test "x$platform_win32" = "xyes"; then
  gdktarget=win32
else
  gdktarget=x11
fi

AC_ARG_WITH([gdktarget],
            [AS_HELP_STRING([--with-gdktarget=@<:@x11/win32@:>@],
                            [select GDK target])],
            [gdktarget=$with_gdktarget])

AC_SUBST([gdktarget])
case $gdktarget in
  x11|win32) ;;
  *) AC_MSG_ERROR([Invalid target for GDK: use x11 or win32.]);;
esac

gdkglext_targetlib=libgdkglext-$gdktarget-$GTKGLEXT_API_VERSION.la
gtkglext_targetlib=libgtkglext-$gdktarget-$GTKGLEXT_API_VERSION.la

AC_SUBST([gdkglext_targetlib])
AC_SUBST([gtkglext_targetlib])

# Checks for programs.
AC_PROG_LN_S

# Debug option
AC_ARG_ENABLE([debug],
              AS_HELP_STRING([--enable-debug=@<:@no/minimum/yes@:>@],
                             [turn on debugging @<:@default=gtkglext_debug_default@:>@]), ,
              [enable_debug=gtkglext_debug_default])

changequote(,)dnl
if test "x$enable_debug" = "xyes"; then
  if test x$cflags_set != xset ; then
      case " $CFLAGS " in
      *[[\ \	]]-g[[\ \	]]*) ;;
      *) CFLAGS="$CFLAGS -g" ;;
      esac
  fi
  GTKGLEXT_DEBUG_FLAGS="-DG_ENABLE_DEBUG"
else
  if test "x$enable_debug" = "xno"; then
    GTKGLEXT_DEBUG_FLAGS="-DG_DISABLE_ASSERT -DG_DISABLE_CHECKS -DG_DISABLE_CAST_CHECKS"
  else
    GTKGLEXT_DEBUG_FLAGS="-DG_DISABLE_CAST_CHECKS"
  fi
fi
changequote([,])dnl

AC_SUBST([GTKGLEXT_DEBUG_FLAGS])

# Platform-specific compiler options
case "$host_os" in
  irix5* | irix6*)
    # Suppress linker warnings
    if test "x$with_gnu_ld" = "xno"; then
      LDFLAGS="$LDFLAGS -Wl,-woff,84 -Wl,-woff,127"
    fi
    ;;
  *)
    ;;
esac

# Ensure MSVC-compatible struct packing convention is used when
# compiling for Win32 with gcc.
# What flag to depends on gcc version: gcc3 uses "-mms-bitfields", while
# gcc2 uses "-fnative-struct".
if test "x$os_win32" = "xyes"; then
  if test "x$GCC" = "xyes"; then
    msnative_struct=''
    AC_MSG_CHECKING([how to get MSVC-compatible struct packing])
    if test -z "$ac_cv_prog_CC"; then
      our_gcc="$CC"
    else
      our_gcc="$ac_cv_prog_CC"
    fi
    case `$our_gcc --version | sed -e 's,\..*,.,' -e q` in
      2.)
	if $our_gcc -v --help 2>/dev/null | grep fnative-struct >/dev/null; then
	  msnative_struct='-fnative-struct'
	fi
	;;
      *)
	if $our_gcc -v --help 2>/dev/null | grep ms-bitfields >/dev/null; then
	  msnative_struct='-mms-bitfields'
	fi
	;;
    esac
    if test x"$msnative_struct" = x ; then
      AC_MSG_RESULT([no way])
      AC_MSG_WARN([produced libraries might be incompatible with MSVC-compiled code])
    else
      CFLAGS="$CFLAGS $msnative_struct"
      AC_MSG_RESULT([${msnative_struct}])
    fi
  fi
fi

if test "x$os_win32" != "xyes"; then
    # libtool option to control which symbols are exported
    # right now, symbols starting with _ are not exported
    LIBTOOL_EXPORT_OPTIONS='-export-symbols-regex "^[[^_]].*"'
else
    # We currently use .def files on Windows
    LIBTOOL_EXPORT_OPTIONS=
fi
AC_SUBST([LIBTOOL_EXPORT_OPTIONS])

# define a MAINT-like variable REBUILD which is set if Perl
# and awk are found, so autogenerated sources can be rebuilt

AC_ARG_ENABLE([rebuilds],
              [AS_HELP_STRING([--disable-rebuilds],
                              [disable all source autogeneration rules])], ,
              [enable_rebuilds=yes])

AC_PATH_PROGS([PERL], [perl5 perl])

REBUILD=\#
if test "x$enable_rebuilds" = "xyes" && \
     test -n "$PERL" && \
     $PERL -e 'exit !($] >= 5.002)' > /dev/null 2>&1 ; then
  REBUILD=
fi
AC_SUBST([REBUILD])

# Checks for headers and libraries.

AC_CHECK_HEADERS([inttypes.h stdlib.h string.h])

AC_PATH_XTRA
save_CPPFLAGS="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS $X_CFLAGS"
save_LIBS="$LIBS"
LIBS="$LIBS $X_LIBS -lXext -lX11 $X_EXTRA_LIBS"
AC_CHECK_HEADERS([X11/Xmu/StdCmap.h Xmu/StdCmap.h], , ,
                 [#include <X11/Xlib.h>
                  #include <X11/Xutil.h>])
AC_CHECK_LIB([Xmu], [XmuLookupStandardColormap], , ,
             [-lXt $X_PRE_LIBS])
CPPFLAGS="$save_CPPFLAGS"
LIBS="$save_LIBS"

PKG_CHECK_MODULES([GTK], [gtk+-2.0 >= 2.4], ,
                  [AS_IF([test -z "${GTK_LIBS+x}"],
                         [AC_MSG_FAILURE([GTK+ 2.4 or newer is required.])])])
PKG_CHECK_MODULES([GDK], [gdk-2.0], ,
                  [AS_IF([test -z "${GDK_LIBS+x}"],
                         [AC_MSG_FAILURE([GDK is required.])])])
PKG_CHECK_MODULES([PANGOX], [pangox], ,
                  [AS_IF([test -z "${PANGOX_LIBS+x}"],
                         [AC_MSG_FAILURE([Pango X font support is required.])])])
PKG_CHECK_MODULES([PANGOFT2], [pangoft2], ,
                  [AS_IF([test -z "${PANGOFT2_LIBS+x}"],
                         [AC_MSG_WARN([Pango Freetype support is required to build some of the examples.])])])

# Checks for library functions.
save_LIBS="$LIBS"
LIBS="$LIBS $MATH_LIB"

AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset sqrt strchr strrchr strstr])

LIBS="$save_LIBS"


##################################################
# Checks for GDK multihead support
##################################################

GDKGLEXT_MULTIHEAD_SUPPORT=no

save_CPPFLAGS="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS $GDK_CFLAGS"
save_LIBS="$LIBS"
LIBS="$LIBS $GDK_LIBS"

AC_CHECK_HEADERS([gdk/gdkdisplay.h gdk/gdkscreen.h],
                 [GDKGLEXT_MULTIHEAD_SUPPORT=yes],
                 [GDKGLEXT_MULTIHEAD_SUPPORT=no])

if test "x$GDKGLEXT_MULTIHEAD_SUPPORT" = "xyes"; then
  AC_MSG_CHECKING([for gdk_display_get_default in GDK library])
  AC_TRY_LINK([#include <gdk/gdk.h>],
              [gdk_display_get_default();],
              [GDKGLEXT_MULTIHEAD_SUPPORT=yes],
              [GDKGLEXT_MULTIHEAD_SUPPORT=no])
  AC_MSG_RESULT([$GDKGLEXT_MULTIHEAD_SUPPORT])
fi

CPPFLAGS="$save_CPPFLAGS"
LIBS="$save_LIBS"

if test "x$GDKGLEXT_MULTIHEAD_SUPPORT" = "xyes"; then
  AC_MSG_NOTICE([GDK supports multihead])
else
  AC_MSG_NOTICE([GDK doesn't support multihead])
fi

AC_SUBST([GDKGLEXT_MULTIHEAD_SUPPORT])
AM_CONDITIONAL([MULTIHEAD_SUPPORT],
               [test "x$GDKGLEXT_MULTIHEAD_SUPPORT" = "xyes"])


##################################################
# Checks for Window System
##################################################

WINDOWING_CFLAGS=""
WINDOWING_LIBS=""

GDKGLEXT_WIN_CFLAGS=""
GDKGLEXT_WIN_LIBS=""

if test "x$gdktarget" = "xx11"; then
  if test "x$no_x" = "xyes" ; then
    AC_MSG_ERROR([X development libraries not found])
  fi

  XMU_LIBS=""
  if test "x$ac_cv_lib_Xmu_XmuLookupStandardColormap" = "xyes" ; then
    XMU_LIBS="-lXmu -lXt $X_PRE_LIBS"
  fi

  WINDOWING_CFLAGS="$X_CFLAGS"
  WINDOWING_LIBS="$X_LIBS $XMU_LIBS -lXext -lX11 $X_EXTRA_LIBS"

  GDKGLEXT_WIN_CFLAGS="$X_CFLAGS"
  GDKGLEXT_WIN_LIBS="$X_LIBS $XMU_LIBS"
fi
AM_CONDITIONAL([USE_X11], [test x$gdktarget = xx11])

if test "x$gdktarget" = "xwin32"; then
  WINDOWING_LIBS="-lgdi32 -luser32 -lkernel32"
  GDKGLEXT_WIN_LIBS="-lgdi32 -luser32 -lkernel32"
  AM_CONDITIONAL([USE_WIN32], [true])
else
  AM_CONDITIONAL([USE_WIN32], [false])
fi

AC_SUBST([WINDOWING_CFLAGS])
AC_SUBST([WINDOWING_LIBS])

AC_SUBST([GDKGLEXT_WIN_CFLAGS])
AC_SUBST([GDKGLEXT_WIN_LIBS])


##################################################
# Checks for OpenGL
##################################################

GL_CFLAGS=""
GL_LDFLAGS=""
GL_LIBS=""

AC_ARG_WITH([gl-prefix],
            [AS_HELP_STRING([--with-gl-prefix=DIR],
                            [OpenGL (Mesa) is installed in DIR [default=auto]])], ,
            [with_gl_prefix=auto])

AC_ARG_WITH([gl-includedir],
            [AS_HELP_STRING([--with-gl-includedir=DIR],
                            [OpenGL (Mesa) headers are in DIR [default=auto]])], ,
            [with_gl_includedir=auto])

AC_ARG_WITH([gl-libdir],
            [AS_HELP_STRING([--with-gl-libdir=DIR],
                            [OpenGL (Mesa) libraries are in DIR [default=auto]])], ,
            [with_gl_libdir=auto])

if test "x$with_gl_includedir" != "xauto"; then
  GL_CFLAGS="-I$with_gl_includedir"
elif test "x$with_gl_prefix" != "xauto"; then
  GL_CFLAGS="-I$with_gl_prefix/include"
fi

if test "x$with_gl_libdir" != "xauto"; then
  GL_LDFLAGS="-L$with_gl_libdir"
elif test "x$with_gl_prefix" != "xauto"; then
  GL_LDFLAGS="-L$with_gl_prefix/lib"
fi

save_CPPFLAGS="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS $GL_CFLAGS $WINDOWING_CFLAGS"
save_LIBS="$LIBS"
LIBS="$LIBS $GL_LDFLAGS $WINDOWING_LIBS $MATH_LIB"

if test "x$gdktarget" = "xx11"; then
  AC_CHECK_HEADERS([GL/glx.h], ,
                   [AC_MSG_ERROR([Cannot find GLX header])])
fi

AC_CHECK_HEADERS([GL/gl.h GL/glu.h], ,
                 [AC_MSG_ERROR([Cannot find OpenGL headers])])

if test "x$gdktarget" = "xx11"; then

  # for X11

  THREAD_LIB="-lpthread"
  STDCXX_LIB="-lstdc++"

  have_GL=no
  GL_LIB_NAME=GL

  # GLcore and GL (SGI)
  AC_CHECK_LIB([GLcore], [glVertex3d],
               [GL_LIBS="-lGLcore"])
  if test "x$ac_cv_lib_GLcore_glVertex3d" = "xyes" ; then
    # if GLcore found, then also check for GL
    AC_CHECK_LIB([GL], [glXCreateContext],
                 [GL_LIBS="-lGL $GL_LIBS"
                  have_GL=yes])
  fi

  # GL
  if test "x$have_GL" = "xno" ; then
    # if no GLcore and GL, check for GL
    AC_CHECK_LIB([GL], [glVertex3d],
                 [GL_LIBS="-lGL"
                  have_GL=yes])
    if test "x$ac_cv_lib_GL_glVertex3d" = "xno" ; then
      # GL may need to be linked with the thread library explicitly
      AC_CHECK_LIB([GL], [glVertex3f],
                   [GL_LIBS="-lGL $THREAD_LIB"
                    have_GL=yes], ,
                   [$THREAD_LIB])
      if test "x$ac_cv_lib_GL_glVertex3f" = "xno" ; then
        # GL may need to be linked with std C++ library explicitly
        AC_CHECK_LIB([GL], [glVertex3i],
                     [GL_LIBS="-lGL $STDCXX_LIB"
                      have_GL=yes], ,
                     [$STDCXX_LIB])
        if test "x$ac_cv_lib_GL_glVertex3i" = "xno" ; then
          # GL may need to be linked with std C++ and thread libraries explicitly
          AC_CHECK_LIB([GL], [glVertex3s],
                       [GL_LIBS="-lGL $STDCXX_LIB $THREAD_LIB"
                        have_GL=yes], ,
                       [$STDCXX_LIB $THREAD_LIB])
        fi
      fi
    fi
  fi

  # MesaGL
  if test "x$have_GL" = "xno" ; then
    # if no GL, check for MesaGL
    AC_CHECK_LIB([MesaGL], [glVertex3d],
                 [GL_LIBS="-lMesaGL"
                  have_GL=yes
                  GL_LIB_NAME=MesaGL])
  fi

  if test "x$have_GL" = "xno" ; then
    # no GL found
    AC_MSG_ERROR([Cannot find GL library])
  fi

  # GLU

  have_GLU=no
  have_SGI_GLU=no

  AC_CHECK_LIB([GLU], [gluSphere],
               [GL_LIBS="-lGLU $GL_LIBS"
                have_GLU=yes], ,
               [$GL_LIBS])
  if test "x$ac_cv_lib_GLU_gluSphere" = "xno" ; then
    # GLU may need to be linked with the thread library explicitly
    AC_CHECK_LIB([GLU], [gluCylinder],
                 [GL_LIBS="-lGLU $GL_LIBS $THREAD_LIB"
                  have_GLU=yes], ,
                 [$GL_LIBS $THREAD_LIB])
    if test "x$ac_cv_lib_GLU_gluCylinder" = "xno" ; then
      # GLU may need to be linked with std C++ library explicitly
      AC_CHECK_LIB([GLU], [gluDisk],
                   [GL_LIBS="-lGLU $GL_LIBS $STDCXX_LIB"
                    have_GLU=yes
                    have_SGI_GLU=yes], ,
                   [$GL_LIBS $STDCXX_LIB])
      if test "x$ac_cv_lib_GLU_gluDisk" = "xno" ; then
        # GLU may need to be linked with std C++ and thread libraries explicitly
        AC_CHECK_LIB([GLU], [gluPartialDisk],
                     [GL_LIBS="-lGLU $GL_LIBS $STDCXX_LIB $THREAD_LIB"
                      have_GLU=yes
                      have_SGI_GLU=yes], ,
                     [$GL_LIBS $STDCXX_LIB $THREAD_LIB])
      fi
    fi
  fi

  if test "x$have_GLU" = "xno" ; then
    # if no GLU, check for MesaGLU
    AC_CHECK_LIB([MesaGLU], [gluSphere],
                 [GL_LIBS="-lMesaGLU $GL_LIBS"
                  have_GLU=yes], ,
                 [$GL_LIBS])
  fi

  if test "x$have_GLU" = "xno" ; then
    # no GLU found
    AC_MSG_ERROR([Cannot find GLU library])
  fi

  # Checks for SGI's GLU library
  if test "x$have_SGI_GLU" = "xno" ; then
    # Try static linking
    save_LDFLAGS="$LDFLAGS"
    LDFLAGS="$LDFLAGS $lt_cv_prog_cc_static"

    AC_CHECK_LIB([GLU], [gluBeginCurve],
                 [have_SGI_GLU=no], ,
                 [$GL_LIBS])
    if test "x$ac_cv_lib_GLU_gluBeginCurve" = "xno" ; then
      AC_CHECK_LIB([GLU], [gluBeginPolygon],
                   [GL_LIBS="$GL_LIBS $STDCXX_LIB"
                    have_SGI_GLU=yes], ,
                   [$GL_LIBS $STDCXX_LIB])
    fi

    LDFLAGS="$save_LDFLAGS"
  fi

  AC_MSG_CHECKING([whether libGLU needs to be linked with the std C++ library])
  AC_MSG_RESULT([$have_SGI_GLU])

  # Checks for some types in gdk/GL/glxext.h

  # GLXFBConfigSGIX
  GDKGLEXT_NEED_GLXFBCONFIGSGIX_TYPEDEF=no
  AC_CHECK_TYPES([GLXFBConfigSGIX], , ,
                 [#include <GL/glx.h>])
  if test "x$ac_cv_type_GLXFBConfigSGIX" = "xno" ; then
    GDKGLEXT_NEED_GLXFBCONFIGSGIX_TYPEDEF=yes
  fi

  # GLXFBConfigIDSGIX
  GDKGLEXT_NEED_GLXFBCONFIGIDSGIX_TYPEDEF=no
  AC_CHECK_TYPES([GLXFBConfigIDSGIX], , ,
                 [#include <GL/glx.h>])
  if test "x$ac_cv_type_GLXFBConfigIDSGIX" = "xno" ; then
    GDKGLEXT_NEED_GLXFBCONFIGIDSGIX_TYPEDEF=yes
  fi

  # GLXPbufferSGIX
  GDKGLEXT_NEED_GLXPBUFFERSGIX_TYPEDEF=no
  AC_CHECK_TYPES([GLXPbufferSGIX], , ,
                 [#include <GL/glx.h>])
  if test "x$ac_cv_type_GLXPbufferSGIX" = "xno" ; then
    GDKGLEXT_NEED_GLXPBUFFERSGIX_TYPEDEF=yes
  fi

  # GLXVideoSourceSGIX
  GDKGLEXT_NEED_GLXVIDEOSOURCESGIX_TYPEDEF=no
  AC_CHECK_TYPES([GLXVideoSourceSGIX], , ,
                 [#include <GL/glx.h>])
  if test "x$ac_cv_type_GLXVideoSourceSGIX" = "xno" ; then
    GDKGLEXT_NEED_GLXVIDEOSOURCESGIX_TYPEDEF=yes
  fi

  # __GLXextFuncPtr
  GDKGLEXT_NEED_GLXEXTFUNCPTR_TYPEDEF=no
  AC_CHECK_TYPES([__GLXextFuncPtr], , ,
                 [#include <GL/glx.h>])
  if test "x$ac_cv_type___GLXextFuncPtr" = "xno" ; then
    GDKGLEXT_NEED_GLXEXTFUNCPTR_TYPEDEF=yes
  fi

else

  # for Win32

  AC_MSG_CHECKING([for glNewList in -lopengl32])
  have_opengl32=no
  LIBS="-lopengl32 $LIBS"
  AC_TRY_LINK([#include <windows.h>
               #include <GL/gl.h>], 
              [glVertex3d(0.0, 0.0, 0.0);], 
              [GL_LIBS="-lopengl32"
               have_opengl32=yes])
  AC_MSG_RESULT([$have_opengl32])
  if test "x$have_opengl32" = "xno" ; then
    AC_MSG_ERROR([Cannot find GL library])
  fi

  AC_MSG_CHECKING([for gluNewQuadric in -lglu32])
  have_glu32=no
  LIBS="-lglu32 $LIBS"
  AC_TRY_LINK([#include <windows.h>
               #include <GL/gl.h>
               #include <GL/glu.h>], 
              [gluNewQuadric();], 
              [GL_LIBS="-lglu32 $GL_LIBS"
               have_glu32=yes])
  AC_MSG_RESULT([$have_glu32])
  if test "x$have_glu32" = "xno" ; then
    AC_MSG_ERROR([Cannot find GLU library])
  fi

dnl   AC_CHECK_LIB(opengl32, glNewList,
dnl                GL_LIBS="-lopengl32",
dnl                AC_MSG_ERROR(Cannot find GL library))

dnl   AC_CHECK_LIB(glu32, gluNewQuadric,
dnl                GL_LIBS="-lglu32 $GL_LIBS",
dnl                AC_MSG_ERROR(Cannot find GLU library),
dnl                $GL_LIBS)

fi

dnl # if using mesa, check for xmesa.h
dnl if test "x$ac_cv_lib_MesaGL_glNewList" = "xyes" ; then
dnl   AC_CHECK_HEADERS([GL/xmesa.h])
dnl   AM_CONDITIONAL(ENABLE_XMESA_FX, \
dnl                  test "x$ac_cv_header_GL_xmesa_h" = "xyes")
dnl else
dnl   # force a failed check
dnl   AM_CONDITIONAL(ENABLE_XMESA_FX, test "no" = "yes")
dnl fi

# Checks for typedefs in gdk/GL/glext.h

# GLhalfNV
GDKGLEXT_NEED_GLHALFNV_TYPEDEF=no
AC_CHECK_TYPES([GLhalfNV], , ,
               [#include <GL/gl.h>])
if test "x$ac_cv_type_GLhalfNV" = "xno" ; then
  GDKGLEXT_NEED_GLHALFNV_TYPEDEF=yes
fi

GL_LIBS="$GL_LDFLAGS $GL_LIBS"

AC_SUBST([GL_CFLAGS])
AC_SUBST([GL_LIBS])

CPPFLAGS="$save_CPPFLAGS"
LIBS="$save_LIBS"


##################################################
# Checks for gtk-doc and docbook-tools
##################################################

GTK_DOC_CHECK

##################################################
# Output configuration header
##################################################

dnl this section will only be run if config.status is invoked with no
dnl arguments, or with "gdk/gdkglext-config.h" as an argument.
AC_CONFIG_COMMANDS([gdk/gdkglext-config.h],
[
  outfile=gdkglext-config.h-tmp
  cat > $outfile <<\_______EOF
/* gdkglext-config.h
 *
 * This is a generated file.  Please modify `configure.ac'
 */

#ifndef GDKGLEXT_CONFIG_H
#define GDKGLEXT_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

_______EOF

	cat >>$outfile <<_______EOF
$gdkglext_windowing
$gdkglext_multihead_support
_______EOF

	cat >>$outfile <<_______EOF

#if !defined(GDKGLEXT_MULTIHEAD_SUPPORT) && defined(GDK_MULTIHEAD_SAFE)
#error "Installed GdkGLExt library doesn't have multihead support."
#endif

_______EOF

	cat >>$outfile <<_______EOF
$gdkglext_need_glxfbconfigsgix_typedef
$gdkglext_need_glxfbconfigidsgix_typedef
$gdkglext_need_glxpbuffersgix_typedef
$gdkglext_need_glxvideosourcesgix_typedef
$gdkglext_need_glxextfuncptr_typedef
$gdkglext_need_glhalfnv_typedef
_______EOF

	cat >>$outfile <<_______EOF

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GDKGLEXT_CONFIG_H */
_______EOF


  if cmp -s $outfile gdk/gdkglext-config.h; then
    AC_MSG_NOTICE([gdk/gdkglext-config.h is unchanged])
    rm -f $outfile
  else
    mv $outfile gdk/gdkglext-config.h
  fi

],[

if test "x$gdktarget" = "xx11" ; then
  gdkglext_windowing='
#define GDKGLEXT_WINDOWING_X11'
elif test "x$gdktarget" = "xwin32" ; then
  gdkglext_windowing='
#define GDKGLEXT_WINDOWING_WIN32'
fi

if test "x$GDKGLEXT_MULTIHEAD_SUPPORT" = "xyes"; then
  gdkglext_multihead_support='
#define GDKGLEXT_MULTIHEAD_SUPPORT'
fi

if test "x$GDKGLEXT_NEED_GLXFBCONFIGSGIX_TYPEDEF" = "xyes"; then
  gdkglext_need_glxfbconfigsgix_typedef='
#define GDKGLEXT_NEED_GLXFBCONFIGSGIX_TYPEDEF'
fi

if test "x$GDKGLEXT_NEED_GLXFBCONFIGIDSGIX_TYPEDEF" = "xyes"; then
  gdkglext_need_glxfbconfigidsgix_typedef='
#define GDKGLEXT_NEED_GLXFBCONFIGIDSGIX_TYPEDEF'
fi

if test "x$GDKGLEXT_NEED_GLXPBUFFERSGIX_TYPEDEF" = "xyes"; then
  gdkglext_need_glxpbuffersgix_typedef='
#define GDKGLEXT_NEED_GLXPBUFFERSGIX_TYPEDEF'
fi

if test "x$GDKGLEXT_NEED_GLXVIDEOSOURCESGIX_TYPEDEF" = "xyes"; then
  gdkglext_need_glxvideosourcesgix_typedef='
#define GDKGLEXT_NEED_GLXVIDEOSOURCESGIX_TYPEDEF'
fi

if test "x$GDKGLEXT_NEED_GLXEXTFUNCPTR_TYPEDEF" = "xyes"; then
  gdkglext_need_glxextfuncptr_typedef='
#define GDKGLEXT_NEED_GLXEXTFUNCPTR_TYPEDEF'
fi

if test "x$GDKGLEXT_NEED_GLHALFNV_TYPEDEF" = "xyes"; then
  gdkglext_need_glhalfnv_typedef='
#define GDKGLEXT_NEED_GLHALFNV_TYPEDEF'
fi

])


##################################################
# Config files
##################################################

AC_CONFIG_FILES([
gdkglext.pc
gtkglext.pc
gdkglext-uninstalled.pc
gtkglext-uninstalled.pc
gtkglext.spec
gtkglext.nsi
Makefile
gdk/Makefile
gdk/gdkglversion.h
gdk/glext/Makefile
gdk/x11/Makefile
gdk/win32/Makefile
gtk/Makefile
gtk/gtkglversion.h
docs/Makefile
docs/reference/Makefile
docs/reference/gtkglext/Makefile
docs/reference/gtkglext/version.xml
examples/Makefile
examples/glade/Makefile
])

AC_OUTPUT


##################################################
# Print configuration
##################################################

echo "
configuration:
	OpenGL CFLAGS:		$GL_CFLAGS
	OpenGL LIBS:		$GL_LIBS
	multihead support:	$GDKGLEXT_MULTIHEAD_SUPPORT
	debug:			$enable_debug
"
