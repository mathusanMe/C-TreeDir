#include "test_cd.h"

bool test_path_empty()
{
    node *root = malloc(sizeof(node));
    root->is_folder = true;
    root->children = NULL;
    root->parent = NULL;
    root->root = root;

    node *current = cd(root, "");

    bool is_valid = current == root;

    free_node(root);

    display_test(is_valid, "test_path_empty");

    return is_valid;
}

bool test_path_is_incorrect() {
    node *root = malloc(sizeof(node));
    if (root == NULL)
    {
        printf("test_path_is_incorrect: failed to allocate memory.\n");
        return false;
    }
    root->is_folder = true;
    root->children = NULL;
    root->parent = root;
    root->root = root;

    node *current = cd(root, "test");

    bool is_valid = current == NULL;

    free_node(root);
    
    display_test(is_valid, "test_path_is_incorrect");

    return is_valid;
}

bool test_path_contains_file() {
    node *root = malloc(sizeof(node));
    root->is_folder = true;
    root->children = NULL;
    root->parent = NULL;
    root->root = root;

    node *file = malloc(sizeof(node));
    file->is_folder = false;
    file->children = NULL;
    file->parent = root;
    file->root = root;
    strcpy(file->name, "test");

    root->children = malloc(sizeof(list_node));
    root->children->no = file;
    root->children->succ = NULL;

    node *current = cd(root, "test");

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