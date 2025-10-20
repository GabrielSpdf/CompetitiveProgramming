#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;

void solve(){
	int n, m;
	cin >> n >> m;
	int a, b;
	int ans = 0;
	int pa=0, pb=0;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		if((a-pa)%2==0){
			ans += (a-pa) - (pb!=b);
		}
		else{
			ans += (a-pa) - (pb==b);
		}

		pa=a;
		pb=b;
	}
	ans += (m-a);
	cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int t; cin >> t; while(t--)
		solve();

    return 0;
}
