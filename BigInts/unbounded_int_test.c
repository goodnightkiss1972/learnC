#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "unbounded_int.h"

#define DEBUGAGE false

void affiche_unbounded_int(unbounded_int *unbi);
void test_string2unbounded_int(const char *test, const char signe_attendu, const int len_attendu);
void test_unbounded_int2string(const char *test, const char *attendu);

int main(void)
{
    printf("\n");
    test_string2unbounded_int("1", '+', 1);
    test_string2unbounded_int("-1", '-', 1);
    test_string2unbounded_int("120943834954059", '+', 15);
    test_string2unbounded_int("-1000012244343", '-', 13);

/*    // test de la fonction d'affichage
    printf("\n");
    unbounded_int *test = malloc(sizeof(unbounded_int));
    *test = string2unbounded_int("545454");
    affiche_unbounded_int(test);
    printf("\n");
    *test = string2unbounded_int("-545454");
    affiche_unbounded_int(test);
    printf("\n");
*/

    printf("\n");
    test_unbounded_int2string("1", "+1");
    test_unbounded_int2string("-1", "-1");
    test_unbounded_int2string("120943834954059", "+120943834954059");
    test_unbounded_int2string("-1000012244343", "-1000012244343");

    printf("\n");
    printf("******************\n");
    printf("*    TESTS OK    *\n");
    printf("******************\n");
    return 0;
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

void test_string2unbounded_int(const char *test, const char signe_attendu, const int len_attendu)
{
    unbounded_int *unbi = malloc(sizeof(unbounded_int));
    *unbi = string2unbounded_int(test);

    if (DEBUGAGE)
    {
        printf("** LONGUEUR = %ld ", unbi->len);
        printf("** VALEUR = ");
        affiche_unbounded_int(unbi);
    }
    assert(unbi->signe == signe_attendu);
    assert(unbi->len == len_attendu);
    free(unbi);
    printf("**** test_string2unbounded_int OK pour %s\n", test);
}

void test_unbounded_int2string(const char *test, const char *attendu)
{
    unbounded_int *unbi = malloc(sizeof(unbounded_int));
    *unbi = string2unbounded_int(test);

    if (DEBUGAGE)
        printf("\n~~~~ unbounded_int2string = %s\n", unbounded_int2string(unbi));

    assert(strcmp(unbounded_int2string(unbi), attendu) == 0);
    free(unbi);
    printf("**** test_unbounded_int2string OK pour %s\n", test);
}