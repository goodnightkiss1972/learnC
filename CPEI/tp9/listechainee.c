#include <stdio.h>
#include <stdlib.h>

// Notre structure qui contient des coordonnees dans le plan
typedef struct Element Element;
struct Element
{
    double x;
    double y;
    Element *suivant;
};

// Cette structure contient un pointeur vers le premier element de la liste
typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

Liste *initialisationListe();

int main()
{
    Liste *maListe = initialisationListe();

    printf("Mon premier point de coordonnees : (%lf, %lf)\n", maListe->premier->x, maListe->premier->y);
}

Liste *initialisationListe()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if(liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    element->x = 2;
    element->y = 1;
    element->suivant = NULL;
    liste->premier = element;
    
    return liste;
}

