#include "output.h"

extern FILE *OUTPUT;
extern bool VERBOSE;

void set_output(FILE *output)
{
    OUTPUT = output;
}

void close_output()
{
    if (OUTPUT != NULL)
    {
        int closed = fclose(OUTPUT);

        if (closed != 0)
        {
            perror("Closing output file caused an error.");
            exit(EXIT_FAILURE);
        }
    }
}

void set_verbose(bool verbose)
{
    VERBOSE = verbose;
}