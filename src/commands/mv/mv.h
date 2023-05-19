#ifndef MV_H
#define MV_H

#include "../../utils/nodes.h"
#include "../../utils/exit.h"

bool mv(noeud *current, char *src, char *dest, FILE *output, bool verbose);
void update_destination(nearest *nrst, char *name);
bool move(noeud *current, nearest *src_nrst, nearest *dest_nrst, FILE *output, bool verbose);
bool is_file_a_parent(noeud *current, noeud *node_to_mv);

#endif