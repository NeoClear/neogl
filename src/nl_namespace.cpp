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

void nl::give_event(nl_window *win, nl_widget *item)
{
    int _xpos = (int)win->curse_x;
    int _ypos = (int)win->curse_y;
    int _left_but = win->mouse_left_pressed;
    /* int _right_but = win->mouse_right_pressed; */
    int left_up_x = item->place->x;
    int left_up_y = item->place->y;
    int right_down_x = item->place->x + item->scale->x;
    int right_down_y = item->place->y + item->scale->y;
    if (_xpos >= left_up_x && _xpos <= right_down_x && _ypos >= left_up_y && _ypos <= right_down_y) {
        if (_left_but == nl_true && item->pushed == nl_false) {
            item->pushed = nl_true;
            item->handle(nl_push);
        }
        if (_left_but == nl_false && item->pushed == nl_true) {
            item->pushed = nl_false;
            item->handle(nl_up);
        }
        if (item->entered == nl_false) {
            item->entered = nl_true;
            item->handle(nl_enter);
        }
    } else {
        if (item->entered == nl_true) {
            item->entered = nl_false;
            item->handle(nl_leave);
        }
    }
}

void nl::change_frame_scale(nl_window *item)
{
    int w, h;
    glfwGetFramebufferSize(item->value(), &w, &h);
    item->scale->x = w;
    item->scale->y = h;
}

int nl::check_focus(nl_window *item)
{
    int focused = glfwGetWindowAttrib(item->value(), GLFW_FOCUSED);
    return focused;
}

int nl::run(nl_group *head)
{
    nl_window *point = head->get_head();
    while (nl_true) {
        point->make_self_current();
        change_frame_scale(point);
        if (!point->should_close()) {
            glClear(GL_COLOR_BUFFER_BIT);
            nl_widget *temp;
            set_mouse_pos(point);
            set_mouse_action(point);
            if (point->widget_num != 0) {
                temp = point->sub_head;
                nl_font::draw(640, 480);
                for (int i = 0; i < point->widget_num; i++) {
                    if (check_focus(point))
                        give_event(point, temp);
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

