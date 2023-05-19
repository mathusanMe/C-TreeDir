#ifndef PWD_H
#define PWD_H

#include <stdio.h>
#include <stdbool.h>
#include "../../utils/output.h"
#include "../../utils/nodes.h"

bool pwd(noeud *node);
bool pwd_rec(noeud *node);

#endif