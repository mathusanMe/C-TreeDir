#include "cp.h"

void cp(noeud *current, char *src, char *dest, FILE *output, bool verbose)
{
    nearest *nrst_src = get_nearest(current, src);

    if (nrst_src == NULL)
    {
        printf("cp: %s: No such file or directory - src\n", src);
        exit(1);
    }

    nearest *nrst_dest = get_nearest(current, dest);

    if (nrst_dest == NULL)
    {
        printf("cp: %s: No such file or directory - dest\n", dest);
        exit(1);
    }

    if (nrst_src->parent == NULL)
    {
        printf("cp: %s: No such file or directory - src\n", src);
        exit(1);
    }

    if (nrst_dest->parent == NULL)
    {
        printf("cp: %s: No such file or directory - dest\n", dest);
        exit(1);
    }

    noeud *src_node = NULL;

    if (strcmp(nrst_src->parent->nom, nrst_src->name) == 0)
    {
        src_node = nrst_src->parent;
    }
    else
    {
        for (liste_noeud *tmp = nrst_src->parent->fils; tmp != NULL; tmp = tmp->succ)
        {
            if (strcmp(tmp->no->nom, nrst_src->name) == 0)
            {
                src_node = tmp->no;
                break;
            }
        }
    }

    if (src_node == NULL)
    {
        printf("cp: %s: No source node found\n", src);
        exit(1);
    }

    if (is_ancestor_to(src_node, nrst_dest->parent))
    {
        printf("cp: %s: can't copy a directory, or a file, into itself\n", src_node->nom);
        exit(1);
    }

    noeud *copy_src_node = deep_copy_node(src_node, output, verbose);

    if (copy_src_node == NULL)
    {
        printf("cp: %s: node can't be copied\n", src_node->nom);
        exit(1);
    }

    noeud *dest_node = nrst_dest->parent;

    if (strcmp(nrst_dest->parent->nom, nrst_dest->name) != 0)
    {
        strcpy(copy_src_node->nom, nrst_dest->name);
    }

    add_child(dest_node, copy_src_node, output, verbose);

    free(nrst_src);
    free(nrst_dest);
}

bool is_ancestor_to(noeud *nodeA, noeud *nodeB)
{
    if (nodeA == NULL || nodeB == NULL)
    {
        return false;
    }

    if (nodeB == nodeB->racine)
    {
        return false;
    }

    if (nodeA == nodeB)
    {
        return true;
    }

    return is_ancestor_to(nodeA, nodeB->pere);
}

noeud *deep_copy_node(noeud *node, FILE *output, bool verbose)
{
    if (node == NULL)
    {
        return NULL;
    }

    noeud *copy_node = malloc(sizeof(noeud));

    if (copy_node == NULL)
    {
        return NULL;
    }

    strcpy(copy_node->nom, node->nom);
    copy_node->fils = NULL;
    copy_node->est_dossier = node->est_dossier;
    copy_node->racine = node->racine;

    for (liste_noeud *tmp = node->fils; tmp != NULL; tmp = tmp->succ)
    {
        noeud *copy_child = deep_copy_node(tmp->no, output, verbose);

        if (copy_child == NULL)
        {
            return NULL;
        }

        add_child(copy_node, copy_child, output, verbose);
    }

    return copy_node;
}
