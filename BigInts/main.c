#include <stdio.h>
#include <assert.h>

#include "unbounded_int.h"

void test_detection(const char *detection, char signe_attendu, int len_attendu);

int main(void)
{
    test_detection ("1", '+', 1);
    test_detection("-1", '-', 1);
    test_detection ("120943834954059", '+', 15);
    test_detection("-1000012244343", '-', 13);

    printf("\n");
    printf("******************\n");
    printf("*    TESTS OK    *\n");
    printf("******************\n");
    return 0;
}

void test_detection(const char *detection, char signe_attendu, int len_attendu) {
    unbounded_int *unbi = malloc(sizeof(unbounded_int));
    *unbi = string2unbounded_int(detection);
    assert(unbi->signe == signe_attendu);
    assert(unbi->len == len_attendu);
}