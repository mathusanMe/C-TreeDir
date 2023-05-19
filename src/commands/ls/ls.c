#include "ls.h"

bool ls(noeud *current, char *path)
{
    noeud *node_from_path = cd(current, path);

    if (node_from_path == NULL || !node_from_path->est_dossier)
    {
        if (VERBOSE)
        {
            printf("ls: Cannot acces to %s: Not a directory.\n", node_from_path == NULL ? "node" : node_from_path->nom);
        }
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