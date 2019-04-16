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
void display_list(list *l);
int list_size(list *l);
list *reverse_list(list *l);

/* Exercice 2 */
int value_at_position(list *l, int i);
int position_at_first_value(list *l, int valeur);
int position_of_minimum(list *l);

/* Exercice 3 */
list *switch_into_list(list *l, int src, int dest);
int position_of_minimum_after_a_position(list *l, int apres);
list *order_list(list *l);

/* Supplements */
list *add_to_list(list *l, int newhead);
list *reach_member_list(list *l, int member);
list *add_to_list_after_position(list *l, int newhead, int position);

int main()
{
    int tableau[10] = {5, 6, 7, 1, 3, 10, 4, 2, 9, 0};

    list *maliste = new_list(tableau, 10);
    printf("\n");
    display_list(maliste);
    printf("\nLa liste contient %d elements.\n", list_size(maliste));

    list *malisteinversee = reverse_list(maliste);
    printf("\n");
    display_list(malisteinversee);

    printf("\nL'element 3 de la premiere liste est : %d\n", value_at_position(maliste, 3));
    printf("\nL'element 15 de la premiere liste est : %d\n", value_at_position(maliste, 15));

    printf("\nLa premiere valeur 1 est a la position : %d\n", position_at_first_value(maliste, 1));
    printf("\nLa premiere valeur 99 est a la position : %d\n", position_at_first_value(maliste, 99));

    printf("\n");
    display_list(maliste);

    printf("\nL'indice du minimum de la liste est : %d\n", position_of_minimum(maliste));

    printf("\nAvant echange de 1 vers 3\n");
    display_list(maliste);

    list *malisteechangee = switch_into_list(maliste, 1, 3);
    printf("\nApres echange de 1 vers 3\n");
    display_list(malisteechangee);

    printf("\nAvant tri\n");
    display_list(maliste);

    list *malistetriee = order_list(maliste);
    printf("\nApres tri\n");
    display_list(malistetriee);

    printf("\nApres ajout de 8 au debut\n");
    malistetriee = add_to_list(malistetriee, 8);
    display_list(malistetriee);

    printf("\nApres ajout de 11 au debut et tri dans la foulee\n");
    malistetriee = order_list(add_to_list(malistetriee, 11));
    display_list(malistetriee);

    // presque equivalent a "value_at_position" sauf qu'ici c'est le type list qui est retourne
    list *recherche = reach_member_list(maliste, 6);
    printf("\nLa valeur recherchee est %d\n", recherche->head);
    display_list(maliste);
    
    list *malisteajoutee = add_to_list_after_position(maliste, 8, 4);
    printf("\nApres ajout de %d en position %d\n", 8, 4);
    display_list(malisteajoutee);

    malisteajoutee = add_to_list_after_position(malisteajoutee, 15, 0);
    printf("\nApres ajout de %d en position %d\n", 15, 0);
    display_list(malisteajoutee);

    malisteajoutee = add_to_list_after_position(malisteajoutee, 12, 11);
    printf("\nApres ajout de %d en position %d\n", 12, 11);
    display_list(malisteajoutee);

    malisteajoutee = add_to_list_after_position(malisteajoutee, 19, 13);
    printf("\nApres ajout de %d en position %d\n", 19, 13);
    display_list(malisteajoutee);

}

void display_list(list *l)
{
    while (l != NULL)
    {
        printf("%d ", l->head);
        l = l->queue;
    }
    printf("\n");
}

int list_size(list *l)
{
    int taille = 0;
    while (l != NULL)
    {
        taille++;
        l = l->queue;
    }
    return taille;
}

list *reverse_list(list *l)
{
    // calculer la taille de la liste, puis mettre ses elements a l'envers dans un tableau
    // puis creer la liste a partir de ce tableau avec la fonction du prof.
    int taille = list_size(l);
    if (taille == 0)
    {
        printf("\nERREUR: la liste est vide.\n");
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

int value_at_position(list *l, int i)
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

int position_at_first_value(list *l, int valeur)
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

int position_of_minimum(list *l)
{
    int taille = list_size(l);
    if (taille == 0)
    {
        printf("\nERREUR: la liste est vide.\n");
        return INT_MIN;
    }
    int indice = 0, indice_minimum = 0;
    int minimum = l->head; // on initialise le minimum avec la premiere valeur
    while (l != NULL)      // on balaye la liste
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

list *switch_into_list(list *l, int src, int dest)
{
    int taille = list_size(l);
    if (taille == 0)
    {
        printf("\nERREUR: la liste est vide.\n");
        return NULL;
    }
    if (src < 0 || src > taille - 1 || dest < 0 || dest > taille - 1)
    {
        printf("\nERREUR: un des indices est en dehors de la liste.\n");
        return NULL;
    }
    int tableau[taille]; // declaration du tableau de travail
    for (int i = 0; i < taille; i++)
    {
        //printf("Boucle %d valeur %d\n", i, l->head);
        tableau[i] = l->head;
        l = l->queue;
    }
    // echange
    int temp = tableau[dest];
    tableau[dest] = tableau[src];
    tableau[src] = temp;

    list *retour = new_list(tableau, taille);
    return retour;
}

int position_of_minimum_after_a_position(list *l, int apres)
{
    int taille = list_size(l);
    if (taille == 0)
    {
        printf("\nERREUR: la liste est vide.\n");
        return INT_MIN;
    }

    // on va avancer de "apres" dans la liste avant de commencer
    // si c'est possible
    if (apres < 0 || apres > taille - 1)
    {
        printf("\nERREUR: indice apres hors limite.\n");
        return -1;
    }
    for (int i = 0; i < apres; i++)
    {
        l = l->queue; // on avance
    }

    int indice = apres, indice_minimum = apres;
    int minimum = l->head; // on initialise le minimum avec la premiere valeur
    while (l != NULL)      // on balaye la liste
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

list *order_list(list *l)
{
    int taille = list_size(l);
    if (taille == 0)
    {
        printf("\nERREUR: la liste est vide.\n");
        return NULL;
    }
    // tri croissant
    list *tri = l;
    for (int i = 0; i < taille; i++)
    {
        tri = switch_into_list(tri, position_of_minimum_after_a_position(tri, i), i);
    }
    /*
    printf("\nIndice minimum apres 0 : %d", position_of_minimum_after_a_position(tri, 0));
    printf("\nIndice minimum apres 4 : %d", position_of_minimum_after_a_position(tri, 4));
    printf("\nIndice minimum apres 9 : %d", position_of_minimum_after_a_position(tri, 9));
    printf("\nIndice minimum apres 10 : %d", position_of_minimum_after_a_position(tri, 10));
*/
    return tri;
}

list *add_to_list(list *l, int newhead)
{
    list *newlist = malloc(sizeof(list));
    newlist->head = newhead;
    newlist->queue = l;
    return newlist;
}

list *reach_member_list(list *l, int member)
{
    if (member > list_size(l) - 1)
    {
        printf("\nERREUR: impossible d'atteindre l'element %d.\n", member);
        return NULL;
    }
    int indice = 0;
    while (l != NULL)
    {
        if (indice == member)
        {
            return l;
        }
        l = l->queue;
        indice++;
    }
}

list *add_to_list_after_position(list *l, int newhead, int position)
{
    if (position > list_size(l))
    {
        printf("\nERREUR: la position est hors limite, impossible d'inserer l'element en position %d.\n", position);
        return l;
    }
    // on ajoute le nouveau membre au debut
    list *newlist = add_to_list(l, newhead);
    // ensuite on permute avec la fonction adequate
    newlist = switch_into_list(newlist, 0, position);
    return newlist;
}
