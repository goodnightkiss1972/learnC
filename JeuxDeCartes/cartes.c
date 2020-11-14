#include <stdio.h>
#include <stdlib.h>

typedef enum {AS, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI} valeur_carte;
typedef enum {TREFLE=0, CARREAU=13, COEUR=26, PIQUE=39} couleur_carte;

typedef struct Carte Carte; // permet de manipuler directement le type "Carte" sans mettre le mot cle "struct" devant...
struct Carte
{
    valeur_carte valeur;
    couleur_carte couleur;
};

int plusPetit(Carte c1, Carte c2){
    int resultat = 0; //0 si c1 > c2, 1 si c1 < c2
    if (c1.valeur < c2.valeur){
        resultat = 1;
    }
    if (c1.valeur == c2.valeur && c1.couleur < c2.couleur){
        resultat = 1;
    }
    return resultat;
}

int estTrie(Carte *hand, int taille){
    int resultat = 1; //1 triée, 0 sinon
    for (int i = 0; i<taille; i++){
        Carte c1 = *(hand+i);
        Carte c2 = *(hand+1+i);
        if((plusPetit(c1,c2))==0){
            resultat = 0;
        }
    }
    return resultat;
}

int versNombre(Carte c){
    return c.valeur + c.couleur;
}

Carte versCarte(int n){
    Carte c;
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

void affiche_carte(Carte c) {
  printf("%d %d \n", c.valeur, c.couleur);
}

Carte creer_Carte(int valeur, int couleur) {
  Carte c = { valeur, couleur };
  return c;
}

int main(){
    struct Carte c1;
    c1.valeur = CINQ;
    c1.couleur = COEUR;
    struct Carte c2;
    c2.valeur = CINQ;
    c2.couleur = PIQUE;
    struct Carte c3;
    c3.valeur = ROI;
    c3.couleur= PIQUE;
    struct Carte hand1[3]={c1,c2,c3};
    struct Carte hand2[3]={c3,c2,c1};
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
    struct Carte c4 = versCarte(13);
    struct Carte c5 = versCarte(51);
    printf("%d\n",c4.valeur);
    printf("%d\n",c4.couleur);
    printf("%d\n",c5.valeur);
    printf("%d\n",c5.couleur);

    printf("--- un autre test des fonctions versNombre versCarte combinés : les deux affichages suivants doivent etre 5 0--- \n");
    struct Carte fab1 = {SIX, TREFLE};
    affiche_carte(fab1);
    affiche_carte(versCarte(versNombre(fab1)));

    printf("Creation du paquet standard 52 cartes pour le poker.\n");
    Carte paquet[52];
    int i = 0;
    for (int couleur = 0; couleur <= 3; couleur++) {
      for (int valeur = 0; valeur <= 12; valeur++) {
	//printf("valeur = %d / couleur = %d \n", valeur, couleur);
	paquet[i] = creer_Carte(valeur, couleur);
	i++;
      }
    }
    for (int i = 0; i < 52; i++) {
      affiche_carte(paquet[i]);
    }
}

