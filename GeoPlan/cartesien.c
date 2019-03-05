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
    double i;
    double j;
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
    that.i = -1 * this.b;
    that.j = this.a;
    *v = that;
}

void vecteurDroite(droite d, vecteur *v)
{
    vecteur this;
    this.i = -1 * d.b;
    this.j = d.a;
    *v = this;
}

void droite1ptVecteur(pt A, vecteur v, droite *d)
{
    droite this;
    this.a = v.j;
    this.b = -1 * v.i;
    this.c = (v.i * A.y) - (v.j * A.x);
    *d = this;
}

double normeVecteur(vecteur u)
{
    return (sqrt(pow(u.i, 2) + pow(u.j, 2)));
}

double produitScalaire(vecteur u, vecteur v, double *cosalpha)
{
    double produit = (u.i * v.i) + (u.j * v.j);
    double normu = normeVecteur(u);
    double normv = normeVecteur(v);
    if (normu != 0 && normv != 0)
    {
        *cosalpha = produit / (normu * normv);
    }
    return produit;
}