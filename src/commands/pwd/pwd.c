#include "pwd.h"

/**
 * Print the path of the working directory
 * Then print newline
 * @param node current node
 */
bool pwd(noeud *node, FILE *output, bool verbose)
{
    if (node == NULL)
    {
        if (verbose)
        {
            fprintf(output, "pwd: Current node is NULL\n");
        }
        return false;
    }

    bool is_valid = pwd_rec(node, output, verbose);
    puts("");

    return is_valid;
}

/**
 * By walking back through the entire file tree,
 * from the root node, print the file's name then it's child's one
 */
bool pwd_rec(noeud *node, FILE *output, bool verbose)
{
    if (node == NULL || node->pere == NULL)
    {
        return false;
    }

    // If current node is root
    if (node->racine == node)
    {
        fprintf(output, "/");
        return true;
    }

    if (pwd_rec(node->pere, output, verbose))
    {
        fprintf(output, "%s/", node->nom);
        return true;
    }
    return false;
}