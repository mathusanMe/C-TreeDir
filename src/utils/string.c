#include "string.h"

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