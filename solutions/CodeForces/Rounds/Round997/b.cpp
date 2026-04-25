#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FORI(n) for(int i=0; i<(n); i++)
#define FORJ(n) for(int j=0; j<(n); j++)
#define FORK(n) for(int k=0; k<(n); k++)
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
	int n;
	cin >> n;
	vi v(n);
	for(int i=0; i<n; i++) v[i] = n-i;
	
	vector<string> grid;
	FORI(n){
		string s;
		cin >> s;
		grid.pb(s);
	}
	
	vi jumps(n, 0);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i<j && grid[i][j]=='1') jumps[i]--;
			if(i>j && grid[i][j]=='1') jumps[i]++;
		}
	}

	/* tvi(jumps); */

	vi ans(n);
	for(int i=0; i<n; i++){
		ans[n-i-1+jumps[i]] = i+1;
	}

	FORI(n) cout << ans[i] << " ";
	cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
