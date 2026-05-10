#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct {
    int x;
    int y;
    int largeur;
    int hauteur;
    char texte[50];
} Bouton;

int interface_lancer(void);

#endif
