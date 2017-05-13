#ifndef WIDGET_H
#define WIDGET_H

#include "nl_namespace.h"

class nl_widget
{
private:
    int xpoint, ypoint;
    int width, height;
    const char *caption;
    nl_widget *prev_widget, *next_widget;
public:
    nl_widget(int _x, int _y, int _w, int _h, const char *caption);
    ~nl_widget();
    draw();
    int prev(nl_widget *_prev);
    int next(nl_widget *_next);
    nl_widget *prev();
    nl_widget *next();
}
#endif