#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int len;        // taille du tableau modelisant la grille
int n;          // taille du cote d'un bloc
int cotegrille; // longueur d'un cote de la grille
int cotebloc;   // longueur d'un bloc

void print_grid(int t[]);
int read_grid(char fichier[255], int t[]);
int solve(int t[], int b[][cotegrille], int position);
int write_grid(char fichier[255], int t[]);
int check_grid(int t[], int b[][cotegrille]);
void copy_grid(int tsource[], int tdestination[]);
void enhance_grid(int t[], int b[][cotegrille]);

int manque_sur_ligne(int val, int rang, int t[]);
int manque_sur_colonne(int val, int rang, int t[]);
int manque_dans_bloc(int val, int rang, int t[], int b[][cotegrille]);
int depose_amelioration(int rang, int t[], int b[][cotegrille]);

int main()
{
    printf("\nEntrez la taille de la grille svp (minimum 2) : ");
    scanf("%d", &n);
    if (n < 2)
    {
        printf("\nERREUR: La grille est trop petite (minimum 2)...\n");
        return 0;
    }
    // un tableau de n de long devra contenir n puissance 4 cellules.
    len = pow(n, 4);
    cotegrille = sqrt(len);      // longueur d'un cote de la grille
    cotebloc = sqrt(cotegrille); // longeur d'un bloc
    int grille[len];             // la grille en tableau a une seule dimension
    for (int i = 0; i < len; i++)
    {
        grille[i] = 0;
    }

    char nomfichier[255] = "";
    printf("\nEntrez le nom du fichier de grille svp : ");
    scanf("%254s", nomfichier);

    // Chargement de la grille a partir d'un fichier externe
    if (read_grid(nomfichier, grille) == 0)
    {
        printf("\nERREUR: impossible d'ouvrir le fichier %s\n", nomfichier);
        return 0;
    }
    printf("\n");
    print_grid(grille);

    //    return 0; // a enlever le temps de blinder la lecture de la grille

    // creation des cases de la grille remplies avec les indices
    // il nous faut "cotegrille" blocs, chaque bloc contiendra "cotegrille" indices
    int blocs[cotegrille][cotegrille];
    int indice = 0; // l'indice va etre ecrit dans le tableau blocs
    int position = 0;
    int bloc = 0;
    do
    {
        //printf("bloc %2d position %2d indice %2d\n", bloc, position, indice);
        blocs[bloc][position] = indice;
        indice++;
        position++;
        if (position % cotebloc == 0)
        {
            position = position - cotebloc;
            bloc++;
        }
        if ((indice % cotebloc == 0) && (position % cotebloc == 0) && (bloc % cotebloc == 0))
        {
            bloc = bloc - cotebloc;
            position = position + cotebloc;
        }
        if (indice % (len / cotebloc) == 0)
        {
            bloc = bloc + cotebloc;
            position = 0;
        }

    } while (indice <= len);

    // verification du rendu des blocs
    /*
    for (int j = 0; j < cotegrille; j++)
    {
        printf("Indices du bloc %d :", j);
        for (int k = 0; k < cotegrille; k++)
        {
            printf("[%2d] ", blocs[j][k]);
        }
        printf("\n");
    }
    */
    // tests
    /*
    printf(" attendu 1 > %d\n", manque_sur_ligne(2, 1, grille)); // devrait etre vrai donc = 1
    printf(" attendu 1 > %d\n", manque_sur_ligne(4, 10, grille)); // devrait etre vrai donc = 1
    printf(" attendu 0 > %d\n", manque_sur_ligne(4, 5, grille)); // devrait etre faux donc = 0
    printf("\n");
    printf(" attendu 0 > %d\n", manque_sur_colonne(2, 2, grille)); // devrait etre faux donc = 0
    printf(" attendu 0 > %d\n", manque_sur_colonne(3, 10, grille)); // devrait etre faux donc = 0
    printf(" attendu 1 > %d\n", manque_sur_colonne(4, 3, grille)); // devrait etre vrai donc = 1
    printf("\n");
    printf(" attendu 0 > %d\n", manque_dans_bloc(4, 0, grille, blocs)); // devrait etre faux donc = 0
    printf(" attendu 1 > %d\n", manque_dans_bloc(4, 11, grille, blocs)); // devrait etre vrai donc = 1
    printf("\n");
    */

    // verification initiale de la grille
    if (check_grid(grille, blocs) != 1)
    {
        printf("ERREUR : La grille contient des erreurs, elle n'aura pas de solution.\n");
        return 0;
    }

    // avec la grille chargee et valide on va creer une grille de travail pour la methode intelligente
    int grilletravail[len];
    copy_grid(grille, grilletravail);
    enhance_grid(grilletravail, blocs);
    printf("\n");
    print_grid(grilletravail);

    //return 0; // ici on peut s'arreter pour voir l'amelioration seulement

    int resultat;
    resultat = solve(grille, blocs, 0);
    if (resultat == 1)
    {
        printf("\n");
        print_grid(grille);

        // ultime verification avant sauvegarde du resultat
        if (check_grid(grille, blocs) != 1)
        {
            printf("ERREUR : Apres solve correct la grille n'est pas valide...\n");
            return 0;
        }

        char *nomsansextension;
        int j = 0;
        //Découper la chaîne selon les espaces
        nomsansextension = strtok(nomfichier, ".");

        strcat(nomfichier, ".resultat.txt"); // on rajoute l'extension pour la sauvegarde
        if (write_grid(nomfichier, grille) == 1)
        {
            printf("\nLe resultat se trouve dans %s\n", nomfichier);
        }
        else
        {
            printf("\nERREUR : Sauvegarde du fichier impossible.");
        }
    }
    return 0;
}

void print_grid(int t[])
{
    int i = 1;
    while (i < len + 1)
    {
        if (cotegrille <= 9)
        {
            printf("%d ", t[i - 1]);
        }
        else
        {
            printf("%3d ", t[i - 1]);
        }
        if (i > 0)
        {
            if ((i % cotegrille) == 0)
            {
                printf("\n");
            }
        }
        i++;
    }
}

int read_grid(char nomfichier[255], int t[])
{
    // Chaque ligne devra contenir des nombres de taille 99 maximum d'ou 2*cotegrille
    // et un cotegrille supplementaire pour les espaces.
    int tailleligne = 2 * cotegrille + cotegrille;
    int position = 0; // repere pour l'injection dans le tableau en parametre
    int i = 0;

    FILE *fichier = fopen(nomfichier, "r"); // Ouverture du fichier en lecture seule
    if (fichier != NULL)
    {
        char ligne[tailleligne];
        while (i < cotegrille) // on cible "cotegrille" ligne pour eviter les lignes vides apres la grille
        {
            fgets(ligne, tailleligne, fichier);
            //printf("Ligne lue : '%s'", ligne);
            // https://openclassrooms.com/forum/sujet/comprendre-strtok
            char *token;
            int j = 0;
            //Découper la chaîne selon les espaces
            token = strtok(ligne, " ");

            //Afficher le résultat du découpage
            while (j < cotegrille)
            {
                t[position] = atoi(token);
                position++;
                token = strtok(NULL, " ");
                j++;
            }
            //printf("\n");
            i++;
        }
        fclose(fichier);
    }
    else
    {
        perror(nomfichier); // Affiche l'erreur si on arrive pas a ouvrir le fichier
        return 0;
    }
    return 1; // Tout s'est bien passe
}

int solve(int t[], int b[][cotegrille], int position)
{

    // le Sudoku est terminé quand on a mis la derniere case
    if (position == len + 1)
    {
        return 1;
        printf("\n FINAL de solve\n");
    }
    // Si la case n'est pas egale a zero on passe a la suivante
    // en essayant toutes les possibilites de 1 a cotegrille
    // ce qui fait aussi qu'on ne touchera pas les valeurs mises au départ
    if (t[position] != 0)
    {
        return solve(t, b, position + 1);
    }

    for (int essai = 1; essai <= cotegrille; essai++)
    {
        if (manque_sur_ligne(essai, position, t) == 1 && manque_sur_colonne(essai, position, t) == 1 && manque_dans_bloc(essai, position, t, b) == 1)
        {
            //printf("\nEcrire dans la position %2d la valeur %d\n", position, essai);
            t[position] = essai;
            if (solve(t, b, position + 1) == 1)
            {
                return 1;
            }
        }
    }

    t[position] = 0; // on remet a zero pour pouvoir essayer a nouveau apres
    return 0;        // on y est pas arrive
}

int manque_sur_ligne(int val, int rang, int t[])
{
    int borne_inf = (rang / cotegrille) * cotegrille;
    int borne_sup = ((rang / cotegrille) * cotegrille) + cotegrille - 1;
    //printf("inf %d / sup %d\n", borne_inf, borne_sup);
    //printf("Test manque_sur_ligne la val %d en rang %d :", val, rang);
    for (int i = borne_inf; i <= borne_sup; i++) // cette boucle constitue la ligne
    {
        if (t[i] == val)
        {
            return 0; // (faux) on a trouvé val sur la ligne
        }
    }
    return 1; // (vrai) val est absente de la ligne
}

int manque_sur_colonne(int val, int rang, int t[])
{
    int rang_inf = -1;
    do
    {
        if (rang < cotegrille)
        {
            rang_inf = rang;
        }
        else
        {
            rang = rang - cotegrille;
        }
    } while (rang_inf == -1);
    int rang_sup = rang_inf + (cotegrille - 1) * cotegrille;
    //printf("inf %d / sup %d\n", rang_inf, rang_sup);
    //printf("Test manque_sur_colonne la val %d en rang %d :", val, rang);
    for (int i = rang_inf; i <= rang_sup; i = i + cotegrille) // Cette boucle constitue la colonne
    {
        if (t[i] == val)
        {
            return 0; // (faux) on a trouvé val sur la colonne
        }
    }
    return 1; // (vrai) val est absente de la colonne
}

int manque_dans_bloc(int val, int rang, int t[], int b[][cotegrille])
{
    // on va rechercher dans quelle bloc se trouve la "val" par son "rang"
    // puis une fois le bloc identifie on cherche si "val" en est absent
    // si absent (vrai) on retourne 1, sinon si present (faux) on retourne 0.
    int bloctrouve = -1;
    // identification du bloc
    for (int i = 0; i < cotegrille; i++)
    { // pour chaque bloc
        for (int j = 0; j < cotegrille; j++)
        { // on regarde les indices
            if (b[i][j] == rang)
            {
                bloctrouve = i;
            }
        }
    }
    // on a le bloc dans bloctrouve et on regarde si val est dans ce bloc
    for (int i = 0; i < cotegrille; i++)
    { // pour chaque element du bloc
        if (t[b[bloctrouve][i]] == val)
        {
            return 0;
        }
    }
    return 1;
}

int write_grid(char nomfichier[255], int t[])
{

    FILE *fichier = fopen(nomfichier, "w"); // Ouverture du fichier en ecriture
    if (fichier != NULL)
    {
        int i = 1;
        while (i < len + 1) // on va ecrire autant d'element qu'il y en a dans le tableau
        {
            if (cotegrille <= 9)
            {
                fprintf(fichier, "%d ", t[i - 1]);
            }
            else
            {
                fprintf(fichier, "%3d ", t[i - 1]);
            }
            if (i % cotegrille == 0)
            {
                if (i != len)
                {
                    fprintf(fichier, "\n");
                }
            }
            i++;
        }
        fclose(fichier);
    }
    else
    {
        perror(nomfichier); // Affiche l'erreur si on arrive pas a fermer le fichier
        return 0;
    }
    return 1; // Tout s'est bien passe
}

/**
 * @brief Verifie si la grille respecte les regles du SUDOKU
 * 
 * @param t la grille a verifier
 * @param b les definitions des blocs (tableaux d'indices)
 * @return int 1 si la grille est valide, sinon 0
 */
int check_grid(int t[], int b[][cotegrille])
{
    // on va passer en revue tout les elements de la grille
    // chaque fois on va retenir la valeur de la cellule et la remplacer par 9999
    // si la retenue est manquante dans la ligne, la colonne et le bloc
    // alors on remet la retenue en place est on continue
    // jusqu'a avoir parcouru tout le tableau
    int retenue = 0;
    int i = 0;
    while (i < len)
    {
        retenue = t[i]; // on retient la valeur en cours
        if (retenue != 0)
        {
            t[i] = 9999; // on met 9999 à la place
            if (manque_sur_ligne(retenue, i, t) == 1 && manque_sur_colonne(retenue, i, t) == 1 && manque_dans_bloc(retenue, i, t, b) == 1)
            {
                //printf("Verification position %d ok\n", i);
                t[i] = retenue; // on remet la valeur retenue en place
            }
            else
            {
                printf("\n");
                printf("Verification position %d incorrecte\n", i);
                return 0; // la grille n'est pas valide
            }
        }
        i++;
    }
    return 1; // la grille est valide
}

void copy_grid(int tsource[], int tdestination[])
{
    // copie de valeurs a valeurs par une boucle de taille len
    for (int i = 0; i < len; i++)
    {
        tdestination[i] = tsource[i];
    }
}

void enhance_grid(int t[], int b[][cotegrille])
{
    // pour ameliorer une grille on va parcourir toute les positions qui contiennent zero
    // puis a chaque fois on va regarder si plus d'une solution est possible
    // si c'est le cas on passe a la prochaine position
    // jusqu'a rencontrer une position avec une seule solution possible et on l'applique
    // puis on recommence jusqu'a ne plus rien ameliorer
    // ou ne plus rien a avoir a ameliorer pour ne pas faire de boucle infinie

    int amelioration = 1; // sera mis a 1 chaque fois qu'une amelioration aura eu lieu
    while (amelioration > 0)
    {
        amelioration = 0;
        for (int i = 0; i < len; i++)
        {
            if (t[i] == 0)
            {
                //printf("essai amelioration au rang %d (valeur actuelle %d)\n", i, t[i]);
                amelioration = amelioration + depose_amelioration(i, t, b);
            }
        }
    }
}

int depose_amelioration(int rang, int t[], int b[][cotegrille])
{
    // si au rang en question il n'existe qu'une seule solution respectant les regles
    // alors on ecrit cette solution dans la grille et on retourne 1
    // sinon on a pas trouve d'amelioration on retourne 0

    int nb_solutions_possibles = 0;
    int index_solutions = 0;
    int solutions[cotegrille];

    // il faut parcourir entre 1 et le cotegrille +1
    for (int k = 1; k < cotegrille + 1; k++)
    {
        if (manque_sur_ligne(k, rang, t) == 1 && manque_sur_colonne(k, rang, t) == 1 && manque_dans_bloc(k, rang, t, b) == 1)
        {
            solutions[index_solutions] = k;
            index_solutions++;
            nb_solutions_possibles++;
            //printf("index_solutions %d / nb_solutions_possibles %d / rang %d / solution %d\n", index_solutions, nb_solutions_possibles, rang, k);
        }
    }
    // si une seule solution trouvee alors on l'ecrit (et c'est forcement la premiere entree du tableau solutions)
    if (nb_solutions_possibles == 1)
    {
        //printf("amelioration rang %d : solution posee %d\n", rang, solutions[0]);
        t[rang] = solutions[0];
        return 1;
    }
    return 0;
}