#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_string_blank(char *str);
bool is_string_alnum(char *str);
char *strdup(const char *s);
bool is_length_valid(char *name, int min, int max);
bool is_name_valid(char *name, char *function_name);

#endif