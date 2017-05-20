#include "nl_namespace.h"

class nl_window;

int nl::nl_error_num = 0;
/* double nl::pos_x; */
/* double nl::pos_y; */

void nl::error()
{
    nl_error_num++;
    printf("error %d: happened\n", nl_error_num);
}
/* void nl::set_pos(double _x, double _y) */
/* { */
/*     pos_x = _x; */
/*     pos_y = _y; */
/* } */

/* void nl::get_pos() */
/* { */
/*     printf("%f, %f\n", pos_x, pos_y); */
/* } */

int nl::init()
{
    return (int)glfwInit();
}

void nl::set_mouse_pos(nl_window *item)
{
    double xpos, ypos;
    glfwGetCursorPos(item->value(), &xpos, &ypos);
    item->curse_x = xpos;
    item->curse_y = ypos;
}

void nl::set_mouse_action(nl_window *item)
{
    int left_state = glfwGetMouseButton(item->value(), GLFW_MOUSE_BUTTON_LEFT);
    int right_state = glfwGetMouseButton(item->value(), GLFW_MOUSE_BUTTON_RIGHT);
    if (left_state == GLFW_PRESS)
        item->mouse_left_pressed = nl_true;
    else
        item->mouse_left_pressed = nl_false;
    if (right_state == GLFW_PRESS)
        item->mouse_right_pressed = nl_true;
    else
        item->mouse_right_pressed = nl_false;
}

int nl::run(nl_group *head)
{
    nl_window *point = head->get_head();
    while (nl_true) {
        point->make_self_current();
        if (!point->should_close()) {
            glClear(GL_COLOR_BUFFER_BIT);
            nl_widget *temp;
            set_mouse_pos(point);
            set_mouse_action(point);
            if (point->widget_num != 0) {
                temp = point->sub_head;
                for (int i = 0; i < point->widget_num; i++) {
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

