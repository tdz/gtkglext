/* GdkGLExt - OpenGL Extension to GDK
 * Copyright (C) 2002  Naofumi Yasufuku
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
 * !!! NOTICE !!!
 * Contents of this file are ripped from GDK.
 *
 * Naofumi
 */

/* GDK - The GIMP Drawing Kit
 * Copyright (C) 1995-1997 Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GTK+ Team and others 1997-1999.  See the AUTHORS
 * file for a list of people on the GTK+ Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GTK+ at ftp://ftp.gtk.org/pub/gtk/. 
 */

#ifndef __GDK_INTERANL_WIN32_H__
#define __GDK_INTERNAL_WIN32_H__

#include <gdk/gdkwin32.h>

G_BEGIN_DECLS

/*
 * Win32 private data structures ripped from GTK+ 2.0.3.
 */

/*
 * GdkDrawableImplWin32 data structure
 */

typedef struct _GdkDrawableImplWin32 GdkDrawableImplWin32;

struct _GdkDrawableImplWin32
{
  GdkDrawable parent_instance;
  GdkDrawable *wrapper;
  GdkColormap *colormap;
  HANDLE handle;
};

/*
 * GdkPixmapImplWin32 data structure
 */

typedef struct _GdkPixmapImplWin32 GdkPixmapImplWin32;

struct _GdkPixmapImplWin32
{
  GdkDrawableImplWin32 parent_instance;

  gint width;
  gint height;

  GdkImage *image;		/* A pointer to the GdkImage
				 * containing the pixels.
				 */
  guint is_foreign : 1;
};

G_END_DECLS

#endif /* __GDK_INTERANL_WIN32_H__ */
