#ifndef STRING_H
#define STRING_H

#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool contains(char **string_array, size_t size, char *word);
bool is_string_blank(char *str);
bool contains_newline(char *str);
bool is_string_alnum(char *str);
char *strdup(const char *s);

#endif