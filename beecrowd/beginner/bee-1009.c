//Accepted - 2021

#include <stdio.h>
 
int main() {
 
    double salario_fixo, vendas, salario_final;
    char nome[20];

    fgets(nome, 20, stdin);

    scanf("%lf %lf", &salario_fixo, &vendas);

    salario_final = salario_fixo + (0.15*vendas);

    printf("TOTAL = R$ %.2lf\n", salario_final);
 
    return 0;
}