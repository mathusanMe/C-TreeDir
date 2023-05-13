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
    if (list->succ != NULL)
    {
        free_node_list(list->succ);
    }

    free_node(list->no);
    free(list);
}