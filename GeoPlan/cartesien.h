#ifndef __cartesien_h_
#define __cartesien_h_

typedef struct {
    double x;
    double y;
} pt;

typedef struct {
    double a;
    double b;
    double c;
} droite;

typedef struct
{
    double i;
    double j;
} vecteur;

double distance2pt(pt A, pt B);

void droite2pt(pt A, pt B, droite *d, vecteur *v);

void vecteurDroite(droite d, vecteur *v);

void droite1ptVecteur(pt A, vecteur v, droite *d);

double normeVecteur(vecteur u);

double produitScalaire(vecteur u, vecteur v, double *cosalpha);

#endif //__cartesien_h_
