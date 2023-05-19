#include "exit.h"

void exit_system(char *message, int code)
{
    printf("%s\n", message);
    exit(code);
}