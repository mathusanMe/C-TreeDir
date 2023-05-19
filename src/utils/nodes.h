#ifndef NODES_H
#define NODES_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "string.h"

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

typedef struct nearest
{
    noeud *parent;
    char name[100];
} nearest;

extern noeud *test_tree_dir;

noeud *create_root(FILE *output, bool verbose);
noeud *create_node(char *name, bool is_folder, noeud *parent, noeud *root, FILE *output, bool verbose);
liste_noeud *create_list_node(noeud *no, liste_noeud *succ, FILE *output, bool verbose);
bool add_child(noeud *parent, noeud *child, FILE *output, bool verbose);
bool is_equal(noeud *nodeA, noeud *nodeB, bool initial_call);
void print_node(noeud *node);
void free_node(noeud *node);
void free_node_list(liste_noeud *list);

nearest *get_nearest(noeud *current, char *path);
bool is_nearest_null(nearest *nrst);

// Test tree dir
void create_test_tree_dir(FILE *output, bool verbose);
noeud *get_test_tree_dir();
void free_test_tree_dir();

#endif