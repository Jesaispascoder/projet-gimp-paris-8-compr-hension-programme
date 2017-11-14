/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-2003 Spencer Kimball and Peter Mattis
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

/* NOTE: This file is auto-generated by pdbgen.pl. */

#include "config.h"

#include <gegl.h>

#include "pdb-types.h"

#include "core/gimp.h"
#include "core/gimpcontainer-filter.h"
#include "core/gimpcontainer.h"
#include "core/gimpparamspecs.h"
#include "text/gimp-fonts.h"

#include "gimppdb.h"
#include "gimpprocedure.h"
#include "internal-procs.h"


static GValueArray *
fonts_refresh_invoker (GimpProcedure      *procedure,
                       Gimp               *gimp,
                       GimpContext        *context,
                       GimpProgress       *progress,
                       const GValueArray  *args,
                       GError            **error)
{
  gimp_fonts_load (gimp);

  return gimp_procedure_get_return_values (procedure, TRUE, NULL);
}

static GValueArray *
fonts_get_list_invoker (GimpProcedure      *procedure,
                        Gimp               *gimp,
                        GimpContext        *context,
                        GimpProgress       *progress,
                        const GValueArray  *args,
                        GError            **error)
{
  gboolean success = TRUE;
  GValueArray *return_vals;
  const gchar *filter;
  gint32 num_fonts = 0;
  gchar **font_list = NULL;

  filter = g_value_get_string (&args->values[0]);

  if (success)
    {
      font_list = gimp_container_get_filtered_name_array (gimp->fonts,
                                                          filter, &num_fonts);
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    {
      g_value_set_int (&return_vals->values[1], num_fonts);
      gimp_value_take_stringarray (&return_vals->values[2], font_list, num_fonts);
    }

  return return_vals;
}

void
register_fonts_procs (GimpPDB *pdb)
{
  GimpProcedure *procedure;

  /*
   * gimp-fonts-refresh
   */
  procedure = gimp_procedure_new (fonts_refresh_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-fonts-refresh");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-fonts-refresh",
                                     "Refresh current fonts. This function always succeeds.",
                                     "This procedure retrieves all fonts currently in the user's font path and updates the font dialogs accordingly.",
                                     "Sven Neumann <sven@gimp.org>",
                                     "Sven Neumann",
                                     "2003",
                                     NULL);
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-fonts-get-list
   */
  procedure = gimp_procedure_new (fonts_get_list_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-fonts-get-list");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-fonts-get-list",
                                     "Retrieve the list of loaded fonts.",
                                     "This procedure returns a list of the fonts that are currently available.",
                                     "Sven Neumann <sven@gimp.org>",
                                     "Sven Neumann",
                                     "2003",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("filter",
                                                       "filter",
                                                       "An optional regular expression used to filter the list",
                                                       FALSE, TRUE, FALSE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   gimp_param_spec_int32 ("num-fonts",
                                                          "num fonts",
                                                          "The number of available fonts",
                                                          0, G_MAXINT32, 0,
                                                          GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   gimp_param_spec_string_array ("font-list",
                                                                 "font list",
                                                                 "The list of font names",
                                                                 GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);
}
