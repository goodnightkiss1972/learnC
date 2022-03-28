/* https://www.ltam.lu/Tutoriel-Ansi-C/prg-c98.htm */

#include <stdio.h>
#include "unbounded_int.h"

unbounded_int string2unbounded_int(const char *e)
{
    unbounded_int *unbi = malloc(sizeof(unbounded_int));

    /* il faudra gerer le cas de la chaine vide */

    printf("\n **** DETECTION [%s] **** \n", e);
    if (*e == '-')
    {
        printf("NEGATIF\n");
        unbi->signe = '-';
        e++;
    }
    else
    {
        printf("POSITIF\n");
        unbi->signe = '+';
    }

    int position_apres_signe = 0;
    while (*e != '\0')
    {
        /* si la chaine ne represente qu'un seul chiffre il faut l'inserer en DERNIER */
        if (*(e + 1) == '\0')
        {
            printf("DERNIER       %c\n", *e);
            e++;
            position_apres_signe++;
            continue;
        }
        else if (position_apres_signe == 0) {
            printf("PREMIER       %c\n", *e);
            e++;
            position_apres_signe++;
            continue;
        }
        if (position_apres_signe >= 1 && *(e + 1) != '\0')
        {
            printf("MILIEU        %c\n", *e);
            e++;
            position_apres_signe++;
            continue;
        }
    }

    /* affectation de la taille */
    unbi->len = position_apres_signe;

    return *unbi;
}
