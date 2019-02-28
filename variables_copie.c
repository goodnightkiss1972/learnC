#include <stdio.h>

void fonction(int fi);

int main() {
    int i;
    i = 15;
    printf("Avant la fonction, i a pour adresse %x et valeur %d.\n", &i, i);
    // exemple de passage par copie
    fonction(i);
    printf("Apres la fonction, i a pour adresse %x et valeur %d.\n", &i, i);
    return 0;
}

void fonction(int fi) {
    printf("Dans la fonction, fi a pour adresse %x et valeur %d.\n",&fi, fi);
    fi = fi +1;
    printf("Dans la fonction, fi a pour adresse %x et valeur %d.\n",&fi, fi);
    return;
}