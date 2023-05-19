#include "display_test.h"

void display_test(int type, char *func_name, FILE *output)
{
    char buffer[50];

    if (output != stdout)
    {
        fprintf(output, "%s\n", func_name);
        return;
    }

    if (type < 0)
    {
        sprintf(output, buffer, "./lib_tests.sh name %s", func_name);
    }
    else if (type > 0)
    {
        sprintf(output, buffer, "./lib_tests.sh passed %s", func_name);
    }
    else
    {
        sprintf(output, buffer, "./lib_tests.sh failed %s", func_name);
    }

    system(buffer);
}