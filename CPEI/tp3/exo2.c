#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);
int losange(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
double produit_scalaire(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);


double sqr(double a) {
    return a*a;
}

int main()
{
    double xa,ya,xb,yb,xc,yc,xd,yd;
    printf("entrer les quatres coordonees : \n");
    scanf("%lf %lf %lf %lf", &xa, &ya, &xb, &yb);
    distance(xa,ya,xb,yb);
    printf("entrer les huit coordonees : \n");
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd);
    losange(xa,ya,xb,yb,xc,yc,xd,yd);
}

double distance(double x1, double y1, double x2, double y2)
{
    double resultat;
    resultat = sqrt(sqr(y2 - y1) + sqr(x2 - x1));
    printf("la distance entre les 2 points est %lf \n",resultat);
}

double produit_scalaire(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{   
    double xv1,yv1,xv2,yv2,produit;
    xv1 = x2 - x4;
    yv1 = y2 - y4;
    xv2 = x1 - x3;
    yv2 = y1 - y3;
    produit = xv1 * xv2 + yv1 * yv2;
    return produit;  
}   

int losange(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{   
    double xm1,ym1,xm2,ym2,produit;
    int test;
    produit = produit_scalaire(x1,y1,x2,y2,x3,y3,x4,y4);
    xm1 = (x1 + x3) / 2;
    ym1 = (y1 + y3) / 2;
    xm2 = (x4 + x2) / 2;
    ym2 = (y4 + y2) / 2;
    if (produit == 0 && xm1==xm2 && ym1==ym2 ) {
        test = 1;
        printf("c'est un losange");
    }
    else {
        test = 0;
        printf("c'est pas un losange");
    }
    return test;
}

