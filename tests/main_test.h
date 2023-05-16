#ifndef MAIN_TEST_H
#define MAIN_TEST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../src/utils/math.h"
#include "commands/mkdir/test_mkdir.h"
#include "commands/cd/test_cd.h"
#include "commands/ls/test_ls.h"
#include "parser/test_parser.h"

bool run_tests();

#endif