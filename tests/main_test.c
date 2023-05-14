#include "main_test.h"

bool run_tests()
{
    puts("\n\n /===== TESTS =====/ \n");

    system("chmod +x ./colors.sh");
    system("chmod +x ./lib_tests.sh");

    create_test_tree_dir();

    bool all_tests_passed = run_test_mkdir();
    all_tests_passed &= run_test_cd();
    all_tests_passed &= run_test_ls();

    free_test_tree_dir();

    return all_tests_passed;
}