#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int k,p,i,j,max=500900;
    cin>>k>>p;
    vector<bool>freq(max,false);
    freq[0]=true;

    for(i=0;i<p;i++){
        int aux;
        cin>>aux;
        for(j=0;j<max;j++) if(freq[j]&&j+aux<max) freq[j+aux]=true;
    }

    for(i=0;i<k;i++){
        int m;
        cin>>m;
        for(j=0;j<101;j++){
            if(freq[m+j]){
                cout<<j<<"\n";
                break;
            }
        }
    }
}

signed main(){
    solve();

    return 0;
}