#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} pt;

typedef struct
{
    double a;
    double b;
    double c;
} droite;

double distance(pt A, pt B)
{
    //Formule avec l'aide de la librairie math.h
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

void equationDroite(pt A, pt B, droite *d)
{
    droite this;
    this.a = A.y - B.y;                 //y1 - y2 = a;
    this.b = B.x - A.x;                 //x2 - x1 = b;
    this.c = B.y * A.x - A.y * B.x;     //y2 * x1 - y1 * x2 = c
    *d = this;
}
