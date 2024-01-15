//Accepted - 2021

#include <stdio.h>
 
int main() {
 
    int code1, code2, units1, units2;
    float preco1, preco2;

    scanf("%d %d %f", &code1, &units1, &preco1);
 
    scanf("%d %d %f", &code2, &units2, &preco2);

    printf("VALOR A PAGAR: R$ %.2f\n", (units1*preco1)+(units2*preco2));   

    return 0;
}