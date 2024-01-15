//Accepted

#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll n, f, a, b, inp, pos=0;
		priority_queue<ll, vector<ll>, greater<ll>> mm;

		cin >> n >> f >> a >> b;
		for(int i=0; i<n; i++){
			cin >> inp;
			mm.push(inp);
		}

		while(!mm.empty()){
			f-=min((mm.top()-pos)*a, b); pos=mm.top(); mm.pop();
			if(f<=0){ cout << "NO" << endl; break; }
		}

		if(f>0){ cout << "YES" << endl; }
	}


	return 0;
}


