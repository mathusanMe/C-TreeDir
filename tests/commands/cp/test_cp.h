#ifndef TEST_CP_H
#define TEST_CP_H

#include "../../../src/utils/nodes.h"
#include "../../utils/display_test.h"
#include "../../../src/commands/cp/cp.h"

bool test_cp_file(FILE *output, bool verbose);
bool test_cp_dir(FILE *output, bool verbose);
bool run_tests_cp(FILE *output, bool verbose);

#endif