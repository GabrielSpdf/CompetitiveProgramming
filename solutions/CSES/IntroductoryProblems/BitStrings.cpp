#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
	int n;
	cin >> n;
	
	if(n==0){
		cout << "0\n";
		return;
	}
	int num=1;
	for(int i=1; i<=n; i++){
		num <<= 1;
		num = num % (long long)(1e9 + 7);
	}

	cout << num << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	solve();

    return 0;
}
