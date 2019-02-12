#include <stdio.h>

typedef enum
{
    FALSE,
    TRUE
} bool;

bool not(bool x)
{
    switch (x)
    {
    case FALSE:
        return TRUE;
    case TRUE:
        return FALSE;
    default:
        return x;
    }
}

bool estPair(int a);

int main()
{
    int listeNombres[5] = {1, 3, 2, 6, 7};
    int listePairs[5], listeImpairs[5], i, nbPair = 0, nbImpair = 0;
    for (i = 0; i < 5; i++)
    {
        if (estPair(listeNombres[i]) == TRUE)
        {
            listePairs[nbPair] = listeNombres[i];
            nbPair++;
        }
        else
        {
            listeImpairs[nbImpair] = listeNombres[i];
            nbImpair++;
        }
    }
    printf("pair = %d, impair = %d\n", nbPair, nbImpair);
    for (i = 0; i < 5; i++)
    {
        printf("Pair %d = %d\n", i, listePairs[i]);
    }
    for (i = 0; i < 5; i++)
    {
        printf("Impair %d = %d\n", i, listeImpairs[i]);
    }
}

bool estPair(int a)
{
    int reste;
    reste = a % 2;
    if (reste == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
