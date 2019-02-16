#include <stdio.h>
#include <math.h>

int main() {
    double x= 1.6 , x1 = 1.61;
    while ( x - x1 < pow(10, -20)) {
        x = x1;
        x1 = x - (pow(x, 2.0) - x - 1) / (2 * x - 1);
    }
    printf("%.20lf\n", x1);
    return 0;
}
