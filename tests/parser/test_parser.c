#include "test_parser.h"

bool test_inputs(char *path, size_t number_of_tests)
{
    for (size_t index = 1; index <= number_of_tests; ++index)
    {
        char *input_path = malloc((strlen(path) + 1) * sizeof(char));

        if (input_path == NULL)
        {
            printf("test_input%zu: failed to allocate memory.\n", index);
            return false;
        }

        test_an_input(input_path);
        free(input_path);
    }
}

bool test_an_input(char *input_path)
{
    bool is_valid = parse_file(input_path); // && compare_output(input_path, NULL);

    display_test(is_valid, input_path);

    return is_valid;
}

bool run_tests_parser()
{
    display_test(-1, "parser");

    bool result = test_inputs("", 0);
    return result;
}