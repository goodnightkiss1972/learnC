#include <stdio.h>
#include <math.h>

int len; // taille du tableau modelisant la grille
int n; // taille du cote d'un bloc
int cotegrille; // longueur d'un cote de la grille
int cotebloc; // longeur d'un bloc

void print_grid(int t[]);
int solve(int t[], int b[][cotegrille], int position);

int manque_sur_ligne(int val, int rang, int t[]);
int manque_sur_colonne(int val, int rang, int t[]);
int manque_dans_bloc(int val, int rang, int t[], int b[][cotegrille]);

int main()
{
    printf("Entrez la taille de la grille (minimum 2) :");
    scanf("%d", &n);
    if (n < 2)
    {
        printf("ERREUR: La grille est trop petite (minimum 2)...");
        return 0;
    }

    // un tableau avec un dimension devra contenir n puissance 4 cellules.
    len = pow(n, 4);
    cotegrille = sqrt(len);      // longueur d'un cote de la grille
    cotebloc = sqrt(cotegrille); // longeur d'un bloc

    int grille[len]; // la grille en tableau a une seule dimension
    for (int i = 0; i < len; i++)
    {
        grille[i] = 0;
    }
    if (n == 2)
    {
        grille[0] = 1;
        grille[3] = 3;
        grille[5] = 4;
        grille[7] = 2;
        grille[8] = 2;
        grille[10] = 3;
        grille[14] = 2;
    }
    print_grid(grille);

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
/*    for (int j = 0; j < cotegrille; j++)
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
    printf(" attendu 0 > %d\n", manque_sur_ligne(4, 10, grille)); // devrait etre faux donc = 0
    printf(" attendu 1 > %d\n", manque_sur_colonne(2, 2, grille)); // devrait etre vrai donc = 1
    printf(" attendu 0 > %d\n", manque_sur_colonne(4, 10, grille)); // devrait etre faux donc = 0
    printf(" attendu 1 > %d\n", manque_dans_bloc(4, 0, grille, blocs)); // devrait etre vrai donc = 1
    printf(" attendu 0 > %d\n", manque_dans_bloc(4, 10, grille, blocs)); // devrait etre faux donc = 0
    */
    printf("\n a la fin : %d\n", solve(grille, blocs, 0));
    printf("\n");
    print_grid(grille);
    
    
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
            printf("%2d ", t[i - 1]);
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

int solve(int t[], int b[][cotegrille], int position) {

    // le Sudoku est terminé quand on a mis la derniere case
    if (position == len + 1) {
        return 1;
    }
    // Si la case n'est pas egale a zero on passe a la suivante
    // en essayant toutes les possibilites de 1 a cotegrille
    // ce qui fait aussi qu'on ne touchera pas les valeurs mises au départ
    printf("%2d ", position);
    if (t[position] != 0) {
        return solve(t, b, position + 1);
    }
    else
    {
        for (int essai = 1; essai <= cotegrille; essai++){
            if (manque_sur_ligne(essai, position, t) == 1 && manque_sur_colonne(essai, position, t) == 1 && manque_dans_bloc(essai, position, t, b) == 1) {
                t[position] = essai;
                return solve(t, b, position + 1);
            }
        }
    }
    return 0; // on y est pas arrive
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
    for (int i = 0; i < cotegrille; i++) {// pour chaque bloc
        for (int j = 0; j < cotegrille; j++) {// on regarde les indices
            if (b[i][j] == rang) {
                bloctrouve = i;
            }
        }
    }
    //printf("Test manque_dans_bloc la val %d en rang %d (bloc trouve: %d):", val, rang, bloctrouve);
    // on a le bloc dans bloctrouve et on regarde si val est dans ce bloc
    for (int i = 0; i < cotegrille; i++) {// pour chaque element du bloc
        if (b[bloctrouve][i] == val) {
            return 0;
        }
    }
    return 1;
}
