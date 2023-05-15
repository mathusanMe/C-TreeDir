#ifndef TEST_MKDIR_H
#define TEST_MKDIR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/mkdir/mkdir.h"

bool test_name_empty();
bool test_name_contains_non_alnum_char();
bool test_name_too_long();
bool test_name_already_exists();
bool run_test_mkdir();

#endif