#ifndef POINT_H
#define POINT_H

typedef struct {
    double x;
    double y;
    int classe;
} Point;

void afficher_point(Point p);
void dessiner_point(Point p);

#endif
