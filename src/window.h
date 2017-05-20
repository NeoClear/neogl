#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>
#include "nl_namespace.h"
#include "widget.h"

class nl_widget;
class nl_button;
struct nl_point;

class nl_window
{
public:
    int widget_num;
    double curse_x, curse_y;
    int mouse_left_pressed;
    int mouse_right_pressed;
private:
    GLFWwindow *nl_win;
    nl_point *scale;
    int nl_color;
    nl_window *prev_window, *next_window;
    int group_id;
    const char *title;
public:
    nl_widget *sub_head;
    nl_window(int _width, int _height, const char *_title);
    ~nl_window();
    static void cursor_pos_callback(GLFWwindow *win, double x, double y);
    int add(nl_widget *item);
    GLFWwindow *value();
    int prev(nl_window *_prev);
    int next(nl_window *_next);
    nl_window *prev();
    nl_window *next();
    int color(int _color);
    int color();
    int should_close();
    void swap_self_buffer();
    void make_self_current();
    void id(int _id);
    int id();
    int destroy_self();
    const char *title_self();
    nl_point *scale_self();
};

#endif

