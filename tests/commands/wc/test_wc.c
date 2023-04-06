#include "test_wc.h"

#define EMPTY_FILE "./tests/commands/wc/inputs/empty_file"
#define ONE_LINE_FILE "./tests/commands/wc/inputs/one_line_file"
#define MULTIPLE_LINES_FILE "./tests/commands/wc/inputs/multiple_lines_file"

int test_not_existing_file()
{
    // TODO : Print error in a log file
    return 1;
}

int test_empty_file()
{
    int output = wc(EMPTY_FILE);
    return output == 0 ? true : false;
}

int test_one_line_file()
{
    int output = wc(ONE_LINE_FILE);
    return output == 4 ? true : false;
}

int test_multiple_lines_file()
{
    int output = wc(MULTIPLE_LINES_FILE);
    return output == 19 ? true : false;
}

int run_wc_tests()
{
    int passed;
    int all_tests_passed = 1;

    display_test(-1, "test_wc");

    // passed = test_not_existing_file();
    // all_tests_passed *= passed;
    // display_test(passed, "test_not_existing_file");

    passed = test_empty_file();
    all_tests_passed *= passed;
    display_test(passed, "test_empty_file");

    passed = test_one_line_file();
    all_tests_passed *= passed;
    display_test(passed, "test_one_line_file");

    passed = test_multiple_lines_file();
    all_tests_passed *= passed;
    display_test(passed, "test_multiple_lines_file");

    return all_tests_passed ? EXIT_SUCCESS : EXIT_FAILURE;
}