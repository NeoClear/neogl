#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>
#include "nl_namespace.h"
#include "widget.h"

class nl_window
{
private:
    GLFWwindow *nl_win;
    int nl_color;
    nl_window *prev_window, *next_window;
    int group_id;
    const char *title;
    nl_widget *sub_head;
public:
    nl_window(int width, int height, const char *title);
    ~nl_window();
    GLFWwindow *value();
    int prev(nl_window *_prev);
    int next(nl_window *_next);
    nl_window *prev();
    nl_window *next();
    int color(int color);
    int color();
    int should_close();
    void swap_self_buffer();
    void make_self_current();
    void id(int _id);
    int id();
    int destroy_self();
    const char *title_self();
};

#endif

