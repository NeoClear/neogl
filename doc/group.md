#group.h
- a class to manage the windows of one applicaion

---
---
##variables
- `nl_window *head`
    - the pointer holds the **circle of the windows bend**
- `int number`
    - the value holds the **number of the windows**

---
---
##functions
- `nl_group()`
    - initialize some of the variables
- `int add(nl_window *item)`
    - **add the window** to the group
- `int remove()`
    - remove number by 1
    - **didn't do the destroy job**
    - **destroy job was done in the nl namespace**
    - **see in nl_namespace.md**
- `nl_window *get_head()`
    - *return head pointer**

---
---
##author: neoclear
##e-mail: saogong123456@outlook.com
