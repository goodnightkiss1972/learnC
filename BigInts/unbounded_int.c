/* https://www.ltam.lu/Tutoriel-Ansi-C/prg-c98.htm */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "unbounded_int.h"

#define DEBUGAGE false

unbounded_int string2unbounded_int(const char *e)
{
    unbounded_int *unbi = (unbounded_int *)malloc(sizeof(unbounded_int));

    /* il faudra gerer le cas de la chaine vide */

    if (DEBUGAGE)
        printf("**** string2unbounded_int [%s] **** ", e);
    if (*e == '-')
    {
        if (DEBUGAGE)
            printf("NEGATIF ");
        unbi->signe = '-';
        e++;
    }
    else
    {
        if (DEBUGAGE)
            printf("POSITIF ");
        unbi->signe = '+';
    }

    while (*e != '\0')
    {
        /* si la chaine ne represente qu'un seul chiffre il faut l'inserer en DERNIER */
        *unbi = ajouter_1chiffre_a_la_fin(*e, unbi);
        e++;
    }

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

    char *s = malloc((unbi->len + 1) * sizeof(char));
    s[0] = unbi->signe;

    int i = 1;
    chiffre *chui = malloc(sizeof(chiffre));
    chui = unbi->premier;
    while (chui != NULL)
    {
        s[i] = chui->c;
        chui = chui->suivant;
        i++;
    }

    if (DEBUGAGE)
    {
        printf("\n**** unbounded_int2string() = %s ****", s);
    }

    free(chui);
    return s;
}

unbounded_int ajouter_1chiffre_a_la_fin(const char ch, unbounded_int *unbi)
{
    /*  ALGORITHME

        ABCDEFGHIJ
        1234478909

        cas particulier dans le premier terme de la liste (hors signe)

        creer 1 > A { precedent = NULL, suivant = NULL }
        modifier UNBI premier = nouveau (A), dernier = nouveau (A)

        A (precedent = NULL, suivant = NULL)
        premier = A
        dernier = A

        *********

        creer 2 > B { precedent = dernier (A), suivant = NULL }
        modifier dernier (A) {precedent = inchangé, suivant = nouveau (B)}
        modifier UNBI dernier = nouveau (B)

        A (precedent = NULL, suivant = B)
        B (precedent = A, suivant = NULL
        premier = A
        dernier = B

        *********

        creer 3 > C { precedent = dernier (B), suivant = NULL }
        modifier dernier (B) {precedent = inchangé, suivant = nouveau (C)}
        modifier UNBI dernier = nouveau (C)

        A (precedent = NULL, suivant = B)
        B (precedent = A, suivant = C
        C (precedent = B, suivant = NULL)
        premier = A
        dernier = C

        etc.
    */
    chiffre *nouveau = malloc(sizeof(chiffre));
    if (!isdigit(ch))
    {
        /* il faut declarer unbi comme incorrect */
        unbi->signe = '*';
        return *unbi;
    }

    nouveau->c = ch;         /* affectation du chiffre lui même */
    nouveau->suivant = NULL; /* pas de suivant car on ajoute a la fin de la liste */

    if (unbi->premier == NULL && unbi->dernier == NULL) /* si la liste est vide */
    {
        nouveau->precedent = NULL;
        unbi->premier = nouveau;
        unbi->dernier = nouveau;
    }
    else
    {
        nouveau->precedent = unbi->dernier;
        unbi->dernier->suivant = nouveau;
        unbi->dernier = nouveau;
    }

    unbi->len++; /* increment de la taille */

    return *unbi;
}

void affiche_unbounded_int(unbounded_int *unbi)
{
    if (unbi == NULL) {
        return;
    }
    printf("%c", unbi->signe);
    chiffre *chui = malloc(sizeof(chiffre));
    chui = unbi->premier;
    while (chui != NULL)
    {
        printf("%c", chui->c);
        chui = chui->suivant;
    }
    free(chui);
}