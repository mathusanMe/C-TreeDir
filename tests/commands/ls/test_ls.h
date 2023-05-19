#ifndef TEST_LS_H
#define TEST_LS_H

#include "../../../src/utils/nodes.h"
#include "../../utils/display_test.h"
#include "../../../src/commands/ls/ls.h"

// typedef struct noeud noeud;

bool test_path_to_file(FILE *output, bool verbose);
bool test_path_to_empty_directory(FILE *output, bool verbose);
bool test_path_to_directory_with_files(FILE *output, bool verbose);
bool run_test_ls(FILE *output, bool verbose);

#endif