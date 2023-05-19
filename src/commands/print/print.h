#ifndef PRINT_H
#define PRINT_H

#define TOP_FILE " ├─ "
#define MID_FILE " │  "
#define END_FILE " └─ "
#define NO_SPACE "    "

#include "../../utils/nodes.h"

void print(noeud *node, FILE *output);
void print_node_tab(noeud *node, char *pretab, char *indent, FILE *output);
char *handleFileTypePrinting(noeud *node);
char *handleFileIndentation(bool isParentDirTheLast, liste_noeud *current, char *indent);
char *addToString(char *string, char *toAdd);

#endif