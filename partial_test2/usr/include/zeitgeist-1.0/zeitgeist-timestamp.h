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

#ifndef _ZEITGEIST_TIMESTAMP_H_
#define _ZEITGEIST_TIMESTaMP_H_

#include <glib.h>

G_BEGIN_DECLS

/**
 * ZEITGEIST_TIMESTAMP_SECOND:
 *
 * A second represented as a Zeitgeist timestamp (ie. 1000ms)
 */
#define ZEITGEIST_TIMESTAMP_SECOND G_GINT64_CONSTANT (1000)

/**
 * ZEITGEIST_TIMESTAMP_MINUTE:
 *
 * A minute represented as a Zeitgeist timestamp (ie. 60000ms)
 */
#define ZEITGEIST_TIMESTAMP_MINUTE G_GINT64_CONSTANT (60000)

/**
 * ZEITGEIST_TIMESTAMP_HOUR:
 *
 * An hour represented as a Zeitgeist timestamp (ie. 3600000ms)
 */
#define ZEITGEIST_TIMESTAMP_HOUR G_GINT64_CONSTANT (3600000)

/**
 * ZEITGEIST_TIMESTAMP_DAY:
 *
 * A day represented as a Zeitgeist timestamp (ie. 86400000ms)
 */
#define ZEITGEIST_TIMESTAMP_DAY G_GINT64_CONSTANT (86400000)

/**
 * ZEITGEIST_TIMESTAMP_WEEK:
 *
 * A week represented as a Zeitgeist timestamp (ie. 604800000ms)
 */
#define ZEITGEIST_TIMESTAMP_WEEK G_GINT64_CONSTANT (604800000)

/**
 * ZEITGEIST_TIMESTAMP_YEAR:
 *
 * A year represented as a Zeitgeist timestamp (ie. 31556952000ms).
 * Be warned that a year is not 365 days, but in fact 365.2425 days to
 * account for leap years.
 */
#define ZEITGEIST_TIMESTAMP_YEAR G_GINT64_CONSTANT (31556952000)

gint64       zeitgeist_timestamp_for_now            (void);

gint64       zeitgeist_timestamp_from_timeval       (GTimeVal    *tv);

void         zeitgeist_timestamp_to_timeval         (gint64       timestamp,
                                                     GTimeVal    *tv);

gint64       zeitgeist_timestamp_from_iso8601       (const gchar *datetime);

gchar*       zeitgeist_timestamp_to_iso8601         (gint64       timestamp);

gint64       zeitgeist_timestamp_from_date          (GDate       *date);

gint64       zeitgeist_timestamp_from_dmy           (GDateDay     day,
                                                     GDateMonth   month,
                                                     GDateYear    year);

void         zeitgeist_timestamp_to_date            (gint64       timestamp,
                                                     GDate       *date);

gint64       zeitgeist_timestamp_next_midnight      (gint64       timestamp);

gint64       zeitgeist_timestamp_prev_midnight      (gint64       timestamp);


G_END_DECLS

#endif /* _ZEITGEIST_TIMESTAMP_H_ */
