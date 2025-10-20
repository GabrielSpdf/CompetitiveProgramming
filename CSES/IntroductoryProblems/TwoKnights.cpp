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

#define int long long

void solve(){
	int n;
	cin >> n;

	for(int k=1; k<=n; k++){
		cout << ((k*k)*((k*k)-1)/2)-((k-1)*(k-2)*4) << "\n";
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
