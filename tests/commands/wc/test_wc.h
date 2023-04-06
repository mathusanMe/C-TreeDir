#ifndef TEST_WC_H
#define TEST_WC_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/wc/wc.h"

int test_not_existing_file();
int test_empty_file();
int test_one_line_file();
int test_multiple_lines_file();
int run_wc_tests();

#endif