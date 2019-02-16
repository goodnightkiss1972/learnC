#include <stdio.h>

#define PU 0.45//PU
#define AA 4//AA
#define AP 3//AA
#define DEBUG printf("LIGNE %d promotion = %d, le cout est %lf\n",__LINE__,AP,cout);

int main()
{
    double cout;
    int articles_demandes, paquets, reste;

    printf("combien d'articles voulez vous acheter ? \n");
    scanf("%d", &articles_demandes);
    DEBUG
    if (AP == 0)
    {
        printf("c'est offert par la maison\n");
    }
    else
    {
        paquets = articles_demandes / AA;
        reste = articles_demandes % AA;
        cout = (paquets * AP + reste) * PU;
        DEBUG
        printf("vous payez le nombre de %d articles au prix de %lf euros (%d articles reels)\n", articles_demandes, cout, paquets*AP+reste);
    }
    return 0;
}
