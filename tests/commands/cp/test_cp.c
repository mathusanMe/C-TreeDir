#include "test_cp.h"

bool test_cp_file()
{
    noeud *root = get_test_tree_dir();
    cp(root, "Td/td1", "Td/td1copy");
    nearest *nrst = get_nearest(root, "Td/td1");
    liste_noeud *td1 = nrst->parent->fils;
    bool is_valid = is_equal(td1->no, td1->succ->succ->no, true);
    free(nrst);
    display_test(is_valid, "test_cp_file");
    return is_valid;
}

bool test_cp_folder()
{
    noeud *root = get_test_tree_dir();
    cp(root, "Td", "Tdcopy");
    bool is_valid = is_equal(root->fils->succ->no, root->fils->succ->succ->succ->no, true);
    display_test(is_valid, "test_cp_folder");
    return is_valid;
}

bool run_tests_cp()
{
    create_test_tree_dir();

    display_test(-1, "cp");
    bool result = test_cp_file();
    result &= test_cp_folder();

    free_test_tree_dir();

    return result;
}
