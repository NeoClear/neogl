#include <stdio.h>
#include <nl.h>

void ter(nl_window *item)
{
    switch (item->color()) {
    case nl_red:
        item->color(nl_green);
        break;
    case nl_green:
        item->color(nl_blue);
        break;
    case nl_blue:
        item->color(nl_dark);
        break;
    case nl_dark:
        item->color(nl_red);
        break;
    }
}

class my_but: public nl_button
{
public:
    nl_window *win;
    my_but(int x, int y, int w, int h, const char *title, int theme): nl_button(x, y, w, h, title, theme)
    {
        win = new nl_window(600, 600, "ass");
        win->color(nl_red);
        win->add(this);
    }
    virtual int handle(int e)
    {
        switch (e) {
        case nl_push:
            ter(win);
        }
        return nl_success;
    }
};

int nl_main(int argc, char *argv[])
{
    nl_group *global = new nl_group();
    my_but *ins = new my_but(100, 100, 100, 100, "ass", nl_light);
    global->add(ins->win);
    return nl::run(global);
}
