#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define tvi(v) FORI(0, (v).size()) cerr << (v)[i] << " "; cerr << "\n";
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI(0, (v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI(0, (v).size()) { FORJ(0, (v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 
#define rall(v) (v).rbegin(), (v).rend() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int qtd0=0, qtd1=0;
    FORI(0, (int)s.size()){
        if(s[i]=='0') qtd0++;
        else qtd1++;
    }
    if(qtd0%2!=0){
        qtd0--;
        qtd1--;
    }
    int pares1 = max(qtd0, qtd1)/2;
    int pares2 = min(qtd0, qtd1)/2;
    int sum = pares1 + pares2;

    if(sum==k){
        cout << "YES\n";
        return;
    }
    for(int i=0; i<pares2; i++){
        cerr << "sum: " << sum << "\n";
        cerr << "k: " << k << "\n";
        sum-=2;
        if(sum==k){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
