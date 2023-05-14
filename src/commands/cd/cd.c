#include "cd.h"

noeud *cd(noeud *current, char *path)
{
    noeud *start_node = current;

    if (current == NULL || path == NULL)
    {
        return current;
    }

    if (!current->est_dossier)
    {
        printf("cd: Not a directory\n");
        return NULL;
    }

    // Copy path to a modifiable buffer
    char *modifiable_path = strdup(path);

    if (modifiable_path == NULL)
    {
        return current;
    }

    // If the path is empty, return the current node
    if (modifiable_path[0] == '\0')
    {
        printf("cd: path is empty, returning to root\n");
        free(modifiable_path);
        return current->racine;
    }

    // If the path is absolute, start from the root of the copied node
    if (modifiable_path[0] == '/')
    {
        noeud *result = cd(current->racine, modifiable_path + 1);
        free(modifiable_path);
        return result;
    }

    // If the path is relative, start from the copied current node
    for (char *next_token = strtok(modifiable_path, "/"); next_token != NULL; next_token = strtok(NULL, "/"))
    {
        if (strcmp(next_token, ".") == 0) // If the next token is ".", do nothing
        {
            continue;
        }

        if (strcmp(next_token, "..") == 0) // If the next token is "..", go to the parent
        {
            current = current->pere;
        }
        else
        {
            liste_noeud *children = current->fils;

            if (children == NULL)
            {
                printf("cd: %s: No such directory\n", next_token);
                free(modifiable_path);
                return current;
            }

            for (; children != NULL; children = children->succ)
            {
                if (strcmp(children->no->nom, next_token) == 0)
                {
                    if (!children->no->est_dossier)
                    {
                        printf("cd: %s: Not a directory\n", next_token);
                        free(modifiable_path);
                        return start_node;
                    }
                    break;
                }
            }
        }
    }
    free(modifiable_path);
    return current;
}