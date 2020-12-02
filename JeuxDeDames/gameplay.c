/**
 * Le fichier contenant toutes les fonctions de modelisation du jeu
 * Les 4 premieres sont deja données, les autres sont à écrire.
 */


/* retourne le joueur courant de *g*/
joueur getJoueurCourant(jeu*g){
	return g->tabJ[g->jCourant];
}

/* retourne la valeur (dans l'enum caseVal) de la position p dans le jeu g **/
caseVal getCaseVal(jeu* g, position p){
	return g->plateau[p.lig*g->NB_Col+p.col];
}

/* fonction permettant de changer la valeur de la position p du jeu *g en lui donnant la valeur s **/
void setCaseVal(jeu* g, position p, caseVal s){
	g->plateau[p.lig*g->NB_Col+p.col]=s;
}

/* fonction pour initialiser le plateau de *g a un plateau vide de dimensions nl lignes et nc colonnes 
 * si on l'utilise une seconde fois pour changer la taille du plateau, ne pas oublier de faire free de g->plateau avant 
 * */
void initBlank(jeu *g, int nl, int nc) {
    g->NB_Col = nc;
    g->NB_Lig = nl;
    g->plateau = calloc(1,g->NB_Lig * g->NB_Col * sizeof (int));
    g->jCourant = 0;
}

/* fonction pour initialiser le plateau de *g a un plateau 
 * de dimensions nl lignes et nc colonnes
 * avec des pieces blanches sur les nli premieres lignes aux cases prevues par les regles
 * avec des pieces noires sur les nli dernieres lignes aux cases prevues par les regles
 *
 * on peut utiliser initBlank pour commencer et ensuite on se sert de setCaseVal
 */
void init(jeu* g, int nl, int nc, int nli){
	initBlank(g,nl,nc);
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
			setCaseVal(g,p,PB);
		}
	}
	for (i = (nl - nli) ; i < nl ; i++){
		if (i%2 == 0){
			j = 0;
		}
		else{
			j = 1;
		}
		for (j ; j < nc ; j+=2){
			position p = {i,j};
			setCaseVal(g,p,PN);
		}
	}
}

/* retourne 1 si les deux positions p et q ont les memes coordonnées et 0 sinon */
int equals(position p,position q){
	if (p.lig == q.lig && p.col == q.col){
		return 1;
	}
	else
	{
		return 0;
	}
}

/* retourne 1 si la position est bien dans le damier du jeu g et 0 sinon */
int isValide(jeu* g,position p){
	if (p.lig >= 0 && p.lig < g->NB_Lig && p.col >= 0 && p.col < g->NB_Col) {
		return 1;
	}
	else
	{
		return 0;
	}
}

/* retourne 1 si la position p est vide dans le damier du jeu g et 0 sinon
 * (par rapport aux dimensions NB_Lig et NB_Col du plateau)
 * */
int isVide(jeu* g, position p){
	/* les break sont inutile vu qu'on retourne dans les case... */
	switch (getCaseVal(g, p)) {
		//DNC=-4,DBC,PNC,PBC,VIDE,PB,PN,DB,DN
		case VIDE : return 1; break;
		default : return 0; break;
	}
}

/* retourne la couleur (du type enuméré couleur) de la position p dans le jeu *g 
 * (NOCOL si la case est Vide)
 * */
couleur getCouleur(jeu* g, position p){
	/* les break sont inutile vu qu'on retourne dans les case... */
	switch (getCaseVal(g, p)) {
		//DNC=-4,DBC,PNC,PBC,VIDE,PB,PN,DB,DN
		case DNC : case PNC : case PN : case DN : return NOIR; break;
		case DBC : case PBC : case PB : case DB : return BLANC; break;
		case VIDE : return NOCOL; break;
	}
}

/* retourne le type de piece de la position p dans le jeu *g 
 * (NOTYPE si la case est Vide)
 * */
typePiece getTypePiece(jeu* g, position p){
	/* les break sont inutile vu qu'on retourne dans les case... */
	switch (getCaseVal(g, p)) {
		//DNC=-4,DBC,PNC,PBC,VIDE,PB,PN,DB,DN
		case DNC : case DBC : case DN : case DB : return Dame; break;
		case PNC : case PBC : case PN : case PB : return Pion; break;
		case VIDE : return NOTYPE; break;
	}
}

/* retourne 1 si la position p dans *g est une piece capturee (voir type caseVal) et 0 sinon */
int isCapture(jeu* g, position p){
	/* les break sont inutile vu qu'on retourne dans les case... */
	switch (getCaseVal(g, p)) {
		//DNC=-4,DBC,PNC,PBC,VIDE,PB,PN,DB,DN
		case DNC : case DBC : case PNC : case PBC : return 1; break;
		default : return 0; break;
	}
}

/* permet de switcher la valeur d'une position p de capturée à non capturée et vice versa */
void switchCapture(jeu* g, position p){
	/* ici sans les break on prend un gros risque :-) ils sont indispensables */
	switch (getCaseVal(g, p)) {
		//DNC=-4,DBC,PNC,PBC,VIDE,PB,PN,DB,DN
		case DNC : setCaseVal(g, p, DN); break;
		case DBC : setCaseVal(g, p, DB); break;
		case PNC : setCaseVal(g, p, PN); break;
		case PBC : setCaseVal(g, p, PB); break;
		case VIDE : setCaseVal(g, p, VIDE); break;
		case PB : setCaseVal(g, p, PBC); break;
		case PN : setCaseVal(g, p, PNC); break;
		case DB : setCaseVal(g, p, DBC); break;
		case DN : setCaseVal(g, p, DNC); break;
	}
}

/* transforme en dames tous les pions qui sont arrives sur la rangee du fond adverse
 * retourne le nombre de pions ainsi promus
 */
int promotion(jeu*g){
	int i = 0, j = 0;
	position p;
	int promus = 0;
	int decalage = 0;
	/* ligne 0 (BLANC) si un PN alors on le transforme en DN */
	/* la ligne 0 etant paire on va avancer en suivant 0 2 4 etc */
	for (i = 0; i < g->NB_Col; i+=2) {
		p.lig = 0;
		p.col = i;
		if (getCaseVal(g,p) == PN) {
			setCaseVal(g,p,DN);
			promus++;
		}
	}
	/* ligne NB_Lig-1 (NOIR) si un PB alors on le transforme en DB */
	if (g->NB_Lig % 2 == 0) {
		decalage++;
	}
	for (j = 0; j < g->NB_Col; j+=2) {
		p.lig = g->NB_Lig-1;
		p.col = j+decalage;
		if (getCaseVal(g,p) == PB) {
			setCaseVal(g,p,DB);
			promus++;
		}
	}
	return promus;
}

/*
 * effectue le deplacement de la piece de p vers qu
 * en supposant que c'est bien un deplacement valide (sans verification)
 */
void doDeplace(jeu*g, position deb, position fin){	
	setCaseVal(g, fin, getCaseVal(g, deb));
	setCaseVal(g, deb, VIDE);
}

/*
 * effectue un mouvement de la piece p vers en capturant la piece en position prise
 * en supposant que c'est bien une prise valide (sans aucune verification)
 */
void doMange(jeu*g, position p, position q, position prise){
	doDeplace(g,p,q);
	switchCapture(g,prise);
}


/* annule la capture de toutes les pieces capturees du plateau */
void undoCapture(jeu*g) {
	position p;
	for (int i = 0; i < g->NB_Lig; i++){
		for (int j = 0; j < g->NB_Col; j++){
			p.lig = i;
			p.col = j;
			switch (getCaseVal(g, p)) {
				//DNC=-4,DBC,PNC,PBC,VIDE,PB,PN,DB,DN
				case DNC : setCaseVal(g, p, DN); break;
				case DBC : setCaseVal(g, p, DB); break;
				case PNC : setCaseVal(g, p, PN); break;
				case PBC : setCaseVal(g, p, PB); break;
			}
		}
	}
}

/* supprime du plateau toutes les pièces capturées */
void removeCapture(jeu*g) {
	position p;
	for (int i = 0; i < g->NB_Lig; i++){
		for (int j = 0; j < g->NB_Col; j++){
			p.lig = i;
			p.col = j;
			switch (getCaseVal(g, p)) {
				//DNC=-4,DBC,PNC,PBC,VIDE,PB,PN,DB,DN
				case DNC : case DBC : case PNC : case PBC : setCaseVal(g, p, VIDE); break;
			}
		}
	}
}

/* retourne la position Voisine de p en avancant dans la direction donnee par dirlig dircol */
position posVoisine(position p, int dirlig, int dircol){
	/* hypotheses : on cherche le mouvement "juste" voisin (le plus proche) dans la direction indiquee */
	/* si il n'y en a pas on renverra la position invalide -1, -1                                      */

	/* traitement des cas particuliers des bordures ou des directions egales a la position             */
	/* ou encore des directions invalides															   */
	if ((dirlig == p.lig) || (dircol == p.col) || (dirlig < 0) || (dircol < 0) || (((dirlig + dircol) % 2) != 0)) {
		return (position){-1,-1};
	}
	/* en haut a droite */
	if ((dirlig > p.lig) && (dircol > p.col)) {
		return (position){p.lig+1,p.col+1};
	}
	/* en haut a gauche */
	if ((dirlig > p.lig) && (dircol < p.col)) {
		return (position){p.lig+1,p.col-1};
	}
	/* en bas a droite */
	if ((dirlig < p.lig) && (dircol > p.col)) {
		return (position){p.lig-1,p.col+1};
	}
	/* en bas a gauche */
	if ((dirlig < p.lig) && (dircol < p.col)) {
		return (position){p.lig-1,p.col-1};
	}
	return (position){-1,-1};
}

/* retourne 1 si les deux positions p et q sont sur une même diagonale et 0 sinon */
int isMemeDiag(position p, position q){
	// A ECRIRE S1
	return -1;
}

/* teste si le deplacement d'un pion de p vers q dans *g correspond à un mouvement sans prise valide*/
int isMoveElemPionValide(jeu*g, position p, position q){
	// A ECRIRE S1
	return -1;		
}

/* teste si le deplacement d'un pion de p vers q dans *g correspond à une prise valide*/
position isMangePionValide(jeu*g, position p, position q){
	// A ECRIRE S2
	return (position){-1,-1};
}


/* teste si le deplacement d'une dame de p vers q dans *g correspond à un mouvement sans prise valide*/
int isMoveElemDameValide(jeu*g, position p, position q){
	// A ECRIRE S2
	return -1;
}

/* teste si le deplacement d'une dame de p vers q dans *g correspond à une prise valide
 * retourne la position de la piece prise si c'est le caseVal
 * retourne une position non valide {-1,-1} sinon
 */
position isMangeDameValide(jeu*g, position p, position q){
	// A ECRIRE S2
	return (position){-1,-1};
}


/* fonction reunissant les deux fonctions isMoveElemPionValide et isMoveElemDameValide
 * teste si le deplacement de la piece présente en position p vers q dans *g correspond à un mouvement sans prise valide
 */
int isMoveElemValide(jeu*g, position p, position q){
	// A ECRIRE S2
	return -1;
}


/* fonction reunissant les deux fonctions isMangeElemPionValide et isMangeElemDameValide
 * teste si le deplacement de la piece présente en position p vers la position q dans *g correspond à une prise valide
 * retourne la position de la piece prise si c'est le caseVal
 * retourne une position non valide {-1,-1} sinon
 */
position isMangeValide(jeu*g, position p, position q){
	// A ECRIRE S2
	return (position){-1,-1};
}

/***********************************************************************************
 * Fonctions relatives au struct move
 * voir TP sur listes chainées c'est tres proche
***********************************************************************************/

/* cree avec malloc un move vide (first et last egaux a NULL) */
move* newMoveVide(){
	// A ECRIRE S2-S3
	return NULL;
}

/* ajoute une nouvelle etape en position p a la suite de m->last 
 */
void ajouteEtape(move* m, position p) {
	// A ECRIRE S2-S3
}

/* libere (avec free) les mallocs fait pour le mouvement m y compris les cellules etape de la liste chainee entre m->first et m->last
 * */
void libereMem(move* m){
	// A ECRIRE S2-S3

}



/***********************************************************************************
 * Fonctions de recherche de meilleur coup
 * 	- pour regle meilleur coup obligatoire
 * 	- pour faire jouer CPU
 *  S4
***********************************************************************************/


/* retourne un mouvement sans prise possible a partir de la position p, et NULL si aucun n'est possible.
 *	S4
 */ 
move* bestmoveelem(jeu* g, position p){
		return NULL;
}

/* retourne un mouvement de rafle optimal a partir de la position p, NULL si aucune prise n'est possible
 * S4
 */
move* bestmange(jeu* g, position p){
		return NULL;
}

/* retourne le meilleur mouvement possible (en score) depuis la position p 
 * en utilisant les deux fonctions précédentes 
 * */
move* bestMove(jeu*g, position p){
		return NULL;
}

/* retourne le meilleur mouvement possible pour la couleur c 
 * en utilisant la foncton bestMove sur toutes les cases.
 */
move* bestMoveAll(jeu *g, couleur c){
		return NULL;
}



