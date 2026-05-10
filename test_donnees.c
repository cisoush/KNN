#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

int main(int argc, char *argv[]) {
    Donnees d;

    if (argc != 2) {
        fprintf(stderr, "Usage : %s fichier\n", argv[0]);
        return EXIT_FAILURE;
    }

    d = creer_donnees();

    if (!chargement_fichier(argv[1], &d)) {
        return EXIT_FAILURE;
    }

    afficher_donnees(d);

    if (!sauvegarde_fichier("copie_donnees.txt", d)) {
        liberer_donnees(&d);
        return EXIT_FAILURE;
    }

    liberer_donnees(&d);

    return EXIT_SUCCESS;
}