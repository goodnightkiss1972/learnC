#include <stdio.h>

double carres(double a, int n);

int main()
{
    double a;
    int n;
    printf("Entrez un nombre puis la puissance n (entier positif) svp :\n");
    scanf("%lf %d", &a, &n);
    printf("Carrés itérés : (%lf)^%d = %lf\n", a, n, carres(a, n));
    return 0;
}

double carres(double a, int n)
{
    if (n < 0)
    {
        printf("La puissance %d n'est pas positive...\n", n);
        return -1;
    }
    if (n == 0)
    {
        return 1;
    }
    {
        printf("carres simples - multiplication \n");
        return (a * carres(a, n - 1));
    }
}
