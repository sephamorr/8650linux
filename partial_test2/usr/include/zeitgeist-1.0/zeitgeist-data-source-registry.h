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

#ifndef _ZEITGEIST_DATA_SOURCE_REGISTRY_H_
#define _ZEITGEIST_DATA_SOURCE_REGISTRY_H_

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <zeitgeist-event.h>
#include <zeitgeist-enums.h>
#include <zeitgeist-data-source.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_DATA_SOURCE_REGISTRY         (zeitgeist_data_source_registry_get_type())
#define ZEITGEIST_DATA_SOURCE_REGISTRY(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), ZEITGEIST_TYPE_DATA_SOURCE_REGISTRY, ZeitgeistDataSourceRegistry))
#define ZEITGEIST_DATA_SOURCE_REGISTRY_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), ZEITGEIST_TYPE_DATA_SOURCE_REGISTRY, ZeitgeistDataSourceRegistryClass))
#define ZEITGEIST_DATA_SOURCE_REGISTRY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), ZEITGEIST_TYPE_DATA_SOURCE_REGISTRY, ZeitgeistDataSourceRegistryClass))
#define ZEITGEIST_IS_DATA_SOURCE_REGISTRY(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), ZEITGEIST_TYPE_DATA_SOURCE_REGISTRY))
#define ZEITGEIST_IS_DATA_SOURCE_REGISTRY_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), ZEITGEIST_TYPE_DATA_SOURCE_REGISTRY))

typedef struct _ZeitgeistDataSourceRegistry ZeitgeistDataSourceRegistry;
typedef struct _ZeitgeistDataSourceRegistryClass ZeitgeistDataSourceRegistryClass;

struct _ZeitgeistDataSourceRegistryClass
{
  GObjectClass parent_class;

  void (*source_registered)   (ZeitgeistDataSourceRegistry *registry,
                               ZeitgeistDataSource *source);
  void (*source_disconnected) (ZeitgeistDataSourceRegistry *registry,
                               ZeitgeistDataSource *source);
  void (*source_enabled)      (ZeitgeistDataSourceRegistry *registry,
                               gchar *unique_id,
                               gboolean enabled);
};


struct _ZeitgeistDataSourceRegistry
{
  GObject parent_instance;
};

GType        zeitgeist_data_source_registry_get_type  (void);

ZeitgeistDataSourceRegistry* zeitgeist_data_source_registry_new  (void);

void         zeitgeist_data_source_registry_get_data_sources  (
                                     ZeitgeistDataSourceRegistry *self,
                                     GCancellable                *cancellable,
                                     GAsyncReadyCallback          callback,
                                     gpointer                     user_data);

GPtrArray*   zeitgeist_data_source_registry_get_data_sources_finish (
                                     ZeitgeistDataSourceRegistry *self,
                                     GAsyncResult                *res,
                                     GError                     **error);

void         zeitgeist_data_source_registry_register_data_source (
                                     ZeitgeistDataSourceRegistry *self,
                                     ZeitgeistDataSource         *source,
                                     GCancellable                *cancellable,
                                     GAsyncReadyCallback          callback,
                                     gpointer                     user_data);

gboolean     zeitgeist_data_source_registry_register_data_source_finish (
                                     ZeitgeistDataSourceRegistry *self,
                                     GAsyncResult                *res,
                                     GError                     **error);

void         zeitgeist_data_source_registry_set_data_source_enabled (
                                     ZeitgeistDataSourceRegistry *self,
                                     const gchar                 *unique_id,
                                     gboolean                     enabled,
                                     GCancellable                *cancellable,
                                     GAsyncReadyCallback          callback,
                                     gpointer                     user_data);

gboolean     zeitgeist_data_source_registry_set_data_source_enabled_finish (
                                     ZeitgeistDataSourceRegistry *self,
                                     GAsyncResult                *res,
                                     GError                     **error);

G_END_DECLS

#endif /* _ZEITGEIST_DATA_SOURCE_REGISTRY_H_ */

