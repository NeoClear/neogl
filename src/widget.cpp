#include "widget.h"

nl_widget::nl_widget(int _x, int _y, int _w, int _h, const char *_caption)
{
    xpoint = _x;
    ypoint = _y;
    width = _w;
    height = _h;
    caption = _caption;
}
nl_widget::~nl_widget()
{

}
int nl_widget::draw()
{
    return nl_true;
}
int nl_widget::prev(nl_widget *_prev)
{
    prev_widget = _prev;
    return nl_true;
}
int nl_widget::next(nl_widget *_next)
{
    next_widget= _next;
    return nl_true;
}
nl_widget *nl_widget::prev()
{
    return prev_widget;
}
nl_widget *nl_widget::next()
{
    return next_widget;
}
