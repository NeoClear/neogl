#widget.h
- the base class of all the widgets in the window

---
---
##variables
- `nl_widget *prev_widget, *next_widget`
    - the pointer **to construct the circle**
    - **not used yet**
- `const char *caption`
    - the **caption of the widget**
- `nl_point *place`
    - the location of the **left top**
- `nl_point *scale`
    - the location of the **right botton, compared to left top**
- `nl_window *parent`
    - the **mother of all widgets**
- `float x1, y1`
    - the location of **left top, using opengl locating system**
- `float x2, y2`
    - the location of **right botton, using opengl locating system**

---
---
##functions
- `nl_widget(int _x, int _y, int _w, int _h, const char *caption)`
    - the constructor. **set the scale and location and title**
- `~nl_widget()`
    - nothing
- `virtual int draw()`
    - the drawing function of all widgets.
    - **it's a virtual function, for others widgets to recover it**
- `int prev(nl_widget *_prev)`
    - set the prev **as _prev**
    - **not used yet**
- `int next(nl_widget *_next)`
    - set the next **as _next**
    - **not used yet**
- `int par(nl_window *_par)`
    - **set the parent as _par**
- `nl_widget *prev()`
    - **get the prev**
- `nl_widget *next()`
    - **get the next**

---
---
##author: neoclear
##e-mail: saogong123456@outlook.com
