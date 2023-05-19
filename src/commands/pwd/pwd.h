#ifndef PWD_H
#define PWD_H

#include "../../utils/nodes.h"

bool pwd(noeud *node, FILE *output, bool verbose);
bool pwd_rec(noeud *node, FILE *output, bool verbose);

#endif