#include "test_mkdir.h"

bool mkdir_test_name_empty()
{
    noeud *root = get_test_tree_dir();

    bool is_valid = mkdir(root, "") == false;
    display_test(is_valid, "test_name_empty");
    return is_valid;
}

bool mkdir_test_name_contains_non_alnum_char()
{
    noeud *root = get_test_tree_dir();
    bool is_valid = mkdir(root, "test!") == false;
    display_test(is_valid, "test_name_contains_non_alnum_char");
    return is_valid;
}

bool mkdir_test_name_too_long()
{
    char *name = malloc(sizeof(char) * 256);
    if (name == NULL)
    {
        printf("test_name_too_long: failed to allocate memory.\n");
        return false;
    }
    memset(name, 'a', 255);
    name[255] = '\0';
    noeud *root = get_test_tree_dir();
    bool is_valid = mkdir(root, name) == false;
    free(name);
    display_test(is_valid, "test_name_too_long");
    return is_valid;
}

bool mkdir_test_name_already_exists()
{
    noeud *root = get_test_tree_dir();
    bool is_valid = mkdir(root, "test") && !mkdir(root, "test");
    display_test(is_valid, "test_name_already_exists");
    return is_valid;
}

bool run_test_mkdir()
{
    create_test_tree_dir();

    display_test(-1, "mkdir");
    bool result = mkdir_test_name_empty();
    result &= mkdir_test_name_contains_non_alnum_char();
    result &= mkdir_test_name_too_long();
    result &= mkdir_test_name_already_exists();

    free_test_tree_dir();

    return result;
}
