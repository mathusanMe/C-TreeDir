#include "test_rm.h"

bool rm_test_file(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    bool is_valid = rm(root, "edt", output, verbose) == true;
    display_test(get_type_of_print(is_valid), "rm_test_file", output);
    return is_valid;
}

bool rm_test_empty_dir(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    bool is_valid = rm(root, "Cours/ProjetC", output, verbose) == true;
    display_test(get_type_of_print(is_valid), "rm_test_empty_dir", output);
    return is_valid;
}

bool rm_test_not_empty_dir(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    bool is_valid = rm(root, "Cours", output, verbose) == true;
    display_test(get_type_of_print(is_valid), "rm_test_not_empty_dir", output);
    return is_valid;
}

bool run_tests_rm(FILE *output, bool verbose)
{
    create_test_tree_dir(output, verbose);

    display_test(NAME, "rm", output);
    bool result = rm_test_file(output, verbose);
    result &= rm_test_empty_dir(output, verbose);
    result &= rm_test_not_empty_dir(output, verbose);

    free_test_tree_dir(output, verbose);

    return result;
}