#include "parser.h"

bool parse_file(char *input_file_path, FILE *output, bool verbose)
{
    char line[MAX_LINE_LENGTH];
    FILE *INPUT = fopen(input_file_path, "r");

    if (INPUT == NULL)
    {
        perror("Opening file caused an error.");
        if (verbose)
        {
            fprintf(output, "'%s' could not be opened.\n", input_file_path);
        }

        exit(EXIT_FAILURE);
    }

    noeud *root = create_root(output, verbose);
    noeud *current = root;

    while (fgets(line, MAX_LINE_LENGTH, INPUT) != NULL)
    {
        current = parse_line(current, line, output, verbose);
    }

    int closed = fclose(INPUT);
    if (closed != 0)
    {
        perror("Closing file caused an error.");
        if (verbose)
        {
            fprintf(output, "'%s' could not be closed.\n", input_file_path);
        }

        free_node(root);

        exit(EXIT_FAILURE);
    }

    free_node(root);

    return true;
}

noeud *parse_line(noeud *current, char *line, FILE *output, bool verbose)
{
    char *strToken = strtok(line, SEPARATORS);

    if (strToken == NULL || is_string_blank(strToken) || contains_newline(strToken))
    {
        return current;
    }

    char **arguments = NULL;

    if (strcmp(strToken, "ls") == 0)
    {
        arguments = calloc(NB_LS_ARGUMENTS, sizeof(char *));

        if (parse_arguments(strToken, "ls", NB_LS_ARGUMENTS, arguments, true, output, verbose))
        {
            ls(current, arguments[0], output, verbose);
        }
        else if ((strToken = strtok(NULL, SEPARATORS)) == NULL)
        {
            ls(current, ".", output, verbose);
        }

        free_arguments(arguments, NB_LS_ARGUMENTS);
    }

    else if (strcmp(strToken, "cd") == 0)
    {
        arguments = calloc(NB_CD_ARGUMENTS, sizeof(char *));
        noeud *node = NULL;
        if (parse_arguments(strToken, "cd", NB_CD_ARGUMENTS, arguments, true, output, verbose))
        {
            node = cd(current, arguments[0], output, verbose);
        }
        else if ((strToken = strtok(NULL, SEPARATORS)) == NULL)
        {
            node = cd(current, "/", output, verbose);
        }

        if (node != NULL)
        {
            current = node;
        }

        free_arguments(arguments, NB_CD_ARGUMENTS);
    }

    else if (strcmp(strToken, "pwd") == 0)
    {
        if (parse_arguments(strToken, "pwd", NB_PWD_ARGUMENTS, arguments, true, output, verbose))
        {
            pwd(current, output, verbose);
        }
    }

    else if (strcmp(strToken, "mkdir") == 0)
    {
        arguments = malloc(NB_MKDIR_ARGUMENTS * sizeof(char *));

        if (parse_arguments(strToken, "mkdir", NB_MKDIR_ARGUMENTS, arguments, false, output, verbose))
        {
            mkdir(current, arguments[0], output, verbose);
        }

        free_arguments(arguments, NB_MKDIR_ARGUMENTS);
    }

    else if (strcmp(strToken, "touch") == 0)
    {
        arguments = malloc(NB_TOUCH_ARGUMENTS * sizeof(char *));

        if (parse_arguments(strToken, "touch", NB_TOUCH_ARGUMENTS, arguments, false, output, verbose))
        {
            touch(current, arguments[0], output, verbose);
        }

        free_arguments(arguments, NB_TOUCH_ARGUMENTS);
    }

    else if (strcmp(strToken, "rm") == 0)
    {
        arguments = malloc(NB_RM_ARGUMENTS * sizeof(char *));

        parse_arguments(strToken, "rm", NB_RM_ARGUMENTS, arguments, false, output, verbose);
        {
            rm(current, arguments[0], output, verbose);
        }

        free_arguments(arguments, NB_RM_ARGUMENTS);
    }

    else if (strcmp(strToken, "cp") == 0)
    {
        arguments = malloc(NB_CP_ARGUMENTS * sizeof(char *));

        parse_arguments(strToken, "cp", NB_CP_ARGUMENTS, arguments, false, output, verbose);
        {
            cp(current, arguments[0], arguments[1], output, verbose);
        }

        free_arguments(arguments, NB_CP_ARGUMENTS);
    }

    else if (strcmp(strToken, "mv") == 0)
    {
        arguments = malloc(NB_MV_ARGUMENTS * sizeof(char *));

        parse_arguments(strToken, "mv", NB_MV_ARGUMENTS, arguments, false, output, verbose);
        {
            mv(current, arguments[0], arguments[1], output, verbose);
        }

        free_arguments(arguments, NB_MV_ARGUMENTS);
    }

    else if (strcmp(strToken, "print") == 0)
    {
        if (parse_arguments(strToken, "print", NB_PRINT_ARGUMENTS, arguments, true, output, verbose))
        {
            print(current->racine, output);
        }
    }

    return current;
}

bool parse_arguments(char *strToken, char *command, size_t total_arguments, char **arguments, bool could_have_no_arguments, FILE *output, bool verbose)
{
    int increment = 0;

    while (increment < total_arguments)
    {
        strToken = strtok(NULL, SEPARATORS);
        if (strToken == NULL)
        {
            if (!could_have_no_arguments)
            {
                fprintf(output, "Error: %s: not enough arguments\n", command);
            }
            return false;
        }

        *(arguments + increment) = malloc((strlen(strToken) + 1) * sizeof(char));

        if (*(arguments + increment) == NULL)
        {
            if (verbose)
            {
                fprintf(output, "Error %s: Unable to allocate memory.\n", command);
            }

            return false;
        }

        strcpy(*(arguments + increment), strToken);

        ++increment;
    }

    strToken = strtok(NULL, SEPARATORS);
    if (strToken != NULL && !is_string_blank(strToken) && !contains_newline(strToken))
    {
        if (verbose)
        {
            fprintf(output, "Error: %s: too much arguments\n", command);
        }
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