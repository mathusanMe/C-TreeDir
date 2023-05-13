#include "nodes.h"

void free_node(node *node)
{
    if (node->children != NULL)
    {
        free_node_list(node->children);
    }

    free(node);
}

void free_node_list(list_node *list)
{
    list_node *current = list;
    list_node *next = current->succ;

    while (next != NULL)
    {
        free_node(current->no);
        free(current);
        current = next;
        next = current->succ;
    }

    free_node(current->no);
    free(current);
}