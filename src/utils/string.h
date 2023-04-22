#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_empty(char *str);
bool is_alpnum(char *str);
bool is_length_valid(char *str, size_t min, size_t max);

#endif