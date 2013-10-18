/*
 * Copyright (C) 2009 Canonical, Ltd.
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
 * Authored by Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 */

#if !defined (_ZEITGEIST_H_INSIDE_) && !defined (ZEITGEIST_COMPILATION)
#error "Only <zeitgeist.h> can be included directly."
#endif

#ifndef _ZEITGEIST_EVENT_H_
#define _ZEITGEIST_EVENT_H_

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <zeitgeist-subject.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_EVENT (zeitgeist_event_get_type ())

#define ZEITGEIST_EVENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
        ZEITGEIST_TYPE_EVENT, ZeitgeistEvent))
        
#define ZEITGEIST_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), \
        ZEITGEIST_TYPE_EVENT, ZeitgeistEventClass))
        
#define ZEITGEIST_IS_EVENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
        ZEITGEIST_TYPE_EVENT))
        
#define ZEITGEIST_IS_EVENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), \
        ZEITGEIST_TYPE_EVENT))
        
#define ZEITGEIST_EVENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), \
        ZEITGEIST_TYPE_EVENT, ZeitgeistEventClass))

typedef struct _ZeitgeistEvent ZeitgeistEvent;
typedef struct _ZeitgeistEventClass ZeitgeistEventClass;

struct _ZeitgeistEventClass
{
  GInitiallyUnownedClass parent_class;
};


struct _ZeitgeistEvent
{
  GInitiallyUnowned parent_instance;
};

GType        zeitgeist_event_get_type           (void);

ZeitgeistEvent* zeitgeist_event_new             (void);

ZeitgeistEvent* zeitgeist_event_new_full        (const gchar    *interpretation,
                                                 const gchar    *manifestation,
                                                 const gchar    *actor,
                                                 ...) G_GNUC_NULL_TERMINATED;

ZeitgeistEvent* zeitgeist_event_new_full_valist (const gchar    *interpretation,
                                                 const gchar    *manifestation,
                                                 const gchar    *actor,
                                                 va_list         args);

ZeitgeistEvent* zeitgeist_event_new_from_variant (GVariant *event);

guint32      zeitgeist_event_get_id             (ZeitgeistEvent *event);

void         zeitgeist_event_set_id             (ZeitgeistEvent *event,
                                                 guint32         id);

gint64       zeitgeist_event_get_timestamp      (ZeitgeistEvent *event);

void         zeitgeist_event_set_timestamp      (ZeitgeistEvent *event,
                                                 gint64          timestamp);
        
const gchar* zeitgeist_event_get_interpretation (ZeitgeistEvent *event);

void         zeitgeist_event_set_interpretation (ZeitgeistEvent *event,
                                                 const gchar    *interpretation);
        
const gchar* zeitgeist_event_get_manifestation  (ZeitgeistEvent *event);

void         zeitgeist_event_set_manifestation (ZeitgeistEvent *event,
                                                const gchar    *manifestation);

const gchar* zeitgeist_event_get_actor         (ZeitgeistEvent *event);

void         zeitgeist_event_set_actor         (ZeitgeistEvent *event,
                                                const gchar    *actor);

const gchar* zeitgeist_event_get_origin        (ZeitgeistEvent *event);
void         zeitgeist_event_set_origin        (ZeitgeistEvent *event,
                                                const gchar    *origin);

void         zeitgeist_event_set_actor_from_app_info (ZeitgeistEvent *event,
                                                      GAppInfo       *appinfo);
        
ZeitgeistSubject*
             zeitgeist_event_get_subject       (ZeitgeistEvent *event,
                                                gint            index);

gint         zeitgeist_event_num_subjects      (ZeitgeistEvent *event);

void         zeitgeist_event_add_subject       (ZeitgeistEvent   *event,
                                                ZeitgeistSubject *subject);

GByteArray*  zeitgeist_event_get_payload       (ZeitgeistEvent   *event);

void         zeitgeist_event_set_payload       (ZeitgeistEvent   *event,
                                                GByteArray       *payload);

GVariant*    zeitgeist_event_to_variant        (ZeitgeistEvent   *event);

GVariant*    zeitgeist_events_to_variant       (GPtrArray        *events);

GPtrArray*   zeitgeist_events_from_variant     (GVariant         *events);

GPtrArray*   zeitgeist_events_from_valist      (va_list           events);

/**
 * ZEITGEIST_EVENT_VARIANT_SIGNATURE:
 *
 * The #GVariant signature for a serialized #ZeitgeistEvent
 */
#define ZEITGEIST_EVENT_VARIANT_SIGNATURE "(asaasay)"

/**
 * ZEITGEIST_EVENT_VARIANT_TYPE:
 *
 * The #GVariantType of #ZEITGEIST_EVENT_SIGNATURE
 */
#define ZEITGEIST_EVENT_VARIANT_TYPE G_VARIANT_TYPE(ZEITGEIST_EVENT_VARIANT_SIGNATURE)

G_END_DECLS

#endif /* _ZEITGEIST_EVENT_H_ */
