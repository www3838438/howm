#ifndef CONFIG_H
#define CONFIG_H

/**
 * @file config.h
 */

/** The main modifier key. */
#define MODKEY Mod4Mask
/** Number of workspaces. */
#define WORKSPACES 3
/** When moving the mouse over a window, focus on the window? */
#define FOCUS_MOUSE 0
/** Upon spawning a new window, move the mouse to the new window? */
#define FOLLOW_MOVE 0
/** The size (in pixels) of the useless gaps. */
#define GAP 0
/** Enable debugging output */
#define DEBUG_ENABLE 1
/** When in zoom layout, should a gap be displayed? */
#define ZOOM_GAP 0
/** When in zoom layout, should a border be displayed? */
#define ZOOM_BORDER 0
/** The size (in pixels) of the border. */
#define BORDER_PX 2
/** The border colour when the window is focused. */
#define BORDER_FOCUS "#FF00FF"
/** The border colour when the window is unfocused. */
#define BORDER_UNFOCUS "#00FF00"

/** Shell commands that will be executed. */
static const char *term_cmd[] = {"urxvt", "-e", "sleep", "300", NULL};
static const char *dmenu_cmd[] = {"dmenu_run", "-i", "-h", "21", "-b",
					"-nb", "#70898f", "-nf", "black",
					"-sf", "#74718e", "-fn",
					"'Droid Sans Mono-10'"};
/* The key that, when combined with a number, defines a count. e.g:
 *
 * SUPER + 2*/
static int count_mod = MODKEY;

/* The standard key map, feel free to change them. In the form:
 *
 * {Modifier, Mode, Key, Command, Args}
 */
static const Key keys[] = {
	{ MODKEY, NORMAL, XK_Return, spawn, {.cmd = term_cmd} },
	{ MODKEY, NORMAL, XK_r, spawn, {.cmd = dmenu_cmd} },

	{ MODKEY, NORMAL, XK_s, change_layout, {.i = VSTACK} },
	{ MODKEY, NORMAL, XK_g, change_layout, {.i = GRID} },
	{ MODKEY, NORMAL, XK_s, change_layout, {.i = ZOOM} },
	{ MODKEY, NORMAL, XK_n, next_layout, {NULL} },
	{ MODKEY | ShiftMask, NORMAL, XK_n, previous_layout, {NULL} },
	{ MODKEY, NORMAL, XK_f, change_mode, {.i = FOCUS} },

	{ MODKEY, FOCUS, XK_k, focus_prev_client, {NULL} },
	{ MODKEY, FOCUS, XK_j, focus_next_client, {NULL} },
	{ MODKEY | ShiftMask, FOCUS, XK_k, move_current_up, {NULL} },
	{ MODKEY | ShiftMask, FOCUS, XK_j, move_current_down, {NULL} },
	{ MODKEY, FOCUS, XK_Escape, change_mode, {.i = NORMAL} },

	{ MODKEY, FOCUS, XK_space, focus_next_ws, {NULL} },
	{ MODKEY | ShiftMask, FOCUS, XK_space, focus_prev_ws, {NULL} },
	{ MODKEY, FOCUS, XK_1, change_ws, {.i = 1} },
    { MODKEY, FOCUS, XK_2, change_ws, {.i = 2} },
    { MODKEY, FOCUS, XK_3, change_ws, {.i = 3} },
    { MODKEY | ShiftMask, FOCUS, XK_1, current_to_ws, {.i = 1} },
    { MODKEY | ShiftMask, FOCUS, XK_2, current_to_ws, {.i = 2} },
    { MODKEY | ShiftMask, FOCUS, XK_3, current_to_ws, {.i = 3} }
};

/* The operations to be performed on a target. Vim's built in help is useful
 * for this:
 *
 * :help operators
 */
static const Operator operators[] = {
	{MODKEY, XK_q, op_kill},
    {MODKEY, XK_j, op_move_down},
    {MODKEY, XK_k, op_move_up}
};

/* Motions, can be used to show that an operation should be performed on a
 * certain target. e.g:
 *
 * q4c (QUIT, 4, Clients)
 * q2w (QUIT, 2, Workspaces)
 */
static const Motion motions[] = {
	{MODKEY, XK_c, CLIENT},
	{MODKEY, XK_w, WORKSPACE}
};

/* Workspaces and their default layouts. */
static Workspace workspaces[] = {
    {NULL},
	{.layout = HSTACK},
	{.layout = HSTACK},
	{.layout = HSTACK}
};

#endif
