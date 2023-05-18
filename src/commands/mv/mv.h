#ifndef MV_H
#define MV_H

#include <string.h>
#include "../utils/nodes.h"

bool mv(noeud *current, char *src, char *dest);
void update_destination(nearest *nrst, char *name);
bool move(noeud *current, nearest *src_nrst, nearest *dest_nrst);

#endif