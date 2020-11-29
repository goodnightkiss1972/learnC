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
int test_case(jeu* g, position p, typePiece t, couleur c, int capture){
	if (getCouleur(g, p) == c && getTypePiece(g, p) == t && isCapture(g, p) == capture) {
		//printf("OK a la position (%d %d) nous avons bien un(e) %d de couleur %d.\n", p.lig, p.col, getTypePiece(g, p), getCouleur(g, p));
		return 1;
	}
	else
	{
		printf("** ERREUR ** a la position (%d %d) nous avons un(e) %d de couleur %d et capturee : %d\n", p.lig, p.col, getTypePiece(g, p), getCouleur(g, p), isCapture(g, p));
		return 0;
	}
}

/* teste la validite d'une position par rapport au jeu */
int test_valide(jeu* g,position p, int attendu) {
	if (isValide(g, p) == attendu) {
		return 1;
	}
	else
	{
		printf("** ERREUR ** Cette position (%d %d) n'a pas le bon isValide pour le jeu.\n", p.lig, p.col);
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
	
	/* normalement il faudrait ecrire un test specifique pour getCouleur, getTypePiece et isCapture
	mais ici on fait les trois a la fois dans test_case */
	test_case(g, (position){1,3}, Pion, BLANC, 0);
	test_case(g, (position){2,1}, NOTYPE, NOCOL, 0);
	test_case(g, (position){8,8}, Dame, BLANC, 0);
	test_case(g, (position){3,3}, Dame, NOIR, 1);

	/* test validite */
	test_valide(g,(position){1,-1},0);
	test_valide(g,(position){-1,1},0);
	test_valide(g,(position){0,0},1);
	test_valide(g,(position){9,9},1);
	test_valide(g,(position){12,5},0);
	test_valide(g,(position){6,11},0);

	//printf("test 10/10/4 doit etre egal a 1 : %d\n", test_plateau(g,10,10,4)); // plus valable car on a boulverse la grille

	/* changeons le statut de capture et constatons l'effet graphiquement */
	switchCapture(g, (position){3,3});
	resetTerm();
	print_damier(g);
	sleepcp(500);
	switchCapture(g, (position){8,8});
	resetTerm();
	print_damier(g);
	sleepcp(500);

	/* promotion noir */
	setCaseVal(g,(position){0,8},PN); // ajout d'un pion noir	
	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g);
	sleepcp(1500);
	promotion(g);
	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g);
	sleepcp(500);

	/* promotion blanc */
	setCaseVal(g,(position){9,9},PB); // ajout d'un pion blanc
	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g);
	sleepcp(1500);
	promotion(g);
	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g);
	sleepcp(500);

	/* mouvement simule */
	doDeplace(g, (position){3,1}, (position){4,0});
	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g);
	sleepcp(1500);

	/* prise simulee */
	setCaseVal(g,(position){4,6},PN); // ajout d'un pion noir
	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g);
	sleepcp(1500);
	doMange(g, (position){3,5}, (position){5,7}, (position){4,6});
	resetTerm(); //permet de reinitialiser l'affichage du terminal
	print_damier(g);
	sleepcp(1500);


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


