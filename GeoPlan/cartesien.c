#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} pt;

typedef struct {
    double a;
    double b;
    double c;
} droite;

double distance(pt A, pt B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}
