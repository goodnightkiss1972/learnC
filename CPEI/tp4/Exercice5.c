#include <stdio.h>

int fib(int n);

int main()
{
    int n;
    printf("Entrez un nombre entier svp :\n");
    scanf("%d", &n);
    printf("Technique recursion: fib(%d) = %d\n", n, fib(n));
    return 0;
}

int fib(int n)
{
    printf("%d\n", n); // ne termine jamais car n devient negatif
    if (n < 0)
    {
        return -1;
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return (fib(n - 2) + fib(n - 1));
    }
}

/*
int f(int nbImpair)
{
    int i = 0, depart = 1, resultat = 0;
    if (nbImpair < 1)
    {
        return 0;
    }
    for (i = 0; i < nbImpair; i++)
    {
        resultat = resultat + (depart + i * 2);
    }
    return resultat;
}
*/