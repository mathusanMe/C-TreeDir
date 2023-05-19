#ifndef CD_H
#define CD_H

#include <stdio.h>
#include <stdlib.h>
#include "../../main.h"
#include "../../utils/nodes.h"
#include "../../utils/string.h"

// cd() returns NULL if the path is invalid or is a file,
// else it returns the node from the path while changing the current node
noeud *cd(noeud *current, char *path);

#endif