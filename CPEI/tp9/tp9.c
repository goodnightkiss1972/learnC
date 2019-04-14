#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list list;
struct list
{
    int head;
    list *queue;
};

list *new_list(int array[], int len)
{
    list *lst = NULL;
    list **end = &lst;
    for (int i = 0; i < len; i++)
    {
        *end = malloc(sizeof(list));
        (*end)->head = array[i];
        (*end)->queue = NULL;
        end = &((*end)->queue);
    }
    return lst;
}

/* Exercice 1 */
void affiche_liste(list *l);
int taille_list(list *l);
list *renverse_liste(list *l);

/* Exercice 2 */

int main()
{

    int tableau[10] = {5, 6, 7, 2, 3, 10, 4, 1, 0, -1};

    list *maliste = new_list(tableau, 10);
    affiche_liste(maliste);
    printf("La liste contient %d elements.\n", taille_list(maliste));

    list *malisteinversee = renverse_liste(maliste);
    affiche_liste(malisteinversee);
}

void affiche_liste(list *l)
{
    while (l != NULL)
    {
        printf("%d ", l->head);
        l = l->queue;
    }
    printf("\n");
}

int taille_list(list *l)
{
    int taille = 0;
    while (l != NULL)
    {
        taille++;
        l = l->queue;
    }
    return taille;
}

list *renverse_liste(list *l)
{
    // calculer la taille de la liste, puis mettre ses elements dans un tableau
    // creer un deuxieme tableau en lisant le premier a l'envers
    // puis creer la liste a partir de ce deuxieme tableau.
    int taille = taille_list(l);
    if (taille == 0)
    {
        printf("ERREUR: la liste est vide.\n");
        return NULL;
    }
    int tableau[taille];
    for (int i = 0; i < taille; i++)
    {
        //printf("Boucle %d valeur %d\n", taille-i-1, l->head);
        tableau[taille - i - 1] = l->head;
        l = l->queue;
    }
    list *retour = new_list(tableau, taille);
    return retour;
}