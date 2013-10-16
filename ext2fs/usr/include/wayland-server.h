/*
 * Copyright © 2008 Kristian Høgsberg
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef WAYLAND_H
#define WAYLAND_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <stdint.h>
#include "wayland-util.h"
#include "wayland-version.h"

enum {
	WL_EVENT_READABLE = 0x01,
	WL_EVENT_WRITABLE = 0x02,
	WL_EVENT_HANGUP   = 0x04,
	WL_EVENT_ERROR    = 0x08
};

struct wl_event_loop;
struct wl_event_source;
typedef int (*wl_event_loop_fd_func_t)(int fd, uint32_t mask, void *data);
typedef int (*wl_event_loop_timer_func_t)(void *data);
typedef int (*wl_event_loop_signal_func_t)(int signal_number, void *data);
typedef void (*wl_event_loop_idle_func_t)(void *data);

struct wl_event_loop *wl_event_loop_create(void);
void wl_event_loop_destroy(struct wl_event_loop *loop);
struct wl_event_source *wl_event_loop_add_fd(struct wl_event_loop *loop,
					     int fd, uint32_t mask,
					     wl_event_loop_fd_func_t func,
					     void *data);
int wl_event_source_fd_update(struct wl_event_source *source, uint32_t mask);
struct wl_event_source *wl_event_loop_add_timer(struct wl_event_loop *loop,
						wl_event_loop_timer_func_t func,
						void *data);
struct wl_event_source *
wl_event_loop_add_signal(struct wl_event_loop *loop,
			int signal_number,
			wl_event_loop_signal_func_t func,
			void *data);

int wl_event_source_timer_update(struct wl_event_source *source,
				 int ms_delay);
int wl_event_source_remove(struct wl_event_source *source);
void wl_event_source_check(struct wl_event_source *source);


int wl_event_loop_dispatch(struct wl_event_loop *loop, int timeout);
void wl_event_loop_dispatch_idle(struct wl_event_loop *loop);
struct wl_event_source *wl_event_loop_add_idle(struct wl_event_loop *loop,
					       wl_event_loop_idle_func_t func,
					       void *data);
int wl_event_loop_get_fd(struct wl_event_loop *loop);

struct wl_client;
struct wl_display;
struct wl_listener;
struct wl_resource;
struct wl_global;
typedef void (*wl_notify_func_t)(struct wl_listener *listener, void *data);

void wl_event_loop_add_destroy_listener(struct wl_event_loop *loop,
					struct wl_listener * listener);
struct wl_listener *wl_event_loop_get_destroy_listener(
					struct wl_event_loop *loop,
					wl_notify_func_t notify);

struct wl_display *wl_display_create(void);
void wl_display_destroy(struct wl_display *display);
struct wl_event_loop *wl_display_get_event_loop(struct wl_display *display);
int wl_display_add_socket(struct wl_display *display, const char *name);
void wl_display_terminate(struct wl_display *display);
void wl_display_run(struct wl_display *display);
void wl_display_flush_clients(struct wl_display *display);

typedef void (*wl_global_bind_func_t)(struct wl_client *client, void *data,
				      uint32_t version, uint32_t id);

uint32_t wl_display_get_serial(struct wl_display *display);
uint32_t wl_display_next_serial(struct wl_display *display);

void wl_display_add_destroy_listener(struct wl_display *display,
				     struct wl_listener *listener);
struct wl_listener *wl_display_get_destroy_listener(struct wl_display *display,
						    wl_notify_func_t notify);

struct wl_global *wl_global_create(struct wl_display *display,
				   const struct wl_interface *interface,
				   int version,
				   void *data, wl_global_bind_func_t bind);
void wl_global_destroy(struct wl_global *global);

struct wl_client *wl_client_create(struct wl_display *display, int fd);
void wl_client_destroy(struct wl_client *client);
void wl_client_flush(struct wl_client *client);
void wl_client_get_credentials(struct wl_client *client,
			       pid_t *pid, uid_t *uid, gid_t *gid);

void wl_client_add_destroy_listener(struct wl_client *client,
				    struct wl_listener *listener);
struct wl_listener *wl_client_get_destroy_listener(struct wl_client *client,
						   wl_notify_func_t notify);

struct wl_resource *
wl_client_get_object(struct wl_client *client, uint32_t id);
void
wl_client_post_no_memory(struct wl_client *client);

struct wl_listener {
	struct wl_list link;
	wl_notify_func_t notify;
};

struct wl_signal {
	struct wl_list listener_list;
};

static inline void
wl_signal_init(struct wl_signal *signal)
{
	wl_list_init(&signal->listener_list);
}

static inline void
wl_signal_add(struct wl_signal *signal, struct wl_listener *listener)
{
	wl_list_insert(signal->listener_list.prev, &listener->link);
}

static inline struct wl_listener *
wl_signal_get(struct wl_signal *signal, wl_notify_func_t notify)
{
	struct wl_listener *l;

	wl_list_for_each(l, &signal->listener_list, link)
		if (l->notify == notify)
			return l;

	return NULL;
}

static inline void
wl_signal_emit(struct wl_signal *signal, void *data)
{
	struct wl_listener *l, *next;

	wl_list_for_each_safe(l, next, &signal->listener_list, link)
		l->notify(l, data);
}

typedef void (*wl_resource_destroy_func_t)(struct wl_resource *resource);

#ifndef WL_HIDE_DEPRECATED

struct wl_object {
	const struct wl_interface *interface;
	const void *implementation;
	uint32_t id;
};

struct wl_resource {
	struct wl_object object;
	wl_resource_destroy_func_t destroy;
	struct wl_list link;
	struct wl_signal destroy_signal;
	struct wl_client *client;
	void *data;
};

struct wl_buffer {
	struct wl_resource resource;
	int32_t width, height;
	uint32_t busy_count;
} WL_DEPRECATED;


uint32_t
wl_client_add_resource(struct wl_client *client,
		       struct wl_resource *resource) WL_DEPRECATED;

struct wl_resource *
wl_client_add_object(struct wl_client *client,
		     const struct wl_interface *interface,
		     const void *implementation,
		     uint32_t id, void *data) WL_DEPRECATED;
struct wl_resource *
wl_client_new_object(struct wl_client *client,
		     const struct wl_interface *interface,
		     const void *implementation, void *data) WL_DEPRECATED;

struct wl_global *
wl_display_add_global(struct wl_display *display,
		      const struct wl_interface *interface,
		      void *data,
		      wl_global_bind_func_t bind) WL_DEPRECATED;

void
wl_display_remove_global(struct wl_display *display,
			 struct wl_global *global) WL_DEPRECATED;

#endif

/*
 * Post an event to the client's object referred to by 'resource'.
 * 'opcode' is the event number generated from the protocol XML
 * description (the event name). The variable arguments are the event
 * parameters, in the order they appear in the protocol XML specification.
 *
 * The variable arguments' types are:
 * - type=uint: 	uint32_t
 * - type=int:		int32_t
 * - type=fixed:	wl_fixed_t
 * - type=string:	(const char *) to a nil-terminated string
 * - type=array:	(struct wl_array *)
 * - type=fd:		int, that is an open file descriptor
 * - type=new_id:	(struct wl_object *) or (struct wl_resource *)
 * - type=object:	(struct wl_object *) or (struct wl_resource *)
 */
void wl_resource_post_event(struct wl_resource *resource,
			    uint32_t opcode, ...);
void wl_resource_queue_event(struct wl_resource *resource,
			     uint32_t opcode, ...);

/* msg is a printf format string, variable args are its args. */
void wl_resource_post_error(struct wl_resource *resource,
			    uint32_t code, const char *msg, ...)
	__attribute__ ((format (printf, 3, 4)));
void wl_resource_post_no_memory(struct wl_resource *resource);

#include "wayland-server-protocol.h"

struct wl_display *
wl_client_get_display(struct wl_client *client);

struct wl_resource *
wl_resource_create(struct wl_client *client,
		   const struct wl_interface *interface,
		   int version, uint32_t id);
void
wl_resource_set_implementation(struct wl_resource *resource,
			       const void *implementation,
			       void *data,
			       wl_resource_destroy_func_t destroy);

void
wl_resource_destroy(struct wl_resource *resource);
uint32_t
wl_resource_get_id(struct wl_resource *resource);
struct wl_list *
wl_resource_get_link(struct wl_resource *resource);
struct wl_resource *
wl_resource_from_link(struct wl_list *resource);
struct wl_resource *
wl_resource_find_for_client(struct wl_list *list, struct wl_client *client);
struct wl_client *
wl_resource_get_client(struct wl_resource *resource);
void
wl_resource_set_user_data(struct wl_resource *resource, void *data);
void *
wl_resource_get_user_data(struct wl_resource *resource);
int
wl_resource_get_version(struct wl_resource *resource);
void
wl_resource_set_destructor(struct wl_resource *resource,
			   wl_resource_destroy_func_t destroy);
int
wl_resource_instance_of(struct wl_resource *resource,
			const struct wl_interface *interface,
			const void *implementation);

void
wl_resource_add_destroy_listener(struct wl_resource *resource,
				 struct wl_listener * listener);
struct wl_listener *
wl_resource_get_destroy_listener(struct wl_resource *resource,
				 wl_notify_func_t notify);

struct wl_shm_buffer;

struct wl_shm_buffer *
wl_shm_buffer_get(struct wl_resource *resource);

void *
wl_shm_buffer_get_data(struct wl_shm_buffer *buffer);

int32_t
wl_shm_buffer_get_stride(struct wl_shm_buffer *buffer);

uint32_t
wl_shm_buffer_get_format(struct wl_shm_buffer *buffer);

int32_t
wl_shm_buffer_get_width(struct wl_shm_buffer *buffer);

int32_t
wl_shm_buffer_get_height(struct wl_shm_buffer *buffer);

int
wl_display_init_shm(struct wl_display *display);

struct wl_shm_buffer *
wl_shm_buffer_create(struct wl_client *client,
		     uint32_t id, int32_t width, int32_t height,
		     int32_t stride, uint32_t format);

void wl_log_set_handler_server(wl_log_func_t handler);

#ifdef  __cplusplus
}
#endif

#endif
