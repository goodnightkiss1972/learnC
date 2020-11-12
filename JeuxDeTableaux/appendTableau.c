#include <stdio.h>
#include <stdlib.h>

#define NB_ELEM 4

bool depart[NB_ELEM] = { FALSE, TRUE, TRUE, FALSE };

void afficheTableauInt(int tableau[], int taille);
bool *codageGray(bool b[], int taille);
bool *decodageGray(bool g[], int taille, bool b[]);

int main()
{
  afficheTableauBool(depart, NB_ELEM);

  bool *gray = codageGray(depart, NB_ELEM);
  afficheTableauBool(gray, NB_ELEM);

  
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

bool *codageGray(bool b[], int taille) {
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

