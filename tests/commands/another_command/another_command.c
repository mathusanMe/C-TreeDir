#include "another_command.h"

bool this_is_a_command()
{
    display_test(true, "this_is_a_command");
    return true;
}

bool this_is_also_a_command()
{
    display_test(true, "this_is_also_a_command");
    return true;
}

bool run_another_command_tests()
{

    display_test(-1, "another_command_tests");

    bool all_tests_passed =
        this_is_a_command() &&
        this_is_also_a_command();

    return all_tests_passed;
}