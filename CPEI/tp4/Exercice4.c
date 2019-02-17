#include <stdio.h>

int pgcd_iteration(int a, int b);
int pgcd_recursion(int a, int b);

int main()
{
    int a, b;
    printf("Entrez deux nombres entiers svp :\n");
    scanf("%d %d", &a, &b);
    printf("Technique iteration: pgcd(%d,%d) = %d\n", a, b, pgcd_iteration(a, b));
    printf("Technique recursion: pgcd(%d,%d) = %d\n", a, b, pgcd_recursion(a, b));
    return 0;
}

int pgcd_iteration(int a, int b)
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

int pgcd_recursion(int a, int b)
{
    int reste;
    if (a < 1 || b < 1)
    {
        printf("pgcd demande deux entiers strictement superieurs a 1.\n");
        return -1;
    }
    if (a == b)
    {
        return a;
    }
    reste = a % b;
    printf("reste de %d %% %d = %d\n", a, b, reste);
    if (reste == 0) {
        return b;
    }
    else
    {
        return pgcd_recursion(b, reste);
    }
}