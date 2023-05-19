#ifndef MKDIR_H
#define MKDIR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../utils/nodes.h"
#include "../../utils/string.h"

bool mkdir(noeud *current, char *name, FILE *output, bool verbose);

#endif