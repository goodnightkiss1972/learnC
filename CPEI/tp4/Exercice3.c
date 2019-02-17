#include <stdio.h>

int f(int nbImpair);
int f2(int nbImpair);

int main()
{
    int nbImpair = 0;
    printf("Entrez un nombre d'impairs a sommer svp :\n");
    scanf("%d", &nbImpair);
    printf("Technique 1: Somme des %d premiers impairs = %d\n", nbImpair, f(nbImpair));
    printf("Technique 2: Somme des %d premiers impairs = %d\n", nbImpair, f2(nbImpair));
    return 0;
}

int f(int nbImpair)
{
    int i = 0, depart = 1, resultat = 0;
    if (nbImpair < 1)
    {
        return 0;
    }
    for (i = 0; i < nbImpair; i++)
    {
        resultat = resultat + (depart + i * 2);
    }
    return resultat;
}

int f2(int nbImpair)
{
    if (nbImpair == 1)
    {
        return 1;
    }
    else
    {
        return (nbImpair + (nbImpair - 1) + f2(nbImpair - 1));
    }
}
