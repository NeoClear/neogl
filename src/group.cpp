#include "group.h"

nl_group::nl_group(): number(0), head(NULL) {

}

int nl_group::add(nl_window *item)
{
    number++;
    if (number == 1) {
        head = item;
        head->prev(head);
        head->next(head);
        return 0;
    }
    if (number == 2) {
        item->next(head->next());
        item->prev(head);
        head->next(item);
        head->prev(item);
        return 0;
    }
    item->next(head->next());
    item->prev(head);
    head->next()->prev(item);
    head->next(item);
    return 0;
}

int nl_group::remove()
{
    number--;
    if (number == 0)
        return nl_false;
    return nl_true;
}

nl_window *nl_group::get_head()
{
    return head;
}

