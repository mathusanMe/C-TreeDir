#include "main_test.h"

bool run_tests()
{
    puts("\n\n /===== TESTS =====/ \n");

    system("chmod +x ./colors.sh");
    system("chmod +x ./lib_tests.sh");

    bool all_tests_passed = true;

    char *segmentation_fault = "ad";
    memmove(segmentation_fault, "ezrg", 3 * sizeof(char));

    return all_tests_passed;
}