#ifndef MAIN_H
#define MAIN_H

#define TESTS_KEYS                       \
    {                                    \
        "test", "tests", "TEST", "TESTS" \
    }

#define TESTS_KEYS_SIZE 4

#define VERBOSE_KEYS                                                           \
    {                                                                          \
        "verbose", "-verbose", "--verbose", "VERBOSE", "-VERBOSE", "--VERBOSE" \
    }

#define VERBOSE_KEYS_SIZE 4

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utils/output.h"
#include "utils/nodes.h"
#include "../tests/main_test.h"

extern bool VERBOSE;
extern FILE *OUTPUT;

int main(int argc, char *argv[]);

#endif