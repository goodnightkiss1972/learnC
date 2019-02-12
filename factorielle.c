/* factorielle.c */
#include <stdio.h>

/* Fonction qui calcule n! (factorielle n) */
double factorielle(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorielle(n - 1);
}

int main(void)
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    printf("%d! = %lf\n", n, factorielle(n));
    return 0;
}