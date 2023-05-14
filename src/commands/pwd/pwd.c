#include "pwd.h"

/**
 * Print the path of the working directory
 * Then print newline
 * @param node current node
 */
void pwd(noeud *node)
{
    pwd_rec(node);
    puts("");
}

/**
 * By walking back through the entire file tree,
 * from the root node, print the file's name then it's child's one
 */
void pwd_rec(noeud *node)
{
    if (node == NULL)
    {
        return;
    }

    // If current node is root
    if (node->pere == node)
    {
        printf("/");
        return;
    }

    pwd_rec(node->pere);
    printf("%s/", node->nom);
}