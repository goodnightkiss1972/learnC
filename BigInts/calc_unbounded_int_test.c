#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "unbounded_int.h"
#include "calc_unbounded_int_lib.h"

#define DEBUGAGE false

void compare_fichier_modele(char *a_tester, char *modele, bool resultat_attendu);
void test_calc_unbounded_int_non_regression(char *a_tester, bool resultat_attendu);

int main()
{
    printf("\n");
    printf("****************\n");
    printf("* Compare file *\n");
    printf("****************\n");

    compare_fichier_modele("test/test01_unitaires/01_vide.txt",          "test/test01_unitaires/modele_vide.txt", true);
    compare_fichier_modele("test/test01_unitaires/01_vide.txt",          "test/test01_unitaires/02_1234567890.txt", false);
    compare_fichier_modele("test/test01_unitaires/02_1234567890.txt",    "test/test01_unitaires/modele_vide.txt", false);

    compare_fichier_modele("test/test01_unitaires/02_1234567890.txt",    "test/test01_unitaires/02_1234567890_identique.txt", true);
    compare_fichier_modele("test/test01_unitaires/02_1234567890.txt",    "test/test01_unitaires/03_2234567890.txt", false);
    compare_fichier_modele("test/test01_unitaires/02_1234567890.txt",    "test/test01_unitaires/04_1034567890.txt", false);
    compare_fichier_modele("test/test01_unitaires/02_1234567890.txt",    "test/test01_unitaires/05_1234567899.txt", false);
    compare_fichier_modele("test/test01_unitaires/02_1234567890.txt",    "test/test01_unitaires/06_12345678900.txt", false);

    compare_fichier_modele("test/test01_unitaires/07_ab_1234567890.txt",    "test/test01_unitaires/07_ab_1234567890_identique.txt", true);
    compare_fichier_modele("test/test01_unitaires/07_ab_1234567890.txt",    "test/test01_unitaires/08_ab_1234567890_2234567890.txt", false);

    printf("*******************\n");
    printf("* Compare file OK *\n");
    printf("*******************\n");

    printf("\n");
    printf("******************\n");
    printf("* Non regression *\n");
    printf("******************\n");

    test_calc_unbounded_int_non_regression("test/test02_nonregression/nr_test01", true);

    printf("*********************\n");
    printf("* Non regression OK *\n");
    printf("*********************\n");
    return 0;
}

void compare_fichier_modele(char *a_tester, char *modele, bool resultat_attendu)
{
    bool resultat = true; /* on part du principe que la comparaison est vraie et on cherche si quelque chose invalide cela */
    FILE *fichier_a_tester = ouvre_fichier_lecture(a_tester);
    FILE *fichier_modele = ouvre_fichier_lecture(modele);
    char t, m;
    int position = 0;

    while (true) /* comparaison caractere a caractere */
    {
        t = fgetc(fichier_a_tester);
        m = fgetc(fichier_modele);
        if (t == EOF && m == EOF) break;
        if (t != m)
        {
            //printf("       compare_fichier_modele : Difference a la position %d : %c different du modele (%c)\n", position, t, m);
            resultat = false;
            break;
        }
        position++;
    }

    assert(resultat == resultat_attendu);
    printf("OK     compare_fichier_modele sur fichiers %s et %s\n", a_tester, modele);
}

void test_calc_unbounded_int_non_regression(char *a_tester, bool resultat_attendu) {
    //printf("./calc_unbounded_int_test -i %s_input.txt -o %s_resultat.txt\n", a_tester, a_tester);
    char *fichier_input;
    fichier_input = malloc(sizeof(*fichier_input)*50);
    sprintf(fichier_input, "%s_input.txt", a_tester);

    char *fichier_resultat;
    fichier_resultat = malloc(sizeof(*fichier_resultat)*50);
    sprintf(fichier_resultat, "%s_resultat.txt", a_tester);

    char *fichier_modele;
    fichier_modele = malloc(sizeof(*fichier_modele)*50);
    sprintf(fichier_modele, "%s_modele.txt", a_tester);

    char *chaine_lancement;
    chaine_lancement = malloc(sizeof(*chaine_lancement)*250);
    sprintf(chaine_lancement, "./calc_unbounded_int -i %s -o %s", fichier_input, fichier_resultat);
//    printf(chaine_lancement);
//    printf("\n");
    int lancement;
    lancement = system(chaine_lancement);

    compare_fichier_modele(fichier_resultat, fichier_modele, true);
}