#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>

enum nl_color
{
    nl_red = 0,
    nl_green = 1,
    nl_blue = 2,
};

enum nl_bool
{
    nl_false = 0,
    nl_true = 1,
};

class nl_window
{
private:
    GLFWwindow *nl_win;
    int nl_color;
    nl_window *prev_window, *next_window;
    int group_id;
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
};

#endif

