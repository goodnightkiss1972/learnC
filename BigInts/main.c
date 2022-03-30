#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "unbounded_int.h"

#define DEBUGAGE true

void test_string2unbounded_int(const char *test, char signe_attendu, int len_attendu);
void test_unbounded_int2string(const char *test);

int main(void)
{

    test_string2unbounded_int("1", '+', 1);
    test_string2unbounded_int("-1", '-', 1);
    test_string2unbounded_int("120943834954059", '+', 15);
    test_string2unbounded_int("-1000012244343", '-', 13);
    test_unbounded_int2string("1");
    test_unbounded_int2string("-1");
    test_unbounded_int2string("120943834954059");
    test_unbounded_int2string("-1000012244343");

    printf("\n");
    printf("******************\n");
    printf("*    TESTS OK    *\n");
    printf("******************\n");
    return 0;
}

void test_string2unbounded_int(const char *test, char signe_attendu, int len_attendu)
{
    unbounded_int *unbi = (unbounded_int *)malloc(sizeof(unbounded_int));
    *unbi = string2unbounded_int(test);
    assert(unbi->signe == signe_attendu);
    assert(unbi->len == len_attendu);
    if (DEBUGAGE)
    {
        printf("** LONGUEUR = %ld ", unbi->len);
        printf("** VALEUR = ");
        printf("%c", unbi->signe);
        chiffre *chui = (chiffre *)malloc(sizeof(chiffre));
        chui = unbi->premier;
        while (chui != NULL)
        {
            if (DEBUGAGE)
                printf("%c", chui->c);
            chui = chui->suivant;
        }
        if (DEBUGAGE)
            printf("\n");
        free(chui);
    }
    free(unbi);
}

void test_unbounded_int2string(const char *test)
{
    unbounded_int *unbi = (unbounded_int *)malloc(sizeof(unbounded_int));
    *unbi = string2unbounded_int(test);
    printf("test %s\n", unbounded_int2string(unbi));
    free(unbi);
}