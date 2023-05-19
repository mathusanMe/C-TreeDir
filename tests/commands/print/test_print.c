#include "test_print.h"

bool test_print_test_tree()
{
    noeud *root_node = get_test_tree_dir();
    print_node(root_node);
    display_test(true, "print_test_tree");

    return true;
}

bool run_tests_print()
{
    create_test_tree_dir();

    display_test(-1, "print");
    bool result = test_print_test_tree();

    free_test_tree_dir();

    return result;
}