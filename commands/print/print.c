#include "print.h"

void print_node(noeud *node)
{
    print_node_tab(node, 0);
}

void print_node_tab(noeud *node, size_t tab)
{
    printf("%s%s\n", " ", handleFileTypePrinting(node));

    // TO DO : Call again function for all sub-directories and files and add 2 spaces in tabulation
    liste_noeud *current = node->fils;

    while (current != NULL)
    {
        print_node_tab(current->no, tab + 3);
        current = current->succ;
    }
}

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