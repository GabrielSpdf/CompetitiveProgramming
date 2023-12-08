//Accepted

#include <bits/stdc++.h>
    
using namespace std;
    
    
int main(){
    long long numT, n, k, x, min, max;
    
    cin >> numT;
    
    for(int i=0; i<numT; i++){
        cin >> n >> k >> x;
        min = k*(k+1)/2;
        max = (n*(n+1)/2) - ((n-k)*(n-k+1)/2);
    
        if(x >= min && x <= max) { cout << "YES\n"; } 
        else { cout << "NO\n"; }
    
    }
    
    
    return 0;
}