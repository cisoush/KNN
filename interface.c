#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>

#include "interface.h"

void initialiser_boutons(Bouton boutons[]) {

  boutons[0].largeur = 220;
  boutons[0].hauteur = 50;

  boutons[0].x = MENU_X + (LARGEUR_MENU - boutons[0].largeur) / 2;

  boutons[0].y = 100;

  strcpy(boutons[0].texte, "Mode");

  boutons[1].largeur = 220;
  boutons[1].hauteur = 80;

  boutons[1].x = MENU_X + (LARGEUR_MENU - boutons[1].largeur) / 2;

  boutons[1].y = 190;

  strcpy(boutons[1].texte,"Valeur K");

  boutons[2].largeur = 220;
  boutons[2].hauteur = 50;

  boutons[2].x = MENU_X + (LARGEUR_MENU - boutons[2].largeur) / 2;

  boutons[2].y = 330;

  strcpy(boutons[2].texte,"Charger");

  boutons[3].largeur = 220;
  boutons[3].hauteur = 50;

  boutons[3].x = MENU_X + (LARGEUR_MENU - boutons[3].largeur) / 2;

  boutons[3].y = 410;

  strcpy(boutons[3].texte,"Sauvegarder");

  boutons[4].largeur = 220;
  boutons[4].hauteur = 50;

  boutons[4].x = MENU_X + (LARGEUR_MENU - boutons[4].largeur) / 2;

  boutons[4].y = 560;

  strcpy(boutons[4].texte,"Quitter");
}

void dessiner_interface(Bouton boutons[], int k, Donnees d) {

  int i;

  MLV_clear_window(COULEUR_FOND);

  dessiner_zone_knn();

  dessiner_menu();

  for (i = 0; i < d.n; i++) {
    dessiner_point(d.points[i]);
  }

  for (i = 0; i < 5; i++) {

    if (i == 1) {
      dessiner_bouton_k(boutons[i], k);
    }

    else {
      dessiner_bouton(boutons[i]);
    }
  }
}

void dessiner_zone_knn(void) {

  MLV_draw_filled_rectangle(
			    40,
			    40,
			    820,
			    620,
			    COULEUR_ZONE
			    );

  MLV_draw_rectangle(
		     40,
		     40,
		     820,
		     620,
		     MLV_COLOR_DARK_BLUE
		     );
}

int clic_dans_zone_knn(int x,int y) {

  if (
      x >= 40
      &&
      x <= 860
      &&
      y >= 40
      &&
      y <= 660
      ) {
    return 1;
  }

  return 0;
}

void dessiner_menu(void) {

  int largeur_texte;
  int hauteur_texte;
  int x;

  MLV_draw_filled_rectangle(
			    MENU_X,
			    0,
			    LARGEUR_MENU,
			    HAUTEUR_FENETRE,
			    COULEUR_MENU
			    );

  MLV_get_size_of_text(
		       "MENU",
		       &largeur_texte,
		       &hauteur_texte
		       );

  x = MENU_X + (LARGEUR_MENU - largeur_texte) / 2;

  MLV_draw_text(
		x,
		25,
		"MENU",
		MLV_COLOR_WHITE
		);
}

void dessiner_bouton(Bouton bouton) {

  int largeur_texte;
  int hauteur_texte;

  int texte_x;
  int texte_y;

  MLV_draw_filled_rectangle(
			    bouton.x,
			    bouton.y,
			    bouton.largeur,
			    bouton.hauteur,
			    COULEUR_BOUTON
			    );

  MLV_draw_rectangle(
		     bouton.x,
		     bouton.y,
		     bouton.largeur,
		     bouton.hauteur,
		     COULEUR_BORDURE
		     );

  MLV_get_size_of_text(
		       bouton.texte,
		       &largeur_texte,
		       &hauteur_texte
		       );

  texte_x = bouton.x + (bouton.largeur - largeur_texte) / 2;
    
  texte_y = bouton.y + (bouton.hauteur - hauteur_texte) / 2;

  MLV_draw_text(
		texte_x,
		texte_y,
		bouton.texte,
		COULEUR_TEXTE
		);
}

void dessiner_bouton_k(Bouton bouton, int k) {

  char texte_k[20];
  int largeur_texte;
  int hauteur_texte;
  int texte_x;

  MLV_draw_filled_rectangle(
			    bouton.x,
			    bouton.y,
			    bouton.largeur,
			    bouton.hauteur,
			    COULEUR_BOUTON
			    );

  MLV_draw_rectangle(
		     bouton.x,
		     bouton.y,
		     bouton.largeur,
		     bouton.hauteur,
		     COULEUR_BORDURE
		     );

  MLV_get_size_of_text(
		       bouton.texte,
		       &largeur_texte,
		       &hauteur_texte
		       );

  texte_x = bouton.x + (bouton.largeur - largeur_texte) / 2;

  MLV_draw_text(texte_x, bouton.y + 10, bouton.texte, COULEUR_TEXTE);

  sprintf(texte_k,"%d", k);

  MLV_get_size_of_text(
		       texte_k,
		       &largeur_texte,
		       &hauteur_texte
		       );

  texte_x = bouton.x + (bouton.largeur - largeur_texte) / 2;

  MLV_draw_text(
		texte_x,
		bouton.y + 45,
		texte_k,
		COULEUR_TEXTE
		);
}

int clic_dans_bouton(Bouton bouton, int x, int y) {

  if (
      x >= bouton.x
      &&
      x <= bouton.x +
      bouton.largeur
      &&
      y >= bouton.y
      &&
      y <= bouton.y +
      bouton.hauteur
      ) {
    return 1;
  }

  return 0;
}


int interface_lancer() {

    int continuer;
    int souris_x;
    int souris_y;
    int k;
    int classe_actuelle; 

    MLV_Keyboard_button touche;

    Bouton boutons[5];

    Donnees d;

    continuer = 1;

    k = K_DEFAUT;
    classe_actuelle = 1;
    d = creer_donnees();

    initialiser_boutons(boutons);

    MLV_create_window(
		      "PROJET",
		      "KNN",
		      LARGEUR_FENETRE,
		      HAUTEUR_FENETRE
		      );

    while (continuer) {

      dessiner_interface(boutons, k, d);

      MLV_actualise_window();

      touche = MLV_KEYBOARD_NONE;

      MLV_wait_keyboard_or_mouse(
				 &touche,
				 NULL,
				 NULL,
				 &souris_x,
				 &souris_y
				 );

      if (clic_dans_zone_knn(souris_x,souris_y)) {

	Point p;

	p.x = ((double)(souris_x - 40) / 410.0) - 1.0;

	p.y = 1.0 - ((double)(souris_y - 40) / 310.0);

	p.classe = classe_actuelle;

	ajouter_point(&d, p);
      }

      if (touche == MLV_KEYBOARD_ESCAPE) {
	continuer = 0;
      }

      if (touche == MLV_KEYBOARD_UP) {
	k++;
      }

      if (touche == MLV_KEYBOARD_DOWN && k > 1) {
	k--;
      }

      if (touche == MLV_KEYBOARD_r) {

	classe_actuelle = 1;
      }

      if (touche == MLV_KEYBOARD_b) {

	classe_actuelle = 2;
      }

      if (
	  clic_dans_bouton(
			   boutons[4],
			   souris_x,
			   souris_y
			   )
	  ) {
	continuer = 0;
      }
    }

    MLV_free_window();

    return 1;
}

