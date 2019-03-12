#include <stdio.h>
// https://fr.wikipedia.org/wiki/Algorithme_de_tri

void main()
{
    int table[10] = {8, 18, 4, 3, 20, 13, 5, 2, 15, 5};
//    int table[10] = {2, 18, 4, 3, 20, 13, 5, 8, 15, 5};
//    int table[10] = {8, 4, 3, 5, 2, 5, 15, 13, 20, 18};
    int n = sizeof(table) / sizeof(table[0]); // technique simple pour connaitre la taille d'un tableau
    int temoin = 0;
    do
    {
        temoin = 0;
        for (int i = 0; i < n - 1; i++) // on va echanger les places deux par deux
        {
            if (table[i + 1] < table[i])
            {
                int temp = table[i + 1];
                table[i + 1] = table[i];
                table[i] = temp;
                temoin = 1; // on sait qu'on a fait une action
                // remarque : si on veut éviter le dernier tour de vérification
                // il suffirait de ne pas mettre le temoin à 1 si la seule permutation a lieu pour i = 0
            }
        }
        for (int j = 0; j < n; j++) // quand on a parcouru n-1 on affiche le tableau partiellement trié
        {
            printf("%d, ", table[j]);
        }
        printf("\n");
    } while (temoin != 0);
}
