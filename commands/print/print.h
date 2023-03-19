#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/nodes.h"

void print_node(noeud *node);
void print_node_tab(noeud *node, char *pretab, char *tabulation);
char *handleFileDepth(liste_noeud *current, char *tabulation);
char *handleFilePosition(liste_noeud *current, char *tabulation);
char *handleFileTypePrinting(noeud *node);
char *addToString(char *string, char *toAdd);

#endif