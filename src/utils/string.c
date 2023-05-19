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
    strncpy(d, s, strlen(s));
    d[strlen(s)] = '\0';
    return d;
}

bool is_length_valid(char *name, int min, int max)
{
    int length = strlen(name);

    if (length < min || length > max)
    {
        return false;
    }

    return true;
}

bool is_name_valid(char *name, char *function_name, FILE *output, bool verbose)
{
    if (name == NULL)
    {
        if (verbose)
        {
            fprintf(output, "%s: the name is null.\n", function_name);
        }
        return false;
    }

    if (is_string_blank(name))
    {
        if (verbose)
        {
            fprintf(output, "%s: the name is blank.\n", function_name);
        }
        return false;
    }

    if (!(is_string_alnum(name)))
    {
        if (verbose)
        {
            fprintf(output, "%s: the name is not alphanumeric.\n", function_name);
        }
        return false;
    }

    if (!(is_length_valid(name, 1, 99)))
    {
        if (verbose)
        {
            fprintf(output, "%s: the name is longer than 99 characters.\n", function_name);
        }
        return false;
    }

    return true;
}