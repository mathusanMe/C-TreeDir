#include "mkdir.h"

bool mkdir(noeud *current, char *name)
{
    if (current == NULL || !is_name_valid(name, "mkdir"))
    {
        return false;
    }

    if (!current->est_dossier)
    {
        if (VERBOSE)
        {
            printf("mkdir: %s is not a folder.\n", current->nom);
        }
        return false;
    }

    liste_noeud *children = current->fils;

    if (children == NULL)
    {
        current->fils = malloc(sizeof(liste_noeud));
        if (current->fils == NULL)
        {
            if (VERBOSE)
            {
                printf("mkdir: failed to allocate memory.\n");
            }
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
            printf("mkdir: the folder %s already exists. exit program.\n", name);
            exit(1);
        }
    }

    noeud *new_node = create_node(name, true, current, current->racine);
    if (new_node == NULL)
    {
        if (VERBOSE)
        {
            printf("mkdir: failed to create node.\n");
        }
        return false;
    }

    if (last_child == NULL)
    {
        current->fils = create_list_node(new_node, NULL);
        if (current->fils == NULL)
        {
            if (VERBOSE)
            {
                printf("mkdir: failed to create list node.\n");
            }
            free(new_node);
            return false;
        }
        return true;
    }

    last_child->succ = create_list_node(new_node, NULL);
    if (last_child->succ == NULL)
    {
        if (VERBOSE)
        {
            printf("mkdir: failed to create list node.\n");
        }
        free(new_node);
        return false;
    }

    return true;
}