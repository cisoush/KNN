#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double aleatoire_double(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int main(int argc, char *argv[]) {
    FILE *f;
    int n;
    int classes;
    int dimension;
    int i, j;
    int classe;
    double valeur;

    if (argc < 4 || argc > 5) {
        fprintf(stderr,
                "Usage : %s fichier n classes [dimension]\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    n = atoi(argv[2]);
    classes = atoi(argv[3]);

    if (argc == 5)
        dimension = atoi(argv[4]);
    else
        dimension = 2;

    if (n <= 0 || classes <= 0 || dimension <= 0) {
        fprintf(stderr, "Erreur : paramètres invalides\n");
        return EXIT_FAILURE;
    }

    f = fopen(argv[1], "w");
    if (f == NULL) {
        fprintf(stderr, "Erreur ouverture fichier\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    fprintf(f, "%d %d %d\n", n, dimension, classes);

    for (i = 0; i < n; i++) {

        classe = rand() % classes + 1;

        fprintf(f, "%d ", classe);

        for (j = 0; j < dimension; j++) {

            valeur = aleatoire_double(-1.0, 1.0);

            fprintf(f, "%f", valeur);

            if (j < dimension - 1)
                fprintf(f, " ");
        }

        fprintf(f, "\n");
    }

    fclose(f);

    printf("Fichier %s généré avec succès.\n", argv[1]);

    return EXIT_SUCCESS;
}