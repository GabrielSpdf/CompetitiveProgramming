#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(v) (v).begin(), (v).end() // e.g. sort(all(v));

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
	int n, k;
	cin >> n >> k;

	vll va(n), vb(n);
	for(auto &a: va) cin >> a;
	for(auto &a: vb) cin >> a;
	
	vll pfs_sum(n), max_vb(n);
	pfs_sum[0] = va[0];
	max_vb[0] = vb[0];
	for(int i=1; i<n; i++){
		pfs_sum[i]+=(va[i]+pfs_sum[i-1]);
		max_vb[i]=max(max_vb[i-1], vb[i]);
	}
	
	ll ans=0;
	for(int i=0; i<n; i++){
		if(i==k) break;
		ans=max(ans, pfs_sum[i]+(max_vb[i]*(k-(i+1))));
	}
	
	cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
