#include <stdio.h>
// l'utilisation du tableau n'est pas forcement une bonne idee
// car on trimbale la taille du tableau [3] et le degre du polynome à plusieurs endroits
// alors que mathematiquement ces deux notions sont liées. 
double horner_rec(int i, double x, int degre, double coefs[3]);

int main()
{
    double x = 2, resultat;
    double coefs[3]={2, 4, 3};
    int degre = 2; // contient le nombre de coefs -1
    printf("Resultat : p(%lf) = %lf\n", x, horner_rec(0, x, degre, coefs));
}

double horner_rec(int i, double x, int degre, double coefs[3])
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
