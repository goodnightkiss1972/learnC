#include <stdio.h>
#include <stdlib.h>

typedef enum {AS = 1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI} valeur_carte;
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
    if (n<=13){
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
  // Pique, Trefle, Coeur, Carreau
  // char symboles[15+1] = {226, 153, 160, '-', 226, 153, 163, '-', 226, 153, 165, '-', 226, 153, 166, 0};
  char affichage[4];
  switch (c.valeur) {
    case AS: affichage[0] = 'A'; break;
    case DEUX: affichage[0] = '2'; break;
    case TROIS: affichage[0] = '3'; break;
    case QUATRE: affichage[0] = '4'; break;
    case CINQ: affichage[0] = '5'; break;
    case SIX: affichage[0] = '6'; break;
    case SEPT: affichage[0] = '7'; break;
    case HUIT: affichage[0] = '8'; break;
    case NEUF: affichage[0] = '9'; break;
    case DIX: affichage[0] = 'X'; break;
    case VALET: affichage[0] = 'V'; break;
    case DAME: affichage[0] = 'D'; break;
    case ROI: affichage[0] = 'R'; break;
    default: affichage[0] = '-';
  }
  affichage[1] = 226;
  affichage[2] = 153;
  switch (c.couleur) {
    case TREFLE: affichage[3] = 163; break;
    case CARREAU: affichage[3] = 166; break;
    case COEUR: affichage[3] = 165; break;
    case PIQUE: affichage[3] = 160; break;
    default: affichage[3] = '-';
    }
  fprintf(stdout, "%s : %d + %d = %d\n", affichage, c.valeur, c.couleur, c.valeur + c.couleur);
}

Carte creer_Carte(int valeur, int couleur) {
  Carte c = { valeur, couleur };
  return c;
}

int main(){
  Carte c1 = creer_Carte(CINQ, COEUR);
  Carte c2 = creer_Carte(CINQ, PIQUE);
  Carte c3 = creer_Carte(ROI, PIQUE);
  Carte hand1[3]={c1,c2,c3};
  Carte hand2[3]={c3,c2,c1};
  int a = estTrie(hand1,3);
  int b = estTrie(hand2,3);
    printf("--- test de la fonction plusPetit : vrai (1) car 5COEUR plus petit que 5PIQUE --- \n");
    affiche_carte(c1);
    affiche_carte(c2);
    printf("--- test de la fonction plusPetit : faux (0) car 5PIQUE plus grand que 5COEUR --- \n");
    affiche_carte(c2);
    affiche_carte(c1);
    printf("%d\n",plusPetit(c2,c1));
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

    printf("--- un autre test des fonctions versNombre versCarte combinés : les deux affichages suivants doivent etre 6+ 0 = 6 --- \n");
    struct Carte fab1 = {SIX, TREFLE};
    affiche_carte(fab1);
    affiche_carte(versCarte(versNombre(fab1)));

    printf("Creation du paquet standard 52 cartes.\n");
    Carte paquet[52];
    int i = 0;
    for (int couleur = 0; couleur <= 39; couleur +=13) {
      for (int valeur = 1; valeur <= 13; valeur++) {
	paquet[i] = creer_Carte(valeur, couleur);
	i++;
      }
    }
    for (int i = 0; i < 52; i++) {
      affiche_carte(paquet[i]);
    }
}

