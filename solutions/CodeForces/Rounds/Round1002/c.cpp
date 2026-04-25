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
	int n;
	cin >> n;

	vvi grid(n, vi(n));
	FORI(0, n){
		FORJ(0, n){
			int inp;
			cin >> inp;
			grid[i][j] = inp;
		}
	}

	vi qtd;
	FORI(0, n){
		int tam=0;
		for(int j=n-1; j>=0; j--){
			if(grid[i][j]==1) tam++;
			else break;
		}
		qtd.pb(tam);
	}
	sort(qtd.begin(), qtd.end());
	/* FORI(0, qtd.size()) cout << qtd[i] << " "; */
	int ans=0;
	for(int i=0; i<n; i++){
		if(qtd[i]>=ans) ans++;
	}
	cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
