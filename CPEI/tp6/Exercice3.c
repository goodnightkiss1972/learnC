#include <stdio.h>

int somme_tableau(int tableau[], int taille);

int main() {
    int tab1[6] = {1, 4, 5, 5, 2, 3};
    printf("Somme des elements de tab1 = %d", somme_tableau(tab1, sizeof(tab1)/sizeof(tab1[0])));
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
