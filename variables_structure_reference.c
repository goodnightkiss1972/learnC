#include <stdio.h>

typedef struct
{
    int x;
    int y;
} coordonnee;

void fonction(coordonnee *fi);

int main() {
    coordonnee i;
    i.x = 0;
    i.y = 0;
    coordonnee *ptri = &i;

    printf("Avant la fonction, la structure  a pour adresse %x et valeurs [%d, %d].\n", &i, i.x, i.y);
    // exemple de passage d'une structure
    fonction(ptri);
    printf("Apres l'appel la structure a mtnt  pour adresse %x et valeurs [%d, %d].\n", &i, i.x, i.y);
    printf("la structure a ete modifiee dans la fonction (passage par reference)\n");
    return 0;
}

void fonction(coordonnee *fi) {
    printf("Dans la fonction, la structure  recue a pour adresse %x et valeurs [%d, %d].\n",&fi, fi->x, fi->y);
    fi->x = fi->x + 1;
    fi->y = fi->y + 1;
    printf("Apres i+1 la structure recue a pour adresse          %x et valeurs [%d, %d].\n",&fi, fi->x, fi->y);
    return;
}