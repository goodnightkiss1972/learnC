#include <stdio.h>

int pgcd(int a, int b);

int main()
{
    int a, b;
    printf("Entrez deux nombres entiers svp :\n");
    scanf("%d %d", &a, &b);
    printf("Technique iteration: pgcd(%d,%d) = %d\n", a, b, pgcd(a, b));
    return 0;
}

int pgcd(int a, int b)
{
    int minab, i, pgcd;
    if (a < 1 || b < 1)
    {
        printf("pgcd demande deux entiers strictement superieurs a 1.\n");
        return -1;
    }
    if (a == b)
    {
        return a;
    }
    if (a < b)
    {
        minab = a;
    }
    else
    {
        minab = b;
    }
    for (i = 1;i <= minab;i++) {
        if((a % i == b % i) && ((a % i) == 0) && ((b % i) == 0)) {
            pgcd = i;
        }
    }
    return pgcd;
}
