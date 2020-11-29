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


/* un prog pour voir l'affichage d'un plateau avec les fonctions deja fournies 
 * Vous pouvez le tester de suite en compilant puis executant ce main
 * */
void tests_S0(){
	jeu *g =calloc(1,sizeof(jeu));
	initBlank(g,12,12);
	
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
	
	free(g->plateau); // pour eviter els fuites de memoire on libere g et son plateau
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


