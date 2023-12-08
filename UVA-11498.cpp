//Accepted

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nqueries, n, m, fim=0, a, b;
    while(fim == 0){
        scanf("%d", &nqueries);
        if(nqueries==0) {fim=1; break;}
        scanf("%d %d", &n, &m);
        for(int i=0; i<nqueries; i++){
            scanf("%d %d", &a, &b);
            if(a==n || b==m) printf("divisa\n");
            if(a>n && b>m) printf("NE\n");
            if(a<n && b>m) printf("NO\n");
            if(a>n && b<m) printf("SE\n");
            if(a<n && b<m) printf("SO\n");
        }
    }

    return 0;
}