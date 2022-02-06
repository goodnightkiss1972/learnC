#include <stdio.h>

typedef struct
{
    int coordoonnees[2];
    char lettre;
} intersection;

void fonction(intersection fi);

int main() {
    intersection i;
    i.coordoonnees[0] = 0;
    i.coordoonnees[1] = 0;
    i.lettre = 'A';

    printf("Avant la fonction, la structure  a pour adresse %x et valeurs %c (%d, %d).\n", &i, i.lettre, i.coordoonnees[0], i.coordoonnees[1]);
    // exemple de passage d'une structure
    fonction(i);
    printf("Apres l'appel la structure a mtnt  pour adresse %x et valeurs %c (%d, %d).\n", &i, i.lettre, i.coordoonnees[0], i.coordoonnees[1]);
    printf("la structure n'a pas ete modifiee dans la fonction (passage par copie)\n");
    return 0;
}

void fonction(intersection fi) {
    printf("Dans la fonction, la structure  recue a pour adresse %x et valeurs %c (%d, %d).\n",&fi, fi.lettre, fi.coordoonnees[0], fi.coordoonnees[1]);
    fi.coordoonnees[0] = fi.coordoonnees[0] +1;
    fi.coordoonnees[1] = fi.coordoonnees[1] +1;
    fi.lettre = 'B';
    printf("Apres i+1 la structure recue a pour adresse          %x et valeurs %c (%d, %d).\n",&fi, fi.lettre, fi.coordoonnees[0], fi.coordoonnees[1]);
    return;
}