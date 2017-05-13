#ifndef NL_NAMESPACE_H
#define NL_NAMESPACE_H

#include <GLFW/glfw3.h>
#include "group.h"

namespace nl {
    int init();
    int run(nl_group *head);
}

#endif

