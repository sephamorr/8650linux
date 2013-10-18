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

#ifndef _ZEITGEIST_RESULT_SET_H_
#define _ZEITGEIST_RESULT_SET_H_

#include <glib.h>
#include <glib-object.h>
#include <zeitgeist-event.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_RESULT_SET (zeitgeist_result_set_get_type ())

#define ZEITGEIST_RESULT_SET(obj) \
        (G_TYPE_CHECK_INSTANCE_CAST ((obj), ZEITGEIST_TYPE_RESULT_SET, ZeitgeistResultSet))

#define ZEITGEIST_IS_RESULT_SET(obj) \
       (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ZEITGEIST_TYPE_RESULT_SET))

#define ZEITGEIST_RESULT_SET_GET_IFACE(obj) \
       (G_TYPE_INSTANCE_GET_INTERFACE(obj, zeitgeist_result_set_get_type (), ZeitgeistResultSetIface))

typedef struct _ZeitgeistResultSetIface ZeitgeistResultSetIface;
typedef struct _ZeitgeistResultSet ZeitgeistResultSet;


struct _ZeitgeistResultSetIface
{
  GTypeInterface g_iface;

  /*< public >*/
  guint           (*size)              (ZeitgeistResultSet *self);

  guint           (*estimated_matches) (ZeitgeistResultSet *self);

  ZeitgeistEvent* (*next)              (ZeitgeistResultSet *self);

  gboolean        (*has_next)          (ZeitgeistResultSet *self);
  
  ZeitgeistEvent* (*peek)              (ZeitgeistResultSet *self);

  void            (*seek)              (ZeitgeistResultSet *self,
                                        guint               pos);

  guint           (*tell)              (ZeitgeistResultSet *self);
};

GType           zeitgeist_result_set_get_type          (void) G_GNUC_CONST;

guint           zeitgeist_result_set_size              (ZeitgeistResultSet *self);

guint           zeitgeist_result_set_estimated_matches (ZeitgeistResultSet *self);

ZeitgeistEvent* zeitgeist_result_set_next              (ZeitgeistResultSet *self);

gboolean        zeitgeist_result_set_has_next          (ZeitgeistResultSet *self);

ZeitgeistEvent* zeitgeist_result_set_peek              (ZeitgeistResultSet *self);

void            zeitgeist_result_set_seek              (ZeitgeistResultSet *self,
                                                        guint               pos);

guint           zeitgeist_result_set_tell              (ZeitgeistResultSet *self);

#define _vala_zeitgeist_result_set_next_value(rs) (zeitgeist_result_set_has_next(rs) ? zeitgeist_result_set_next(rs) : NULL)
#define _vala_zeitgeist_result_set_iterator(rs) ((ZeitgeistResultSet*)g_object_ref(rs))

G_END_DECLS

#endif /* _HAVE_ZEITGEIST_RESULT_SET_H */
