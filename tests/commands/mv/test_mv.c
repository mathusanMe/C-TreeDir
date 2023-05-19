#include "test_mv.h"

bool mv_test_file(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);

    bool is_valid = mv(root, "edt", "Cours", output, verbose);
    display_test(is_valid, "test_file", output);
    return is_valid;
}

bool mv_test_dir(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);

    bool is_valid = mv(root, "Td", "Cours", output, verbose);
    display_test(is_valid, "test_dir", output);
    return is_valid;
}

bool mv_test_file_into_newfile(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);

    bool is_valid = mv(root, "Cours/edt", "/EDT", output, verbose);
    display_test(is_valid, "test_file_into_newfile", output);
    return is_valid;
}

bool mv_test_dir_into_newdir(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);

    bool is_valid = mv(root, "Cours/Td", "/TDS", output, verbose);
    display_test(is_valid, "test_dir_into_newdir", output);
    return is_valid;
}

bool run_tests_mv(FILE *output, bool verbose)
{
    create_test_tree_dir(output, verbose);

    display_test(NAME, "mv", output);
    bool result = mv_test_file(output, verbose);
    result &= mv_test_dir(output, verbose);
    result &= mv_test_file_into_newfile(output, verbose);
    result &= mv_test_dir_into_newdir(output, verbose);

    free_test_tree_dir(output, verbose);

    return result;
}