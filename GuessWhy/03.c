#include <stdio.h>

// Calcul de la suite de Fibonacci avec un tableau

void main() {
    int n = 20;
    int fibo[n];
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i < n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    // fin du calcul, affichage de la suite
    for (int j = 0; j < n; j++){
        printf("%d, ", fibo[j]);
    }
}
