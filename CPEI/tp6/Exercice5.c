#include <stdio.h>
// lien utile : https://www.irif.fr/~hf/verif/ens/an08-09/IF2/Cours10/C10.htm
#define len 10
void affiche_tableau(int table[], int taille);
void trie(int table[], int taille);

int main() {
    int tableau[len] = {4, 3, 0, 6, 18, 10, 4, 7, 21, 9};
    affiche_tableau(tableau, len);
    int pivot = tableau[len/2];
    trie(tableau, pivot);
    affiche_tableau(tableau, len);
    return 0;
}

void trie(int table[], int taille) {

}

void affiche_tableau(int table[], int taille) {
    if (taille == 0) {
        return;
    }
    printf("\n");
    for (int i = 0;i < taille;i++) {
        printf("[ %3d  ]", table[i]);
    }
    return;
}
