#include "display_test.h"

void display_test(nature_of_message type, char *func_name, FILE *output)
{
    switch (type)
    {
    case NAME:
        fprintf(output, "\n[COMMAND - %s]\n", func_name);
        break;

    case SUCCESS:
        fprintf(output, "\tSUCCESS ✓ - %s\n", func_name);
        break;

    case FAILURE:
        fprintf(output, "\tFAILURE ✘ - %s\n", func_name);
        break;

    default:
        break;
    }
}

nature_of_message get_type_of_print(bool success)
{
    return success ? SUCCESS : FAILURE;
}