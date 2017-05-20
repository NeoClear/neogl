#include "widget.h"

nl_widget::nl_widget(int _x, int _y, int _w, int _h, const char *_caption): pushed(nl_false), entered(nl_false)
{
    place = new nl_point;
    scale = new nl_point;
    place->x = _x;
    place->y = _y;
    scale->x = _w;
    scale->y = _h;
    caption = _caption;
}
nl_widget::~nl_widget()
{

}

int nl_widget::par(nl_window *_par)
{
    parent = _par;
    return 0;
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

int nl_widget::handle(int e)
{
    printf("UNLIKELY: %d\n", e);
    return nl_unlikely;
}
