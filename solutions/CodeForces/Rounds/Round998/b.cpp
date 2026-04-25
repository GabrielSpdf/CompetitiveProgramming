#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(sti, n) for(int i=(sti); i<(n); i++)
#define FORJ(stj, n) for(int j=(stj); j<(n); j++)
#define FORK(stk, n) for(int k=(stk); k<(n); k++)
#define tvi(v) FORI((v).size()) cerr << (v)[i] << " "; cerr << "\n"
#define tii(val) cerr <<  "(" << (val).first << ", " << (val).second << ")\n";
#define tvii(v) FORI((v).size()) { tii((v)[i]) } cerr << "\n";
#define tvvi(v) FORI((v).size()) { FORJ((v)[i].size()){ cerr <<  v[i][j] << " "; } cerr << "\n"; }  
#define all(v) (v).begin(), (v).end() 

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<bool> vbl;

void solve(){
	int n, m;
	cin >> n >> m;

    vvi g(n, vi(m));
	FORI(0, n){
		FORJ(0, m){
            cin >> g[i][j];
        }
    }
    vi p(n);
	FORI(0, n){
        sort(g[i].begin(), g[i].end());
        p[g[i][0]] = i+1;
    }

    sort(g.begin(), g.end(), [](const auto &a, const auto &b) { return a[0] < b[0]; });

	FORI(0, n){
		FORJ(0, m){
            if (g[i][j] != i+n*j) {
                cout << "-1" << "\n";
                return;
            }
        }
    }

    for (auto pi : p) {
        cout << pi << " ";
    }
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
