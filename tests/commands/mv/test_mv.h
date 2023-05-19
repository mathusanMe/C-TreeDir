#ifndef TEST_MV_H
#define TEST_MV_H

#include "../../../src/utils/nodes.h"
#include "../../utils/display_test.h"
#include "../../../src/commands/mv/mv.h"

bool mv_test_file(FILE *output, bool verbose);
bool mv_test_dir(FILE *output, bool verbose);
bool mv_test_file_into_dir(FILE *output, bool verbose);
bool mv_test_dir_into_dir(FILE *output, bool verbose);
bool mv_test_file_into_newfile(FILE *output, bool verbose);
bool mv_test_dir_into_newdir(FILE *output, bool verbose);
bool run_tests_mv(FILE *output, bool verbose);

#endif