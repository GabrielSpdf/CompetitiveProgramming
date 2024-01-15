//Accepted - 2021

#include <stdio.h>
 
int main() {
 
    float n1, n2, n3, n4, media, score, nova_media;
    
    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    media = (((2*n1)+(3*n2)+(4*n3)+(1*n4))/10);
    printf("Media: %.1f\n", media);
    if(media>=7)
    {
        printf("Aluno aprovado.\n");
    }
    else if(media<5)
    {
        printf("Aluno reprovado.\n");
    }
    else
    {
        printf("Aluno em exame.\n");
        scanf("%f", &score);
        printf("Nota do exame: %.1f\n", score);
        nova_media = (score+media)/2;
        if(nova_media>=5)
        {
            printf("Aluno aprovado.\n");
            printf("Media final: %.1f\n", nova_media);
        }
        else 
        {
            printf("Aluno reprovado.\n");
            printf("Media final: %.1f\n", nova_media);
        }
    }
    
 
    return 0;
}