#ifndef DONNEES_H
#define DONNEES_H

#include "point.h"

typedef struct {
    Point *points;
    int n;
    int capacite;
    int dimension;
    int nb_classes;
} Donnees;

Donnees creer_donnees(void);
void liberer_donnees(Donnees *d);
int ajouter_point(Donnees *d, Point p);
int chargement_fichier(const char *nom_fichier, Donnees *d);
int sauvegarde_fichier(const char *nom_fichier, Donnees d);
void afficher_donnees(Donnees d);

#endif