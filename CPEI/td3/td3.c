
/*#include <stdio.h>
 

void hanoi(int n, int T1, int T2){
  if (n==1) {printf("deplacer le disque %d de la tour %d a la tour %d \n",n,T1,T2);}
  else {hanoi(n-1,T1,6 - T1 -T2); printf("deplacer le disque %d de la tour %d a la tour %d \n",n,T1,T2); hanoi(n-1,6-T1 -T2,T2);}
  return;}

int main(){
  int disque,tour1,tour2;
  printf("entrer les informations : \n");
  scanf("%d %d %d",&disque,&tour1,&tour2);
  hanoi(disque,tour1,tour2);
  return 0;
  }*/
     
//avec explication

#include <stdio.h>
  
void deplacer(int a, int b, int k) {
  printf("deplacer le disque %d de la tour %d à la tour %d \n",k,a,b);
}

void hanoi(int nombre_de_disque, int tour_de_depart, int tour_d_arrive) {
  if (nombre_de_disque < 1) {
    printf("on rigole bien nan?");
  } else if (nombre_de_disque == 1) {
    deplacer(tour_de_depart, tour_d_arrive,1);
  } else {
    int autre_tour = 6 - tour_de_depart - tour_d_arrive;
    // 1/ deplacer n-1 disques de la tour de depart a autre tour
    hanoi(nombre_de_disque - 1, tour_de_depart, autre_tour);
    // 2/ deplacer 1 disque de la tour de tour de depart a tour d'arrive
    deplacer(tour_de_depart, tour_d_arrive,nombre_de_disque);
    // 3/ deplacer n-1 disques de la tour autre tour a tour d'arrivee
    hanoi(nombre_de_disque - 1, autre_tour, tour_d_arrive);
  }
}

int main() {
  printf("n = \n");
  int n;
  scanf("%d",&n);
  hanoi(n,1,3);
  return 0;
}


