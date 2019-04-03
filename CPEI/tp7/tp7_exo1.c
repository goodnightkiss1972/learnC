#include <stdio.h>

void fonct(int g[], int i, int n);

int main () {
  int n;
  printf("entrer la valeur de n : ");
  scanf("%d",&n);
  int g[n];
  fonct(g,0,n);
  return 0;
}



void fonct(int g[], int i, int n) {
  int j;
  for (j=0;j<n;j++) {
    g[i]=j;
    if (i==(n-1)) {
    for (int k = 0; k < n; k++) {
    printf("[ %d ]", g[k]);
    }
  }   
  else {
        fonct(g,i+1,n);
      }
    printf("\n");
  }
}



