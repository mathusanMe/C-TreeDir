#include "test_mkdir.h"

bool mkdir_test_name_empty(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir();

    bool is_valid = mkdir(root, "", output, verbose) == false;
    display_test(get_type_of_print(is_valid), "test_name_empty", output);
    return is_valid;
}

bool mkdir_test_name_contains_non_alnum_char(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    bool is_valid = mkdir(root, "test!", output, verbose) == false;
    display_test(get_type_of_print(is_valid), "test_name_contains_non_alnum_char", output);
    return is_valid;
}

bool mkdir_test_name_too_long(FILE *output, bool verbose)
{
    char *name = malloc(sizeof(char) * 256);
    if (name == NULL)
    {
        fprintf(output, "test_name_too_long: failed to allocate memory.\n");
        return false;
    }
    memset(name, 'a', 255);
    name[255] = '\0';
    noeud *root = get_test_tree_dir(output, verbose);
    bool is_valid = mkdir(root, name, output, verbose) == false;
    free(name);
    display_test(get_type_of_print(is_valid), "test_name_too_long", output);
    return is_valid;
}

bool run_tests_mkdir(FILE *output, bool verbose)
{
    create_test_tree_dir(output, verbose);

    display_test(NAME, "mkdir", output);
    bool result = mkdir_test_name_empty(output, verbose);
    result &= mkdir_test_name_contains_non_alnum_char(output, verbose);
    result &= mkdir_test_name_too_long(output, verbose);

    free_test_tree_dir(output, verbose);

    return result;
}
