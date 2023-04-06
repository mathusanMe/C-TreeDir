#include "test.h"

int test_always_pass()
{
    return 1;
}

int test_always_fail()
{
    return 0;
}

int run_test_tests()
{
    int passed;
    int all_tests_passed = 1;

    display_test(-1, "test_tests");

    passed = test_always_pass();
    all_tests_passed *= passed;
    display_test(passed, "test_always_pass");

    // passed = test_always_fail();
    // all_tests_passed *= passed;
    // display_test(passed, "test_always_fail");

    return all_tests_passed ? EXIT_SUCCESS : EXIT_FAILURE;
}