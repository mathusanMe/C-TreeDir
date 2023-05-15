#include "test_cd.h"

bool test_path_empty()
{
    noeud *root = get_test_tree_dir();
    noeud *current = cd(root, "");
    bool is_valid = current == root;
    display_test(is_valid, "test_path_empty");
    return is_valid;
}

bool test_path_is_incorrect()
{
    noeud *root = get_test_tree_dir();
    noeud *current = cd(root, "unknown/path/to/folder");
    bool is_valid = current == root;
    display_test(is_valid, "test_path_is_incorrect");
    return is_valid;
}

bool test_path_contains_file()
{
    noeud *root = get_test_tree_dir();
    noeud *current = cd(root, "Td/t1/");
    bool is_valid = current == root;
    display_test(is_valid, "test_path_contains_file");
    return is_valid;
}

bool test_valid_path()
{
    noeud *root = get_test_tree_dir();
    noeud *projetC = cd(root, "Cours/ProjetC");
    noeud *td = cd(root, "Td/");
    bool is_valid = projetC != NULL && td != NULL && (projetC == cd(td, "../Cours/./ProjetC"));
    display_test(is_valid, "test_valid_path");
    return is_valid;
}

bool run_test_cd()
{
    create_test_tree_dir();

    bool result = test_path_empty();
    result &= test_path_is_incorrect();
    result &= test_path_contains_file();
    result &= test_valid_path();

    free_test_tree_dir();

    return result;
}