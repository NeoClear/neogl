#include <stdio.h>
#include "nl.h"

int nl_main(int argc, char *argv[])
{
    nl_window *win = new nl_window(640, 480, "windows98");
    nl_window *win10 = new nl_window(640, 480, "windows10");
    nl_group *gg = new nl_group();
    /* win->prev(win10); */
    /* win->next(win10); */
    /* win10->prev(win); */
    /* win10->next(win); */
    win->color(nl_blue);
    win10->color(nl_red);
    gg->add(win);
    gg->add(win10);
    return nl::run(gg);
}
