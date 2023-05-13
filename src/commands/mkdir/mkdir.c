#include "mkdir.h"

bool is_name_valid(char *name);
bool is_length_valid(char *name, int min, int max);

void mkdir(node *current, char *name)
{
    if (current == NULL)
    {
        return;
    }

    if (!(is_name_valid(name)))
    {
        printf("mkdir: %s is not valid name.\n", name);
        return;
    }

    if (!(current->is_folder))
    {
        printf("mkdir: %s is not a folder.\n", current->name);
        return;
    }

    list_node *children = current->children;

    for (; children != NULL && children->succ != NULL; children = children->succ)
    {
        if (strcmp(children->no->name, name) == 0)
        {
            printf("mkdir: the folder already exists.\n");
            return;
        }
    }

    node *new = malloc(sizeof(node));
    memcpy(new->name, name, strlen(name) + 1);
    new->is_folder = true;
    new->children = NULL;
    new->parent = current;
    new->root = current->root;
    children->succ = malloc(sizeof(list_node));
    children->succ->no = new;
}

bool is_name_valid(char *name)
{
    if (name == NULL)
    {
        printf("the name is null.\n");
        return false;
    }

    if (isblank(name))
    {
        printf("the name is blank.\n");
        return false;
    }

    if (!(isalnum(name)))
    {
        printf("the name is not alphanumeric.\n");
        return false;
    }

    if (!(is_length_valid(name, 1, 99)))
    {
        printf("the name is longer than 99 characters.\n");
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