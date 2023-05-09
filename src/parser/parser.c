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

void parse_line(char *line)
{
    char *strToken = strtok(line, SEPARATORS);

    if (strcmp(strToken, "ls") == 0)
    {
        // TODO: Check that next token is null
        // TODO: Send toward ls command with no arguments
    }

    if (strcmp(strToken, "cd") == 0)
    {
        // TODO: Disintguish cases
        // TODO: Send toward cd command with associated arguments
    }

    if (strcmp(strToken, "pwd") == 0)
    {
        // TODO: Check that next token is null
        // TODO: Send toward pwd command with no arguments
    }

    if (strcmp(strToken, "mkdir") == 0)
    {
        // TODO: Check that next token is not null and the next is null
        // TODO: Send toward mkdir command with one arguments
    }

    if (strcmp(strToken, "touch") == 0)
    {
        // TODO: Check that next token is not null and the next is null
        // TODO: Send toward touch command with one arguments
    }

    if (strcmp(strToken, "rm") == 0)
    {
        // TODO: Check that next token is not null and the next is null
        // TODO: Send toward rm command with one arguments
    }

    if (strcmp(strToken, "cp") == 0)
    {
        // TODO: Check that next two tokens are not null and that the third one is
        // TODO: Send toward cp command with two arguments
    }

    if (strcmp(strToken, "mv") == 0)
    {
        // TODO: Check that next two tokens are not null and that the third one is
        // TODO: Send toward mv command with two arguments
    }

    if (strcmp(strToken, "print") == 0)
    {
        // TODO: Check that next token is null
        // TODO: Send toward print command with no arguments
    }
}