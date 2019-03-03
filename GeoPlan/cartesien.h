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

#endif //__cartesien_h_
