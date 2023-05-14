#include "test_mkdir.h"

bool test_name_empty()
{
    noeud *root = create_root();
    bool is_valid = mkdir(root, "") == false;
    free_node(root);
    display_test(is_valid, "test_name_empty");
    return is_valid;
}

bool test_name_contains_non_alnum_char()
{
    noeud *root = create_root();
    bool is_valid = mkdir(root, "test!") == false;
    free_node(root);
    display_test(is_valid, "test_name_contains_non_alnum_char");
    return is_valid;
}

bool test_name_too_long()
{
    char *name = malloc(sizeof(char) * 256);
    if (name == NULL)
    {
        printf("test_name_too_long: failed to allocate memory.\n");
        return false;
    }
    memset(name, 'a', 255);
    name[255] = '\0';
    noeud *root = create_root();
    bool is_valid = mkdir(root, name) == false;
    free(name);
    free_node(root);
    display_test(is_valid, "test_name_too_long");
    return is_valid;
}

bool test_name_already_exists()
{
    noeud *root = create_root();
    bool is_valid = mkdir(root, "test") && !mkdir(root, "test");
    free_node(root);
    display_test(is_valid, "test_name_already_exists");
    return is_valid;
}

bool run_test_mkdir()
{
    bool result = true;

    result &= test_name_empty();
    result &= test_name_contains_non_alnum_char();
    result &= test_name_too_long();
    result &= test_name_already_exists();
    return result;
}
