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
        printf("mkdir: %s is not a folder.\n", current->nom);
        return false;
    }

    liste_noeud *children = current->fils;

    if (children == NULL)
    {
        current->fils = malloc(sizeof(liste_noeud));
        if (current->fils == NULL)
        {
            printf("mkdir: failed to allocate memory.\n");
            return false;
        }
        current->fils->no = malloc(sizeof(noeud));
        if (current->fils->no == NULL)
        {
            printf("mkdir: failed to allocate memory.\n");
            return false;
        }
        memcpy(current->fils->no->nom, name, strlen(name) + 1);
        current->fils->no->est_dossier = true;
        current->fils->no->fils = NULL;
        current->fils->no->pere = current;
        current->fils->no->racine = current->racine;
        current->fils->succ = NULL;
        return true;
    }

    liste_noeud *last_child = NULL;

    for (; children != NULL; last_child = children, children = children->succ)
    {
        if (strcmp(children->no->nom, name) == 0)
        {
            printf("mkdir: the folder already exists.\n");
            return false;
        }
    }

    noeud *new_node = create_node(name, true, current, current->racine);
    if (new_node == NULL)
    {
        printf("mkdir: failed to create node.\n");
        return false;
    }

    if (last_child == NULL)
    {
        current->fils = create_list_node(new_node, NULL);
        if (current->fils == NULL)
        {
            printf("mkdir: failed to create list node.\n");
            free(new_node);
            return false;
        }
        return true;
    }

    last_child->succ = create_list_node(new_node, NULL);
    if (last_child->succ == NULL)
    {
        printf("mkdir: failed to create list node.\n");
        free(new_node);
        return false;
    }

    return true;
}

bool is_name_valid(char *name)
{
    if (name == NULL)
    {
        printf("mkdir: the name is null.\n");
        return false;
    }

    if (is_string_blank(name))
    {
        printf("mkdir: the name is blank.\n");
        return false;
    }

    if (!(is_string_alnum(name)))
    {
        printf("mkdir: the name is not alphanumeric.\n");
        return false;
    }

    if (!(is_length_valid(name, 1, 99)))
    {
        printf("mkdir: the name is longer than 99 characters.\n");
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