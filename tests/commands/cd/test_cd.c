#include "test_cd.h"

bool test_path_empty()
{
    noeud *root = create_root();
    noeud *current = cd(root, "");
    bool is_valid = current == root;
    free_node(root);
    display_test(is_valid, "test_path_empty");
    return is_valid;
}

bool test_path_is_incorrect()
{
    noeud *root = create_root();
    noeud *current = cd(root, "test");
    bool is_valid = current == NULL;
    free_node(root);
    display_test(is_valid, "test_path_is_incorrect");
    return is_valid;
}

bool test_path_contains_file()
{
    noeud *root = create_root();
    noeud *file = create_node("test", false, root, root);
    root->fils = create_list_node(file, NULL);
    noeud *current = cd(root, "test");
    bool is_valid = current == NULL;
    free_node(root);
    display_test(is_valid, "test_path_contains_file");
    return is_valid;
}

bool run_test_cd()
{
    bool result = test_path_empty();
    result &= test_path_is_incorrect();
    result &= test_path_contains_file();
    return result;
}