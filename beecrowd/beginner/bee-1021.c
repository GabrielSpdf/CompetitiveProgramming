//Accepted - 2021

#include <stdio.h>

int main() 
{
    double valor, troco;
    int nota, moeda;

    scanf("%lf", &valor);

    troco = valor;

    /*NOTA*/
    printf("NOTAS:\n");

    nota = (int)troco/100;
    printf("%d nota(s) de R$ 100.00\n", nota);
    troco -= nota*100;

    nota = (int)troco/50;
    printf("%d nota(s) de R$ 50.00\n", nota);
    troco -= nota*50;

    nota = (int)troco/20;
    printf("%d nota(s) de R$ 20.00\n", nota);
    troco -= nota*20;

    nota = (int)troco/10;
    printf("%d nota(s) de R$ 10.00\n", nota);
    troco -= nota*10;

    nota = (int)troco/5;
    printf("%d nota(s) de R$ 5.00\n", nota);
    troco -= nota*5;

    nota = (int)troco/2;
    printf("%d nota(s) de R$ 2.00\n", nota);
    troco -= nota*2;

    /*MOEDA*/
    printf("MOEDAS:\n");

    moeda = troco/1;
    printf("%d moeda(s) de R$ 1.00\n", moeda);
    troco -= moeda*1;

    moeda = troco/0.50;
    printf("%d moeda(s) de R$ 0.50\n", moeda);
    troco -= moeda*0.50;

    moeda = troco/0.25;
    printf("%d moeda(s) de R$ 0.25\n", moeda);
    troco -= moeda*0.25;

    moeda = troco/0.10;
    printf("%d moeda(s) de R$ 0.10\n", moeda);
    troco -= moeda*0.10;

    moeda = troco/0.05;
    printf("%d moeda(s) de R$ 0.05\n", moeda);
    troco -= moeda*0.05;

    moeda = troco/0.01;
    
    printf("%.lf moeda(s) de R$ 0.01\n", troco*100);
    troco -= moeda*0.01;
    
    return 0;
}