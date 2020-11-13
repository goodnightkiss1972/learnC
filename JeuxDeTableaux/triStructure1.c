#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nom[50];
    int age;
} Personne;

void Afficher(Personne P[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("\t%s \t %d ans\n",P[i].nom,P[i].age);
}

int Tri_age(const void* a,const void* b)
{
    Personne* pa=(Personne*)a;
    Personne* pb=(Personne*)b;
    return pa->age - pb->age;
}

int Tri_nom(const void* a,const void* b)
{
    Personne* pa=(Personne*)a;
    Personne* pb=(Personne*)b;
    return strcmp(pa->nom,pb->nom);
}

int main()
{
    Personne P[4] = {{"Pierre",20},{"Yves",50},{"Steph",18},{"Claude",27}};
    printf("Affichage brut :\n");
    Afficher(P,4);
    printf("Tri selon age :\n");
    qsort(P,4,sizeof(Personne),Tri_age);
    Afficher(P,4);
    printf("Tri selon nom :\n");
    qsort(P,4,sizeof(Personne),Tri_nom);
    Afficher(P,4);
    return 0;
}
