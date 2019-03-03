#include <stdio.h>
#include <cartesien.h>

int main()
{
    // Affiche la distance de deux points en utilisant la librairie maison
    pt A = {1, 0};
    pt B = {1, 4};
    printf("La distance est de %4.2f\n", distance(A, B));
}