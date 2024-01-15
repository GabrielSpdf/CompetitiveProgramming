//Accepted - 2021

#include <stdio.h>
#include <math.h>

int main() 
{
    double num1, num2, num3, formula1, formula2;

    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if(num1 != 0 && sqrt(pow(num2,2)-4*num1*num3)>=0)
    {
        formula1 = ((-num2+sqrt(pow(num2,2)-4*num1*num3))/(2*num1));
        formula2 = ((-num2-sqrt(pow(num2,2)-4*num1*num3))/(2*num1));
        printf("R1 = %.5lf\nR2 = %.5lf\n", formula1, formula2);
    }
    else    
        printf("Impossivel calcular\n");

    return 0;
}