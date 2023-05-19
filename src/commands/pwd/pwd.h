#ifndef PWD_H
#define PWD_H

#include <stdio.h>
#include <stdbool.h>
#include "../../utils/nodes.h"

bool pwd(noeud *node, FILE *output, bool verbose);
bool pwd_rec(noeud *node, FILE *output, bool verbose);

#endif