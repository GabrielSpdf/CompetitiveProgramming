//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, b, c;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(a>b && a>c) {if(b<c){printf("Case %d: %d\n", i, c);} if(c<b){printf("Case %d: %d\n", i, b);}}
        if(b>a && b>c) {if(a<c){printf("Case %d: %d\n", i, c);} if(c<a){printf("Case %d: %d\n", i, a);}}
        if(c>a && c>b) {if(a<b){printf("Case %d: %d\n", i, b);} if(b<a){printf("Case %d: %d\n", i, a);}}
    }

    return 0;
}