#ifndef TEST_WC_H
#define TEST_WC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/wc/wc.h"

bool test_empty_file();
bool test_one_line_file();
bool test_multiple_lines_file();
bool run_wc_tests();

#endif