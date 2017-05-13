#include <stdio.h>
#include "nl.h"

int nl_main(int argc, char *argv[])
{
    nl_window *win = new nl_window(640, 480, "windows");
    nl_window *win10 = new nl_window(640, 480, "windows10");
    nl_window *macos = new nl_window(640, 480, "macos");
    nl_window *linux = new nl_window(640, 480, "linux");
    nl_group *gg = new nl_group();
    win->color(nl_blue);
    win10->color(nl_solarized);
    macos->color(nl_light);
    linux->color(nl_dark);
    gg->add(win);
    gg->add(win10);
    gg->add(macos);
    gg->add(linux);
    /* printf("win: %s %s\n", win->prev()->title_self(), win->next()->title_self()); */
    /* printf("win10: %s %s\n", win10->prev()->title_self(), win10->next()->title_self()); */
    /* printf("macos: %s %s\n", macos->prev()->title_self(), macos->next()->title_self()); */
    /* printf("linux: %s %s\n", linux->prev()->title_self(), linux->next()->title_self()); */
    return nl::run(gg);
}
