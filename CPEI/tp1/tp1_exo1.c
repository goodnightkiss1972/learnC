#include <stdio.h>

int fonction1();
int fonction2();
int fonction4();
int fonction5();


int main() {

 fonction1();
 fonction2();
 fonction4();
 fonction5();

return 0;
}
//question 1)

int fonction1(){
    double x;
    printf("question 1) : entrer un nombre : \n");
    scanf("%lf",&x);
    printf("mon nombre est %lf\n", x);
    return 0;
}
//question 2)
int fonction2(){   
    double x;
    printf("question 2) :entrer un nombre : \n");
    scanf("%lf",&x);
    int x1 = x;
    printf("mon nombre converti est : %d\n", x1);
    return 0;
}   
//question 4)
int fonction4(){ 
    double x;
    printf("question 4) : entrer un nombre : \n");
    scanf("%lf",&x);
    char x1 = x;
    printf("mon nombre converti est : %c\n", x1);
    return 0;
}   
//question 5)
int fonction5(){
    int i;
    char i1;
    for (i=176;i<=218;i++)
        {
            i1 = i;
            printf("%c",i1);
        }
    return 0;
}