#include "nodes.h"

noeud *test_tree_dir = NULL;

noeud *create_root()
{
    noeud *root = create_node("", true, NULL, NULL);
    if (root == NULL)
    {
        if (VERBOSE)
        {
            printf("create_root: failed to allocate memory.\n");
        }
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
        if (VERBOSE)
        {
            printf("create_node: failed to allocate memory.\n");
        }
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
        if (VERBOSE)
        {
            printf("create_list_node: failed to allocate memory.\n");
        }
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

    liste_noeud *last_child = NULL;
    for (; children != NULL; last_child = children, children = children->succ)
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

    if (last_child != NULL)
    {
        last_child->succ = new_list_node;
    }
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

noeud *get_test_tree_dir()
{
    return test_tree_dir;
}

void create_test_tree_dir()
{
    noeud *A1 = create_root();
    noeud *A2 = create_node("Cours", true, A1, A1);
    noeud *A3 = create_node("Td", true, A1, A1);
    noeud *A4 = create_node("edt", false, A1, A1);
    noeud *A5 = create_node("ProjetC", true, A2, A1);
    noeud *A6 = create_node("Anglais", true, A2, A1);
    noeud *A7 = create_node("td1", false, A3, A1);
    noeud *A8 = create_node("td2", false, A3, A1);

    add_child(A1, A2);
    add_child(A1, A3);
    add_child(A1, A4);
    add_child(A2, A5);
    add_child(A2, A6);
    add_child(A3, A7);
    add_child(A3, A8);

    test_tree_dir = A1;
}

void free_test_tree_dir()
{
    free_node(test_tree_dir);
}
