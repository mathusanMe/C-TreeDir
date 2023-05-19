#include "ls.h"

bool ls(noeud *current, char *path, FILE *output, bool verbose)
{
    noeud *node_from_path = cd(current, path, output, false);

    if (node_from_path == NULL || !node_from_path->est_dossier)
    {
        if (verbose)
        {
            fprintf(output, "ls: Cannot acces to %s: Not a directory.\n", node_from_path == NULL ? "node" : node_from_path->nom);
        }
        return false;
    }

    if (node_from_path->fils == NULL)
    {
        return true;
    }

    for (liste_noeud *liste = node_from_path->fils; liste != NULL; liste = liste->succ)
    {
        fprintf(output, "%s\n", liste->no->nom);
    }

    return true;
}