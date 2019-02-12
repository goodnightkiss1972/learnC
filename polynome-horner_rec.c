#include <stdio.h>

double horner_rec(int i, double x, int n);

int main()
{
    double resultat;
    resultat = horner_rec(0, 10, 2);
    printf("Resultat = %lf\n", resultat);
}

double horner_rec(int i, double x, int n)
{
    double a;
    printf("Entrez coefficient %d : ", i);
    scanf("%lf", &a);
    if (i == n)
    {
        return a;
    }
    else
    {
        return (a + x * horner_rec(i + 1, x, n));
    }
}
