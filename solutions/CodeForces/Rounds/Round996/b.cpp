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
	vll va(n), vb(n);
	for(auto &a: va) cin >> a;
	for(auto &a: vb) cin >> a;

	ll cnt=0;
	vll pfs(n);
	for(int i=0; i<n; i++){
		if(vb[i]-va[i]>0){
			cnt+=(vb[i]-va[i]);	
			pfs[i]+=2*cnt;
		}
	}

	vll ans(n);
	for(int i=0; i<n; i++){
		ans[i] = va[i] + pfs[i] - cnt;
	}
	
	string pans = "YES";
	for(int i=0; i<n; i++){
		if(ans[i]<vb[i]) pans="NO";
	}
	cout << pans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
