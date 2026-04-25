#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto &a : v) cin >> a;

	int mx1=v[0], mx2=v[0];

	for(int i=1; i<n; i++){
		mx1 = max(v[i], mx1+v[i]);
		mx2 = max(mx2, mx1);
	}

	cout << mx2 << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
