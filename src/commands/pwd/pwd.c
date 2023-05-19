#include "pwd.h"

/**
 * Print the path of the working directory
 * Then print newline
 * @param node current node
 */
bool pwd(noeud *node)
{
    if (node == NULL)
    {
        if (VERBOSE)
        {
            printf("pwd: Current node is NULL\n");
        }
        return false;
    }

    bool is_valid = pwd_rec(node);
    puts("");

    return is_valid;
}

/**
 * By walking back through the entire file tree,
 * from the root node, print the file's name then it's child's one
 */
bool pwd_rec(noeud *node)
{
    if (node == NULL || node->pere == NULL)
    {
        return false;
    }

    // If current node is root
    if (node->racine == node)
    {
        printf("/");
        return true;
    }

    if (pwd_rec(node->pere))
    {
        printf("%s/", node->nom);
        return true;
    }
    return false;
}