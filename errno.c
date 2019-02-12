//#include <errno.h>
#include <stdio.h>

// pas génial, ici meme avec la gestion errno on peut avoir x = nan ou x = inf (infini)
// errno ne se declenche pas vraiment ou alors il y a un truc...

int main(void)
{
    double x;

//    errno = 0;
    x = x / 0;

//    if (errno == 0)
        printf("x = %f\n", x);

    return 0;
}