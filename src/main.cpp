#include <stdio.h>
#include "nl.h"

void trans(int _w, int _h)
{
    int x = 100, y = 100, w = 100, h = 100;
    w = x + w;
    h = y + h;
    float x1, y1;
    float x2, y2;
    x1 = -1.0f * ((float)_w / 2 - (float)x) / ((float)_w / 2);
    y1 = 1.0f * ((float)_h / 2 - (float)y) / ((float)_h / 2);
    x2 = -1.0f * ((float)_w / 2 - (float)w) / ((float)_w / 2);
    y2 = 1.0f * ((float)_h / 2 - (float)h) / ((float)_h / 2);
    /* glColor3f(0.98f, 0.625f, 0.12f); */
    glColor3f(0.98828125f, 0.9609375f, 0.890625f);
    glRectf(x1, y1, x2, y2);
    glFlush();
}

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
    /* return nl::run(gg); */
    while (!linux->should_close())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        /* glColor3f(0.98f, 0.625f, 0.12f); */
        /* //绘制矩形，第一对坐标表示左上角，第二对表示右下角 */
        /* glRectf(-0.2f, 0.2f, 0.2f, -0.2f); */
        /* glFlush(); */
        trans(640, 480);
        /* Swap front and back buffers */
        linux->swap_self_buffer();
        /* Poll for and process events */
        glfwPollEvents();

    }
    glfwTerminate();
    return 0;
}
