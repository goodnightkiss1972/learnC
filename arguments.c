#include <stdio.h>
#include <string.h>

/*
Pour récupérer les arguments dans le programme C, on utilise les paramètres argc et argv du main. L'entier argc donne le nombre d'arguments rentrés dans la ligne de commande plus 1, et le paramètre argv est un tableau de chaînes de caractères qui contient comme éléments :

Le premier élément argv[0] est une chaîne qui contient le nom du fichier executable du programme ;
Les éléments suivants argv[1], argv[2], etc... sont des chaînes de caractères qui contiennent les arguments passés en ligne de commande.
Le prototype de la fonction main est donc :
int main(int argc, char**argv);
*/

int main(int argc, char **argv)
{
    int i;
    printf("Vous avez entré %d mots\n", argc - 1);
    puts("Leurs longueurs sont :");
    for (i = 1; i < argc; i++)
    {
        printf("%s : %lu\n", argv[i], strlen(argv[i]));
    }
    return 0;
}