#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "point.h"

void afficher_point(Point p) {
    printf("classe=%d x=%f y=%f\n", p.classe, p.x, p.y);
}

void dessiner_point(Point p) {

  int ecran_x;
  int ecran_y;

  ecran_x = 40 + (int)((p.x + 1.0) * 410);

  ecran_y = 40 + (int)((1.0 - p.y) * 310);

  if (p.classe == 1) {

    MLV_draw_filled_circle(
			   ecran_x,
			   ecran_y,
			   6,
			   MLV_COLOR_RED
			   );
  }

  else {

    MLV_draw_filled_circle(
			   ecran_x,
			   ecran_y,
			   6,
			   MLV_COLOR_BLUE
			   );
  }
}
