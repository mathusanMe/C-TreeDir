#include "test_mv.h"

bool mv_test_file()
{
    noeud *root = get_test_tree_dir();

    bool is_valid = mv(root, "edt", "Cours");
    display_test(is_valid, "test_file");
    return is_valid;
}

bool mv_test_dir()
{
    noeud *root = get_test_tree_dir();

    bool is_valid = mv(root, "Td", "Cours");
    display_test(is_valid, "test_dir");
    return is_valid;
}

bool mv_test_file_into_newfile()
{
    noeud *root = get_test_tree_dir();

    bool is_valid = mv(root, "Cours/edt", "/EDT");
    display_test(is_valid, "test_file_into_newfile");
    return is_valid;
}

bool mv_test_dir_into_newdir()
{
    noeud *root = get_test_tree_dir();

    bool is_valid = mv(root, "Cours/Td", "/TDS");
    display_test(is_valid, "test_dir_into_newdir");
    return is_valid;
}

bool run_tests_mv()
{
    create_test_tree_dir();

    display_test(-1, "mv");
    bool result = mv_test_file();
    result &= mv_test_dir();
    result &= mv_test_file_into_newfile();
    result &= mv_test_dir_into_newdir();

    free_test_tree_dir();

    return result;
}