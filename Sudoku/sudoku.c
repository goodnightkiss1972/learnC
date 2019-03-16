#include <stdio.h>
#include <math.h>

int len; // taille du tableau modelisant la grille
int n; // taille du cote d'un bloc
int cotegrille; // longueur d'un cote de la grille
int cotebloc; // longeur d'un bloc

void print_grid(int t[], int len);

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
        grille[5] = 2;
        grille[7] = 1;
        grille[9] = 3; //erreur
        grille[10] = 4;
        grille[12] = 3;
    }
    print_grid(grille, len);

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
    for (int j = 0; j < cotegrille; j++)
    {
        printf("Indices du bloc %d :", j);
        for (int k = 0; k < cotegrille; k++)
        {
            printf("[%2d] ", blocs[j][k]);
        }
        printf("\n");
    }

    printf(" %d\n", manque_sur_ligne(2, 1, grille)); // devrait etre vrai donc = 1
    printf(" %d\n", manque_sur_ligne(4, 10, grille)); // devrait etre faux donc = 0
/*
    manque_dans_bloc(1, 3, grille, blocs);
    manque_dans_bloc(2, 14, grille, blocs);
*/
    return 0;
}

void print_grid(int t[], int len)
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

int manque_sur_ligne(int val, int rang, int t[])
{
    int borne_inf = (rang / cotegrille) * cotegrille;
    int borne_sup = ((rang / cotegrille) * cotegrille) + cotegrille - 1;
    //printf("inf %d / sup %d\n", borne_inf, borne_sup);
    printf("Test manque_sur_ligne la val %d en rang %d :", val, rang);
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
    // on a le bloc dans bloctrouve et on regarde si val est dans ce bloc
    for (int i = 0; i < cotegrille; i++) {// pour chaque element du bloc
        if (b[bloctrouve][i] == val) {
            return 0;
        }
    }
    return 1;
}
