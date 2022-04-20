#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "unbounded_int.h"
#include "calc_unbounded_int_lib.h"

/* https://yard.onl/sitelycee/cours/c/Ouvriretfermerunfichier.html */

int main(int argc, char *argv[])
{
    /* affichage des parametres passes au programme */
    initialise(argc, argv);


    fclose(fichier_source);
    fclose(fichier_resultat);
    return 0;
}

