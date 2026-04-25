//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, l, c, d, p, nl, np, cont=0, r1, r2, r3;

    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    if(k*l >= nl*n){ r1=(k*l)/nl; } else{ r1=0; }
    if(c*d >= n){ r2=c*d; } else{ r2=0; }
    if(p >= n*np){ r3= p/np; } else{ r3=0; }

    cont =min(min(r1, r2), r3);
    cont /= n;

    cout << cont << endl;

    return 0;
}