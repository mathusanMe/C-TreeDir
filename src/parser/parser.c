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

    noeud *root = create_root();
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

        free_node(root);

        return false;
    }

    free_node(root);

    return true;
}

noeud *parse_line(noeud *current, char *line)
{
    char *strToken = strtok(line, SEPARATORS);
    char **arguments = NULL;

    if (strcmp(strToken, "ls") == 0)
    {
        arguments = calloc(NB_LS_ARGUMENTS, sizeof(char *));

        if (parse_arguments(strToken, "ls", NB_LS_ARGUMENTS, arguments))
        {
            ls(current, arguments[0]);
        }
        else if ((strToken = strtok(NULL, SEPARATORS)) == NULL)
        {
            ls(current, ".");
        }

        free_arguments(arguments, NB_LS_ARGUMENTS);
    }

    else if (strcmp(strToken, "cd") == 0)
    {
        arguments = calloc(NB_CD_ARGUMENTS, sizeof(char *));
        noeud *node = NULL;
        if (parse_arguments(strToken, "cd", NB_CD_ARGUMENTS, arguments))
        {
            node = cd(current, arguments[0]);
        }
        else if ((strToken = strtok(NULL, SEPARATORS)) == NULL)
        {
            node = cd(current, "/");
        }

        if (node != NULL)
        {
            current = node;
        }

        free_arguments(arguments, NB_CD_ARGUMENTS);
    }

    else if (strcmp(strToken, "pwd") == 0)
    {
        if (parse_arguments(strToken, "pwd", NB_PWD_ARGUMENTS, arguments))
        {
            pwd(current);
        }
    }

    else if (strcmp(strToken, "mkdir") == 0)
    {
        arguments = malloc(NB_MKDIR_ARGUMENTS * sizeof(char *));

        if (parse_arguments(strToken, "mkdir", NB_MKDIR_ARGUMENTS, arguments))
        {
            mkdir(current, arguments[0]);
        }

        free_arguments(arguments, NB_MKDIR_ARGUMENTS);
    }

    else if (strcmp(strToken, "touch") == 0)
    {
        arguments = malloc(NB_TOUCH_ARGUMENTS * sizeof(char *));

        if (parse_arguments(strToken, "touch", NB_TOUCH_ARGUMENTS, arguments))
        {
            touch(current, arguments[0]);
        }

        free_arguments(arguments, NB_TOUCH_ARGUMENTS);
    }

    else if (strcmp(strToken, "rm") == 0)
    {
        arguments = malloc(NB_RM_ARGUMENTS * sizeof(char *));

        if (parse_arguments(strToken, "rm", NB_RM_ARGUMENTS, arguments))
        {
            rm(current, arguments[0]);
        }

        free_arguments(arguments, NB_RM_ARGUMENTS);
    }

    else if (strcmp(strToken, "cp") == 0)
    {
        arguments = malloc(NB_CP_ARGUMENTS * sizeof(char *));

        parse_arguments(strToken, "cp", NB_CP_ARGUMENTS, arguments);
        // TODO: Send toward cp command with two arguments

        free_arguments(arguments, NB_CP_ARGUMENTS);
    }

    else if (strcmp(strToken, "mv") == 0)
    {
        arguments = malloc(NB_MV_ARGUMENTS * sizeof(char *));

        parse_arguments(strToken, "mv", NB_MV_ARGUMENTS, arguments);
        // TODO: Send toward mv command with two arguments

        free_arguments(arguments, NB_MV_ARGUMENTS);
    }

    else if (strcmp(strToken, "print") == 0)
    {
        if (parse_arguments(strToken, "print", NB_PRINT_ARGUMENTS, arguments))
        {
            print(current->racine);
        }
    }

    return current;
}

bool parse_arguments(char *strToken, char *command, size_t total_arguments, char **arguments)
{
    int increment = 0;

    while (increment < total_arguments)
    {
        strToken = strtok(NULL, SEPARATORS);
        if (strToken == NULL)
        {
            printf("Error: %s: not enough arguments\n", command);
            return false;
        }

        *(arguments + increment) = malloc((strlen(strToken) + 1) * sizeof(char));

        if (*(arguments + increment) == NULL)
        {
            printf("Error %s: Unable to allocate memory.\n", command);

            return false;
        }

        strcpy(*(arguments + increment), strToken);

        ++increment;
    }

    strToken = strtok(NULL, SEPARATORS);
    if (strToken != NULL && !is_string_blank(strToken) && !contains_newline(strToken))
    {
        printf("Error: %s: too much arguments\n", command);
        return false;
    }

    return true;
}

void free_arguments(char **args, size_t size)
{
    for (size_t index = 0; index < size; ++index)
    {
        free(*(args + index));
    }

    free(args);
}