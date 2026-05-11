#ifndef INTERFACE_H
#define INTERFACE_H

#include "donnees.h"
#include "point.h"



#define LARGEUR_FENETRE 1200
#define HAUTEUR_FENETRE 700

#define LARGEUR_MENU 300
#define MENU_X 900

#define COULEUR_FOND MLV_COLOR_DARK_BLUE
#define COULEUR_ZONE MLV_COLOR_WHITE

#define COULEUR_MENU MLV_COLOR_BLUE

#define COULEUR_BOUTON MLV_COLOR_YELLOW
#define COULEUR_BORDURE MLV_COLOR_BLACK

#define COULEUR_TEXTE MLV_COLOR_BLACK

#define K_DEFAUT 3



typedef struct {
    int x;
    int y;
    int largeur;
    int hauteur;
    char texte[50];
} Bouton;

void initialiser_boutons(Bouton boutons[]);
void dessiner_interface(Bouton boutons[], int k, Donnees d);
void dessiner_zone_knn();
void dessiner_menu();
void dessiner_bouton(Bouton bouton);
void dessiner_bouton_k(Bouton bouton, int k);
int clic_dans_bouton(Bouton bouton, int x, int y);
int clic_dans_zone_knn(int x, int y);





int interface_lancer();

#endif
