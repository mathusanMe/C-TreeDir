#ifndef TEST_MV_H
#define TEST_MV_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/mv/mv.h"

bool mv_test_file();
bool mv_test_dir();
bool mv_test_file_into_dir();
bool mv_test_dir_into_dir();
bool mv_test_file_into_newfile();
bool mv_test_dir_into_newdir();
bool run_tests_mv();

#endif