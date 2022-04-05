#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calc_unbounded_int_lib.h"

/* https://yard.onl/sitelycee/cours/c/Ouvriretfermerunfichier.html */

void initialise(int argc, char *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("   argv[%d] : '%s'\n", i, argv[i]);
    }
    if (argc == 1) /* aucun parametre recu : on va utiliser stdin et stdout */
    {
        printf("aucun parametre recu : on va utiliser stdin et stdout.\n");
        return;
    }
    if (argc == 2 || argc == 4 || argc > 5) /* mauvaise liste de parametre, fin du programme */
    {
        printf("mauvaise liste de parametre, fin du programme.\n");
        return;
    }
    if (argc == 3 || argc == 5)
    {
        if (strcmp(argv[3-2], "-i") == 0) {
            printf("Source   == %s\n", argv[3-1]);
            fichier_source = ouvre_fichier_lecture(argv[3-1]);
        }
        if (strcmp(argv[3-2], "-o") == 0) {
            printf("Resultat == %s\n", argv[3-1]);
            fichier_resultat = ouvre_fichier_ecriture(argv[3-1]);
        }
    }
    if (argc == 5)
    {
        if (strcmp(argv[5-2], "-i") == 0) {
            printf("Source   == %s\n", argv[5-1]);
            fichier_source = ouvre_fichier_lecture(argv[5-1]);
        }
        if (strcmp(argv[5-2], "-o") == 0) {
            printf("Resultat == %s\n", argv[5-1]);
            fichier_resultat = ouvre_fichier_ecriture(argv[5-1]);
        }
    }
}

FILE *ouvre_fichier_lecture(char *argument) {
    FILE *fichier = fopen(argument, "r");
    if (fichier != NULL) {
        printf("OK     : tout va bien on a trouve le fichier %s \n", argument);
    }
    else {
        printf("ERREUR : impossible d'ouvrir le fichier %s\n", argument);
        exit(1);
    }
    return fichier; 
}

FILE *ouvre_fichier_ecriture(char *argument) {
    FILE *fichier = fopen(argument, "w");
    if (fichier != NULL) {
        printf("OK     : tout va bien on a trouve le fichier %s \n", argument);
    }
    else {
        printf("ERREUR : impossible d'ouvrir le fichier %s\n", argument);
        exit(1);
    }
    return fichier; 
}