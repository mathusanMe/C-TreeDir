#include "cd.h"

noeud *cd(noeud *current, char *path)
{
    if (current == NULL || path == NULL)
    {
        return NULL;
    }

    if (!current->est_dossier)
    {
        printf("cd: Not a directory\n");
        return NULL;
    }

    char *modifiable_path = strdup(path);

    if (modifiable_path == NULL)
    {
        return NULL;
    }

    if (modifiable_path[0] == '\0')
    {
        printf("cd: path is empty, returning to root\n");
        free(modifiable_path);
        return current->racine;
    }

    if (modifiable_path[0] == '/')
    {
        noeud *result = cd(current->racine, modifiable_path + 1);
        free(modifiable_path);
        return result;
    }

    for (char *next_token = strtok(modifiable_path, "/"); next_token != NULL; next_token = strtok(NULL, "/"))
    {
        if (strcmp(next_token, ".") == 0)
        {
            continue;
        }

        if (strcmp(next_token, "..") == 0)
        {
            if (current->pere == NULL)
            {
                printf("cd: Can't move to parent directory, node not declared.\n");
                free(modifiable_path);
                return NULL;
            }
            current = current->pere;
            continue;
        }

        liste_noeud *children = current->fils;

        if (children == NULL)
        {
            printf("cd: %s: No such directory\n", next_token);
            free(modifiable_path);
            return NULL;
        }

        liste_noeud *child;
        for (child = children; child != NULL; child = child->succ)
        {
            if (strcmp(child->no->nom, next_token) == 0)
            {
                if (!child->no->est_dossier)
                {
                    printf("cd: %s: Not a directory\n", next_token);
                    free(modifiable_path);
                    return NULL;
                }
                break;
            }
        }

        if (child == NULL)
        {
            printf("cd: %s: No such directory\n", next_token);
            free(modifiable_path);
            return NULL;
        }

        // Update current to the found child
        current = child->no;
    }

    free(modifiable_path);
    return current;
}
