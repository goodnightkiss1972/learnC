#include <stdio.h>

int main()
{
    int borneInf = 1, borneSup = 101, reponse = 0;
    printf("Je vais deviner votre age...\n");
    while ((borneSup - borneInf) >= 1)
    {
        printf("Les bornes %d %d - ", borneInf, borneSup);
        printf("Est-ce vous etes plus age (1) ou plus jeune (-1) que %d ans ? ", (borneSup + borneInf) / 2);
        scanf("%d", &reponse);
        switch (reponse)
        {
        case 0:
            printf("Je suis tombe pile sur votre age %d ans.\n", (borneSup + borneInf) / 2);
            return 0;
        case 1:
            borneInf = ((borneSup + borneInf) / 2) + 1;
            break;
        case -1:
            borneSup = ((borneSup + borneInf) / 2) - 1;
            break;
        }
    }
    printf("Les bornes %d %d - ", borneInf, borneSup);
    printf("Facile vous avez %d ans.", borneSup);
    return 0;
}