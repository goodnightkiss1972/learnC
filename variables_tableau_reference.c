#include <stdio.h>

void fonction(int fi[]);

int main() {
    int i[2] = {15, 0};

    printf("Avant la fonction, le tableau a pour adresse %x et valeurs [%d, %d].\n", &i, i[0], i[1]);
    // exemple de passage d'un tableau
    fonction(i);
    printf("Apres l'appel le tableau a mtnt pour adresse %x et valeurs [%d, %d].\n", &i, i[0], i[1]);
    printf("le parametre a ete modifie dans la fonction (passage par reference)\n");
    return 0;
}

void fonction(int fi[]) {
    printf("Dans la fonction, le tableau recu a pour adresse %x et valeurs [%d, %d].\n",&fi, fi[0], fi[1]);
    fi[0] = fi[0] +1;
    fi[1] = fi[1] +1;
    printf("Apres i+1 le tableau recu a pour adresse %x         et valeurs [%d, %d].\n",&fi, fi[0], fi[1]);
    return;
}