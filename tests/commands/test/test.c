#include "test.h"

int test_always_pass()
{
    system("./colors.sh cyan '    test_always_pass'");
    return 1;
}

int test_always_fail()
{
    system("./colors.sh red '    test_always_fail'");
    return 0;
}

int run_test_tests()
{
    int all_tests_passed = 1;

    system("chmod +x ./colors.sh");
    system("./colors.sh blue 'test_test'");

    all_tests_passed *= test_always_pass();
    // all_tests_passed *= test_always_fail();

    printf("%s\n", all_tests_passed ? "EXIT_SUCCESS" : "EXIT_FAILURE");
    return all_tests_passed ? EXIT_SUCCESS : EXIT_FAILURE;
}