#include <stdio.h>
#include <stdlib.h>

typedef struct list list;
struct list
{
    int head;
    list *queue;
};

// Crée oar le prof dans tp9.c
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

// Viens de ex1.c

int len_list(list *liste)
{
    int i = 0;

    while (liste != NULL)
    {
        i++;
        liste = liste->queue;
    }

    return i;
}

void affichage(list *liste)
{
    while (liste != NULL)
    {
        printf("%d ", liste->head);
        liste = liste->queue;
    }
}

//DEBUT PARTIE 3

list *echange_list(int i, int j, list *lst)
{
    int len = len_list(lst);
    list *cur_lst = lst;

    if ((i >= len) || (j >= len))
    {
        return NULL;
    }

    int t[len];
    for (int k = 0; k < len; k++)
    {
        t[k] = cur_lst->head;
        cur_lst = cur_lst->queue;
    }

    int temp = t[i];
    t[i] = t[j];
    t[j] = temp;

    cur_lst = lst;

    for (int k = 0; k < len; k++)
    {
        cur_lst->head = t[k];
        cur_lst = cur_lst->queue;
    }
    list *result = new_list(t, len);
    return result;
}

//Note: Implémenter une meilleure fonction de tri
void tri_bulle(int t[], int len)
{
    int temp;
    for (int i = len - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

list *sort_list(list *lst)
{
    int len = len_list(lst);
    list *cur_lst = lst;

    int t[len];
    for (int k = 0; k < len; k++)
    {
        t[k] = cur_lst->head;
        cur_lst = cur_lst->queue;
    }

    tri_bulle(t, len);

    cur_lst = lst;

    for (int k = 0; k < len; k++)
    {
        cur_lst->head = t[k];
        cur_lst = cur_lst->queue;
    }
    list *result = new_list(t, len);
    return result;
}

int main()
{
    int test1[9] = {56, 87, 2, 3, 4, 5, 6, 7, 45};
    int test2[0] = {};
    list *test1a;
    list *test2a;
    test1a = new_list(test1, 9);
    test2a = new_list(test2, 0);

    list *liste_echangee = echange_list(3, 7, test1a);
    affichage(liste_echangee);
    printf("\n");
    list *liste_triee = sort_list(test1a);
    affichage(liste_triee);
    return 0;
}
