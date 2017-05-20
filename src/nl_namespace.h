#ifndef NL_NAMESPACE_H
#define NL_NAMESPACE_H

#include <GLFW/glfw3.h>
#include "group.h"
#include "window.h"
#include "widget.h"

class nl_group;
class nl_window;

struct nl_point
{
    int x;
    int y;
};

enum nl_color
{
    nl_red = 0,
    nl_green = 1,
    nl_blue = 2,
    nl_dark = 3,
    nl_light = 4,
    nl_solarized = 5,
};

enum nl_bool
{
    nl_false = 0,
    nl_true = 1,
};

enum nl_event
{
    nl_push = 0,
    nl_up = 1,
    nl_enter = 2,
    nl_leave = 3,
};

enum nl_return_t
{
    nl_success = 0,
    nl_fail = 1,
    nl_likely = 2,
    nl_unlikely = 3,
};

namespace nl
{
    extern int nl_error_num;
    void set_mouse_pos(nl_window *item);
    void set_mouse_action(nl_window *item);
    void give_event(nl_window *win, nl_widget *item);
    int check_focus(nl_window *item);
    void error();
    int init();
    int run(nl_group *head);
}

#endif

