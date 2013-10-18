/*
 * Copyright (C) 2010 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authored by
 *             Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 */

#ifndef _ZEITGEIST_MIMETYPES_H_
#define _ZEITGEIST_MIMETYPES_H_

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

void         zeitgeist_register_mimetype           (const gchar *mimetype,
                                                    const gchar *interpretation_uri);

void         zeitgeist_register_mimetype_regex     (const gchar *mimetype_regex,
                                                    const gchar *interpretation_uri);

const gchar* zeitgeist_interpretation_for_mimetype (const gchar *mimetype);

void         zeitgeist_register_uri_scheme         (const gchar *uri_scheme,
                                                    const gchar *manifestation_type);

const gchar* zeitgeist_manifestation_for_uri       (const gchar *uri);

G_END_DECLS

#endif /* _ZEITGEIST_MIMETYPES_H_ */
