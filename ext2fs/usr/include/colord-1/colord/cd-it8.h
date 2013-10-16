/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2012 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU Lesser General Public License Version 2.1
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#if !defined (__COLORD_H_INSIDE__) && !defined (CD_COMPILATION)
#error "Only <colord.h> can be included directly."
#endif

#ifndef __CD_IT8_H
#define __CD_IT8_H

#include <glib-object.h>
#include <gio/gio.h>

#include "cd-color.h"
#include "cd-math.h"

G_BEGIN_DECLS

#define CD_TYPE_IT8		(cd_it8_get_type ())
#define CD_IT8(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), CD_TYPE_IT8, CdIt8))
#define CD_IT8_CLASS(k)		(G_TYPE_CHECK_CLASS_CAST((k), CD_TYPE_IT8, CdIt8Class))
#define CD_IS_IT8(o)		(G_TYPE_CHECK_INSTANCE_TYPE ((o), CD_TYPE_IT8))
#define CD_IS_IT8_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), CD_TYPE_IT8))
#define CD_IT8_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), CD_TYPE_IT8, CdIt8Class))
#define CD_IT8_ERROR		(cd_it8_error_quark ())
#define CD_IT8_TYPE_ERROR	(cd_it8_error_get_type ())

typedef struct _CdIt8Private CdIt8Private;

typedef struct
{
	 GObject		 parent;
	 CdIt8Private		*priv;
} CdIt8;

typedef struct
{
	GObjectClass		 parent_class;
	/*< private >*/
	/* Padding for future expansion */
	void (*_cd_it8_reserved1) (void);
	void (*_cd_it8_reserved2) (void);
	void (*_cd_it8_reserved3) (void);
	void (*_cd_it8_reserved4) (void);
	void (*_cd_it8_reserved5) (void);
	void (*_cd_it8_reserved6) (void);
	void (*_cd_it8_reserved7) (void);
	void (*_cd_it8_reserved8) (void);
} CdIt8Class;

/**
 * CdIt8Error:
 * @CD_IT8_ERROR_FAILED: the transaction failed for an unknown reason
 *
 * Errors that can be thrown
 */
typedef enum
{
	CD_IT8_ERROR_FAILED,
	CD_IT8_ERROR_LAST
} CdIt8Error;

/**
 * CdIt8Kind:
 *
 * The kind of IT8 file.
 **/
typedef enum {
	CD_IT8_KIND_UNKNOWN,
	CD_IT8_KIND_TI1,
	CD_IT8_KIND_TI3,
	CD_IT8_KIND_CCMX,
	CD_IT8_KIND_CAL,
	CD_IT8_KIND_LAST
} CdIt8Kind;

GType		 cd_it8_get_type		(void);
GQuark		 cd_it8_error_quark		(void);
CdIt8		*cd_it8_new			(void);
CdIt8		*cd_it8_new_with_kind		(CdIt8Kind	 kind);

/* sync */
gboolean	 cd_it8_load_from_data		(CdIt8		*it8,
						 const gchar	*data,
						 gsize		 size,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
gboolean	 cd_it8_load_from_file		(CdIt8		*it8,
						 GFile		*file,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
gboolean	 cd_it8_save_to_file		(CdIt8		*it8,
						 GFile		*file,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;
gboolean	 cd_it8_save_to_data		(CdIt8		*it8,
						 gchar		**data,
						 gsize		*size,
						 GError		**error)
						 G_GNUC_WARN_UNUSED_RESULT;

/* setters */
void		 cd_it8_set_kind		(CdIt8		*it8,
						 CdIt8Kind	 kind);
void		 cd_it8_set_normalized		(CdIt8		*it8,
						 gboolean	 normalized);
void		 cd_it8_set_originator		(CdIt8		*it8,
						 const gchar	*originator);
void		 cd_it8_set_title		(CdIt8		*it8,
						 const gchar	*title);
void		 cd_it8_set_spectral		(CdIt8		*it8,
						 gboolean	 spectral);
void		 cd_it8_set_instrument		(CdIt8		*it8,
						 const gchar	*instrument);
void		 cd_it8_set_reference		(CdIt8		*it8,
						 const gchar	*reference);
void		 cd_it8_set_enable_created	(CdIt8		*it8,
						 gboolean	 enable_created);
void		 cd_it8_add_data		(CdIt8		*it8,
						 const CdColorRGB *rgb,
						 const CdColorXYZ *xyz);
void		 cd_it8_add_option		(CdIt8		*it8,
						 const gchar	*option);
void		 cd_it8_set_matrix		(CdIt8		*it8,
						 const CdMat3x3 *matrix);

/* getters */
const CdMat3x3	*cd_it8_get_matrix		(CdIt8		*it8);
CdIt8Kind	 cd_it8_get_kind		(CdIt8		*it8);
gboolean	 cd_it8_get_normalized		(CdIt8		*it8);
const gchar	*cd_it8_get_originator		(CdIt8		*it8);
const gchar	*cd_it8_get_title		(CdIt8		*it8);
gboolean	 cd_it8_get_spectral		(CdIt8		*it8);
const gchar	*cd_it8_get_instrument		(CdIt8		*it8);
const gchar	*cd_it8_get_reference		(CdIt8		*it8);
gboolean	 cd_it8_get_enable_created	(CdIt8		*it8);
guint		 cd_it8_get_data_size		(CdIt8		*it8);
gboolean	 cd_it8_get_data_item		(CdIt8		*it8,
						 guint		 idx,
						 CdColorRGB	*rgb,
						 CdColorXYZ	*xyz);
gboolean	 cd_it8_has_option		(CdIt8		*it8,
						 const gchar	*option);

G_END_DECLS

#endif /* __CD_IT8_H */

