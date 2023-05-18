#include "test_rm.h"

bool rm_test_file()
{
    noeud *root = get_test_tree_dir();
    bool is_valid = rm(root, "edt") == true;
    display_test(is_valid, "rm_test_file");
    return is_valid;
}

bool rm_test_empty_dir()
{
    noeud *root = get_test_tree_dir();
    bool is_valid = rm(root, "Cours/ProjetC") == true;
    display_test(is_valid, "rm_test_empty_dir");
    return is_valid;
}

bool rm_test_not_empty_dir()
{
    noeud *root = get_test_tree_dir();
    bool is_valid = rm(root, "Cours") == true;
    display_test(is_valid, "rm_test_not_empty_dir");
    return is_valid;
}

bool run_tests_rm()
{
    create_test_tree_dir();

    display_test(-1, "rm");
    bool result = rm_test_file();
    result &= rm_test_empty_dir();
    result &= rm_test_not_empty_dir();

    free_test_tree_dir();

    return result;
}