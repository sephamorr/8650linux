/*
 * Copyright (c) 2002-2010 BalaBit IT Ltd, Budapest, Hungary
 * Copyright (c) 1998-2010 Balázs Scheidler
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As an additional exemption you are allowed to compile & link against the
 * OpenSSL libraries as published by the OpenSSL project. See the file
 * COPYING for details.
 *
 */
  
#ifndef APPHOOK_H_INCLUDED
#define APPHOOK_H_INCLUDED

#include "syslog-ng.h"

/* this enum must be in the order the given events actually happen in time */
enum
{
  AH_STARTUP,
  AH_POST_DAEMONIZED,
  AH_PRE_CONFIG_LOADED,
  AH_POST_CONFIG_LOADED,
  AH_SHUTDOWN,
};

typedef void (*ApplicationHookFunc)(gint type, gpointer user_data);

void register_application_hook(gint type, ApplicationHookFunc func, gpointer user_data);
void app_startup();
void app_post_daemonized();
void app_pre_config_loaded();
void app_post_config_loaded();
void app_shutdown();

#endif
