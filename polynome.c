#include <stdio.h>

double horner_rec(int i, double x, int n);
double horner_it(double x, int n);

int main()
{
    double resultat;
    resultat = horner_rec(0, 10, 2);
    printf("Resultat = %lf\n", resultat);
}

double horner_rec(int i, double x, int n)
{
    double a, temp;
    printf("Entrez coefficient %d : ", i);
    scanf("%lf", &a);
    if (i == n)
    {
        temp = a;
        printf("Coucou %d\n", i);
    }
    else
    {
        temp = a + x * horner_rec(i + 1, x, n);
        printf("Coucou %d\n", i);
    }
    printf("temp = %lf\n", temp);
    return temp;
}
double horner_it(double x, int n)
{
    double a;
    double b;
    printf("Entrez coefficient %d\n", n);
    scanf("%lf", &a);
    int i;
    for (i = 1; i <= n; i = i + 1)
    {
        printf("Entrez coefficient %d\n", (n - i));
        scanf("%lf", &b);
        a = b + x * a;
    }
    return a;
}