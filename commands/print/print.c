#include "print.h"

#define TOP_FILE " ├─ "
#define MID_FILE " |  "
#define END_FILE " ⌎─ "
#define NO_SPACE "    "

/**
 * Used to print the root node of the tree
 * @param node the root of the tree
 */
void print_node(noeud *node)
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
    printf("%s%s\n", indent_for_file, handleFileTypePrinting(node));

    liste_noeud *current = node->fils;

    while (current != NULL)
    {
        print_node_tab(current->no, handleFilePosition(current, indent), handleFileDepth(current, indent));
        current = current->succ;
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
 * Add to indent an suffix depending whether or not
 * the current `liste_noeud` is the last or has successor.
 * The indentation returned is supposed to fit the printed node.
 * @param current the `liste_noeud` containing the node going to be printed
 */
char *handleFilePosition(liste_noeud *current, char *indent)
{
    char *prefix;
    if (current->succ == NULL)
    {
        prefix = END_FILE;
    }
    else
    {
        prefix = TOP_FILE;
    }

    return addToString(indent, prefix);
}

/**
 * Add to indent an suffix depending whether or not
 * the current `liste_noeud` is the last or has successor.
 * The indentation returned is supposed to fit subdirectories of the printed node.
 * @param current the `liste_noeud` containing the node going to be printed
 */
char *handleFileDepth(liste_noeud *current, char *indent)
{
    char *prefix;
    if (current->succ == NULL)
    {
        prefix = NO_SPACE;
    }
    else
    {
        prefix = MID_FILE;
    }

    return addToString(indent, prefix);
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