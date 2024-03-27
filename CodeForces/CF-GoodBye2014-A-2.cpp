//Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int fun(ll i, vector<ll> &v, ll ans, ll who){
	ans+=v[i];
	/* cout << "ans: " << ans << endl; */
	
	if(ans>who){ return -1; }
	else if(ans==who){ return 1; }

	return 0 + fun(ans, v, ans, who);
}

int main(){
	ll n, t, input, ver=0;
	cin >> n >> t;
	vector<ll> v(n-1);

	for(int i=0; i<(n-1); i++){
		cin >> input;
		v[i] = input;
	}

	int ans;
	ans = fun(0, v, ver, t-1);
	cout << (ans == -1? "NO" : "YES") << endl;

	return 0;
}

