#include "cd.h"

noeud *cd(noeud *courant, char* chem) {
    
    // Si le chemin est vide, on retourne la racine
    if (chem[0] == '\0') {
        return courant->racine;
    }

    // Si le chemin est absolu, on démarre à la racine
    if (chem[0] == '/') {
        return cd(courant->racine, chem + 1);
    }

    // Si le chemin est relatif, on démarre à la position courante
    char *next = strtok(chem, '/');
    while (next != NULL) {
        // Si le token est ., on ne fait rien
        if (strcmp(next, ".") == 0) {
            next = strtok(NULL, '/');
            continue;
        }

        // Si le token est .., on remonte d'un niveau
        if (strcmp(next, "..") == 0) {    
            courant = courant->pere;
            next = strtok(NULL, '/');
            continue;
        }

        // Si le token est un nom de dossier, on descend d'un niveau
        if (courant->est_dossier) {
            liste_noeud *fils = courant->fils;
            while (fils != NULL) {
                if (strcmp(fils->no->nom, next) == 0) {
                    courant = fils->no;
                    break;
                }
                fils = fils->succ;
            }
            next = strtok(NULL, '/');
            continue;
        }

        // Si le token n'existe pas ou existe mais n'est pas un dossier, on retourne NULL
        // et affichage d'un message d'erreur
        printf("cd: %s: No such directory\n", next);
        return NULL;
    }

    return courant;
}