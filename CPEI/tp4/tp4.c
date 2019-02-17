

#include <stdlib.h>
#include <stdio.h>

int main() {

  int n=0;
  int somme = 0, i = 0,  cnt=0;

        while(n >= cnt)
        {
            if((i % 2) != 0)
            {
                somme = somme + i;
                cnt++;
            }
            i++;
        }
        printf("%d\n", somme);
  
        return 0;
    }

  
