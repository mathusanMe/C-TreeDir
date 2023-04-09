#ifndef CD_H
#define CD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/nodes.h"

noeud *cd_relatif(noeud *courant, char* chem);
noeud *cd_absolue(char* chem);

#endif