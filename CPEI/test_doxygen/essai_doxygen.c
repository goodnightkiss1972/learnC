/**
 * @file essai_doxygen.c
 * @author fabien c (goodnightkiss1972@gmail.com)
 * @brief a priori le premier bloc de commentaire est tres important pour la documentation
 * il faut donc le generer sinon il n'y a pas grand chose qui sera produit.
 * @version 0.1
 * @date 2019-03-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <stdio.h>

/**
 * @brief Cette fonction permet l'affichage d'un tableau entre crochets dans la sortie standard.
 * Elle est suffisamment utilisee pour etre mise dans une librairie si besoin.
 * 
 * @param tableau designe le tableau a afficher a l'ecran
 * @param taille est la taille du tableau (le professeur ne veut pas de sizeof dans le code)
 * @return int retourne 1 si le tableau peut etre affiche, sinon 0 en cas d'erreur
 */
int affiche_tableau(int tableau[], int taille);

int main()
{
    /**
     * @brief montableau sert pour la demonstration de la fonction
     * 
     */
    int montableau[6] = {2, 3, 6, 12, 4, 7};
    /**
     * @brief exemple d'appel
     * 
     */
    affiche_tableau(montableau, 6);
}

int affiche_tableau(int tableau[], int taille)
{
    /**
     * @brief si la taille n'est pas un entier positif alors la fonction s'arrete.
     * On affiche egalement un message d'erreur.
     */
    if (taille < 1)
    {
        printf("ERREUR: la taille du tableau doit etre superieure a 1.");
        return 0;
    }
    /**
     * @brief Debut de l'affichage avec le premier crochet.
     * 
     */
    printf("[ ");
    /**
     * @brief On boucle entre 0 et taille pour afficher les elements
     * 
     */
    for (int i = 0; i < taille; i++)
    {
        /**
         * @brief Si on se trouve a la derniere position on affiche pas de virgule de separation
         * 
         */
        if (i == taille -1) {
            printf("%d ", tableau[i]);
        }
        else
        {
            printf("%d, ", tableau[i]);
        }
    }
    /**
     * @brief On referme les crochets et on retourne 1 pour le succes.
     * 
     */
    printf("]\n");
    return 1;
}