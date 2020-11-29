/**
 * Fichier contenant les fonctions faisant se derouler le jeu dans le terminal
 * (a l'exception des fonctions auxiliaires d'affichage pur qui sont dans affichage.c
 * A faire en S3
 */
 


/*
 * Fonction permettant de choisir les infos des joueurs
 * S3  : pour deux joueurs humains
 * S4  : pour CPU ou Humain?
 * 
 * Attention faire malloc pour les noms!!
 */
void saisieJoueurs(jeu *g);

/*
 * Fonction proposant de saisir une taille de plateau
 * S3
 */
void saisiePlateau(jeu *g);

/*
 * saisit une sequence d'etapes tapées au clavier sous la forme d'une suite d'entiers de tailles paire
 * 		par exemple 3 3 4 4 pour déplacer un pion de la position (3,3) à la position voisine (4,4)
 * 		on peut aussi ecrire des sequences plus longues pour les rafles : 3 3 5 5 7 3 qui correspond à (3,3)->(5,5)->(7,3)
 * 
 * 
 * Cette fonction verifie juste que le nmobre d'entiers tapé est bien pair (2 entiers par position)
 * mais pas que le move est un move autorisé ou correct
 *  
 * Si tout va bien elle ajoute une a une ces etapes (avec la fonction ajouteEtape) a la suite du move dont l'adresse est passée en 2nd argument et retourne 1
 * 
 * sinon elle retoune 0
 * 
 * A FAIRE EN S3
 * 
 */
int saisieMov(jeu* g, move* m){
	//A ECRIRE S3
	return -1;
}

/*
 * Fonction faisant se dérouler le tour du joueur Courant
 * S3 : joueur humain
 * S4 : joueur humain ou CPU
 * retourne 1 si le tour s'est passé normalement
 * retourne 0 si le joueur courant n'avait plus de coup a jouer
 * 
 * en gros dans une version basique:
 * 		saisieMov
 * 		test si move valide et affichage du move si oui
 * 		mise a jour avec pieces capturees suprrimées
 * 		jCourant=1-jCourant
 * 
 * pour faire mieux :
 * 	 saisieMov doit se repeter tant que le joueur tape un move incorrect
 * 	 implémenter la regle qui dit qu'on doit toujours joue le meilleur coup possible
 * 	 gerer le cas d'un joueur CPU
 * 
 */	
int joueTour(jeu*g){
	//A ECRIRE S3
	return -1;
}

/*
 * Fonction faisant se dérouler le jeu *g du début à la fin
 * en gros :
 * 		tant que le jeu n'est pas fini
 * 			joueTour(g)
 * 		affiche gagnant			
 * 	
 */
void playGame(jeu* g);

/* 
 * launchGame : 
 * la fonction appelée par le main pour lancer le jeu 
 * propose un menu de choix avant de lancer playGame
 * puis retour au menu en fin de partie
 * 
 * En gros : 
 * 		tant que le joueur ne quitte pas le jeu
 * 			affiche menu choix
 * 			saisieJoueurs
 * 			saisiePlateau
 * 			creation jeu g
 * 			playGame(g)
 * 			libere g
 * 	
 * */
void launchGame(){
	//A ECRIRE S3
}
