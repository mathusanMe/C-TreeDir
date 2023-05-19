#include "mv.h"

bool mv(noeud *current, char *src, char *dest, FILE *output, bool verbose)
{
    nearest *src_nrst = get_nearest(current, src);
    nearest *dest_nrst = get_nearest(current, dest);

    if (src_nrst == NULL || dest_nrst == NULL)
    {
        exit_system("mv: cannot allocate memory.\n", 1);
    }

    if (is_nearest_null(src_nrst) || is_nearest_null(dest_nrst))
    {
        exit_system("mv: error while getting nearest dir. exit program.\n", 1);
    }

    update_destination(dest_nrst, src_nrst->name);

    bool moved = move(current, src_nrst, dest_nrst, output, verbose);
    free(src_nrst);
    free(dest_nrst);
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

bool move(noeud *current, nearest *src_nrst, nearest *dest_nrst, FILE *output, bool verbose)
{
    liste_noeud *children = src_nrst->parent->fils;

    if (children == NULL)
    {
        exit_system("mv: file does not exist. exit program.", 1);
    }

    noeud *first_child = children->no;
    if (strcmp(first_child->nom, src_nrst->name) == 0)
    {
        if (is_file_a_parent(current, first_child))
        {
            exit_system("mv: cannot delete a parent folder. exit program.\n", 1);
        }

        src_nrst->parent->fils = children->succ;
        if (is_name_valid(dest_nrst->name, "mv", output, verbose))
        {
            strncpy(first_child->nom, dest_nrst->name, strlen(dest_nrst->name) + 1);
        }
        add_child(dest_nrst->parent, first_child, output, verbose);
        first_child->pere = dest_nrst->parent;
        free(children);
        return true;
    }

    for (liste_noeud *child = children->succ; child != NULL; child = child->succ, children = children->succ)
    {
        if ((strcmp(child->no->nom, src_nrst->name)) == 0)
        {
            noeud *to_move = child->no;

            if (is_file_a_parent(current, to_move))
            {
                exit_system("mv: cannot move a parent folder. exit program.\n", 1);
            }

            children->succ = child->succ;
            if (is_name_valid(dest_nrst->name, "mv", output, verbose))
            {
                strncpy(to_move->nom, dest_nrst->name, strlen(dest_nrst->name) + 1);
            }
            add_child(dest_nrst->parent, to_move, output, verbose);
            to_move->pere = dest_nrst->parent;
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