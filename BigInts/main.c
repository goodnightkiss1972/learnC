#include <stdio.h>
#include "unbounded_int.h"

int main(void)
{
    char chaine[] = "123";
    unbounded_int *retour = malloc(sizeof(unbounded_int));
    *retour = string2unbounded_int(chaine);
    printf("le signe  est %c\n", retour->signe);
    printf("la taille est %ld\n", retour->len);
    return 0;
}