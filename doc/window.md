#window.h
- a class called nl_window to carry the function of GLFWwindow.

---
---
##variables
- `GLFWwindow *nl_win`
    - the class pointer containing the **real window info**
- `nl_point *scale`
    - the nl_point variables containing the **height and width**.
- `int nl_color`
    - the value contains the color of the window. **values are listed in nl_namespace.md**
- `nl_window *prev_window, *next_window`
    - the pointer construct **the window in a group**, the implementation are listed in **group.md**
- `int group_id`
    - the id in the group, **not used yet**
- `const char *title`
    - the **title of the window** displayed.
- `nl_widget *subhead`
    - the pointer of the **widgets in the window**. Not migranted from the public namespace yet.

---
---
##functions
- `nl_window(int _width, int _height, const char *_title)`
    - **initlize the window.**
- `~nl_window()`
    - **nothing**
- `GLFWwindow *value`
    - the function returns the **real variable of the window.**
- `int prev(nl_window *_prev)`
    - the function **set the prev window**
- `int next(nl_window *_nwxt)`
    - the function **set the next window**
- `nl_window *prev()`
    - **returns the prev window**
- `nl_window *next()`
    - **returns the next window**
- `int color(int _color)`
    - **set the color**
- `int color()`
    - returns the **color of the window**
- `int should_close()`
    - if **user closed the window, return nl_false**
    - else **return nl_true**
- `void swap_self_buffer`
    - swap it self
- `void make_self_current`
    - make the **OpenGL draw on the current window**
- `void id(int _id)`
    - set the **id of the window** as *_id*
    - **not used yet**
- `int id()`
    - returns the **id of the window**
    - **not used yet**
- `int destroy_self()`
    - **destroy the current window**
- `const char *title_self`
    - get the **title of the window**
- `nl_point *scale_self()`
    - returns the **height and width as nl_point**
    - **nl_point see in nl_namespace.md**

---
##author: neoclear
##e-mail: saogong123456@outlook.com
