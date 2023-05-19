#include "test_cp.h"

bool test_cp_file(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    cp(root, "Td/td1", "Td/td1copy", output, verbose);
    nearest *nrst = get_nearest(root, "Td/td1");
    liste_noeud *td1 = nrst->parent->fils;
    bool is_valid = is_equal(td1->no, td1->succ->succ->no, true);
    free(nrst);
    display_test(get_type_of_print(is_valid), "test_cp_file", output);
    return is_valid;
}

bool test_cp_folder(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    cp(root, "Td", "Tdcopy", output, verbose);
    bool is_valid = is_equal(root->fils->succ->no, root->fils->succ->succ->succ->no, true);
    display_test(get_type_of_print(is_valid), "test_cp_folder", output);
    return is_valid;
}

bool run_tests_cp(FILE *output, bool verbose)
{
    create_test_tree_dir(output, verbose);

    display_test(NAME, "cp", output);
    bool result = test_cp_file(output, verbose);
    result &= test_cp_folder(output, verbose);

    free_test_tree_dir(output, verbose);

    return result;
}
