#include <bits/stdc++.h>
#include <iterator>

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
	int n;
	cin >> n;
	vi va(n), vb(n); 
	for(auto &a: va) cin >> a;
	for(auto &a: vb) cin >> a;

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	vi ans(n, 0);
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(va[i]<=vb[j]){ ans[i]=j-i; break; }
		}
	}

	cout << *max_element(ans.begin(), ans.end()) << "\n";
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
