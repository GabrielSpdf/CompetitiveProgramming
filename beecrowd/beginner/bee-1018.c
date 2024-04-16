//Accepted - 2021

#include <stdio.h>

int main() 
{
    int valor, troco, nota_100, nota_50, nota_20, nota_10, nota_5, nota_2, nota_1;

    scanf("%d", &valor);

    printf("%d\n", valor);

    troco = valor;
    nota_100 = troco/100;
    troco -= (nota_100)*100;
    printf("%d nota(s) de R$ 100,00\n", nota_100);
    
    nota_50 = troco/50;
    troco -= (nota_50)*50;
    printf("%d nota(s) de R$ 50,00\n", nota_50);
    
    nota_20 = troco/20;
    troco -= (nota_20)*20;
    printf("%d nota(s) de R$ 20,00\n", nota_20);
    
    nota_10 = troco/10;
    troco -= (nota_10)*10;
    printf("%d nota(s) de R$ 10,00\n", nota_10);
    
    nota_5 = troco/5;
    troco -= (nota_5)*5;
    printf("%d nota(s) de R$ 5,00\n", nota_5);
    
    nota_2 = troco/2;
    troco -= (nota_2)*2;
    printf("%d nota(s) de R$ 2,00\n", nota_2);
    
    
    printf("%d nota(s) de R$ 1,00\n", troco);
    

    return 0;
}