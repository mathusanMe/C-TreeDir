#include "print.h"

#define MIDDLE_FILE "├─ "
#define END_FILE "`─ "

void print_node(noeud *node)
{
    print_node_tab(node, "");
}

void print_node_tab(noeud *node, char *tabulation)
{
    printf("%s%s\n", tabulation, handleFileTypePrinting(node));

    // TO DO : Call again function for all sub-directories and files and add 2 spaces in tabulation
    liste_noeud *current = node->fils;

    while (current != NULL)
    {
        print_node_tab(current->no, addTabulation(current, tabulation));
        current = current->succ;
    }
}

char *addTabulation(liste_noeud *current, char *tabulation)
{
    char *interlude;
    if (current->succ == NULL)
    {
        interlude = END_FILE;
    }
    else
    {
        interlude = MIDDLE_FILE;
    }

    char *newTab = malloc((strlen(tabulation) + strlen(interlude) + 1) * sizeof(char));
    memmove(newTab, tabulation, strlen(tabulation) * sizeof(char));
    memmove(newTab + strlen(tabulation), interlude, strlen(interlude) * sizeof(char));
    newTab[strlen(tabulation) + strlen(interlude)] = '\0';

    return newTab;
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