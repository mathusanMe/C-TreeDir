#include "main_test.h"

bool run_tests(FILE *output, bool verbose)
{
    bool all_tests_passed = run_test_ls(output, verbose);
    all_tests_passed &= run_tests_cd(output, verbose);
    all_tests_passed &= run_tests_pwd(output, verbose);
    all_tests_passed &= run_tests_mkdir(output, verbose);
    all_tests_passed &= run_tests_touch(output, verbose);
    all_tests_passed &= run_tests_print(output, verbose);
    all_tests_passed &= run_tests_rm(output, verbose);
    all_tests_passed &= run_tests_cp(output, verbose);
    all_tests_passed &= run_tests_mv(output, verbose);

    return all_tests_passed;
}