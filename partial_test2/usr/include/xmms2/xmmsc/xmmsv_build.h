/*  XMMS2 - X Music Multiplexer System
 *  Copyright (C) 2003-2011 XMMS2 Team
 *
 *  PLUGINS ARE NOT CONSIDERED TO BE DERIVED WORK !!!
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 */


#ifndef __XMMSV_BUILD_H__
#define __XMMSV_BUILD_H__

#include "xmmsc/xmmsv_general.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup BuildValueType Easier building of lists and dictionaries
 * @ingroup ValueType
 * @{
 */
/* These helps us doing compiletime typechecking */
static inline const char *__xmmsv_identity_const_charp (const char *v) {return v;}
static inline xmmsv_t *__xmmsv_identity_xmmsv (xmmsv_t *v) {return v;}
static inline xmmsv_t *__xmmsv_null_to_none (xmmsv_t *v) { return v ? v : xmmsv_new_none (); }

#define XMMSV_DICT_ENTRY(k, v) __xmmsv_identity_const_charp (k), __xmmsv_identity_xmmsv (v)
#define XMMSV_DICT_ENTRY_STR(k, v) XMMSV_DICT_ENTRY (k, __xmmsv_null_to_none (xmmsv_new_string (v)))
#define XMMSV_DICT_ENTRY_INT(k, v) XMMSV_DICT_ENTRY (k, xmmsv_new_int (v))
#define XMMSV_DICT_END NULL
xmmsv_t *xmmsv_build_dict (const char *firstkey, ...);

#define XMMSV_LIST_ENTRY(v) __xmmsv_identity_xmmsv (v)
#define XMMSV_LIST_ENTRY_STR(v) XMMSV_LIST_ENTRY (__xmmsv_null_to_none (xmmsv_new_string (v)))
#define XMMSV_LIST_ENTRY_INT(v) XMMSV_LIST_ENTRY (xmmsv_new_int (v))
#define XMMSV_LIST_ENTRY_COLL(v) XMMSV_LIST_ENTRY (__xmmsv_null_to_none (xmmsv_new_coll (v)))
#define XMMSV_LIST_END NULL

xmmsv_t *xmmsv_build_list (xmmsv_t *first_entry, ...);
xmmsv_t *xmmsv_build_list_va (xmmsv_t *first_entry, va_list ap);
/** @} */

#ifdef __cplusplus
}
#endif

#endif
