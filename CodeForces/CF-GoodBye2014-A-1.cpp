//Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, t, input, ver=0, ans=0;
	cin >> n >> t;
	vector<ll> v(n-1);

	for(int i=0; i<(n-1); i++){
		cin >> input;
		v[i] = input;
	}

	ans+=v[0];

	for(int j=0; j<(n-1); j++){
		if(j==ans) ans+=v[j];
		/* cout << "ans: " << ans << endl; */
		if(ans>(t-1)){ cout << "NO" << endl; return 0; }
		if(ans==(t-1)){ cout << "YES" << endl; return 0; }
	}


	return 0;
}
