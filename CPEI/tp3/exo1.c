#include <stdio.h>

void milieu(float x1, float y1, float x2, float y2);
void droite(float x1, float y1, float x2, float y2);
void test(float x1, float y1, float x2, float y2, float x3, float y3);


int main()
{
    float xa, ya, xb, yb, xc, yc;
    printf("entrer les quatres coordonees : \n");
    scanf("%f %f %f %f", &xa, &ya, &xb, &yb);
    milieu(xa, ya, xb, yb);
    droite(xa, ya, xb, yb);
    printf("entrer 2 coordonnees supplementaires : \n");
    scanf("%f %f",&xc, &yc);
    test(xa, ya, xb, yb, xc, yc);
}

void milieu(float x1, float y1, float x2, float y2)
{
    float xm, ym;
    xm = (x1 + x2) / 2;
    ym = (y1 + y2) / 2;
    printf("les coordonnees du milieu sont : %f , %f \n", xm, ym);
}

void droite(float x1, float y1, float x2, float y2)
{
    float a,b,c;
    a = y1 - y2;
    b = x2 - x1;
    c = y2 * x1 - y1 * x2;
    printf("l'equation de la droite passant par ces points est : %f*x + (%f)*y + (%f) = 0\n",a,b,c);

}

void test(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float a,b,c,resultat;
    a = y1 - y2;
    b = x2 - x1;
    c = y2 * x1 - y1 * x2;
    resultat = a * x3 + b * y3 + c;
    if (resultat==0) {
        printf("les trois points sont alignes \n");
    }
    else {
        printf("les 3 points ne sont pas alignes \n");
    }
}