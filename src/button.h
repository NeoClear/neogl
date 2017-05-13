#ifndef BUTTON_H
#define BUTTON_H

#include "widget.h"

class nl_button: public nl_widget
{
private:
    int theme;
public:
    int draw();
};
#endif
