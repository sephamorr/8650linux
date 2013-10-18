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

#ifndef _ZEITGEIST_ONTOLOGY_MANIFESTATIONS_H_
#define _ZEITGEIST_ONTOLOGY_MANIFESTATIONS_H_

/**
 * SECTION:zeitgeist-ontology-manifestations
 * @short_description: Helper macros for declaring manifestation types
 *                     for both events and subjects
 * @include: zeitgeist.h
 *
 * 
 */

/* IMPORTANT: AUTO GENERATED CONTENT BELOW HERE */

/**
 * ZEITGEIST_NCAL_ATTACHMENT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Attachment">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;Attachment</ulink>
 *
 *	An object attached to a calendar entity. This class has been introduced to serve as a structured value of the ncal:attach property. See the documentation of ncal:attach for details.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_ATTACHMENT
 */
#define ZEITGEIST_NCAL_ATTACHMENT "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Attachment"

/**
 * ZEITGEIST_NCAL_CALENDAR_DATA_OBJECT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#CalendarDataObject">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;CalendarDataObject</ulink>
 *
 *	A DataObject found in a calendar. It is usually interpreted as one of the calendar entity types (e.g. Event, Journal, Todo etc.).
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCAL_CALENDAR_DATA_OBJECT "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#CalendarDataObject"

/**
 * ZEITGEIST_NCO_CONTACT_LIST_DATA_OBJECT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactListDataObject">http://www.semanticdesktop.org/ontologies/2007/03/22/nco&num;ContactListDataObject</ulink>
 *
 *	An entity occuring on a contact list (usually interpreted as an nco:Contact).
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCO_CONTACT_LIST_DATA_OBJECT "http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactListDataObject"

/**
 * ZEITGEIST_NFO_ARCHIVE_ITEM:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#ArchiveItem">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;ArchiveItem</ulink>
 *
 *	A file entity inside an archive.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_EMBEDDED_FILE_DATA_OBJECT
 */
#define ZEITGEIST_NFO_ARCHIVE_ITEM "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#ArchiveItem"

/**
 * ZEITGEIST_NFO_ATTACHMENT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Attachment</ulink>
 *
 *	A file attached to another data object. Many data formats allow for attachments: emails, vcards, ical events, id3 and exif.
 *
 * Children: #ZEITGEIST_NCAL_ATTACHMENT
 *
 * Parents: #ZEITGEIST_NFO_EMBEDDED_FILE_DATA_OBJECT
 */
#define ZEITGEIST_NFO_ATTACHMENT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Attachment"

/**
 * ZEITGEIST_NFO_DELETED_RESOURCE:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#DeletedResource">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;DeletedResource</ulink>
 *
 *	A file entity that has been deleted from the original source. Usually such entities are stored within various kinds of 'Trash' or 'Recycle Bin' folders.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_FILE_DATA_OBJECT
 */
#define ZEITGEIST_NFO_DELETED_RESOURCE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#DeletedResource"

/**
 * ZEITGEIST_NFO_EMBEDDED_FILE_DATA_OBJECT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;EmbeddedFileDataObject</ulink>
 *
 *	A file embedded in another data object. There are many ways in which a file may be embedded in another one. Use this class directly only in cases if none of the subclasses gives a better description of your case.
 *
 * Children: #ZEITGEIST_NFO_ARCHIVE_ITEM, #ZEITGEIST_NFO_ATTACHMENT
 *
 * Parents: #ZEITGEIST_NFO_FILE_DATA_OBJECT
 */
#define ZEITGEIST_NFO_EMBEDDED_FILE_DATA_OBJECT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#EmbeddedFileDataObject"

/**
 * ZEITGEIST_NFO_FILE_DATA_OBJECT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FileDataObject">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;FileDataObject</ulink>
 *
 *	A resource containing a finite sequence of bytes with arbitrary information, that is available to a computer program and is usually based on some kind of durable storage. A file is durable in the sense that it remains available for programs to use after the current program has finished.
 *
 * Children: #ZEITGEIST_NFO_EMBEDDED_FILE_DATA_OBJECT, #ZEITGEIST_NFO_DELETED_RESOURCE, #ZEITGEIST_NFO_REMOTE_DATA_OBJECT
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_FILE_DATA_OBJECT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FileDataObject"

/**
 * ZEITGEIST_NFO_HARD_DISK_PARTITION:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HardDiskPartition">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;HardDiskPartition</ulink>
 *
 *	A partition on a hard disk.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_HARD_DISK_PARTITION "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HardDiskPartition"

/**
 * ZEITGEIST_NFO_MEDIA_STREAM:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaStream">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;MediaStream</ulink>
 *
 *	A stream of multimedia content, usually contained within a media container such as a movie (containing both audio and video) or a DVD (possibly containing many streams of audio and video). Most common interpretations for such a DataObject include Audio and Video.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_MEDIA_STREAM "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaStream"

/**
 * ZEITGEIST_NFO_REMOTE_DATA_OBJECT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemoteDataObject">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;RemoteDataObject</ulink>
 *
 *	A file data object stored at a remote location. Don't confuse this class with a RemotePortAddress. This one applies to a particular resource, RemotePortAddress applies to an address, that can have various interpretations.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_FILE_DATA_OBJECT
 */
#define ZEITGEIST_NFO_REMOTE_DATA_OBJECT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemoteDataObject"

/**
 * ZEITGEIST_NFO_REMOTE_PORT_ADDRESS:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemotePortAddress">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;RemotePortAddress</ulink>
 *
 *	An address specifying a remote host and port. Such an address can be interpreted in many ways (examples of such interpretations include mailboxes, websites, remote calendars or filesystems), depending on an interpretation, various kinds of data may be extracted from such an address.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_REMOTE_PORT_ADDRESS "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RemotePortAddress"

/**
 * ZEITGEIST_NFO_SOFTWARE_ITEM:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareItem">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;SoftwareItem</ulink>
 *
 *	A DataObject representing a piece of software. Examples of interpretations of a SoftwareItem include an Application and an OperatingSystem.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_SOFTWARE_ITEM "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareItem"

/**
 * ZEITGEIST_NFO_SOFTWARE_SERVICE:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareService">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;SoftwareService</ulink>
 *
 *	A service published by a piece of software, either by an operating system or an application. Examples of such services may include calendar, addressbook and mailbox managed by a PIM application. This category is introduced to distinguish between data available directly from the applications (Via some Interprocess Communication Mechanisms) and data available from files on a disk. In either case both DataObjects would receive a similar interpretation (e.g. a Mailbox) and wouldn't differ on the content level.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_SOFTWARE_SERVICE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SoftwareService"

/**
 * ZEITGEIST_NFO_WEB_DATA_OBJECT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#WebDataObject">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;WebDataObject</ulink>
 *
 *	An information resources of which representations (files, streams) can be retrieved through a web server. They may be generated at retrieval time. Typical examples are pages served by PHP or AJAX or mp3 streams.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_WEB_DATA_OBJECT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#WebDataObject"

/**
 * ZEITGEIST_NMO_MAILBOX_DATA_OBJECT:
 *
 * Macro defining the manifestation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#MailboxDataObject">http://www.semanticdesktop.org/ontologies/2007/03/22/nmo&num;MailboxDataObject</ulink>
 *
 *	An entity encountered in a mailbox. Most common interpretations for such an entity include Message or Folder.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NMO_MAILBOX_DATA_OBJECT "http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#MailboxDataObject"

/**
 * ZEITGEIST_ZG_EVENT_MANIFESTATION:
 *
 * Macro defining the manifestation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#EventManifestation">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;EventManifestation</ulink>
 *
 *	Base class for event manifestation types. Please do no instantiate directly, but use one of the sub classes. The manifestation of an event describes 'how it happened'. Fx. 'the user did this' or 'the system notified the user'.
 *
 * Children: #ZEITGEIST_ZG_USER_ACTIVITY, #ZEITGEIST_ZG_SYSTEM_NOTIFICATION, #ZEITGEIST_ZG_HEURISTIC_ACTIVITY, #ZEITGEIST_ZG_SCHEDULED_ACTIVITY, #ZEITGEIST_ZG_WORLD_ACTIVITY
 *
 * Parents: None
 */
#define ZEITGEIST_ZG_EVENT_MANIFESTATION "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#EventManifestation"

/**
 * ZEITGEIST_ZG_HEURISTIC_ACTIVITY:
 *
 * Macro defining the manifestation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#HeuristicActivity">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;HeuristicActivity</ulink>
 *
 *	An event that is caused indirectly from user activity or deducted via analysis of other events. Fx. if an algorithm divides a user workflow into disjoint 'projects' based on temporal analysis it could insert heuristic events when the user changed project.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_MANIFESTATION
 */
#define ZEITGEIST_ZG_HEURISTIC_ACTIVITY "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#HeuristicActivity"

/**
 * ZEITGEIST_ZG_SCHEDULED_ACTIVITY:
 *
 * Macro defining the manifestation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#ScheduledActivity">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;ScheduledActivity</ulink>
 *
 *	An event that was directly triggered by some user initiated sequence of actions. For example a music player automatically changing to the next song in a playlist.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_MANIFESTATION
 */
#define ZEITGEIST_ZG_SCHEDULED_ACTIVITY "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#ScheduledActivity"

/**
 * ZEITGEIST_ZG_SYSTEM_NOTIFICATION:
 *
 * Macro defining the manifestation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#SystemNotification">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;SystemNotification</ulink>
 *
 *	An event send to the user by the operating system. Examples could include when the user inserts a USB stick or when the system warns that the hard disk is full.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_MANIFESTATION
 */
#define ZEITGEIST_ZG_SYSTEM_NOTIFICATION "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#SystemNotification"

/**
 * ZEITGEIST_ZG_USER_ACTIVITY:
 *
 * Macro defining the manifestation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#UserActivity">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;UserActivity</ulink>
 *
 *	An event that was actively performed by the user. For example saving or opening a file by clicking on it in the file manager.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_MANIFESTATION
 */
#define ZEITGEIST_ZG_USER_ACTIVITY "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#UserActivity"

/**
 * ZEITGEIST_ZG_WORLD_ACTIVITY:
 *
 * Macro defining the manifestation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#WorldActivity">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;WorldActivity</ulink>
 *
 *	An event that was performed by an entity, usually human or organization, other than the user. An example could be logging the activities of other people in a team.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_MANIFESTATION
 */
#define ZEITGEIST_ZG_WORLD_ACTIVITY "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#WorldActivity"


/* IMPORTANT: AUTO GENERATED CONTENT STOP */

#endif /* _ZEITGEIST_ONTOLOGY_MANIFESTATIONS_H_ */
