#ifndef TEST_CD_H
#define TEST_CD_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/cd/cd.h"

bool test_path_is_empty();
bool test_path_is_incorrect();
bool test_path_contains_file();
bool test_valid_path();
bool run_tests_cd();

#endif