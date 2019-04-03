#include <stdio.h>

int main()
{
    FILE *file = fopen("Exercice1.c", "r");
    if (file == NULL)
    {
        printf("\nERREUR: impossible d'ouvrir le fichier.\n");
    }
    else
    {
        printf("\nLe fichier est bien ouvert.\n");
    }

    /* // lecture d'un entier
    int x;
    fscanf(file, "%d", &x);
    printf("La valeur contenue dans le fichier est: %d", x);
*/

    char buffer[2048];
    char *resultat = "EMPTY";
    while (resultat != NULL)
    {
        resultat = fgets(buffer, sizeof(buffer), file);
        if (resultat != NULL)
        {
            printf("%s", resultat);
        }
    }
    fclose(file);
    printf("\n");
    return 0;
}