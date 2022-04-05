#include <stdio.h>

FILE *fichier_source;
FILE *fichier_resultat;




void initialise(int argc, char *argv[]);

FILE *ouvre_fichier_lecture(char *argument);

FILE *ouvre_fichier_ecriture(char *argument);