//Accepted

#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;

    cin >> n;
    vector<ll> v(n), v1, v2;

    for(int i=0; i<n; i++){
        v[i]=i+1;
        if((i+1)%2){ v1.push_back(i+1); }
        else{ v2.push_back(i+1); }
    }

    ll sum=(int)v1.size()+(int)v2.size();
    if(sum<4){ cout << (sum==1? "1" : "NO SOLUTION") << endl; }
    else{
        int p;
        for(p=0; p<(int)v2.size(); p++){
            cout << v2[p] << " ";
        }
        for(p=0; p<(int)v1.size(); p++){
            cout << v1[p] << " ";
        }
    }

    return 0;
}
