#include "test.h"

void test_always_pass()
{
    puts("/== ALWAYS PASS ==/");
    assert(true);
    puts("|== ----------- ==|");
}

void test_always_fail()
{
    puts("/== ALWAYS FAIL ==/");
    assert(false);
    puts("|== ----------- ==|");
}

void run_test_tests()
{
    test_always_pass();
    // test_always_fail();
}