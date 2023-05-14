#include "ls.h"

bool ls(noeud *current, char *path)
{
    noeud *copy_current = current;
    noeud *node_from_path = get_noeud(copy_current, path);

    if (node_from_path == NULL)
    {
        return false;
    }

    if (!node_from_path->est_dossier)
    {
        printf("ls: %s: Not a directory.\n", node_from_path->nom);
        return false;
    }

    if (node_from_path->fils == NULL)
    {
        printf("ls: %s: There is no file or directory.\n", node_from_path->nom);
        return false;
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
        printf("ls: cannot access '%s': No such directory.\n", path);
        return NULL;
    }

    return node_from_path;
}