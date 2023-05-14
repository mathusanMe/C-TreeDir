#include "nodes.h"

noeud *create_root()
{
    noeud *root = create_node("", true, NULL, NULL);
    if (root == NULL)
    {
        printf("create_root: failed to allocate memory.\n");
        return NULL;
    }
    root->pere = root;
    root->racine = root;
    return root;
}

noeud *create_node(char *name, bool is_folder, noeud *parent, noeud *root)
{
    noeud *new_node = malloc(sizeof(noeud));
    if (new_node == NULL)
    {
        printf("create_node: failed to allocate memory.\n");
        return NULL;
    }
    memcpy(new_node->nom, name, strlen(name) + 1);
    new_node->est_dossier = is_folder;
    new_node->pere = parent;
    new_node->racine = root;
    new_node->fils = NULL;
    return new_node;
}

liste_noeud *create_list_node(noeud *no, liste_noeud *succ)
{
    liste_noeud *new_list_node = malloc(sizeof(liste_noeud));
    if (new_list_node == NULL)
    {
        printf("create_list_node: failed to allocate memory.\n");
        return NULL;
    }
    new_list_node->no = no;
    new_list_node->succ = succ;
    return new_list_node;
}

bool add_child(noeud *parent, noeud *child)
{
    if (parent == NULL || child == NULL)
    {
        return false;
    }

    liste_noeud *children = parent->fils;
    if (children == NULL)
    {
        parent->fils = create_list_node(child, NULL);
        if (parent->fils == NULL)
        {
            return false;
        }
        return true;
    }

    for (; children != NULL; children = children->succ)
    {
        if (strcmp(children->no->nom, child->nom) == 0)
        {
            return false;
        }
    }

    liste_noeud *new_list_node = create_list_node(child, NULL);
    if (new_list_node == NULL)
    {
        return false;
    }

    children = parent->fils;
    for (; children->succ != NULL; children = children->succ)
        ;
    children->succ = new_list_node;
    return true;
}

void free_node(noeud *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->fils != NULL)
    {
        free_node_list(node->fils);
    }

    free(node);
}

void free_node_list(liste_noeud *list)
{
    if (list == NULL)
    {
        return;
    }

    if (list->succ != NULL)
    {
        free_node_list(list->succ);
    }

    free_node(list->no);
    free(list);
}