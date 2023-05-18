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
        exit_system("rm: file does not exist. exit program.", 1);
    }

    noeud *first_child = children->no;
    if (strcmp(first_child->nom, src_nrst->name) == 0)
    {
        if (is_file_a_parent(current, first_child))
        {
            exit_system("rm: cannot delete a parent folder. exit program.\n", 1);
        }

        src_nrst->parent->fils = children->succ;
        // TODO : Move it
        return true;
    }
    return false;
}

void exit_system(char *message, int code)
{
    printf("%s\n", message);
    exit(code);
}