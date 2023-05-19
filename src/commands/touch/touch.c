#include "touch.h"

bool touch(noeud *current, char *name, FILE *output, bool verbose)
{
    if (current == NULL || !is_name_valid(name, "touch", output, verbose))
    {
        return false;
    }

    if (!current->est_dossier)
    {
        if (verbose)
        {
            fprintf(output, "touch: %s is not a folder.\n", current->nom);
        }
        return false;
    }

    liste_noeud *children = current->fils;

    if (children == NULL)
    {
        current->fils = malloc(sizeof(liste_noeud));
        if (current->fils == NULL)
        {
            if (verbose)
            {
                fprintf(output, "touch: failed to allocate memory.\n");
            }
            return false;
        }
        current->fils->no = create_node(name, false, current, current->racine, output, verbose);
        current->fils->succ = NULL;
        return true;
    }

    liste_noeud *last_child = NULL;

    for (; children != NULL; last_child = children, children = children->succ)
    {
        if (strcmp(children->no->nom, name) == 0)
        {
            fprintf(output, "touch: file already exists. exit program.\n");
            exit(1);
        }
    }

    noeud *new_node = create_node(name, false, current, current->racine, output, verbose);
    if (new_node == NULL)
    {
        if (verbose)
        {
            fprintf(output, "touch: failed to create node.\n");
        }
        return false;
    }

    last_child->succ = create_list_node(new_node, NULL, output, verbose);
    if (last_child->succ == NULL)
    {
        if (verbose)
        {
            fprintf(output, "touch: failed to create list node.\n");
        }
        free(new_node);
        return false;
    }

    return true;
}