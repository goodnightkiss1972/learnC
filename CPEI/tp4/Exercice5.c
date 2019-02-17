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
        return -1; // arrete la recursion pour fib(-1) appelee en // de fib(0)
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
