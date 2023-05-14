#include "mkdir.h"

bool is_name_valid(char *name);
bool is_length_valid(char *name, int min, int max);

bool mkdir(node *current, char *name)
{
    if (current == NULL)
    {
        return false;
    }

    if (!is_name_valid(name))
    {
        printf("mkdir: %s is not valid name.\n", name);
        return false;
    }

    if (!current->is_folder)
    {
        printf("mkdir: %s is not a folder.\n", current->name);
        return false;
    }

    list_node *children = current->children;

    if (children == NULL)
    {
        current->children = malloc(sizeof(list_node));
        if (current->children == NULL)
        {
            printf("mkdir: failed to allocate memory.\n");
            return false;
        }
        current->children->no = malloc(sizeof(node));
        if (current->children->no == NULL)
        {
            printf("mkdir: failed to allocate memory.\n");
            return false;
        }
        memcpy(current->children->no->name, name, strlen(name) + 1);
        current->children->no->is_folder = true;
        current->children->no->children = NULL;
        current->children->no->parent = current;
        current->children->no->root = current->root;
        current->children->succ = NULL;
        return true;
    }

    for (; children != NULL; children = children->succ)
    {
        if (strcmp(children->no->name, name) == 0)
        {
            printf("mkdir: the folder already exists.\n");
            return false;
        }
    }



    node *new_node = create_node(name, true, current, current->root);
    if (new_node == NULL)
    {
        printf("mkdir: failed to create node.\n");
        return false;
    }

    children->succ = create_list_node(new_node, NULL);
    if (children->succ == NULL)
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