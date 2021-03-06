#ifndef WIDGET_H
#define WIDGET_H

#include "nl_namespace.h"
#include "window.h"

struct nl_point;
class nl_window;

class nl_widget
{
public:
    int pushed;
    int entered;
    const char *caption;
    nl_point *place;
    nl_point *scale;
    nl_window *parent;
    float x1, y1;
    float x2, y2;

private:
    nl_widget *prev_widget, *next_widget;

public:
    nl_widget(int _x, int _y, int _w, int _h, const char *caption);
    ~nl_widget();
    virtual int draw();
    int prev(nl_widget *_prev);
    int next(nl_widget *_next);
    int par(nl_window *_par);
    nl_widget *prev();
    nl_widget *next();
    virtual int handle(int e);
};
#endif
