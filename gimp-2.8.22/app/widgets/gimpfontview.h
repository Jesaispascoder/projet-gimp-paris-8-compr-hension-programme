/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * gimpfontview.h
 * Copyright (C) 2003 Michael Natterer <mitch@gimp.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GIMP_FONT_VIEW_H__
#define __GIMP_FONT_VIEW_H__


#include "gimpcontainereditor.h"


#define GIMP_TYPE_FONT_VIEW            (gimp_font_view_get_type ())
#define GIMP_FONT_VIEW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_FONT_VIEW, GimpFontView))
#define GIMP_FONT_VIEW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIMP_TYPE_FONT_VIEW, GimpFontViewClass))
#define GIMP_IS_FONT_VIEW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_FONT_VIEW))
#define GIMP_IS_FONT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_FONT_VIEW))
#define GIMP_FONT_VIEW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIMP_TYPE_FONT_VIEW, GimpFontViewClass))


typedef struct _GimpFontViewClass  GimpFontViewClass;

struct _GimpFontView
{
  GimpContainerEditor  parent_instance;

  GtkWidget           *refresh_button;
};

struct _GimpFontViewClass
{
  GimpContainerEditorClass  parent_class;
};


GType       gimp_font_view_get_type (void) G_GNUC_CONST;

GtkWidget * gimp_font_view_new      (GimpViewType     view_type,
                                     GimpContainer   *container,
                                     GimpContext     *context,
                                     gint             view_size,
                                     gint             view_border_width,
                                     GimpMenuFactory *menu_factory);


#endif  /*  __GIMP_FONT_VIEW_H__  */
