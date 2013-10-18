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

#ifndef _ZEITGEIST_DATA_SOURCE_H_
#define _ZEITGEIST_DATA_SOURCE_H_

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_DATA_SOURCE (zeitgeist_data_source_get_type ())

#define ZEITGEIST_DATA_SOURCE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
        ZEITGEIST_TYPE_DATA_SOURCE, ZeitgeistDataSource))
        
#define ZEITGEIST_DATA_SOURCE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), \
        ZEITGEIST_TYPE_DATA_SOURCE, ZeitgeistDataSourceClass))
        
#define ZEITGEIST_IS_DATA_SOURCE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
        ZEITGEIST_TYPE_DATA_SOURCE))
        
#define ZEITGEIST_IS_DATA_SOURCE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), \
        ZEITGEIST_TYPE_DATA_SOURCE))
        
#define ZEITGEIST_DATA_SOURCE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), \
        ZEITGEIST_TYPE_DATA_SOURCE, ZeitgeistDataSourceClass))

typedef struct _ZeitgeistDataSource ZeitgeistDataSource;
typedef struct _ZeitgeistDataSourceClass ZeitgeistDataSourceClass;

struct _ZeitgeistDataSourceClass
{
  GInitiallyUnownedClass parent_class;
};


struct _ZeitgeistDataSource
{
  GInitiallyUnowned parent_instance;
};

GType                zeitgeist_data_source_get_type       (void);

ZeitgeistDataSource* zeitgeist_data_source_new            (void);
ZeitgeistDataSource* zeitgeist_data_source_new_full       (const gchar *id,
                                                           const gchar *name,
                                                           const gchar *desc,
                                                           GPtrArray   *event_templates);

ZeitgeistDataSource* zeitgeist_data_source_new_from_variant (GVariant *src);

const gchar* zeitgeist_data_source_get_unique_id  (ZeitgeistDataSource *src);
void         zeitgeist_data_source_set_unique_id  (ZeitgeistDataSource *src,
                                                   const gchar* unique_id);
                                        
const gchar* zeitgeist_data_source_get_name (ZeitgeistDataSource *src);
void         zeitgeist_data_source_set_name (ZeitgeistDataSource *src,
                                             const gchar         *name);
                                        
const gchar* zeitgeist_data_source_get_description (ZeitgeistDataSource *src);
void         zeitgeist_data_source_set_description (ZeitgeistDataSource *src, 
                                                    const gchar *description);

GPtrArray*   zeitgeist_data_source_get_event_templates (ZeitgeistDataSource *src);
void         zeitgeist_data_source_set_event_templates (ZeitgeistDataSource *src,
                                                        GPtrArray *event_templates);

gboolean     zeitgeist_data_source_is_running  (ZeitgeistDataSource *src);
void         zeitgeist_data_source_set_running (ZeitgeistDataSource *src,
                                                gboolean running);

gint64        zeitgeist_data_source_get_timestamp (ZeitgeistDataSource *src);
void         zeitgeist_data_source_set_timestamp  (ZeitgeistDataSource *src,
                                                   gint64 timestamp);

gboolean     zeitgeist_data_source_is_enabled  (ZeitgeistDataSource *src);
void         zeitgeist_data_source_set_enabled (ZeitgeistDataSource *src,
                                                gboolean enabled);

GVariant*    zeitgeist_data_source_to_variant       (ZeitgeistDataSource *src);
GVariant*    zeitgeist_data_source_to_variant_full  (ZeitgeistDataSource *src);

GVariant*    zeitgeist_data_sources_to_variant  (GPtrArray *sources);

GPtrArray*   zeitgeist_data_sources_from_variant  (GVariant *sources);

/**
 * ZEITGEIST_DATA_SOURCE_VARIANT_SIGNATURE:
 *
 * The #GVariant signature for a serialized #ZeitgeistDataSource
 */
#define ZEITGEIST_DATA_SOURCE_VARIANT_SIGNATURE "(sssa(asaasay))"

/**
 * ZEITGEIST_DATA_SOURCE_VARIANT_TYPE:
 *
 * The #GVariantType of #ZEITGEIST_DATA_SOURCE_VARIANT_SIGNATURE
 */
#define ZEITGEIST_DATA_SOURCE_VARIANT_TYPE G_VARIANT_TYPE(ZEITGEIST_DATA_SOURCE_VARIANT_SIGNATURE)

/**
 * ZEITGEIST_DATA_SOURCE_WITH_INFO_VARIANT_SIGNATURE:
 *
 * The #GVariant signature for a serialized #ZeitgeistDataSource
 */
#define ZEITGEIST_DATA_SOURCE_WITH_INFO_VARIANT_SIGNATURE "(sssa(asaasay)bxb)"

/**
 * ZEITGEIST_DATA_SOURCE_WITH_INFO_VARIANT_TYPE:
 *
 * The #GVariantType of #ZEITGEIST_DATA_SOURCE_WITH_INFO_VARIANT_SIGNATURE
 */
#define ZEITGEIST_DATA_SOURCE_WITH_INFO_VARIANT_TYPE G_VARIANT_TYPE(ZEITGEIST_DATA_SOURCE_WITH_INFO_VARIANT_SIGNATURE)

G_END_DECLS

#endif /* _ZEITGEIST_DATA_SOURCE_H_ */
