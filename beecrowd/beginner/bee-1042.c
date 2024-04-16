//Accepted - 2021

#include <stdio.h>
 
int main() {
 
    int n1, n2, n3;
    
    scanf("%d %d %d", &n1, &n2, &n3);
    
    if(n1<n2 && n1<n3)
    {
        printf("%d\n", n1);
        if(n2<n3)
        {
            printf("%d\n%d\n", n2, n3);
        }
        else 
        {
            printf("%d\n%d\n", n3, n2);
        }
    }
    else if(n2<n1 && n2<n3)
    {
        printf("%d\n", n2);
        if(n1<n3)
        {
            printf("%d\n%d\n", n1, n3);
        }
        else 
        {
            printf("%d\n%d\n", n3, n1);
        }
    }
    else 
    {
        printf("%d\n", n3);
        if(n1<n2)
        {
            printf("%d\n%d\n", n1, n2);
        }
        else 
        {
            printf("%d\n%d\n", n2, n1);
        }
    }
    
    printf("\n");
    
    printf("%d\n%d\n%d\n", n1, n2, n3);
 
    return 0;
}