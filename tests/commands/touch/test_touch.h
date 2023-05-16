#ifndef TEST_TOUCH_H
#define TEST_TOUCH_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/touch/touch.h"

bool touch_test_name_empty();
bool touch_test_name_contains_non_alnum_char();
bool touch_test_name_too_long();
bool touch_test_name_already_exists();
bool run_tests_touch();

#endif