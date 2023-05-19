#ifndef TEST_RM_H
#define TEST_RM_H

#include "../../../src/utils/nodes.h"
#include "../../utils/display_test.h"
#include "../../../src/commands/rm/rm.h"

bool rm_test_file(FILE *output, bool verbose);
bool rm_test_empty_dir(FILE *output, bool verbose);
bool rm_test_not_empty_dir(FILE *output, bool verbose);
bool run_tests_rm(FILE *output, bool verbose);

#endif