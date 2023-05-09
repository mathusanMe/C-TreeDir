#ifndef PARSER_H
#define PARSER_H

#define MAX_LINE_LENGTH 1000
#define SEPARATORS " "

#define NB_LS_ARGUMENTS 0
#define NB_CD_ARGUMENTS 1
#define NB_PWD_ARGUMENTS 0
#define NB_MKDIR_ARGUMENTS 1
#define NB_RM_ARGUMENTS 1
#define NB_TOUCH_ARGUMENTS 1
#define NB_CP_ARGUMENTS 2
#define NB_MV_ARGUMENTS 2
#define NB_PRINT_ARGUMENTS 0

#define MAX_ARGUMENTS 2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void parse_file(char *file_path);
void parse_line(char *line);
char** parse_arguments(char *command, int total_arguments);

#endif