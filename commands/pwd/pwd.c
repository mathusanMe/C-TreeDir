#include "pwd.h"

void pwd(noeud *node)
{
    pwd_rec(node);
    puts("");
}

void pwd_rec(noeud *node)
{
    if (node->pere == node)
    {
        printf("/");
        return;
    }

    pwd_rec(node->pere);
    printf("%s/", node->nom);
}