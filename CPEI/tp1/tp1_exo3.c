#include <stdio.h>


int main() {
  double x = 0.60,z;
  int y;
  printf("combien de pommes voulez vous acheter ? \n");
  scanf("%d",&y);
    z = x*y;
  printf("%lf euros svp! \n",z);
  return 0;
}

//question 2)

int main() {
  double x = 0.60,z;
  int y;
  printf("combien de pommes voulez vous acheter ? \n");
  scanf("%d",&y);
  if(y<=5){
    z = x*y; printf("%lf euros svp! \n",z); 
  }
  else{
    z = 3 + 0.50 * (y-5); printf("%lf euros svp!",z);
  }
  return 0;
}

//question 3)

int main() {
  double p = 0.60,b = 0.45, z;
  int y1, y2;
  printf("combien de pommes et de bananes voulez vous acheter ? \n");
  scanf("%d %d",&y1,&y2);
    z = p*y1 + b*y2;
  printf("%lf euros svp! \n",z);
  return 0;
}
//j'ai combiné pommes et bananes mais ils voulaient que banane donc pareil.

//question 4)

int main()
{
    double prix_unit = 0.45, cout;
    int articles_demandes, articles_achetes = 4, articles_payes = 3, paquets, reste;

    printf("combien d'articles voulez vous acheter ? \n");
    scanf("%d", &articles_demandes);

    if (articles_payes == 0)
    {
        printf("c'est offert par la maison");
    }
    else
    {
        paquets = articles_demandes / articles_achetes;
        reste = articles_demandes % articles_achetes;
        cout = (paquets * articles_payes + reste) * prix_unit;

        printf("vous payez le nombre de %d articles au prix de %lf euros\n", articles_demandes, cout);
    }
    return 0;
}
