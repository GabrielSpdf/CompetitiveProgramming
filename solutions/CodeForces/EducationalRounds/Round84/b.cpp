#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    map<int, bool> princes, daughters;

    for(int i=0; i<n; i++){
        princes[i] = false;
        daughters[i] = false;
    }

    for(int i=0; i<n; i++){
        int qtd; cin >> qtd;
        for(int j=0; j<qtd; j++){
            int inp; cin >> inp;
            v[i].push_back(--inp);
        }
        sort(v[i].begin(), v[i].end());
    }

    int sat = -1, sas = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            if(princes[v[i][j]] == false){
                sas++;
                princes[v[i][j]] = true;
                daughters[i] = true;
                break;
            }
        }
        if(daughters[i] == false){
            sat = i;
        }
    }

    if(sas == n){
        cout << "OPTIMAL\n";
        return;
    }

    cout << "IMPROVE\n";
    for(auto &it : princes){
        if(it.second == false){
            cout << sat+1 << " " << it.first+1 << "\n";
            return;
        }
    }
}

signed main(){
    int t; 
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}