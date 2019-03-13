#include <stdio.h>

#define taille 10

int main() {
    int input;
    int tableau[taille];
    for (int i = 0; i < taille; i++) {
        printf("Entrez Rang %d = ", i);
        scanf("%d", &input);
        tableau[i] = input;
    }
    return 0;
}

