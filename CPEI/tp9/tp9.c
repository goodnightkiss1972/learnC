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
int taille_liste(list *l);
list *renverse_liste(list *l);

/* Exercice 2 */
int valeur_a_la_position_liste(list *l, int i);
int position_de_la_premiere_valeur_liste(list *l, int valeur);
int indice_minimum_liste(list *l);

int main()
{
    int tableau[10] = {5, 6, 7, 2, 3, 10, 4, 1, 0, 12};

    list *maliste = new_list(tableau, 10);
    printf("\n");
    affiche_liste(maliste);
    printf("\nLa liste contient %d elements.\n", taille_liste(maliste));

    list *malisteinversee = renverse_liste(maliste);
    printf("\n");
    affiche_liste(malisteinversee);

    printf("\nL'element 3 de la premiere liste est : %d\n", valeur_a_la_position_liste(maliste, 3));
    printf("\nL'element 15 de la premiere liste est : %d\n", valeur_a_la_position_liste(maliste, 15));

    printf("\nLa premiere valeur 1 est a la position : %d\n", position_de_la_premiere_valeur_liste(maliste, 1));
    printf("\nLa premiere valeur 99 est a la position : %d\n", position_de_la_premiere_valeur_liste(maliste, 99));

    printf("\n");
    affiche_liste(maliste);

    printf("\nL'indice du minimum de la liste est : %d\n", indice_minimum_liste(maliste));
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

int taille_liste(list *l)
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
    // calculer la taille de la liste, puis mettre ses elements a l'envers dans un tableau
    // puis creer la liste a partir de ce tableau avec la fonction du prof.
    int taille = taille_liste(l);
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

int valeur_a_la_position_liste(list *l, int i)
{
    int indice = 0;
    while (l != NULL) // on balaye la liste
    {
        if (indice == i) // on a trouve l'element i
        {
            return l->head;
        }
        else // on avance
        {
            l = l->queue;
            indice++;
        }
    }
    // remarque au dernier coup on a pu avancer dans le vide et donc le while s'interrompt.
    return -1; // on est pas arrive a i car la liste s'est terminee avant
}

int position_de_la_premiere_valeur_liste(list *l, int valeur)
{
    int indice = 0;
    while (l != NULL) // on balaye la liste
    {
        if (l->head == valeur) // on a trouve l'element i
        {
            return indice;
        }
        else // on avance
        {
            l = l->queue;
            indice++;
        }
    }
    // remarque au dernier coup on a pu avancer dans le vide et donc le while s'interrompt.
    return -1; // on est pas arrive a la valeur car la liste s'est terminee avant
}

int indice_minimum_liste(list *l)
{
    int taille = taille_liste(l);
    if (taille == 0)
    {
        printf("ERREUR: la liste est vide.\n");
        return INT_MIN;
    }
    int indice = 0, indice_minimum = 0;
    int minimum = l->head; // on initialise le minimum avec la premiere valeur
    while (l != NULL) // on balaye la liste
    {
        if (l->head <= minimum) // on a trouve plus petit ou egal
        {
            minimum = l->head;
            indice_minimum = indice;
        }
        l = l->queue; // on avance
        indice++;
    }
    return indice_minimum;
}