#include <stdio.h>

int fib_iteration(int n);

int main()
{
    int n;
    printf("Entrez un nombre entier strictement positif svp :\n");
    scanf("%d", &n);
    printf("Technique iteration: fib_iteration(%d) = %d\n", n, fib_iteration(n));
    return 0;
}

int fib_iteration(int n)
{
    int i, fibn, fibn1, fibn2;
    if (n < 0)
    {
        printf("Fibonacci necessite un entier non négatif svp...\n");
        return -1; // arrete la recursion pour fib(-1) appelee en // de fib(0)
    }
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        fibn1 = 1;
        fibn2 = 1;
        for (i = 1; i < n;i++){
            fibn = fibn1 + fibn2;
            fibn2 = fibn1;
            fibn1 = fibn;
        }
        return fibn;
    }
}
