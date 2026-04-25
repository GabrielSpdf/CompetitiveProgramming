#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;

void solve(){
	int x, n;
	cin >> x >> n;	
	int sum=0;
	for(int i=0; i<n; i++){
		if(i%2) sum-=x;
		else sum+=x;
	}
	
	cout << sum << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
