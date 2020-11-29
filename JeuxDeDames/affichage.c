/**
 * Fichier contenant des fonctions d'affichage 
 * Ne pas modifier sauf a des fins de customisation
 */

//#define AFFICHEJOLI //mettre cette ligne en commentaire pour de l'affichage plus simple sous windows

/* constantes pour l'affichage des pieces dans print_piece */
#ifdef AFFICHEJOLI
#define BLKDOT "\u26AB"
#define WHTDOT "\u26AA"
#define YELDOT "\xF0\x9F\x9F\xA1"
#define BLKSQU "\xE2\xAC\x9B"//"\u2B1B"
#define WHTSQU "\u2B1C"
#define YELSQU "\xF0\x9F\x9F\xA8"
#else
#define BLKDOT BBLK"PN"
#define WHTDOT BWHT"PB"
#define YELDOT BYEL"PC"
#define BLKSQU BBLK"DN"
#define WHTSQU BWHT"DB"
#define YELSQU BYEL"DC"
#endif

/* fonction pour affichage symboles sous Powershell Windows */
void configWindowsConsole(){
	#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL,"fr_FR.UTF8");
	#endif	
}


/* fonction pour temporiser l'affichage */
void sleepcp(int milliseconds) {
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end) {
    }
}

/* fonction permettant d'effacer l'ecran du terminal */
void resetTerm() {
    #ifdef _WIN32
    system("@cls||clear");
    #else
    printf(clean);
    #endif
}

/* fonction permettant de redimensionner le terminal a une taille passeee en parameter */
void resizeTerminal(int haut, int larg){
	printf("\e[8;%d;%d;t",haut,larg);
}

/* fonction permettant de redimensionner le terminal a une taille apropriée pour le damier de *g*/
void resizeTerminalToGame(jeu* g){
	printf("\e[8;100;%d;t",6*(g->NB_Col+3));	
}

void switchcolorbckgrd(int i, int j) {
    if (j == -1) {
        printf(RESET);             //defaultbackground
    } else if (((i + j) % 2) == 0) {
        printf(REDHB);             //redbackground

    } else {
        printf(WHTHB);             //graybackground
    }
}

void print_piece(caseVal s) {
    switch (s) {
        case PBC:
        case PNC:
            printf(YELDOT);
            break;
        case DNC:
        case DBC:
            printf(YELSQU);
            break;
        case PB:
            printf(WHTDOT);
            break;
        case DB:
            printf(WHTSQU);
            break;
        case PN:
            printf(BLKDOT);
            break;
        case DN:
            printf(BLKSQU);  	
            break;
        default:
            printf("  ");
            break;
    }
}

void print_ligne(jeu* g, int i) {
    position p;
    p.lig = i;
    caseVal s;
    switchcolorbckgrd(i, -1);
    printf("       ");
    for (int j = 0; j < g->NB_Col; j++) {
        switchcolorbckgrd(i, j);
        printf("      ");
    }
    switchcolorbckgrd(i, -1);
    printf("\n");
    printf("  %2d   ", i);
    for (int j = 0; j < g->NB_Col; j++) {
        p.col = j;
        s = getCaseVal(g, p);
        switchcolorbckgrd(i, j);
        printf("  ");
        print_piece(s);
        switchcolorbckgrd(i, j);
        printf("  ");
    }
    switchcolorbckgrd(i, -1);
    printf("   %2d   \n", i);

    printf("       ");
    for (int j = 0; j < g->NB_Col; j++) {
        switchcolorbckgrd(i, j);
        printf("      ");
    }
    switchcolorbckgrd(i, -1);

    printf("\n");


}

void print_ligne_char(jeu* g, char c) {
    for (int j = 0; j < 12+6*g->NB_Col; j++) {
        printf("%c",c);
    }
    printf("\n");  
}

void print_bordure_horizontale(jeu *g) {
    print_ligne_char(g,' ');
    printf("      ");
    for (int j = 0; j < g->NB_Col; j++) {
        printf("   %2d ", j);
    }
    printf("\n");
    print_ligne_char(g,' ');

}

void print_damier(jeu* g) {
    print_ligne_char(g,'-');
    print_bordure_horizontale(g);
    for (int i = g->NB_Lig - 1; i>-1; i--) {
        print_ligne(g, i);
    }
    print_bordure_horizontale(g);
    print_ligne_char(g,'-');

}

void print_pos(position p){
    printf("%d %d ",p.lig,p.col);
}

void print_move(move*m){  
	etape *mc = m->first;
	while (mc != NULL)
	{
            print_pos(mc->pos);
            printf(" -> ");
            mc = mc->next;
	}
	printf("\n");
}

void print_couleur(couleur c){
	if(c==BLANC)
		printf("Blanc");
	else if(c==NOIR)
		printf("Noir");	
	else
		printf("NoCol");
}

void print_typePiece(typePiece tp){
	if(tp==Pion)
		printf("Pion");
	else if(tp==Dame)
		printf("Dame");
	else
		printf("Vide");
}
