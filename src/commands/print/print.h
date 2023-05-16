#ifndef PRINT_H
#define PRINT_H

#define TOP_FILE " ├─ "
#define MID_FILE " │  "
#define END_FILE " └─ "
#define NO_SPACE "    "

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../utils/nodes.h"

void print_node(noeud *node);
void print_node_tab(noeud *node, char *pretab, char *indent);
char *handleFileTypePrinting(noeud *node);
char *handleFilePosition(liste_noeud *current, char *indent);
char *handleFileIndentation(bool isParentDirTheLast, liste_noeud *current, char *indent);
char *handleFileDepth(liste_noeud *current, char *indent);
char *addToString(char *string, char *toAdd);

#endif