#include "cd.h"

node *cd(node *current, char *path)
{
    if (current == NULL)
    {
        return NULL;
    }

    if (path == NULL)
    {
        return current;
    }

    // If the path is empty, return the current node
    if (path[0] == '\0')
    {
        return current->root;
    }

    // If the path is absolute, start from the root
    if (path[0] == '/')
    {
        return cd(current->root, path + 1);
    }

    // If the path is relative, start from the current node
    for (char *next_token = strtok(path, "/"); next_token != NULL; next_token = strtok(NULL, "/"))
    {
        if (strcmp(next_token, ".") == 0) // If the next token is ".", do nothing
        {
            next_token = strtok(NULL, "/");
        }
        else if (strcmp(next_token, "..") == 0) // If the next token is "..", go to the parent
        {
            current = current->parent;
            next_token = strtok(NULL, "/");
        }
        else if (current->is_folder)
        {
            list_node *children = current->children;

            for (; children != NULL; children = children->succ)
            {
                if (strcmp(children->no->name, next_token) == 0)
                {
                    current = children->no;
                    break;
                }
            }
        }
        else
        {
            printf("cd: %s: No such directory\n", next_token);
            return NULL;
        }
    }

    return current;
}