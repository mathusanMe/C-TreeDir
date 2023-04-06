#include "display_test.h"

void display_test(int type, char *func_name)
{
    char buffer[50];

    if (type < 0)
    {
        sprintf(buffer, "./lib_tests.sh none %s", func_name);
    }
    else if (type > 0)
    {
        sprintf(buffer, "./lib_tests.sh true %s", func_name);
    }
    else
    {
        sprintf(buffer, "./lib_tests.sh false %s", func_name);
    }

    system(buffer);
}