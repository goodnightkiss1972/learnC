#include <stdio.h>

void fonction(int fi);

int main() {
    int i;
    i = 15;
    printf("Avant la fonction, i a pour adresse %x et valeur %d.\n", &i, i);
    // exemple de passage par copie
    fonction(i);
    printf("Apres l'appel i a pour adresse %x et valeur %d.\n", &i, i);
    printf("Le parametre n'a pas ete modifie pour l'appelant, on en a fait une copie.\n");
    return 0;
}

void fonction(int fi) {
    printf("En entrant dans la fonction, le parametre recu a pour adresse %x et valeur %d.\n",&fi, fi);
    fi = fi +1;
    printf("Apres i+1 dans la fonction,  le parametre recu a pour adresse %x et valeur %d.\n",&fi, fi);
    return;
}