#include "nl_namespace.h"

int nl::init()
{
    return (int)glfwInit();
}

int nl::run(nl_group *head)
{
    nl_window *point = head->get_head();
    while (nl_true) {
        point->make_self_current();
        if (!point->should_close()) {
            glClear(GL_COLOR_BUFFER_BIT);
            point->swap_self_buffer();
            glfwPollEvents();
        } else {
            if (head->remove() == nl_false)
                break;
            point->next()->prev(point->prev());
            point->prev()->next(point->next());
            point->destroy_self();
        }
        point = point->next();
    }
    glfwTerminate();
    return 0;
}

