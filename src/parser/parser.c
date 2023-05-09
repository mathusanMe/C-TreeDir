#include "parser.h"

void parse_file(char *file_path)
{
    char line[MAX_LINE_LENGTH] FILE *file = fopen(file_path, "r");

    if (file == NULL)
    {
        perror("Opening file caused an error.");
        printf("'%s' could not be opened.");

        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        parse_line(line);
    }

    int closed = fclose(file);
    if (closed != 0)
    {
        perror("Closing file caused an error.");
        printf("'%s' could not be closed.");

        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}