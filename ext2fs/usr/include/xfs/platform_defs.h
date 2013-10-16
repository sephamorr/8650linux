/* include/platform_defs.h.  Generated from platform_defs.h.in by configure.  */
/*
 * Copyright (c) 2000-2005 Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it would be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write the Free Software Foundation,
 * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * @configure_input@
 */
#ifndef __XFS_PLATFORM_DEFS_H__
#define __XFS_PLATFORM_DEFS_H__

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/types.h>
#include <limits.h>

#define HAVE___U32 1
#ifdef HAVE___U32
#include <asm/types.h>
#else
typedef unsigned char		__u8;
typedef signed char		__s8;
typedef unsigned short		__u16;
typedef signed short		__s16;
typedef unsigned int		__u32;
typedef signed int		__s32;
typedef unsigned long long int	__u64;
typedef signed long long int	__s64;
#endif

#ifdef __CHECKER__
#define __bitwise		__attribute__((bitwise))
#define __force			__attribute__((force))
#else
#define __bitwise
#define __force
#endif

typedef __u16	__bitwise	__be16;
typedef __u32	__bitwise	__be32;
typedef __u64	__bitwise	__be64;

typedef struct filldir		filldir_t;

#if defined(__linux__)
#include <xfs/linux.h>
#elif defined(__FreeBSD__)
#include <xfs/freebsd.h>
#elif defined(__FreeBSD_kernel__)
#include <xfs/gnukfreebsd.h>
#elif defined(__APPLE__)
#include <xfs/darwin.h>
#elif defined(__sgi__) || defined(__sgi)
#include <xfs/irix.h>
#else
# error unknown platform... have fun porting!
#endif

/* long and pointer must be either 32 bit or 64 bit */
#define SIZEOF_LONG 4
#define SIZEOF_CHAR_P 4
#define BITS_PER_LONG (SIZEOF_LONG * CHAR_BIT)

/* Check if __psint_t is set to something meaningful */
/* #undef HAVE___PSINT_T */
#ifndef HAVE___PSINT_T
# if (SIZEOF_CHAR_P * CHAR_BIT) == 32
typedef int __psint_t;
# elif (SIZEOF_CHAR_P * CHAR_BIT) == 64
#  if BITS_PER_LONG == 64
typedef long __psint_t;
#  else
/* This is a very strange architecture, which has 64 bit pointers but */
/* not 64 bit longs.  So, just punt here and assume long long is OK.  */
typedef long long __psint_t;
#  endif
# else
#  error Unknown pointer size
# endif
#endif

/* Check if __psunsigned_t is set to something meaningful */
/* #undef HAVE___PSUNSIGNED_T */
#ifndef HAVE___PSUNSIGNED_T
# if (SIZEOF_CHAR_P * CHAR_BIT) == 32
typedef unsigned int __psunsigned_t;
# elif (SIZEOF_CHAR_P * CHAR_BIT) == 64
#  if BITS_PER_LONG == 64
typedef long __psunsigned_t;
#  else
/* This is a very strange architecture, which has 64 bit pointers but */
/* not 64 bit longs.  So, just punt here and assume long long is OK.  */
typedef unsigned long long __psunsigned_t;
#  endif
# else
#  error Unknown pointer size
# endif
#endif

/* Define if you want gettext (I18N) support */
/* #undef ENABLE_GETTEXT */
#ifdef ENABLE_GETTEXT
# include <libintl.h>
# define _(x)                   gettext(x)
# define N_(x)			 x
#else
# define _(x)                   (x)
# define N_(x)			 x
# define textdomain(d)          do { } while (0)
# define bindtextdomain(d,dir)  do { } while (0)
#endif
#include <locale.h>

#ifdef DEBUG
# define ASSERT(EX)	assert(EX)
#else
# define ASSERT(EX)	((void) 0)
#endif

/*
 * sparse kernel source annotations
 */
#ifndef __user
#define __user
#endif

#define IRIX_DEV_BITSMAJOR      14
#define IRIX_DEV_BITSMINOR      18
#define IRIX_DEV_MAXMAJ         0x1ff
#define IRIX_DEV_MAXMIN         0x3ffff
#define IRIX_DEV_MAJOR(dev)	((int)(((unsigned)(dev) >> IRIX_DEV_BITSMINOR) \
					& IRIX_DEV_MAXMAJ))
#define IRIX_DEV_MINOR(dev)	((int)((dev) & IRIX_DEV_MAXMIN))
#define IRIX_MKDEV(major,minor)	((xfs_dev_t)(((major) << IRIX_DEV_BITSMINOR) \
					| (minor&IRIX_DEV_MAXMIN)))
#define IRIX_DEV_TO_KDEVT(dev)	makedev(IRIX_DEV_MAJOR(dev),IRIX_DEV_MINOR(dev))

/* ARM old ABI has some weird alignment/padding */
#if defined(__arm__) && !defined(__ARM_EABI__)
#define __arch_pack __attribute__((packed))
#else
#define __arch_pack
#endif

#endif	/* __XFS_PLATFORM_DEFS_H__ */
