/**
 * L'executable du programme
 * C'est le seul fichier à compiler avec gcc main.c
 * Voir sujet pour plus d'explications.
 **/ 

#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "colors.c"
#include "structures.c"
#include "gameplay.c"
#include "affichage.c"
#include "interfaceJeu.c"
#include "tests.c"


/* test la conformité du plateau dynamiquement avec 1 si tout est bon, 0 si une erreur */
int test_plateau(jeu* g, int nl, int nc, int nli){
	/* teste les blancs */
	int i,j;
	for (i = 0 ; i < nli ; i++){
		if (i%2 == 0){
			j = 0;
		}
		else{
			j = 1;
		}
		for (j ; j < nc ; j+=2){
			position p = {i,j};
			if (getCouleur(g, p) != BLANC) {
				return 0;
			}
		}
	}
	/* il faut completer avec un test sur les noirs et les vides */
	return 1;
}

/* teste la couleur et le type a la position donnee */
int test_case(jeu* g, position p, typePiece t, couleur c){
//	printf("type : %d\n", t);
//	printf("couleur : %d\n", c);
	if (getCouleur(g, p) == c && getTypePiece(g, p) == t) {
		//printf("OK a la position (%d %d) nous avons bien un(e) %d de couleur %d.\n", p.lig, p.col, getTypePiece(g, p), getCouleur(g, p));
		return 1;
	}
	else
	{
		printf("** ERREUR ** a la position (%d %d) nous avons un(e) %d de couleur %d.\n", p.lig, p.col, getTypePiece(g, p), getCouleur(g, p));
		return 0;
	}
}

/* un prog pour voir l'affichage d'un plateau avec les fonctions deja fournies 
 * Vous pouvez le tester de suite en compilant puis executant ce main
 * */
void tests_S0(){
	jeu *g =calloc(1,sizeof(jeu));
	//initBlank(g,12,12);
	init(g,10,10,4);

	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g); //afiche le damier de g dans le terminal
	sleepcp(500);		// temporise pendant 500millisecondes

	setCaseVal(g,(position){1,1},PN); // ajout d'un pion noir	
	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g);
	sleepcp(500);
	
	setCaseVal(g,(position){8,8},DB); // ajout d'une dame blanche	
	resetTerm();
	print_damier(g);
	sleepcp(500);
	
	setCaseVal(g,(position){3,3},DNC); // ajout d'une dame noir capturee
	resetTerm();
	print_damier(g);
	
	position p;
	p.lig = 1;
	p.col = 3;
	test_case(g, p, Pion, BLANC);
	p.lig = 2;
	p.col = 1;
	test_case(g, p, NOTYPE, NOCOL);
	p.lig = 8;
	p.col = 8;
	test_case(g, p, Dame, BLANC);
	//printf("test 10/10/4 doit etre egal a 1 : %d\n", test_plateau(g,10,10,4)); // plus valable car on a boulverse la grille


	free(g->plateau); // pour eviter les fuites de memoire on libere g et son plateau
	free(g);
}

/* un prog de test utilisant des fonctions du fichier tests.c pour la fin de la Semaine1 */
void tests_S1(){
	test_doDeplace();
	test_doMange();
	test_isValide();
	test_undoCapture();	
	test_isMoveElemPion();

}

int main(){
/* POUR WINDOWS NE PAS EFFACER 
 */
	configWindowsConsole();
/********************************/

	tests_S0();
	//tests_S1(); // a decommenter pour lancer les tests S1
}


