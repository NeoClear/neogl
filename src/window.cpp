#include "window.h"


nl_window::nl_window(int width, int height, const char *title): prev_window(NULL), next_window(NULL)
{
    nl_win = glfwCreateWindow(width, height, title, NULL, NULL);
}
nl_window::~nl_window() {}
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

nl_group::nl_group(): number(0), head(NULL) {

}
int nl_group::add(nl_window *item)
{
    number++;
    if (number == 1) {
        head = item;
        head->prev(head);
        head->next(head);
        return 0;
    }
    item->next(head->next());
    item->prev(head);
    head->next(item);
    item->id(number);
    return 0;
}
nl_window *nl_group::get_head()
{
    return head;
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
            point->swap_self_buffer();
            glfwPollEvents();
        } else {
            break;
        }
        point = point->next();
    }
    glfwTerminate();
    return 0;
}

extern int nl_main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    nl::init();
    return nl_main(argc, argv);
}
