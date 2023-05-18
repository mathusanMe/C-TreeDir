#ifndef RM_H
#define RM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/nodes.h"
#include "../cd/cd.h"

void rm(noeud *current, char *path);
void is_path_a_parent(noeud *node_to_rm);
void exit_system(char *message, int code);

#endif