#include <stdio.h>

#define taille (8)
void montreTableau(int tableau[taille]);

int main()
{

    int tableau[taille] = {3, 2, 4, -1, 6, 0, -5, 18};
    int permute = 0, i, temp, compteurBoucles = 0, permutations = 0;

    do
    {
        montreTableau(tableau);
        permute = 0;
        compteurBoucles++;
        for (i = 0; i < (taille - 1); i++)
        {
            if (tableau[i + 1] < tableau[i])
            {
                temp = tableau[i + 1];
                tableau[i + 1] = tableau[i];
                tableau[i] = temp;
                permutations++;
                permute = 1;
            }
        }
    } while (permute == 1);
    printf("FIN\n");
    montreTableau(tableau);
    printf("Nb Boucles : %d avec %d permutations.\n", compteurBoucles, permutations);
}

void montreTableau(int tableau[taille])
{
    int i;
    printf("[ ");
    for (i = 0; i < taille; i++)
    {
        printf("%d, ", tableau[i]);
    }
    printf(" ]\n");
}
