#include "mkdir.h"

bool is_name_valid(char *name);
bool is_length_valid(char *name, int min, int max);

bool mkdir(noeud *current, char *name)
{
    if (current == NULL)
    {
        return false;
    }

    if (!is_name_valid(name))
    {
        return false;
    }

    if (!current->est_dossier)
    {
        VERBOSE_PRINT ? printf("mkdir: %s is not a folder.\n", current->nom) : 0;
        return false;
    }

    liste_noeud *children = current->fils;

    if (children == NULL)
    {
        current->fils = malloc(sizeof(liste_noeud));
        if (current->fils == NULL)
        {
            VERBOSE_PRINT ? printf("mkdir: failed to allocate memory.\n") : 0;
            return false;
        }
        current->fils->no = create_node(name, true, current, current->racine);
        current->fils->succ = NULL;
        return true;
    }

    liste_noeud *last_child = NULL;

    for (; children != NULL; last_child = children, children = children->succ)
    {
        if (strcmp(children->no->nom, name) == 0)
        {
            VERBOSE_PRINT ? printf("mkdir: the folder already exists.\n") : 0;
            return false;
        }
    }

    noeud *new_node = create_node(name, true, current, current->racine);
    if (new_node == NULL)
    {
        VERBOSE_PRINT ? printf("mkdir: failed to create node.\n") : 0;
        return false;
    }

    if (last_child == NULL)
    {
        current->fils = create_list_node(new_node, NULL);
        if (current->fils == NULL)
        {
            VERBOSE_PRINT ? printf("mkdir: failed to create list node.\n") : 0;
            free(new_node);
            return false;
        }
        return true;
    }

    last_child->succ = create_list_node(new_node, NULL);
    if (last_child->succ == NULL)
    {
        VERBOSE_PRINT ? printf("mkdir: failed to create list node.\n") : 0;
        free(new_node);
        return false;
    }

    return true;
}

bool is_name_valid(char *name)
{
    if (name == NULL)
    {
        VERBOSE_PRINT ? printf("mkdir: the name is null.\n") : 0;
        return false;
    }

    if (is_string_blank(name))
    {
        VERBOSE_PRINT ? printf("mkdir: the name is blank.\n") : 0;
        return false;
    }

    if (!(is_string_alnum(name)))
    {
        VERBOSE_PRINT ? printf("mkdir: the name is not alphanumeric.\n") : 0;
        return false;
    }

    if (!(is_length_valid(name, 1, 99)))
    {
        VERBOSE_PRINT ? printf("mkdir: the name is longer than 99 characters.\n") : 0;
        return false;
    }

    return true;
}

bool is_length_valid(char *name, int min, int max)
{
    int length = strlen(name);

    if (length < min || length > max)
    {
        return false;
    }

    return true;
}