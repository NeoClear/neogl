#include "button.h"


nl_button::nl_button(int _x, int _y, int _w, int _h, const char *_title): nl_widget(_x, _y, _w, _h, _title)
{
    place = new nl_point;
    scale = new nl_point;
    place->x = _x;
    place->y = _y;
    scale->x = _w;
    scale->y = _h;
    caption = _title;
}

int nl_button::draw()
{
    printf("ass we can\n");
    nl_point *corner = new nl_point;
    /* float x1, y1, x2, y2; */
    printf("ass we can\n");
    corner->x = place->x + scale->x;
    corner->y = place->y + scale->y;
    printf("ass we can\n");
    x1 = -1.0f * ((float)parent->scale_self()->x / 2 - (float)place->x) / ((float)parent->scale_self()->x / 2);
    y1 = 1.0f * ((float)parent->scale_self()->y / 2 - (float)place->y) / ((float)parent->scale_self()->y / 2);
    x2 = -1.0f * ((float)parent->scale_self()->x / 2 - (float)corner->x) / ((float)parent->scale_self()->x/ 2);
    y2 = 1.0f * ((float)parent->scale_self()->y / 2 - (float)corner->y) / ((float)parent->scale_self()->y / 2);
    printf("ass we can\n");
    glColor3f(0.0f, 0.0f, 0.0f);
    printf("%s\n", caption);
    glRectf(x1, y1, x2, y2);
    glFlush();
    return 0;
}
