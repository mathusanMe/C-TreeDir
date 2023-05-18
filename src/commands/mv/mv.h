#ifndef MV_H
#define MV_H

#include "../utils/nodes.h"

bool mv(noeud *current, char *src, char *dest);
bool move(noeud *current, nearest *src_nrst, nearest *dest_nrst);

#endif