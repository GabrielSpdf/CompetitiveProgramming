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
typedef vector<bool> vbl;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for(auto &a: v) cin >> a;
	sort(v.begin(), v.end());

	vll aux(n, 0); // qnt falta pro prox nivel
	for(int i=1; i<n; i++){
		aux[i] = v[i]-v[i-1]; // lv0 lv1 lv2 lv3
	}	

	vll pfs(n, 0);
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
