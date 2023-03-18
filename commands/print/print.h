#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/nodes.h"

void print_node(noeud *node);
void print_node_tab(noeud *node, size_t tab);
char *handleFileTypePrinting(noeud *node);

#endif