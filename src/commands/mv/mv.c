#include "mv.h"

bool mv(noeud *current, char *src, char *dest, FILE *output, bool verbose)
{
    nearest *nrst_src = get_nearest(current, src);
    nearest *nrst_dest = get_nearest(current, dest);

    if (nrst_src == NULL || nrst_dest == NULL)
    {
        exit_system("mv: cannot allocate memory.\n", 1);
    }

    if (is_nearest_null(nrst_src) || is_nearest_null(nrst_dest))
    {
        exit_system("mv: error while getting nearest dir. exit program.\n", 1);
    }

    update_destination(nrst_dest, nrst_src->name);

    bool moved = move(current, nrst_src, nrst_dest, output, verbose);
    free(nrst_src);
    free(nrst_dest);
    return moved;
}

void update_destination(nearest *nrst, char *name)
{
    if (is_nearest_null(nrst))
    {
        return;
    }

    for (liste_noeud *children = nrst->parent->fils; children != NULL; children = children->succ)
    {
        noeud *child = children->no;
        if ((strcmp(child->nom, nrst->name)) == 0)
        {
            if (child->est_dossier)
            {
                nrst->parent = child;
                strncpy(nrst->name, name, strlen(name) + 1);
            }
            return;
        }
    }
}

bool move(noeud *current, nearest *nrst_src, nearest *nrst_dest, FILE *output, bool verbose)
{
    liste_noeud *children = nrst_src->parent->fils;

    if (children == NULL)
    {
        exit_system("mv: file does not exist. exit program.", 1);
    }

    noeud *first_child = children->no;
    if (strcmp(first_child->nom, nrst_src->name) == 0)
    {
        if (is_file_a_parent(current, first_child))
        {
            exit_system("mv: cannot delete a parent folder. exit program.\n", 1);
        }

        nrst_src->parent->fils = children->succ;
        if (is_name_valid(nrst_dest->name, "mv", output, verbose))
        {
            strncpy(first_child->nom, nrst_dest->name, strlen(nrst_dest->name) + 1);
        }
        add_child(nrst_dest->parent, first_child, output, verbose);
        first_child->pere = nrst_dest->parent;
        free(children);
        return true;
    }

    for (liste_noeud *child = children->succ; child != NULL; child = child->succ, children = children->succ)
    {
        if ((strcmp(child->no->nom, nrst_src->name)) == 0)
        {
            noeud *to_move = child->no;

            if (is_file_a_parent(current, to_move))
            {
                exit_system("mv: cannot move a parent folder. exit program.\n", 1);
            }

            children->succ = child->succ;
            if (is_name_valid(nrst_dest->name, "mv", output, verbose))
            {
                strncpy(to_move->nom, nrst_dest->name, strlen(nrst_dest->name) + 1);
            }
            add_child(nrst_dest->parent, to_move, output, verbose);
            to_move->pere = nrst_dest->parent;
            free(child);
            return true;
        }
    }
    return false;
}

bool is_file_a_parent(noeud *current, noeud *node_to_mv)
{
    if (node_to_mv == current->racine)
    {
        return true;
    }

    for (; current != current->racine; current = current->pere)
    {
        if (current == node_to_mv)
        {
            return true;
        }
    }

    return false;
}