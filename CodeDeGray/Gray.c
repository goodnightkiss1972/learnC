#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    FALSE,
    TRUE
} bool;

#define NB_ELEM 4

bool depart[NB_ELEM] = { FALSE, TRUE, TRUE, FALSE };

void afficheTableauBool(bool b[], int taille);
bool XOR(bool a, bool b);
bool *codageGray(bool b[], int taille);
bool *decodageGray(bool g[], int taille, bool b[]);

int main()
{
  afficheTableauBool(depart, NB_ELEM);

  // premiere technique
  bool *gray = codageGray(depart, NB_ELEM);
  afficheTableauBool(gray, NB_ELEM);

  // deuxième technique
  bool *binaire = NULL;
  binaire = malloc(NB_ELEM * sizeof(bool));
  if (NULL == binaire) {
    perror("Erreur lors du malloc");
    exit(-1);
  }
  decodageGray(gray, NB_ELEM, binaire);
  afficheTableauBool(binaire, NB_ELEM);
  
  free(gray);
  free(binaire);
}

void afficheTableauBool(bool b[], int taille) {
  printf("[ ");
  int i;
  for (i = 0; i < taille; i++) {
    if (b[i] == TRUE) {
      printf("1 ");
    }
    else {
      printf("0 ");
    }
    if (i != taille -1) {
      printf(",");
    }
  }
  printf("]\n");
}

bool XOR(bool a, bool b) {
  if (a == FALSE && b == FALSE) {
      return FALSE;
  }
  if (a == FALSE && b == TRUE) {
      return TRUE;
  }
  if (a == TRUE && b == FALSE) {
      return TRUE;
  }
  if (a == TRUE && b == TRUE) {
      return FALSE;
  }
}

bool *codageGray(bool b[], int taille) {
  // premiere technique on alloue dynamiquement le tableau ce qui permettra de le retourner
  // car la mémoire ainsi allouée n'est pas perdue en sortie de la fonction.
  bool *g = NULL;
  g = malloc(NB_ELEM * sizeof(bool));
  if (NULL == g) {
    perror("Erreur lors du malloc");
    exit(-1);
  }
  g[0] = b[0];
  int i = 1;
  while (i < taille) {
    g[i] = XOR(b[i], b[i-1]);
    i++;
  }
  return g;
}

bool *decodageGray(bool g[], int taille, bool b[]) {
  // deuxième technique on a passé le retour souhaité en paramètre
  // cela nécessite de l'avoir créé au préalable dans l'appelant
  b[0] = g[0];
  int i = 1;
  while (i < taille) {
    b[i] = XOR(g[i], b[i-1]);
    i++;
  }
  return b;
}
