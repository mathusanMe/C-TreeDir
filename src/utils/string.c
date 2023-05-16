#include "string.h"

bool contains(char **string_array, size_t size, char *word)
{
    for (char **str = string_array; str < string_array + size; ++str)
    {
        if (strcmp(*str, word) == 0)
        {
            return true;
        }
    }
    return false;
}

bool is_string_blank(char *str)
{
    while (*str != '\0')
    {
        if (!isblank(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

bool contains_newline(char *str)
{
    while (*str != '\0')
    {
        // printf("%s\n", *str == '\n' ? "true" : "false");
        if (*str == '\n')
        {
            return true;
        }
        str++;
    }
    return false;
}

bool is_string_alnum(char *str)
{
    while (*str != '\0')
    {
        if (!isalnum(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

char *strdup(const char *s)
{
    char *d = malloc(strlen(s) + 1);
    if (d == NULL)
    {
        return NULL;
    }
    strcpy(d, s);
    return d;
}