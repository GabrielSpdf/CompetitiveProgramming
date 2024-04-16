//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,l,m,n,d, cont=0;

    cin >> k >> l >> m >> n >> d;

    int auxk = k, auxl = l, auxm = m, auxn = n;

    vector<int> sol(d+2, -1);

    for(int i=0; i<d; i++){
        if(k<=d){ sol[k]=k; }
        if(l<=d){ sol[l]=l; }
        if(m<=d){ sol[m]=m; }
        if(n<=d){ sol[n]=n; }

        k+=auxk; l+=auxl; m+=auxm; n+=auxn;
    }

    for(int j=1; j<=d; j++){
        if(sol[j] != -1){ cont++; }
    }

    cout << cont << endl;

    return 0;
}