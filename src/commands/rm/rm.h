#ifndef RM_H
#define RM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../utils/nodes.h"
#include "../cd/cd.h"

bool rm(noeud *current, char *path);
bool remove_child(noeud *current, noeud *to_delete_parent, char *name);
bool is_nearest_dir_a_parent(noeud *current, noeud *node_to_rm_parent);
void exit_system(char *message, int code);

#endif