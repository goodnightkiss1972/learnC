#include <stdio.h>

void composition(int n, int p[n], int q[n], int r[n]);

int main() {
  int p[3] = {0,2,1};
  int q[3] = {1,2,0};
  int r[3];
  composition(3,p,q,r);
  for (int k=0; k<3; k++) {
    printf(" [ %d ] ", r[k]);
  }
  return 0;
}


void composition(int n, int p[n], int q[n], int r[n]) {
  for (int i = 0; i<n; i++) {
    r[i] = p[q[i]];
  }
}

  
