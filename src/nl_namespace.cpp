#include "nl_namespace.h"
#include "window.h"

int nl::nl_error_num = 0;

void nl::error()
{
    nl_error_num++;
    printf("error %d: happened\n", nl_error_num);
}

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
            nl_widget *temp;
            if (point->widget_num != 0) {
                temp = point->sub_head;
                for (int i = 0; i < 32; i++) {
                    temp->draw();
                    temp = temp->next();
                }
            }
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

