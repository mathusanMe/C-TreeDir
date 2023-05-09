#ifndef PARSER_H
#define PARSER_H

#define MAX_LINE_LENGTH 1000
#define SEPARATORS " "

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void parse_file(char *file_path);
void parse_line(char *line);
void parse_command(char *command, char *args);

#endif