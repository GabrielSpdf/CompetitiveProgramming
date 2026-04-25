//Accepted

#include <bits/stdc++.h>

typedef long long ll;
const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll n, maior=-1, idx, menor=LLINF;

		cin >> n;
		vector<ll> v(n);
		vector<ll> b(n, 0);
		vector<ll> aux;

		for(auto &a : v){
			cin >> a;
			b[a-1]++;
		}

		for(ll i=0; i<(ll)b.size(); i++){
			if(b[i]>maior){ maior=b[i]; idx=i+1; }
		}

		for(ll j=0; j<(ll)v.size(); j++){
			if(v[j]!=idx) aux.push_back(j);
		}

		
		if(maior == v.size()){ menor=-1; }
		else{
			if(aux.size()==1){ menor=min(aux[0], (ll)v.size()-aux[0]-1); }
			else{
				for(ll k=0; k<(ll)aux.size()-1; k++){
					menor=min(menor, min(aux[k], aux[k+1]));
					menor=min(menor, min((ll)v.size()-aux[k]-1, (ll)v.size()-aux[k+1]-1));
					menor=min(menor, aux[k+1]-aux[k]-1);
				}
			}
		}

		cout << menor << "\n";
	}


    return 0;
}
