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
	vi va(n), vb(n);
	for(auto &a: va) cin >> a;
	for(auto &a: vb) cin >> a;
	
	int mx=0;
	for(int i=0; i<n; i++){
		int temp=0;
		for(int j=i; j<n; j++){
			/* cerr << j-i << "\n"; */
			if(va[i]<=vb[j]){ break; }
			temp++;
		}
		mx=max(mx, temp);
	}

	cout << mx << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
