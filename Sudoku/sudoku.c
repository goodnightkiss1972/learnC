#include <stdio.h>
#include <math.h>

void print_grid(int t[], int len);
int missing_on_line(int val, int rang, int t[], int len);
int missing_on_column(int val, int rang, int t[], int len);
int missing_on_cell(int val, int rang, int t[], int len);

int main()
{
    int n;   // taille du cote d'une cellule
    int len; // taille du tableau modelisant la grille

    printf("Entrez la taille de la grille (minimum 2) :");
    scanf("%d", &n);
    if (n < 2)
    {
        printf("ERREUR: La grille est trop petite (minimum 2)...");
        return 0;
    }
    // un tableau avec un dimension devra contenir n puissance 4 cellules.
    len = pow(n, 4);
    int cote = sqrt(len);      // longueur d'un cote de la grille
    int cotecase = sqrt(cote); // longeur d'une case

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
    }
    //    print_grid(grille, len);
    /*
    printf("val=%d sur position=%d resultat:%d\n", 1, 3, missing_on_column(1, 3, grille, len));
    printf("val=%d sur position=%d resultat:%d\n", 2, 3, missing_on_column(2, 3, grille, len));
    printf("val=%d sur position=%d resultat:%d\n", 2, 5, missing_on_column(2, 5, grille, len));
    printf("val=%d sur position=%d resultat:%d\n", 2, 14, missing_on_column(2, 14, grille, len));
*/
    // creation des cases de la grille remplies avec les indices
    // il nous faut "cote" case, chaque case contiendra "cote" indices
    int cases[cote][cote];
    int indice = 0; // l'indice va etre ecrit dans le tableau cases
    int position = 0;
    int casecourante = 0;
    do
    {
        //printf("case %2d position %2d indice %2d\n", casecourante, position, indice);
        cases[casecourante][position] = indice;
        indice++;
        position++;
        if (position % cotecase == 0)
        {
            position = position - cotecase;
            casecourante++;
        }
        if ((indice % cotecase == 0) && (position % cotecase == 0) && (casecourante % cotecase == 0))
        {
            casecourante = casecourante - cotecase;
            position = position + cotecase;
        }
        if (indice % (len / cotecase) == 0)
        {
            casecourante = casecourante + cotecase;
            position = 0;
        }

    } while (indice <= len);

    for (int j = 0; j < cote; j++)
    {
        printf("Indices de la case %d :", j);
        for (int k = 0; k < cote; k++)
        {
            printf("[%2d] ", cases[j][k]);
        }
        printf("\n");
    }
    return 0;
}

void print_grid(int t[], int len)
{
    int i = 1;
    int l = sqrt(len);
    while (i < len + 1)
    {
        if (sqrt(len) <= 9)
        {
            printf("%d ", t[i - 1]);
        }
        else
        {
            printf("%2d ", t[i - 1]);
        }
        if (i > 0)
        {
            if ((i % l) == 0)
            {
                printf("\n");
            }
        }
        i++;
    }
}

int missing_on_line(int val, int rang, int t[], int len)
{
    int cote = sqrt(len);
    int borne_inf = (rang / cote) * cote;
    int borne_sup = ((rang / cote) * cote) + cote - 1;
    //printf("inf %d / sup %d\n", borne_inf, borne_sup);
    for (int i = borne_inf; i <= borne_sup; i++) // cette boucle constitue la ligne
    {
        if (t[i] == val)
        {
            return 0; // (faux) on a trouvé val sur la ligne
        }
    }
    return 1; // (vrai) val est absente de la ligne
}

int missing_on_column(int val, int rang, int t[], int len)
{
    int cote = sqrt(len);
    int rang_inf = -1;
    do
    {
        if (rang < cote)
        {
            rang_inf = rang;
        }
        else
        {
            rang = rang - cote;
        }
    } while (rang_inf == -1);
    int rang_sup = rang_inf + (cote - 1) * cote;
    //printf("inf %d / sup %d\n", rang_inf, rang_sup);
    for (int i = rang_inf; i <= rang_sup; i = i + cote) // Cette boucle constitue la colonne
    {
        if (t[i] == val)
        {
            return 0; // (faux) on a trouvé val sur la colonne
        }
    }
    return 1; // (vrai) val est absente de la colonne
}

int missing_on_cell(int val, int rang, int t[], int len)
{
    return 0;
}
