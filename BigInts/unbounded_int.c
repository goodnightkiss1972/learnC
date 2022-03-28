/* https://www.ltam.lu/Tutoriel-Ansi-C/prg-c98.htm */

#include <stdio.h>
#include "unbounded_int.h"

unbounded_int string2unbounded_int(const char *e)
{
    unbounded_int *unbi = malloc(sizeof(unbounded_int));
    
    /* determination du signe */
    unbi->signe = '+';
    
    int i = 0;
    while (*e != '\0')
    {
        printf("caractere %c\n", *e);
        e++;
        i++;
    }

    /* affectation de la taille */
    unbi->len = i;

    return *unbi;
}
