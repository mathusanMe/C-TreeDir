#include <stdlib.h>
#include <stdio.h>
#include "utils/string.h"
#include "parser/parser.h"
#include "utils/nodes.h"
#include "../tests/main_test.h"

#define TESTS_KEYS                       \
    {                                    \
        "test", "tests", "TEST", "TESTS" \
    }

#define TESTS_KEYS_SIZE 4

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return EXIT_FAILURE;
    }

    char *tests_keys[] = TESTS_KEYS;

    if (contains(tests_keys, TESTS_KEYS_SIZE, argv[1]))
    {
        if (run_tests())
        {
            return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
    }

    parse_file(argv[1]);

    return EXIT_SUCCESS;
}