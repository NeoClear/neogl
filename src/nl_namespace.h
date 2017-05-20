#ifndef NL_NAMESPACE_H
#define NL_NAMESPACE_H

#include <GLFW/glfw3.h>
#include "group.h"

class nl_group;

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

namespace nl
{
    extern int nl_error_num;
    void error();
    int init();
    int run(nl_group *head);
}

#endif

