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

bool test_valid_path() {
    noeud *root = create_root();

    noeud *l1n1 = create_node("l1n1", true, root, root);
    noeud *l1n2 = create_node("l1n2", true, root, root);
    noeud *l1n3 = create_node("l1n3", false, root, root);

    noeud *l2n1 = create_node("l2n1", true, l1n2, root);
    noeud *l2n2 = create_node("l2n2", false, l1n2, root);
    
    liste_noeud *children = create_list_node(l1n1, NULL);
    children = create_list_node(l1n2, children);
    children = create_list_node(l1n3, children);
    root->fils = children;

    liste_noeud *children2 = create_list_node(l2n1, NULL);
    children2 = create_list_node(l2n2, children2);
    l1n2->fils = children2;

    bool is_valid = cd(l1n1, "/../l1n2/./l2n1/") == l2n1;
    free_node(root);
    display_test(is_valid, "test_valid_path");
    return is_valid;
}

bool run_test_cd()
{
    bool result = test_path_empty();
    result &= test_path_is_incorrect();
    result &= test_path_contains_file();
    result &= test_valid_path();
    return result;
}