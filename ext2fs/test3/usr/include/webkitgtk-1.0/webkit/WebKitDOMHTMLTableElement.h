/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef WebKitDOMHTMLTableElement_h
#define WebKitDOMHTMLTableElement_h

#include "webkit/webkitdomdefines.h"
#include <glib-object.h>
#include <webkit/webkitdefines.h>
#include "webkit/WebKitDOMHTMLElement.h"


G_BEGIN_DECLS
#define WEBKIT_TYPE_DOM_HTML_TABLE_ELEMENT            (webkit_dom_html_table_element_get_type())
#define WEBKIT_DOM_HTML_TABLE_ELEMENT(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_HTML_TABLE_ELEMENT, WebKitDOMHTMLTableElement))
#define WEBKIT_DOM_HTML_TABLE_ELEMENT_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_HTML_TABLE_ELEMENT, WebKitDOMHTMLTableElementClass)
#define WEBKIT_DOM_IS_HTML_TABLE_ELEMENT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_HTML_TABLE_ELEMENT))
#define WEBKIT_DOM_IS_HTML_TABLE_ELEMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_HTML_TABLE_ELEMENT))
#define WEBKIT_DOM_HTML_TABLE_ELEMENT_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_HTML_TABLE_ELEMENT, WebKitDOMHTMLTableElementClass))

struct _WebKitDOMHTMLTableElement {
    WebKitDOMHTMLElement parent_instance;
};

struct _WebKitDOMHTMLTableElementClass {
    WebKitDOMHTMLElementClass parent_class;
};

WEBKIT_API GType
webkit_dom_html_table_element_get_type (void);

/**
 * webkit_dom_html_table_element_create_t_head:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLElement*
webkit_dom_html_table_element_create_t_head(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_delete_t_head:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_delete_t_head(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_create_t_foot:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLElement*
webkit_dom_html_table_element_create_t_foot(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_delete_t_foot:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_delete_t_foot(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_create_caption:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLElement*
webkit_dom_html_table_element_create_caption(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_delete_caption:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_delete_caption(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_insert_row:
 * @self: A #WebKitDOMHTMLTableElement
 * @index: A #glong
 * @error: #GError
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLElement*
webkit_dom_html_table_element_insert_row(WebKitDOMHTMLTableElement* self, glong index, GError **error);

/**
 * webkit_dom_html_table_element_delete_row:
 * @self: A #WebKitDOMHTMLTableElement
 * @index: A #glong
 * @error: #GError
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_delete_row(WebKitDOMHTMLTableElement* self, glong index, GError **error);

/**
 * webkit_dom_html_table_element_get_caption:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLTableCaptionElement*
webkit_dom_html_table_element_get_caption(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_caption:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #WebKitDOMHTMLTableCaptionElement
 * @error: #GError
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_caption(WebKitDOMHTMLTableElement* self, WebKitDOMHTMLTableCaptionElement* value, GError **error);

/**
 * webkit_dom_html_table_element_get_t_head:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLTableSectionElement*
webkit_dom_html_table_element_get_t_head(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_t_head:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #WebKitDOMHTMLTableSectionElement
 * @error: #GError
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_t_head(WebKitDOMHTMLTableElement* self, WebKitDOMHTMLTableSectionElement* value, GError **error);

/**
 * webkit_dom_html_table_element_get_t_foot:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLTableSectionElement*
webkit_dom_html_table_element_get_t_foot(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_t_foot:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #WebKitDOMHTMLTableSectionElement
 * @error: #GError
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_t_foot(WebKitDOMHTMLTableElement* self, WebKitDOMHTMLTableSectionElement* value, GError **error);

/**
 * webkit_dom_html_table_element_get_rows:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLCollection*
webkit_dom_html_table_element_get_rows(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_get_t_bodies:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMHTMLCollection*
webkit_dom_html_table_element_get_t_bodies(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_get_align:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_align(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_align:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_align(WebKitDOMHTMLTableElement* self, const gchar* value);

/**
 * webkit_dom_html_table_element_get_bg_color:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_bg_color(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_bg_color:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_bg_color(WebKitDOMHTMLTableElement* self, const gchar* value);

/**
 * webkit_dom_html_table_element_get_border:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_border(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_border:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_border(WebKitDOMHTMLTableElement* self, const gchar* value);

/**
 * webkit_dom_html_table_element_get_cell_padding:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_cell_padding(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_cell_padding:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_cell_padding(WebKitDOMHTMLTableElement* self, const gchar* value);

/**
 * webkit_dom_html_table_element_get_cell_spacing:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_cell_spacing(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_cell_spacing:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_cell_spacing(WebKitDOMHTMLTableElement* self, const gchar* value);

/**
 * webkit_dom_html_table_element_get_frame:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_frame(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_frame:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_frame(WebKitDOMHTMLTableElement* self, const gchar* value);

/**
 * webkit_dom_html_table_element_get_rules:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_rules(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_rules:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_rules(WebKitDOMHTMLTableElement* self, const gchar* value);

/**
 * webkit_dom_html_table_element_get_summary:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_summary(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_summary:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_summary(WebKitDOMHTMLTableElement* self, const gchar* value);

/**
 * webkit_dom_html_table_element_get_width:
 * @self: A #WebKitDOMHTMLTableElement
 *
 * Returns:
 *
**/
WEBKIT_API gchar*
webkit_dom_html_table_element_get_width(WebKitDOMHTMLTableElement* self);

/**
 * webkit_dom_html_table_element_set_width:
 * @self: A #WebKitDOMHTMLTableElement
 * @value: A #gchar
 *
 * Returns:
 *
**/
WEBKIT_API void
webkit_dom_html_table_element_set_width(WebKitDOMHTMLTableElement* self, const gchar* value);

G_END_DECLS

#endif /* WebKitDOMHTMLTableElement_h */
