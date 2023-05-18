#ifndef NODES_H
#define NODES_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct noeud;
struct liste_noeud;

struct noeud
{
    bool est_dossier;
    char nom[100];
    struct noeud *pere;
    struct noeud *racine;
    struct liste_noeud *fils;
};

struct liste_noeud
{
    struct noeud *no;
    struct liste_noeud *succ;
};

typedef struct noeud noeud;
typedef struct liste_noeud liste_noeud;

extern noeud *test_tree_dir;

typedef struct nearest
{
    noeud *parent;
    char *name;
} nearest;

noeud *create_root();
noeud *create_node(char *name, bool is_folder, noeud *parent, noeud *root);
liste_noeud *create_list_node(noeud *no, liste_noeud *succ);
bool add_child(noeud *parent, noeud *child);
void free_node(noeud *node);
void free_node_list(liste_noeud *list);

nearest *get_nearest(noeud *current, char *path);
bool is_nearest_null(nearest *nrst);

// Test tree dir
void create_test_tree_dir();
noeud *get_test_tree_dir();
void free_test_tree_dir();

#endif