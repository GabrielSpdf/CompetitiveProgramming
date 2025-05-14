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
			cin >> grid[i][j];
		}
	}

	vi ans(2*n, 0);
	
	int pos=1;
	FORI(0, n){
		ans[pos++] = grid[0][i];
	}
	FORI(1, n){
		ans[pos++] = grid[i][n-1];
	}

	set<int> st(all(ans));
	int missing=0;
	for(auto nxt : st){
		if(nxt!=missing) break;
		else missing++;
	}

	ans[0]=missing;
	for(auto &a: ans){
		cout << a << " ";
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
