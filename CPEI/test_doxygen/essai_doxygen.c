#include <stdio.h>

int affiche_tableau(int tableau[], int taille);

int main()
{
    int montableau[6] = {2, 3, 6, 12, 4, 7};
    affiche_tableau(montableau, 6);
}

int affiche_tableau(int tableau[], int taille)
{
    if (taille < 1)
    {
        printf("ERREUR: la taille du tableau doit etre superieure a 1.");
        return 0;
    }
    printf("[ ");
    for (int i = 0; i < taille; i++)
    {
        if (i == taille -1) {
            printf("%d ", tableau[i]);
        }
        else
        {
            printf("%d, ", tableau[i]);
        }
    }
    printf("]\n");
    return 1;
}