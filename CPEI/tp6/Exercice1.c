#include <stdio.h>

#define len 6
void affiche_tableau(int table[], int taille);
void copie_tableau(int source[], int t_source, int dest[], int t_dest);

int main() {
    int tab1[len] = {10, 20, 30, 40, 50, 60};
    affiche_tableau(tab1, len);

    int tab2[len];
    copie_tableau(tab1, len, tab2, len);
    affiche_tableau(tab2, len);
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

void copie_tableau(int source[], int t_source, int dest[], int t_dest) {
    if (t_source == 0) {
        printf("ERREUR : La taille du tableau est egale a zero...\n");
        return;
    }
    if (t_source != t_dest) {
        printf("ERREUR : Les deux tableaux n'ont pas la meme taille...\n");
        return;
    }
    for (int i = 0;i < t_source; i++) {
        dest[i] = source[i];
    }
    return;
}