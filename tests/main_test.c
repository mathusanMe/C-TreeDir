#include "main_test.h"

void run_tests()
{
    puts("\n\n /===== TESTS =====/ \n");

    int all_tests_passed = 0;

    system("chmod +x ./colors.sh");
    system("chmod +x ./lib_tests.sh");

    all_tests_passed += run_test_tests();
    all_tests_passed += run_another_command_tests();

    printf("\n%s\n", all_tests_passed == 0 ? "EXIT_SUCCESS" : "EXIT_FAILURE");
}