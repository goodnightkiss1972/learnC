#include <stdio.h>

void fonction(int *fi);

int main() {
    int i = 15;
    int *ptri = &i;
    printf("Avant la fonction, i a pour adresse %x et valeur %d.\n", &i, i);
    // exemple de passage par reference
    fonction(ptri); // on aurait aussi pu appeler avec fonction(&i);
    printf("Apres l'appel i a pour adresse %x et valeur %d.\n", &i, i);
    printf("le parametre a ete modifie dans la fonction (passage par reference)\n");
    return 0;
}

void fonction(int *fi) {
    printf("En entrant dans la fonction, le parametre recu a pour adresse %x et valeur %d.\n",&fi, *fi);
    *fi = *fi +1;
    printf("Apres i+1 dans la fonction,  le parametre recu a pour adresse %x et valeur %d.\n",&fi, *fi);
    return;
}