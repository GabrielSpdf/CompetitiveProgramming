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
	int n;
	cin >> n;
	
	vpii acc;
	for(int i=0; i<n; i++){
		int fst, snd;
		cin >> fst >> snd;
		acc.emplace_back(fst, 1);
		acc.emplace_back(snd, -1);
	}

	sort(acc.begin(), acc.end());
	int aux=0, ans=0;
	for(int i=0; i<(int)acc.size(); i++){
		aux+=acc[i].second;
		ans = max(ans, aux);
	}
	
	cout << ans << "\n";
}

int main(){
	/* setIO("problemname"); */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	/* int t; cin >> t; while(t--) */
		solve();

    return 0;
}
