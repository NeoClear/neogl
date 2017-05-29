#ifndef SLIDE_H
#define SLIDE_H
#endif

#include "widget.h"

class nl_slide: public nl_widget
{
public:
    float value;
private:
    int theme;
public:
    nl_slide(int _x, int _y, int _w, int _h, const char *_title, int _theme);
    virtual int draw();
    virtual int handle(int e);

};
