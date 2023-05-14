#include "ls.h"

bool ls(noeud* current, char* path) {
    noeud* node_from_path = cd(current, path); // cd() returns NULL if the path is invalid or is a file

    if (node_from_path == NULL) {
        printf("ls: cannot access '%s': No such directory\n", path);
        return false;
    }

    if (node_from_path->est_dossier && node_from_path->fils != NULL) {
        for (liste_noeud *liste = node_from_path->fils; liste != NULL; liste = liste->succ) {
            printf("%s\n", liste->no->nom);
        }
        return true;
    }
    return false;
}