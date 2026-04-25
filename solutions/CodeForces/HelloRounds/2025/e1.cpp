// Unsolved

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

vector<map<int, int>> listAdj;
vi ans;
int unt;

void dfs(int idx, int stp, int dif, int deep){
	if(deep==unt){
		return;
	}
	ans.push_back(listAdj[idx][dif]);
	
	int nxt_wg=INT_MAX, nxt_one;
	for(auto nxt: listAdj[idx]){
		if(nxt.first!=dif){
			if(listAdj[idx][nxt.first] < nxt_wg){
				nxt_wg = listAdj[idx][nxt.first];
				nxt_one = nxt.first;
			}
		}
	}
	dfs(nxt_one, stp, idx, deep+1);
}

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	
	listAdj.clear();
	listAdj = vector<map<int, int>>(n);
	ans.clear();

	for(int i=0; i<m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		v--; u--;
		listAdj[v][u]=w;
		listAdj[u][v]=w;
	}

	for(int i=0; i<q; i++){
		int a, b, k;
		cin >> a >> b >> k;
		a--; b--;
		
		unt=k;
		ans.clear();
		for(auto nxt: listAdj[a]) dfs(nxt.first, b, a, 1);
		
		vi vprint(ans.begin(), ans.end());
		sort(vprint.rbegin(), vprint.rend());
		/* for(auto el: vprint) cout << el << " "; */
		/* cout << "\n"; */
		cout << vprint[k-1] << " ";
	}
	cout << "\n";
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
