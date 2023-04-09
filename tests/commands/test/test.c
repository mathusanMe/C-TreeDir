#include "test.h"

bool test_always_pass()
{
    display_test(true, "test_always_pass");
    return true;
}

bool test_always_fail()
{
    display_test(false, "test_always_fail");
    return false;
}

bool run_test_tests()
{
    display_test(-1, "test_tests");

    int all_tests_passed =
        test_always_pass(); // && test_always_fail();

    return all_tests_passed;
}