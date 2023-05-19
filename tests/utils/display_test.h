#ifndef DISPLAY_TEST_H
#define DISPLAY_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum
{
    NAME,
    SUCCESS,
    FAILURE
} nature_of_message;

void display_test(nature_of_message type, char *func_name, FILE *output);
nature_of_message get_type_of_print(bool success);

#endif