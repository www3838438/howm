#ifndef XCB_HELP_H
#define XCB_HELP_H

#include <stdint.h>
#include <xcb/randr.h>
#include <xcb/xproto.h>

#include "types.h"

/**
 * @file xcb_help.h
 *
 * @author Harvey Hunt
 *
 * @date 2015
 *
 * @brief howm
 */

enum net_atom_enum { NET_WM_STATE_FULLSCREEN, NET_SUPPORTED, NET_WM_STATE,
	NET_ACTIVE_WINDOW };
enum wm_atom_enum { WM_DELETE_WINDOW, WM_PROTOCOLS };

void elevate_window(xcb_window_t win);
void move_resize(xcb_window_t win, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void set_border_width(xcb_window_t win, uint16_t w);
void get_atoms(const char **names, xcb_atom_t *atoms);
void check_other_wm(void);
void focus_window(xcb_window_t win);
void grab_buttons(client_t *c);
void delete_win(xcb_window_t win);
void setup_ewmh(void);
void setup_ewmh_geom(void);
void ewmh_process_wm_state(client_t *c, xcb_atom_t a, int action);
void ewmh_set_current_workspace(void);
xcb_randr_output_t *randr_get_outputs(unsigned int *nr_outputs);
xcb_rectangle_t output_reply_to_rect(xcb_randr_get_output_info_reply_t *output);
xcb_randr_output_t randr_get_primary_output(void);
void center_pointer(xcb_rectangle_t rect);
void warp_pointer(int16_t x, int16_t y);

#endif
