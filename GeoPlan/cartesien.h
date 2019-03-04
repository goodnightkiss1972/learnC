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

double distance(pt A, pt B);
void equationDroite(pt A, pt B, droite *d);

#endif //__cartesien_h_
