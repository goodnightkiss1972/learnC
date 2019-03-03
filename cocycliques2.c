#include <stdio.h>

#define nbPoints (4)
typedef struct
{
    float x;
    float y;
} pts;
pts liste[nbPoints];
typedef struct
{
    float a;
    float b;
    float c;
} equationDroite;

void montrePoints(pts listeAMontrer[nbPoints]);
equationDroite *fabriqueEquationDroite(pts p1, pts p2);
void fabriqueEquationDroite2(pts p1, pts p2, equationDroite *eq);
int verifiePtsSurEquationDroite(pts p1, equationDroite eq);

int main()
{
    int k;
    float xinput, yinput;
    for (k = 0; k < nbPoints; k++)
    {
        printf("Entrez point %d (x puis espace et y) : ", k);
        scanf("%f %f", &xinput, &yinput);
        liste[k].x = xinput;
        liste[k].y = yinput;
    }
    montrePoints(liste);

    // on fabrique l'equation entre les deux premiers points de la liste (elements 0 et 1)
    equationDroite *equation01;
    equation01 = fabriqueEquationDroite(liste[0], liste[1]);
    // verifions si le troisieme point est sur la droite (element 2)
    printf("verification point 2 sur droite (01) %d\n", verifiePtsSurEquationDroite(liste[2], *equation01));
    // verifions si le quatrieme point est sur la droite (element 3)
    printf("verification point 3 sur droite (01) %d\n", verifiePtsSurEquationDroite(liste[3], *equation01));
    // verifions que le 2ieme point est sur la droite du 1er et du 4 ieme en une seule ligne
    printf("verification point 1 sur droite (03): %d\n", verifiePtsSurEquationDroite(liste[1], *fabriqueEquationDroite(liste[0], liste[3])));

    // autre technique en utlisant la fonction "2"
    equationDroite eq01;
    fabriqueEquationDroite2(liste[0], liste[1], &eq01);
    printf("En dehors de la fonction 2 :\n");
    printf("La droite passant par les points (%f,%f) et (%f,%f) est : %f X + (%f) Y + (%f) = 0\n", liste[0].x, liste[0].y, liste[1].x, liste[1].y, eq01.a, eq01.b, eq01.c);

}

void montrePoints(pts listeAMontrer[nbPoints])
{
    int k;
    /* display array contents */
    for (k = 0; k < nbPoints; k++)
    {
        printf("%d: ( %f , %f )\n", k, liste[k].x, liste[k].y);
    }
}

equationDroite *fabriqueEquationDroite(pts p1, pts p2)
{
    static equationDroite equation;
    // l'utilisation d'une variable statique n'est pas une super idee
    // au premier appel de la fonction la variable "equation" va rester en mémoire
    // visible depuis l'appelant.
    // Même si ici on reset "equation" à chaque fois c'est un peu dommage de recycler la variable
    // on ne prend pas de risque ici toutefois
    equation.a = p1.y - p2.y;               //y1 - y2 = a
    equation.b = p2.x - p1.x;               //x2 - x1 = b
    equation.c = p2.y * p1.x - p1.y * p2.x; //y2 * x1 - y1 * x2 = c
    printf("La droite passant par les points (%f,%f) et (%f,%f) est : %f X + (%f) Y + (%f) = 0\n", p1.x, p1.y, p2.x, p2.y, equation.a, equation.b, equation.c);
    return (&equation);
    // question : comment gerer si p1 = p2 car si les points sont confondus alors que doit devenir notre equation ?
}

void fabriqueEquationDroite2(pts p1, pts p2, equationDroite *ret)
{
    // Enorme avantage de ce type d'ecriture : on peut retourner plus d'une variable en sortie
    // c'est a dire que la variable passee est modifiee par la fonction mais surtout on pourrait
    // en avoir plusieurs...
    equationDroite this;
    this.a = p1.y - p2.y;               //y1 - y2 = a;
    this.b = p2.x - p1.x;               //x2 - x1 = b;
    this.c = p2.y * p1.x - p1.y * p2.x; //y2 * x1 - y1 * x2 = c
    *ret = this;
}

int verifiePtsSurEquationDroite(pts p, equationDroite eq)
{
    if (eq.a * p.x + eq.b * p.y + eq.c == 0)
    {
        return 1; // appartient a la droite
    }
    else
    {
        return 0; // n'appartient pas a la droite
    }
}