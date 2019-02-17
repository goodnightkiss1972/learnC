#include <stdio.h>

#define DP printf("%s : %d\n", __FILE__, __LINE__);
#define MONTREINT(a) printf("DEBUG = %d LINE = %d\n",a, __LINE__);

int main () {
    int n = 10,i;
    DP;
    for (i=0; i<n; i++)
    {
        printf("Nous sommes a i = : %d\n", i);
        MONTREINT(i*2);
    }
    DP;
}
