#include "cd.h"

node *cd(node *current, char *path)
{

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
    for (char *next = strtok(path, "/"); next != NULL; next = strtok(NULL, "/"))
    {
        if (strcmp(next, ".") == 0) // If the next token is ".", do nothing
        {
            next = strtok(NULL, "/");
        }
        else if (strcmp(next, "..") == 0) // If the next token is "..", go to the parent
        {
            current = current->parent;
            next = strtok(NULL, "/");
        }
        else if (current->is_folder)
        {
            list_node *children = current->children;

            for (; children != NULL; children = children->succ)
            {
                if (strcmp(children->no->name, next) == 0)
                {
                    current = children->no;
                    break;
                }
            }
        }
        else
        {
            printf("cd: %s: No such directory\n", next);
            return NULL;
        }
    }

    return current;
}