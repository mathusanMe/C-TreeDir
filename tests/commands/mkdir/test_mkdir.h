#ifndef TEST_MKDIR_H
#define TEST_MKDIR_H

#include "../../../src/utils/nodes.h"
#include "../../utils/display_test.h"
#include "../../../src/commands/mkdir/mkdir.h"

bool mkdir_test_name_empty(FILE *output, bool verbose);
bool mkdir_test_name_contains_non_alnum_char(FILE *output, bool verbose);
bool mkdir_test_name_too_long(FILE *output, bool verbose);
bool run_tests_mkdir(FILE *output, bool verbose);

#endif