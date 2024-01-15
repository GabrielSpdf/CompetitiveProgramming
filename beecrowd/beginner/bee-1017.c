//Accepted - 2021

#include <stdio.h>
#define CAR_JOHN 12

 
int main() 
{
    int tempo, velocidade_media;

    scanf("%d", &tempo);
    scanf("%d", &velocidade_media);

    printf("%.3f\n", (float)(tempo*velocidade_media)/CAR_JOHN);
 
    return 0;
}