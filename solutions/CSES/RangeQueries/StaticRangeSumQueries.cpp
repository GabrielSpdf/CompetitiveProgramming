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

void solve(){
	int n, q;
	cin >> n >> q;
	vi v(n);
	for(auto &a: v) cin >> a;

	vector<ll> pfs(n+1, 0);
	for(int i=0; i<n; i++){
		pfs[i+1]=pfs[i]+v[i];
	}

	/* for(int i=0; i<pfs.size(); i++) cout << pfs[i] << " "; */
 
	for(int i=0; i<q; i++){
		int inp1, inp2;
		cin >> inp1 >> inp2;
		cout << pfs[inp2]-pfs[inp1-1] << "\n";
	}
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
