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

#ifndef _ZEITGEIST_ENUMS_H_
#define _ZEITGEIST_ENUMS_H_

#include <glib-object.h>
#include <gio/gio.h>
#include <zeitgeist-enumtypes.h>

/**
 * SECTION:zeitgeist-enums 
 * @short_description: Enumerations used in the Zeitgeist API
 * @include: zeitgeist.h
 */

G_BEGIN_DECLS

/**
 * ZeitgeistResultType:
 * @ZEITGEIST_RESULT_TYPE_MOST_RECENT_EVENTS: All events with the most recent events first
 * @ZEITGEIST_RESULT_TYPE_LEAST_RECENT_EVENTS: All events with the oldest ones first
 * @ZEITGEIST_RESULT_TYPE_MOST_RECENT_SUBJECTS: One event for each subject only, ordered with the most recent events first
 * @ZEITGEIST_RESULT_TYPE_LEAST_RECENT_SUBJECTS: One event for each subject only, ordered with oldest events first
 * @ZEITGEIST_RESULT_TYPE_MOST_POPULAR_SUBJECTS: One event for each subject only, ordered by the popularity of the subject
 * @ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_SUBJECTS: One event for each subject only, ordered ascendingly by popularity
 * @ZEITGEIST_RESULT_TYPE_MOST_POPULAR_ACTOR: The last event of each different actor, ordered with the most popular actor first
 * @ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_ACTOR: The last event of each different actor, ordered with the least popular actor first
 * @ZEITGEIST_RESULT_TYPE_MOST_RECENT_ACTOR: One event for each different actor, with the actor that has been used most recently first
 * @ZEITGEIST_RESULT_TYPE_LEAST_RECENT_ACTOR: One event for each different actor, with the actor that has been used least recently first
 * @ZEITGEIST_RESULT_TYPE_MOST_RECENT_ORIGIN: The last event of each different origin ordered with the most recent event first
 * @ZEITGEIST_RESULT_TYPE_LEAST_RECENT_ORIGIN: The first event of each different origin ordered with the least recent event first
 * @ZEITGEIST_RESULT_TYPE_MOST_POPULAR_ORIGIN: The last event of each different origin, ordered by the popularity of the origin
 * @ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_ORIGIN: The last event of each different origin, ordered ascendingly by the popularity of the origin
 * @ZEITGEIST_RESULT_TYPE_OLDEST_ACTOR: The first event of each different actor
 * @ZEITGEIST_RESULT_TYPE_MOST_RECENT_SUBJECT_INTERPRETATION: One event for each subject interpretation only ordered with the most recent events first
 * @ZEITGEIST_RESULT_TYPE_LEAST_RECENT_SUBJECT_INTERPRETATION: One event for each subject interpretation only ordered with the least recent events first
 * @ZEITGEIST_RESULT_TYPE_MOST_POPULAR_SUBJECT_INTERPRETATION: One event for each subject interpretation only, ordered by the popularity of the subject interpretation
 * @ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_SUBJECT_INTERPRETATION: One event for each subject interpretation only, ordered ascendingly by popularity of the subject interpretation
 * @ZEITGEIST_RESULT_TYPE_MOST_RECENT_MIMETYPE: One event for each mimetype only, ordered with the most recent events first
 * @ZEITGEIST_RESULT_TYPE_LEAST_RECENT_MIMETYPE: One event for each mimetype only, ordered with the least recent events first
 * @ZEITGEIST_RESULT_TYPE_MOST_POPULAR_MIMETYPE: One event for each mimetype only, ordered by the popularity of the mimetype
 * @ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_MIMETYPE: One event for each mimetype only, ordered ascendingly by popularity of the mimetype
 * @ZEITGEIST_RESULT_TYPE_MOST_RECENT_CURRENT_URI: One event for each current uri only, ordered with the most recent events first
 * @ZEITGEIST_RESULT_TYPE_LEAST_RECENT_CURRENT_URI: One event for each current uri only, ordered with oldest events first
 * @ZEITGEIST_RESULT_TYPE_MOST_POPULAR_CURRENT_URI: One event for each current uri only, ordered by the popularity of the current uri
 * @ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_CURRENT_URI: One event for each current uri only, ordered ascendingly by popularity
 * @ZEITGEIST_RESULT_TYPE_MOST_RECENT_EVENT_ORIGIN: One event for each event origin only, ordered with the most recent events first
 * @ZEITGEIST_RESULT_TYPE_LEAST_RECENT_EVENT_ORIGIN: One event for each event origin only, ordered with the least recent events first
 * @ZEITGEIST_RESULT_TYPE_MOST_POPULAR_EVENT_ORIGIN: One event for each event origin only, ordered by the popularity of the event origin
 * @ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_EVENT_ORIGIN: One event for each event origin only, ordered ascendingly by popularity of the event origin
 * @ZEITGEIST_RESULT_TYPE_RELEVANCY: Only allowed on zeitgeist_index_search(). Events are sorted by query relevancy
 *
 * Used to control how the query results are grouped and sorted.
 * See zeitgeist_log_find_events(), zeitgeist_log_find_event_ids(), and
 * zeitgeist_index_search().
 */
typedef enum
{
  ZEITGEIST_RESULT_TYPE_MOST_RECENT_EVENTS = 0,
  ZEITGEIST_RESULT_TYPE_LEAST_RECENT_EVENTS = 1,
  ZEITGEIST_RESULT_TYPE_MOST_RECENT_SUBJECTS = 2,
  ZEITGEIST_RESULT_TYPE_LEAST_RECENT_SUBJECTS = 3,
  ZEITGEIST_RESULT_TYPE_MOST_POPULAR_SUBJECTS = 4,
  ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_SUBJECTS = 5,
  ZEITGEIST_RESULT_TYPE_MOST_POPULAR_ACTOR = 6,
  ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_ACTOR = 7,
  ZEITGEIST_RESULT_TYPE_MOST_RECENT_ACTOR = 8,
  ZEITGEIST_RESULT_TYPE_LEAST_RECENT_ACTOR = 9,
  ZEITGEIST_RESULT_TYPE_MOST_RECENT_ORIGIN = 10,
  ZEITGEIST_RESULT_TYPE_LEAST_RECENT_ORIGIN = 11,
  ZEITGEIST_RESULT_TYPE_MOST_POPULAR_ORIGIN = 12,
  ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_ORIGIN = 13,
  ZEITGEIST_RESULT_TYPE_OLDEST_ACTOR = 14,
  ZEITGEIST_RESULT_TYPE_MOST_RECENT_SUBJECT_INTERPRETATION = 15,
  ZEITGEIST_RESULT_TYPE_LEAST_RECENT_SUBJECT_INTERPRETATION = 16,
  ZEITGEIST_RESULT_TYPE_MOST_POPULAR_SUBJECT_INTERPRETATION = 17,
  ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_SUBJECT_INTERPRETATION = 18,
  ZEITGEIST_RESULT_TYPE_MOST_RECENT_MIMETYPE = 19,
  ZEITGEIST_RESULT_TYPE_LEAST_RECENT_MIMETYPE = 20,
  ZEITGEIST_RESULT_TYPE_MOST_POPULAR_MIMETYPE = 21,
  ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_MIMETYPE = 22,
  ZEITGEIST_RESULT_TYPE_MOST_RECENT_CURRENT_URI = 23,
  ZEITGEIST_RESULT_TYPE_LEAST_RECENT_CURRENT_URI = 24,
  ZEITGEIST_RESULT_TYPE_MOST_POPULAR_CURRENT_URI = 25,
  ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_CURRENT_URI = 26,
  ZEITGEIST_RESULT_TYPE_MOST_RECENT_EVENT_ORIGIN = 27,
  ZEITGEIST_RESULT_TYPE_LEAST_RECENT_EVENT_ORIGIN = 28,
  ZEITGEIST_RESULT_TYPE_MOST_POPULAR_EVENT_ORIGIN = 29,
  ZEITGEIST_RESULT_TYPE_LEAST_POPULAR_EVENT_ORIGIN = 30,
  ZEITGEIST_RESULT_TYPE_RELEVANCY = 100,
} ZeitgeistResultType;

/**
 * ZeitgeistStorageState:
 * @ZEITGEIST_STORAGE_STATE_NOT_AVAILABLE: The subject is not available right now
 * @ZEITGEIST_STORAGE_STATE_AVAILABLE: The subject is available
 * @ZEITGEIST_STORAGE_STATE_ANY: The availability of the subject is irrelevant
 *
 * Used to restrict queries to only available subjects.
 * See zeitgeist_log_find_events() and zeitgeist_log_find_event_ids().
 */
typedef enum
{
  ZEITGEIST_STORAGE_STATE_NOT_AVAILABLE = 0,
  ZEITGEIST_STORAGE_STATE_AVAILABLE = 1,
  ZEITGEIST_STORAGE_STATE_ANY = 2,
} ZeitgeistStorageState;

G_END_DECLS

#endif /* _ZEITGEIST_ENUMS_H_ */
