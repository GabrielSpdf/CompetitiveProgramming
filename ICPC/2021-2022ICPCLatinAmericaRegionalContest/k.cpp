#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n; cin >> n;

    vector<string> vs;
    map<char, int> mp;

    for(int i=0; i<n; i++){
        string s; cin >> s;
        vs.push_back(s);
        mp[s[0]]=1;
    }

    for(int i=0; i<n; i++){
        map<char, int> mc;
        for(int j=0; j<vs[i].size(); j++){
            mc[vs[i][j]]=1;
        }

        int qtd=0;
        for(auto [ch, v] : mc){
            if(mp[ch]==0) break;
            if(mp[ch]==1) qtd++;
        }
        if(qtd==mc.size()){
            cout << "Y\n";
            return;
        }
    }

    cout << "N" << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}