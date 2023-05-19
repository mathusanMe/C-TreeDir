#include "nodes.h"

noeud *test_tree_dir = NULL;

bool is_equal(noeud *nodeA, noeud *nodeB, bool initial_call)
{
    if (nodeA == NULL || nodeB == NULL)
    {
        return false;
    }

    if (!initial_call && strcmp(nodeA->nom, nodeB->nom) != 0)
    {
        return false;
    }

    if (nodeA->racine != nodeB->racine)
    {
        return false;
    }

    if (nodeA->est_dossier != nodeB->est_dossier)
    {
        return false;
    }

    if (nodeA->fils == NULL || nodeB->fils == NULL)
    {
        return nodeA->fils == NULL && nodeB->fils == NULL;
    }

    for (liste_noeud *tmpA = nodeA->fils, *tmpB = nodeB->fils; tmpA != NULL && tmpB != NULL; tmpA = tmpA->succ, tmpB = tmpB->succ)
    {
        if (!is_equal(tmpA->no, tmpB->no, false))
        {
            return false;
        }
    }

    return true;
}

noeud *create_root()
{
    noeud *root = create_node("", true, NULL, NULL);
    if (root == NULL)
    {
        printf("create_root: failed to allocate memory.\n");
        return NULL;
    }
    root->pere = root;
    root->racine = root;
    return root;
}

noeud *create_node(char *name, bool is_folder, noeud *parent, noeud *root)
{
    noeud *new_node = malloc(sizeof(noeud));
    if (new_node == NULL)
    {
        printf("create_node: failed to allocate memory.\n");
        return NULL;
    }
    strncpy(new_node->nom, name, strlen(name) + 1);
    new_node->est_dossier = is_folder;
    new_node->pere = parent;
    new_node->racine = root;
    new_node->fils = NULL;
    return new_node;
}

liste_noeud *create_list_node(noeud *no, liste_noeud *succ)
{
    liste_noeud *new_list_node = malloc(sizeof(liste_noeud));
    if (new_list_node == NULL)
    {
        printf("create_list_node: failed to allocate memory.\n");
        return NULL;
    }
    new_list_node->no = no;
    new_list_node->succ = succ;
    return new_list_node;
}

bool add_child(noeud *parent, noeud *child)
{
    if (parent == NULL || child == NULL)
    {
        return false;
    }

    child->pere = parent;

    liste_noeud *children = parent->fils;
    if (children == NULL)
    {
        parent->fils = create_list_node(child, NULL);
        if (parent->fils == NULL)
        {
            return false;
        }
        return true;
    }

    liste_noeud *last_child = NULL;
    for (; children != NULL; last_child = children, children = children->succ)
    {
        if (strcmp(children->no->nom, child->nom) == 0)
        {
            return false;
        }
    }

    liste_noeud *new_list_node = create_list_node(child, NULL);
    if (new_list_node == NULL)
    {
        return false;
    }

    if (last_child != NULL)
    {
        last_child->succ = new_list_node;
    }

    return true;
}

void print_node(noeud *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("[%c][%s]\n", node->est_dossier ? 'D' : 'F', node->nom);
}

void free_node(noeud *node)
{
    if (node == NULL)
    {
        return;
    }

    free_node_list(node->fils);

    free(node);
}

void free_node_list(liste_noeud *list)
{
    if (list == NULL)
    {
        return;
    }

    free_node_list(list->succ);

    free_node(list->no);
    free(list);
}

nearest *get_nearest(noeud *current, char *path)
{
    if (current == NULL || path == NULL)
    {
        printf("get_nearest: current or path is NULL.\n");
        return NULL;
    }

    char *modifiable_path = strdup(path);

    if (modifiable_path == NULL)
    {
        printf("get_nearest: modifiable_path is NULL.\n");
        return NULL;
    }

    nearest *nrst = malloc(sizeof(nearest));
    if (nrst == NULL)
    {
        printf("get_nearest: nrst is NULL.\n");
        return NULL;
    }

    if (modifiable_path[0] == '\0')
    {
        nrst->parent = current->pere;
        strncpy(nrst->name, current->nom, strlen(current->nom) + 1);
        free(modifiable_path);
        return nrst;
    }

    if (modifiable_path[0] == '/')
    {
        nearest *nrst_rec = get_nearest(current->racine, modifiable_path + 1);
        free(modifiable_path);
        free(nrst);
        return nrst_rec;
    }

    noeud *tmp = current;

    for (char *next_token = strtok(modifiable_path, "/"); next_token != NULL; next_token = strtok(NULL, "/"))
    {
        if (strcmp(next_token, ".") == 0)
        {
            continue;
        }

        if (strcmp(next_token, "..") == 0)
        {
            if (tmp->pere == NULL)
            {
                free(modifiable_path);
                free(nrst);
                return NULL;
            }
            tmp = tmp->pere;
            continue;
        }

        liste_noeud *children = tmp->fils;

        if (children == NULL)
        {
            if (tmp->est_dossier)
            {
                if (next_token == NULL)
                {
                    nrst->parent = tmp->pere;
                    strncpy(nrst->name, tmp->nom, strlen(tmp->nom) + 1);
                    free(modifiable_path);
                    return nrst;
                }
            }
            else
            {
                if (next_token == NULL)
                {
                    nrst->parent = tmp->pere;
                    strncpy(nrst->name, tmp->nom, strlen(tmp->nom) + 1);
                    free(modifiable_path);
                    return nrst;
                }
                else
                {
                    free(modifiable_path);
                    free(nrst);
                    return NULL;
                }
            }
        }

        bool found = false;

        for (liste_noeud *current_child = children; current_child != NULL; current_child = current_child->succ)
        {
            if (strcmp(current_child->no->nom, next_token) == 0)
            {
                if (!current_child->no->est_dossier)
                {
                    if (strtok(NULL, "/") != NULL)
                    {
                        free(modifiable_path);
                        free(nrst);
                        return NULL;
                    }
                    nrst->parent = tmp;
                    strncpy(nrst->name, current_child->no->nom, strlen(current_child->no->nom) + 1);
                    free(modifiable_path);
                    return nrst;
                }
                tmp = current_child->no;
                found = true;
                break;
            }
        }

        if (!found)
        {
            if (strtok(NULL, "/") == NULL)
            {
                nrst->parent = tmp;
                strncpy(nrst->name, next_token, strlen(next_token) + 1);
                free(modifiable_path);
            }
            return nrst;
        }
    }
    nrst->parent = tmp->pere;
    strncpy(nrst->name, tmp->nom, strlen(tmp->nom) + 1);
    free(modifiable_path);
    return nrst;
}

bool is_nearest_null(nearest *nrst)
{
    return nrst != NULL && (nrst->parent == NULL || nrst->name == NULL);
}

noeud *get_test_tree_dir()
{
    return test_tree_dir;
}

void create_test_tree_dir()
{
    noeud *A1 = create_root();
    noeud *A2 = create_node("Cours", true, A1, A1);
    noeud *A3 = create_node("Td", true, A1, A1);
    noeud *A4 = create_node("edt", false, A1, A1);
    noeud *A5 = create_node("ProjetC", true, A2, A1);
    noeud *A6 = create_node("Anglais", true, A2, A1);
    noeud *A7 = create_node("td1", false, A3, A1);
    noeud *A8 = create_node("td2", false, A3, A1);

    add_child(A1, A2);
    add_child(A1, A3);
    add_child(A1, A4);
    add_child(A2, A5);
    add_child(A2, A6);
    add_child(A3, A7);
    add_child(A3, A8);

    test_tree_dir = A1;
}

void free_test_tree_dir()
{
    free_node(test_tree_dir);
}
