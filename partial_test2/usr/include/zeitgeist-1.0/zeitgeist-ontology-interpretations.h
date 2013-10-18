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

#ifndef _ZEITGEIST_ONTOLOGY_INTERPRETATIONS_H_
#define _ZEITGEIST_ONTOLOGY_INTERPRETATIONS_H_

/**
 * SECTION:zeitgeist-ontology-interpretations
 * @short_description: Helper macros for declaring interpretation types
 *                     for both events and subjects
 * @include: zeitgeist.h
 *
 * 
 */

/* IMPORTANT: AUTO GENERATED CONTENT BELOW HERE */

/**
 * ZEITGEIST_NCAL_ALARM:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Alarm">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;Alarm</ulink>
 *
 *	Provide a grouping of component properties that define an alarm.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCAL_ALARM "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Alarm"

/**
 * ZEITGEIST_NCAL_CALENDAR:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Calendar">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;Calendar</ulink>
 *
 *	A calendar. Inspirations for this class can be traced to the VCALENDAR component defined in RFC 2445 sec. 4.4, but it may just as well be used to represent any kind of Calendar.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCAL_CALENDAR "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Calendar"

/**
 * ZEITGEIST_NCAL_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Event">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;Event</ulink>
 *
 *	Provide a grouping of component properties that describe an event.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCAL_EVENT "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Event"

/**
 * ZEITGEIST_NCAL_FREEBUSY:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Freebusy">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;Freebusy</ulink>
 *
 *	Provide a grouping of component properties that describe either a request for free/busy time, describe a response to a request for free/busy time or describe a published set of busy time.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCAL_FREEBUSY "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Freebusy"

/**
 * ZEITGEIST_NCAL_JOURNAL:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Journal">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;Journal</ulink>
 *
 *	Provide a grouping of component properties that describe a journal entry.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCAL_JOURNAL "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Journal"

/**
 * ZEITGEIST_NCAL_TIMEZONE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Timezone">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;Timezone</ulink>
 *
 *	Provide a grouping of component properties that defines a time zone.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCAL_TIMEZONE "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Timezone"

/**
 * ZEITGEIST_NCAL_TODO:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Todo">http://www.semanticdesktop.org/ontologies/2007/04/02/ncal&num;Todo</ulink>
 *
 *	Provide a grouping of calendar properties that describe a to-do.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCAL_TODO "http://www.semanticdesktop.org/ontologies/2007/04/02/ncal#Todo"

/**
 * ZEITGEIST_NCO_CONTACT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nco#Contact">http://www.semanticdesktop.org/ontologies/2007/03/22/nco&num;Contact</ulink>
 *
 *	A Contact. A piece of data that can provide means to identify or communicate with an entity.
 *
 * Children: #ZEITGEIST_NCO_PERSON_CONTACT, #ZEITGEIST_NCO_ORGANIZATION_CONTACT
 *
 * Parents: None
 */
#define ZEITGEIST_NCO_CONTACT "http://www.semanticdesktop.org/ontologies/2007/03/22/nco#Contact"

/**
 * ZEITGEIST_NCO_CONTACT_GROUP:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactGroup">http://www.semanticdesktop.org/ontologies/2007/03/22/nco&num;ContactGroup</ulink>
 *
 *	A group of Contacts. Could be used to express a group in an addressbook or on a contact list of an IM application. One contact can belong to many groups.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCO_CONTACT_GROUP "http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactGroup"

/**
 * ZEITGEIST_NCO_CONTACT_LIST:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactList">http://www.semanticdesktop.org/ontologies/2007/03/22/nco&num;ContactList</ulink>
 *
 *	A contact list, this class represents an addressbook or a contact list of an IM application. Contacts inside a contact list can belong to contact groups.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NCO_CONTACT_LIST "http://www.semanticdesktop.org/ontologies/2007/03/22/nco#ContactList"

/**
 * ZEITGEIST_NCO_ORGANIZATION_CONTACT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact">http://www.semanticdesktop.org/ontologies/2007/03/22/nco&num;OrganizationContact</ulink>
 *
 *	A Contact that denotes on Organization.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NCO_CONTACT
 */
#define ZEITGEIST_NCO_ORGANIZATION_CONTACT "http://www.semanticdesktop.org/ontologies/2007/03/22/nco#OrganizationContact"

/**
 * ZEITGEIST_NCO_PERSON_CONTACT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PersonContact">http://www.semanticdesktop.org/ontologies/2007/03/22/nco&num;PersonContact</ulink>
 *
 *	A Contact that denotes a Person. A person can have multiple Affiliations.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NCO_CONTACT
 */
#define ZEITGEIST_NCO_PERSON_CONTACT "http://www.semanticdesktop.org/ontologies/2007/03/22/nco#PersonContact"

/**
 * ZEITGEIST_NFO_APPLICATION:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Application">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Application</ulink>
 *
 *	An application.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_SOFTWARE
 */
#define ZEITGEIST_NFO_APPLICATION "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Application"

/**
 * ZEITGEIST_NFO_ARCHIVE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Archive</ulink>
 *
 *	A compressed file. May contain other files or folder inside.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_DATA_CONTAINER
 */
#define ZEITGEIST_NFO_ARCHIVE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Archive"

/**
 * ZEITGEIST_NFO_AUDIO:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Audio">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Audio</ulink>
 *
 *	A file containing audio content.
 *
 * Children: #ZEITGEIST_NMM_MUSIC_PIECE
 *
 * Parents: #ZEITGEIST_NFO_MEDIA
 */
#define ZEITGEIST_NFO_AUDIO "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Audio"

/**
 * ZEITGEIST_NFO_BOOKMARK:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Bookmark">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Bookmark</ulink>
 *
 *	A bookmark of a webbrowser. Use nie:title for the name/label, nie:contentCreated to represent the date when the user added the bookmark, and nie:contentLastModified for modifications. nfo:bookmarks to store the link.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_BOOKMARK "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Bookmark"

/**
 * ZEITGEIST_NFO_BOOKMARK_FOLDER:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#BookmarkFolder">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;BookmarkFolder</ulink>
 *
 *	A folder with bookmarks of a webbrowser. Use nfo:containsBookmark to relate Bookmarks. Folders can contain subfolders, use containsBookmarkFolder to relate them.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_BOOKMARK_FOLDER "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#BookmarkFolder"

/**
 * ZEITGEIST_NFO_CURSOR:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Cursor">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Cursor</ulink>
 *
 *	A Cursor.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_RASTER_IMAGE
 */
#define ZEITGEIST_NFO_CURSOR "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Cursor"

/**
 * ZEITGEIST_NFO_DATA_CONTAINER:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#DataContainer">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;DataContainer</ulink>
 *
 *	A superclass for all entities, whose primary purpose is to serve as containers for other data object. They usually don't have any "meaning" by themselves. Examples include folders, archives and optical disc images.
 *
 * Children: #ZEITGEIST_NFO_FILESYSTEM, #ZEITGEIST_NFO_ARCHIVE, #ZEITGEIST_NFO_FOLDER, #ZEITGEIST_NFO_TRASH
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_DATA_CONTAINER "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#DataContainer"

/**
 * ZEITGEIST_NFO_DOCUMENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Document">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Document</ulink>
 *
 *	A generic document. A common superclass for all documents on the desktop.
 *
 * Children: #ZEITGEIST_NFO_TEXT_DOCUMENT, #ZEITGEIST_NFO_PRESENTATION, #ZEITGEIST_NFO_MIND_MAP, #ZEITGEIST_NFO_SPREADSHEET
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_DOCUMENT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Document"

/**
 * ZEITGEIST_NFO_EXECUTABLE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Executable">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Executable</ulink>
 *
 *	An executable file.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_EXECUTABLE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Executable"

/**
 * ZEITGEIST_NFO_FILESYSTEM:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Filesystem</ulink>
 *
 *	A filesystem. Examples of filesystems include hard disk partitions, removable media, but also images thereof stored in files such as ISO.
 *
 * Children: #ZEITGEIST_NFO_FILESYSTEM_IMAGE
 *
 * Parents: #ZEITGEIST_NFO_DATA_CONTAINER
 */
#define ZEITGEIST_NFO_FILESYSTEM "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Filesystem"

/**
 * ZEITGEIST_NFO_FILESYSTEM_IMAGE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;FilesystemImage</ulink>
 *
 *	An image of a filesystem. Instances of this class may include CD images, DVD images or hard disk partition images created by various pieces of software (e.g. Norton Ghost). Deprecated in favor of nfo:Filesystem.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_FILESYSTEM
 */
#define ZEITGEIST_NFO_FILESYSTEM_IMAGE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#FilesystemImage"

/**
 * ZEITGEIST_NFO_FOLDER:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Folder">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Folder</ulink>
 *
 *	A folder/directory. Examples of folders include folders on a filesystem and message folders in a mailbox.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_DATA_CONTAINER
 */
#define ZEITGEIST_NFO_FOLDER "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Folder"

/**
 * ZEITGEIST_NFO_FONT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Font">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Font</ulink>
 *
 *	A font.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_FONT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Font"

/**
 * ZEITGEIST_NFO_HTML_DOCUMENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;HtmlDocument</ulink>
 *
 *	A HTML document, may contain links to other files.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_PLAIN_TEXT_DOCUMENT
 */
#define ZEITGEIST_NFO_HTML_DOCUMENT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#HtmlDocument"

/**
 * ZEITGEIST_NFO_ICON:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Icon">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Icon</ulink>
 *
 *	An Icon (regardless of whether it's a raster or a vector icon. A resource representing an icon could have two types (Icon and Raster, or Icon and Vector) if required.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_IMAGE
 */
#define ZEITGEIST_NFO_ICON "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Icon"

/**
 * ZEITGEIST_NFO_IMAGE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Image">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Image</ulink>
 *
 *	A file containing an image.
 *
 * Children: #ZEITGEIST_NFO_ICON, #ZEITGEIST_NFO_VECTOR_IMAGE, #ZEITGEIST_NFO_RASTER_IMAGE
 *
 * Parents: #ZEITGEIST_NFO_VISUAL
 */
#define ZEITGEIST_NFO_IMAGE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Image"

/**
 * ZEITGEIST_NFO_MEDIA:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Media">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Media</ulink>
 *
 *	A piece of media content. This class may be used to express complex media containers with many streams of various media content (both aural and visual).
 *
 * Children: #ZEITGEIST_NFO_VISUAL, #ZEITGEIST_NFO_AUDIO
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_MEDIA "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Media"

/**
 * ZEITGEIST_NFO_MEDIA_LIST:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaList">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;MediaList</ulink>
 *
 *	A file containing a list of media files.e.g. a playlist.
 *
 * Children: #ZEITGEIST_NMM_MUSIC_ALBUM
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_MEDIA_LIST "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MediaList"

/**
 * ZEITGEIST_NFO_MIND_MAP:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MindMap">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;MindMap</ulink>
 *
 *	A MindMap, created by a mind-mapping utility. Examples might include FreeMind or mind mapper.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_DOCUMENT
 */
#define ZEITGEIST_NFO_MIND_MAP "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#MindMap"

/**
 * ZEITGEIST_NFO_OPERATING_SYSTEM:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#OperatingSystem">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;OperatingSystem</ulink>
 *
 *	An OperatingSystem.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_SOFTWARE
 */
#define ZEITGEIST_NFO_OPERATING_SYSTEM "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#OperatingSystem"

/**
 * ZEITGEIST_NFO_PAGINATED_TEXT_DOCUMENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;PaginatedTextDocument</ulink>
 *
 *	A file containing a text document, that is unambiguously divided into pages. Examples might include PDF, DOC, PS, DVI etc.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_TEXT_DOCUMENT
 */
#define ZEITGEIST_NFO_PAGINATED_TEXT_DOCUMENT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PaginatedTextDocument"

/**
 * ZEITGEIST_NFO_PLAIN_TEXT_DOCUMENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;PlainTextDocument</ulink>
 *
 *	A file containing plain text (ASCII, Unicode or other encodings). Examples may include TXT, HTML, XML, program source code etc.
 *
 * Children: #ZEITGEIST_NFO_SOURCE_CODE, #ZEITGEIST_NFO_HTML_DOCUMENT
 *
 * Parents: #ZEITGEIST_NFO_TEXT_DOCUMENT
 */
#define ZEITGEIST_NFO_PLAIN_TEXT_DOCUMENT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#PlainTextDocument"

/**
 * ZEITGEIST_NFO_PRESENTATION:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Presentation">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Presentation</ulink>
 *
 *	A Presentation made by some presentation software (Corel Presentations, OpenOffice Impress, MS Powerpoint etc.).
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_DOCUMENT
 */
#define ZEITGEIST_NFO_PRESENTATION "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Presentation"

/**
 * ZEITGEIST_NFO_RASTER_IMAGE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RasterImage">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;RasterImage</ulink>
 *
 *	A raster image.
 *
 * Children: #ZEITGEIST_NFO_CURSOR
 *
 * Parents: #ZEITGEIST_NFO_IMAGE
 */
#define ZEITGEIST_NFO_RASTER_IMAGE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#RasterImage"

/**
 * ZEITGEIST_NFO_SOFTWARE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Software">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Software</ulink>
 *
 *	A piece of software. Examples may include applications and the operating system. This interpretation most commonly applies to SoftwareItems.
 *
 * Children: #ZEITGEIST_NFO_APPLICATION, #ZEITGEIST_NFO_OPERATING_SYSTEM
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_SOFTWARE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Software"

/**
 * ZEITGEIST_NFO_SOURCE_CODE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;SourceCode</ulink>
 *
 *	Code in a compilable or interpreted programming language.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_PLAIN_TEXT_DOCUMENT
 */
#define ZEITGEIST_NFO_SOURCE_CODE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#SourceCode"

/**
 * ZEITGEIST_NFO_SPREADSHEET:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Spreadsheet">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Spreadsheet</ulink>
 *
 *	A spreadsheet, created by a spreadsheet application. Examples might include Gnumeric, OpenOffice Calc or MS Excel.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_DOCUMENT
 */
#define ZEITGEIST_NFO_SPREADSHEET "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Spreadsheet"

/**
 * ZEITGEIST_NFO_TEXT_DOCUMENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#TextDocument">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;TextDocument</ulink>
 *
 *	A text document.
 *
 * Children: #ZEITGEIST_NFO_PAGINATED_TEXT_DOCUMENT, #ZEITGEIST_NFO_PLAIN_TEXT_DOCUMENT
 *
 * Parents: #ZEITGEIST_NFO_DOCUMENT
 */
#define ZEITGEIST_NFO_TEXT_DOCUMENT "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#TextDocument"

/**
 * ZEITGEIST_NFO_TRASH:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Trash">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Trash</ulink>
 *
 *	Represents a container for deleted files, a feature common in modern operating systems.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_DATA_CONTAINER
 */
#define ZEITGEIST_NFO_TRASH "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Trash"

/**
 * ZEITGEIST_NFO_VECTOR_IMAGE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#VectorImage">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;VectorImage</ulink>
 *
 *	.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_IMAGE
 */
#define ZEITGEIST_NFO_VECTOR_IMAGE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#VectorImage"

/**
 * ZEITGEIST_NFO_VIDEO:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Video">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Video</ulink>
 *
 *	A video file.
 *
 * Children: #ZEITGEIST_NMM_TVSHOW, #ZEITGEIST_NMM_MOVIE
 *
 * Parents: #ZEITGEIST_NFO_VISUAL
 */
#define ZEITGEIST_NFO_VIDEO "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Video"

/**
 * ZEITGEIST_NFO_VISUAL:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Visual">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Visual</ulink>
 *
 *	File containing visual content.
 *
 * Children: #ZEITGEIST_NFO_IMAGE, #ZEITGEIST_NFO_VIDEO
 *
 * Parents: #ZEITGEIST_NFO_MEDIA
 */
#define ZEITGEIST_NFO_VISUAL "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Visual"

/**
 * ZEITGEIST_NFO_WEBSITE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Website">http://www.semanticdesktop.org/ontologies/2007/03/22/nfo&num;Website</ulink>
 *
 *	A website, usually a container for remote resources, that may be interpreted as HTMLDocuments, images or other types of content.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NFO_WEBSITE "http://www.semanticdesktop.org/ontologies/2007/03/22/nfo#Website"

/**
 * ZEITGEIST_NMM_MOVIE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie">http://www.semanticdesktop.org/ontologies/2009/02/19/nmm&num;Movie</ulink>
 *
 *	A Movie.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_VIDEO
 */
#define ZEITGEIST_NMM_MOVIE "http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#Movie"

/**
 * ZEITGEIST_NMM_MUSIC_ALBUM:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum">http://www.semanticdesktop.org/ontologies/2009/02/19/nmm&num;MusicAlbum</ulink>
 *
 *	The music album as provided by the publisher. Not to be confused with media lists or collections.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_MEDIA_LIST
 */
#define ZEITGEIST_NMM_MUSIC_ALBUM "http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicAlbum"

/**
 * ZEITGEIST_NMM_MUSIC_PIECE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece">http://www.semanticdesktop.org/ontologies/2009/02/19/nmm&num;MusicPiece</ulink>
 *
 *	Used to assign music-specific properties such a BPM to video and audio.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_AUDIO
 */
#define ZEITGEIST_NMM_MUSIC_PIECE "http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#MusicPiece"

/**
 * ZEITGEIST_NMM_TVSERIES:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVSeries">http://www.semanticdesktop.org/ontologies/2009/02/19/nmm&num;TVSeries</ulink>
 *
 *	A TV Series has multiple seasons and episodes.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NMM_TVSERIES "http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVSeries"

/**
 * ZEITGEIST_NMM_TVSHOW:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow">http://www.semanticdesktop.org/ontologies/2009/02/19/nmm&num;TVShow</ulink>
 *
 *	A TV Show.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NFO_VIDEO
 */
#define ZEITGEIST_NMM_TVSHOW "http://www.semanticdesktop.org/ontologies/2009/02/19/nmm#TVShow"

/**
 * ZEITGEIST_NMO_EMAIL:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#Email">http://www.semanticdesktop.org/ontologies/2007/03/22/nmo&num;Email</ulink>
 *
 *	An email.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NMO_MESSAGE
 */
#define ZEITGEIST_NMO_EMAIL "http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#Email"

/**
 * ZEITGEIST_NMO_IMMESSAGE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#IMMessage">http://www.semanticdesktop.org/ontologies/2007/03/22/nmo&num;IMMessage</ulink>
 *
 *	A message sent with Instant Messaging software.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_NMO_MESSAGE
 */
#define ZEITGEIST_NMO_IMMESSAGE "http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#IMMessage"

/**
 * ZEITGEIST_NMO_MAILBOX:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#Mailbox">http://www.semanticdesktop.org/ontologies/2007/03/22/nmo&num;Mailbox</ulink>
 *
 *	A mailbox - container for MailboxDataObjects.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NMO_MAILBOX "http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#Mailbox"

/**
 * ZEITGEIST_NMO_MESSAGE:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#Message">http://www.semanticdesktop.org/ontologies/2007/03/22/nmo&num;Message</ulink>
 *
 *	A message. Could be an email, instant messanging message, SMS message etc.
 *
 * Children: #ZEITGEIST_NMO_EMAIL, #ZEITGEIST_NMO_IMMESSAGE
 *
 * Parents: None
 */
#define ZEITGEIST_NMO_MESSAGE "http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#Message"

/**
 * ZEITGEIST_NMO_MIME_ENTITY:
 *
 * Macro defining the interpretation type <ulink url="http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#MimeEntity">http://www.semanticdesktop.org/ontologies/2007/03/22/nmo&num;MimeEntity</ulink>
 *
 *	A MIME entity, as defined in RFC2045, Section 2.4.
 *
 * Children: None
 *
 * Parents: None
 */
#define ZEITGEIST_NMO_MIME_ENTITY "http://www.semanticdesktop.org/ontologies/2007/03/22/nmo#MimeEntity"

/**
 * ZEITGEIST_ZG_ACCEPT_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#AcceptEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;AcceptEvent</ulink>
 *
 *	Event triggered when the user accepts a request of some sort. Examples could be answering a phone call, accepting a file transfer, or accepting a friendship request over an IM protocol. See also DenyEvent for when the user denies a similar request.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_ACCEPT_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#AcceptEvent"

/**
 * ZEITGEIST_ZG_ACCESS_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#AccessEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;AccessEvent</ulink>
 *
 *	Event triggered by opening, accessing, or starting a resource. Most zg:AccessEvents will have an accompanying zg:LeaveEvent, but this need not always be the case.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_ACCESS_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#AccessEvent"

/**
 * ZEITGEIST_ZG_CREATE_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#CreateEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;CreateEvent</ulink>
 *
 *	Event type triggered when an item is created.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_CREATE_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#CreateEvent"

/**
 * ZEITGEIST_ZG_DELETE_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#DeleteEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;DeleteEvent</ulink>
 *
 *	Event triggered because a resource has been deleted or otherwise made permanently unavailable. Fx. when deleting a file. FIXME: How about when moving to trash?.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_DELETE_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#DeleteEvent"

/**
 * ZEITGEIST_ZG_DENY_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#DenyEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;DenyEvent</ulink>
 *
 *	Event triggered when the user denies a request of some sort. Examples could be rejecting a phone call, rejecting a file transfer, or denying a friendship request over an IM protocol. See also AcceptEvent for the converse event type.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_DENY_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#DenyEvent"

/**
 * ZEITGEIST_ZG_EVENT_INTERPRETATION:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#EventInterpretation">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;EventInterpretation</ulink>
 *
 *	Base class for event interpretations. Please do no instantiate directly, but use one of the sub classes. The interpretation of an event describes 'what happened' - fx. 'something was created' or 'something was accessed'.
 *
 * Children: #ZEITGEIST_ZG_DENY_EVENT, #ZEITGEIST_ZG_ACCESS_EVENT, #ZEITGEIST_ZG_EXPIRE_EVENT, #ZEITGEIST_ZG_LEAVE_EVENT, #ZEITGEIST_ZG_CREATE_EVENT, #ZEITGEIST_ZG_MOVE_EVENT, #ZEITGEIST_ZG_ACCEPT_EVENT, #ZEITGEIST_ZG_SEND_EVENT, #ZEITGEIST_ZG_MODIFY_EVENT, #ZEITGEIST_ZG_DELETE_EVENT, #ZEITGEIST_ZG_RECEIVE_EVENT
 *
 * Parents: None
 */
#define ZEITGEIST_ZG_EVENT_INTERPRETATION "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#EventInterpretation"

/**
 * ZEITGEIST_ZG_EXPIRE_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#ExpireEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;ExpireEvent</ulink>
 *
 *	Event triggered when something expires or times out. These types of events are normally not triggered by the user, but by the operating system or some external party. Examples are a recurring calendar item or task deadline that expires or a when the user fails to respond to an external request such as a phone call.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_EXPIRE_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#ExpireEvent"

/**
 * ZEITGEIST_ZG_LEAVE_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#LeaveEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;LeaveEvent</ulink>
 *
 *	Event triggered by closing, leaving, or stopping a resource. Most zg:LeaveEvents will be following a zg:Access event, but this need not always be the case.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_LEAVE_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#LeaveEvent"

/**
 * ZEITGEIST_ZG_MODIFY_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#ModifyEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;ModifyEvent</ulink>
 *
 *	Event triggered by modifying an existing resources. Fx. when editing and saving a file on disk or correcting a typo in the name of a contact.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_MODIFY_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#ModifyEvent"

/**
 * ZEITGEIST_ZG_MOVE_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#MoveEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;MoveEvent</ulink>
 *
 *	Event triggered when a resource has been moved from a location to another. Fx. moving a file from a folder to another.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_MOVE_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#MoveEvent"

/**
 * ZEITGEIST_ZG_RECEIVE_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#ReceiveEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;ReceiveEvent</ulink>
 *
 *	Event triggered when something is received from an external party. The event manifestation must be set according to the world view of the receiving party. Most often the item that is being received will be some sort of message - an email, instant message, or broadcasted media such as micro blogging.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_RECEIVE_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#ReceiveEvent"

/**
 * ZEITGEIST_ZG_SEND_EVENT:
 *
 * Macro defining the interpretation type <ulink url="http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#SendEvent">http://www.zeitgeist-project.com/ontologies/2010/01/27/zg&num;SendEvent</ulink>
 *
 *	Event triggered when something is send to an external party. The event manifestation must be set according to the world view of the sending party. Most often the item that is being send will be some sort of message - an email, instant message, or broadcasted media such as micro blogging.
 *
 * Children: None
 *
 * Parents: #ZEITGEIST_ZG_EVENT_INTERPRETATION
 */
#define ZEITGEIST_ZG_SEND_EVENT "http://www.zeitgeist-project.com/ontologies/2010/01/27/zg#SendEvent"


/* IMPORTANT: AUTO GENERATED CONTENT STOP */

#endif /* _ZEITGEIST_ONTOLOGY_INTERPRETATIONS_H_ */
