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
 * Authored by: Michal Hruby <michal.mhr@gmail.com>
 */

#if !defined (_ZEITGEIST_H_INSIDE_) && !defined (ZEITGEIST_COMPILATION)
#error "Only <zeitgeist.h> can be included directly."
#endif

#ifndef _ZEITGEIST_SYMBOLS_H_
#define _ZEITGEIST_SYMBOLS_H_

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

GList*   zeitgeist_symbol_get_parents (const gchar *symbol);

GList*   zeitgeist_symbol_get_children (const gchar *symbol);

GList*   zeitgeist_symbol_get_all_children (const gchar *symbol);

gboolean zeitgeist_symbol_is_a (const gchar *symbol, const gchar *parent);

G_END_DECLS

#endif /* _ZEITGEIST_SYMBOLS_H_ */
