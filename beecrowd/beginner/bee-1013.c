//Accepted - 2021

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a, b, c, verifica, omaior;

    scanf("%d %d %d", &a, &b, &c);

    verifica = (a+b+abs(a-b))/2;
    omaior = (c+verifica+abs(c-verifica))/2;
        
    printf("%d eh o maior\n", omaior);
    
        
    return 0;
}