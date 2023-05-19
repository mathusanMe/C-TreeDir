#ifndef TEST_RM_H
#define TEST_RM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/rm/rm.h"

bool rm_test_file();
bool rm_test_empty_dir();
bool rm_test_not_empty_dir();
bool run_tests_rm();

#endif