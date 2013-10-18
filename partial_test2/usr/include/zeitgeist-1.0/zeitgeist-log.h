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

#ifndef _ZEITGEIST_LOG_H_
#define _ZEITGEIST_LOG_H_

#include <glib-object.h>
#include <gio/gio.h>
#include <zeitgeist-monitor.h>
#include <zeitgeist-event.h>
#include <zeitgeist-enums.h>
#include <zeitgeist-result-set.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_LOG          (zeitgeist_log_get_type())
#define ZEITGEIST_LOG(o)            (G_TYPE_CHECK_INSTANCE_CAST ((o), ZEITGEIST_TYPE_LOG, ZeitgeistLog))
#define ZEITGEIST_LOG_CLASS(k)      (G_TYPE_CHECK_CLASS_CAST((k), ZEITGEIST_TYPE_LOG, ZeitgeistLogClass))
#define ZEITGEIST_LOG_GET_CLASS(o)  (G_TYPE_INSTANCE_GET_CLASS ((o), ZEITGEIST_TYPE_LOG, ZeitgeistLogClass))
#define ZEITGEIST_IS_LOG(o)         (G_TYPE_CHECK_INSTANCE_TYPE ((o), ZEITGEIST_TYPE_LOG))
#define ZEITGEIST_IS_LOG_CLASS(k)   (G_TYPE_CHECK_CLASS_TYPE ((k), ZEITGEIST_TYPE_LOG))

typedef struct _ZeitgeistLog ZeitgeistLog;
typedef struct _ZeitgeistLogClass ZeitgeistLogClass;

struct _ZeitgeistLogClass
{
  GObjectClass parent_class;
};


struct _ZeitgeistLog
{
  GObject parent_instance;
};

GType        zeitgeist_log_get_type             (void);

ZeitgeistLog* zeitgeist_log_new                 (void);

ZeitgeistLog* zeitgeist_log_get_default         (void);

void         zeitgeist_log_insert_events        (ZeitgeistLog        *self,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data,
                                                 ...) G_GNUC_NULL_TERMINATED;

void         zeitgeist_log_insert_events_no_reply
                                                (ZeitgeistLog        *self,
                                                 ...) G_GNUC_NULL_TERMINATED;

void         zeitgeist_log_insert_events_valist (ZeitgeistLog        *self,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data,
                                                 va_list              events);

void         zeitgeist_log_insert_events_from_ptrarray
                                                (ZeitgeistLog        *self,
                                                 GPtrArray           *events,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);

GArray*      zeitgeist_log_insert_events_finish (ZeitgeistLog        *self,
                                                 GAsyncResult        *res,
                                                 GError             **error);

void         zeitgeist_log_find_events          (ZeitgeistLog        *self,
                                                 ZeitgeistTimeRange  *time_range,
                                                 GPtrArray           *event_templates,
                                                 ZeitgeistStorageState storage_state,
                                                 guint32              num_events,
                                                 ZeitgeistResultType  result_type,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);

ZeitgeistResultSet*
             zeitgeist_log_find_events_finish   (ZeitgeistLog        *self,
                                                 GAsyncResult        *res,
                                                 GError             **error);

void         zeitgeist_log_find_event_ids       (ZeitgeistLog        *self,
                                                 ZeitgeistTimeRange  *time_range,
                                                 GPtrArray           *event_templates,
                                                 ZeitgeistStorageState storage_state,
                                                 guint32              num_events,
                                                 ZeitgeistResultType  result_type,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);

GArray*      zeitgeist_log_find_event_ids_finish (ZeitgeistLog       *self,
                                                  GAsyncResult       *res,
                                                  GError            **error);

void         zeitgeist_log_get_events           (ZeitgeistLog        *self,
                                                 GArray              *event_ids,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);

ZeitgeistResultSet*
             zeitgeist_log_get_events_finish    (ZeitgeistLog        *self,
                                                 GAsyncResult        *res,
                                                 GError             **error);

void         zeitgeist_log_find_related_uris    (ZeitgeistLog        *self,
                                                 ZeitgeistTimeRange  *time_range,
                                                 GPtrArray           *event_templates,
                                                 GPtrArray           *result_event_templates,
                                                 ZeitgeistStorageState storage_state,
                                                 guint32              num_events,
                                                 ZeitgeistResultType  result_type,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);

gchar**      zeitgeist_log_find_related_uris_finish (ZeitgeistLog    *self,
                                                     GAsyncResult    *res,
                                                     GError         **error);

void         zeitgeist_log_delete_events        (ZeitgeistLog        *self,
                                                 GArray              *event_ids,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);

gboolean     zeitgeist_log_delete_events_finish (ZeitgeistLog        *self,
                                                 GAsyncResult        *res,
                                                 GError             **error);

void         zeitgeist_log_delete_log           (ZeitgeistLog        *self,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);

gboolean     zeitgeist_log_delete_log_finish    (ZeitgeistLog        *self,
                                                 GAsyncResult        *res,
                                                 GError             **error);

void         zeitgeist_log_quit                 (ZeitgeistLog        *self,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);

gboolean     zeitgeist_log_quit_finish          (ZeitgeistLog        *self,
                                                 GAsyncResult        *res,
                                                 GError             **error);

void         zeitgeist_log_install_monitor      (ZeitgeistLog        *self,
                                                 ZeitgeistMonitor    *monitor);

void         zeitgeist_log_remove_monitor       (ZeitgeistLog        *self,
                                                 ZeitgeistMonitor    *monitor);

gboolean     zeitgeist_log_is_connected         (ZeitgeistLog *self);

void         zeitgeist_log_get_version          (ZeitgeistLog *self,
                                                 gint *major,
                                                 gint *minor,
                                                 gint *micro);

G_END_DECLS

#endif /* _ZEITGEIST_LOG_H_ */
