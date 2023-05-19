#ifndef PARSER_H
#define PARSER_H

#define MAX_LINE_LENGTH 1000
#define SEPARATORS " \n"

#define NB_LS_ARGUMENTS 1
#define NB_CD_ARGUMENTS 1
#define NB_PWD_ARGUMENTS 0
#define NB_MKDIR_ARGUMENTS 1
#define NB_RM_ARGUMENTS 1
#define NB_TOUCH_ARGUMENTS 1
#define NB_CP_ARGUMENTS 2
#define NB_MV_ARGUMENTS 2
#define NB_PRINT_ARGUMENTS 0

#define MAX_ARGUMENTS 2

#include "../utils/nodes.h"
#include "../main.h"
#include "../utils/string.h"
#include "../commands/ls/ls.h"
#include "../commands/cd/cd.h"
#include "../commands/pwd/pwd.h"
#include "../commands/mkdir/mkdir.h"
#include "../commands/touch/touch.h"
#include "../commands/print/print.h"

bool parse_file(char *file_path, FILE *output, bool verbose);
noeud *parse_line(noeud *current, char *line, FILE *output, bool verbose);
bool parse_arguments(char *strToken, char *command, size_t total_arguments, char **arguments, bool could_have_no_arguments, FILE *output, bool verbose);
void free_arguments(char **args, size_t size);

#endif