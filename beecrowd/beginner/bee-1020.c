//Accepted - 2021

#include <stdio.h>

int main() 
{
    int idade_em_dias, ano, mes;

    scanf("%d", &idade_em_dias);

    ano = idade_em_dias/365;
    idade_em_dias %= 365;

    mes = idade_em_dias/30;
    idade_em_dias %= 30;

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, idade_em_dias);

    return 0;
}