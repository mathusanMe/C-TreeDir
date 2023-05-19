#ifndef MV_H
#define MV_H

#include <string.h>
#include "../../utils/nodes.h"
#include "../../utils/exit.h"

bool mv(noeud *current, char *src, char *dest);
void update_destination(nearest *nrst, char *name);
bool move(noeud *current, nearest *src_nrst, nearest *dest_nrst);
bool is_file_a_parent(noeud *current, noeud *node_to_mv);

#endif