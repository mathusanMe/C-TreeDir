#ifndef TEST_PRINT_H
#define TEST_PRINT_H

#include <stdbool.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/print/print.h"

bool test_print_test_tree(FILE *output);
bool run_tests_print(FILE *output, bool verbose);

#endif