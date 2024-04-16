//Accepted - 2021

#include <stdio.h>
#include <math.h>
 
int main() {
 
    double pi, radius, size;

    pi = 3.14159;

    scanf("%lf", &radius);

    size = (4.0/3)*pi*pow(radius, 3);

    printf("VOLUME = %.3lf\n", size);

    return 0;
}