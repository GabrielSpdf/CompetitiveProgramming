#include <bits/stdc++.h>

using namespace std;

#define int long long
int MOD=1006903069;

void solve(){
    int n,i,j,tst;
    cin>>n;
    cin>>tst;
    map<pair<int,int>,int>mapa;
    for(i=0;i<tst;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mapa[{a,b}]=c;
    }
    int resp=0;
    cin>>tst;
    for(i=0;i<tst;i++){
        int a,b,c;
        cin>>a>>b>>c;
        resp=(resp+(mapa[{b,a}]*c)%MOD)%MOD;
    }
    cout<<resp<<"\n";
}

signed main(){
    solve();

    return 0;
}