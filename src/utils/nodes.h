#ifndef NODES_H
#define NODES_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node;
struct list_node;

struct node
{
    bool is_folder;
    char name[100];
    struct node *parent;
    struct node *root;
    struct list_node *children;
};

struct list_node
{
    struct node *no;
    struct list_node *succ;
};

typedef struct node node;
typedef struct list_node list_node;

node *create_node(char *name, bool is_folder, node *parent, node *root);
list_node *create_list_node(node *no, list_node *succ);
bool add_child(node *parent, node *child);
void free_node(node *node);
void free_node_list(list_node *list);

#endif