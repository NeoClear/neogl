#include "window.h"

nl_window::nl_window(int _width, int _height, const char *_title): prev_window(NULL), next_window(NULL), widget_num(0), sub_head(NULL)
{
    scale = new nl_point;
    nl_win = glfwCreateWindow(_width, _height, _title, NULL, NULL);
    scale->x = _width;
    scale->y = _height;
    title = _title;
}

nl_window::~nl_window() {}

int nl_window::add(nl_widget *item)
{
    widget_num++;
    if (widget_num == 1) {
        sub_head = item;
        sub_head->prev(sub_head);
        sub_head->next(sub_head);
        sub_head->par(this); 
        return nl_true;
    }
    nl_widget *ins;
    ins = sub_head->next();
    item->next(ins);
    item->prev(sub_head);
    sub_head->next(item);
    ins->prev(item);
    item->par(this);
    return nl_true;
}

GLFWwindow *nl_window::value()
{
    return nl_win;
}

int nl_window::prev(nl_window *_prev)
{
    prev_window = _prev;
    return 0;
}

int nl_window::next(nl_window *_next)
{
    next_window = _next;
    return 0;
}

nl_window *nl_window::nl_window::prev()
{
    return prev_window;
}

nl_window *nl_window::nl_window::next()
{
    return next_window;
}

int nl_window::color(int color)
{
    this->make_self_current();
    switch (color) {
    case nl_red:
        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
        nl_color = nl_red;
        break;
    case nl_green:
        glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
        nl_color = nl_green;
        break;
    case nl_blue:
        glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
        nl_color = nl_blue;
        break;
    case nl_dark:
        glClearColor(0.17578125f, 0.17578125f, 0.17578125f, 0.0f);
        nl_color = nl_dark;
        break;
    case nl_light:
        glClearColor(0.98828125f, 0.9609375f, 0.890625f, 0.0f);
        nl_color = nl_light;
        break;
    case nl_solarized:
        glClearColor(0.0078125f, 0.016796875f, 0.20703125f, 0.0f);
        nl_color = nl_solarized;
        break;
    }
    return 0;
}

int nl_window::color()
{
    return nl_color;
}

int nl_window::should_close()
{
    return (int)glfwWindowShouldClose(nl_win);
}

void nl_window::swap_self_buffer()
{
    glfwSwapBuffers(nl_win);
}

void nl_window::make_self_current()
{
    glfwMakeContextCurrent(nl_win);
}

void nl_window::id(int _id)
{
    group_id = _id;
}

int nl_window::id()
{
    return group_id;
}

int nl_window::destroy_self()
{
    glfwDestroyWindow(nl_win);
    return 0;
}

const char *nl_window::title_self()
{
    return title;
}

nl_point *nl_window::scale_self()
{
    return scale;
}
