#ifndef CLIENT_H
#define CLIENT_H

#include <stdbool.h>
#include <stdint.h>
#include <xcb/xcb.h>
#include <xcb/xproto.h>

#include "types.h"

/**
 * @file client.h
 *
 * @author Harvey Hunt
 *
 * @date 2015
 *
 * @brief howm
 */

enum teleport_locations { TOP_LEFT, TOP_CENTER, TOP_RIGHT, CENTER, BOTTOM_LEFT, BOTTOM_CENTER, BOTTOM_RIGHT };

int get_non_tff_count(monitor_t *m);
client_t *get_first_non_tff(monitor_t *m);
void change_client_gaps(client_t *c, int size);
void kill_client(monitor_t *m, workspace_t *w, client_t *c);
void move_up(client_t *c);
client_t *next_client(client_t *c);
void update_focused_client(client_t *c);
client_t *prev_client(client_t *c, workspace_t *w);
client_t *create_client(xcb_window_t w);
void remove_client(monitor_t *m, workspace_t *w, client_t *c);
void client_to_ws(client_t *c, workspace_t *ws, bool follow);
void draw_clients(void);
void change_client_geom(client_t *c, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void set_fullscreen(client_t *c, bool fscr);
void set_urgent(client_t *c, bool urg);
void move_client(int cnt, bool up);
void move_current_down(void);
void move_current_up(void);

void teleport_client(const int direction);
void focus_next_client(void);
void focus_prev_client(void);
void current_to_ws(workspace_t *ws);
void toggle_float(void);
void resize_float_width(const int dw);
void resize_float_height(const int dh);
void move_float_y(const int dy);
void move_float_x(const int dx);
void toggle_fullscreen(void);
void make_master(void);
void focus_urgent(void);
void resize_master(const int ds);
void paste(void);
void toggle_bar(void);

#endif
