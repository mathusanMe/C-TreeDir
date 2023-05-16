#include "main_test.h"

bool run_tests()
{
    system("chmod +x ./colors.sh");
    system("chmod +x ./lib_tests.sh");

    bool all_tests_passed = run_test_mkdir();
    all_tests_passed &= run_test_cd();
    all_tests_passed &= run_tests_touch();
    all_tests_passed &= run_test_ls();

    return all_tests_passed;
}