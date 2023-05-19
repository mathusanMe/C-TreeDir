#include "test_parser.h"

bool test_inputs(char *path, size_t number_of_tests, FILE *output, bool verbose)
{
    if (path == NULL)
    {
        return false;
    }

    bool is_valid = false;
    for (size_t index = 1; index <= number_of_tests; ++index)
    {
        char *input_path = malloc((strlen(path) + 1) * sizeof(char));

        if (input_path == NULL && verbose)
        {
            fprintf(output, "test_input%zu: failed to allocate memory.\n", index);
            return false;
        }

        is_valid &= test_an_input(input_path, output, verbose);
        free(input_path);
    }
    return is_valid;
}

bool test_an_input(char *input_path, FILE *output, bool verbose)
{
    bool is_valid = parse_file(input_path, output, verbose); // && compare_output(input_path, NULL);

    display_test(is_valid, input_path, output);

    return is_valid;
}

bool run_tests_parser(FILE *output, bool verbose)
{
    display_test(-1, "parser", output);

    // bool result = test_inputs("", 0, output, verbose);
    // return result;
    return true;
}