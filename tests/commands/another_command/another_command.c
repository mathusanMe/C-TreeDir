#include "another_command.h"

int this_is_a_command()
{
    return 1;
}

int this_is_also_a_command()
{
    return 1;
}

int run_another_command_tests()
{
    int passed;
    int all_tests_passed = 1;

    display_test(-1, "another_command_tests");

    passed = this_is_a_command();
    all_tests_passed *= passed;
    display_test(passed, "this_is_a_command");

    passed = this_is_also_a_command();
    all_tests_passed *= passed;
    display_test(passed, "this_is_also_a_command");

    return all_tests_passed ? EXIT_SUCCESS : EXIT_FAILURE;
}