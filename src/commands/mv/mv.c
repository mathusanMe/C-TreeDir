#include "mv.h"

bool mv(noeud *current, char *src, char *dest)
{
    nearest *src_nrst = get_nearest(current, src);
    nearest *dest_nrst = get_nearest(current, dest);

    if (is_nearest_null(src_nrst) || is_nearest_null(dest_nrst))
    {
        exit_system("mv: cannot allocate memory.\n", 1);
    }

    update_destination(dest_nrst, src_nrst->name);

    bool moved = move(current, src_nrst, dest_nrst);
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
                nrst->name = name;
            }
            return;
        }
    }
}

bool move(noeud *current, nearest *src_nrst, nearest *dest_nrst)
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
        if (dest_nrst->parent != first_child->racine)
        {
            strcpy(first_child->nom, dest_nrst->name);
        }
        add_child(dest_nrst->parent, first_child);
        first_child->pere = dest_nrst->parent;
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
            if (dest_nrst->parent != to_move->racine)
            {
                strcpy(to_move->nom, dest_nrst->name);
            }
            add_child(dest_nrst->parent, to_move);
            to_move->pere = dest_nrst->parent;
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

void exit_system(char *message, int code)
{
    printf("%s\n", message);
    exit(code);
}