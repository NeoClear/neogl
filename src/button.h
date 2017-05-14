#ifndef BUTTON_H
#define BUTTON_H

#include "widget.h"

class nl_button: public nl_widget
{
private:
    int theme;
public:
    nl_button(int _x, int _y, int _w, int _h, const char *_title);
    int draw();
};
#endif
