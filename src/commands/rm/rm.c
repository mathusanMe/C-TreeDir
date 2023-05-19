#include "rm.h"

bool rm(noeud *current, char *path)
{
    nearest *nrst = get_nearest(current, path);

    if (nrst == NULL || nrst->parent == NULL || nrst->name == NULL)
    {
        exit_system("rm: error while getting nearest dir. exit program.\n", 1);
    }

    bool deleted = remove_child(current, nrst->parent, nrst->name);
    free(nrst);
    return deleted;
}

bool remove_child(noeud *current, noeud *to_delete_parent, char *name)
{
    if (to_delete_parent == NULL || name == NULL)
    {
        return false;
    }

    liste_noeud *children = to_delete_parent->fils;

    if (children == NULL)
    {
        exit_system("rm: file does not exist. exit program.", 1);
    }

    noeud *first_child = children->no;
    if (strcmp(first_child->nom, name) == 0)
    {
        if (is_nearest_dir_a_parent(current, first_child))
        {
            exit_system("rm: cannot delete a parent folder. exit program.\n", 1);
        }

        to_delete_parent->fils = children->succ;
        free_node(first_child);
        free(children);
        return true;
    }

    for (liste_noeud *child = children->succ; child != NULL; child = child->succ, children = children->succ)
    {
        if ((strcmp(child->no->nom, name)) == 0)
        {
            noeud *to_delete = child->no;

            if (is_nearest_dir_a_parent(current, to_delete))
            {
                exit_system("rm: cannot delete a parent folder. exit program.\n", 1);
            }

            children->succ = child->succ;
            free_node(to_delete);
            free(child);
            return true;
        }
    }
    return false;
}

bool is_nearest_dir_a_parent(noeud *current, noeud *node_to_rm)
{
    if (node_to_rm == current->racine)
    {
        return true;
    }

    for (; current != current->racine; current = current->pere)
    {
        if (current == node_to_rm)
        {
            return true;
        }
    }

    return false;
}

void exit_system(char *message, int code)
{
    printf("%s\n", message);
    exit(code);
}