//Accepted

#include <bits/stdc++.h>
    
using namespace std;
    
int main(){
    int numT, n, k, a, existe;
    
    cin >> numT;
    for(int i=0; i<numT; i++){
        existe = 0;
        cin >> n >> k;
        for(int j=0; j<n; j++){
            cin >> a;
            if(a == k) { existe = 1; }
        }
        if(existe == 1) { cout << "YES" << endl;}
        else { cout << "NO" << endl; }
    }
    
    return 0;
}