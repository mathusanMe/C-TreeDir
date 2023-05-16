#include "parser.h"

bool parse_file(char *file_path)
{
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(file_path, "r");

    if (file == NULL)
    {
        perror("Opening file caused an error.");
        printf("'%s' could not be opened.", file_path);

        return false;
    }

    noeud *root; // = create_root()
    noeud *current = root;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        current = parse_line(current, line);
    }

    int closed = fclose(file);
    if (closed != 0)
    {
        perror("Closing file caused an error.");
        printf("'%s' could not be closed.", file_path);

        return false;
    }

    return true;
}

noeud *parse_line(noeud *current, char *line)
{
    char *strToken = strtok(line, SEPARATORS);

    if (strcmp(strToken, "ls") == 0)
    {
        parse_arguments("ls", NB_LS_ARGUMENTS);
        ls(current, ".");
        return current;
    }

    if (strcmp(strToken, "cd") == 0)
    {
        // TODO: Disintguish cases
        // TODO: Send toward cd command with associated arguments

        return NULL;
    }

    if (strcmp(strToken, "pwd") == 0)
    {
        parse_arguments("pwd", NB_PWD_ARGUMENTS);
        // TODO: Send toward pwd command with no arguments
        return current;
    }

    if (strcmp(strToken, "mkdir") == 0)
    {
        char **arguments = parse_arguments("mkdir", NB_MKDIR_ARGUMENTS);
        // TODO: Send toward mkdir command with one arguments
        return current;
    }

    if (strcmp(strToken, "touch") == 0)
    {
        char **arguments = parse_arguments("touch", NB_TOUCH_ARGUMENTS);
        // TODO: Send toward touch command with one arguments
        return current;
    }

    if (strcmp(strToken, "rm") == 0)
    {
        char **arguments = parse_arguments("rm", NB_RM_ARGUMENTS);
        // TODO: Send toward rm command with one arguments
        return current;
    }

    if (strcmp(strToken, "cp") == 0)
    {
        char **arguments = parse_arguments("cp", NB_CP_ARGUMENTS);
        // TODO: Send toward cp command with two arguments
        return current;
    }

    if (strcmp(strToken, "mv") == 0)
    {
        char **arguments = parse_arguments("mv", NB_MV_ARGUMENTS);
        // TODO: Send toward mv command with two arguments
        return current;
    }

    if (strcmp(strToken, "print") == 0)
    {
        parse_arguments("print", NB_PRINT_ARGUMENTS);
        // TODO: Send toward print command with no arguments
        return current;
    }
}

char **parse_arguments(char *command, int total_arguments)
{
    char *strToken = NULL;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
    int increment = 0;

    while (increment < total_arguments)
    {
        strToken = strtok(NULL, SEPARATORS);
        if (strToken == NULL)
        {
            printf("Error: %s: not enough arguments\n", command);
            exit(EXIT_FAILURE);
        }

        *(arguments + increment) = strToken;
        ++increment;
    }

    strToken = strtok(NULL, SEPARATORS);
    if (strToken != NULL)
    {
        printf("Error: %s: too much arguments\n", command);
        exit(EXIT_FAILURE);
    }

    return arguments;
}