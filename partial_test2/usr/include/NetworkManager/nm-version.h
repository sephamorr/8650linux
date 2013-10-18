/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2011 Red Hat, Inc.
 */

#ifndef NM_VERSION_H
#define NM_VERSION_H

/**
 * NM_MAJOR_VERSION:
 *
 * Evaluates to the major version number of NetworkManager which this source
 * is compiled against.
 */
#define NM_MAJOR_VERSION (0)

/**
 * NM_MINOR_VERSION:
 *
 * Evaluates to the minor version number of NetworkManager which this source
 * is compiled against.
 */
#define NM_MINOR_VERSION (9)

/**
 * NM_MICRO_VERSION:
 *
 * Evaluates to the micro version number of NetworkManager which this source
 * compiled against.
 */
#define NM_MICRO_VERSION (4)

/**
 * NM_CHECK_VERSION:
 * @major: major version (e.g. 1 for version 1.2.5)
 * @minor: minor version (e.g. 2 for version 1.2.5)
 * @micro: micro version (e.g. 5 for version 1.2.5)
 *
 * Returns %TRUE if the version of the NetworkManager header files
 * is the same as or newer than the passed-in version.
 */
#define NM_CHECK_VERSION(major,minor,micro)                         \
    (NM_MAJOR_VERSION > (major) ||                                  \
     (NM_MAJOR_VERSION == (major) && NM_MINOR_VERSION > (minor)) || \
     (NM_MAJOR_VERSION == (major) && NM_MINOR_VERSION == (minor) && NM_MICRO_VERSION >= (micro)))

#endif  /* NM_VERSION_H */

