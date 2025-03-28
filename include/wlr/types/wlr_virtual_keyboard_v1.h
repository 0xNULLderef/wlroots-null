/*
 * This an unstable interface of wlroots. No guarantees are made regarding the
 * future consistency of this API.
 */
#ifndef WLR_USE_UNSTABLE
#error "Add -DWLR_USE_UNSTABLE to enable unstable wlroots features"
#endif

#ifndef WLR_TYPES_WLR_VIRTUAL_KEYBOARD_V1_H
#define WLR_TYPES_WLR_VIRTUAL_KEYBOARD_V1_H

#include <wayland-server-core.h>
#include <wlr/types/wlr_keyboard.h>

struct wlr_virtual_keyboard_manager_v1 {
	struct wl_global *global;
	struct wl_list virtual_keyboards; // wlr_virtual_keyboard_v1.link

	struct {
		struct wl_signal new_virtual_keyboard; // struct wlr_virtual_keyboard_v1
		struct wl_signal destroy;
	} events;

	struct {
		struct wl_listener display_destroy;
	} WLR_PRIVATE;
};

struct wlr_virtual_keyboard_v1 {
	struct wlr_keyboard keyboard;
	struct wl_resource *resource;
	struct wlr_seat *seat;
	bool has_keymap;

	struct wl_list link; // wlr_virtual_keyboard_manager_v1.virtual_keyboards
};

struct wlr_virtual_keyboard_manager_v1* wlr_virtual_keyboard_manager_v1_create(
	struct wl_display *display);

struct wlr_virtual_keyboard_v1 *wlr_input_device_get_virtual_keyboard(
	struct wlr_input_device *wlr_dev);

#endif
