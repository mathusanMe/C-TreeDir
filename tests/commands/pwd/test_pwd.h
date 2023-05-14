#ifndef TEST_PWD_H
#define TEST_PWD_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/pwd/pwd.h"

bool test_current_node_is_null();
bool test_current_node_is_root();
bool test_current_node_is_correct();
bool run_tests_pwd();

#endif