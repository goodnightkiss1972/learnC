
/**
 * 
 * Fichiers pour ecrire des fonctions de tests 
 *  
 * Des exemples sont donnés pour la S1
 * 
 * Il est fortement recommandé de faire de telles fonctions au fur eet à mesure
 *   
 */




int test_doDeplace(){
	int ret=1;
	jeu *g = calloc(1,sizeof(jeu)); // calloc pour etre sur d'avoir NULL dans g->plateau
	initBlank(g,10,10);
	
	print_ligne_char(g,'-');	
	printf("  Tests fonction doDeplace sur damier 10x10 \n");
	print_ligne_char(g,'-');	

	position deb = {2,0};
	position fin = {3,1};
	
	setCaseVal(g,deb,PB);
	
	doDeplace(g,deb,fin);
	if(getCaseVal(g,deb)!=VIDE || getCaseVal(g,fin)!=PB){
		ret=0;
		printf("!!! PB Test doDeplace !!!\n");
	}
	else{
		printf("Test doDeplace ok\n");
	}
	free(g->plateau);
	free(g);	
	return ret;		
}

int test_doMange(){
	int ret=1;
	jeu *g = calloc(1,sizeof(jeu));
	initBlank(g,10,10);
	
	print_ligne_char(g,'-');	
	printf("  Tests fonction doMange sur damier 10x10 \n");
	print_ligne_char(g,'-');	

	position deb = {2,0};
	position prise = {3,1};
	position fin = {4,2};
	setCaseVal(g,deb,PB);
	setCaseVal(g,prise,PN);
	
	doMange(g,deb,fin,prise);
	if(getCaseVal(g,deb)!=VIDE || getCaseVal(g,fin)!=PB || getCaseVal(g,prise)!=PNC){
		ret=0;
		printf("!!! PB Test doMange !!!\n");
	}
	else{
		printf("Test doMange ok\n");
		
	}
	
	free(g->plateau);
	free(g);	
	return ret;		
}

int test_undoCapture(){
	int ret=1;
	jeu *g = calloc(1,sizeof(jeu));
	initBlank(g,10,10);
	
	print_ligne_char(g,'-');	
	printf("  Tests fonction undoCapture sur damier 10x10 \n");
	print_ligne_char(g,'-');	

	position p = {2,0};
	position pc = {3,1};
	setCaseVal(g,p,PB);
	setCaseVal(g,pc,PNC);
	
	undoCapture(g);
	for(int lig = 0; lig< g->NB_Lig ; lig++){
		for(int col=0; col<g->NB_Col ; col ++){
			if(getCaseVal(g,(position){lig,col})<0){
				ret=0;
				printf("!!! PB Test undoCapture en position  %d %d!!!\n",lig,col);	
			}			
		}
	}
	if(ret==1){
		printf("Test undoCapture ok\n");		
	}
	
	print_ligne_char(g,'-');	
	free(g->plateau);
	free(g);	
	return ret;			
	
}

int test_isValide(){
	int ret=1;
	jeu *g = calloc(1,sizeof(jeu));
	initBlank(g,10,10);


	print_ligne_char(g,'-');	
	printf("  Tests fonction isValide sur damier 10x10 \n");
	print_ligne_char(g,'-');	

	
	position tab[] = {{4,6},{10,4},{5,1},{-1,-1}};
	int verite[] = {1,0,1,0};	

	for(int ntest=0; ntest<4; ntest++){
		if(isValide(g,tab[ntest])!=verite[ntest]){
			printf("!! test isValide %d pas OK !! \n",ntest);
			ret=0;
		}else
			printf("test isValide %d ok\n",ntest);
	}
	print_ligne_char(g,'-');

	free(g->plateau);
	free(g);	
	return ret;		
}

int test_isMoveElemPion(){	
	jeu *g = calloc(1,sizeof(jeu));	 // pour etre sur d'avoir des zeros partout au debut
	initBlank(g,10,10);
	print_ligne_char(g,'-');	
	printf("  Tests fonction isMoveElemPion sur damier 10x10 \n");
	print_ligne_char(g,'-');	

	int ret=1;
	
	
	position pTMEP ={3,5};
	position tab[] = {{4,6},{4,4},{5,7},{-1,-1},{4,8},{2,4}};
	int verite[] = {1,0,0,0,0,0};	
	
	setCaseVal(g,pTMEP,PB);
	setCaseVal(g,tab[1],PNC);

	for(int ntest=0; ntest<6; ntest++){
		if(isMoveElemPionValide(g,pTMEP,tab[ntest])!=verite[ntest]){
			printf("!! test isMoveElem %d pas OK !! \n",ntest);
			ret=0;
		}else
			printf("test isMovelem %d ok\n",ntest);
	}
	print_ligne_char(g,'-');



	free(g->plateau);
	free(g);
	return ret;
}


