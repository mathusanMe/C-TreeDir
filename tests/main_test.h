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
#include "commands/mv/test_mv.h"
#include "commands/rm/test_rm.h"
#include "commands/cp/test_cp.h"
#include "commands/print/test_print.h"

bool run_tests(FILE *output, bool verbose);

#endif