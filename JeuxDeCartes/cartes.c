#include <stdio.h>
#include <stdlib.h>

typedef enum {AS, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI} valeur_carte;
typedef enum {TREFLE=0, CARREAU=13, COEUR=26, PIQUE=39} couleur_carte;

typedef struct carte carte;
struct carte
{
    valeur_carte valeur;
    couleur_carte couleur;
};

int plusPetit(carte c1, carte c2){
    int resultat = 0; //0 si c1 > c2, 1 si c1 < c2
    if (c1.valeur < c2.valeur){
        resultat = 1;
    }
    if (c1.valeur == c2.valeur && c1.couleur < c2.couleur){
        resultat = 1;
    }
    return resultat;
}

int estTrie(carte *hand, int taille){
    int resultat = 1; //1 triée, 0 sinon
    for (int i = 0; i<taille; i++){
        carte c1 = *(hand+i);
        carte c2 = *(hand+1+i);
        if((plusPetit(c1,c2))==0){
            resultat = 0;
        }
    }
    return resultat;
}

int versNombre(carte c){
    return c.valeur + c.couleur;
}

carte versCarte(int n){
    carte c;
    if (n<=12){
        c.valeur = n;
        c.couleur = 0;
    }
    else{
        c.valeur = n%13;
        c.couleur = n/13 * 13;
    }
    return c;
}

int main(){
    struct carte c1;
    c1.valeur = CINQ;
    c1.couleur = COEUR;
    struct carte c2;
    c2.valeur = CINQ;
    c2.couleur = PIQUE;
    struct carte c3;
    c3.valeur = ROI;
    c3.couleur= PIQUE;
    struct carte hand1[3]={c1,c2,c3};
    struct carte hand2[3]={c3,c2,c1};
    int a = estTrie(hand1,3);
    int b = estTrie(hand2,3);
    printf("--- test de la fonction plusPetit --- \n");
    printf("%d\n",plusPetit(c1,c2));
    printf("--- test de la fonction estTrie --- \n");
    printf("%d\n",a);
    printf("%d\n",b);
    printf("--- test de la fonction versNombre --- \n");
    printf("%d\n",versNombre(c1));
    printf("%d\n",versNombre(c3));
    printf("--- test de la fonction versCarte --- \n");
    struct carte c4 = versCarte(13);
    struct carte c5 = versCarte(51);
    printf("%d\n",c4.valeur);
    printf("%d\n",c4.couleur);
    printf("%d\n",c5.valeur);
    printf("%d\n",c5.couleur);
}

