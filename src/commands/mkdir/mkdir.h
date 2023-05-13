#ifndef MKDIR_H
#define MKDIR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../utils/nodes.h"

bool mkdir(node *current, char *name);
bool is_name_valid(char *name);
bool is_length_valid(char *name, int min, int max);

#endif