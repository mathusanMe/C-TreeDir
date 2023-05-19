#include "cd.h"

noeud *cd(noeud *current, char *path, FILE *output, bool verbose)
{
    if (current == NULL || path == NULL)
    {
        return NULL;
    }

    if (!current->est_dossier)
    {
        if (verbose)
        {
            fprintf(output, "cd: Not a directory.\n");
        }
        return NULL;
    }

    char *modifiable_path = strdup(path);

    if (modifiable_path == NULL)
    {
        return NULL;
    }

    if (modifiable_path[0] == '\0')
    {
        free(modifiable_path);
        return current->racine;
    }

    if (modifiable_path[0] == '/')
    {
        noeud *result = cd(current->racine, modifiable_path + 1, output, verbose);
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
                if (verbose)
                {
                    fprintf(output, "cd: Can't move to parent directory, node not declared.\n");
                }
                free(modifiable_path);
                return NULL;
            }
            current = current->pere;
            continue;
        }

        liste_noeud *children = current->fils;

        if (children == NULL)
        {
            if (verbose)
            {
                fprintf(output, "cd: %s: No such directory.\n", next_token);
            }
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
            if (verbose)
            {
                fprintf(output, "cd: %s: No such directory.\n", next_token);
            }
            free(modifiable_path);
            return NULL;
        }

        if (!child->no->est_dossier)
        {
            if (verbose)
            {
                fprintf(output, "cd: %s: Not a directory.\n", next_token);
            }
            free(modifiable_path);
            return NULL;
        }
        current = child->no;
    }
    free(modifiable_path);
    return current;
}