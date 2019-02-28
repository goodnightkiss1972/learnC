#include <stdio.h>

void fonction(int fi[]);

int main() {
    int i[2] = {15, 0};

    printf("Avant la fonction, i a pour adresse %x et valeur %d, %d.\n", &i, i[0], i[1]);
    // exemple de passage d'un tableau
    fonction(i);
    printf("Apres la fonction, i a pour adresse %x et valeur %d, %d.\n", &i, i[0], i[1]);
    return 0;
}

void fonction(int fi[]) {
    printf("Dans la fonction, fi a pour adresse %x et valeur %d, %d.\n",&fi, fi[0], fi[1]);
    fi[0] = fi[0] +1;
    printf("Dans la fonction, fi a pour adresse %x et valeur %d, %d.\n",&fi, fi[0], fi[1]);
    return;
}