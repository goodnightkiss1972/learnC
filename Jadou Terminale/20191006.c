#include <stdio.h>
#include <math.h>

int main()
{
    // tiré du premier contrôle de Jade, l'algorithme 2 est faux car n ne correspond pas à ce qui est calculé dans U
    // Algorithme 1
    int n = 0;
    double U = 500;
    while (U<=1190)
    {
        n = n + 1;
        U = -700*pow(0.75, n) + 1200;
        printf("J'en suis ici : n = %i et U = %lf\n", n, U);
    }
    printf("\nAlgorithme 1: Le rang n trouve est %i, U vaut alors %lf\n", n, U);

    // Algorithme 2
    n = 0;
    U = 500;
    while (U<=1190)
    {
        U = -700*pow(0.75, n) + 1200;
        n = n + 1;
        printf("J'en suis ici : n = %i et U = %lf\n", n, U);
    }
    printf("\nAlgorithme 2: Le rang n trouve est %i, U vaut alors %lf\n", n, U);
    return 0;
}
