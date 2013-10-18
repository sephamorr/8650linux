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

#ifndef _ZEITGEIST_MONITOR_H_
#define _ZEITGEIST_MONITOR_H_

#include <glib-object.h>
#include <zeitgeist-timerange.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_MONITOR          (zeitgeist_monitor_get_type())
#define ZEITGEIST_MONITOR(o)            (G_TYPE_CHECK_INSTANCE_CAST ((o), ZEITGEIST_TYPE_MONITOR, ZeitgeistMonitor))
#define ZEITGEIST_MONITOR_CLASS(k)      (G_TYPE_CHECK_CLASS_CAST((k), ZEITGEIST_TYPE_MONITOR, ZeitgeistMonitorClass))
#define ZEITGEIST_MONITOR_GET_CLASS(o)  (G_TYPE_INSTANCE_GET_CLASS ((o), ZEITGEIST_TYPE_MONITOR, ZeitgeistMonitorClass))
#define ZEITGEIST_IS_MONITOR(o)         (G_TYPE_CHECK_INSTANCE_TYPE ((o), ZEITGEIST_TYPE_MONITOR))
#define ZEITGEIST_IS_MONITOR_CLASS(k)   (G_TYPE_CHECK_CLASS_TYPE ((k), ZEITGEIST_TYPE_MONITOR))

typedef struct _ZeitgeistMonitor ZeitgeistMonitor;
typedef struct _ZeitgeistMonitorClass ZeitgeistMonitorClass;

struct _ZeitgeistMonitorClass
{
  GObjectClass parent_class;

  /*< signals >*/
  void (*events_inserted)  (ZeitgeistMonitor   *self,
                            ZeitgeistTimeRange *time_range,
                            GPtrArray          *events);

  void (*events_deleted)  (ZeitgeistMonitor   *self,
                           ZeitgeistTimeRange *time_range,
                           GArray             *event_ids);
};


struct _ZeitgeistMonitor
{
  GObject parent_instance;
};

GType               zeitgeist_monitor_get_type       ();

ZeitgeistMonitor*   zeitgeist_monitor_new            (ZeitgeistTimeRange *time_range,
                                                      GPtrArray          *event_templates);

ZeitgeistTimeRange* zeitgeist_monitor_get_time_range (ZeitgeistMonitor   *self);

GPtrArray*          zeitgeist_monitor_get_templates  (ZeitgeistMonitor   *self);

const gchar*        zeitgeist_monitor_get_path       (ZeitgeistMonitor   *self);

G_END_DECLS

#endif /* _ZEITGEIST_MONITOR_H_ */
