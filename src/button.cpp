#include "button.h"


nl_button::nl_button(int _x, int _y, int _w, int _h, const char *_title, int _theme): nl_widget(_x, _y, _w, _h, _title)
{
    place = new nl_point;
    scale = new nl_point;
    place->x = _x;
    place->y = _y;
    scale->x = _w;
    scale->y = _h;
    caption = _title;
    theme = _theme;
}

int nl_button::draw()
{
    nl_point *corner = new nl_point;
    corner->x = place->x + scale->x;
    corner->y = place->y + scale->y;
    x1 = -1.0f * ((float)parent->scale_self()->x / 2 - (float)place->x) / ((float)parent->scale_self()->x / 2);
    y1 = 1.0f * ((float)parent->scale_self()->y / 2 - (float)place->y) / ((float)parent->scale_self()->y / 2);
    x2 = -1.0f * ((float)parent->scale_self()->x / 2 - (float)corner->x) / ((float)parent->scale_self()->x/ 2);
    y2 = 1.0f * ((float)parent->scale_self()->y / 2 - (float)corner->y) / ((float)parent->scale_self()->y / 2);
    switch (theme) {
    case nl_red:
        glColor3f(1.0f, 0.0f, 0.0f);
        break;
    case nl_green:
        glColor3f(0.0f, 1.0f, 0.0f);
        break;
    case nl_blue:
        glColor3f(0.0f, 0.0f, 1.0f);
        break;
    case nl_dark:
        glColor3f(0.17578125f, 0.17578125f, 0.17578125f);
        break;
    case nl_light:
        glColor3f(0.98828125f, 0.9609375f, 0.890625f);
        break;
    case nl_solarized:
        glColor3f(0.0078125f, 0.016796875f, 0.20703125f);
        break;
    }
    glRectf(x1, y1, x2, y2);
    glFlush();
    return 0;
}
