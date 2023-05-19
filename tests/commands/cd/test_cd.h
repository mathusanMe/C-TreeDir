#ifndef TEST_CD_H
#define TEST_CD_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../../utils/display_test.h"
#include "../../../src/commands/cd/cd.h"

bool test_path_is_empty(FILE *output, bool verbose);
bool test_path_is_incorrect(FILE *output, bool verbose);
bool test_path_contains_file(FILE *output, bool verbose);
bool test_valid_path(FILE *output, bool verbose);
bool run_tests_cd(FILE *output, bool verbose);

#endif