#include <stdio.h>

enum couleur { rouge, vert, jaune, bleu, premier = rouge, dernier = bleu };

int main(int argc, char **argv) {
  for (enum couleur c = premier; c <= dernier; c++) {
    printf("couleur %d \n", c);
  }
  return 0;
}
	     
