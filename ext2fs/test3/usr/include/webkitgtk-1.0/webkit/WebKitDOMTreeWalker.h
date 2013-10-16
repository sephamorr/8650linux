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

#ifndef WebKitDOMTreeWalker_h
#define WebKitDOMTreeWalker_h

#include "webkit/webkitdomdefines.h"
#include <glib-object.h>
#include <webkit/webkitdefines.h>
#include "webkit/WebKitDOMObject.h"


G_BEGIN_DECLS
#define WEBKIT_TYPE_DOM_TREE_WALKER            (webkit_dom_tree_walker_get_type())
#define WEBKIT_DOM_TREE_WALKER(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), WEBKIT_TYPE_DOM_TREE_WALKER, WebKitDOMTreeWalker))
#define WEBKIT_DOM_TREE_WALKER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass),  WEBKIT_TYPE_DOM_TREE_WALKER, WebKitDOMTreeWalkerClass)
#define WEBKIT_DOM_IS_TREE_WALKER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), WEBKIT_TYPE_DOM_TREE_WALKER))
#define WEBKIT_DOM_IS_TREE_WALKER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),  WEBKIT_TYPE_DOM_TREE_WALKER))
#define WEBKIT_DOM_TREE_WALKER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj),  WEBKIT_TYPE_DOM_TREE_WALKER, WebKitDOMTreeWalkerClass))

struct _WebKitDOMTreeWalker {
    WebKitDOMObject parent_instance;
};

struct _WebKitDOMTreeWalkerClass {
    WebKitDOMObjectClass parent_class;
};

WEBKIT_API GType
webkit_dom_tree_walker_get_type (void);

/**
 * webkit_dom_tree_walker_parent_node:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_parent_node(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_first_child:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_first_child(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_last_child:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_last_child(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_previous_sibling:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_previous_sibling(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_next_sibling:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_next_sibling(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_previous_node:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_previous_node(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_next_node:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_next_node(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_get_root:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_get_root(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_get_what_to_show:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns:
 *
**/
WEBKIT_API gulong
webkit_dom_tree_walker_get_what_to_show(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_get_filter:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNodeFilter*
webkit_dom_tree_walker_get_filter(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_get_expand_entity_references:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns:
 *
**/
WEBKIT_API gboolean
webkit_dom_tree_walker_get_expand_entity_references(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_get_current_node:
 * @self: A #WebKitDOMTreeWalker
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API WebKitDOMNode*
webkit_dom_tree_walker_get_current_node(WebKitDOMTreeWalker* self);

/**
 * webkit_dom_tree_walker_set_current_node:
 * @self: A #WebKitDOMTreeWalker
 * @value: A #WebKitDOMNode
 * @error: #GError
 *
 * Returns: (transfer none):
 *
**/
WEBKIT_API void
webkit_dom_tree_walker_set_current_node(WebKitDOMTreeWalker* self, WebKitDOMNode* value, GError **error);

G_END_DECLS

#endif /* WebKitDOMTreeWalker_h */
