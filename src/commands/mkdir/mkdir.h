#ifndef MKDIR_H
#define MKDIR_H

#include <stdio.h>
#include <stdlib.h>
#include "../../utils/nodes.h"
#include "../../utils/string.h"

bool mkdir(noeud *current, char *name);
bool is_name_valid(char *name);
bool is_length_valid(char *name, int min, int max);

#endif