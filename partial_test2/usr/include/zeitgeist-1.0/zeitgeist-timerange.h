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

#if !defined (_ZEITGEIST_H_INSIDE_) && !defined (ZEITGEIST_COMPILATION)
#error "Only <zeitgeist.h> can be included directly."
#endif

#ifndef _ZEITGEIST_TIME_RANGE_H_
#define _ZEITGEIST_TIME_RANGE_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_TIME_RANGE          (zeitgeist_time_range_get_type())
#define ZEITGEIST_TIME_RANGE(o)            (G_TYPE_CHECK_INSTANCE_CAST ((o), ZEITGEIST_TYPE_TIME_RANGE, ZeitgeistTimeRange))
#define ZEITGEIST_TIME_RANGE_CLASS(k)      (G_TYPE_CHECK_CLASS_CAST((k), ZEITGEIST_TYPE_TIME_RANGE, ZeitgeistTimeRangeClass))
#define ZEITGEIST_TIME_RANGE_GET_CLASS(o)  (G_TYPE_INSTANCE_GET_CLASS ((o), ZEITGEIST_TYPE_TIME_RANGE, ZeitgeistTimeRangeClass))
#define ZEITGEIST_IS_TIME_RANGE(o)         (G_TYPE_CHECK_INSTANCE_TYPE ((o), ZEITGEIST_TYPE_TIME_RANGE))
#define ZEITGEIST_IS_TIME_RANGE_CLASS(k)   (G_TYPE_CHECK_CLASS_TYPE ((k), ZEITGEIST_TYPE_TIME_RANGE))

typedef struct _ZeitgeistTimeRange ZeitgeistTimeRange;
typedef struct _ZeitgeistTimeRangeClass ZeitgeistTimeRangeClass;

struct _ZeitgeistTimeRangeClass
{
  GInitiallyUnownedClass parent_class;
};

struct _ZeitgeistTimeRange
{
  GInitiallyUnowned parent_instance;
};

GType       zeitgeist_time_range_get_type      (void);

ZeitgeistTimeRange*
            zeitgeist_time_range_new           (gint64               start_msec,
                                                gint64               end_msec);

ZeitgeistTimeRange*
            zeitgeist_time_range_new_from_variant
                                               (GVariant *time_range);

ZeitgeistTimeRange*
            zeitgeist_time_range_new_from_now  (void);

ZeitgeistTimeRange*
            zeitgeist_time_range_new_to_now    (void);

ZeitgeistTimeRange*
            zeitgeist_time_range_new_anytime   (void);

gint64      zeitgeist_time_range_get_start     (ZeitgeistTimeRange *time_range);

gint64      zeitgeist_time_range_get_end       (ZeitgeistTimeRange *time_range);

gchar*      zeitgeist_time_range_get_start_iso8601 (ZeitgeistTimeRange *time_range);

gchar*      zeitgeist_time_range_get_end_iso8601   (ZeitgeistTimeRange *time_range);

GVariant*   zeitgeist_time_range_to_variant    (ZeitgeistTimeRange *time_range);

/**
 * ZEITGEIST_TIME_RANGE_VARIANT_SIGNATURE:
 *
 * The #GVariant signature of a serialized #ZeitgeistTimeRange
 */
#define ZEITGEIST_TIME_RANGE_VARIANT_SIGNATURE "(xx)"

/**
 * ZEITGEIST_TIME_RANGE_VARIANT_TYPE:
 *
 * The #GVariantType of a serialized #ZeitgeistTimeRange
 */
#define ZEITGEIST_TIME_RANGE_VARIANT_TYPE G_VARIANT_TYPE(ZEITGEIST_TIME_RANGE_VARIANT_SIGNATURE)

G_END_DECLS

#endif /* _ZEITGEIST_TIME_RANGE_H_ */
