/*
 * libcryptsetup - cryptsetup library
 *
 * Copyright (C) 2004, Christophe Saout <christophe@saout.de>
 * Copyright (C) 2004-2007, Clemens Fruhwirth <clemens@endorphin.org>
 * Copyright (C) 2009-2012, Red Hat, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * @file libcryptsetup.h
 * @brief Public cryptsetup API
 *
 * For more verbose examples of LUKS related use cases,
 * please read @ref index "examples".
 */

#ifndef _LIBCRYPTSETUP_H
#define _LIBCRYPTSETUP_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct crypt_device; /* crypt device handle */

/**
 * Initialize crypt device handle and check if provided device exists.
 *
 * @param cd Returns pointer to crypt device handle
 * @param device Path to the backing device.
 * 	  If @e device is not a block device but a path to some file,
 * 	  the function will try to create a loopdevice and attach
 * 	  the file to the loopdevice with AUTOCLEAR flag set.
 * 	  If @e device is @e NULL function it will initialize dm backend only.
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @note Note that logging is not initialized here, possible messages uses
 * 	 default log function.
 */
int crypt_init(struct crypt_device **cd, const char *device);

/**
 * Initialize crypt device handle from provided active device name,
 * and, optionally, from separate metadata (header) device
 * and check if provided device exists.
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @param cd returns crypt device handle for active device
 * @param name name of active crypt device
 * @param header_device optional device containing on-disk header
 * 	  (@e NULL if it the same as underlying device on there is no on-disk header)
 *
 * @post In case @e device points to active LUKS device but header load fails,
 * context device type is set to @e NULL and @e 0 is returned as if it were successful.
 * Context with @e NULL device type can only be deactivated by crypt_deactivate
 *
 * @note @link crypt_init_by_name @endlink is equivalent to calling
 * 	 crypt_init_by_name_and_header(cd, name, NULL);
 */
int crypt_init_by_name_and_header(struct crypt_device **cd,
				  const char *name,
				  const char *header_device);

/**
 * This is equivalent to call
 * @ref crypt_init_by_name_and_header "crypt_init_by_name_and_header(cd, name, NULL)"
 *
 * @sa crypt_init_by_name_and_header
 */
int crypt_init_by_name(struct crypt_device **cd, const char *name);

/**
 * @defgroup loglevel "Cryptsetup logging"
 *
 * Set of functions and defines used in cryptsetup for
 * logging purposes
 *
 */

/**
 * @addtogroup loglevel
 * @{
 */

/** normal log level */
#define CRYPT_LOG_NORMAL 0
/** error log level */
#define CRYPT_LOG_ERROR  1
/** verbose log level */
#define CRYPT_LOG_VERBOSE  2
/** debug log level - always on stdout */
#define CRYPT_LOG_DEBUG -1

/**
 * Set log function.
 *
 * @param cd crypt device handle (can be @e NULL to set default log function)
 * @param log user defined log function reference
 * @param usrptr provided identification in callback
 * @param level log level below (debug messages can uses other levels)
 * @param msg log message
 */
void crypt_set_log_callback(struct crypt_device *cd,
	void (*log)(int level, const char *msg, void *usrptr),
	void *usrptr);

/**
 * Defines log function or use the default one otherwise.
 *
 * @see crypt_set_log_callback
 *
 * @param cd crypt device handle
 * @param level log level
 * @param msg log message
 */
void crypt_log(struct crypt_device *cd, int level, const char *msg);
/** @} */

/**
 * Set confirmation callback (yes/no)
 *
 * If code need confirmation (like resetting uuid or restoring LUKS header from file)
 * this function is called. If not defined, everything is confirmed.
 *
 * Callback function @e confirm should return @e 0 if operation is declined,
 * other values mean accepted.
 *
 * @param cd crypt device handle
 * @param confirm user defined confirm callback reference
 * @param usrptr provided identification in callback
 * @param msg Message for user to confirm
 *
 * @note Current version of cryptsetup API requires confirmation only when UUID is being changed
 */
void crypt_set_confirm_callback(struct crypt_device *cd,
	int (*confirm)(const char *msg, void *usrptr),
	void *usrptr);

/**
 * Set password query callback.
 *
 * If code need @e _interactive_ query for password, this callback is called.
 * If not defined, compiled-in default is called (uses terminal input).
 *
 * Callback should return length of password in buffer
 * or negative errno value in case of error.
 *
 * @param cd crypt device handle
 * @param password user defined password callback reference
 * @param usrptr provided identification in callback
 * @param msg Message for user
 * @param buf buffer for password
 * @param length size of buffer
 *
 * @note Note that if this function is defined, verify option is ignored
 *   (caller which provided callback is responsible for password verification)
 * @note Only zero terminated passwords can be entered this way, for complex
 *   use API functions directly.
 * @note Maximal length of password is limited to @e length @e - @e 1 (minimal 511 chars)
 *
 * @see Callback function is used in these call provided, that certain conditions are met:
 * @li crypt_keyslot_add_by_passphrase
 * @li crypt_activate_by_passphrase
 * @li crypt_resume_by_passphrase
 * @li crypt_resume_by_keyfile
 * @li crypt_keyslot_add_by_keyfile
 * @li crypt_keyslot_add_by_volume_key
 *
 */
void crypt_set_password_callback(struct crypt_device *cd,
	int (*password)(const char *msg, char *buf, size_t length, void *usrptr),
	void *usrptr);

/**
 * Set timeout for interactive password entry using default
 * password callback
 *
 * @param cd crypt device handle
 * @param timeout_sec timeout in seconds
 */
void crypt_set_timeout(struct crypt_device *cd, uint64_t timeout_sec);

/**
 * Set number of retries in case password input has been incorrect
 *
 * @param cd crypt device handle
 * @param tries the number
 */
void crypt_set_password_retry(struct crypt_device *cd, int tries);

/**
 * Set how long should cryptsetup iterate in PBKDF2 function.
 * Default value heads towards the iterations which takes around 1 second
 *
 * @param cd crypt device handle
 * @param iteration_time_ms the time in ms
 */
void crypt_set_iteration_time(struct crypt_device *cd, uint64_t iteration_time_ms);
/* Don't ask :-) */
void crypt_set_iterarion_time(struct crypt_device *cd, uint64_t iteration_time_ms);

/**
 * Set whether passphrase will be verified on input
 * (user has to input same passphrase twice)
 *
 * @param cd crypt device handle
 * @param password_verify @e 0 = false, @e !0 true
 */
void crypt_set_password_verify(struct crypt_device *cd, int password_verify);

/**
 * Set data device (encrypted payload area device) if LUKS header is separated
 *
 * @param cd crypt device handle
 * @param device path to device
 *
 * @pre context is of LUKS type
 * @pre unlike @ref crypt_init, in this function param @e device
 * 	has to be block device (at least 512B large)
 */
int crypt_set_data_device(struct crypt_device *cd, const char *device);

/**
 * @defgroup rng "Cryptsetup RNG"
 *
 * @addtogroup rng
 * @{
 *
 */

/** CRYPT_RNG_URANDOM - use /dev/urandom */
#define CRYPT_RNG_URANDOM 0
/** CRYPT_RNG_RANDOM  - use /dev/random (waits if no entropy in system) */
#define CRYPT_RNG_RANDOM  1

/**
 * Set which RNG (random number generator) is used for generating long term key
 *
 * @param cd crypt device handle
 * @param rng_type kernel random number generator to use
 *
 */
void crypt_set_rng_type(struct crypt_device *cd, int rng_type);

/**
 * Get which RNG (random number generator) is used for generating long term key
 *
 * @param cd crypt device handle
 * @return RNG type on success or negative errno value otherwise.
 *
 */
int crypt_get_rng_type(struct crypt_device *cd);

/** @} */

/**
 * Helper to lock/unlock memory to avoid swap sensitive data to disk
 *
 * @param cd crypt device handle, can be @e NULL
 * @param lock 0 to unlock otherwise lock memory
 *
 * @returns Value indicating whether the memory is locked (function can be called multiple times).
 *
 * @note Only root can do this.
 * @note It locks/unlocks all process memory, not only crypt context.
 */
int crypt_memory_lock(struct crypt_device *cd, int lock);

/**
 * @defgroup crypt_type "Cryptsetup on-disk format types"
 *
 * Set of functions, \#defines and structs related
 * to on-disk format types
 */

/**
 * @addtogroup crypt_type
 * @{
 */

/** regular crypt device, no on-disk header */
#define CRYPT_PLAIN "PLAIN"
/** LUKS version 1 header on-disk */
#define CRYPT_LUKS1 "LUKS1"
/** loop-AES compatibility mode */
#define CRYPT_LOOPAES "LOOPAES"

/**
 * Get device type
 *
 * @param cd crypt device handle
 * @return string according to device type or @e NULL if not known.
 */
const char *crypt_get_type(struct crypt_device *cd);

/**
 *
 * Structure used as parameter for PLAIN device type
 *
 * @see crypt_format
 */
struct crypt_params_plain {
	const char *hash; /**< password hash function */
	uint64_t offset; /**< offset in sectors */
	uint64_t skip; /**< IV offset / initialization sector */
	uint64_t size; /**< size of mapped device or @e 0 for autodetection */
};

/**
 * Structure used as parameter for LUKS device type
 *
 * @see crypt_format, crypt_load
 *
 * @note during crypt_format @e data_device attribute determines
 * 	 if the LUKS header is separated from encrypted payload device
 *
 */
struct crypt_params_luks1 {
	const char *hash; /**< hash used in LUKS header */
	size_t data_alignment; /**< data alignment in sectors, data offset is multiple of this */
	const char *data_device; /**< detached encrypted data device or @e NULL */
};

/**
 *
 * Structure used as parameter for loop-AES device type
 *
 * @see crypt_format
 *
 */
struct crypt_params_loopaes {
	const char *hash; /**< key hash function */
	uint64_t offset;  /**< offset in sectors */
	uint64_t skip;    /**< IV offset / initialization sector */
};

/** @} */

/**
 * Create (format) new crypt device (and possible header on-disk) but not activates it.
 *
 * @pre @e cd contains initialized and not formatted device context (device type must @b not be set)
 *
 * @param cd crypt device handle
 * @param type type of device (optional params struct must be of this type)
 * @param cipher (e.g. "aes")
 * @param cipher_mode including IV specification (e.g. "xts-plain")
 * @param uuid requested UUID or @e NULL if it should be generated
 * @param volume_key pre-generated volume key or @e NULL if it should be generated (only for LUKS)
 * @param volume_key_size size of volume key in bytes.
 * @param params crypt type specific parameters (see @link crypt_type @endlink)
 *
 * @returns @e 0 on success or negative errno value otherwise.
 *
 * @note Note that crypt_format does not enable any keyslot (in case of work with LUKS device), but it stores volume key internally
 * 	 and subsequent crypt_keyslot_add_* calls can be used.
 */
int crypt_format(struct crypt_device *cd,
	const char *type,
	const char *cipher,
	const char *cipher_mode,
	const char *uuid,
	const char *volume_key,
	size_t volume_key_size,
	void *params);

/**
 * Set new UUID for already existing device
 *
 * @param cd crypt device handle
 * @param uuid requested UUID or @e NULL if it should be generated
 *
 * @returns 0 on success or negative errno value otherwise.
 *
 * @note Currently, only LUKS device type are supported
 */
int crypt_set_uuid(struct crypt_device *cd,
		   const char *uuid);

/**
 * Load crypt device parameters from on-disk header
 *
 * @param cd crypt device handle
 * @param requested_type - use @e NULL for all known
 * @param params crypt type specific parameters (see @link crypt_type @endlink)
 *
 * @returns 0 on success or negative errno value otherwise.
 *
 * @post In case LUKS header is read successfully but payload device is too small
 * error is returned and device type in context is set to @e NULL
 *
 * @note Note that in current version load works only for LUKS device type
 *
 */
int crypt_load(struct crypt_device *cd,
	       const char *requested_type,
	       void *params);

/**
 * Try to repair crypt device on-disk header if invalid
 *
 * @param cd crypt device handle
 * @param requested_type - use @e NULL for all known
 * @param params crypt type specific parameters (see @link crypt_type @endlink)
 *
 * @returns 0 on success or negative errno value otherwise.
 *
 */
int crypt_repair(struct crypt_device *cd,
		 const char *requested_type,
		 void *params __attribute__((unused)));

/**
 * Resize crypt device
 *
 * @param cd - crypt device handle
 * @param name - name of device to resize
 * @param new_size - new device size in sectors or @e 0 to use all of the underlying device size
 *
 * @return @e 0 on success or negative errno value otherwise.
 */
int crypt_resize(struct crypt_device *cd,
		 const char *name,
		 uint64_t new_size);

/**
 * Suspends crypt device.
 *
 * @param cd crypt device handle, can be @e NULL
 * @param name name of device to suspend
 *
 * @return 0 on success or negative errno value otherwise.
 *
 * @note Only LUKS device type is supported
 *
 */
int crypt_suspend(struct crypt_device *cd,
		  const char *name);

/**
 * Resumes crypt device using passphrase.
 *
 *
 * @param cd crypt device handle
 * @param name name of device to resume
 * @param keyslot requested keyslot or CRYPT_ANY_SLOT
 * @param passphrase passphrase used to unlock volume key, @e NULL for query
 * @param passphrase_size size of @e passphrase (binary data)
 *
 * @return unlocked key slot number or negative errno otherwise.
 *
 * @note Only LUKS device type is supported
 */
int crypt_resume_by_passphrase(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *passphrase,
	size_t passphrase_size);

/**
 * Resumes crypt device using key file.
 *
 * @param cd crypt device handle
 * @param name name of device to resume
 * @param keyslot requested keyslot or CRYPT_ANY_SLOT
 * @param keyfile key file used to unlock volume key, @e NULL for passphrase query
 * @param keyfile_size number of bytes to read from keyfile, 0 is unlimited
 * @param keyfile_offset number of bytes to skip at start of keyfile
 *
 * @return unlocked key slot number or negative errno otherwise.
 */
int crypt_resume_by_keyfile_offset(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	size_t keyfile_offset);
/**
 * Backward compatible crypt_resume_by_keyfile_offset() (without offset).
 */
int crypt_resume_by_keyfile(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size);

/**
 * Releases crypt device context and used memory.
 *
 * @param cd crypt device handle
 */
void crypt_free(struct crypt_device *cd);

/**
 * @defgroup keyslot "Cryptsetup LUKS keyslots"
 * @addtogroup keyslot
 * @{
 *
 */

/** iterate through all keyslots and find first one that fits */
#define CRYPT_ANY_SLOT -1

/**
 * Add key slot using provided passphrase
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot requested keyslot or @e CRYPT_ANY_SLOT
 * @param passphrase passphrase used to unlock volume key, @e NULL for query
 * @param passphrase_size size of passphrase (binary data)
 * @param new_passphrase passphrase for new keyslot, @e NULL for query
 * @param new_passphrase_size size of @e new_passphrase (binary data)
 *
 * @return allocated key slot number or negative errno otherwise.
 */
int crypt_keyslot_add_by_passphrase(struct crypt_device *cd,
	int keyslot,
	const char *passphrase,
	size_t passphrase_size,
	const char *new_passphrase,
	size_t new_passphrase_size);

/**
 * Get number of keyslots supported for device type.
 *
 * @param type crypt device type
 *
 * @return slot count or negative errno otherwise if device
 * doesn't not support keyslots.
 */
int crypt_keyslot_max(const char *type);

/**
* Add key slot using provided key file path
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot requested keyslot or @e CRYPT_ANY_SLOT
 * @param keyfile key file used to unlock volume key, @e NULL for passphrase query
 * @param keyfile_size number of bytes to read from keyfile, @e 0 is unlimited
 * @param keyfile_offset number of bytes to skip at start of keyfile
 * @param new_keyfile keyfile for new keyslot, @e NULL for passphrase query
 * @param new_keyfile_size number of bytes to read from @e new_keyfile, @e 0 is unlimited
 * @param new_keyfile_offset number of bytes to skip at start of new_keyfile
 *
 * @return allocated key slot number or negative errno otherwise.
 *
 * @note Note that @e keyfile can be "-" for STDIN
 *
 */
int crypt_keyslot_add_by_keyfile_offset(struct crypt_device *cd,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	size_t keyfile_offset,
	const char *new_keyfile,
	size_t new_keyfile_size,
	size_t new_keyfile_offset);
/**
 * Backward compatible crypt_keyslot_add_by_keyfile_offset() (without offset).
 */
int crypt_keyslot_add_by_keyfile(struct crypt_device *cd,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	const char *new_keyfile,
	size_t new_keyfile_size);

/**
 * Add key slot using provided volume key
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot requested keyslot or CRYPT_ANY_SLOT
 * @param volume_key provided volume key or @e NULL if used after crypt_format
 * @param volume_key_size size of volume_key
 * @param passphrase passphrase for new keyslot, @e NULL for query
 * @param passphrase_size size of passphrase
 *
 * @return allocated key slot number or negative errno otherwise.
 *
 */
int crypt_keyslot_add_by_volume_key(struct crypt_device *cd,
	int keyslot,
	const char *volume_key,
	size_t volume_key_size,
	const char *passphrase,
	size_t passphrase_size);

/**
 * Destroy (and disable) key slot
 *
 * @pre @e cd contains initialized and formatted LUKS device context
 *
 * @param cd crypt device handle
 * @param keyslot requested key slot to destroy
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @note Note that there is no passphrase verification used.
 */
int crypt_keyslot_destroy(struct crypt_device *cd, int keyslot);

/** @} */

/**
 * @defgroup aflags "Device runtime attributes"
 *
 * Activation flags
 *
 * @addtogroup aflags
 * @{
 *
 */
/** device is read only */
#define CRYPT_ACTIVATE_READONLY (1 << 0)
/** only reported for device without uuid */
#define CRYPT_ACTIVATE_NO_UUID  (1 << 1)
/** activate more non-overlapping mapping to the same device */
#define CRYPT_ACTIVATE_SHARED   (1 << 2)
/** enable discards aka TRIM */
#define CRYPT_ACTIVATE_ALLOW_DISCARDS (1 << 3)

/**
 * Active device runtime attributes
 */
struct crypt_active_device {
	uint64_t offset; /**< offset in sectors */
	uint64_t iv_offset; /**< IV initialization sector */
	uint64_t size; /**< active device size */
	uint32_t flags; /**< activation flags */
};

/**
 * Receives runtime attributes of active crypt device
 *
 * @param cd crypt device handle (can be @e NULL)
 * @param name name of active device
 * @param cad preallocated active device attributes to fill
 *
 * @return @e 0 on success or negative errno value otherwise
 *
 */
int crypt_get_active_device(struct crypt_device *cd,
			    const char *name,
			    struct crypt_active_device *cad);

/** @} */

/**
 * Activate device or check passphrase
 *
 * @param cd crypt device handle
 * @param name name of device to create, if @e NULL only check passphrase
 * @param keyslot requested keyslot to check or @e CRYPT_ANY_SLOT
 * @param passphrase passphrase used to unlock volume key, @e NULL for query
 * @param passphrase_size size of @e passphrase
 * @param flags activation flags
 *
 * @return unlocked key slot number or negative errno otherwise.
 */
int crypt_activate_by_passphrase(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *passphrase,
	size_t passphrase_size,
	uint32_t flags);

/**
 * Activate device or check using key file
 *
 * @param cd crypt device handle
 * @param name name of device to create, if @e NULL only check keyfile
 * @param keyslot requested keyslot to check or CRYPT_ANY_SLOT
 * @param keyfile key file used to unlock volume key
 * @param keyfile_size number of bytes to read from keyfile, 0 is unlimited
 * @param keyfile_offset number of bytes to skip at start of keyfile
 * @param flags activation flags
 *
 * @return unlocked key slot number or negative errno otherwise.
 */
int crypt_activate_by_keyfile_offset(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	size_t keyfile_offset,
	uint32_t flags);
/**
 * Backward compatible crypt_activate_by_keyfile_offset() (without offset).
 */
int crypt_activate_by_keyfile(struct crypt_device *cd,
	const char *name,
	int keyslot,
	const char *keyfile,
	size_t keyfile_size,
	uint32_t flags);

/**
 * Activate device using provided volume key
 *
 *
 * @param cd crypt device handle
 * @param name name of device to create, if @e NULL only check volume key
 * @param volume_key provided volume key (or @e NULL to use internal)
 * @param volume_key_size size of volume_key
 * @param flags activation flags
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 * @note If @e NULL is used for volume_key, device has to be initialized
 * 	 by previous operation (like @ref crypt_format
 * 	 or @ref crypt_init_by_name)
 */
int crypt_activate_by_volume_key(struct crypt_device *cd,
	const char *name,
	const char *volume_key,
	size_t volume_key_size,
	uint32_t flags);

/**
 * Deactivate crypt device. This function tries to remove active device-mapper
 * mapping from kernel. Also, sensitive data like the volume key are removed from
 * memory
 *
 * @param cd crypt device handle, can be @e NULL
 * @param name name of device to deactivate
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 */
int crypt_deactivate(struct crypt_device *cd, const char *name);

/**
 * Get volume key from of crypt device
 *
 * @param cd crypt device handle
 * @param keyslot use this keyslot or @e CRYPT_ANY_SLOT
 * @param volume_key buffer for volume key
 * @param volume_key_size on input, size of buffer @e volume_key,
 *        on output size of @e volume_key
 * @param passphrase passphrase used to unlock volume key
 * @param passphrase_size size of @e passphrase
 *
 * @return unlocked key slot number or negative errno otherwise.
 */
int crypt_volume_key_get(struct crypt_device *cd,
	int keyslot,
	char *volume_key,
	size_t *volume_key_size,
	const char *passphrase,
	size_t passphrase_size);

/**
 * Verify that provided volume key is valid for crypt device
 *
 * @param cd crypt device handle
 * @param volume_key provided volume key
 * @param volume_key_size size of @e volume_key
 *
 * @return @e 0 on success or negative errno value otherwise.
 */
int crypt_volume_key_verify(struct crypt_device *cd,
	const char *volume_key,
	size_t volume_key_size);


/*
 * @defgroup devstat "dmcrypt device status"
 * @addtogroup devstat
 * @{
 */

/**
 * Device status
 */
typedef enum {
	CRYPT_INVALID, /**< device mapping is invalid in this context */
	CRYPT_INACTIVE, /**< no such mapped device */
	CRYPT_ACTIVE, /**< device is active */
	CRYPT_BUSY /**< device is active and has open count > 0 */
} crypt_status_info;

/**
 * Get status info about device name
 *
 * @param cd crypt device handle, can be @e NULL
 * @param name crypt device name
 *
 * @return value defined by crypt_status_info.
 *
 */
crypt_status_info crypt_status(struct crypt_device *cd, const char *name);

/**
 * Dump text-formatted information about crypt device to log output
 *
 * @param cd crypt device handle
 *
 * @return @e 0 on success or negative errno value otherwise.
 */
int crypt_dump(struct crypt_device *cd);

/**
 * Get cipher used in device
 *
 * @param cd crypt device handle
 *
 * @return used cipher, e.g. "aes" or @e NULL otherwise
 *
 */
const char *crypt_get_cipher(struct crypt_device *cd);

/**
 * Get cipher mode used in device
 *
 * @param cd crypt device handle
 *
 * @return used cipher mode e.g. "xts-plain" or @e otherwise
 *
 */
const char *crypt_get_cipher_mode(struct crypt_device *cd);

/**
 * Get device UUID
 *
 * @param cd crypt device handle
 *
 * @return device UUID or @e NULL if not set
 *
 */
const char *crypt_get_uuid(struct crypt_device *cd);

/**
 * Get path to underlaying device
 *
 * @param cd crypt device handle
 *
 * @return path to underlaying device name
 *
 */
const char *crypt_get_device_name(struct crypt_device *cd);

/**
 * Get device offset in sectors where real data starts on underlying device)
 *
 * @param cd crypt device handle
 *
 * @return device offset in sectors
 *
 */
uint64_t crypt_get_data_offset(struct crypt_device *cd);

/**
 * Get IV offset in sectors (skip)
 *
 * @param cd crypt device handle
 *
 * @return IV offset
 *
 */
uint64_t crypt_get_iv_offset(struct crypt_device *cd);

/**
 * Get size (in bytes) of volume key for crypt device
 *
 * @param cd crypt device handle
 *
 * @return volume key size
 *
 */
int crypt_get_volume_key_size(struct crypt_device *cd);

/**
 * @addtogroup keyslot
 * @{
 *
 */

/**
 * Crypt keyslot info
 */
typedef enum {
	CRYPT_SLOT_INVALID, /**< invalid keyslot */
	CRYPT_SLOT_INACTIVE, /**< keyslot is inactive (free) */
	CRYPT_SLOT_ACTIVE, /**< keyslot is active (used) */
	CRYPT_SLOT_ACTIVE_LAST /**< keylost is active (used)
				*   and last used at the same time */
} crypt_keyslot_info;

/**
 * Get information about particular key slot
 *
 *
 * @param cd crypt device handle
 * @param keyslot requested keyslot to check or CRYPT_ANY_SLOT
 *
 * @return value defined by crypt_keyslot_info
 *
 */
crypt_keyslot_info crypt_keyslot_status(struct crypt_device *cd, int keyslot);
/** @} */

/**
 * Backup header and keyslots to file
 *
 * @param cd crypt device handle
 * @param requested_type type of header to backup
 * @param backup_file file to backup header to
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 */
int crypt_header_backup(struct crypt_device *cd,
	const char *requested_type,
	const char *backup_file);

/**
 * Restore header and keyslots from backup file
 *
 *
 * @param cd crypt device handle
 * @param requested_type type of header to restore
 * @param backup_file file to restore header from
 *
 * @return @e 0 on success or negative errno value otherwise.
 *
 */
int crypt_header_restore(struct crypt_device *cd,
	const char *requested_type,
	const char *backup_file);

/**
 * Receives last reported error
 *
 * @param cd crypt device handle
 * @param buf buffef for message
 * @param size size of buffer
 *
 * @note Note that this is old API function using global context.
 * All error messages are reported also through log callback.
 */
void crypt_last_error(struct crypt_device *cd, char *buf, size_t size);

/**
 * Receives last reported error, DEPRECATED
 *
 * @param buf buffef for message
 * @param size size of buffer
 *
 * @note Note that this is old API function using global context.
 * All error messages are reported also through log callback.
 */
void crypt_get_error(char *buf, size_t size);

/**
 * Get directory where mapped crypt devices are created
 *
 * @return the directory path
 */
const char *crypt_get_dir(void);

/**
 * @defgroup dbg "Library debug level"
 *
 * Set library debug level
 *
 * @addtogroup dbg
 * @{
 */

/** Debug all */
#define CRYPT_DEBUG_ALL  -1
/** Debug none */
#define CRYPT_DEBUG_NONE  0

/**
 * Set the debug level for library
 *
 * @param level debug level
 *
 */
void crypt_set_debug_level(int level);

/** @} */

#ifdef __cplusplus
}
#endif
#endif /* _LIBCRYPTSETUP_H */
