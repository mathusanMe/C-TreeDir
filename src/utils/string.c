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