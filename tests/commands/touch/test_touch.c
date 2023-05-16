#include "test_touch.h"

bool touch_test_name_empty()
{
    noeud *root = get_test_tree_dir();

    bool is_valid = touch(root, "") == false;
    display_test(is_valid, "test_name_empty");
    return is_valid;
}

bool touch_test_name_contains_non_alnum_char()
{
    noeud *root = get_test_tree_dir();
    bool is_valid = touch(root, "test!") == false;
    display_test(is_valid, "test_name_contains_non_alnum_char");
    return is_valid;
}

bool touch_test_name_too_long()
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
    bool is_valid = touch(root, name) == false;
    free(name);
    display_test(is_valid, "test_name_too_long");
    return is_valid;
}

bool touch_test_name_already_exists()
{
    noeud *root = get_test_tree_dir();

    bool is_valid = touch(root, "test") && !touch(root, "test");
    display_test(is_valid, "test_name_already_exists");
    return is_valid;
}

bool run_tests_touch()
{
    create_test_tree_dir();

    display_test(-1, "touch");
    bool result = true;
    result &= touch_test_name_empty();
    result &= touch_test_name_contains_non_alnum_char();
    result &= touch_test_name_too_long();
    result &= touch_test_name_already_exists();

    free_test_tree_dir();

    return result;
}
