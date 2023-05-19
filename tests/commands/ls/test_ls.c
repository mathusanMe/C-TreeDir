#include "test_ls.h"

bool test_path_to_file(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    char *path = "Td/td1";
    bool is_valid = !ls(root, path, output, verbose);
    display_test(get_type_of_print(is_valid), "test_path_to_file", output);
    return is_valid;
}

bool test_path_to_empty_directory(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    char *path = "Cours/ProjetC/";
    bool is_valid = ls(root, path, output, verbose);
    display_test(get_type_of_print(is_valid), "test_path_to_empty_directory", output);
    return is_valid;
}

bool test_path_to_directory_with_files(FILE *output, bool verbose)
{
    noeud *root = get_test_tree_dir(output, verbose);
    char *path = "Td";
    bool is_valid = ls(root, path, output, verbose);
    display_test(get_type_of_print(is_valid), "test_path_to_directory_with_files", output);
    return is_valid;
}

bool run_test_ls(FILE *output, bool verbose)
{
    create_test_tree_dir(output, verbose);

    display_test(NAME, "ls", output);
    bool result = test_path_to_file(output, verbose);
    result &= test_path_to_empty_directory(output, verbose);
    result &= test_path_to_directory_with_files(output, verbose);

    free_test_tree_dir(output, verbose);

    return result;
}