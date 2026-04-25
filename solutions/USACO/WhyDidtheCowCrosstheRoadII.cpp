#include <bits/stdc++.h>
#include <climits>

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
	int n, k, b;
	cin >> n >> k >> b;
	vi v(n, 0);
	vi pfs(n+1, 0);

	FORI(0, b){
		int inp; cin >> inp; --inp;
		v[inp]++;
	}
	
	FORI(1, n+1){
		pfs[i] = pfs[i-1] + v[i-1];
	}
	int ans=LLONG_MAX;
	FORI(k, n+1){
		pfs[i]-=pfs[max(0LL, i-k)];
		ans = min(pfs[i], ans);
	} 
	cout << ans << "\n";
}

signed main(){
	setIO("maxcross");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
