#include "test_pwd.h"

bool test_current_node_is_null()
{
    noeud *root = NULL;

    bool is_valid = pwd(root) == false;

    display_test(is_valid, "test_current_node_is_null");
    return is_valid;
}

bool test_current_node_is_root()
{
    noeud *root = get_test_tree_dir();

    // TODO : check what's being print
    bool is_valid = pwd(root) == true;

    display_test(is_valid, "test_current_node_is_root");
    return is_valid;
}

bool test_current_node_is_correct()
{
    noeud *root = get_test_tree_dir();
    noeud *current_node = cd(root, "/Cours/ProjetC");

    if (current_node == NULL)
    {
        return false;
    }

    // TODO : check what's being print
    bool is_valid = pwd(current_node) == true;

    display_test(is_valid, "test_current_node_is_correct");
    return is_valid;
}

bool run_tests_pwd()
{
    create_test_tree_dir();

    display_test(-1, "pwd");
    bool result = test_current_node_is_null();
    result &= test_current_node_is_root();
    result &= test_current_node_is_correct();

    free_test_tree_dir();

    return result;
}