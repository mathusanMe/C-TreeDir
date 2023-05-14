#include "test_ls.h"

bool test_path_to_file() {
    noeud* root = get_test_tree_dir();
    char* path = "Td/td1";
    bool is_valid = !ls(root, path);
    display_test(is_valid, "test_path_to_file");
    return is_valid;
}

bool test_path_to_empty_directory() {
    noeud* root = get_test_tree_dir();
    char* path = "Cours/ProjetC/";
    bool is_valid = !ls(root, path);
    display_test(is_valid, "test_path_to_empty_directory");
    return is_valid;
}

bool test_path_to_directory_with_files() {
    noeud* root = get_test_tree_dir();
    char* path = "Td";
    bool is_valid = ls(root, path);
    display_test(is_valid, "test_path_to_directory_with_files");
    return is_valid;
}

bool run_test_ls() {
    bool is_valid = true;
    is_valid &= test_path_to_file();
    is_valid &= test_path_to_empty_directory();
    is_valid &= test_path_to_directory_with_files();
    return is_valid;
}