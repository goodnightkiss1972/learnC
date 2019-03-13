#include <stdio.h>

void affiche_tableau(int table[], int taille);
void copie_tableau(int source[], int t_source, int dest[], int t_dest);

int main() {
    int tab1[6] = {10, 20, 30, 40, 50, 60};
    int t_tab1 = sizeof(tab1) / sizeof(tab1[0]);
    affiche_tableau(tab1, t_tab1);

    int tab2[t_tab1];
    copie_tableau(tab1, t_tab1, tab2, t_tab1);
    affiche_tableau(tab2, t_tab1);
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