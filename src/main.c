#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils/nodes.h"
#include "../tests/main_test.h"

int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "test") == 0)
    {
        run_tests();
    }

    return EXIT_SUCCESS;
}