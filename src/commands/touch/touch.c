#include "touch.h"

bool touch(noeud *current, char *name)
{
    if (current == NULL || !is_name_valid(name, "touch"))
    {
        return false;
    }

    if (!current->est_dossier)
    {
        printf("touch: %s is not a folder.\n", current->nom);
        return false;
    }

    liste_noeud *children = current->fils;

    if (children == NULL)
    {
        current->fils = malloc(sizeof(liste_noeud));
        if (current->fils == NULL)
        {
            printf("touch: failed to allocate memory.\n");
            return false;
        }
        current->fils->no = create_node(name, true, current, current->racine);
        current->fils->succ = NULL;
        return true;
    }

    liste_noeud *last_child = NULL;

    for (; children != NULL; last_child = children, children = children->succ)
    {
        if (strcmp(children->no->nom, name) == 0)
        {
            printf("touch: file already exists.\n");
            return false;
        }
    }

    noeud *new_node = create_node(name, false, current, current->racine);
}