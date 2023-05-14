#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_string_blank(char* str);
bool is_string_alnum(char* str);
char *strdup(const char *s);

#endif