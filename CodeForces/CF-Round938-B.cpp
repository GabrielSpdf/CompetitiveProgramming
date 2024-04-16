//Accepted

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const long long LLINF = 4e18;
const double EPS = 1e-9;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio();
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll n, c, d, inp, menor;
		menor = LLINF;
		vector<ll> v, aux;

		cin >> n >> c >> d;
		for(ll i=0; i<(n*n); i++){
			cin >> inp;
			v.push_back(inp);
			if(inp<menor) menor = inp;
		}

		ll front=menor, value=menor;
		for(ll j=0; j<n; j++){
			if(j>0){
				front+=c;
			}
			value = front;
			aux.push_back(value);
			/* cout << value << " "; */
			for(ll k=0; k<(n-1); k++){
				value+=d;
				aux.push_back(value);
				/* cout << value << " "; */
			}
			/* cout << "\n"; */
		}

		sort(v.begin(), v.end());
		sort(aux.begin(), aux.end());

		/* cout << "aux: "; */
		/* for(ll t=0; t<(n*n); t++){ */
		/* 	cout << aux[t] << " "; */
		/* } */

		/* cout << "\n"; */
		/* cout << "v: "; */
		/* for(ll q=0; q<(n*n); q++){ */
		/* 	cout << v[q] << " "; */
		/* } */

		if(v == aux) cout << "YES\n";
		else cout << "NO\n";


	}


	return 0; 
}
