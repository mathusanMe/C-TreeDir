#include "test_wc.h"

#define EMPTY_FILE "./tests/commands/wc/inputs/empty_file"
#define ONE_LINE_FILE "./tests/commands/wc/inputs/one_line_file"
#define MULTIPLE_LINES_FILE "./tests/commands/wc/inputs/multiple_lines_file"

bool test_empty_file()
{
    int output = wc(EMPTY_FILE);
    bool condition_to_pass_test = (output == 0);

    display_test(condition_to_pass_test, "test_empty_file");
    return condition_to_pass_test;
}

bool test_one_line_file()
{
    int output = wc(ONE_LINE_FILE);
    bool condition_to_pass_test = (output == 4);

    display_test(condition_to_pass_test, "test_one_line_file");
    return condition_to_pass_test;
}

bool test_multiple_lines_file()
{
    int output = wc(MULTIPLE_LINES_FILE);
    bool condition_to_pass_test = (output == 19);

    display_test(condition_to_pass_test, "test_multiple_lines_file");
    return condition_to_pass_test;
}

bool run_wc_tests()
{
    display_test(-1, "test_wc");

    bool all_tests_passed =
        test_empty_file() &&
        test_one_line_file() &&
        test_multiple_lines_file();

    return all_tests_passed;
}