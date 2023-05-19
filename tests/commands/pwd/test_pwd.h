#ifndef TEST_PWD_H
#define TEST_PWD_H

#include "../../../src/utils/nodes.h"
#include "../../utils/display_test.h"
#include "../../../src/commands/pwd/pwd.h"
#include "../../../src/commands/cd/cd.h"

bool test_current_node_is_null(FILE *output, bool verbose);
bool test_current_node_is_root(FILE *output, bool verbose);
bool run_tests_pwd(FILE *output, bool verbose);

#endif