#include "print.h"

#define TOP_FILE " ├─ "
#define MID_FILE " |  "
#define END_FILE " ⌎─ "
#define NO_SPACE "    "

void print_node(noeud *node)
{
    print_node_tab(node, "", "");
}

void print_node_tab(noeud *node, char *pretab, char *tabulation)
{
    printf("%s%s\n", pretab, handleFileTypePrinting(node));

    liste_noeud *current = node->fils;

    printf("%s\n", tabulation);
    while (current != NULL)
    {
        print_node_tab(current->no, handleFilePosition(current, tabulation), handleFileDepth(current, tabulation));
        current = current->succ;
    }
    printf("%s\n", tabulation);
}

char *handleFileDepth(liste_noeud *current, char *tabulation)
{
    char *interlude;
    if (current->succ == NULL)
    {
        interlude = NO_SPACE;
    }
    else
    {
        interlude = MID_FILE;
    }

    return addToString(tabulation, interlude);
}

char *handleFilePosition(liste_noeud *current, char *tabulation)
{

    char *interlude;
    if (current->succ == NULL)
    {
        interlude = END_FILE;
    }
    else
    {
        interlude = TOP_FILE;
    }

    return addToString(tabulation, interlude);
}

char *addToString(char *string, char *toAdd)
{
    char *newTab = malloc((strlen(string) + strlen(toAdd) + 1) * sizeof(char));
    memmove(newTab, string, strlen(string) * sizeof(char));
    memmove(newTab + strlen(string), toAdd, strlen(toAdd) * sizeof(char));
    newTab[strlen(string) + strlen(toAdd)] = '\0';

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