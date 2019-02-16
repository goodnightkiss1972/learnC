#include <stdio.h>

int main() {
  int U,n=0;
    printf("saisir le premier terme : ");
    scanf("%d", &U);
    while(U!=1){
         if (U%2==0) {
           U = U / 2;
         } else {
           U = 3 * U + 1;
             }
         n++;
    }
         printf("\nl'indice recherche est %d ", n);
         return 0;
           }

           
          
int main() {
  int U, n = 0, b;
  printf("saisir le premier terme et le terme b : ");
  scanf("%d %d", &U, &b);

  while(U!=b && U!=1){
    if (U%2==0) {
        U = U / 2;
    } else {
        U = 3 * U + 1;
    }
    n++;
  }
  if(U==b){
     printf("\nl'indice recherche est %d ", n);
  } else if (b==4){
     printf("\nl'indice recherche est %d ", n+1);
  } else if (b==2){
     printf("\nl'indice recherche est %d ", n+2);
  } else { printf("Nope\n");
      }
    return 0;
           }
    
    
