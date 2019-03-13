#include <stdio.h>

#define len 6

int somme_tableau(int tableau[], int taille);

int main() {
    int tab1[len] = {1, 4, 5, 5, 2, 3};
    printf("Somme des elements de tab1 = %d", somme_tableau(tab1, len));
    return 0;
}

int somme_tableau(int tableau[], int taille) {
    if (taille == 0) {
        printf("ERREUR : Le tableau a une taille nulle...");
        return -1;
    }
    int resultat;
    for (int i = 0; i < taille; i++) {
        resultat = resultat + tableau[i];
    }
    return resultat;
}
