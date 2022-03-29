/* https://www.ltam.lu/Tutoriel-Ansi-C/prg-c98.htm */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "unbounded_int.h"

unbounded_int string2unbounded_int(const char *e)
{
    unbounded_int *unbi = (unbounded_int*)malloc(sizeof(unbounded_int));

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
            *unbi = ajouter1chiffre(*e, unbi);
            //printf(" # suivant = %x # precedent = %x\n", encours->suivant, encours->precedent);
            e++;
            position_apres_signe++;
            continue;
        }
        else if (position_apres_signe == 0)
        {
            printf("PREMIER       %c\n", *e);
            *unbi = ajouter1chiffre(*e, unbi);
            //printf(" # suivant = %x # precedent = %x\n", encours->suivant, encours->precedent);
            e++;
            position_apres_signe++;
            continue;
        }
        if (position_apres_signe >= 1 && *(e + 1) != '\0')
        {
            printf("MILIEU        %c\n", *e);
            *unbi = ajouter1chiffre(*e, unbi);
            //printf(" # suivant = %x # precedent = %x\n", encours->suivant, encours->precedent);
            e++;
            position_apres_signe++;
            continue;
        }
    }

    /* affectation de la taille */
    unbi->len = position_apres_signe;

    return *unbi;
}

char *unbounded_int2string(const unbounded_int *unbi)
{
    if (unbi == NULL)
    {
        return NULL;
    }
    if (unbi->len == 0 || unbi->signe == '*')
    {
        return NULL;
    }

    printf("Affichage   ");
    if (unbi->signe == '-')
    {
        printf("%c", unbi->signe);
    }

    chiffre *encours = (chiffre*)malloc(sizeof(chiffre));
    encours = unbi->premier;

    for (size_t i = 1; i < unbi->len; i++)
    {
        printf("%c", encours->c);
        encours = encours->suivant;
    }
    printf("\n");
    return "ABC";
}

unbounded_int ajouter1chiffre(const char ch, unbounded_int *unbi)
{
    chiffre *nouveau = malloc(sizeof(chiffre));
    if isdigit (ch)
    {
        nouveau->c = ch;
    }
    else
    {
        /* il faut declarer unbi comme incorrect */
        unbi->signe = '*';
    }
    nouveau->c = ch;
    nouveau->suivant = NULL;
    if (unbi->dernier == NULL) {
        nouveau->precedent = NULL;
        unbi->premier = nouveau;
        unbi->dernier = nouveau;
    }
    else
    {
        unbi->dernier->suivant = nouveau;
        nouveau->precedent = unbi->dernier;
        unbi->dernier = nouveau;
    }

    return *unbi;
}
