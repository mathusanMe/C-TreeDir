#include "print.h"

/**
 * Used to print the root node of the tree
 * @param node the root of the tree
 */
void print(noeud *node)
{
    print_node_tab(node, "", "");
}

/**
 * Used to print the entire tree and retain passed indentation
 * @param node the current node you are printing.
 * @param indent_for_file indentation you print before the name of the node (end with TOP_FILE OR END_FILE)
 * @param indent indentation of subdirectories
 */
void print_node_tab(noeud *node, char *indent_for_file, char *indent)
{
    char *fileName = handleFileTypePrinting(node);
    printf("%s%s\n", indent_for_file, fileName);
    free(fileName);

    liste_noeud *current = node->fils;

    while (current != NULL)
    {
        char *new_indent_for_file = handleFileIndentation(true, current, indent);
        char *new_indent = handleFileIndentation(false, current, indent);

        print_node_tab(current->no, new_indent_for_file, new_indent);
        current = current->succ;

        free(new_indent_for_file);
        free(new_indent);
    }
}

/**
 * Return the name of the node passed in arguments depending on whether it is a folder or not.
 * @example "[name]" if the node is a directory, "name" otherwise.
 */
char *handleFileTypePrinting(noeud *node)
{
    size_t fileNameSize = strlen(node->nom);
    char *fileName;

    if (!node->est_dossier)
    {
        fileName = malloc((fileNameSize + 1) * sizeof(char));
        memmove(fileName, node->nom, fileNameSize + 1);
    }
    else
    {
        fileName = malloc((fileNameSize + 3) * sizeof(char));
        memmove(fileName + 1, node->nom, fileNameSize);
        fileName[0] = '[';
        fileName[fileNameSize + 1] = ']';
        fileName[fileNameSize + 2] = '\0';
    }

    return fileName;
}

/**
 * Add to indentation a suffix depending whether or not
 * the current `liste_noeud` is the last or has successor.
 * The indentation returned is supposed to fit subdirectories of the printed node.
 * @param current the `liste_noeud` containing the node going to be printed
 * @param isIndentTheLast a boolean being true if the indent being added is
 *                        juxtaposed to file's name
 */
char *handleFileIndentation(bool isIndentTheLast, liste_noeud *current, char *indent)
{
    char *suffix;
    if (current->succ == NULL)
    {
        suffix = isIndentTheLast ? END_FILE : NO_SPACE;
    }
    else
    {
        suffix = isIndentTheLast ? TOP_FILE : MID_FILE;
    }

    return addToString(indent, suffix);
}

/**
 * Add `toAdd` at the end of `string`
 */
char *addToString(char *string, char *toAdd)
{
    size_t string_size = strlen(string);
    size_t toAdd_size = strlen(toAdd);

    char *newTab = malloc((string_size + toAdd_size + 1) * sizeof(char));

    memmove(newTab, string, string_size * sizeof(char));
    memmove(newTab + string_size, toAdd, toAdd_size * sizeof(char));

    newTab[string_size + toAdd_size] = '\0';

    return newTab;
}