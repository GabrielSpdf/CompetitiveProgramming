//Accepted

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a , b, c, cont=0, ver=0;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        if(a>0){ ver++; } if(b>0){ ver++; } if(c>0){ ver++; }
        if(ver>=2){ cont++; }
        ver=0;
    }

    cout << cont << endl;

    return 0;
}