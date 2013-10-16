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




#ifndef __XMMSCLIENT_GLIB_H__
#define __XMMSCLIENT_GLIB_H__

#include <glib.h>
#include "xmmsclient/xmmsclient.h"

#ifdef __cplusplus
extern "C" {
#endif

void *xmmsc_mainloop_gmain_init (xmmsc_connection_t *connection);
void xmmsc_mainloop_gmain_shutdown (xmmsc_connection_t *connection, void *udata);

#ifdef __cplusplus
}
#endif

#endif
