//Accepted - 2021

#include <stdio.h>
 
int main() {
 
    int qtd_empregados, horas_mes;
    float salario_hora;

    scanf("%d %d %f", &qtd_empregados, &horas_mes, &salario_hora);

    printf("NUMBER = %d\n", qtd_empregados);

    printf("SALARY = U$ %.2f\n", horas_mes*salario_hora);
 
    return 0;
}