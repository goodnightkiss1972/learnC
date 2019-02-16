#include <stdio.h>
    int main() {
    int hauteur;
    printf("Quelle hauteur ?");
    scanf("%d", &hauteur);
    for (int i = 1; i <= hauteur; i++) {
        for (int j = 1; j <= hauteur; j++) {
            printf("*");
        }
        
        printf("\n");
    }
    return 0;
}