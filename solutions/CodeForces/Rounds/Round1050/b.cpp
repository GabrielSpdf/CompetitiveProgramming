#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;

void solve(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	
	int ans = 0;
	for(int i=0; i<n; i++){
		int mq; cin >> mq;
		if(mq<=y) ans++;
	}

	for(int i=0; i<m; i++){
		int nq; cin >> nq;
		if(nq<=x) ans++;
	}
	cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
