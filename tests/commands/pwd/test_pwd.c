#include "test_pwd.h"

bool test_current_node_is_null(FILE *output, bool verbose)
{
    noeud *root = NULL;

    bool is_valid = pwd(root, output, verbose) == false;

    display_test(get_type_of_print(is_valid), "test_current_node_is_null", output);
    return is_valid;
}

bool test_current_node_is_root(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);

    // TODO : check what's being print
    bool is_valid = pwd(root, output, verbose) == true;

    display_test(get_type_of_print(is_valid), "test_current_node_is_root", output);
    return is_valid;
}

bool run_tests_pwd(FILE *output, bool verbose)
{
    create_test_tree_dir(output, verbose);

    display_test(NAME, "pwd", output);
    bool result = test_current_node_is_null(output, verbose);
    result &= test_current_node_is_root(output, verbose);

    free_test_tree_dir(output, verbose);

    return result;
}