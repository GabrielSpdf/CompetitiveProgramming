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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	int n, k;
	cin >> n >> k;
	vi v(n);
	for(auto &a: v) cin >> a;

	vi vaux(2*n, 0);
	FORI(0, 2*n){
		vaux[i] = v[i%n] - (i*k);
		// cout << vaux[i] << " ";
	}

	vi ans(2*n);
	stack<int> stk;
	FORI(0, 2*n){
		while(!stk.empty() && vaux[i] < vaux[stk.top()]){
			// cerr << "vaux[i]: " << vaux[i] << "\n";
			ans[stk.top()] = (i%n)+1;
			stk.pop();
		}
		stk.push(i);
	}

	FORI(0, n){
		cout << ans[i] << " ";
	}
}

signed main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
	solve();

    return 0;
}
