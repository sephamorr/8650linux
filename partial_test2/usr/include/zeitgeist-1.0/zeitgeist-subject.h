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

#ifndef _ZEITGEIST_SUBJECT_H_
#define _ZEITGEIST_SUBJECT_H_

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

#define ZEITGEIST_TYPE_SUBJECT (zeitgeist_subject_get_type ())

#define ZEITGEIST_SUBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
        ZEITGEIST_TYPE_SUBJECT, ZeitgeistSubject))
        
#define ZEITGEIST_SUBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), \
        ZEITGEIST_TYPE_SUBJECT, ZeitgeistSubjectClass))
        
#define ZEITGEIST_IS_SUBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
        ZEITGEIST_TYPE_SUBJECT))
        
#define ZEITGEIST_IS_SUBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), \
        ZEITGEIST_TYPE_SUBJECT))
        
#define ZEITGEIST_SUBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), \
        ZEITGEIST_TYPE_SUBJECT, ZeitgeistSubjectClass))

typedef struct _ZeitgeistSubject ZeitgeistSubject;
typedef struct _ZeitgeistSubjectClass ZeitgeistSubjectClass;

struct _ZeitgeistSubjectClass
{
  GInitiallyUnownedClass parent_class;
};


struct _ZeitgeistSubject
{
  GInitiallyUnowned parent_instance;
};

GType        zeitgeist_subject_get_type           (void);

ZeitgeistSubject* zeitgeist_subject_new           (void);

ZeitgeistSubject* zeitgeist_subject_new_full      (const gchar *uri,
                                                   const gchar *interpretation,
                                                   const gchar *manifestation,
                                                   const gchar *mimetype,
                                                   const gchar *origin,
                                                   const gchar *text,
                                                   const gchar *storage);

const gchar* zeitgeist_subject_get_uri            (ZeitgeistSubject *subject);
void         zeitgeist_subject_set_uri            (ZeitgeistSubject *subject,
                                                   const gchar*      uri);
                                        
const gchar* zeitgeist_subject_get_interpretation (ZeitgeistSubject *subject);
void         zeitgeist_subject_set_interpretation (ZeitgeistSubject *subject, 
                                                   const gchar      *interpretation);
                                        
const gchar* zeitgeist_subject_get_manifestation  (ZeitgeistSubject *subject);
void         zeitgeist_subject_set_manifestation  (ZeitgeistSubject *subject, 
                                                   const gchar      *manifestation);
                                
const gchar* zeitgeist_subject_get_mimetype       (ZeitgeistSubject *subject);
void         zeitgeist_subject_set_mimetype       (ZeitgeistSubject *subject, 
                                                   const gchar      *mimetype);
                                
const gchar* zeitgeist_subject_get_origin         (ZeitgeistSubject *subject);
void         zeitgeist_subject_set_origin         (ZeitgeistSubject *subject,
                                                   const gchar      *origin);
                                
const gchar* zeitgeist_subject_get_text           (ZeitgeistSubject *subject);
void         zeitgeist_subject_set_text           (ZeitgeistSubject *subject,
                                                   const gchar      *text);

const gchar* zeitgeist_subject_get_storage        (ZeitgeistSubject *subject);
void         zeitgeist_subject_set_storage        (ZeitgeistSubject *subject,
                                                   const gchar      *storage);

const gchar* zeitgeist_subject_get_current_uri    (ZeitgeistSubject *subject);
void         zeitgeist_subject_set_current_uri    (ZeitgeistSubject *subject,
                                                   const gchar      *current_uri);

G_END_DECLS

#endif /* _ZEITGEIST_SUBJECT_H_ */
