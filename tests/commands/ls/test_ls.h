#ifndef TEST_LS_H
#define TEST_LS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/ls/ls.h"

bool test_path_to_file();
bool test_path_to_empty_directory();
bool test_path_to_directory_with_files();
bool run_test_ls();

#endif