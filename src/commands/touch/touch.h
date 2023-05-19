#ifndef TOUCH_H
#define TOUCH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../utils/nodes.h"
#include "../../utils/string.h"

bool touch(noeud *current, char *name, FILE *output, bool verbose);

#endif