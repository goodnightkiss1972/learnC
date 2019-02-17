#include <stdio.h>

int moncarre(int x);

int main() {
    int depart = 4;
    int resultat;
    resultat = moncarre(depart);
    printf("mon resultat est %d et mon depart etait %d", resultat, depart);
    return 0;
}

int moncarre(int x) {
    int temp;
    temp = x * x;
    return(temp);
}