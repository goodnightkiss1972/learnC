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

typedef struct
{
    double u1;
    double u2;
} vecteur;

double distance2pt(pt A, pt B)
{
    //Formule avec l'aide de la librairie math.h
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

void droite2pt(pt A, pt B, droite *d, vecteur *v)
{
    droite this;
    this.a = A.y - B.y;                 //y1 - y2 = a;
    this.b = B.x - A.x;                 //x2 - x1 = b;
    this.c = B.y * A.x - A.y * B.x;     //y2 * x1 - y1 * x2 = c
    *d = this;

    vecteur that;
    that.u1 = -1 * this.b;
    that.u2 = this.a;
    *v = that;
}

void vecteurDroite(droite d, vecteur *v)
{
    vecteur this;
    this.u1 = -1 * d.b;
    this.u2 = d.a;
    *v = this;
}

void droite1ptVecteur(pt A, vecteur v, droite *d)
{
    droite this;
    this.a = v.u2;
    this.b = -1 * v.u1;
    this.c = (v.u1 * A.y) - (v.u2 * A.x);
    *d = this;
}