#include "ls.h"

bool ls(noeud *current, char *path)
{
    noeud *node_from_path = get_noeud(current, path);

    if (node_from_path == NULL)
    {
        return false;
    }

    if (!node_from_path->est_dossier)
    {
        VERBOSE_PRINT ? printf("ls: %s: Not a directory.\n", node_from_path->nom) : 0;
        return false;
    }

    if (node_from_path->fils == NULL)
    {
        return true;
    }

    for (liste_noeud *liste = node_from_path->fils; liste != NULL; liste = liste->succ)
    {
        printf("%s\n", liste->no->nom);
    }

    return true;
}

noeud *get_noeud(noeud *current, char *path)
{
    noeud *node_from_path = cd(current, path);

    if (node_from_path == NULL)
    {
        VERBOSE_PRINT ? printf("ls: cannot access '%s': No such directory.\n", path) : 0;
        return NULL;
    }

    return node_from_path;
}