/*
    Copyright (C) 1999 Silicon Graphics, Inc.  All Rights Reserved.
    Copyright (C) 2004 Red Hat, Inc.

    This program is free software; you can redistribute it and/or modify it
    under the terms of version 2.1 of the GNU Lesser General Public License
    as published by the Free Software Foundation.

    This program is distributed in the hope that it would be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  Further, any
    license provided herein, whether implied or otherwise, is limited to
    this program in accordance with the express provisions of the GNU Lesser
    General Public License.  Patent licenses, if any, provided herein do not
    apply to combinations of this program with other product or programs, or
    any other product whatsoever. This program is distributed without any
    warranty that the program is delivered free of the rightful claim of any
    third person by way of infringement or the like.  See the GNU Lesser
    General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write the Free Software Foundation, Inc., 59
    Temple Place - Suite 330, Boston MA 02111-1307, USA.
*/

#ifndef __GAMIN_FAM_H__
#define __GAMIN_FAM_H__ 1

#ifdef __cplusplus
extern "C" {
#endif

/* For NAME_MAX - maximum # of chars in a filename */
#include <limits.h>

/* PATH_MAX is not defined in limits.h on some platforms */
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

/**
 * Structure associated to a FAM connection
 */
typedef struct FAMConnection FAMConnection;
typedef FAMConnection *FAMConnectionPtr;

struct FAMConnection {
    int fd;
    void *client;
};

/**
 * FAMCONNECTION_GETFD:
 *
 * The only field available from the connection is the file
 * descriptor and it should be accessed though the macro
 */
#define FAMCONNECTION_GETFD(fc) ((fc)->fd)

/***
 * FAMRequest:
 *
 * Structure associated to a FAM request
 * it should not be public but unfortunately it is included int the
 * FAMEvent structure.
 */
typedef struct FAMRequest FAMRequest;
typedef FAMRequest *FAMRequestPtr;

struct FAMRequest {
    int reqnum;
};

/**
 * FAMREQUEST_GETREQNUM:
 *
 * The only field available from the request is the request
 * number and it should be accessed though the macro
 */
#define FAMREQUEST_GETREQNUM(fr) ((fr)->reqnum)

/**
 * FAMEvent Structure, it is a public structure provided back to the
 * application, this part is part of the API/ABI.
 * The FAMCodes indicates what kind of event happened that raised
 * the callback at the application level.
 */
typedef enum FAMCodes {
    FAMChanged=1,
    FAMDeleted=2,
    FAMStartExecuting=3,
    FAMStopExecuting=4,
    FAMCreated=5,
    FAMMoved=6,
    FAMAcknowledge=7,
    FAMExists=8,
    FAMEndExist=9
} FAMCodes;

typedef struct  FAMEvent {
    FAMConnection* fc;         /* The fam connection that event occurred on */
    FAMRequest fr;             /* Corresponds to the FamRequest from monitor */
    char *hostname;            /* host and filename - pointer to which */
    char filename[PATH_MAX];   /* file changed */
    void *userdata;            /* userdata associated with this monitor req. */
    FAMCodes code;             /* What happened to file - see above */
} FAMEvent;

/**
 * FAMOpen/FAMClose:
 * those are the functions used to connect and disconnect to the FAM service
 */
extern int FAMOpen(FAMConnection* fc);
extern int FAMOpen2(FAMConnection* fc, const char* appName);
extern int FAMClose(FAMConnection* fc);

/**
 * FAMMonitorDirectory/FAMMonitorFile/FAMMonitorCollection:
 * Those functions are used to register monitoring requests for
 * files or directories.
 */

extern int FAMMonitorDirectory	(FAMConnection *fc,
			       	 const char *filename,
			       	 FAMRequest* fr,
			       	 void* userData);
extern int FAMMonitorFile	(FAMConnection *fc,
			  	 const char *filename, 
			  	 FAMRequest* fr,
			  	 void* userData);
extern int FAMMonitorDirectory2(FAMConnection *fc,
				const char *filename,
				FAMRequest* fr);
extern int FAMMonitorFile2	(FAMConnection *fc,
			   	 const char *filename,
			   	 FAMRequest* fr);

/**
 * FAMMonitorCollection:
 *
 * Seems an attempt at changing the scope of the API,
 * not supported, it's not described in the man pages anyway.
 */
extern int FAMMonitorCollection	(FAMConnection *fc,
				 const char *filename, 
				 FAMRequest* fr,
				 void* userData,
				 int depth,
				 const char* mask);

/**
 * FAMSuspendMonitor/FAMResumeMonitor:
 *
 * Those two functions are used to momentarily suspend and later resume
 * a given monitoring request.
 */
extern int FAMSuspendMonitor	(FAMConnection *fc,
				 const FAMRequest *fr);
extern int FAMResumeMonitor	(FAMConnection *fc,
				 const FAMRequest *fr);

/**
 * FAMCancelMonitor:
 *
 * This function is used to permanently stop a monitoring request.
 */
extern int FAMCancelMonitor	(FAMConnection *fc,
				 const FAMRequest *fr);

/**
 * FAMNextEvent/FAMPending:
 *
 *  FAMNextEvent will get the next fam event (file/directory change).  If
 *  there are no fam events waiting, then FAMNextEvent will wait
 *  until a fam event has been received (from fam).
 *
 *  FAMPending will return the number of fam events that are waiting.
 *  This routine always returns immediately to the caller.
 */
extern int FAMNextEvent		(FAMConnection *fc,
				 FAMEvent *fe);
extern int FAMPending		(FAMConnection* fc);

/**
 * FAMErrno:
 *
 * If an error occurs within libgamin FAMErrno should be set to a
 * non-zero value.
 */
extern int FAMErrno;

/**
 * FAMDebugLevel:
 *
 * Currently unimplemented as in the SGI FAM.  Exists only for
 * compatibility.
 */
extern int FAMDebugLevel (FAMConnection *fc,
			  int level);
/**
 * FAM_DEBUG_OFF:
 * Unused macro, compatibility for SGI FAM API.
 */
#define FAM_DEBUG_OFF 0
/**
 * FAM_DEBUG_ON:
 * Unused macro, compatibility for SGI FAM API.
 */
#define FAM_DEBUG_ON  1
/**
 * FAM_DEBUG_VERBOSE:
 * Unused macro, compatibility for SGI FAM API.
 */
#define FAM_DEBUG_VERBOSE 2

/**
 * FamErrList:
 *
 * In case FAMErrno is set, FAMErrlist is a global string array indexed
 * by FAMErrno that describes the last error that happened.
 * NOTE: this is not a good mechanism, it's present here only to provide
 *       API and ABI compatibility with FAM.
 */
extern const char *FamErrlist[];

/**
 * FAMNoExists:
 *
 * Specific extension for the core FAM API where Exists event are not
 * propagated on directory monitory listing startup. This speeds up 
 * watching large directories but can introduce a mismatch between the FAM
 * view of the directory and the program own view.
 *
 * Returns 0 in case of success and -1 in case of error.
 */
extern int FAMNoExists		(FAMConnection *fc);

#ifdef __cplusplus
}
#endif

#endif /* __GAMIN_FAM_H__ */
