#ifndef MAIN_TEST_H
#define MAIN_TEST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "commands/ls/test_ls.h"
#include "commands/cd/test_cd.h"
#include "commands/pwd/test_pwd.h"
#include "commands/mkdir/test_mkdir.h"
#include "commands/touch/test_touch.h"
#include "commands/print/test_print.h"
#include "parser/test_parser.h"

bool run_tests(FILE *output, bool verbose);

#endif