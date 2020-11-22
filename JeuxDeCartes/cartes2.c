#include <stdio.h>
#include <stdlib.h>

typedef enum {AS = 1, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI} valeur_carte;
typedef enum {TREFLE=0, CARREAU=13, COEUR=26, PIQUE=39} couleur_carte;

typedef struct Carte Carte;
struct Carte {
  valeur_carte valeur;
  couleur_carte couleur;
  int rang;
};

int carte_vers_nombre(Carte c);
Carte nombre_vers_carte(int n);
Carte creer_carte_bataille(int valeur, int couleur);
void affiche_carte(Carte c);

int est_plus_petit(Carte c1, Carte c2);
int est_trie(Carte *hand, int taille);
void affiche_liste_carte(Carte liste[], int taille);

typedef struct Joueur Joueur;
struct Joueur {
  char prenom[12];
  int jeu[];
};

void tests();

int main() {

  printf("Creation du paquet standard 52 cartes pour la bataille.\n");
  Carte paquet[52];
  int i = 0;
  for (int couleur = 0; couleur <= 39; couleur +=13) {
    for (int valeur = 1; valeur <= 13; valeur++) {
      paquet[i] = creer_carte_bataille(valeur, couleur);
      i++;
    }
  }
  affiche_liste_carte(paquet, 52);

}

int carte_vers_nombre(Carte c) {
  return c.valeur + c.couleur;
}

Carte nombre_vers_carte(int n) {
  valeur_carte valeur;
  couleur_carte couleur;
  if (n<=13) {
    valeur = n;
    couleur = 0;
  }
  else {
    valeur = n%13;
    couleur = n/13 * 13;
  }
  Carte c = creer_carte_bataille(valeur, couleur);
  return c;
}

Carte creer_carte_bataille(int valeur, int couleur) {
  Carte c = { valeur, couleur };
  // a la bataille les cartes ont constamment le même rang, pas d'atout donc le rang ne change pas
  c.rang = carte_vers_nombre(c);
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
  //  fprintf(stdout, "%s : %d + %d = %d", affichage, c.valeur, c.couleur, c.valeur + c.couleur);
  fprintf(stdout, "%s (%d) ", affichage, c.rang);
  //  fprintf(stdout, "%s ", affichage);
}

int est_plus_petit(Carte c1, Carte c2) {
  int resultat = 0; //0 si c1 > c2, 1 si c1 < c2
  if (c1.valeur < c2.valeur) {
    resultat = 1;
  }
  if (c1.valeur == c2.valeur && c1.couleur < c2.couleur) {
    resultat = 1;
  }
  return resultat;
}

int est_trie(Carte *hand, int taille) {
  int resultat = 1; //1 triée, 0 sinon
  for (int i = 0; i<taille; i++) {
    Carte c1 = *(hand+i);
    Carte c2 = *(hand+1+i);
    if((est_plus_petit(c1,c2))==0) {
      resultat = 0;
    }
  }
  return resultat;
}

void affiche_liste_carte(Carte liste[], int taille) {
  for (int i=0; i < taille; i++) {
    affiche_carte(liste[i]);
    printf("\n");
  }
  printf("\n");
}


void tests() {
  Carte c1 = creer_carte_bataille(CINQ, COEUR);
  Carte c2 = creer_carte_bataille(CINQ, PIQUE);
  Carte c3 = creer_carte_bataille(ROI, PIQUE);
  Carte hand1[3]={c1,c2,c3};
  Carte hand2[3]={c3,c2,c1};
  int a = est_trie(hand1,3);
  int b = est_trie(hand2,3);
  printf("--- test de la fonction plusPetit : vrai (1) car 5COEUR plus petit que 5PIQUE --- \n");
  affiche_carte(c1);
  printf("\n");
  affiche_carte(c2);
  printf("\n");
  printf("--- test de la fonction plusPetit : faux (0) car 5PIQUE plus grand que 5COEUR --- \n");
  affiche_carte(c2);
  printf("\n");
  affiche_carte(c1);
  printf("\n");
  printf("%d\n",est_plus_petit(c2,c1));
  printf("--- test de la fonction estTrie --- \n");
  printf("%d\n",a);
  printf("%d\n",b);
  printf("--- test de la fonction versNombre --- \n");
  printf("%d\n",carte_vers_nombre(c1));
  printf("%d\n",carte_vers_nombre(c3));
  printf("--- test de la fonction versCarte --- \n");
  struct Carte c4 = nombre_vers_carte(13);
  struct Carte c5 = nombre_vers_carte(51);
  printf("%d\n",c4.valeur);
  printf("%d\n",c4.couleur);
  printf("%d\n",c5.valeur);
  printf("%d\n",c5.couleur);

  printf("--- un autre test des fonctions carte_vers_nombre & nombre_vers_carte combinés : les deux affichages suivants doivent etre 6+ 0 = 6 --- \n");
  struct Carte fab1 = creer_carte_bataille(SIX, TREFLE);
  affiche_carte(fab1);
  printf("\n");
  affiche_carte(nombre_vers_carte(carte_vers_nombre(fab1)));
  printf("\n");
}
