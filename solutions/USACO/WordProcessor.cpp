//Accepted

#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    string s;
    cin >> n >> k;
    vector<string> vs;

    for(int i=0; i<n; i++){ cin >> s; vs.push_back(s); }

    int cont=0;
    for(int j=0; j<(int)vs.size(); j++){
        cont += vs[j].size();
        if(cont>k){ cont=0; j--; cout << "\n"; }
        else{ if(cont==(int)vs[j].size()) cout << vs[j]; else cout << " " << vs[j]; }
    }

    return 0;
}