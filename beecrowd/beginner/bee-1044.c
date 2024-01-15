//Accepted - 2021

#include <stdio.h>

int main()
{
    int a,b;

    scanf("%d %d", &a, &b);

    if(a>b)
    {
        if((a/b)*b == a)
            printf("Sao Multiplos\n");

        else 
            printf("Nao sao Multiplos\n");
    }

    else if(b>a)
    {
        if((b/a)*a == b)
            printf("Sao Multiplos\n");

        else
            printf("Nao sao Multiplos\n");
    }

    else 
        printf("Sao Multiplos\n");

    return 0;
}