#include <stdio.h>
#include <cartesien.h>

int main()
{
    // Affiche la distance de deux points en utilisant la librairie maison
    pt A = {1, 0};
    pt B = {1, 4};
    printf("La distance est de %4.2f\n", distance(A, B));
    droite eqAB;
    equationDroite(A, B, &eqAB);
    printf("L'equation de la droite (AB): (%4.2f)X + (%4.2f)Y + (%4.2f) = 0\n", eqAB.a, eqAB.b, eqAB.c);
}