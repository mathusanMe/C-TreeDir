#include <stdlib.h>
#include "utils/nodes.h"
#include "commands/print/print.c"

int main()
{
    noeud root_node = {true, "root", NULL, NULL, NULL};
    print_node(root_node);
    return EXIT_SUCCESS;
}