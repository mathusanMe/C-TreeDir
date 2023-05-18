#ifndef TEST_PARSER_H
#define TEST_PARSER_H

#include <stdlib.h>
#include <stdbool.h>
#include "../utils/display_test.h"
#include "../../src/parser/parser.h"

bool test_inputs(char *path, size_t number_of_tests);
bool test_an_input(char *input_path);
bool compare_outputs(char *output_path, char *expected_output_path);
bool run_tests_parser();

#endif