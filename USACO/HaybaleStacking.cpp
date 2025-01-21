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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	int n, k;
	cin >> n >> k;

	vi v(n, 0);
	FORI(0, k){
		int s, e;
		cin >> s >> e; --s; --e;
		v[s]++;
		v[e+1]--;
	}

	vi pfs(n+1, 0);
	FORI(1, n+1){
		pfs[i] = pfs[i-1] + v[i-1];
	}
	sort(pfs.begin(), pfs.end());

	cout << pfs[(n+1)/2] << "\n";
}

signed main(){
	setIO("stacking");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
