#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "unbounded_int.h"

void test_detection(const char *detection, char signe_attendu, int len_attendu);
void test_restitution(const char *restitution);

int main(void)
{

    test_detection ("1", '+', 1);
    test_detection("-1", '-', 1);
    test_detection ("120943834954059", '+', 15);
    test_detection("-1000012244343", '-', 13);
    test_restitution ("1");
    test_restitution("-1");
    test_restitution ("120943834954059");
    test_restitution("-1000012244343");


    printf("\n");
    printf("******************\n");
    printf("*    TESTS OK    *\n");
    printf("******************\n");
    return 0;
}

void test_detection(const char *detection, char signe_attendu, int len_attendu) {
    unbounded_int *unbi = (unbounded_int*)malloc(sizeof(unbounded_int));
    *unbi = string2unbounded_int(detection);
    assert(unbi->signe == signe_attendu);
    assert(unbi->len == len_attendu);
    printf("Longueur = %ld\n", unbi->len);
    printf("Valeur: ");
    chiffre *chui = (chiffre*)malloc(sizeof(chiffre));
    chui = unbi->premier;
    while (chui != NULL)
    {
        printf("%c", chui->c);
        chui = chui->suivant;
    }
    free(chui);
    free(unbi);
}

void test_restitution(const char *restitution) {
    unbounded_int *unbi = (unbounded_int*)malloc(sizeof(unbounded_int));
    *unbi = string2unbounded_int(restitution);
    printf("Restitution %s\n", unbounded_int2string(unbi));
    free(unbi);
}