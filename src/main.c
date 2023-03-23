#include <stdlib.h>
#include "utils/nodes.h"
#include "commands/print/print.h"

int main()
{
    noeud root_node = {true, "", NULL, NULL, NULL};
    print_node(&root_node);
    return EXIT_SUCCESS;
}