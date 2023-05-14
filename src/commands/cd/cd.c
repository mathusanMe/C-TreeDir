#include "cd.h"

noeud *cd(noeud *current, char *path)
{
    if (current == NULL || path == NULL)
    {
        return NULL;
    }

    if (!current->est_dossier)
    {
        VERBOSE_PRINT ? printf("cd: Not a directory.\n") : 0;
        return NULL;
    }

    char *modifiable_path = strdup(path);

    if (modifiable_path == NULL)
    {
        return NULL;
    }

    if (modifiable_path[0] == '\0')
    {
        VERBOSE_PRINT ? printf("cd: path is empty, returning to root.\n") : 0;
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
                VERBOSE_PRINT ? printf("cd: Can't move to parent directory, node not declared.\n") : 0;
                free(modifiable_path);
                return NULL;
            }
            current = current->pere;
            continue;
        }

        liste_noeud *children = current->fils;

        if (children == NULL)
        {
            VERBOSE_PRINT ? printf("cd: %s: No such directory.\n", next_token) : 0;
            free(modifiable_path);
            return NULL;
        }

        liste_noeud *child = children;
        while (child != NULL && strcmp(child->no->nom, next_token) != 0)
        {
            child = child->succ;
        }

        if (child == NULL)
        {
            VERBOSE_PRINT ? printf("cd: %s: No such directory.\n", next_token) : 0;
            free(modifiable_path);
            return NULL;
        }

        if (!child->no->est_dossier)
        {
            VERBOSE_PRINT ? printf("cd: %s: Not a directory.\n", next_token) : 0;
            free(modifiable_path);
            return NULL;
        }
        current = child->no;
    }
    free(modifiable_path);
    return current;
}