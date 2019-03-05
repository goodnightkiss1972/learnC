#include <stdio.h>
#include <cartesien.h>

int main()
{
    // Affiche la distance de deux points en utilisant la librairie maison.
    pt A = {0, 0};
    pt B = {3, 1};
    printf("La distance est de %4.2f\n", distance2pt(A, B));

    // Recherche de l'equation cartesienne d'une droite passant par deux points
    // la fonction va aussi retourner un vecteur directeur de cette droite.
    droite dAB;
    vecteur vAB;
    droite2pt(A, B, &dAB, &vAB); // Cette fonction va retourner deux structures
    printf("(1) L'equation de la droite (AB): (%4.2f)X + (%4.2f)Y + (%4.2f) = 0\n", dAB.a, dAB.b, dAB.c);
    printf("(2) Un vecteur directeur de la droite (AB) : (%4.2f)i + (%4.2f)j\n", vAB.i, vAB.j);
    droite dAB2;
    droite1ptVecteur(A, vAB, &dAB2); // on va verifier cette fonction avec les resultats precedents
    printf("(3) L'equation de la droite (AB): (%4.2f)X + (%4.2f)Y + (%4.2f) = 0\n", dAB2.a, dAB2.b, dAB2.c);

    // On cherche a verifier si le vecteur AB est perpendiculaire a un autre
    vecteur vCD = {-1, 3};
    printf("(4) Un autre vecteur (CD) : (%4.2f)i + (%4.2f)j\n", vCD.i, vCD.j);
    double cosABCD;
    printf("Produit scalaire de AB et CD : %4.2f\n", produitScalaire(vAB, vCD, &cosABCD));
    printf("Le cosinus de l'angle entre AB et CD : %4.2f\n", cosABCD);
}
