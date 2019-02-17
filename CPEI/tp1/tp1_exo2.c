#include <stdio.h>

int main()
{
    int x, y, z;
    printf("quel nombre multiplier ?");
    scanf("%d %d", &x, &y);
    printf("produit des deux ? \n");
    scanf("%d", &z);
    if (z == x * y)
    {
        printf("Correct ! \n");
    }
    else
    {
        printf("dommage ! \n");
    }
    return 0;
}