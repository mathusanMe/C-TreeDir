#include "test_cd.h"

bool test_path_is_empty(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    noeud *current = cd(root, "", output, verbose);
    bool is_valid = current == root;
    display_test(is_valid, "test_path_is_empty", output);
    return is_valid;
}

bool test_path_is_incorrect(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    noeud *current = cd(root, "unknown/path/to/folder", output, verbose);
    bool is_valid = current == NULL;
    display_test(is_valid, "test_path_is_incorrect", output);
    return is_valid;
}

bool test_path_contains_file(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    noeud *current = cd(root, "Td/t1/", output, verbose);
    bool is_valid = current == NULL;
    display_test(is_valid, "test_path_contains_file", output);
    return is_valid;
}

bool test_valid_path(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);

    noeud *projetC = cd(root, "Cours/ProjetC", output, verbose);
    if (projetC == NULL)
    {
        return false;
    }

    noeud *td = cd(root, "Td", output, verbose);
    if (td == NULL)
    {
        return false;
    }

    bool is_valid = projetC != NULL && td != NULL && (projetC == cd(td, "../Cours/./ProjetC", output, verbose));
    display_test(is_valid, "test_valid_path", output);
    return is_valid;
}

bool run_tests_cd(FILE *output, bool verbose)
{
    create_test_tree_dir(output, verbose);

    display_test(-1, "cd", output);
    bool result = test_path_is_empty(output, verbose);
    result &= test_path_is_incorrect(output, verbose);
    result &= test_path_contains_file(output, verbose);
    result &= test_valid_path(output, verbose);

    free_test_tree_dir(output, verbose);

    return result;
}