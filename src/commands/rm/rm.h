#ifndef RM_H
#define RM_H

#include "../../utils/nodes.h"
#include "../../utils/exit.h"
#include "../cd/cd.h"

bool rm(noeud *current, char *path, FILE *output, bool verbose);
bool remove_child(noeud *current, noeud *to_delete_parent, char *name, FILE *output, bool verbose);
bool is_nearest_dir_a_parent(noeud *current, noeud *node_to_rm_parent);

#endif