#include "mkdir.h"

void mkdir(noeud *courant, char *name)
{

    if (is_empty(name))
    {
        printf("mkdir: le nom est vide.\n");
        return;
    }

    if (!is_alpnum(name))
    {
        printf("mkdir: le nom contient des caractères non alpha-numériques.\n");
        return;
    }

    if (!is_length_valid(name, 1, 99))
    {
        printf("mkdir: le nom est trop long.\n");
        return;
    }

    if (courant->est_dossier)
    {
        liste_noeud *fils = courant->fils;
        for (; fils != NULL; fils = fils->succ)
        {
            if (strcmp(fils->no->nom, name) == 0)
            {
                printf("mkdir: le dossier existe déjà.\n");
                return;
            }
        }
    }

    noeud *nouveau = malloc(sizeof(noeud));
    memcpy(nouveau->nom, name, strlen(name) + 1);
    nouveau->est_dossier = true;
    nouveau->pere = courant;
    nouveau->fils = NULL;
    nouveau->racine = courant->racine;
}