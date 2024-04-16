//Accepted - 2021

#include <stdio.h>
#define X 60
#define Y 90
 
int main() 
{
    int tempo; 
    float diferenca_tempo;
    
    scanf("%d", &tempo);

    diferenca_tempo = (float)tempo/(Y-X)*60;
    
    printf("%.0f minutos\n", diferenca_tempo);
 
    return 0;
}