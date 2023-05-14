#include "nodes.h"

node *create_root()
{
    node *root = create_node("", true, NULL, NULL);
    if (root == NULL)
    {
        printf("create_root: failed to allocate memory.\n");
        return NULL;
    }
    root->parent = root;
    root->root = root;

    return root;
}

node *create_node(char *name, bool is_folder, node *parent, node *root)
{
    node *new_node = malloc(sizeof(node));

    if (new_node == NULL)
    {
        printf("create_node: failed to allocate memory.\n");
        return NULL;
    }

    memcpy(new_node->name, name, strlen(name) + 1);
    new_node->is_folder = is_folder;
    new_node->parent = parent;
    new_node->root = root;
    new_node->children = NULL;

    return new_node;
}

list_node *create_list_node(node *no, list_node *succ)
{
    list_node *new_list_node = malloc(sizeof(list_node));

    if (new_list_node == NULL)
    {
        printf("create_list_node: failed to allocate memory.\n");
        return NULL;
    }

    new_list_node->no = no;
    new_list_node->succ = succ;

    return new_list_node;
}

bool add_child(node *parent, node *child)
{
    if (parent == NULL || child == NULL)
    {
        return false;
    }

    list_node *children = parent->children;

    if (children == NULL)
    {
        parent->children = create_list_node(child, NULL);
        if (parent->children == NULL)
        {
            return false;
        }
        return true;
    }

    for (; children != NULL; children = children->succ)
    {
        if (strcmp(children->no->name, child->name) == 0)
        {
            return false;
        }
    }

    list_node *new_list_node = create_list_node(child, NULL);
    if (new_list_node == NULL)
    {
        return false;
    }

    children = parent->children;
    for (; children->succ != NULL; children = children->succ)
        ;
    children->succ = new_list_node;

    return true;
}

void free_node(node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->children != NULL)
    {
        free_node_list(node->children);
    }

    free(node);
}

void free_node_list(list_node *list)
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