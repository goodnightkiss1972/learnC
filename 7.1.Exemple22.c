#include <stdio.h>
double horner_rec(int i, double x, int degre, double coefs[degre+1]);

int main()
{
    int n;
    double x;
    printf("Entrez degré polynome : ");
    scanf("%d", &n);
    double coefs[n+1];
    int i;
    for (i = 0;i <= n;i++)
    {
        printf("Entrez coefficient %d : ", i);
        scanf("%lf", &coefs[i]);
    }
    printf("Entrez x : ");
    scanf("%lf", &x);
    printf("Resultat : p(%lf) = %lf\n", x, horner_rec(0, x, n, coefs));
}

double horner_rec(int i, double x, int degre, double coefs[degre+1])
{
    if (i == degre)
    {
        return coefs[i];
    }
    else
    {
        return (coefs[i] + x * horner_rec(i + 1, x, degre, coefs));
    }
}
