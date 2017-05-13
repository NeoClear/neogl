#ifndef GROUP_H
#define GROUP_H

#include "window.h"
#include <GLFW/glfw3.h>

class nl_window;
class nl_group
{
private:
    nl_window *head;
    int number;
public:
    nl_group();
    int add(nl_window *item);
    int remove();
    nl_window *get_head();
};

#endif

