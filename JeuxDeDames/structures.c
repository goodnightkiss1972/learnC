/**
 * 
 * Fichiers contenant toutes les enum et struct pour le jeu
 * 
 * NE PAS MODIFIER
 * 
 */ 

/* la structure representant les valeurs possibles des cases du plateau 
 * VIDE si aucune piexe n'occupe la case
 * les noms PB,PN,DB,DN correpondent respectivement a pion blanc, pion noir, dame blanche, dame noire
 * les versions avec un C sont pour les pieces qui sont capturées et seront utiles quand on cherchera a modeliser les sequences de prise
 * remarquez que la version capturée d'une piece a toujours une valeur negative egale a l'opposée de la version non capturée
 */
typedef enum caseVal{
	DNC=-4,DBC,PNC,PBC,VIDE,PB,PN,DB,DN
}caseVal;

/* un type enumere pour les couleurs qui servira pour les pieces et pour les joueurs
 * la valeur NOCOL qui sera utile pour les fonctions qui devront retourner la couleur de la piece occupant une case donnée : si la case est vide, on retournera NOCOL
 */
typedef enum couleur{
	NOIR,NOCOL,BLANC
}couleur;

/* idem que couleur mais pour le type des pieces */
typedef enum typePiece{
	NOTYPE,Pion,Dame
}typePiece;

/* alias de enum pour différencier joueur humain et controlé par la machine */
typedef enum typeJoueur{
	Humain,
	CPU
}typeJoueur;

/* alias de structure pour représenter un joueur */
typedef struct joueur{
	char *nom;
	typeJoueur type; //0 pour humain, 1 pour machine
	couleur coul;
} joueur;

/* alias de structure centrale du jeu qui contient toute la configuration d'une partie en cours */
typedef struct jeu{
	int NB_Lig;
	int NB_Col;
	int NB_LigInit;
	caseVal* plateau;
	int jCourant;
	joueur tabJ[2];
}jeu;

/* alias de structure utile pour simplifier l'ecriture du code et qui modelise une position du plateau */
typedef struct position{
	int lig,col;
}position;

/* etape de mouvement : a comprendre comme les noeuds d'une liste chainee */
typedef struct etape{
	position pos;
	struct etape* next;	
}etape;

/* alias de structure pour representer les mouvements
 * un pointeur vers l'etape de depart
 * un pointeur vers l'etape d'arrivée
 * un entier pour le score du mouvement (0 si pas de prise, n si mouvement de capture de n pieces adverses)
*/
typedef struct move{
	etape* first;
	etape* last;
	int score;
}move;


