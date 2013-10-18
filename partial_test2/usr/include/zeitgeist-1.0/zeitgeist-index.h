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

#ifndef _ZEITGEIST_INDEX_H_
#define _ZEITGEIST_INDEX_H_

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <zeitgeist-event.h>
#include <zeitgeist-enums.h>
#include <zeitgeist-index.h>
#include <zeitgeist-result-set.h>
#include <zeitgeist-timerange.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_INDEX          (zeitgeist_index_get_type())
#define ZEITGEIST_INDEX(o)            (G_TYPE_CHECK_INSTANCE_CAST ((o), ZEITGEIST_TYPE_INDEX, ZeitgeistIndex))
#define ZEITGEIST_INDEX_CLASS(k)      (G_TYPE_CHECK_CLASS_CAST((k), ZEITGEIST_TYPE_INDEX, ZeitgeistIndexClass))
#define ZEITGEIST_INDEX_GET_CLASS(o)  (G_TYPE_INSTANCE_GET_CLASS ((o), ZEITGEIST_TYPE_INDEX, ZeitgeistIndexClass))
#define ZEITGEIST_IS_INDEX(o)         (G_TYPE_CHECK_INSTANCE_TYPE ((o), ZEITGEIST_TYPE_INDEX))
#define ZEITGEIST_IS_INDEX_CLASS(k)   (G_TYPE_CHECK_CLASS_TYPE ((k), ZEITGEIST_TYPE_INDEX))

typedef struct _ZeitgeistIndex ZeitgeistIndex;
typedef struct _ZeitgeistIndexClass ZeitgeistIndexClass;

struct _ZeitgeistIndexClass
{
  GObjectClass parent_class;
};


struct _ZeitgeistIndex
{
  GObject parent_instance;
};

GType           zeitgeist_index_get_type        (void);

ZeitgeistIndex* zeitgeist_index_new             (void);

void            zeitgeist_index_search          (ZeitgeistIndex        *self,
                                                 const gchar           *query,
                                                 ZeitgeistTimeRange    *time_range,
                                                 GPtrArray             *event_templates,
                                                 guint32                offset,
                                                 guint32                num_events,
                                                 ZeitgeistResultType    result_type,
                                                 GCancellable          *cancellable,
                                                 GAsyncReadyCallback    callback,
                                                 gpointer               user_data);

ZeitgeistResultSet*
                zeitgeist_index_search_finish  (ZeitgeistIndex      *self,
                                                GAsyncResult        *res,
                                                GError             **error);

void            zeitgeist_index_search_with_relevancies
                                               (ZeitgeistIndex       *self,
                                                const gchar          *query,
                                                ZeitgeistTimeRange   *time_range,
                                                GPtrArray            *event_templates,
                                                ZeitgeistStorageState storage_state,
                                                guint32               offset,
                                                guint32               num_events,
                                                ZeitgeistResultType   result_type,
                                                GCancellable         *cancellable,
                                                GAsyncReadyCallback   callback,
                                                gpointer              user_data);

ZeitgeistResultSet*
                zeitgeist_index_search_with_relevancies_finish 
                                               (ZeitgeistIndex      *self,
                                                GAsyncResult        *res,
                                                gdouble            **relevancies,
                                                gint                *relevancies_size,
                                                GError             **error);

G_END_DECLS

#endif /* _ZEITGEIST_INDEX_H_ */
