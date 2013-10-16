/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2011-2012 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#if !defined (__COLORHUG_H_INSIDE__) && !defined (CH_COMPILATION)
#error "Only <colorhug.h> can be included directly."
#endif

#ifndef __CH_INHX32_H
#define __CH_INHX32_H

#include <glib.h>

#include "ch-common.h"

G_BEGIN_DECLS

gboolean	 ch_inhx32_to_bin		(const gchar	*in_buffer,
						 guint8		**out_buffer,
						 gsize		*out_size,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;

G_END_DECLS

#endif /* __CH_INHX32_H */
