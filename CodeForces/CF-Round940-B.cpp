//Accepted

#include <bits/stdc++.h>

typedef long long ll;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

using namespace std;

vector<ll> mersenne(ll exp){
	vector<ll> vaux;

	ll result=1;
	for(ll i=0; i<exp; i++){
		result*=2;
		vaux.push_back(result-1);
	}

	return vaux;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll n, k, max_m=0, print;
		cin >> n >> k;

		vector<ll> v;
		v = mersenne(30);	//O(30)

		/* cout << "mersenne: "; */
		for(ll i=0; i<(ll)v.size(); i++){
			/* cout << v[i] << " "; */
			if(v[i]<=k && v[i]>max_m) max_m = v[i];
		}
		
		if(n==1) cout << k;	
		if(n>1){ print=k-max_m; cout << max_m << " " << print << " ";  }
		if(n>2){
			for(ll i=2; i<n; i++){
				cout << 0;
				if(i!=n-1) cout << " ";
			}
		}
		cout << "\n";


	}


    return 0;
}
