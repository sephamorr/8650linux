/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2010 Richard Hughes <richard@hughsie.com>
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

#ifndef __CD_COLOR_H__
#define __CD_COLOR_H__

#include <glib-object.h>

G_BEGIN_DECLS

typedef struct {
	guint8	 R;
	guint8	 G;
	guint8	 B;
} CdColorRGB8;

typedef struct {
	gdouble	 L;
	gdouble	 a;
	gdouble	 b;
} CdColorLab;

typedef struct {
	gdouble	 Y;
	gdouble	 x;
	gdouble	 y;
} CdColorYxy;

typedef struct {
	gdouble	 X;
	gdouble	 Y;
	gdouble	 Z;
} CdColorXYZ;

typedef struct {
	gdouble	 R;
	gdouble	 G;
	gdouble	 B;
} CdColorRGB;

typedef struct _CdColorSwatch	CdColorSwatch;

#define	CD_TYPE_COLOR_RGB	(cd_color_rgb_get_type ())
#define	CD_TYPE_COLOR_XYZ	(cd_color_xyz_get_type ())
#define	CD_TYPE_COLOR_LAB	(cd_color_lab_get_type ())
#define	CD_TYPE_COLOR_YXY	(cd_color_yxy_get_type ())
#define	CD_TYPE_COLOR_SWATCH	(cd_color_swatch_get_type ())

/* types */
GType		 cd_color_xyz_get_type			(void);
GType		 cd_color_lab_get_type			(void);
GType		 cd_color_rgb_get_type			(void);
GType		 cd_color_yxy_get_type			(void);
GType		 cd_color_swatch_get_type		(void);

const gchar	*cd_color_swatch_get_name		(const CdColorSwatch	*swatch);
const CdColorLab*cd_color_swatch_get_value		(const CdColorSwatch	*swatch);

CdColorXYZ	*cd_color_xyz_new			(void);
CdColorLab	*cd_color_lab_new			(void);
CdColorRGB	*cd_color_rgb_new			(void);
CdColorYxy	*cd_color_yxy_new			(void);
CdColorSwatch	*cd_color_swatch_new			(void);

void		 cd_color_xyz_free			(CdColorXYZ		*src);
void		 cd_color_rgb_free			(CdColorRGB		*src);
void		 cd_color_lab_free			(CdColorLab		*src);
void		 cd_color_yxy_free			(CdColorYxy		*src);
void		 cd_color_swatch_free			(CdColorSwatch		*src);

CdColorXYZ	*cd_color_xyz_dup			(const CdColorXYZ	*src);
CdColorLab	*cd_color_lab_dup			(const CdColorLab	*src);
CdColorRGB	*cd_color_rgb_dup			(const CdColorRGB	*src);
CdColorYxy	*cd_color_yxy_dup			(const CdColorYxy	*src);
CdColorSwatch	*cd_color_swatch_dup			(const CdColorSwatch	*src);

void		 cd_color_xyz_set			(CdColorXYZ		*dest,
							 gdouble		 X,
							 gdouble		 Y,
							 gdouble		 Z);
void		 cd_color_rgb_set			(CdColorRGB		*dest,
							 gdouble		 R,
							 gdouble		 G,
							 gdouble		 B);
void		 cd_color_lab_set			(CdColorLab		*dest,
							 gdouble		 L,
							 gdouble		 a,
							 gdouble		 b);
void		 cd_color_yxy_set			(CdColorYxy		*dest,
							 gdouble		 Y,
							 gdouble		 x,
							 gdouble		 y);
void		 cd_color_swatch_set_name		(CdColorSwatch		*dest,
							 const gchar		*name);
void		 cd_color_swatch_set_value		(CdColorSwatch		*dest,
							 const CdColorLab	*value);

void		 cd_color_xyz_copy			(const CdColorXYZ	*src,
							 CdColorXYZ		*dest);
void		 cd_color_yxy_copy			(const CdColorYxy	*src,
							 CdColorYxy		*dest);
void		 cd_color_lab_copy			(const CdColorLab	*src,
							 CdColorLab		*dest);
void		 cd_color_xyz_clear			(CdColorXYZ		*dest);
void		 cd_color_rgb_copy			(const CdColorRGB	*src,
							 CdColorRGB		*dest);
void		 cd_color_rgb8_to_rgb			(const CdColorRGB8	*src,
							 CdColorRGB		*dest);
void		 cd_color_rgb_to_rgb8			(const CdColorRGB	*src,
							 CdColorRGB8		*dest);
void		 cd_color_yxy_to_xyz			(const CdColorYxy	*src,
							 CdColorXYZ		*dest);
void		 cd_color_xyz_to_yxy			(const CdColorXYZ	*src,
							 CdColorYxy		*dest);
void		 cd_color_get_blackbody_rgb		(guint			 temp,
							 CdColorRGB		*result);
void		 cd_color_rgb_interpolate		(const CdColorRGB	*p1,
							 const CdColorRGB	*p2,
							 gdouble		 index,
							 CdColorRGB		*result);

GPtrArray	*cd_color_rgb_array_new			(void);
gboolean	 cd_color_rgb_array_is_monotonic	(const GPtrArray	*array);
GPtrArray	*cd_color_rgb_array_interpolate		(const GPtrArray	*array,
							 guint			 new_length)
							 G_GNUC_WARN_UNUSED_RESULT;

G_END_DECLS

#endif /* __CD_COLOR_H__ */

