#include <stdio.h>

#define taille_tableau 10

void affiche_tableau(int table[], int taille);
int indice_plus_petit_apres_i(int t[], int len, int i);

int main() {
    int tableau[taille_tableau] = {4, 3, 0, 6, 18, 10, 4, 7, 21, 9};
    affiche_tableau(tableau, taille_tableau);
    for (int i = 0; i < taille_tableau; i++) {
        int imini, temp;
        imini = indice_plus_petit_apres_i(tableau, taille_tableau, i);
        temp = tableau[i];
        tableau[i] = tableau[imini];
        tableau[imini] = temp;
        affiche_tableau(tableau, taille_tableau);
    }
    return 0;
}

void affiche_tableau(int table[], int taille) {
    if (taille == 0) {
        return;
    }
    printf("\n");
    for (int i = 0;i < taille;i++) {
        printf("[ %d ]", table[i]);
    }
    return;
}

int indice_plus_petit_apres_i(int t[], int len, int i) {
    // la subtilite est de bien initialiser indice et minimum
    // car la recherche peut ne pas trouver de minimum apres i
    int indice = i, minimum = t[i];
    for (int j = i; j < len; j++) {
        if (t[j] < minimum) {
            indice = j;
            minimum = t[j];
        }
    }
    return indice;
}

