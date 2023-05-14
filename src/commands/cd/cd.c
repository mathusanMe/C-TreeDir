#include "cd.h"

node *cd(node *current, char *path)
{
    if (current == NULL || path == NULL)
    {
        return current;
    }

    if (!current->is_folder)
    {
        printf("cd: Not a directory\n");
        return NULL;
    }

    // Copy path to a modifiable buffer
    char *modifiable_path = strdup(path);
    if (modifiable_path == NULL)
    {
        return NULL;
    }

    // If the path is empty, return the current node
    if (modifiable_path[0] == '\0')
    {
        free(modifiable_path);
        return current->root;
    }

    // If the path is absolute, start from the root
    if (modifiable_path[0] == '/')
    {
        node *result = cd(current->root, modifiable_path + 1);
        free(modifiable_path);
        return result;
    }

    // If the path is relative, start from the current node
    for (char *next_token = strtok(modifiable_path, "/"); next_token != NULL; next_token = strtok(NULL, "/"))
    {
        if (strcmp(next_token, ".") == 0) // If the next token is ".", do nothing
        {
            continue;
        }

        if (strcmp(next_token, "..") == 0) // If the next token is "..", go to the parent
        {
            current = current->parent;
        }
        else
        {
            list_node *children = current->children;

            if (children == NULL)
            {
                printf("cd: %s: No such directory\n", next_token);
                free(modifiable_path);
                return NULL;
            }

            for (; children != NULL; children = children->succ)
            {
                if (strcmp(children->no->name, next_token) == 0)
                {
                    if (!children->no->is_folder)
                    {
                        printf("cd: %s: Not a directory\n", next_token);
                        free(modifiable_path);
                        return NULL;
                    }
                    current = children->no;
                    break;
                }
            }
        }
    }

    free(modifiable_path);
    return current;
}
