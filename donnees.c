#include <stdio.h>
#include <stdlib.h>
#include "donnees.h"

Donnees creer_donnees(void) {
    Donnees d;
    d.points = NULL;
    d.n = 0;
    d.capacite = 0;
    d.dimension = 2;
    d.nb_classes = 2;
    return d;
}

void liberer_donnees(Donnees *d) {
    if (d == NULL) return;

    free(d->points);
    d->points = NULL;
    d->n = 0;
    d->capacite = 0;
}

int ajouter_point(Donnees *d, Point p) {
    Point *tmp;
    int nouvelle_capacite;

    if (d == NULL) return 0;

    if (d->n >= d->capacite) {
        nouvelle_capacite = (d->capacite == 0) ? 4 : d->capacite * 2;

        tmp = realloc(d->points, nouvelle_capacite * sizeof(Point));
        if (tmp == NULL) {
            return 0;
        }

        d->points = tmp;
        d->capacite = nouvelle_capacite;
    }

    d->points[d->n] = p;
    d->n++;

    return 1;
}

int chargement_fichier(const char *nom_fichier, Donnees *d) {
    FILE *f;
    int n, dim, classes;
    int i;
    Point p;

    if (nom_fichier == NULL || d == NULL) return 0;

    f = fopen(nom_fichier, "r");
    if (f == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir %s\n", nom_fichier);
        return 0;
    }

    if (fscanf(f, "%d %d %d", &n, &dim, &classes) != 3) {
        fprintf(stderr, "Erreur : format de la première ligne invalide\n");
        fclose(f);
        return 0;
    }

    if (n <= 0 || dim != 2 || classes <= 0) {
        fprintf(stderr, "Erreur : valeurs invalides dans le fichier\n");
        fclose(f);
        return 0;
    }

    *d = creer_donnees();
    d->dimension = dim;
    d->nb_classes = classes;

    for (i = 0; i < n; i++) {
        if (fscanf(f, "%d %lf %lf", &p.classe, &p.x, &p.y) != 3) {
            fprintf(stderr, "Erreur : point invalide ligne %d\n", i + 2);
            fclose(f);
            liberer_donnees(d);
            return 0;
        }

        if (p.classe < 1 || p.classe > classes || p.x < -1 || p.x > 1 || p.y < -1 || p.y > 1) {
            fprintf(stderr, "Erreur : valeurs incorrectes ligne %d\n", i + 2);
            fclose(f);
            liberer_donnees(d);
            return 0;
        }

        if (!ajouter_point(d, p)) {
            fprintf(stderr, "Erreur allocation mémoire\n");
            fclose(f);
            liberer_donnees(d);
            return 0;
        }
    }

    fclose(f);
    return 1;
}

int sauvegarde_fichier(const char *nom_fichier, Donnees d) {
    FILE *f;
    int i;

    if (nom_fichier == NULL) return 0;

    f = fopen(nom_fichier, "w");
    if (f == NULL) {
        fprintf(stderr, "Erreur : impossible de créer %s\n", nom_fichier);
        return 0;
    }

    fprintf(f, "%d %d %d\n", d.n, d.dimension, d.nb_classes);

    for (i = 0; i < d.n; i++) {
        fprintf(f, "%d %f %f\n",
                d.points[i].classe,
                d.points[i].x,
                d.points[i].y);
    }

    fclose(f);
    return 1;
}

void afficher_donnees(Donnees d) {
    int i;

    printf("Nombre de points : %d\n", d.n);
    printf("Dimension : %d\n", d.dimension);
    printf("Nombre de classes : %d\n", d.nb_classes);

    for (i = 0; i < d.n; i++) {
        afficher_point(d.points[i]);
    }
}