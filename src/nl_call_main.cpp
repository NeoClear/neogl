#include <stdio.h>
#include "nl_namespace.h"

extern int nl_main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    nl::init();

    return nl_main(argc, argv);
}

