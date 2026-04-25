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
	int n, l, r;
	cin >> n >> l >> r;
	--l; --r;

	vi v(n);
	for(auto &a: v) cin >> a;

	vi store, pt1, pt2;

	for(int i=0; i<n; i++){
		store.pb(v[i]);
	}

	pt1 = vi(store.begin(), store.begin()+r+1);
	pt2 = vi(store.begin()+l, store.end());
	
	sort(all(pt1));
	sort(all(pt2));

	/* tvi(pt1); */
	/* tvi(pt2); */

	int ans1=0, ans2=0;	
	FORI(0, (r-l+1)) ans1+=pt1[i];
	FORI(0, (r-l+1)) ans2+=pt2[i];

	cout << min(ans1, ans2) << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
