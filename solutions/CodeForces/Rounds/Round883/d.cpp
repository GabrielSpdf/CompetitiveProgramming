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
	ll n, d, h;
	cin >> n >> d >> h;

	vll v(n);
	for(auto &a: v) cin >> a;

	double ans=(d*h/2.0)*n;

	for(int i=0; i<n-1; i++){
		if(v[i]+h > v[i+1]){
			double h2 = v[i]+h-v[i+1]; // height
			double d2 = h2*d/h; // base
			ans -= h2*d2/2.0;
		}
	}

	cout << ans << "\n";
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.precision(10); cout.setf(ios::fixed);
	
	int t;
	cin >> t;
	while(t--) solve();

    return 0;
}
