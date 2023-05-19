#ifndef CP_H
#define CP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../utils/nodes.h"
#include "../../utils/string.h"
#include "../cd/cd.h"

void cp(noeud *current, char *src, char *dest, FILE *output, bool verbose);
bool is_ancestor_to(noeud *nodeA, noeud *nodeB);
noeud *deep_copy_node(noeud *node, FILE *output, bool verbose);

#endif