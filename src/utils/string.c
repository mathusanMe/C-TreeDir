#include "string.h"

bool is_empty(char *str)
{
    if (str[0] == '\0')
    {
        return true;
    }

    return false;
}

bool is_alpnum(char *str)
{

    for (char *c = str; *c != '\0'; ++c)
    {
        if (!isalnum(*c))
        {
            return false;
        }
    }

    return true;
}

bool is_length_valid(char *str, size_t min, size_t max)
{
    size_t len = strlen(str);
    if (len < min || len > max)
    {
        return false;
    }
    return true;
}