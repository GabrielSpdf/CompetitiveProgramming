#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
	int n;
	cin >> n;

	int ans=0;

	while(n>=5){
		n/=5;
		ans+=n;
	}

	cout << ans << "\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
