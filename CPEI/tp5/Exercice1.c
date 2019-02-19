#include <stdio.h>

double expo(int a, int b);
double expoMalin16(int a, int b);
double expoMalin(int a, int b);

int main()
{
    int a, b;
    printf("Entrez deux nombres entiers positifs svp : ");
    scanf("%d %d", &a, &b);
    printf("\nLe resultat %d ^ %d = %lf\n", a, b, expo(a, b));
    printf("\nLe resultat malin16 %d ^ %d = %lf\n", a, b, expoMalin16(a, b));
    printf("\nLe resultat malin %d ^ %d = %lf\n", a, b, expoMalin(a, b));
    return 0;
}

double expo(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    else
    {
        printf("|");
        return a * expo(a, b - 1);
    }
}

double expoMalin16(int a, int b)
{
    if (b == 16)
    {
        return expo(expo(expo(expo(a, 2), 2), 2), 2);
    }
    else
    {
        return -1;
    }
}

double expoMalin(int a, int b)
{
    if (b == 16){
        return expoMalin16(a, b);
    }
    if (b == 8){
        return expo(expo(expo(a, 2), 2), 2);
    }
    if (b == 4){
        return expo(expo(a, 2), 2);
    }
    int q, r;
    q=b/a;
    r=b%a;
    double resultQuotient;
    printf("a = %d, b = %d, q = %d, r = %d\n", a, b, q, r);
    if (q == 2){
        resultQuotient = expo(expo(a, 2), 2);
    }
    if (q == 4){
        resultQuotient = expo(expo(expo(a, 2), 2), 2);
    }
    if (q == 8){
        resultQuotient = expoMalin16(a, b);
    }


    return resultQuotient;
}