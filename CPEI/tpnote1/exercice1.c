#include <stdio.h>

int exercice1()
{
    printf("\n******* EXERCICE 1 *******\n\n");
    int n;
    printf("Entrez un entier superieur a 1 svp :");
    scanf("%d", &n);
    if (n < 2)
    {
        printf("ERREUR : le nombre n'est pas superieur a 1. FIN DU PROGRAMME\n");
        return -1;
    }
    // doit retourner 1 sur n est premier sinon 0
    // on va chercher entre 2 et (n-1) pour lever le caractere premier
    for (int i = 2; i <= (n - 1); i++)
    { // on part de 2 car tout les entiers sont divisibles par 1
        if ((n % i) == 0)
        {
            printf("%d est divisible par %d il n'est donc pas premier.\n", n, i);
            return 0;
        }
    }
    printf("%d est bien premier.\n", n);
    return 1;
}

int exercice2()
{
    printf("\n******* EXERCICE 2 *******\n\n");
    int input = 0, somme = 0;
    while (input >= 0)
    {
        printf("Entrez un entier svp : ");
        scanf("%d", &input);
        if (input < 0)
        {
            printf("La somme des nombres positifs entres est egale a : %d\n", somme);
            return somme;
        }
        else
        {
            somme = somme + input;
        }
    }
}

int exercice4()
{
    printf("\n******* EXERCICE 4 *******\n\n");
    int k = 0;
    printf("Entrez un entier >= 1 svp : ");
    scanf("%d", &k);
    if (k < 2)
    {
        printf("ERREUR : le nombre n'est pas superieur ou egal 1. FIN DU PROGRAMME\n");
        return -1;
    }
    // premiere ligne
    for (int i = 0; i < (k + 2); i++)
    {
        printf("#");
    }
    printf("\n");
    int ligne = 0;
    while (ligne < k) {
        printf("#");
        for (int debut = 1; debut < k - ligne; debut++) {
            printf(" ");
        }
        printf("/");
        for (int fin = k - ligne; fin < k; fin++) {
            printf(" ");
        }
        printf("#");
        printf("\n");
        ligne++;
    }



    // derniere ligne
    if (k != 1)
    {
        for (int i = 0; i < (k + 2); i++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main()
{
    printf("\nexercice1 = %d", exercice1());
    printf("\nexercice2 = %d", exercice2());
    exercice4();
    return 0;
}
