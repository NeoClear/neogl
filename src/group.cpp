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
    item->next(head->next());
    item->prev(head);
    head->next(item);
    item->id(number);
    return 0;
}

nl_window *nl_group::get_head()
{
    return head;
}

