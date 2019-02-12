#include <stdio.h>

#define nbPoints (4)
void montrePoints(float tableau[4][2]);
float * equationDroite(float points[2][2]);

int main()
{
    //float points[4][2] = {{5,0},{0,5},{-5,0},{0,-5}};
    // or
    //float points[nbpoints][2];
    //points[0][0]=5;
    //points[0][1]=0;
    //etc.
    // or dynamic input
    float points[nbPoints][2]; //4 rows for 2 columns = (x,y) 4 times
    int k, j;
    float x, y;
    for (k = 0; k < nbPoints; k++)
    {
        printf("Entrez point %d (x puis espace et y) : ", k);
        scanf("%f %f", &x, &y);
        points[k][0] = x;
        points[k][1] = y;
        printf("\n");
    }
    montrePoints(points);

    float * equation12;
//    float points12[2][2]={{1,2},{3,4}};
    float points12[2][2]={{points[0][0],points[0][1]},{points[1][0],points[1][1]}};
    equation12 = equationDroite(points12);
    printf("Contenu de equation dans l'appelant : %f %f %f\n", equation12[0], equation12[1], equation12[2]);
}

void montrePoints(float tableau[nbPoints][2])
{
    int k, j;
    /* display array contents */
    for (k = 0; k < nbPoints; k++)
    {
        printf("%d:[ %f %f ]", k, tableau[k][0], tableau[k][1]);
        printf("\n");
    }
}

float * equationDroite(float points[2][2]){
    static float equation[3];
    equation[0] = points[0][1] - points[1][1]; //y1 - y2 = a
    equation[1] = points[1][0] - points[0][1]; //x2 - x1 = b
    equation[2] = points[1][1] * points[0][1] - points[0][1] * points[0][0]; //y2 * x1 - y1 * x2 = c
    printf("l'equation de la droite passant par ces points est : %f*x + (%f)*y + (%f) = 0\n",equation[0],equation[1],equation[2]);
    return (equation);
}