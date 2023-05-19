#include "test_print.h"

bool test_print_test_tree(FILE *output)
{
    noeud *root_node = get_test_tree_dir(output);
    print(root_node, output);
    display_test(true, "print_test_tree", output);

    return true;
}

bool run_tests_print(FILE *output, bool verbose)
{
    create_test_tree_dir(output, verbose);

    display_test(NAME, "print", output);
    bool result = test_print_test_tree(output);

    free_test_tree_dir(output, verbose);

    return result;
}