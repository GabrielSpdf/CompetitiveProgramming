//Accepted - 2021

#include <stdio.h>

int main() 
{
    int sec, horas, minutos;

    scanf("%d", &sec);

    horas = (sec/3600);
    sec %= 3600;

    minutos = (sec/60);
    sec %= 60;

    printf("%d:%d:%d\n", horas, minutos, sec);

    return 0;
}