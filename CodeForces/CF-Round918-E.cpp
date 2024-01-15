//Accepted

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
	ll t;
	cin>>t;
	for(ll i=0; i<t; i++){
		map<ll, int> mp;

		ll inp, val, sum=0;
		cin>>inp;
		for(ll j=0; j<inp; j++){
			cin >> val;
			if(j==0 || j%2==0){ sum+=val; }
			else{ sum-=val; }
			mp[sum]++;
		}

		if(mp.size()!=inp || mp.count(0)){ cout << "YES" << endl; }
		else{ cout << "NO" << endl; }
	}

	return 0;
}
