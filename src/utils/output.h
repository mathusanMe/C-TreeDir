#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern FILE *OUTPUT;
extern bool VERBOSE;

void set_output(FILE *output);
void close_output();
void set_verbose(bool verbose);

#endif